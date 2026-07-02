{$IFDEF HELPERS}
function Repeated(const rCount: Integer = 1): MArray; overload;
function Repeatedly(const rCount: Integer = 1): MArray; overload;
function Repeatify(const rCount: Integer = 1): MArray; overload;
function Repeato(const rCount: Integer = 1): MArray; overload;
function Repeta(const rCount: Integer = 1): MArray; overload;
function Repetat(const rCount: Integer = 1): Integer; overload;
function Repete(const rCount: Integer = 1): MArray; overload;
function Repetite(const rCount: Integer = 1): Integer; overload;
function Repetited(const rCount: Integer = 1): MArray; overload;
function Repetitum(const rCount: Integer = 1): MArray; overload;
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
  <Repeatedly>
  @action: Duplicates the elements of the current array a specified number of times sequentially, using exponential growth via System.Copy calls instead of Move.
  @note: If rCount is less than 1 or Self length is 0, an empty array is returned. Safe for managed types.
[==============================================================================}
function MArrayHelper.Repeatedly(const rCount: Integer = 1): MArray; overload;
var
  l, r, f, c, i: Integer;
  p: MArray;
begin
  l := Self.Length;
  if ((rCount < 1) or (l = 0)) then
    Exit([]);
  r := Result.SetSize(l * rCount);
  for i := 0 to (l - 1) do
    Result[i] := Self[i];
  f := l;
  while (f < r) do
  begin
    c := Min(f, (r - f));
    p := System.Copy(Result, 0, c);
    for i := 0 to (c - 1) do
      Result[f + i] := p[i];
    f += c;
  end;
end;

{==============================================================================]
  <Repeatify>
  @action: Creates a new array by repeating the elements of the source array a specified number of times.
  @note: If rCount is 0 or negative, it safely allocates and returns an empty array.
[==============================================================================}
function MArrayHelper.Repeatify(const rCount: Integer = 1): MArray; overload;
var
  i, r, s: Integer;
begin
  if (Result.SetSize(s.Assign(Self.Length) * Max(0, rCount)) > 0) then
  for i := 0 to (rCount - 1) do
    for r := 0 to (s - 1) do
      Result[(i * s) + r] := Self[r];
end;

{==============================================================================]
  <Repeato>
  @action: Duplicates the elements of the source array sequentially into a new array a specified number of times.
  @note: Uses an internal pointer offset (`l`) to shift the destination block for each repetition pass. Returns an empty array if rCount <= 0.
[==============================================================================}
function MArrayHelper.Repeato(const rCount: Integer = 1): MArray; overload;
var
  i, r, l, s: Integer;
begin
  s := High(Self);
  if (Result.SetSize((s + 1) * Max(0, rCount)) < 0) then
    Exit;
  l := 0;
  for i := 0 to (rCount - 1) do
  begin
    for r := 0 to s do
      Result[r + l] := Self[r];
    Inc(l, (s + 1));
  end;
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
  <Repetat>
  @action: Mutates the current array by repeating its original elements a specified number of times in-place,
           by repeatedly concatenating Self onto itself and reassigning.
  @note: Returns the new total length of the array. If rCount is 1 or the array is empty, exits early with no changes.
         If rCount is 0 or negative, the array is cleared and 0 is returned. Safe for managed types.
[==============================================================================}
function MArrayHelper.Repetat(const rCount: Integer = 1): Integer; overload;
var
  original, c: Integer;
  s: MArray;
begin
  if ((rCount = 1) or (Self.Length = 0)) then
    Exit(Self.Length);
  if (rCount < 1) then
    Result := Self.Nullify;
  s := Self;
  for c := 2 to rCount do
    Self := System.Concat(Self, s);
  Result := Self.Length;
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
  <Repetitum>
  @action: Duplicates the elements of the current array a specified number of times sequentially, by repeated Concat accumulation.
  @note: If rCount is less than 1 or Self length is 0, an empty array is returned. Safe for managed types.
[==============================================================================}
function MArrayHelper.Repetitum(const rCount: Integer = 1): MArray; overload;
var
  c: Integer;
begin
  if ((rCount < 1) or (Self.Length = 0)) then
    Exit([]);
  Result := Self.Clone;
  for c := 2 to rCount do
    Result := System.Concat(Result, Self);
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
