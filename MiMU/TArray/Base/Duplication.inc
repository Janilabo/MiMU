{$IFDEF HELPERS}
function Repeated(const rCount: Integer = 1): MArray; overload;
function Repeta(const rCount: Integer = 1): MArray; overload;
function Repete(const rCount: Integer = 1): MArray; overload;
function Repetite(const rCount: Integer = 1): Integer; overload;
function Repetited(const rCount: Integer = 1): MArray; overload;
function Repetize(const rCount: Integer = 1): MArray; overload;
function Repped(const rCount: Integer = 1): MArray; overload;
function Reppite(const rCount: Integer = 1): Integer; overload;
function Reps(const rCount: Integer = 1): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Repeated>
  @action: Duplicates the elements of the current array a specified number of times sequentially.
  @note: If rCount is less than 1, an empty array is returned.
[==============================================================================}
function MArrayHelper.Repeated(const rCount: Integer = 1): MArray; overload;
var
  i, c, r, h: Integer;
begin
  if (rCount < 1) then
    Exit([]);
  h := High(Self);
  SetLength(Result, ((h + 1) * rCount));
  r := 0;
  for c := 1 to rCount do
    for i := 0 to h do
      Result[r.Increase] := Self[i];
end;

{==============================================================================]
  <Repeta>
  @action: Duplicates the elements of the current array a specified number of times sequentially, appending each repetition via System.Insert.
  @note: If rCount is less than 1 or Self length is 0, an empty array is returned. O(rCount^2)-ish due to repeated Insert shifting; illustrative rather than performant.
[==============================================================================}
function MArrayHelper.Repeta(const rCount: Integer = 1): MArray; overload;
var
  r: Integer;
begin
  Result := [];
  if ((rCount < 1) or (Self.Length = 0)) then
    Exit;
  for r := 1 to rCount do
    System.Insert(Self, Result, Result.Length);
end; 

{==============================================================================]
  <Repete>
  @action: Duplicates the elements of the current array a specified number of times sequentially,
           growing the result by self-concatenation without pre-computing final size.
  @note: If rCount is less than 1 or Self length is 0, an empty array is returned. Trims any overshoot from the last doubling step.
[==============================================================================}
function MArrayHelper.Repete(const rCount: Integer = 1): MArray; overload;
var
  l, r: Integer;
begin
  l := Self.Length;
  if ((rCount < 1) or (l = 0)) then
    Exit([]);
  r := (l * rCount);
  Result := Self.Clone;
  while (Result.Length < r) do
    Result := System.Concat(Result, Result);
  if (Result.Length > r) then
    SetLength(Result, r);
end;

{==============================================================================]
  <Repetite>
  @action: Mutates the current array by repeating its original elements a specified number of times in-place.
  @note: Returns the new total length of the array. If rCount is 1 or the array is empty, it exits early with no changes.
         If rCount is 0 or negative, the array is cleared, and 0 is returned.
[==============================================================================}
function MArrayHelper.Repetite(const rCount: Integer = 1): Integer; overload;
var
  s, l, i: Integer;
begin
  s := Self.Length;
  if ((rCount = 1) or (s = 0)) then
    Exit(s);
  Result := Self.SetSize(s * Max(0, rCount));
  for i := s to (Result - 1) do
    Self[i] := Self[i mod s];
end;

{==============================================================================]
  <Repetited>
  @action: Duplicates the elements of the current array a specified number of times sequentially, indexing the source with a modulo wrap.
  @note: If rCount is less than 1 or Self lentgth is 0, an empty array is returned. Safe for managed types.
[==============================================================================}
function MArrayHelper.Repetited(const rCount: Integer = 1): MArray; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  if ((rCount < 1) or (l = 0)) then
    Exit([]);
  for i := 0 to (Result.SetSize(l * rCount) - 1) do
    Result[i] := Self[i mod l];
end;

{==============================================================================]
  <Repetize>
  @action: Duplicates the elements of the current array a specified number of times sequentially,
           using a goto-driven loop instead of a structured for/while construct.
  @note: If rCount is less than 1 or Self length is 0, an empty array is returned.
[==============================================================================}
function MArrayHelper.Repetize(const rCount: Integer = 1): MArray; overload;
var
  l, r, i: Integer;
label
  loop;
begin
  l := Self.Length;
  if ((rCount < 1) or (l = 0)) then
    Exit([]);
  r := Result.SetSize(l * rCount);
  i := 0;
  loop:
  Result[i] := Self[i mod l];
  if (i.Increment < r) then
    goto loop;
end;

{==============================================================================]
  <Repped>
  @action: Duplicates the elements of the current array a specified number of times sequentially, walking source and destination as raw pointers.
  @note: If rCount is less than 1 or Self length is 0, an empty array is returned.
[==============================================================================}
function MArrayHelper.Repped(const rCount: Integer = 1): MArray; overload;
var
  l, c, i: Integer;
  s, r: MPointer;
begin
  if ((rCount < 1) or (l.Assign(Self.Length) = 0)) then
    Exit([]);
  Result.SetSize(l * rCount);
  r := @Result[0];
  for c := 1 to rCount do
  begin
    s := @Self[0];
    for i := 1 to l do
    begin
      r^ := s^;
      Inc(s);
      Inc(r);
    end;
  end;
end;

{==============================================================================]
  <Reppite>
  @action: Mutates the current array by repeating its original elements a specified number of times in-place,
           walking source and destination as raw pointers.
  @note: Returns the new total length of the array. If rCount is 1 or the array is empty, exits early with no changes.
         If rCount is 0 or negative, the array is cleared and 0 is returned.
[==============================================================================}
function MArrayHelper.Reppite(const rCount: Integer = 1): Integer; overload;
var
  l, c, i: Integer;
  s, r: MPointer;
begin
  l := Self.Length;
  if ((rCount = 1) or (l = 0)) then
    Exit(l);
  if (rCount < 1) then
    Exit(Self.Nullify);
  Result := Self.SetSize(l * rCount);
  r := @Self[l];
  for c := 2 to rCount do
  begin
    s := @Self[0];
    for i := 1 to l do
    begin
      r^ := s^;
      Inc(s);
      Inc(r);
    end;
  end;
end;

{==============================================================================]
  <Reps>
  @action: Repeats the elements of the current array a specified number of times, returning a new concatenated array.
  @note: If rCount is 0 or negative, it returns an empty array. The original array remains unchanged.
[==============================================================================}
function MArrayHelper.Reps(const rCount: Integer = 1): MArray; overload;
var
  l, i: Integer;
begin
  for i := 0 to (Result.SetSize(l.Assign(Self.Length) * Max(0, rCount)) - 1) do
    Result[i] := Self[i mod l];
end;
{$ENDIF}
