{$IFDEF HELPERS}
function Enact(const aOrder: TIntegerArray): Boolean; overload;
function Ordain(const aOrder: TIntegerArray): TIntegerArray; overload;
function Rescind(const aOrder: TIntegerArray): Integer; overload;
function Revoke(const aOrder: TIntegerArray): TIntegerArray; overload;

function Ratify(const aOrder: TIntegerArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Enact>
  @action: Rearranges Self in place according to a precomputed order array,
           such that Self[i] becomes SelfOriginal[aOrder[i]].
  @note: Bare verb, mutating — consistent with the project's naming
         convention. Uses in-place cycle-following (each element moved
         exactly once) rather than an auxiliary output buffer; only extra
         space is the O(N) visited-flags array, which is unavoidable
         without destructively marking aOrder itself. Designed to consume
         Sortition's output directly: Self.Enact(Self.Sortition) reproduces
         what Sortie would have done, without a second pass over Self.
         Caller must ensure Length(aOrder) = Self.Length and that aOrder is
         a valid permutation of 0..Length-1 — undefined behavior otherwise.
[==============================================================================}
function MArrayHelper.Enact(const aOrder: TIntegerArray): Boolean; overload;
var
  s, i, j, k: Integer;
  v: TBooleanArray;
  t: MType;
begin
  s := Self.Length;
  Result := (s = aOrder.Length);
  if Result then
  for i := 0 to v.Alloc(s) do
  begin
    if v[i] then
      Continue;
    j := i;
    t := Self[i];
    while True do
    begin
      k := aOrder[j];
      if (k = i) then
      begin
        Self[j] := t;
        v[j] := True;
        Break;
      end;
      Self[j] := Self[k];
      v[j] := True;
      j := k;
    end;
  end;
end;

{==============================================================================]
  <Ordain>
  @action: Rearranges Self in place according to an externally-derived
           order array, such that Self[i] becomes SelfOriginal[aOrder[i]].
           Returns the restore-map needed to undo this rearrangement via
           Revoke.
  @note: Bare verb, mutating, but returns a value — same asymmetric shape
         as Sortie. Result is the inverse of aOrder: Self.Revoke(Result)
         restores Self to the order it held before this call. Caller must
         ensure Length(aOrder) = Self.Length and that aOrder is a valid
         permutation of 0..Length-1 — use Ratify to check first if the
         order's provenance isn't already trusted.
[==============================================================================}
function MArrayHelper.Ordain(const aOrder: TIntegerArray): TIntegerArray; overload;
var
  s, i, j, k: Integer;
  v: TBooleanArray;
  t: MType;
begin
  s := Self.Length;
  if (s <> aOrder.Length) then
    Exit([]);
  for i := 0 to Result.Alloc(s) do
    Result[aOrder[i]] := i;
  SetLength(v, s);
  for i := 0 to (s - 1) do
  begin
    if v[i] then
      Continue;
    j := i;
    t := Self[i];
    repeat
      k := aOrder[j];
      if (k = i) then
      begin
        Self[j] := t;
        v[j] := True;
        Break;
      end;
      Self[j] := Self[k];
      v[j] := True;
      j := k;
    until False;
  end;
end;

{==============================================================================]
  <Rescind>
  @action: Rearranges Self in place by the inverse of a given order array —
           undoes what Enact/Ordain would have done with that same array.
           Returns the number of elements rearranged, or 0 on failure.
  @note: Bare verb, mutating, returns a count rather than the computed
         inverse — use Revoke instead if you need the inverse array itself
         (e.g. to reapply the same restoration to a companion array via
         Ordain). Result is Self.Length on success; 0 signals a length
         mismatch and means Self was left untouched. Caller must ensure
         aOrder is a valid permutation of 0..Length-1 — use Ratify to check
         first if the order's provenance isn't already trusted.
[==============================================================================}
function MArrayHelper.Rescind(const aOrder: TIntegerArray): Integer; overload;
var
  i, j, k: Integer;
  o: TIntegerArray;
  v: TBooleanArray;
  t: MType;
begin
  Result := Self.Length;
  if ((Result < 1) or (Result <> aOrder.Length)) then
    Exit(0);
  for i := 0 to o.Alloc(Result) do
    o[aOrder[i]] := i;
  for i := 0 to v.Alloc(Result) do
  begin
    if v[i] then
      Continue;
    j := i;
    t := Self[i];
    repeat
      k := o[j];
      if (k = i) then
      begin
        Self[j] := t;
        v[j] := True;
        Break;
      end;
      Self[j] := Self[k];
      v[j] := True;
      j := k;
    until False;
  end;
end;

{==============================================================================]
  <Revoke>
  @action: Rearranges Self in place by the inverse of a given order array —
           undoes what Enact/Ordain would have done with that same array.
           Returns the inverse order that was actually applied.
  @note: Bare verb, mutating, but returns a value — the forward order that
         would reproduce this same rearrangement if handed to Ordain on a
         companion array. Designed to close the loop with Sortie:
         Self.Revoke(anOrder) restores Self to the order it held before
         Enact/Ordain applied anOrder. Caller must ensure aOrder is a valid
         permutation of 0..Length-1 — use Ratify to check first if the
         order's provenance isn't already trusted.
[==============================================================================}
function MArrayHelper.Revoke(const aOrder: TIntegerArray): TIntegerArray; overload;
var
  s, i, j, k: Integer;
  v: TBooleanArray;
  t: MType;
begin
  s := Self.Length;
  if (s <> aOrder.Length) then
    Exit([]);
  for i := 0 to Result.Alloc(s) do
    Result[aOrder[i]] := i;
  for i := 0 to v.Alloc(s) do
  begin
    if v[i] then
      Continue;
    j := i;
    t := Self[i];
    while True do
    begin
      k := Result[j];
      if (k = i) then
      begin
        Self[j] := t;
        v[j] := True;
        Break;
      end;
      Self[j] := Self[k];
      v[j] := True;
      j := k;
    end;
  end;
end;

{==============================================================================]
  <Ratify>
  @action: Returns whether aOrder is a valid permutation of 0..Length-1 —
           safe to pass to Enact, Ordain, or Revoke.
  @note: Noun-derived, non-mutating. O(N) time, O(N) space for the seen-
         flags array. Checks length match, in-range values, and no
         duplicates — the three ways a permutation array can be invalid.
[==============================================================================}
function MArrayHelper.Ratify(const aOrder: TIntegerArray): Boolean; overload;
var
  s, i, v: Integer;
  m: TBooleanArray;
begin
  s := Self.Length;
  if (s <> aOrder.Length) then
    Exit(False);
  for i := 0 to m.Alloc(s) do
  begin
    v := aOrder[i];
    if ((v < 0) or (v >= s)) then
      Exit(False);
    if m[v] then
      Exit(False);
    m[v] := True;
  end;
  Result := True;
end;
{$ENDIF}
