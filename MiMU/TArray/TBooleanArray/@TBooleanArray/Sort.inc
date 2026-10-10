{$IFDEF HELPERS}
function Dissociated(const oAscending: Boolean = True): TBooleanArray; overload;
function Flanked(const oAscending: Boolean = True): TBooleanArray; overload;
function Polarize(const oAscending: Boolean = True): Integer; overload;
function Polarized(const oAscending: Boolean = True): TBooleanArray; overload;
function Segregated(const oAscending: Boolean = True): TBooleanArray; overload;
function Sunder(const oAscending: Boolean = True): Boolean; overload;

function Sortition(const oAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Dissociated>
  @action: Returns a sorted copy of the boolean array with all False and True values grouped into contiguous blocks.
  @note: Non-destructive function. Uses frequency counting (Trueness) and block generation for optimal O(N) performance.
[==============================================================================}
function TBooleanArrayHelper.Dissociated(const oAscending: Boolean = True): TBooleanArray; overload;
var
  t, s: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  t := Self.Trueness;
  if ((t = 0) or (t = s)) then
    Exit(Self.Cloned);
  if oAscending then
    Result := Join(TBooleanArray.Falsex(s - t), TBooleanArray.Truex(t))
  else
    Result := Join(TBooleanArray.Truex(t), TBooleanArray.Falsex(s - t));
end;

{==============================================================================]
  <Flanked>
  @action: Returns a sorted copy of a boolean array in O(N) linear time using a single pass with two-ended placement.
  @note: Non-destructive function. No counting pass; the leading value is written from the front and the trailing value from the back, meeting exactly in the middle.
[==============================================================================}
function TBooleanArrayHelper.Flanked(const oAscending: Boolean = True): TBooleanArray; overload;
var
  i, l, h: Integer;
begin
  l := 0;
  h := High(Self);
  for i := 0 to Result.Alloc(h + 1) do
    if (Self[i] = oAscending) then
      Result[h.Decrease] := Self[i]
    else
      Result[l.Increase] := Self[i];
end;

{==============================================================================]
  <Polarize>
  @action: In-place O(N) linear partition of a boolean array using opposing two-pointer swaps.
  @note: Destructive function. Mutates Self directly with O(1) extra space.
[==============================================================================}
function TBooleanArrayHelper.Polarize(const oAscending: Boolean = True): Integer; overload;
var
  l, r: Integer;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  l := 0;
  r := (Result - 1);
  case oAscending of
    True:
    while (l < r) do
    begin
      while ((l < r) and (not Self[l])) do
        Inc(l);
      while ((l < r) and Self[r]) do
        Dec(r);
      if (l < r) then
        Self.Switch(l.Increase, r.Decrease);
    end;
    False:
    while (l < r) do
    begin
      while ((l < r) and Self[l]) do
        Inc(l);
      while ((l < r) and (not Self[r])) do
        Dec(r);
      if (l < r) then
        Self.Switch(l.Increase, r.Decrease);
    end;
  end;
end;

{==============================================================================]
  <Polarized>
  @action: Returns a sorted copy of a boolean array in O(N) linear time using a dual-pointer partition sweep.
  @note: Non-destructive function. Automatically separates False and True values into ordered bounds in a single pass.
[==============================================================================}
function TBooleanArrayHelper.Polarized(const oAscending: Boolean = True): TBooleanArray; overload;
var
  i, s, l, r: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([])
  else if (s = 1) then
	Exit([Self[0]]);
  l := 0;
  r := High(Self);
  case oAscending of
    True:
    for i := 0 to Result.Alloc(s) do
      if Self[i] then
        Result[r.Decrease] := Self[i]
      else
        Result[l.Increase] := Self[i];
    False:
    for i := 0 to Result.Alloc(s) do
      if Self[i] then
        Result[l.Increase] := Self[i]
      else
        Result[r.Decrease] := Self[i];
  end;
end;

{==============================================================================]
  <Segregated>
  @action: Returns a sorted copy of a boolean array in O(N) linear time using pre-count block assignment.
  @note: Non-destructive function. Optimizes CPU cache locality via sequential writes.
[==============================================================================}
function TBooleanArrayHelper.Segregated(const oAscending: Boolean = True): TBooleanArray; overload;
var
  i, s, t, f, r: Integer;
begin
  s := Self.Length;
  if (Result.SetSize(s) = 0) then
    Exit;
  t := 0;
  for i := 0 to (s - 1) do
    if Self[i] then
      Inc(t);
  f := (s - t);
  r := 0;
  case oAscending of
    True:
    begin
      for i := 1 to f do
        Result[r.Increase] := False;
      for i := 1 to t do
        Result[r.Increase] := True;
    end;
    False:
    begin
      for i := 1 to t do
        Result[r.Increase] := True;
      for i := 1 to f do
        Result[r.Increase] := False;
    end;
  end;
end;

{==============================================================================]
  <Sunder>
  @action: Sorts a boolean array in place in O(N) linear time using converging pointers.
  @note: Destructive function. Returns True if the array was modified, performing writes only for misplaced pairs.
[==============================================================================}
function TBooleanArrayHelper.Sunder(const oAscending: Boolean = True): Boolean; overload;
var
  l, r: Integer;
begin
  Result := (Self.Length > 1);
  if not Result then
    Exit;
  l := 0;
  r := High(Self);
  while (l < r) do
  begin
    while ((l < r) and (Self[l] <> oAscending)) do
      Inc(l);
    while ((l < r) and (Self[r] = oAscending)) do
      Dec(r);
    if (l < r) then
    begin
      Self[l.Increase] := (not oAscending);
      Self[r.Decrease] := oAscending;
    end;
  end;
end;

{==============================================================================]
  <Sortition>
  @action: Returns the sorted index order of a boolean array in O(N) linear time using two counting cursors.
  @note: Non-destructive function. Stable: indices within each run keep their original relative order.
[==============================================================================}
function TBooleanArrayHelper.Sortition(const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, s, t, y, n: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit
  else if (s = 1) then
    Exit([0]);
  t := 0;
  for i := 0 to (s - 1) do
    if Self[i] then
      Inc(t);
  n := IfThen(oAscending, 0, t);
  y := IfThen(oAscending, (s - t), 0);
  for i := 0 to Result.Alloc(s) do
    if Self[i] then
      Result[y.Increase] := i
    else
      Result[n.Increase] := i;
end;
{$ENDIF}
