{$IFDEF HELPERS}
function Advance(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
function Retreat(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Advance>
  @action: Moves forward through the array (respecting ascending/descending order)
           starting from currentIndex, and searches for the next value that falls
           within the specified range.
  @note: - Traverses one element at a time in the order defined by aAscending.
         - If the sequence order is broken (e.g., next value < previous in ascending order),
           the function stops and returns -1.
         - Returns the index of the first matching element found, or -1 if
           the end of the array is reached or no valid element is found.
[==============================================================================}
function TIntegerArrayHelper.Advance(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
begin
  Result := currentIndex;
  case aAscending of
    True:
    while InRange(Result.Increment, 0, High(Self)) do
      if (Self[Result] < Self[Result - 1]) then
        Exit(-1)
      else if range.Contains(Self[Result]) then
        Exit(Result);
    False:
    while InRange(Result.Increment, 0, High(Self)) do
      if (Self[Result] > Self[Result - 1]) then
        Exit(-1)
      else if range.Contains(Self[Result]) then
        Exit(Result);
  end;
  Result := -1;
end;

{==============================================================================]
  <Retreat>
  @action: Moves backward through the array (respecting ascending/descending order)
           starting from currentIndex, and searches for the previous value that falls
           within the specified range.
  @note: - Traverses one element at a time in reverse order, as defined by aAscending.
         - If the sequence order is broken (e.g., previous value > next in ascending order),
           the function stops and returns -1.
         - Returns the index of the first matching element found, or -1 if
           the beginning of the array is reached or no valid element is found.
[==============================================================================}
function TIntegerArrayHelper.Retreat(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
begin
  Result := currentIndex;
  case aAscending of
    True:
    while InRange(Result.Decrement, 0, High(Self)) do
      if (Self[Result] < Self[Result - 1]) then
        Exit(-1)
      else if range.Contains(Self[Result]) then
        Exit(Result);
    False:
    while InRange(Result.Decrement, 0, High(Self)) do
      if (Self[Result] > Self[Result - 1]) then
        Exit(-1)
      else if range.Contains(Self[Result]) then
        Exit(Result);
  end;
  Result := -1;
end;
{$ENDIF}