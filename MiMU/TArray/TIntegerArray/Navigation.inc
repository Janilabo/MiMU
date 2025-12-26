{$IFDEF HELPERS}
function Succ(const currentIndex: Integer; const range: TRange): Integer; overload;
function Pred(const currentIndex: Integer; const range: TRange): Integer; overload;
function Successor(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
function Predecessor(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
function Next(const currentIndex: Integer; const range: TRange): Integer; overload;
function Previous(const currentIndex: Integer; const range: TRange): Integer; overload;
function Navigate(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Succ>
  @action: Returns the next array index (currentIndex + 1).
  @note: If the next index is out of array bounds or the value is missing
         according to the provided range, returns -1. Does not skip multiple
         missing values.
[==============================================================================}
function TIntegerArrayHelper.Succ(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := (currentIndex + 1);
  if ((Result > High(Self)) or range.Missing(Self[Result])) then
    Result := -1;
end;

{==============================================================================]
  <Pred>
  @action: Returns the previous array index (currentIndex - 1).
  @note: If the previous index is out of array bounds or the value is missing
         according to the provided range, returns -1. Does not skip multiple
         missing values.
[==============================================================================}
function TIntegerArrayHelper.Pred(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := currentIndex - 1;
  if ((Result < 0) or range.Missing(Self[Result])) then
    Result := -1;
end;

{==============================================================================]
  <Successor>
  @action: Returns the next valid array index in the specified direction.
  @note: If aAscending = True, moves forward; if False, moves backward.
         Skips over elements considered missing by the range.
         Returns -1 if the end of array or invalid values are reached.
[==============================================================================}
function TIntegerArrayHelper.Successor(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
var
  d: Integer;
begin
  d := aAscending.Select(1, -1);
  Result := (currentIndex + d);
  while (InRange(Result, 0, High(Self)) and range.Missing(Self[Result])) do
    Result := (Result + d);
  if ((Result < 0) or (Result > High(Self))) then
    Result := -1;
end;

{==============================================================================]
  <Predecessor>
  @action: Returns the previous valid array index in the specified direction.
  @note: If aAscending = True, moves backward; if False, moves forward.
         Skips over elements considered missing by the range.
         Returns -1 if the beginning of array or invalid values are reached.
[==============================================================================}
function TIntegerArrayHelper.Predecessor(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
var
  d: Integer;
begin
  d := aAscending.Select(-1, 1);
  Result := (currentIndex + d);
  while (InRange(Result, 0, High(Self)) and range.Missing(Self[Result])) do
    Result := (Result + d);
  if ((Result < 0) or (Result > High(Self))) then
    Result := -1;
end;

{==============================================================================]
  <Next>
 @action: Returns the next valid array index by moving forward (incrementing).
  @note: Starts from currentIndex + 1 and skips over any elements that
         range.Missing considers invalid. Returns -1 if no valid element is
         found or the end of the array is reached.
[==============================================================================}
function TIntegerArrayHelper.Next(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := (currentIndex + 1);
  while ((Result <= High(Self)) and range.Missing(Self[Result])) do
    Inc(Result);
  if (Result > High(Self)) then
    Result := -1;
end;

{==============================================================================]
  <Previous>
  @action: Returns the previous valid array index by moving backward (decrementing).
  @note: Starts from currentIndex - 1 and skips over any elements that
         range.Missing considers invalid. Returns -1 if no valid element is
         found or the beginning of the array is reached.
[==============================================================================}
function TIntegerArrayHelper.Previous(const currentIndex: Integer; const range: TRange): Integer; overload;
begin
  Result := (currentIndex - 1);
  while ((Result >= 0) and range.Missing(Self[Result])) do
    Dec(Result);
  if (Result < 0) then
    Result := -1;
end;

{==============================================================================]
  <Navigate>
  @action: Returns the next valid array index in the specified direction.
  @note: Starts from currentIndex and moves forward if aAscending = True,
         backward if aAscending = False. Skips over any elements that are
         considered missing according to the provided range.
         Returns -1 if no valid element exists before reaching the array bounds.
[==============================================================================}
function TIntegerArrayHelper.Navigate(const currentIndex: Integer; const range: TRange; const aAscending: Boolean = True): Integer; overload;
var
  s: Integer;
begin
  s := aAscending.Select(1, -1);
  Result := (currentIndex + s);
  while (InRange(Result, 0, High(Self)) and range.Missing(Self[Result])) do
    Result := (Result + s);
  if (Result < 0) or (Result > High(Self)) then
    Result := -1;
end;
{$ENDIF}
