{$IFDEF HELPERS}
function Highex(const item: MType): Integer; overload;
function Lowex(const item: MType): Integer; overload;

function Extrema(const item: MType): Integer; overload;
function Extreme(const item: MType): Integer; overload;
function Extremify(const item: MType): Integer; overload;
function Extremo(const item: MType): Integer; overload;
function Extremy(const item: MType): Integer; overload;

function Peek(const item: MType): Integer; overload;
function Peep(const item: MType): Integer; overload;

function Firsty: MType; overload;
function Firsty(const null: MType): MType; overload;
function Heady: MType; overload;
function Lasty: MType; overload;
function Lasty(const null: MType): MType; overload;
function Taily: MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================|
  <Highex>
  @action: Returns High(Self) if 'item' matches the last element of the array.
  @note: Executes in O(1) constant time. Safe for empty arrays. Returns -1 if absent.
[==============================================================================}
function MArrayHelper.Highex(const item: MType): Integer; overload;
begin
  if (Self.Length > 0) then
    if (Self[High(Self)] = item) then
      Exit(High(Self));
  Result := -1;
end;

{==============================================================================|
  <Lowex>
  @action: Returns 0 if 'item' matches the first element of the array.
  @note: Executes in O(1) constant time. Safe for empty arrays. Returns -1 if absent.
[==============================================================================}
function MArrayHelper.Lowex(const item: MType): Integer; overload;
begin
  if (Self.Length > 0) then
    if (Self[0] = item) then
      Exit(0);
  Result := -1;
end;

{==============================================================================|
  <Extrema>
  @action: Returns the index (0 or High) where item is found, or -1 if absent.
  @note: Executes in O(1) constant time.
[==============================================================================}
function MArrayHelper.Extrema(const item: MType): Integer; overload;
var
  H: Integer;
begin
  H := High(Self);
  if (H < 0) then
    Exit(-1);
  if (Self[0] = item) then
    Exit(0);
  if (Self[H] = item) then
    Exit(H);
  Result := -1;
end;

{==============================================================================|
  <Extreme>
  @action: Returns the boundary index (High or 0) matching 'item', favoring High if both match.
  @note: Executes in O(1) time. Returns High(Self) if it matches, 0 if only the start matches,
         or -1 if the array is empty or 'item' is absent from both ends.
[==============================================================================}
function MArrayHelper.Extreme(const item: MType): Integer; overload;
begin
  Result := High(Self);
  if ((Result = -1) or (Self[Result] = item)) then
    Exit;
  if (Self[0] = item) then
    Exit(0);
  Result := -1;
end;

{==============================================================================|
  <Extremify>
  @action: Returns 0, High(Self), or -1 using inline conditional evaluation.
  @note: The empty-array guard is a single explicit branch;
         the 0/High(Self)/-1 selection itself is expressed as nested inline conditionals rather than if/then/else.
[==============================================================================}
function MArrayHelper.Extremify(const item: MType): Integer; overload;
begin
  Result := High(Self);
  if (Result > -1) then
    Result := IfThen((Self[Result] = item), Result, IfThen((Self[0] = item), 0, -1));
end;

{==============================================================================|
  <Extremo>
  @action: Returns the first matching boundary index (0 or High), favoring 0 if both match.
  @note: Executes in O(1) constant time. Safe for empty arrays. Returns -1 if 'item' is absent from both ends.
[==============================================================================}
function MArrayHelper.Extremo(const item: MType): Integer; overload;
var
  h: Integer;
begin
  h := High(Self);
  if (h > -1) then
    if (Self[0] = item) then
      Exit(0)
    else if (Self[h] = item) then
      Exit(h);
  Result := -1;
end;

{==============================================================================]
  <Extremy>
  @action: Performs a branchless O(1) edge probe to test if item matches either 
           array boundary (index 0 or High).
  @note: Returns 0 or High(Self) if item exists at an outer endpoint, or -1 if 
         the item does not match either boundary (or if array is empty).
[==============================================================================}
function MArrayHelper.Extremy(const item: MType): Integer; overload;
begin
  Result := High(Self);
  if (Result > -1) then
    Result := (Ord(Self[Result] = item) * ((Result + 1) - Ord(Self[0] = item)) + Ord(Self[0] = item) - 1);
end;

{==============================================================================|
  MArrayHelper.Peek
  @action: Performs a branchless O(1) edge probe against array boundaries.
  @note: Assumes array is non-empty. Returns 0 if index 0 matches, High(Self) 
         if tail matches, or -1 if neither boundary matches item.
[==============================================================================}
function MArrayHelper.Peek(const item: MType): Integer; overload;
begin
  Result := ((Ord(Self[0] = item) - 1) + (Ord((Self[0] <> item) and (Self[High(Self)] = item)) * (High(Self) + 1)));
end;

{==============================================================================]
  <Peep>
  @action: Directly inspects boundary elements and returns 0 or High(Self) if matching 'item'.
  @note: Unguarded O(1) execution. Caller MUST guarantee Length > 0 prior to invocation to avoid Access Violation.
[==============================================================================}
function MArrayHelper.Peep(const item: MType): Integer; overload;
begin
  if (Self[0] = item) then
    Result := 0
  else if (Self[High(Self)] = item) then
    Result := High(Self)
  else
    Result := -1;
end;

{==============================================================================]
  <Firsty>
  @action: Returns the first element (index 0) of the array.
  @note: If the array is empty, the function returns an uninitialized or 
         default value.
[==============================================================================}
function MArrayHelper.Firsty: MType; overload;
begin
  if (Self.Length > 0) then
    Result := Self[0];
end;

{==============================================================================]
  <Firsty>
  @action: Returns the first element of the array, or a provided 
           fallback value if the array is empty.
  @note: Returns null with empty arrays.
[==============================================================================}
function MArrayHelper.Firsty(const null: MType): MType; overload;
begin
  if Self.Empty then
    Result := null
  else
    Result := Self[0];
end;

{==============================================================================]
  <Heady>
  @action: Returns the head (first element) of the array.
  @note: Fast access via index 0. Will throw an out-of-bounds error if the 
         array is completely empty.
[==============================================================================}
function MArrayHelper.Heady: MType; overload;
begin
  Result := Self[0];
end;

{==============================================================================]
  <Lasty>
  @action: Returns the last element of the array.
  @note: If the array is empty, the function returns an uninitialized or 
         default value for MType.
[==============================================================================}
function MArrayHelper.Lasty: MType; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (l > 0) then
    Result := Self[l - 1];
end;

{==============================================================================]
  <Lasty>
  @action: Returns the last element of the array, or a provided fallback 
           value if the array is empty.
  @note: Safe alternative to the parameterless Lasty when dealing with empty arrays.
[==============================================================================}
function MArrayHelper.Lasty(const null: MType): MType; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Result := null
  else
    Result := Self[l - 1];
end;

{==============================================================================]
  <Taily>
  @action: Returns the tail (last element) of the array.
  @note: Uses High() to target the final index. Will throw a range check error 
         if the array is empty.
[==============================================================================}
function MArrayHelper.Taily: MType; overload;
begin
  Result := Self[High(Self)];
end;
{$ENDIF}
