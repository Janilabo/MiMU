{$IFDEF HELPERS}
function Another: MArray; overload;
function Backup: MArray; overload;
function Carbon: MArray; overload;
function Clonage: MArray; overload;
function Clone: MArray; overload;
function Cloned: MArray; overload;
function Clonement: MArray; overload;
function Clonify: MArray; overload;
function Copied: MArray; overload;
function Copycat: MArray; overload;
function Data(out target: MArray): Integer; overload;
function Data(out aLength: Integer): MArray; overload;
function Data: MArray; overload;
function Detach: MArray; overload;
function Ditto: MArray; overload;
function Dupe: MArray; overload;
function Fork: MArray; overload;
function Imago: MArray; overload;
function Imprint: MArray; overload;
function Proversion: MArray; overload;
function Selfie: MArray; overload;
function Twinned: MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Another>
  @action: Simply returns a copy of array.
  @note: None.
[==============================================================================}
function MArrayHelper.Another: MArray; overload;
var
  h, i, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, l);
  h := (l div 2);
  for i := 0 to (h - 1) do
  begin
    Result[i] := Self[i];
    Result[(l - i) - 1] := Self[(l - i) - 1];
  end;
  if l.Odd then
    Result[h] := Self[h];
end;

{==============================================================================]
  <Backup>
  @action: Creates a shallow copy of the current array by iterating backwards.
  @note: Allocates new memory and populates the result array from the last element to the first.
[==============================================================================}
function MArrayHelper.Backup: MArray; overload;
var
  l: Integer;
begin
  l := Result.SetSize(Self.Length);
  while (l.Decrement > -1) do
    Result[l] := Self[l];
end;

{==============================================================================]
  <Carbon>
  @action: Creates a shallow copy of the current array by dynamically supplying elements into a cleared destination array.
  @note: Initializes a zero-length result and sequentially appends source elements until lengths match.
[==============================================================================}
function MArrayHelper.Carbon: MArray; overload;
var
  r, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, 0);
  r := 0;
  while (r < l) do
    Result.Supply(Self[r.Increase]);
end;

{==============================================================================]
  <Clonage>
  @action: Creates and returns a deep or optimized copy of the current multidimensional or custom array.
  @note: Uses direct small-size optimization for lengths 0 to 3, and a 4-pointer inward-converging 
         loop (C4 procedure) for larger arrays to maximize cache locality and performance.
[==============================================================================}
function MArrayHelper.Clonage: MArray; overload;
  procedure C4(const l, f, b, r: Integer);
  begin
    Result[l] := Self[l];
    Result[f] := Self[f];
    Result[b] := Self[b];
    Result[r] := Self[r];
  end;
var
  s, l, r, b, f, i: Integer;
begin
  s := Self.Length;
  case s of
    0: Exit([]);
    1: Exit([Self[0]]);
    2: Exit([Self[0], Self[1]]);
    3: Exit([Self[0], Self[1], Self[2]]);
  end;
  SetLength(Result, s);
  l := 0;
  r := (s - 1);
  b := (r div 2);
  f := Ceil(r / 2);
  for i := 1 to (s div 2) do
    C4(l.Increase, f.Increase, b.Decrease, r.Decrease);
end;

{==============================================================================]
  <Clone>
  @action: Creates a complete, independent deep-copy of the current array instance.
  @note: Allocates new memory and duplicates all elements. Modifications to the 
         cloned array will not affect the original.
[==============================================================================}
function MArrayHelper.Clone: MArray; overload;
var
  h: Integer;
begin
  if (Result.SetSize(h.Assign(High(Self)) + 1) > 0) then
  repeat
    Result[h] := Self[h];
  until (h.Decrement = -1);
end;

{==============================================================================]
  <Cloned>
  @action: Simply returns a clone of array.
  @note: None.
[==============================================================================}
function MArrayHelper.Cloned: MArray; overload;
var
  r: TRange;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, Self.Size);
  r.Create(-1, Result.Size);
  while (r.start.Increment <= r.stop.Decrement) do
  begin
    Result[r.start] := Self[r.start];
    if (r.start <> r.stop) then
      Result[r.stop] := Self[r.stop];
  end;
end;

{==============================================================================]
  <Clonement>
  @action: Creates and returns a copy of the current MArray using an inline 
           4-pointer indexing strategy.
  @note: Uses direct small-size optimization for lengths 0 to 3. For larger arrays, 
         it mirrors elements inward from the edges (l, r) and outward from the 
         center (b, f) simultaneously, using Inc2/Dec2 to update boundaries.
[==============================================================================}
function MArrayHelper.Clonement: MArray; overload;
var
  d: Double;
  s, b, f, l, r, i, c: Integer;
begin
  s := Self.Length;
  case s of
    0: Exit([]);
    1: Exit([Self[0]]);
    2: Exit([Self[0], Self[1]]);
    3: Exit([Self[0], Self[1], Self[2]]);
  end;
  SetLength(Result, s);
  r := (s - 1);
  d := (r / 2);
  b := Floor(d);
  l := 0;
  f := Ceil(d);
  c := b;
  for i := 1 to c do
  begin
    Result[l] := Self[l];
    Result[b] := Self[b];
    Result[f] := Self[f];
    Result[r] := Self[r];
    Inc2(l, f);
    Dec2(b, r);
  end;
end;

{==============================================================================]
  <Clonify>
  @action: Creates and returns a copy of the current MArray using a parallelized 
           or quadrant-segmented indexing strategy.
  @note: Divides the array into four conceptual segments based on the midpoints 
         (l, m, r) and copies elements into the result array across multiple offset 
         positions simultaneously within a single loop structure.
[==============================================================================}
function MArrayHelper.Clonify: MArray; overload;
var
  i, s, m, l, r: Integer;
begin
  s := Self.Length;
  SetLength(Result, s);
  if (s = 0) then
    Exit;
  m := (s div 2);
  l := (m div 2);
  r := (m + (s - m) div 2);
  for i := 0 to (s - 1) do
  begin
    if (i < l) then
      Result[i] := Self[i];
    if ((i + l) < m) then
      Result[i + l] := Self[i + l];
    if ((i + m) < r) then
      Result[i + m] := Self[i + m];
    if ((i + r) < s) then
      Result[i + r] := Self[i + r];
  end;
end;

{==============================================================================]
  <Copied>
  @action: Simply returns a copy of array.
  @note: None.
[==============================================================================}
function MArrayHelper.Copied: MArray; overload;
begin
  Result := System.Copy(Self);
end;

{==============================================================================]
  <Copycat>
  @action: Creates and returns a new array that is an exact duplicate (clone) of the original array.
  @note: By prepending each element (`[Self[i]] + Result`) while looping backwards (`downto 0`), the original order of the elements is preserved.
         Note that array concatenation in a loop is highly inefficient for large arrays due to continuous memory reallocations.
[==============================================================================}
function MArrayHelper.Copycat: MArray; overload;
var
  i: Integer;
begin
  Result := [];
  for i := High(Self) downto 0 do
    Result := ([Self[i]] + Result);
end;

{==============================================================================]
  <Data>
  @action: Duplicates the array into the 'target' parameter and returns its length.
  @note: Uses Copy() to perform a deep copy if the source contains elements. 
         Otherwise, explicitly clears the 'target' array and returns 0.
[==============================================================================}
function MArrayHelper.Data(out target: MArray): Integer; overload;
begin
  Result := Self.Length;
  if (Result > 0) then
    target := System.Copy(Self, 0, Result)
  else
    SetLength(target, 0);
end;

{==============================================================================]
  <Data>
  @action: Returns a deep copy of the array and outputs its element count via 'aLength'.
  @note: Uses Copy() to perform a deep copy if the source contains elements. 
         Otherwise, explicitly clears the Result array and sets 'aLength' to 0.
[==============================================================================}
function MArrayHelper.Data(out aLength: Integer): MArray; overload;
begin
  aLength := Self.Length;
  if (aLength > 0) then
    Result := System.Copy(Self, 0, aLength)
  else
    SetLength(Result, 0);
end;

{==============================================================================]
  <Data>
  @action: Creates and returns a completely independent, deep copy of the array.
  @note: Direct functional approach using native Copy(). Safely handles empty 
         or unassigned arrays by returning an empty instance.
[==============================================================================}
function MArrayHelper.Data: MArray; overload;
begin
  Result := System.Copy(Self, 0, Self.Length)
end;

{==============================================================================]
  <Detach>
  @action: Decouples the array from any shared memory references by forcing a unique allocation.
  @note: Uses copy-on-write behavior to ensure modifications to the result do not affect the original source.
[==============================================================================}
function MArrayHelper.Detach: MArray; overload;
begin
  Result := Self;
  SetLength(Result, Self.Length);
end;

{==============================================================================]
  <Ditto>
  @action: Returns a new array that is a direct duplicate (clone) of the 
           original array.
  @note: Initializes a range structure spanning from index 0 to the high index 
         of the array. If the target array allocation succeeds, it uses a 
         two-pointer repeat-until loop, copying elements to their identical 
         positions from both ends inward. Relies on custom integer helpers 
         (start.Increment and stop.Decrement) to advance the bounds and 
         terminate the loop.
[==============================================================================}
function MArrayHelper.Ditto: MArray; overload;
var
  R: TRange;
begin
  R.Create(0, High(Self));
  if (Result.SetSize(R.stop + 1) > 0) then
  repeat
    Result[R.start] := Self[R.start];
    Result[R.stop] := Self[R.stop];
  until (R.start.Increment > R.stop.Decrement);
end; 

{==============================================================================]
  <Dupe>
  @action: Returns copy of an array arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Dupe: MArray; overload;
var
  i, l, j: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  if ((l mod 2) <> 0) then
  begin
    j := (l div 2);
    Result[j] := Self[j];
  end;
  if (l > 1) then
  for i := 0 to ((l div 2) - 1) do
  begin
    j := ((l - i) - 1);
    Result[i] := Self[i];
    Result[j] := Self[j];
  end;
end;

{==============================================================================]
  <Fork>
  @action: Concatenates the source array with an empty array.
  @note: Creates a flat, shallow copy (clone) of the array using System.Concat.
[==============================================================================}
function MArrayHelper.Fork: MArray; overload;
begin
  Result := System.Concat(Self, []);
end;

{==============================================================================]
  <Imago>
  @action: Returns a shallow copy of the original array, preserving element order.
  @note: Implements the copy using a `label` and `goto` to iterate backwards from 
         the highest index. The name derives from Latin *imitari* ("to copy"), 
         reflecting that the result imitates the source exactly. Time complexity: 
         O(n). Space complexity: O(n) for the result array. Uses the custom 
         `Integer.Decrement` helper to control the loop. The original array is 
         not modified.
[==============================================================================}
function MArrayHelper.Imago: MArray; overload;
label
  loop;
var
  s: Integer;
begin
  s := (Result.SetSize(Self.Length) - 1);
  if (s < 0) then
    Exit;
  loop:
  Result[s] := Self[s];
  if (s.Decrement > -1) then
    goto loop;
end;

{==============================================================================]
  <Imprint>
  @action: Inserts the source array elements into an empty destination array.
  @note: Creates a flat, shallow copy (clone) of the array using System.Insert.
[==============================================================================}
function MArrayHelper.Imprint: MArray; overload;
begin
  Insert(Self, Result, 0);
end;

{==============================================================================]
  <Proversion>
  @action: Preserves the original forward order of the elements in the MArray 
           and returns an identical copy.
  @note: This is a recursive identity implementation. Because it recursively 
         copies slices of the array, running this on large arrays will cause 
         heavy memory overhead and risks a stack overflow error.
[==============================================================================}
function MArrayHelper.Proversion: MArray; overload;
begin
  if (Self.Length < 2) then
    Exit(Self);
  Result := ([Self[0]] + System.Copy(Self, 1, (Self.Length - 1)).Proversion);
end;

{==============================================================================]
  <Selfie>
  @action: Creates and returns a complete duplicate (clone) of the current array.
  @note: Allocates new memory for the result array and copies elements sequentially.
[==============================================================================}
function MArrayHelper.Selfie: MArray; overload;
var
  i: Integer;
begin
  for i := 0 to (Result.SetSize(Self.Length) - 1) do
    Result[i] := Self[i];
end;

{==============================================================================]
  <Twinned>
  @action: Returns a new array that is a direct duplicate (clone) of the 
           original array.
  @note: Allocates a new array of identical length and uses a two-pointer 
         while-loop meeting in the middle to copy elements from both ends 
         simultaneously. Relies on custom integer helpers (L.Increment and 
         R.Decrement) to adjust bounds and handle iteration.
[==============================================================================}
function MArrayHelper.Twinned: MArray; overload;
var
  L, R: Integer;
begin
  R := Self.Length;
  SetLength(Result, R);
  if (R = 0) then
    Exit;
  L := -1;
  while (L.Increment <= R.Decrement) do
  begin
    Result[L] := Self[L];
    Result[R] := Self[R];
  end;
end;
{$ENDIF}
