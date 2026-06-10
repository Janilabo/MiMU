{$IFDEF HELPERS}
function Differ(const target: MArray): Boolean; overload;
function Different(const target: MArray): Boolean; overload;
function Discordant(const target: MArray): Boolean; overload;
function Dissimilar(const target: MArray; const stride: Integer = 10): Boolean; overload;
function NonIdentic(const target: MArray): Boolean; overload;
function NonIdentical(const target: MArray): Boolean; overload;
function Nontwin(const target: MArray): Boolean; overload;
function Selfsameless(const target: MArray): Boolean; overload;
function Unequal(const target: MArray): Boolean; overload;
function Unequivalent(const target: MArray): Boolean; overload;
function Unlike(const target: MArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Different>
  @action: Compares the current array with a target array to see if they differ.
  @note: Returns True if lengths vary. Otherwise, simultaneously scans from both 
         ends (left-to-right and right-to-left) toward the center using inline 
         index modification. Exits True early on the first found difference.
[==============================================================================}
function MArrayHelper.Different(const target: MArray): Boolean; overload;
var
  L, R: Integer;
begin
  R := Self.Length;
  if (R <> target.Length) then
    Exit(True);
  L := -1;
  while (L.Increment < R.Decrement) do
    if ((Self[L] <> target[L]) or (Self[R] <> target[R])) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Discordant>
  @action: Compares the current array with a target array to see if they differ.
  @note: Returns True if the arrays have different lengths or if any 
         corresponding elements do not match. Iterates forward from 
         the beginning (index 0) of the arrays.
[==============================================================================}
function MArrayHelper.Discordant(const target: MArray): Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l <> target.Length) then
    Exit(True);
  i := 0;
  while ((i < l) and (Self[i] = target[i])) do
    Inc(i);
  Result := (i < l);
end;

{==============================================================================]
  <Dissimilar>
  @action: Compares the current array with a target array using a strided, multi-pass approach.
  @note: Returns True if the lengths differ. Otherwise, it first checks elements 
         spaced apart by a calculated stride 's'. If no mismatch is found, it 
         fills in the gaps by checking the remaining elements in subsequent passes.
[==============================================================================}
function MArrayHelper.Dissimilar(const target: MArray; const stride: Integer = 10): Boolean; overload;
var
  i, s, p, l: Integer;
begin
  l := Self.Length;
  if (l <> target.Length) then
    Exit(True);
  s := Max(1, (l div Max(1, stride)));
  i := -s;
  while (i.Increment(s) < l) do
    if (Self[i] <> target[i]) then
      Exit(True);
  for p := 1 to (s - 1) do
  begin
    i := (p - s);
    while (i.Increment(s) < l) do
      if Self[i] <> target[i] then
        Exit(True);
  end;
  Result := False;
end;

{==============================================================================]
  <NonIdentic>
  @action: Compares the current array with a target array to verify if they are non-identical.
  @note: Returns True if the lengths differ. Otherwise, evaluates elements sequentially 
         using a tracking boolean and custom index incrementation inside a 'while' 
         loop, halting as soon as a mismatch sets the result to True.
[==============================================================================}
function MArrayHelper.NonIdentic(const target: MArray): Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l <> target.Length) then
    Exit(True);
  i := -1;
  Result := False;
  while ((not Result) and (i.Increment < l)) do
    Result := (Self[i] <> target[i]);
end;

{==============================================================================]
  <NonIdentical>
  @action: Determines if the current array is not identical to the target array.
  @note: Returns True immediately if the lengths differ or upon finding the 
         first mismatched element pair while iterating forward. Returns False 
         only if all corresponding elements match perfectly.
[==============================================================================}
function MArrayHelper.NonIdentical(const target: MArray): Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l <> target.Length) then
    Exit(True);
  for i := 0 to (l - 1) do
    if (Self[i] <> target[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Nontwin>
  @action: Checks whether the current array and the target array are non-twins.
  @note: Returns True if lengths differ. Otherwise, it uses a bidirectional 
         approach scanning from both ends toward the middle simultaneously, 
         updating a tracking state variable and stopping once a mismatch is found.
[==============================================================================}
function MArrayHelper.Nontwin(const target: MArray): Boolean; overload;
var
  L, R: Integer;
begin
  R := Self.Length;
  if (R <> target.Length) then
    Exit(True);
  L := -1;
  Result := False;
  while ((not Result) and (L.Increment < R.Decrement)) do
    Result := ((Self[L] <> target[L]) or (Self[R] <> target[R]));
end;

{==============================================================================]
  <Selfsameless>
  @action: Compares the current array with a target array to determine if they are structurally different.
  @note: Returns True if the lengths mismatch or any elements differ (i.e., they are not the selfsame array).
         Returns False only if they are perfectly identical.
[==============================================================================}
function MArrayHelper.Selfsameless(const target: MArray): Boolean; overload;
var
  i: Integer;
begin
  try
    if (Self.Length <> target.Length) then
      Exit(True);
    for i := Max(High(Self), High(target)) downto 0 do
      if (Self[i] <> target[i]) then
        Exit(True);
    Result := False;
  except
    Result := True;
  end;
end;

{==============================================================================]
  <Unequal>
  @action: Returns true if arr differs from target (opposite of Equal)
  @note: Inequality version of Equal.
[==============================================================================}
function MArrayHelper.Unequal(const target: MArray): Boolean; overload;
var
 h, i: Integer;
begin
  h := High(Self);
  if (h <> High(target)) then
    Exit(True);
  for i := h downto 0 do
    if (Self[i] <> target[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Unequivalent>
  @action: Checks whether the current array is not equivalent to the target array.
  @note: Returns True immediately if the lengths differ or upon encountering 
         the first mismatched pair of elements during a forward 'for' loop 
         iteration. Returns False only if all elements match perfectly.
[==============================================================================}
function MArrayHelper.Unequivalent(const target: MArray): Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l <> target.Length) then
    Exit(True);
  for i := 0 to (l - 1) do
    if (Self[i] <> target[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Unlike>
  @action: Determines if the current array differs from the target array.
  @note: Returns True if the arrays have different lengths or if any 
         corresponding elements do not match. Iterates backwards from 
         the end of the arrays for efficiency.
[==============================================================================}
function MArrayHelper.Unlike(const target: MArray): Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  if (h <> High(target)) then
    Exit(True);
  while ((h > -1) and (Self[h] = target[h])) do
    Dec(h);
  Result := (h > -1);
end;
{$ENDIF}