{$IFDEF HELPERS}
function Deploy(const flanks: TBooleanArray; const oAscending: Boolean = True): Integer; overload;

function Billeted(const flanks: TBooleanArray; const oAscending: Boolean = True): MArray; overload;
function Consigned(const flanks: TBooleanArray; const oAscending: Boolean = True): MArray; overload;
function Deployed(const flanks: TBooleanArray; const oAscending: Boolean = True): MArray; overload;
function Echeloned(const flanks: TBooleanArray; const oAscending: Boolean = True): MArray; overload;
function Encamped(const flanks: TBooleanArray; const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Deploy>
  @action: Rearranges Self in place into sorted order, given which flank each
           element took when it was admitted to its bucket. Builds the scatter
           map for the flags (see Consignment), then moves every element to
           its destination by walking the map's permutation cycles, carrying
           one element at a time.
  @note: Mutating. Returns Self.Length, or 0 when the lengths differ (an empty
         Self also returns 0).
         In place with respect to the elements: no second element buffer is
         needed, which matters for large or managed MTypes. It still uses an
         integer map and a visited mask, both O(n), so for small POD types a
         copying variant (Deployed, Consigned) can be cheaper.
         Only meaningful when flanks came from the admission process (each
         element was a new minimum or maximum of its bucket). Arbitrary flags
         produce a rearrangement, not a sort.
         Mutating counterpart of Consigned (non-mutating).
[==============================================================================}
function MArrayHelper.Deploy(const flanks: TBooleanArray; const oAscending: Boolean = True): Integer; overload;
var
  f: TIntegerArray;
  d: TBooleanArray;
  s, t: MType;
  i, j, k: Integer;
begin
  if (Self.Length <> flanks.Length) then
    Exit(0);
  Result := Self.Length;
  f := flanks.Consignment(oAscending);
  for i := 0 to d.Alloc(Result) do
    if not d[i] then
    begin
      j := i;
      s := Self[i];
      repeat
        k := f[j];
        t := Self[k];
        Self[k] := s;
        s := t;
        d[j] := True;
        j := k;
      until (j = i);
    end;
end;

{==============================================================================]
  <Billeted>
  @action: Partition and group array elements into two segments based on a boolean mask (flanks) and an alignment flag (oAscending),
           placing non-matching elements on the left and matching elements on the right.
  @note: Validates that `Self` and `flanks` have equal lengths (returns an empty array `[]` if they mismatch).
         It uses a two-pass approach: the first pass counts the total number of non-matching elements (`c`) to determine the partition boundary.
		 The second pass then allocates the result array and populates it—placing non-matching elements into the left segment (`0` to `c - 1`)
		 in reverse order starting from `c - 1` via `l.Decrease`,
		 and matching elements into the right segment (`c` to `High(Self)`) in forward order starting from `c` via `r.Increase`.
[==============================================================================}
function MArrayHelper.Billeted(const flanks: TBooleanArray; const oAscending: Boolean = True): MArray; overload;
var
  c, l, r, i: Integer;
begin
  if (Self.Length <> flanks.Length) then
    Exit([]);
  c := 0;
  for i := 0 to High(Self) do
    if (flanks[i] <> oAscending) then
      Inc(c);
  l := (c - 1);
  r := c;
  for i := 0 to Result.Alloc(Self.Length) do
    if (flanks[i] = oAscending) then
      Result[r.Increase] := Self[i]
    else
      Result[l.Decrease] := Self[i];
end;

{==============================================================================]
  <Consigned>
  @action: Returns Self rearranged into sorted order, given which flank each
           element took when it was admitted to its bucket. Builds the
           scatter map for the flags (see Consignment), then writes every
           element straight to its destination index.
         Non-mutating. Two passes over Self: one inside Consignment (count and
         assign the map), one to scatter. Uses O(n) extra memory for the map.
         Returns an empty array when the lengths differ.
         Only meaningful when flanks came from the admission process (each
         element was a new minimum or maximum of its bucket). Arbitrary flags
         produce a rearrangement, not a sort.
         Equivalent to Self.Scattered(flanks.Consignment(oAscending)), but
         inlined to skip the second length check.
[==============================================================================}
function MArrayHelper.Consigned(const flanks: TBooleanArray; const oAscending: Boolean = True): MArray; overload;
var
  r: TIntegerArray;
  i: Integer;
begin
  if (Self.Length <> flanks.Length) then
    Exit([]);
  r := flanks.Consignment(oAscending);
  for i := 0 to Result.Alloc(Self.Length) do
    Result[r[i]] := Self[i];
end;

{==============================================================================]
  <Deployed>
  @action: Partition and deploy array elements into left and right segments based on a boolean mask (flanks) and an alignment flag (oAscending).
  @note: Validates that `Self` and `flanks` have equal lengths (returns an empty array `[]` if they mismatch). It iterates backward through the array,
         placing elements matching `oAscending` from the right inwards (`r.Decrease`) and non-matching elements from the left inwards (`l.Increase`).
[==============================================================================}
function MArrayHelper.Deployed(const flanks: TBooleanArray; const oAscending: Boolean = True): MArray; overload;
var
  l, r, i: Integer;
begin
  if (Self.Length <> flanks.Length) then
    Exit([]);
  l := 0;
  r := High(Self);
  for i := Result.Alloc(Self.Length) downto 0 do
    if (flanks[i] = oAscending) then
      Result[r.Decrease] := Self[i]
    else
      Result[l.Increase] := Self[i];
end;

{==============================================================================]
  <Echeloned>
  @action: Partition and group array elements based on a boolean mask (flanks),
           placing non-matching elements first (in reverse order) followed by matching elements (in forward order).
  @note: Validates that `Self` and `flanks` have equal lengths (returns an empty array `[]` if they mismatch).
         It uses a two-pass approach using a tracking pointer `p`: the first pass collects elements where `flanks[i] <> oAscending` backwards from the end (`downto 0`),
		 and the second pass collects elements where `flanks[i] = oAscending` forwards from the start (`0 to High(Self)`).
[==============================================================================}
function MArrayHelper.Echeloned(const flanks: TBooleanArray; const oAscending: Boolean = True): MArray; overload;
var
  p, i: Integer;
begin
  if (Self.Length <> flanks.Length) then
    Exit([]);
  p := 0;
  for i := Result.Alloc(Self.Length) downto 0 do
    if (flanks[i] <> oAscending) then
      Result[p.Increase] := Self[i];
  for i := 0 to High(Self) do
    if (flanks[i] = oAscending) then
      Result[p.Increase] := Self[i];
end;

{==============================================================================]
  <Encamped>
  @action: Center-branch array elements outwards from a central starting point (`Self[0]`) into left and right directions
           based on a boolean mask (flanks) and an alignment flag (oAscending), returning a subarray of the original length.
  @note: Validates that `Self` and `flanks` have equal lengths and that `Self` is not empty (returns an empty array `[]` if invalid).
         It allocates an intermediate buffer of size `(n * 2) - 1`, places the first element (`Self[0]`) at the center index (`n - 1`),
		 and branches subsequent elements left or right depending on the `flanks` mask. Finally,
		 it extracts a slice of length `n` from the intermediate buffer starting from the final left index.
[==============================================================================}
function MArrayHelper.Encamped(const flanks: TBooleanArray; const oAscending: Boolean = True): MArray; overload;
var
  s: MArray;
  l, r, i, n: Integer;
begin
  n := Self.Length;
  if ((n <> flanks.Length) or (n = 0)) then
    Exit([]);
  SetLength(s, ((n * 2) - 1));
  l := (n - 1);
  r := l;
  s[l] := Self[0];
  for i := 1 to High(Self) do
    if (flanks[i] = oAscending) then
      s[r.Increment] := Self[i]
    else
      s[l.Decrement] := Self[i];
  for i := 0 to Result.Alloc(n) do
    Result[i] := s[l + i];
end;
{$ENDIF}
