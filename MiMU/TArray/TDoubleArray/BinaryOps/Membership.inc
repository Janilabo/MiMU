{$IFDEF HELPERS}
function BinaryContains(const x: Double; const aAscending: Boolean = True): Boolean;
function BinaryExcludes(const value: Double; const oAscending: Boolean = True): Boolean; overload;
function BinaryExists(const value: Double; const oAscending: Boolean = True): Boolean; overload;
function BinaryFit(const value: Double; const oAscending: Boolean = True): Boolean; overload;
function BinaryIncludes(const value: Double; const oAscending: Boolean = True): Boolean; overload;
function BinaryUnfit(const value: Double; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryContains>
  @action: Binary Contains function for TDoubleArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryContains(const x: Double; const aAscending: Boolean = True): Boolean;
begin
  Result := (Self.BinarySearch(x, aAscending) > -1);
end;

{==============================================================================]
  <BinaryExcludes>
  @action: Determines whether the specified value does not exist in this array
           by using a binary search. The array is assumed to be pre-sorted in
           the order specified by oAscending.
  @note: Performs boundary checks before invoking the binary search. Returns
         True if the array is empty, if the value lies outside the array’s
         sorted bounds, or if the binary search fails to locate the value.
[==============================================================================}
function TDoubleArrayHelper.BinaryExcludes(const value: Double; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := (Self.BinaryUnfit(value, oAscending) or (Self.BinaryPos(value, oAscending) = -1));
end;

function TDoubleArrayHelper.BinaryExists(const value: Double; const oAscending: Boolean = True): Boolean; overload;
  function BS(const L, R: Integer): Boolean;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(False);
    M := (L + ((R - L) div 2));
    if (Self[M] = value) then
      Exit(True);
    if ((oAscending and (value < Self[M])) or ((not oAscending) and (value > Self[M]))) then
      Result := BS(L, (M - 1))
    else
      Result := BS((M + 1), R);
  end;
begin
  Result := BS(0, High(Self));
end;

{==============================================================================]
  <BinaryFit>
  @action: Returns True if the specified value falls within the sortable domain
           represented by the current array. In other words, it verifies that
           the value is within the inclusive bounds defined by the first and
           last elements of the array, assuming that the array is sorted in the
           direction indicated by oAscending.
  @note: This function does not perform a binary search. It simply checks
         whether the value is eligible for a binary lookup or insertion
         attempt. For empty arrays, the function always returns False. When
         oAscending = False, the comparison logic is inverted to support
         descending-sorted arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryFit(const value: Double; const oAscending: Boolean = True): Boolean; overload;
begin
  if oAscending then
    Result := ((not Self.Empty) and (value >= Self[0]) and (value <= Self[High(Self)]))
  else
    Result := ((not Self.Empty) and (value <= Self[0]) and (value >= Self[High(Self)]));
end;

{==============================================================================]
  <BinaryIncludes>
  @action: Determines whether the specified value exists in this array by using
           a binary search. The array is assumed to be pre-sorted in the order
           specified by oAscending.
  @note: Performs boundary checks before invoking the binary search for
         efficiency. Returns True only if the array is non-empty, the value
         lies within the array’s sorted bounds, and the binary search locates
         the element.
[==============================================================================}
function TDoubleArrayHelper.BinaryIncludes(const value: Double; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := (Self.BinaryFit(value, oAscending) and (Self.BinaryPos(value, oAscending) > -1));
end;

{==============================================================================]
  <BinaryUnfit>
  @action: Returns True if the specified value is outside the inclusive bounds
           of the array, or if the array is empty. This indicates that the
           value cannot exist in the array and is not a candidate for a binary
           search within the current bounds.
  @note: This routine is essentially the logical inverse of BinaryFit. It is
         useful as a pre-check before performing binary search or before
         attempting bounded insertion logic. When oAscending = False, the
         boundary comparisons are reversed to support descending-sorted
         arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryUnfit(const value: Double; const oAscending: Boolean = True): Boolean; overload;
begin
  if oAscending then
    Result := (Self.Empty or (value < Self[0]) or (value > Self[High(Self)]))
  else
    Result := (Self.Empty or (value > Self[0]) or (value < Self[High(Self)]));
end;
{$ENDIF}
