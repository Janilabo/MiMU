{$IFDEF HELPERS}
function RankSorted(const oAscending: Boolean = True): MArray; overload;
function TallySorted(const N: Integer = 3; const oAscending: Boolean = True): MArray; overload;
function TallySorted(const oAscending: Boolean; const N: Integer = 3): MArray; overload;
function ToOrder(const oAscending: Boolean = True): MArray; overload;
function Triage(const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <RankSorted>
  @action: Returns a sorted copy of the array constructed by calculating the positional rank of each element.
  @note: Uses O(N^2) pairwise comparison with index-tiebreaking to place every element directly at its rank index.
         Non-destructive function.
[==============================================================================}
function MArrayHelper.RankSorted(const oAscending: Boolean = True): MArray; overload;
var
  i, j, l, r: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  for i := 0 to Result.Alloc(l) do
  begin
    r := 0;
    for j := 0 to (l - 1) do
      if ((oAscending and (Self[j] < Self[i])) or ((not oAscending) and (Self[j] > Self[i])) or ((j < i) and (Self[j] = Self[i]))) then
        Inc(r);
    Result[r] := Self[i];
  end;
end;

{==============================================================================]
  <TallySorted>
  @action: Returns a sorted copy for arrays containing up to N unique key values using linear tallying.
  @note: Non-destructive function. Auto-discovers up to N unique keys and reconstructs the array in O(N) time.
[==============================================================================}
function MArrayHelper.TallySorted(const N: Integer = 3; const oAscending: Boolean = True): MArray; overload;
var
  i, l, u, r: Integer;
  s: MType;
  k: MArray;
  c: TIntegerArray;
  z, j: Integer;
  f: Boolean;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Cloned);
  u := 0;
  for i := 0 to c.Alloc(N) do
    c[i] := 0;
  SetLength(k, N);
  for i := 0 to (l - 1) do
  begin
    s := Self[i];
    f := False;
    for z := 0 to (u - 1) do
      if (k[z] = s) then
      begin
        Inc(c[z]);
        f := True;
        Break;
      end;
    if ((not f) and (u < N)) then
    begin
      k[u] := s;
      c[u] := 1;
      Inc(u);
    end;
  end;
  for i := 0 to (u - 2) do
    for j := (i + 1) to (u - 1) do
      if (oAscending and (k[i] > k[j])) or ((not oAscending) and (k[i] < k[j])) then
      begin
        k.Switch(i, j);
        c.Switch(i, j);
      end;
  SetLength(Result, l);
  r := 0;
  for z := 0 to (u - 1) do
    for i := 1 to c[z] do
      Result[r.Increase] := k[z];
end;

{==============================================================================]
  <TallySorted>
  @action: Convenience overload allowing oAscending as the primary parameter.
  @note: Non-destructive function. Delegates to primary TallySorted method.
[==============================================================================}
function MArrayHelper.TallySorted(const oAscending: Boolean; const N: Integer = 3): MArray; overload;
begin
  Result := Self.TallySorted(N, oAscending);
end;

{==============================================================================]
  <ToOrder>
  @action: Sorts an array by decomposing it into monotonic sub-arrays and 
          recombining them via a k-way merge (Patience / Cascade Sort).
  @note: 
  - Pipeline approach: Executes Self.AsPiles to partition elements into sorted 
    piles, then calls MergeK to merge them back into a single sorted 1D array.
  - Achieves full sorting without a traditional QuickSort pass, leveraging 
    existing structural monotonicity in the source array.
  - Returns a sorted copy of Self according to the oAscending flag.
[==============================================================================}
function MArrayHelper.ToOrder(const oAscending: Boolean = True): MArray; overload;
begin
  Result := Self.AsPiles(oAscending).MergeK(oAscending);
end;

{==============================================================================]
  <Triage>
  @action: In-place single-pass 3-way partition sort (Dutch national flag) for arrays holding at most 3 distinct values; ascending or descending via oAscending.
           Destructive function. Auto-detects the extremes (min/max) and the middle value in an O(N) scan, then partitions in a second O(N) pass. O(1) extra space.
           Not stable. Equal values are indistinguishable, so this only matters for managed types or types where "=" ignores part of the value.
           With more than 3 distinct values the array is only partitioned around the first non-extreme value found (lower values before it, higher after it), not sorted.
           Returns Self.Length, also for arrays with fewer than 2 elements and for arrays whose values are all equal, which are left untouched.
[==============================================================================}
function MArrayHelper.Triage(const oAscending: Boolean = True): Integer; overload;
var
  i, l, m, h: Integer;
  b, c, t: MType;
  e: Boolean;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  b := Self[0];
  t := Self[0];
  e := False;
  for i := 1 to (Result - 1) do
    if (Self[i] < b) then
      b := Self[i]
    else if (Self[i] > t) then
      t := Self[i];
  if (b = t) then
    Exit;
  for i := 0 to (Result - 1) do
    if ((Self[i] <> b) and (Self[i] <> t)) then
    begin
      c := Self[i];
      e := True;
      Break;
    end;
  if not e then
    c := t;
  l := 0;
  m := 0;
  h := (Result - 1);
  case oAscending of
    True:
    while (m <= h) do
      if (Self[m] < c) then
        Self.Switch(l.Increase, m.Increase)
      else if (Self[m] = c) then
        Inc(m)
      else
        Self.Switch(m, h.Decrease);
    False:
    while (m <= h) do
      if (Self[m] > c) then
        Self.Switch(l.Increase, m.Increase)
      else if (Self[m] = c) then
        Inc(m)
      else
        Self.Switch(m, h.Decrease);
  end;
end;
{$ENDIF}
