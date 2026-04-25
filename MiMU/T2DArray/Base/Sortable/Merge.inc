{$IFDEF HELPERS}
function Flattify(const oAscending: Boolean = True): MArray; overload;
function Flatty(const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Flattify>
  @action: Flattens a 2D array into a sorted 1D array result.
  @note: Uses an N-way merge scan. Input sub-arrays must be pre-sorted for 
         the result to be valid.
[==============================================================================}
function M2DArrayHelper.Flattify(const oAscending: Boolean = True): MArray; overload;
var
  h, s, i, r, b: Integer;
  a: TIntegerArray;
  f: Boolean;
  v: MType;
begin
  h := High(Self);
  if (h < 0) then
    Exit([]);
  s := 0;
  SetLength(a, (h + 1));
  for i := 0 to h do
  begin
    s := (s + Self[i].Length);
    a[i] := 0;
  end;
  SetLength(Result, s);
  for i := 0 to (s - 1) do
  begin
    f := False;
    b := -1;
    for r := 0 to h do
    begin
      if (a[r] >= Self[r].Length) then
        Continue;
      if not f then
      begin
        v := Self[r][a[r]];
        b := r;
        f := True;
      end else if ((oAscending and (Self[r][a[r]] < v)) or ((not oAscending) and (Self[r][a[r]] > v))) then
      begin
        v := Self[r][a[r]];
        b := r;
      end;
    end;
    if (b <> -1) then
    begin
      Result[i] := v;
      Inc(a[b]);
    end;
  end;
end;

{==============================================================================]
  <Flatty>
  @action: Flattens a 2D array into a 1D array while maintaining sorted order.
  @note: Uses an N-way merge algorithm.
         Assumes sub-arrays are already sorted (to oAscending).
[==============================================================================}
function M2DArrayHelper.Flatty(const oAscending: Boolean = True): MArray; overload;
var
  h, s, i, r, b: Integer;
  a: TIntegerArray;
  f: Boolean;
  v: MType;
begin
  s := 0;
  h := High(Self);
  SetLength(a, (h + 1));
  for i := 0 to h do
  begin
    s := (s + Self[i].Length);
    a[i] := 0;
  end;
  SetLength(Result, s);
  case oAscending of
    True:
    for i := 0 to (s - 1) do
    begin
      f := False;
      b := -1;
      for r := 0 to h do
      begin
        if (a[r] >= Self[r].Length) then
          Continue;
        if not f then
        begin
          v := Self[r][a[r]];
          b := r;
          f := True;
        end else if (Self[r][a[r]] < v) then
        begin
          v := Self[r][a[r]];
          b := r;
        end;
      end;
      if (b <> -1) then
      begin
        Result[i] := v;
        Inc(a[b]);
      end;
    end;
    False:
    for i := 0 to (s - 1) do
    begin
      f := False;
      b := -1;
      for r := 0 to h do
      begin
        if (a[r] >= Self[r].Length) then
          Continue;
        if not f then
        begin
          v := Self[r][a[r]];
          b := r;
          f := True;
        end else if (Self[r][a[r]] > v) then
        begin
          v := Self[r][a[r]];
          b := r;
        end;
      end;
      if (b <> -1) then
      begin
        Result[i] := v;
        Inc(a[b]);
      end;
    end;
  end;
end;
{$ENDIF}