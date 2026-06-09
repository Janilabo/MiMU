{$IFDEF HELPERS}
function AllOf(const candidates: MArray): Boolean; overload;
function Alike(const target: MArray): Boolean; overload;
function AnyOf(const candidates: MArray): Boolean; overload;
function Congruent(const target: MArray): Boolean; overload;
function Differ(const target: MArray): Boolean; overload;
function Empty: Boolean; overload;
function Equal(const target: MArray): Boolean; overload;
function Equivalent(const target: MArray): Boolean; overload;
function Exists: Boolean; overload;
function Identic(const target: MArray): Boolean; overload;
function Identical(const target: MArray): Boolean; overload;
function Includes(const item: MType; const index: Integer = 2147483647): Boolean; overload;
function Multi(const threshold: Integer = 2): Boolean; overload;
function Multi(const threshold: TRange): Boolean; overload;
function NoneOf(const forbidden: MArray): Boolean; overload;
function Occupied: Boolean; overload;
function Oversize(const limit: Integer): Boolean; overload;
function Plain: Boolean; overload;
function Populated(const population: TRange): Boolean; overload;
function Populated(const populationMin: Integer = 1; const populationMax: Integer = 2147483647): Boolean; overload;
function Same(const target: MArray): Boolean; overload;
function Selfsame(const target: MArray): Boolean; overload;
function Singular: Boolean; overload;
function SizeBetween(const sMin, sMax: Integer): Boolean; overload;
function SizeMax(const target: Integer): Boolean; overload;
function SizeMin(const target: Integer): Boolean; overload;
function Twin(const target: MArray): Boolean; overload;
function Undersize(const limit: Integer): Boolean; overload;
function Void: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AllOf>
  @action: Returns True if arr contains all items from candidates.
  @note: Always True if candidates is empty. False if arr is empty but candidates is not.
[==============================================================================}
function MArrayHelper.AllOf(const candidates: MArray): Boolean; overload;
var
  d: specialize TDictionary<MType, Boolean>;
  i: Integer;
begin
  if candidates.Empty then
    Exit(True);
  if Self.Empty then
    Exit(False);
  d := specialize TDictionary<MType, Boolean>.Create;
  try
    for i := 0 to High(Self) do
      d.AddOrSetValue(Self[i], True);
    for i := 0 to High(candidates) do
      if not d.ContainsKey(candidates[i]) then
        Exit(False);
    Result := True;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Alike>
  @action: Compares the current MArray instance with another target MArray to 
           determine if they contain the exact same elements in the same order.
  @note: Validates the arrays in reverse order, starting from the highest index. 
         If lengths mismatch, the loop is bypassed and returns False. A True 
         result is achieved only if the loop successfully decrements past zero.
[==============================================================================}
function MArrayHelper.Alike(const target: MArray): Boolean; overload;
var
  h: Integer;
begin
  h := IfThen((Self.Length = target.Length), High(Self), Low(Integer));
  while ((h > -1) and (Self[h] = target[h])) do
    Dec(h);
  Result := (h = -1);
end; 

{==============================================================================]
  <AnyOf>
  @action: Returns True if arr contains at least one item from candidates.
  @note: Always False if arr or candidates is empty.
[==============================================================================}
function MArrayHelper.AnyOf(const candidates: MArray): Boolean; overload;
var
  d: specialize TDictionary<MType, Boolean>;
  i: Integer;
begin
  Result := False;
  if (Self.Empty or candidates.Empty) then
    Exit;
  d := specialize TDictionary<MType, Boolean>.Create;
  try
    for i := 0 to High(candidates) do
      d.AddOrSetValue(candidates[i], True);
    for i := 0 to High(Self) do
      if d.ContainsKey(Self[i]) then
        Exit(True);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Congruent>
  @action: Compares the current MArray instance with another target MArray to 
           determine if they contain the exact same elements in the same order.
  @note: Leverages a while loop that increments an index pointer as long as elements 
         match. If lengths mismatch, the loop is bypassed and returns False. 
         A True result is only yielded if the index successfully reaches the array length.
[==============================================================================}
function MArrayHelper.Congruent(const target: MArray): Boolean; overload;
var
  i, l: Integer;
begin
  l := IfThen((Self.Length = target.Length), Self.Length, -1);
  i := 0;
  while ((i < l) and (Self[i] = target[i])) do
    Inc(i);
  Result := (i = l);
end;

{==============================================================================]
  <Differ>
  @action: Returns true if arr differs from target.
  @note: None
[==============================================================================}
function MArrayHelper.Differ(const target: MArray): Boolean; overload;
var
  i: Integer;
begin
  Result := (Self.Size <> target.Size);
  if not Result then
  for i := High(Self) downto 0 do
    if (Self[i] <> target[i]) then
      Exit(True);
end;

{==============================================================================]
  <Empty>
  @action: Returns true if array is empty (Length = 0).
  @note: None.
[==============================================================================}
function MArrayHelper.Empty: Boolean; overload;
begin
  Result := (Self.Size = 0);
end;

{==============================================================================]
  <Equal>
  @action: Returns true if arr equals target (identical arrays)
  @note: None
[==============================================================================}
function MArrayHelper.Equal(const target: MArray): Boolean; overload;
var
  i: Integer;
begin
  Result := (Self.Size = target.Size);
  if Result then
  for i := High(Self) downto 0 do
    if (Self[i] <> target[i]) then
      Exit(False);
end;

{==============================================================================]
  <Equivalent>
  @action: Compares the current MArray instance with another target MArray to 
           determine if they contain the exact same elements in the same order.
  @note: Uses an IfThen initialization to pre-evaluate length alignment. If lengths 
         do not match, the loop is skipped and it returns False. Otherwise, it 
         performs a short-circuiting element check.
[==============================================================================}
function MArrayHelper.Equivalent(const target: MArray): Boolean; overload;
var
  i, l: Integer;
begin
  l := IfThen((Self.Length = target.Length), Self.Length, -1);
  for i := 0 to (l - 1) do
    if (Self[i] <> target[i]) then
      Exit(False);
  Result := (l > -1);
end;

{==============================================================================]
  <Exists>
  @action: Returns true if array length is not 0.
  @note: Alternative for arr.Populated.
[==============================================================================}
function MArrayHelper.Exists: Boolean; overload;
begin
  Result := (Self.Size > 0);
end;

{==============================================================================]
  <Identic>
  @action: Compares the current MArray instance with another target MArray to 
           determine if they contain the exact same elements in the same order.
  @note: Uses a while loop with short-circuit evaluation. The loop terminates 
         immediately if a mismatch is found or if the array lengths differ.
[==============================================================================}
function MArrayHelper.Identic(const target: MArray): Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  Result := (l = target.Length);
  i := -1;
  while (Result and (i.Increment < l)) do
    Result := (Self[i] = target[i]);
end;

{==============================================================================]
  <Identical>
  @action: Compares the current MArray instance with another target MArray to 
           determine if they contain the exact same elements in the same order.
  @note: Returns False immediately if the lengths differ or at the first 
         mismatched element (short-circuit evaluation). Performance is O(n).
[==============================================================================}
function MArrayHelper.Identical(const target: MArray): Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l <> target.Length) then
    Exit(False);
  for i := 0 to (l - 1) do
    if (Self[i] <> target[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Includes>
  @action: Looks array for item starting from start index down to index 0. If found, Result will be True.
  @note: Alternative to TArray_Contains, but this scans in opposite direction.
[==============================================================================}
function MArrayHelper.Includes(const item: MType; const index: Integer = 2147483647): Boolean; overload;
var
  i: Integer;
begin
  for i := Min(High(Self), index) downto 0 do
    if (item = Self[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Multi>
  @action: Returns true if array contains at least threshold of items in it.
  @note: None.	
[==============================================================================}
function MArrayHelper.Multi(const threshold: Integer = 2): Boolean; overload;
begin
  Result := (Self.Size >= threshold);
end;

{==============================================================================]
  <Multi>
  @action: Returns true if array contains at least threshold of items in it.
  @note: None.	
[==============================================================================}
function MArrayHelper.Multi(const threshold: TRange): Boolean; overload;
var
  r: TRange;
begin
  r:= threshold.Normalize;
  Result := InRange(Self.Size, r.start, r.stop);
end;

{==============================================================================]
  <NoneOf>
  @action: Returns true if arr does not contain any items from forbidden.
  @note: None.
[==============================================================================}
function MArrayHelper.NoneOf(const forbidden: MArray): Boolean; overload;
var
  d: specialize TDictionary<MType, Boolean>;
  i: Integer;
begin
  Result := True;
  if (Self.Empty or forbidden.Empty) then
    Exit;
  d := specialize TDictionary<MType, Boolean>.Create;
  try
    for i := 0 to High(forbidden) do
      d.AddOrSetValue(forbidden[i], True);
    for i := 0 to High(Self) do
      if d.ContainsKey(Self[i]) then
        Exit(False);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Occupied>
  @action  Returns True if the dynamic array contains one or more elements;
           otherwise returns False.
  @note    Uses Low(Self) <= High(Self) to determine occupancy. This is
           functionally equivalent to Length(Self) > 0.	
[==============================================================================}
function MArrayHelper.Occupied: Boolean; overload;
begin
  Result := (Low(Self) <= High(Self));
end;

{==============================================================================]
  <Oversize>
  @action: Returns true if size of arr is OVER the limit.
  @note: None.	
[==============================================================================}
function MArrayHelper.Oversize(const limit: Integer): Boolean; overload;
begin
  Result := (Self.Size > limit);
end;

{==============================================================================]
  <Plain>
  @action: Returns true if all array items are identical.
  @note: None.
[==============================================================================}
function MArrayHelper.Plain: Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l <= 1) then
    Exit(True);
  for i := 1 to (l - 1) do
    if (Self[i] <> Self[i - 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Populated(population: TRange)>
  @action: Returns true if arr Length is between population TRange (start, stop).
  @note: None.
[==============================================================================}
function MArrayHelper.Populated(const population: TRange): Boolean; overload;
begin
  Result := InRange(Self.Size, population.Minimum, population.Maximum);
end;

{==============================================================================]
  <Populated>
  @action: Returns true if arr Length is between populationMin and populationMax.
  @note: Strict! Min should NOT be higher than Max.
[==============================================================================}
function MArrayHelper.Populated(const populationMin: Integer = 1; const populationMax: Integer = 2147483647): Boolean; overload;
begin
  Result := InRange(Self.Size, populationMin, populationMax);
end;

{==============================================================================]
  <Same>
  @action: Checks whether this array contains the exact same elements in the 
           exact same order as the target array.
  @note: Uses a two-pointer approach, comparing values from both ends inward 
         simultaneously. Returns False immediately if lengths differ.
[==============================================================================}
function MArrayHelper.Same(const target: MArray): Boolean; overload;
var
  L, R: Integer;
begin
  R := Self.Length;
  if (R <> target.Length) then
    Exit(False);
  L := -1;
  while (L.Increment < R.Decrement) do
    if ((Self[L] <> target[L]) or (Self[R] <> target[R])) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Selfsame>
  @action: Checks whether this array contains the exact same elements in the 
           exact same order as the target array.
  @note: Uses a backward loop starting from the maximum index of both arrays. 
         Relies on a try..except block to catch out-of-bounds mismatches.
[==============================================================================}
function MArrayHelper.Selfsame(const target: MArray): Boolean; overload;
var
  i: Integer;
begin
  try
    for i := Max(High(Self), High(target)) downto 0 do
      if (Self[i] <> target[i]) then
        Exit(False);
    Result := True;
  except
    Result := False;
  end;
end;

{==============================================================================]
  <Singular>
  @action: Returns true if all array items are identical.
  @note: None.
[==============================================================================}
function MArrayHelper.Singular: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <SizeBetween>
  @action: Returns true if size is at equal/greater than sMin and equal/lesser than sMax.
  @note: None.
[==============================================================================}
function MArrayHelper.SizeBetween(const sMin, sMax: Integer): Boolean; overload;
begin
  Result := InRange(Self.Size, sMin, sMax);
end;

{==============================================================================]
  <SizeMax>
  @action: Returns true if size is at equal/lesser than target.
  @note: None.
[==============================================================================}
function MArrayHelper.SizeMax(const target: Integer): Boolean; overload;
begin
  Result := (Self.Size <= target);
end;

{==============================================================================]
  <SizeMin>
  @action: Returns true if size is at equal/greater than target.
  @note: None.	
[==============================================================================}
function MArrayHelper.SizeMin(const target: Integer): Boolean; overload;
begin
  Result := (Self.Size >= target);
end;

{==============================================================================]
  <Twin>
  @action: Checks whether this array is an exact structural match (twin) of 
           the target array by verifying lengths and element values.
  @note: Uses a two-pointer inward scan. Short-circuits the loop condition 
         automatically the moment an element mismatch drops Result to False.
[==============================================================================}
function MArrayHelper.Twin(const target: MArray): Boolean; overload;
var
  L, R: Integer;
begin
  R := Self.Length;
  Result := (R = target.Length);
  L := -1;
  while (Result and (L.Increment < R.Decrement)) do
    Result := ((Self[L] = target[L]) and (Self[R] = target[R]));
end;

{==============================================================================]
  <Undersize>
  @action: Returns true if size of arr is UNDER the limit.
  @note: None.	
[==============================================================================}
function MArrayHelper.Undersize(const limit: Integer): Boolean; overload;
begin
  Result := (Self.Size < limit);
end;

{==============================================================================]
  <Void>
  @action: Returns true if array is void (empty)
  @note: Alternative for Empty.
[==============================================================================}
function MArrayHelper.Void: Boolean; overload;
begin
  Result := (Low(Self) > High(Self));
end;
{$ENDIF}