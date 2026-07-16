{$IFDEF HELPERS}
function BinaryEncase(const item: MType): Boolean; overload;
function BinaryHasVariance: Boolean; overload;
function BinaryIsConstant: Boolean; overload;
function BinaryIsUnique: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryEncase>
  @action: Determines whether the specified item falls within the range of values
           in a sorted array. The function returns True if the item is greater
           than or equal to the smallest element and less than or equal to the
           largest element, regardless of whether the array is ascending or
           descending.
  @note: Works for arrays of any length, including empty arrays.
         - Returns False for empty arrays.
         - Correctly handles both ascending and descending order arrays.
         - Only checks the array’s first and last elements; does not search
           for exact membership.
[==============================================================================}
function MArrayHelper.BinaryEncase(const item: MType): Boolean; overload;
var
  b, t: MType;
  h: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit(False);
  if (Self[0] < Self[h]) then
  begin
    b := Self[0];
    t := Self[h];
  end else
  begin
    b := Self[h];
    t := Self[0];
  end;
  Result := ((item >= b) and (item <= t));
end;

{==============================================================================]
  <BinaryHasVariance>
  @action: Returns True if the sorted array contains more than one distinct value.
  @note:
    • O(1)
    • Requires sorted array
    • Compares first and last elements only
    • False if array has zero or one element
[==============================================================================}
function MArrayHelper.BinaryHasVariance: Boolean; overload;
var
  H: Integer;
begin
  H := High(Self);
  Result := ((H > 0) and (Self[0] <> Self[H]));
end;

{==============================================================================]
  <BinaryIsConstant>
  @action: Returns True if all elements in the sorted array are equal.
  @note:
    • O(1)
    • Requires sorted array
    • Compares first and last elements
    • False if array is empty
[==============================================================================}
function MArrayHelper.BinaryIsConstant: Boolean; overload;
var
  H: Integer;
begin
  H := High(Self);
  Result := ((H > -1) and (Self[0] = Self[H]));
end;

{==============================================================================]
  <BinaryIsUnique>
  @action: Returns True if the sorted array contains no duplicate values.
  @note:
    • O(n)
    • Requires sorted array
    • Adjacent elements are compared
    • False if array is empty
[==============================================================================}
function MArrayHelper.BinaryIsUnique: Boolean; overload;
var
  i, h: Integer;
begin
  h := High(Self);
  for i := 0 to (h - 1) do
    if (Self[i] = Self[i + 1]) then
      Exit(False);
  Result := (h > -1);
end;
{$ENDIF}
