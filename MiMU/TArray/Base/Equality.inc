{$IFDEF HELPERS}
function Alike(const target: MArray): Boolean; overload;
function Analogous(const target: MArray): Boolean; overload;
function Congruent(const target: MArray): Boolean; overload;
function Equal(const target: MArray): Boolean; overload;
function Equivalent(const target: MArray): Boolean; overload;
function Identic(const target: MArray): Boolean; overload;
function Identical(const target: MArray): Boolean; overload;
function Same(const target: MArray): Boolean; overload;
function Selfsame(const target: MArray): Boolean; overload;
function Twin(const target: MArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Analogous>
  @action: Compares the current array with a target array to determine if they 
           are identical in both length and element values.
  @note: Uses a loop unrolling optimization technique (processing blocks of 4 
         elements) to improve comparison performance for larger arrays.
[==============================================================================}
function MArrayHelper.Analogous(const target: MArray): Boolean; overload;
var
  l, i, j, b: Integer;
begin
  l := Self.Length;
  if (l <> target.Length) then
    Exit(False);
  b := (l div 4);
  for i := 0 to (b - 1) do
  begin
    j := (i * 4);
    if ((Self[j] <> target[j]) or (Self[j + 1] <> target[j + 1]) or (Self[j + 2] <> target[j + 2]) or (Self[j + 3] <> target[j + 3])) then
      Exit(False);
  end;
  for i := (b * 4) to (l - 1) do
    if (Self[i] <> target[i]) then
      Exit(False);
  Result := True;
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
{$ENDIF}