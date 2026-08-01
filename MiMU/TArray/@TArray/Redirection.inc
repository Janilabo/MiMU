{$IFDEF HELPERS}
function Deref(const via: TIntegerArray; const sIndex: Integer): MType; overload;
function Level(var parent: TIntegerArray; const sIndex: Integer): MType; overload;
function Root(const parent: TIntegerArray; const sIndex: Integer): MType; overload;
function Repoint(var via: TIntegerArray; const sIndex: Integer): MType; overload;
function Reroot(var parent: TIntegerArray; const sIndex: Integer): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Deref>
  @action: Follows the redirection chain in "via" starting at "sIndex" until 
           reaching a fixed point (via[r] = r), then returns the value at that
           final index in Self. Recursive implementation.
  @note: Does not modify "via". For a variant that flattens the chain as a 
         side effect, see Repoint.
[==============================================================================}
function MArrayHelper.Deref(const via: TIntegerArray; const sIndex: Integer): MType; overload;
begin
  if (via[sIndex] = sIndex) then
    Result := Self[sIndex]
  else
    Result := Self.Deref(via, via[sIndex]);
end;

{==============================================================================]
  <Level>
  @action: Follows the redirection chain in "parent" starting at "sIndex",
           repointing every visited node directly to its grandparent as it
           advances one node at a time (path splitting), then returns the
           value at the final root index in Self.
  @note: Mutates "parent" in place. This is path splitting, not path halving —
         every node on the path gets compressed, not just every other node.
         Result is Self[root], not the root index itself.
[==============================================================================}
function MArrayHelper.Level(var parent: TIntegerArray; const sIndex: Integer): MType; overload;
var
  r, n: Integer;
begin
  r := sIndex;
  while (parent[r] <> r) do
  begin
    n := parent[r];
    parent[r] := parent[parent[r]];
    r := n;
  end;
  Result := Self[r];
end;

{==============================================================================]
  <Root>
  @action: Follows the redirection chain in "parent" starting at "sIndex" until
           reaching a fixed point (parent[r] = r), then returns the value at 
           that final index in Self. Iterative implementation.
  @note: Does not modify "parent". For a variant that flattens the chain as a 
         side effect, see Reroot.
[==============================================================================}
function MArrayHelper.Root(const parent: TIntegerArray; const sIndex: Integer): MType; overload;
var
  r: Integer;
begin
  r := sIndex;
  while (parent[r] <> r) do
    r := parent[r];
  Result := Self[r];
end;

{==============================================================================]
  <Repoint>
  @action: Follows the redirection chain in "via" starting at "sIndex" to find
           the final index, then rewrites every visited index along the way to
           point directly at that final index (full path compression), before 
           returning the value at that index in Self.
  @note: Mutates "via" in place. Subsequent calls with the same "via" and any
         previously visited index resolve in a single step.
[==============================================================================}
function MArrayHelper.Repoint(var via: TIntegerArray; const sIndex: Integer): MType; overload;
var
  r, c, n: Integer;
begin
  r := sIndex;
  while (via[r] <> r) do
    r := via[r];
  c := sIndex;
  while (via[c] <> r) do
  begin
    n := via[c];
    via[c] := r;
    c := n;
  end;
  Result := Self[r];
end; 

{==============================================================================]
  <Reroot>
  @action: Follows the redirection chain in "parent" starting at "sIndex", 
           halving the path length at each step (parent[r] := parent[parent[r]]),
           then returns the value at the final index in Self.
  @note: Mutates "parent" in place. Uses path halving rather than full 
         compression, so multiple calls may be needed to fully flatten a long
         chain. For full compression in a single call, see Repoint.
[==============================================================================}
function MArrayHelper.Reroot(var parent: TIntegerArray; const sIndex: Integer): MType; overload;
var
  r: Integer;
begin
  r := sIndex;
  while (parent[r] <> r) do
  begin
    parent[r] := parent[parent[r]];
    r := parent[r];
  end;
  Result := Self[r];
end;
{$ENDIF}
