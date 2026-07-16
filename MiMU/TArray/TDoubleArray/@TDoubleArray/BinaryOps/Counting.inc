{$IFDEF HELPERS}
function BinaryCount(const x: Double; const aAscending: Boolean = True): Integer;
function BinaryHigherCount(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryLowerCount(const value: Double; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCount>
  @action: Binary Count function for TDoubleArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryCount(const x: Double; const aAscending: Boolean = True): Integer;
var
  r: TRange;
begin
  r := Self.BinaryLocate(x, aAscending);
  Result := IfThen((r.start > -1), r.Size, 0);
end;

{==============================================================================]
  <BinaryHigherCount>
  @action: Returns the number of elements in the array strictly greater than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TDoubleArrayHelper.BinaryHigherCount(const value: Double; const oAscending: Boolean = True): Integer; overload;
var
  p, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  p := Self.BinaryBoundRight(value, oAscending);
  if ((p = -1) or (p > (l - 1))) then
    Result := oAscending.Select(0, l)
  else
    Result := oAscending.Select((l - p), p);
end;

{==============================================================================]
  <BinaryLowerCount>
  @action: Returns the number of elements in the array strictly less than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TDoubleArrayHelper.BinaryLowerCount(const value: Double; const oAscending: Boolean = True): Integer; overload;
var
  p, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  p := Self.BinaryBoundLeft(value, oAscending);
  if ((p = -1) or (p > (l - 1))) then
    Result := oAscending.Select(l, 0)
  else
    Result := oAscending.Select(p, (l - p));
end;
{$ENDIF}
