{$IFDEF HELPERS}
function Deref(const sIndex: Integer): Integer; overload;
function Hop(const sIndex: Integer): Integer; overload;
function Jump(const sIndex: Integer): Integer; overload;
function Level(const sIndex: Integer): Integer; overload;
function Repoint(const sIndex: Integer): Integer; overload;
function Reroot(const sIndex: Integer): Integer; overload;
function Root(const sIndex: Integer): Integer; overload;
function Siblings(const a: Integer): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Siblings>
  @action: Returns every index in Self that shares the same root as "a" —
           i.e. all elements belonging to the same set as "a", including "a"
           itself. Iterates the full array, resolving each index's root and
           comparing it against "a"'s root.
  @note: Does not mutate Self. O(n) per call regardless of chain depth, since
         every index must be checked. For repeated membership queries against
         the same set, consider materializing all sets at once with a full
         partition pass instead of calling Members per element.
[==============================================================================}
function TIntegerArrayHelper.Siblings(const a: Integer): TIntegerArray; overload;
var
  r, i, c: Integer;
begin
  r := Self.Root(a);
  c := 0;
  for i := 0 to Result.Alloc(Self.Length) do
    if (Self.Root(i) = r) then
      Result[c.Increase] := i;
  SetLength(Result, c);
end;
{$ENDIF}
