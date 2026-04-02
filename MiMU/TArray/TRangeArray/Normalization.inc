{$IFDEF HELPERS}
function AsNormal: TRangeArray; overload;
function AsNormalized: TRangeArray; overload;
function Normalize: Integer; overload;
function Normalized: TRangeArray; overload;
function Normalized(out reversedIndices: TIntegerArray): TRangeArray; overload;
function Normalizify: Integer; overload;
function Normally: TRangeArray; overload;
function Normed: TRangeArray; overload;
function ToNormal: TRangeArray; overload;
function ToNormalized: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsNormal>
  @action: Returns a copy of the array with all ranges normalized to ascending order.
  @note: Only descending ranges are modified; original array remains unchanged.
[==============================================================================}
function TRangeArrayHelper.AsNormal: TRangeArray; overload;
var
  i: Integer;
begin
  Result := Self.Copy;
  for i := 0 to High(Result) do
    if Result[i].Descending then
      Swap(Result[i].start, Result[i].stop);
end;

{==============================================================================]
  <AsNormalized>
  @action: Returns the current TRangeArray if all ranges are already normalized
           (i.e. start ≤ stop). If any range is descending, returns a new array
           with all ranges normalized.
  @note: - Avoids unnecessary allocation by returning Self when possible.
         - Calls ToNormal only when a descending range is detected.
         - The original array is not modified.
[==============================================================================}
function TRangeArrayHelper.AsNormalized: TRangeArray; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if Self[i].Descending then
      Exit(Self.ToNormal);
  Result := Self;
end;

{==============================================================================]
  <Normalize>
  @action: Normalizes all ranges in-place by ensuring Start <= Stop.
           For each descending range, Start and Stop are swapped.
  @return: The number of ranges that were modified (i.e. originally descending).
  @note: This method mutates the array contents. No memory is allocated.
         Complexity: O(n).
[==============================================================================}
function TRangeArrayHelper.Normalize: Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    if Self[i].Descending then
    begin
	  Inc(Result);
	  Swap(Self[i].start, Self[i].stop);
    end;
end;

{==============================================================================]
  <Normalized>
  @action: Returns a new array containing normalized copies of all ranges
           (each with Start <= Stop).
  @return: A newly allocated array of normalized ranges.
  @note: The original array remains unchanged. Allocates a new dynamic array of equal length.
         Complexity: O(n).
[==============================================================================}
function TRangeArrayHelper.Normalized: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i].Create(Min(Self[i].start, Self[i].stop), Max(Self[i].start, Self[i].stop));
end;

{==============================================================================]
  <Normalized>
  @action: Returns a normalized copy of the range array in which all ranges are
           guaranteed to be ascending (Start <= Stop).
           Any range whose Descending property is True is inverted by swapping
           its Start and Stop boundaries in the resulting array.
           Returns a new TRangeArray of the same length as Self where all ranges are
           ascending.
  @note:
    - The original array (Self) is not modified.
    - The operation runs in O(n) time and allocates O(n) additional memory.
    - The order of elements is preserved.
    - reversedIndices preserves the encounter order of reversed elements.
[==============================================================================}
function TRangeArrayHelper.Normalized(out reversedIndices: TIntegerArray): TRangeArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Self.Length);
  SetLength(reversedIndices, Self.Length);
  r := 0;
  for i := 0 to High(Self) do
    if Self[i].Descending then
	begin
      Result[i].Create(Self[i].stop, Self[i].start);
      reversedIndices[r.Increase] := i;
    end else
      Result[i] := Self[i];
  SetLength(reversedIndices, r);
end;

{==============================================================================]
  <Normalizify>
  @action: Normalizes all descending ranges in-place and counts how many were normalized.
  @note: Returns number of modified ranges; uses XOR-swap on bounds.
[==============================================================================}
function TRangeArrayHelper.Normalizify: Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to High(Self) do
    if Self[i].Descending then
    begin
      Self[i].start := (Self[i].start xor Self[i].stop);
      Self[i].stop := (Self[i].start xor Self[i].stop);
      Self[i].start := (Self[i].start xor Self[i].stop);
    end else
      Dec(Result);
end;

{==============================================================================]
  <Normally>
  @action: Returns a new array in which all ranges are in ascending order
           (Start <= Stop). Descending ranges are reversed.
  @return: A newly allocated array containing normalized copies of the ranges.
  @note: The original array remains unchanged.
         Allocates a new dynamic array of equal length. Equivalent in effect to Normalized.
         Complexity: O(n).
[==============================================================================}
function TRangeArrayHelper.Normally: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    if Self[i].Ascending then
	  Result[i] := Self[i]
	else
	  Result[i] := Self[i].Reversed;
end;

{==============================================================================]
  <Normed>
  @action: Normalize ranges to ascending order (start <= stop)
  @note: New array with all ranges ordered and direction corrected
[==============================================================================}
function TRangeArrayHelper.Normed: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Result) do
    if Self[i].Descending then
      Result[i] := TRange.Construct(Self[i].stop, Self[i].start)
    else
      Result[i] := Self[i];
end;

{==============================================================================]
  <ToNormal>
  @action: Returns a new TRangeArray where each range that has start > stop
           is swapped (start and stop are reversed). Ranges already in normal
           order are copied as-is.
  @note: - Uses an auxiliary index array to track ranges needing swapping.
         - Preserves the original array order.
         - Safe for empty arrays.
[==============================================================================}
function TRangeArrayHelper.ToNormal: TRangeArray; overload;
var
  i, l, n: Integer;
  f: TIntegerArray;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  SetLength(f, l);
  n := 0;
  for i := 0 to (l - 1) do
    if (Self[i].start > Self[i].stop) then
      f[n.Increase] := i
	else
      Result[i] := Self[i];
  for i := 0 to (n - 1) do
    Result[f[i]] := TRange.Construct(Self[f[i]].stop, Self[f[i]].start);
end;

{==============================================================================]
  <ToNormalized>
  @action: Returns a new TRangeArray where all ranges are normalized such that
           start ≤ stop. If all ranges are already normalized, returns a copy
           of the original array.
  @note: - Uses Min and Max to normalize each range.
         - Efficiently checks if normalization is needed before constructing
           a new array.
         - Safe for empty arrays.
[==============================================================================}
function TRangeArrayHelper.ToNormalized: TRangeArray; overload;
var
  i: Integer;
  f: Boolean;
begin
  if Self.Empty then
    Exit([]);
  f := False;
  for i := 0 to High(Self) do
    if (Self[i].start > Self[i].stop) then
    begin
      f := True;
      Break;
    end;
  if not f then
    Exit(Self.Copy);
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := TRange.Construct(Min(Self[i].start, Self[i].stop), Max(Self[i].start, Self[i].stop));
end;
{$ENDIF}
