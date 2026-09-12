{$IFDEF HELPERS}
function BinaryScan(const item: Boolean; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryScanned(const item: Boolean; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryScanner(const item: Boolean; const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryScanOf(const item: Boolean; const oAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <BinaryScanned>
  @action: Returns an array of all 0-based indices matching the specified item
           in a sorted TBooleanArray using fast boundary checks and O(log N)
           binary search edge resolution.
  @note: Leverages contiguous block properties to avoid full linear iteration.
         Returns an empty array ([]) if item is not present or array is empty.
[==============================================================================}
function TBooleanArrayHelper.BinaryScanned(const item: Boolean; const oAscending: Boolean = True): TIntegerArray; overload;
var
  h, i: Integer;
begin
  h := High(Self);
  case (h > 0) of
    True:
    case (Self[0] = item) of
      True:
      if (Self[h] = item) then
        Result := TRange.Construct(0, h).ToArray
      else
        Result := TRange.Construct(0, Self.BinaryLst(item, oAscending)).ToArray;
      False:
      if (Self[h] = item) then
	    Result := TRange.Construct(Self.Binary1st(item, oAscending), h).ToArray
	  else
        Result := [];
    end;
    False:
	if ((h = 0) and (Self[0] = item)) then
      Result := [0]
	else
	  Result := [];
  end;
end;

{==============================================================================|
  <BinaryScanner>
  @action: Searches a sorted boolean array and returns an array of indices where the target boolean value occurs.
  @note: Uses a dual binary search approach (O(log N)) to find the first and last bounds of the target value.
         Requires array to be sorted according to 'oAscending'.
[==============================================================================}
function TBooleanArrayHelper.BinaryScanner(const item: Boolean; const oAscending: Boolean = True): TIntegerArray; overload;
var
  h: Integer;
  function A(L, R: Integer): Integer;
  var
    m, s: Integer;
  begin
    if (L > R) then
      Exit(-1);
    m := (L + (R - L) div 2);
    if (Self[m] = item) then
    begin
      s := A(L, (m - 1));
      if (s <> -1) then
        Result := s
      else
        Result := m;
    end else if (item = oAscending) then
      Result := A((m + 1), R)
    else
      Result := A(L, (m - 1));
  end;
  function B(L, R: Integer): Integer;
  var
    m, s: Integer;
  begin
    if (L > R) then
      Exit(-1);
    M := (L + (R - L) div 2);
    if (Self[m] = item) then
    begin
      s := B((m + 1), R);
      if (s <> -1) then
        Result := s
      else
        Result := m;
    end else if (item = oAscending) then
      Result := B((m + 1), R)
    else
      Result := B(L, (m - 1));
  end;
begin
  h := High(Self);
  if ((h = -1) or ((Self[0] <> item) and (Self[h] <> item))) then
    Exit([]);
  if ((Self[0] = item) and (Self[h] = item)) then
    Exit(TRange.Construct(0, h).ToArray);
  Result := TRange.Construct(A(0, h), B(0, h)).ToArray;
end;

{==============================================================================|
  <BinaryScanOf>
  @action: Locates the contiguous block of item in a sorted TBooleanArray using
           a single binary search for the block transition point, deriving
           item's range algebraically rather than searching for both edges.
  @note: O(log N) total — one binary search, not two.
[==============================================================================}
function TBooleanArrayHelper.BinaryScanOf(const item: Boolean; const oAscending: Boolean = True): TIntegerArray; overload;
var
  h, s: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit([]);
  s := Self.Binary1st(oAscending, oAscending);
  case (item = oAscending) of
    True:
    if (s > -1) then
      Result := TRange.Construct(s, h).ToArray
    else
      Result := [];
    False:
    if (s = -1) then
      Result := TRange.Construct(0, h).ToArray
    else
      Result := TRange.Construct(0, (s - 1)).ToArray;
  end;
end;
{$ENDIF}
