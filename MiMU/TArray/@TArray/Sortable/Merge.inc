{$IFDEF HELPERS}
function Melt(const items: MArray; const oAscending: Boolean = True): Integer; overload;
function Weld(const A, B: MArray; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Merge2(const A, B: MArray; const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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