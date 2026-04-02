{$IFDEF HELPERS}
function Align(const oAscending: Boolean = True): Integer; overload;
function Aligned(const oAscending: Boolean = True): TRangeArray; overload;
function Ascend: TRangeArray; overload;
function Ascended: TRangeArray; overload;
function Descend: TRangeArray; overload;
function Descended: TRangeArray; overload;
function Redirect: Integer; overload;
function Redirected: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Align>
  @action: Iterates through the array and ensures each range has start ≤ stop 
           if oAscending = True, or start ≥ stop if oAscending = False.
           Swaps start and stop when needed.
  @note: Returns the number of ranges that were modified.
         Does nothing if the array is empty.
[==============================================================================}
function TRangeArrayHelper.Align(const oAscending: Boolean = True): Integer; overload;
var
  P, E: PRange;
  s: Integer;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  P := @Self[0];
  E := (P + Self.Length);
  while (P < E) do
  begin
    if ((oAscending and (P^.start > P^.stop)) or ((not oAscending) and (P^.start < P^.stop))) then
    begin
      s := P^.start;
      P^.start := P^.stop;
      P^.stop := s;
      Inc(Result);
    end;
    Inc(P);
  end;
end;

{==============================================================================]
  <Aligned>
  @action: ?
  @note: ?
[==============================================================================}
function TRangeArrayHelper.Aligned(const oAscending: Boolean = True): TRangeArray; overload;
var
  P, E: PRange;
  r, s: Integer;
begin
  if Self.Empty then
    Exit([]);
  P := @Self[0];
  E := (P + Self.Length);
  SetLength(Result, Self.Length);
  r := 0;
  while (P < E) do
  begin
    if ((oAscending and (P^.start > P^.stop)) or ((not oAscending) and (P^.start < P^.stop))) then
      Result[r.Increase] := TRange.Construct(P^.stop, P^.start)
	else
	  Result[r.Increase] := TRange.Construct(P^.start, P^.stop);
    Inc(P);
  end;
end;

{==============================================================================]
  <Ascend>
  @action: Returns a new range array where each element is transformed using its Ascend method.
  @note: The original array is not modified. The resulting array has the same length as the source array.
[==============================================================================}
function TRangeArrayHelper.Ascend: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Ascend;  
end;

{==============================================================================]
  <Ascended>
  @action: Returns a new range array where each element is replaced with its Ascended result.
  @note: This is a non-mutating operation. The resulting array preserves the original array length.
[==============================================================================}
function TRangeArrayHelper.Ascended: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Ascended;  
end;

{==============================================================================]
  <Descend>
  @action: Returns a new range array where each element is transformed using its Descend method.
  @note: The source array remains unchanged. The result has the same length as the original.
[==============================================================================}
function TRangeArrayHelper.Descend: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Descend;  
end;

{==============================================================================]
  <Descended>
  @action: Returns a new range array where each element is replaced with its Descended result.
  @note: This operation does not modify the original array. The returned array matches the source length.
[==============================================================================}
function TRangeArrayHelper.Descended: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Descended;  
end;

{==============================================================================]
  <Redirect>
  @action: Swaps `start` and `stop` for each range in-place.
  @note: Modifies Self directly. Equivalent to reversing direction of every range.
         Does not validate or normalize bounds. Length unchanged.
         Time complexity: O(n).
[==============================================================================}
function TRangeArrayHelper.Redirect: Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to (Result - 1) do
    Swap(Self[i].start, Self[i].stop);
end;

{==============================================================================]
  <Redirected>
  @action: Returns new array with `start` and `stop` swapped for each range.
  @note: Non-destructive (works on copy). Equivalent to reversing direction
         of every range. Does not validate or normalize bounds.
         Length preserved. Time complexity: O(n).
[==============================================================================}
function TRangeArrayHelper.Redirected: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Result) do
    Result[i] := TRange.Construct(Self[i].stop, Self[i].start);
end;
{$ENDIF}
