{$IFDEF HELPERS}
function Linked(const a, b: Integer): Boolean; overload;
function Union(const a, b: Integer): Boolean; overload;
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
{$ENDIF}
