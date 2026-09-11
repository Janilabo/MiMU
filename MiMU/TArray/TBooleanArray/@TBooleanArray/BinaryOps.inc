{$IFDEF HELPERS}
function BinaryCount(const item: Boolean; const oAscending: Boolean = True): Integer; overload;

function BinaryFind(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
function BinarySearch(const item: Boolean; const oAscending: Boolean = True): Integer; overload;

function Binary1st(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
function BinaryLst(const item: Boolean; const oAscending: Boolean = True): Integer; overload;

function BinaryScan(const item: Boolean; const oAscending: Boolean = True): TIntegerArray; overload;

function BinaryPivot(const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================|
  BinaryCount
  @action: Returns the exact number of occurrences of item in the sorted array.
  @note: Runs in O(log N) time using boundary lookups.
[==============================================================================}
function TBooleanArrayHelper.BinaryCount(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Binary1st(item, oAscending);
  if (Result = -1) then
    Exit(0);
  Result := ((Self.BinaryLst(item, oAscending) - Result) + 1);
end;

{==============================================================================|
  <BinaryFind>
  @action: Returns an arbitrary matching index in O(1) time by checking array
           boundaries rather than running a loop.
  @note: TBooleanArray.BinarySearch (O(1) Branchless Boundary Check)
[==============================================================================}
function TBooleanArrayHelper.BinaryFind(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
var
  H: Integer;
begin
  Result := High(Self);
  if (Result = -1) then
    Exit;
  if (Self[Result] = item) then
    Exit;
  if (Self[0] = item) then
    Exit(0);
  Result := -1;
end;

{==============================================================================|
  <BinarySearch>
  @action: Searches for item in a sorted TBooleanArray.
  @note: Returns an index where item occurs, or -1 if item is not found.
[==============================================================================}
function TBooleanArrayHelper.BinarySearch(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
var
  L, R, M: Integer;
begin
  L := 0;
  R := High(Self);
  while (L <= R) do
  begin
    M := (L + (R - L) div 2);
    if (Self[M] = item) then
      Exit(M);
    if (item = oAscending) then
      L := (M + 1)
    else
      R := (M - 1);
  end;
  Result := -1;
end;

{==============================================================================|
  <Binary1st>
  @action: Returns the VERY FIRST occurrence index of item.
  @note: O(log N) Single-Boundary Binary Search.
[==============================================================================}
function TBooleanArrayHelper.Binary1st(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
var
  H, L, R, M: Integer;
begin
  H := High(Self);
  if (H = -1) then
    Exit(-1);
  if (Self[0] = item) then
    Exit(0);
  if (Self[H] <> item) then
    Exit(-1);
  L := 0;
  R := H;
  Result := -1;
  while (L <= R) do
  begin
    M := (L + (R - L) div 2);
    case (Self[M] = item) of
      True:
      begin
        Result := M;
        R := (M - 1);
      end;
      False:
      if (item = oAscending) then
        L := (M + 1)
      else
        R := (M - 1);
    end;
  end;
end;

{==============================================================================|
  <BinaryLst>
  @action: Returns the VERY LAST index of item in a sorted TBooleanArray.
  @note: Returns -1 if item is not found in the array.
[==============================================================================}
function TBooleanArrayHelper.BinaryLst(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
var
  H, L, R, M: Integer;
begin
  H := High(Self);
  if (H = -1) then
    Exit(-1);
  if (Self[H] = item) then
    Exit(H);
  if (Self[0] <> item) then
    Exit(-1);
  L := 0;
  R := H;
  Result := -1;
  while (L <= R) do
  begin
    M := (L + (R - L) div 2);
    case (Self[M] = item) of
      True:
      begin
        Result := M;
        L := (M + 1);
      end;
      False:
      if (item = oAscending) then
        L := (M + 1)
      else
        R := (M - 1);
    end;
  end;
end;

{==============================================================================|
  TBooleanArray.BinaryScan
  @action: Uses binary search to locate the full contiguous block of item in a
           sorted TBooleanArray and returns all matching array indices.
  @note: Runs in O(log N + K) time, where K is the number of matching elements.
         Returns an empty TIntegerArray if item is not found.
[==============================================================================}
function TBooleanArrayHelper.BinaryScan(const item: Boolean; const oAscending: Boolean = True): TIntegerArray; overload;
var
  r, i: Integer;
begin
  r := Self.Binary1st(item, oAscending);
  if (r = -1) then
    Exit([]);
  for i := 0 to Result.Alloc((Self.BinaryLst(item, oAscending) - r) + 1) do
    Result[i] := (r + i);
end;

{==============================================================================|
  <BinaryPivot>
  @action: Returns the starting index of the second partition in the sorted array.
           - Ascending [F, F, T, T]: Returns index of the FIRST True.
           - Descending [T, T, F, F]: Returns index of the FIRST False.
  @note: Returns Self.Length if the array contains only one uniform value type.
[==============================================================================}
function TBooleanArrayHelper.BinaryPivot(const oAscending: Boolean = True): Integer; overload;
begin
  if oAscending then
    Result := Self.Binary1st(True, True)
  else
    Result := Self.Binary1st(False, False);
  if (Result = -1) then
    Result := Self.Length;
end;
{$ENDIF}
