{$IFDEF HELPERS}
function AllDistinct: Boolean; overload;
function AllEqual: Boolean; overload;
function AllSame: Boolean; overload;
function AllUnique: Boolean; overload;
function Equalized(const rIndex: Integer = 0): Boolean; overload;
function Excessive: Boolean; overload;
function Fits(const maxValue: Integer): Boolean; overload;
function Fits(const target: TRange): Boolean; overload;
function Heterogeneous: Boolean; overload;
function Homogeneous(const item: MType): Boolean; overload;
function Homogeneous: Boolean; overload;
function IsConstant(const item: MType): Boolean; overload;
function IsConstant: Boolean; overload;
function IsDistinct: Boolean; overload;
function Palindrome: Boolean; overload;
function Stationary: Boolean; overload;
function Symmetrical: Boolean; overload;
function Uniform: Boolean; overload;
function Uniform(const item: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AllDistinct>
  @action: Returns True if all elements contained in the array are pairwise distinct.
           Returns False immediately when a duplicate element is detected.
  @note:
    • Arrays with fewer than two elements are considered distinct by definition.
    • Uniqueness is determined using the equality and hash semantics (THashSet).
[==============================================================================}
function MArrayHelper.AllDistinct: Boolean; overload;
var
  h: specialize THashSet<MType>;
  i: MType;
begin
  if (Self.Length < 2) then
    Exit(True);
  h := specialize THashSet<MType>.Create;
  try
    for i in Self do
      if not h.Add(i) then
        Exit(False);
    Result := True;
  finally
    h.Free;
  end;
end;

{==============================================================================]
  <AllEqual>
  @action: Returns true if all values in arr are equal (arr contains only equal values).
  @note: Returns FALSE with empty array!
[==============================================================================}
function MArrayHelper.AllEqual: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[0] <> Self[i]) then
      Exit(False);
  Result := (Self.Length > 0);
end;

{==============================================================================]
  <AllSame>
  @action: Returns true if all values in arr are the same (arr contains only equal values).
  @note: Returns FALSE with empty array!
[==============================================================================}
function MArrayHelper.AllSame: Boolean; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  Result := (l > 0);
  i := 0;
  while (Result and (i.Increment < l)) do
    Result := (Self[0] = Self[i]);
end;

{==============================================================================]
  <AllUnique>
  @action: Returns true if all values in arr are unique (arr contains ONLY unique values).
  @note: None
[==============================================================================}
function MArrayHelper.AllUnique: Boolean; overload;
var
  h, a, b: Integer;
begin
  h := High(Self);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if (Self[a] = Self[b]) then
        Exit(False);
  Result := (h > -1);
end;

{==============================================================================]
  <Equalized>
  @action: Checks whether all elements in the integer array are equal to each other.
           Uses a recursive comparison starting from the specified index.
  @note:
    • Returns False for an empty array.  
    • If rIndex >= High(Self), the recursion has reached the last element,
      so the remaining array is trivially equal.  
    • Recursively compares each element to the next element in the array.
[==============================================================================}
function MArrayHelper.Equalized(const rIndex: Integer = 0): Boolean; overload;
begin
  if Self.Empty then
    Exit(False);
  if (rIndex >= High(Self)) then
    Exit(True);
  Result := ((Self[rIndex] = Self[rIndex + 1]) and Self.Equalized(rIndex + 1));
end;

{==============================================================================]
  <Excessive>
  @action: Returns true if arr contains any duplicates in it.
  @note: None.
[==============================================================================}
function MArrayHelper.Excessive: Boolean; overload;
type
  TDict = specialize TDictionary<MType, Boolean>;
var
  d: TDict;
  i: Integer;
begin
  d := TDict.Create;
  try
    for i := Low(Self) to High(Self) do
      if not d.ContainsKey(Self[i]) then
        d.Add(Self[i], True)
      else
        Exit(True);
  finally
    d.Free;
  end;
  Result := False;
end;

{==============================================================================]
  <Fits>
  @action: Returns true if arr size is at maximum maxValue.
  @note: None.
[==============================================================================}
function MArrayHelper.Fits(const maxValue: Integer): Boolean; overload;
begin
  Result := (Self.Size <= maxValue);
end;

{==============================================================================]
  <Fits>
  @action: Returns true if arr size is between target start and stop.
  @note: None.
[==============================================================================}
function MArrayHelper.Fits(const target: TRange): Boolean; overload;
begin
  Result := InRange(Self.Size, Min(target.start, target.stop), Max(target.start, target.stop));
end;

{==============================================================================]
  <Heterogeneous>
  @action: Returns True if the array is non-empty and all elements are pairwise
           distinct (i.e. no two elements are equal).
  @note:
    • Returns False for an empty array.
    • Uses a recursive pairwise comparison strategy.
    • Time complexity: O(n²).
    • Space complexity: O(n) due to recursion depth.
    • Equality is evaluated using the = operator of MType.
    • Functionally equivalent to an injectivity/distinctness check,
      but significantly less efficient than hash- or sort-based methods.
[==============================================================================}
function MArrayHelper.Heterogeneous: Boolean; overload;
var
  h: Integer;
  function Check(const idx: Integer): Boolean;
  var
    i: Integer;
  begin
    if (idx >= h) then
      Exit(True);
    for i := (idx + 1) to h do
      if (Self[i] = Self[idx]) then
        Exit(False);
    Result := Check(idx + 1);
  end;
begin
  h := High(Self);
  Result := ((h > -1) and Check(0));
end;

{==============================================================================]
  <Homogeneous>
  @action: Returns true if arr consists of ONLY same items.
  @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function MArrayHelper.Homogeneous(const item: MType): Boolean; overload;
var
  h, i: Integer;
begin
  i := -1;
  h := High(Self);
  Result := (h > -1);
  while (Result and (i.Increase < h)) do
    Result := (Self[i] = item);
end;

{==============================================================================]
  <Homogeneous>
  @action: Returns true if arr consists of ONLY same items.
  @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function MArrayHelper.Homogeneous: Boolean; overload;
begin
  Result := (Self.Exists and Homogeneous(Self[0]));
end;

{==============================================================================]
  <IsConstant>
  @action: Returns true if arr consists of item ONLY.
  @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function MArrayHelper.IsConstant(const item: MType): Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  repeat
    Result := ((h > -1) and (Self[h] = item));
  until ((Result = False) or (h.Decrement < 0));
end;

{==============================================================================]
  <IsConstant>
  @action: Returns true if arr consists of ONLY same items.
  @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function MArrayHelper.IsConstant: Boolean; overload;
begin
  Result := ((not Self.Empty) and Self.IsConstant(Self[0]));
end;

{==============================================================================]
  <IsDistinct>
  @action: Returns True if all elements in the array are unique.
           Returns False immediately upon detecting a duplicate element.
  @note:
    • An empty array is considered distinct.
    • Internally uses TDictionary to detect duplicates.
[==============================================================================}
function MArrayHelper.IsDistinct: Boolean; overload;
var
  d: specialize TDictionary<MType, Byte>;
  v: MType;
begin
  d := specialize TDictionary<MType, Byte>.Create;
  try
    for v in Self do
      if not d.TryAdd(v, 0) then
        Exit(False);
    Result := True;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Palindrome>
  @action: Evaluates if the array is symmetrical by comparing elements from 
           the start and end simultaneously.
  @note: 
    - Type Safety: Uses a 'for..in' enumerator, making it safe for managed 
      types (Strings, Interfaces) where bitwise memory comparison fails.
    - Efficiency: O(N) time complexity with a half-pass optimization. The 
      loop breaks as soon as the center of the array is reached.
    - Logic: Iterates forward via the enumerator 's' while manually 
      tracking a descending index 'i' for the mirrored element.
    - Robustness: Handles zero and single-element arrays correctly, 
      treating them as inherently symmetrical.
[==============================================================================}
function MArrayHelper.Palindrome: Boolean; overload;
var
  s: MType;
  i, l: Integer;
begin
  i := High(Self);
  l := ((i + 1) div 2);  
  for s in Self do
    if not (s = Self[i]) then
	  Exit(False)
	else if (i.Decrement < l) then
	  Break;
  Result := True;
end;

{==============================================================================]
  <Stationary>
  @action: Returns True if all elements in the array are identical (zero variance).
  @note: Returns True for empty arrays or single-element arrays by default.
         Short-circuits and exits False immediately upon encountering the 
         first mismatched adjacent element.
[==============================================================================}
function MArrayHelper.Stationary: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Symmetrical>
  @action: Checks if the array is a palindrome (identical when reversed).
  @note: 
    - Efficiency: O(N) time complexity, but only iterates through half of 
      the array (N/2), exiting immediately upon the first mismatch.
    - Logic: Compares the "Head" elements with their "Reflex" counterparts 
      at the "Tail."
    - Performance: Zero memory allocation; uses a simple stack-based loop 
      for maximum speed.
[==============================================================================}
function MArrayHelper.Symmetrical: Boolean; overload;
var
  h, i: Integer;
begin
  h := High(Self);
  for i := 0 to (h div 2) do
    if (Self[i] <> Self[h - i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Uniform>
  @action: Returns true if arr is consistent with only 1 item.
  @note: Returns True with empty arrays!
[==============================================================================}
function MArrayHelper.Uniform: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[0]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Uniform>
  @action: Returns true if arr is consistent with only custom item.
  @note: Returns True with empty arrays!
[==============================================================================}
function MArrayHelper.Uniform(const item: MType): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if (Self[i] <> item) then
      Exit(False);
  Result := True;
end;
{$ENDIF}
