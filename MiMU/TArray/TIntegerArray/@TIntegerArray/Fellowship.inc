{$IFDEF HELPERS}
function Linked(const a, b: Integer): Boolean; overload;
function Linken(const a, b: Integer): Boolean; overload;
function Union(const a, b: Integer): Boolean; overload;
function Union(const a, b: Integer; var size: TIntegerArray): Boolean; overload;
function Unionize(const a, b: Integer): Boolean; overload;
function Unite(const a, b: Integer): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
