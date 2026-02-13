{$IFDEF HELPERS}
function Normalize: Integer; overload;
function Normalized: TRangeArray; overload;
function Normalized(out reversedIndices: TIntegerArray): TRangeArray; overload;
function Normally: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
