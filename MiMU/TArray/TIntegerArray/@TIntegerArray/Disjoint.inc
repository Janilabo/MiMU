{$IFDEF HELPERS}
function Rooted: Boolean; overload;

function Rootcount: Integer; overload;

function Rootless(const sIndex: Integer): Boolean; overload;

function Deref(const sIndex: Integer): Integer; overload;
function Hop(const sIndex: Integer): Integer; overload;
function Jump(const sIndex: Integer): Integer; overload;
function Level(const sIndex: Integer): Integer; overload;
function Repoint(const sIndex: Integer): Integer; overload;
function Reroot(const sIndex: Integer): Integer; overload;
function Root(const sIndex: Integer): Integer; overload;
function Rootage(const sIndex: Integer): Integer; overload;

function Rootings: T2DIntegerArray; overload;
function Clan(const sIndex: Integer): TIntegerArray; overload;
function Rootmax: TIntegerArray; overload;
function Rootmin: TIntegerArray; overload;
function Rootset: TIntegerArray; overload;
function Siblings(const sIndex: Integer): TIntegerArray; overload;

function Linked(const a, b: Integer): Boolean; overload;
function Linken(const a, b: Integer): Boolean; overload;
function Union(const a, b: Integer): Boolean; overload;
function Union(const a, b: Integer; var size: TIntegerArray): Boolean; overload;
function Union(const a, b: TIntegerArray): Integer; overload;
function Unioned(const a, b: Integer): Boolean; overload;
function Unionize(const a, b: Integer): Boolean; overload;
function Unison(const a, b: Integer): Integer; overload;
function Unite(const a, b: Integer): Boolean; overload;

function Corooted(const rIndices: TIntegerArray): Boolean; overload;

function Corootify(const rIndices: TIntegerArray): Integer; overload;

function Rootify: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Rooted>
  @action: Returns True if Self is well-formed as a disjoint-set parent
           array — every element is a valid in-bounds index, and following
           the chain from any index eventually reaches a fixed point
           (Self[r] = r) without an infinite loop.
  @note: Does not mutate Self. O(n) in the common case; a malformed array
         with a genuine cycle (no fixed point) is detected via a visited-set
         guard rather than looping forever.
[==============================================================================}
function TIntegerArrayHelper.Rooted: Boolean; overload;
var
  l, i, r, s: Integer;
begin
  l := Self.Length;
  for i := 0 to (l - 1) do
  begin
    if ((Self[i] < 0) or (Self[i] >= l)) then
      Exit(False);
    r := i;
    s := 0;
    while (Self[r] <> r) do
    begin
      r := Self[r];
      if (s.Increment > l) then
        Exit(False);
    end;
  end;
  Result := True;
end;

{==============================================================================]
  <Rootcount>
  @action: Counts the total number of unique disjoint set representatives (roots) in the array.
  @note: Requires Rootage(i) to return a valid zero-based root index for element i.
[==============================================================================}
function TIntegerArrayHelper.Rootcount: Integer; overload;
var
  s: TIntegerArray;
  i, r: Integer;
begin
  Result := Self.Length;
  for i := 0 to s.Alloc(Result) do
  begin
    r := Self.Rootage(i);
    if (s[r] = 0) then
      s[r] := 1
    else
      Dec(Result);
  end;
end;

{==============================================================================]
  <Rootless>
  @action: Returns True if sIndex is alone in its own set — i.e. no other
           index in Self shares its root.
  @note: Does not mutate Self. O(n) per call, since it must scan the full
         array to confirm no other index shares sIndex's root (there's no
         way to answer this from sIndex's chain alone).
[==============================================================================}
function TIntegerArrayHelper.Rootless(const sIndex: Integer): Boolean; overload;
var
  r, i: Integer;
begin
  if Self.Empty then
    Exit(False);
  r := Self.Rootage(sIndex);
  for i := 0 to High(Self) do
    if ((i <> sIndex) and (Self.Rootage(i) = r)) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Deref>
  @action: Follows the redirection chain in Self starting at "sIndex" until
           reaching a fixed point (Self[r] = r), then returns that final
           index. Recursive implementation. Self is treated as the parent.
  @note: Does not modify Self. For a variant that flattens the chain as a
         side effect, see Repoint.
[==============================================================================}
function TIntegerArrayHelper.Deref(const sIndex: Integer): Integer; overload;
begin
  if (Self[sIndex] = sIndex) then
    Result := sIndex
  else
    Result := Self.Deref(Self[sIndex]);
end;

{==============================================================================]
  <Hop>
  @action: Follows the redirection chain in Self starting at "sIndex",
           repointing every visited node directly to its grandparent as it
           advances one node at a time (path splitting), then returns the
           final root index. Self is treated as the parent.
  @note: Mutates Self in place. This is path splitting, not path halving —
         every node on the path gets compressed, not just every other node.
         Functionally equivalent to Level, restructured to advance-then-write
         instead of capture-then-advance.
[==============================================================================}
function TIntegerArrayHelper.Hop(const sIndex: Integer): Integer; overload;
var
  r: Integer;
begin
  Result := sIndex;
  while (Self[Result] <> Result) do
  begin
    r := Result;
    Result := Self[Result];
    Self[r] := Self[Result];
  end;
end;

{==============================================================================]
  <Jump>
  @action: Follows the redirection chain in Self starting at "sIndex",
           recursively resolving to the final root index and then rewriting
           every visited node along the path to point directly at that root
           (full path compression) as the recursion unwinds. Self is treated
           as the parent.
  @note: Mutates Self in place. Recursive, single-pass implementation — same
         end result as Repoint's two-pass iterative version, so use whichever
         better matches your performance/stack-depth requirements. Subsequent
         calls with any previously visited index resolve in a single step.
[==============================================================================}
function TIntegerArrayHelper.Jump(const sIndex: Integer): Integer; overload;
begin
  if (Self[sIndex] = sIndex) then
    Exit(sIndex);
  Result := Self.Jump(Self[sIndex]);
  Self[sIndex] := Result;
end;

{==============================================================================]
  <Level>
  @action: Follows the redirection chain in Self starting at "sIndex",
           repointing every visited node directly to its grandparent as it
           advances one node at a time (path splitting), then returns the
           final root index. Self is treated as the parent.
  @note: Mutates Self in place. This is path splitting, not path halving —
         every node on the path gets compressed, not just every other node.
[==============================================================================}
function TIntegerArrayHelper.Level(const sIndex: Integer): Integer; overload;
var
  n: Integer;
begin
  Result := sIndex;
  while (Self[Result] <> Result) do
  begin
    n := Self[Result];
    Self[Result] := Self[Self[Result]];
    Result := n;
  end;
end;

{==============================================================================]
  <Repoint>
  @action: Follows the redirection chain in Self starting at "sIndex" to find
           the final index, then rewrites every visited index along the way
           to point directly at that final index (full path compression),
           before returning that root index. Self is treated as the parent.
  @note: Mutates Self in place. Subsequent calls with any previously visited
         index resolve in a single step.
[==============================================================================}
function TIntegerArrayHelper.Repoint(const sIndex: Integer): Integer; overload;
var
  c, n: Integer;
begin
  Result := sIndex;
  while (Self[Result] <> Result) do
    Result := Self[Result];
  c := sIndex;
  while (Self[c] <> Result) do
  begin
    n := Self[c];
    Self[c] := Result;
    c := n;
  end;
end;

{==============================================================================]
  <Reroot>
  @action: Follows the redirection chain in Self starting at "sIndex",
           halving the path length at each step (Self[r] := Self[Self[r]]),
           then returns the final root index. Self is treated as the parent.
  @note: Mutates Self in place. Uses path halving rather than full
         compression, so multiple calls may be needed to fully flatten a long
         chain. For full compression in a single call, see Repoint.
[==============================================================================}
function TIntegerArrayHelper.Reroot(const sIndex: Integer): Integer; overload;
begin
  Result := sIndex;
  while (Self[Result] <> Result) do
  begin
    Self[Result] := Self[Self[Result]];
    Result := Self[Result];
  end;
end;

{==============================================================================]
  <Root>
  @action: Follows the redirection chain in Self starting at "sIndex" until
           reaching a fixed point (Self[r] = r), then returns that final
           index. Iterative implementation. Self is treated as the parent.
  @note: Does not modify Self. For a variant that flattens the chain as a
         side effect, see Reroot.
[==============================================================================}
function TIntegerArrayHelper.Root(const sIndex: Integer): Integer; overload;
begin
  Result := sIndex;
  while (Self[Result] <> Result) do
    Result := Self[Result];
end;

{==============================================================================]
  <Rootage>
  @action: Finds the representative (root) of sIndex's set, with path compression.
  @note: Self must be a disjoint-set parent array (Self[i] = i initially for all i).
[==============================================================================}
function TIntegerArrayHelper.Rootage(const sIndex: Integer): Integer; overload;
var
  s, c: Integer;
begin
  Result := sIndex;
  while (Self[Result] <> Result) do
    Result := Self[Result];
  c := sIndex;
  while (Self[c] <> c) do
  begin
    s := Self[c];
    Self[c] := Result;
    c := s;
  end;
end;

{==============================================================================]
  <Rootings>
  @action: Flattens Self into buckets of indices that share the same root,
           returning one sub-array per distinct set. Order of sub-arrays and
           order of indices within each sub-array follows ascending index
           order, not insertion or merge order.
  @note: Calling this compresses every visited chain as a side effect (each
         Rootage call along the way applies path compression), so Self may
         be left flatter than it started even though buckets aren't affected.
[==============================================================================}
function TIntegerArrayHelper.Rootings: T2DIntegerArray; overload;
var
  m: TIntegerArray;
  r, l, i: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  for i := 0 to m.Alloc(l) do
    m[i] := -1;
  SetLength(Result, 0);
  for i := 0 to (l - 1) do
  begin
    r := Self.Rootage(i);
    if (m[r] = -1) then
    begin
      m[r] := System.Length(Result);
      SetLength(Result, (System.Length(Result) + 1));
      Result[m[r]] := [];
    end;
    Result[m[r]] := (Result[m[r]] + [i]);
  end;
end;

{==============================================================================]
  <Clan>
  @action: Returns every index that belongs to the same set as sIndex,
           including sIndex itself, in ascending index order.
  @note: Calling this compresses every visited chain as a side effect (each
         Rootage call along the way applies path compression). For the full
         partition into all sets at once, see Groups.
[==============================================================================}
function TIntegerArrayHelper.Clan(const sIndex: Integer): TIntegerArray; overload;
var
  r, i: Integer;
begin
  if (Result.Empten = Self.Length) then
    Exit;
  r := Self.Rootage(sIndex);
  for i := 0 to High(Self) do
    if (Self.Rootage(i) = r) then
      Result := (Result + [i]);
end;

{==============================================================================]
  <Rootmax>
  @action: Returns the indices belonging to the largest set in Self — the
           set with the most members. If multiple sets are tied for largest,
           returns the one whose root has the lowest index.
  @note: Calling this compresses every visited chain as a side effect (each
         Rootage call along the way applies path compression). Returns an
         empty array if Self is empty.
[==============================================================================}
function TIntegerArrayHelper.Rootmax: TIntegerArray; overload;
var
  r: T2DIntegerArray;
  m, i: Integer;
begin
  r := Self.Rootings;
  if (System.Length(r) = 0) then
    Exit([]);
  m := 0;
  for i := 1 to (System.Length(r) - 1) do
    if (System.Length(r[i]) > System.Length(r[m])) then
      m := i;
  Result := r[m];
end;

{==============================================================================]
  <Rootmin>
  @action: Returns the indices belonging to the smallest set in Self — the
           set with the fewest members. If multiple sets are tied for
           smallest, returns the one whose root has the lowest index.
  @note: Calling this compresses every visited chain as a side effect (each
         Rootage call along the way applies path compression). Returns an
         empty array if Self is empty.
[==============================================================================}
function TIntegerArrayHelper.Rootmin: TIntegerArray; overload;
var
  r: T2DIntegerArray;
  m, i: Integer;
begin
  r := Self.Rootings;
  if (System.Length(r) = 0) then
    Exit([]);
  m := 0;
  for i := 1 to (System.Length(r) - 1) do
    if (System.Length(r[i]) < System.Length(r[m])) then
      m := i;
  Result := r[m];
end;

{==============================================================================]
  <Rootset>
  @action: Returns the index of every distinct root/representative in Self,
           one per set, in ascending order.
  @note: Calling this compresses every visited chain as a side effect (each
         Rootage call along the way applies path compression).
[==============================================================================}
function TIntegerArrayHelper.Rootset: TIntegerArray; overload;
var
  s: TIntegerArray;
  i, r, c: Integer;
begin
  c := 0;
  for i := 0 to Result.Alloc(s.SetSize(Self.Length)) do
  begin
    r := Self.Rootage(i);
    if (s[r] = 0) then
    begin
      s[r] := 1;
      Result[c.Increase] := r;
    end;
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <Siblings>
  @action: Returns every index in Self that shares the same root as sIndex —
           i.e. all elements belonging to the same set as sIndex, including sIndex
           itself. Iterates the full array, resolving each index's root and
           comparing it against sIndex's root.
  @note: Does not mutate Self. O(n) per call regardless of chain depth, since
         every index must be checked. For repeated membership queries against
         the same set, consider materializing all sets at once with a full
         partition pass instead of calling Members per element.
[==============================================================================}
function TIntegerArrayHelper.Siblings(const sIndex: Integer): TIntegerArray; overload;
var
  r, i, c: Integer;
begin
  r := Self.Root(sIndex);
  c := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if (Self.Root(i) = r) then
      Result[c.Increase] := i;
  SetLength(Result, c);
end;

{==============================================================================]
  <Linked>
  @action: Returns True if "a" and "b" resolve to the same root in Self,
           meaning they belong to the same set. Uses Root internally, so
           does not mutate Self.
  @note: For a version that also compresses the path as it checks, use one
         of the mutating Root-family functions (Jump, Repoint, Level, Hop,
         Reroot) directly on both indices before comparing.
[==============================================================================}
function TIntegerArrayHelper.Linked(const a, b: Integer): Boolean; overload;
begin
  Result := (Self.Root(a) = Self.Root(b));
end;

{==============================================================================]
  <Linken>
  @action: Returns True if "a" and "b" resolve to the same root in Self,
           meaning they belong to the same set. Walks both chains in
           sequence, short-circuiting as soon as the two paths meet, rather
           than always fully resolving both roots independently.
  @note: Does not mutate Self. Functionally equivalent to comparing
         Self.Root(a) with Self.Root(b), but can exit earlier when both
         indices converge on a shared node before either reaches its true
         root.
[==============================================================================}
function TIntegerArrayHelper.Linken(const a, b: Integer): Boolean; overload;
var
  l, r: Integer;
begin
  l := a;
  r := b;
  while ((l <> r) and (Self[l] <> l)) do
    l := Self[l];
  while ((l <> r) and (Self[r] <> r)) do
    r := Self[r];
  Result := (l = r);
end;

{==============================================================================]
  <Union>
  @action: Merges the sets containing "a" and "b" by finding each index's
           root and repointing one root to the other, so future Root/Deref/
           etc. calls on either resolve to the same value. No-op if "a" and
           "b" are already in the same set. Returns True if a merge actually
           occurred, False if "a" and "b" were already linked.
  @note: Mutates Self in place. Does not use union-by-rank/size, so repeated
         unions in an unfavorable order can produce a deeper tree than
         necessary; path-compressing Root-family calls (Jump, Repoint, etc.)
         mitigate this over time regardless.
[==============================================================================}
function TIntegerArrayHelper.Union(const a, b: Integer): Boolean; overload;
var
  l, r: Integer;
begin
  l := Self.Root(a);
  r := Self.Root(b);
  Result := (l <> r);
  if Result then
    Self[l] := r;
end;

{==============================================================================]
  <Union>
  @action: Merges pairs of indices from two arrays (a[i] with b[i])
  @return: Number of successful unions
[==============================================================================}
function TIntegerArrayHelper.Union(const a, b: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to (Min(a.Length, b.Length) - 1) do
    if Self.Union(a[i], b[i]) then
      Inc(Result);
end;

{==============================================================================]
  <Union>
  @action: Merges the sets containing "a" and "b" by finding each index's
           root and attaching the smaller-sized tree's root under the
           larger-sized tree's root (union by size), updating "size" to
           reflect the merged tree's total size. No-op if "a" and "b" are
           already in the same set.
  @note: Mutates Self and "size" in place. "size" must be maintained in sync
         with Self as a companion array — size[i] should equal 1 for every
         index at initialization, and only this function (or an equivalent
         weighted-union implementation) should update it thereafter. Using
         the plain Union overload on the same Self without also updating
         "size" will desynchronize the two arrays. Returns True if a merge
         actually occurred, False if "a" and "b" were already linked.
[==============================================================================}
function TIntegerArrayHelper.Union(const a, b: Integer; var size: TIntegerArray): Boolean; overload;
var
  l, r: Integer;
begin
  l := Self.Root(a);
  r := Self.Root(b);
  Result := (l <> r);
  if Result then
  case size[l] < size[r] of
    True:
    begin
      Self[l] := r;
      size[r] := (size[r] + size[l]);
    end;
	False:
    begin
      Self[r] := l;
      size[l] := (size[l] + size[r]);
    end;
  end;
end;

{==============================================================================]
  <Unioned>
  @action: Merges the sets containing a and b.
  @note: Self must be a disjoint-set parent array.
[==============================================================================}
function TIntegerArrayHelper.Unioned(const a, b: Integer): Boolean; overload;
var
  f, t: Integer;
begin
  f := Self.Rootage(a);
  t := Self.Rootage(b);
  Result := (f <> t);
  if Result then
    Self[t] := f;
end;

{==============================================================================]
  <Unionize>
  @action: Merges the sets containing "a" and "b" by finding each index's
           root and repointing the higher-numbered root to the lower-numbered
           root (deterministic root selection), so future Root/Deref/etc.
           calls on either resolve to the same value. No-op if "a" and "b"
           are already in the same set.
  @note: Mutates Self in place. Always keeps the lower-valued root as the
         surviving root, regardless of tree size — this gives predictable,
         reproducible merges but does not optimize for tree shallowness the
         way union-by-size does. Returns True if a merge actually occurred,
         False if "a" and "b" were already linked.
[==============================================================================}
function TIntegerArrayHelper.Unionize(const a, b: Integer): Boolean; overload;
var
  l, r: Integer;
begin
  l := Self.Root(a);
  r := Self.Root(b);
  Result := (l <> r);
  if Result then
  case (l < r) of
    True: Self[r] := l;
    False: Self[l] := r;
  end;
end;

{==============================================================================]
  <Unison>
  @action: Merges the group containing `b` into the group containing `a`, relabeling every element that shared `b`'s group label to `a`'s group label.
  @note: Returns the surviving group label (`Self[a]`'s original value). No-op if `a` and `b` already belong to the same index (`a = b`), still returning that label.
[==============================================================================}
function TIntegerArrayHelper.Unison(const a, b: Integer): Integer; overload;
var
  o, s, m: Integer;
begin
  s := Self[a];
  if (a = b) then
    Exit(s);
  o := Self[b];
  for m := 0 to High(Self) do
    if (Self[m] = o) then
      Self[m] := s;
  Result := s;
end;

{==============================================================================]
  <Unite>
  @action: Merges the sets containing "a" and "b" by walking both chains in
           sequence — short-circuiting as soon as the two paths meet — then
           repointing one resolved root to the other. No-op if "a" and "b"
           are already in the same set.
  @note: Mutates Self in place. Does not use union-by-rank/size, so repeated
         unions in an unfavorable order can produce a deeper tree than
         necessary; path-compressing Root-family calls (Jump, Repoint, etc.)
         mitigate this over time regardless. Returns True if merge occurred.
[==============================================================================}
function TIntegerArrayHelper.Unite(const a, b: Integer): Boolean; overload;
var
  l, r: Integer;
begin
  l := a;
  r := b;
  while ((l <> r) and (Self[l] <> l)) do
    l := Self[l];
  while ((l <> r) and (Self[r] <> r)) do
    r := Self[r];
  Result := (l <> r);
  if Result then
    Self[l] := r;
end;

{==============================================================================]
  <Corooted>
  @action: Returns True if every index in "indices" resolves to the same
           root — i.e. all of them belong to the same set.
  @note: Calling this compresses every visited chain as a side effect.
         Returns True for an empty or single-element "indices" array.
[==============================================================================}
function TIntegerArrayHelper.Corooted(const rIndices: TIntegerArray): Boolean; overload;
var
  r, i: Integer;
begin
  if (rIndices.Length <= 1) then
    Exit(True);
  r := Self.Rootage(rIndices[0]);
  for i := 1 to High(rIndices) do
    if (Self.Rootage(rIndices[i]) <> r) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Corootify>
  @action: Merges every index in "rIndices" into a single set, by unioning
           the first index with each of the rest in turn.
  @note: Mutates Self in place. No-op for an empty or single-element
         "indices" array. Uses the plain Union rule (no size-weighting).
[==============================================================================}
function TIntegerArrayHelper.Corootify(const rIndices: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 1 to High(rIndices) do
    if Self.Union(rIndices[0], rIndices[i]) then
      Inc(Result);
end;

{==============================================================================]
  <Rootify>
  @action: Fully compresses every chain in Self so that every index points
           directly at its root in a single step. After calling this,
           Self[i] = Rootage(i) for every i, with no intermediate hops
           remaining anywhere in the structure.
  @note: Mutates Self in place. Useful to call once before a batch of
         read-heavy aggregate operations (Rootings, Rootcount, Largest),
         so each subsequent call resolves roots in O(1) instead of
         re-walking partially-compressed chains.
[==============================================================================}
function TIntegerArrayHelper.Rootify: Integer; overload;
var
  s, i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
  begin
    s := Self[i];
    if (s <> Self.Rootage(i)) then
      Inc(Result);
  end;
end;
{$ENDIF}
