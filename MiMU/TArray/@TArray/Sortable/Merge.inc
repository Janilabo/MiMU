{$IFDEF HELPERS}
function House(const items: MArray; const oAscending: Boolean = True): Integer; overload;
function Intermerge(const items: MArray; const oAscending: Boolean = True): Integer; overload;
function Intermerged(const items: MArray; const oAscending: Boolean = True): Integer; overload;
function Melt(const items: MArray; const oAscending: Boolean = True): Integer; overload;
function Weld(const A, B: MArray; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Band(const A, B: MArray; const oAscending: Boolean = True): MArray; overload;
function Collate(const A, B: MArray; const rAscending: Boolean = True): MArray; overload;
function Combine2(const A, B: MArray; const oAscending: Boolean = True): MArray; overload;
function Combo(const A, B: MArray; const rAscending: Boolean = True): MArray; overload;
function Comerge(const A, B: MArray; const rAscending: Boolean = True): MArray; overload;
function Merge2(const A, B: MArray; const oAscending: Boolean = True): MArray; overload;
function Merged2(const A, B: MArray; const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Band>
  @action: Merges two sorted arrays into a single sorted array.
  @note: Both inputs must already be sorted in the direction given by
         oAscending. The merge is stable (ties take from A first), and
         inputs are not modified.
[==============================================================================}
function Band(const A, B: MArray; const oAscending: Boolean = True): MArray; overload;
var
  l, r, c, i, j, t: Integer;
begin
  l := A.Length;
  if (l = 0) then
    Exit(B.Cloned);
  r := B.Length;
  if (r = 0) then
    Exit(A.Cloned);
  if ((oAscending and (A[l - 1] <= B[0])) or ((not oAscending) and (A[l - 1] >= B[0]))) then
    c := -1
  else if ((oAscending and (A[0] >= B[r - 1])) or ((not oAscending) and (A[0] <= B[r - 1]))) then
    c := 1
  else
    c := 0;
  SetLength(Result, (l + r));
  case c of
    0:
    begin
      i := 0;
      j := 0;
      t := 0;
      case oAscending of
        True:
        while ((i < l) and (j < r)) do
          if (A[i] <= B[j]) then
            Result[t.Increase] := A[i.Increase]
          else
            Result[t.Increase] := B[j.Increase];
        False:
        while ((i < l) and (j < r)) do
          if (A[i] >= B[j]) then
            Result[t.Increase] := A[i.Increase]
          else
            Result[t.Increase] := B[j.Increase];
      end;
      while (i < l) do
        Result[t.Increase] := A[i.Increase];
      while (j < r) do
        Result[t.Increase] := B[j.Increase];
    end;
    -1:
    begin
      for i := 0 to (l - 1) do
        Result[i] := A[i];
      for i := 0 to (r - 1) do
        Result[i + l] := B[i];
    end;
    1:
    begin
      for i := 0 to (r - 1) do
        Result[i] := B[i];
      for i := 0 to (l - 1) do
        Result[i + r] := A[i];
    end;
  end;
end;

{==============================================================================]
  <Collate>
  @action: Merges two sorted arrays into a single ordered array, automatically 
           reversing either input if its internal direction conflicts with the 
           target sort order.
  @note: Determines directional mismatch using binary state flags ('00'-'11') 
         against rAscending before dispatching to Merge2.
[==============================================================================}
function Collate(const A, B: MArray; const rAscending: Boolean = True): MArray; overload;
var
  d: Integer;
begin
  d := IfThen(rAscending, 1, -1);
  case Binared((A.Directa = -d), (B.Directa = -d)) of
    '00': Result := Merge2(A, B, rAscending);
    '01': Result := Merge2(A, B.Reversed, rAscending);
    '10': Result := Merge2(A.Reversed, B, rAscending);
    '11': Result := Merge2(A.Reversed, B.Reversed, rAscending);
  end;
end;

{==============================================================================]
  <Combine2>
  @action: Concatenates two MArrays (A and B) — sorted or not — into one array,
    then fully sorts the result via MergeSort. O((n) log(n)) overall, since it
    pays for a full sort rather than exploiting any existing order in A or B.
  @note: Unlike Merge2, this makes no assumption that A or B are pre-sorted —
    that's the entire reason it exists as a separate function rather than a
    Merge2 variant. If both inputs are already sorted, Merge2 does the same
    job in O(n) and should be preferred.
[==============================================================================}
function Combine2(const A, B: MArray; const oAscending: Boolean = True): MArray; overload;
var
  i, l: Integer;
begin
  l := A.Length;
  SetLength(Result, (A.Length + B.Length));
  for i := 0 to (l - 1) do
    Result[i] := A[i];
  for i := 0 to High(B) do
    Result[l + i] := B[i];
  Result.MergeSort(oAscending);
end;

{==============================================================================]
  <Combo>
  @action: Merges two MArray structures into a single ordered MArray, ensuring both input arrays match the target sort direction before merging.
  @note: Uses an inline helper function O() to reverse input arrays A or B if their direction (Directa) opposes the target direction (rAscending).
[==============================================================================}
function Combo(const A, B: MArray; const rAscending: Boolean = True): MArray; overload;
var
  d: Integer;
  function O(const C: MArray): MArray;
  begin
    if (C.Directa = -d) then
      Result := C.Reversed
    else
      Result := C;
  end;
begin
  d := IfThen(rAscending, 1, -1);
  Result := Merge2(O(A), O(B), rAscending);
end;

{==============================================================================]
  <Comerge>
  @action: Merges two sorted arrays into one array in the order given by
           rAscending, detecting each input's direction automatically.
  @note: A and B may each be ascending or descending, in any combination.
         Direction is read in O(1) from each array's first and last element
         (see SortedDirection), so both inputs must really be sorted. An input
         that runs opposite to rAscending is read backward. Length < 2 or
         constant arrays are read forward. Ties take A first, but equal runs
         inside an input that has to be read backward come out reversed.
         Inputs are not modified.
[==============================================================================}
function Comerge(const A, B: MArray; const rAscending: Boolean = True): MArray; overload;
var
  l, r, i, j, t, x, y, d: Integer;
begin
  l := A.Length;
  if (l = 0) then
    Exit(B.QuickSorted(rAscending));
  r := B.Length;
  if (r = 0) then
    Exit(A.QuickSorted(rAscending));
  SetLength(Result, (l + r));
  d := IfThen(rAscending, 1, -1);
  i := IfThen((A.Directa = -d), (l - 1), 0);
  j := IfThen((B.Directa = -d), (r - 1), 0);
  x := IfThen((A.Directa = -d), -1, 1);
  y := IfThen((B.Directa = -d), -1, 1);
  t := 0;
  while ((l > 0) and (r > 0)) do
    if ((A[i] <= B[j]) = rAscending) then
    begin
      Result[t.Increase] := A[i.Increase(x)];
      l := (l - 1);
    end else
    begin
      Result[t.Increase] := B[j.Increase(y)];
      r := (r - 1);
    end;
  while (l.Decrement > -1) do
    Result[t.Increase] := A[i.Increase(x)];
  while (r.Decrement > -1) do
    Result[t.Increase] := B[j.Increase(y)];
end;

{==============================================================================]
  <Merge2>
  @action: Merges two sorted arrays (A and B) into a single sorted array, via
           a standard two-pointer linear merge. Whichever array is exhausted first has
           its remainder skipped; the other's leftover tail is copied over as-is.
  @note: Assumes both A and B are already sorted according to oAscending;
         behavior is undefined otherwise (see Kerge's precondition for the same
         contract).
[==============================================================================}
function Merge2(const A, B: MArray; const oAscending: Boolean = True): MArray; overload;
var
  l, r, i, j, t: Integer;
begin
  l := A.Length;
  r := B.Length;
  SetLength(Result, (l + r));
  i := 0;
  j := 0;
  t := 0;
  case oAscending of
    True:
    while ((i < l) and (j < r)) do
      if (A[i] <= B[j]) then
        Result[t.Increase] := A[i.Increase]
      else
        Result[t.Increase] := B[j.Increase];
    False:
    while ((i < l) and (j < r)) do
      if (A[i] >= B[j]) then
        Result[t.Increase] := A[i.Increase]
      else
        Result[t.Increase] := B[j.Increase];
  end;
  while (i < l) do
    Result[t.Increase] := A[i.Increase];
  while (j < r) do
    Result[t.Increase] := B[j.Increase];
end;

{==============================================================================]
  <Merged2>
  @action: Merges two sorted arrays (A and B) into a single sorted array, via
           a standard two-pointer linear merge. Whichever array is exhausted first has
           its remainder skipped; the other's leftover tail is copied over as-is.
  @note: Assumes both A and B are already sorted according to oAscending;
         behavior is undefined otherwise (see Kerge's precondition for the same
         contract).
[==============================================================================}
function Merged2(const A, B: MArray; const oAscending: Boolean = True): MArray; overload;
var
  l, r, i, j, t: Integer;
begin
  l := A.Length;
  r := B.Length;
  if (Result.SetSize(l + r) = 0) then
    Exit;
  i := 0;
  j := 0;
  t := 0;
  while ((i < l) and (j < r)) do
    if IfThen(oAscending, (A[i] <= B[j]), (A[i] >= B[j])) then
      Result[t.Increase] := A[i.Increase]
    else
      Result[t.Increase] := B[j.Increase];
  while (i < l) do
    Result[t.Increase] := A[i.Increase];
  while (j < r) do
    Result[t.Increase] := B[j.Increase];
end;

{==============================================================================]
  <House>
  @action: Sorts the items array and merges it into Self via Merge2.
  @note: Returns the new length of Self.
[==============================================================================}
function MArrayHelper.House(const items: MArray; const oAscending: Boolean = True): Integer; overload;
begin
  if (items.Length > 0) then
    Self := Merge2(Self, items.QuickSorted(oAscending), oAscending);
  Result := Self.Length;
end;

{==============================================================================]
  <Intermerge>
  @action: Merges a sorted copy of items in-place into an already sorted Self.
  @note: Performs a right-to-left merge to prevent element overwrites. Returns the total length.
[==============================================================================}
function MArrayHelper.Intermerge(const items: MArray; const oAscending: Boolean = True): Integer; overload;
var
  o: MArray;
  s, a, i, j, k: Integer;
begin
  s := Self.Length;
  a := items.Length;
  Result := (s + a);
  if (a = 0) then
    Exit;
  o := items.QuickSorted(oAscending);
  SetLength(Self, Result);
  i := (s - 1);
  j := (a - 1);
  k := (Result - 1);
  case oAscending of
    True:
    while (j >= 0) do
      if (i < 0) then
        Self[k.Decrease] := o[j.Decrease]
      else if (Self[i] > o[j]) then
        Self[k.Decrease] := Self[i.Decrease]
      else
        Self[k.Decrease] := o[j.Decrease];
    False:
    while (j >= 0) do
      if (i < 0) then
        Self[k.Decrease] := o[j.Decrease]
      else if (Self[i] < o[j]) then
        Self[k.Decrease] := Self[i.Decrease]
      else
        Self[k.Decrease] := o[j.Decrease];
  end;
end;

{==============================================================================]
  <Intermerged>
  @action: Merges a sorted copy of items in-place into Self from right to left.
  @note: Uses a single loop with conditional direction check to reduce duplicate code.
[==============================================================================}
function MArrayHelper.Intermerged(const items: MArray; const oAscending: Boolean = True): Integer; overload;
var
  o: MArray;
  s, a, i, j, k: Integer;
  b: Boolean;
begin
  s := Self.Length;
  a := items.Length;
  Result := (s + a);
  if (a = 0) then
    Exit;
  o := items.QuickSorted(oAscending);
  SetLength(Self, Result);
  i := (s - 1);
  j := (a - 1);
  k := (Result - 1);
  while (j >= 0) do
  begin
    if (i < 0) then
      b := False
    else if oAscending then
      b := (Self[i] > o[j])
    else
      b := (Self[i] < o[j]);
    if b then
      Self[k.Decrease] := Self[i.Decrease]
    else
      Self[k.Decrease] := o[j.Decrease];
  end;
end;

{==============================================================================]
  <Melt>
  @action: Merges an external sorted array into Self in-place, maintaining sorted order.
  @note: 
  - Expands Self and uses a back-to-front two-pointer selection loop to perform 
    the merge in O(N + M) time without allocating additional heap memory for buffers.
  - Requires both Self and items to already be pre-sorted according to oAscending.
  - Copies any remaining items prefix if Self is exhausted first.
  - Returns the new total length of Self.
[==============================================================================}
function MArrayHelper.Melt(const items: MArray; const oAscending: Boolean = True): Integer; overload;
var
  a, b, s, i, r: Integer;
begin
  s := High(Self);
  i := High(items);
  Result := ((s + i) + 2);
  SetLength(Self, Result);
  if (Result = 0) then
    Exit;
  r := Result;
  while ((s > -1) and (i > -1)) do
    if ((oAscending and (items[i] > Self[s])) or ((not oAscending) and (items[i] < Self[s]))) then
      Self[r.Decrement] := items[i.Decrease]
    else
      Self[r.Decrement] := Self[s.Decrease];
  for r := 0 to i do
    Self[r] := items[r];
end;

{==============================================================================]
  <Weld>
  @action: Merges two pre-sorted arrays A and B into Self as a single sorted
           array, returning High(Self).
  @note: A and B must each be pre-sorted (to oAscending) for the result to
         be valid. Stable: on ties, elements from A precede elements from B.
[==============================================================================}
function MArrayHelper.Weld(const A, B: MArray; const oAscending: Boolean = True): Integer; overload;
var
  i: Integer;
  l, r: TRange;
begin
  if A.Empty then
    Exit(B.Data(Self));
  if B.Empty then
    Exit(A.Data(Self));
  Result := Self.SetSize(A.Length + B.Length);
  l.Create(0, A.Length);
  r.Create(0, B.Length);
  i := 0;
  while ((l.start < l.stop) and (r.start < r.stop)) do
    if ((oAscending and (A[l.start] <= B[r.start])) or ((not oAscending) and (A[l.start] >= B[r.start]))) then
      Self[i.Increase] := A[l.start.Increase]
    else
      Self[i.Increase] := B[r.start.Increase];
  while (l.start < l.stop) do
    Self[i.Increase] := A[l.start.Increase];
  while (r.start < r.stop) do
    Self[i.Increase] := B[r.start.Increase];
end;
{$ENDIF}