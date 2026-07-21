{$IFDEF HELPERS}
function Alias(const source: MArray): Integer; overload;
function Employ(const source: MArray): Integer; overload;
function Ply(const source: MArray): Integer; overload;
function Requisition(const source: MArray): Integer; overload;
function Update(const target: MArray): Integer; overload;
function Use(const source: MArray): Integer; overload;
function Wield(const source: MArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Alias>
  @action: Aliases Self to source via reference assignment; no element copy
  @note: Self and source share the same underlying array after this call.
         Mutating either one affects both. O(1) — cheap, but non-owning.
[==============================================================================}
function MArrayHelper.Alias(const source: MArray): Integer; overload;
begin
  Result := source.Length;
  Self := source;
end;

{==============================================================================]
  <Employ>
  @action: Deep-copies source into Self via System.Copy, resizing Self to
           match source's length
  @note: Self receives an independent copy; mutating Self afterward does not
         affect source. Self fully owns the resulting data. Uses the RTL's
         built-in Copy() rather than a manual element loop.
[==============================================================================}
function MArrayHelper.Employ(const source: MArray): Integer; overload;
begin
  Self := System.Copy(source, 0, source.Length);
  Result := Self.Length;
end;

{==============================================================================]
  <Ply>
  @action: Deep-copies source into Self via Concat against an empty array,
           fully replacing Self's prior contents
  @note: Self receives an independent copy; mutating Self afterward does not
         affect source. Self fully owns the resulting data. Functionally
         equivalent to Copy() or Insert-based replacement, routed through
         Concat as the underlying RTL mechanism.
[==============================================================================}
function MArrayHelper.Ply(const source: MArray): Integer; overload;
begin
  Self := System.Concat(MArray(nil), source);
  Result := Self.Length;
end;

{==============================================================================]
  <Requisition>
  @action: Deep-copies source into Self by clearing Self and inserting
           source's full contents via the RTL's array Insert procedure
  @note: Self receives an independent copy; mutating Self afterward does not
         affect source. Self fully owns the resulting data. Uses Insert/splice
         rather than a manual loop or Copy() — functionally equivalent to
         Copy(), routed through a different RTL entry point.
[==============================================================================}
function MArrayHelper.Requisition(const source: MArray): Integer; overload;
begin
  SetLength(Self, 0);
  Insert(source, Self, 0);
  Result := Self.Length;
end;

{==============================================================================]
  <Update>
  @action: Overwrites Self with a copy of target and returns the new length.
  @note: Mutates Self by reassignment; target is duplicated via System.Copy
         so Self and target remain independent after the call. Differs from
         the MArray-returning overload only in its return value.
[==============================================================================}
function MArrayHelper.Update(const target: MArray): Integer; overload;
begin
  MArray(Self) := System.Copy(target);
  Result := Self.Length;
end;

{==============================================================================]
  <Use>
  @action: Aliases Self to source via reference assignment; no element copy
  @note: Self and source share the same underlying array after this call.
         Mutating either one affects both. O(1) — cheap, but non-owning.
[==============================================================================}
function MArrayHelper.Use(const source: MArray): Integer; overload;
begin
  Self := source;
  Result := Self.Length;
end;

{==============================================================================]
  <Wield>
  @action: Deep-copies source into Self, resizing Self to match source's length
  @note: Self receives an independent copy; mutating Self afterward does not
         affect source. O(n) — costs a full element copy, but Self fully owns
         the resulting data.
[==============================================================================}
function MArrayHelper.Wield(const source: MArray): Integer; overload;
var
  r: Integer;
begin
  Result := source.Length;
  for r := 0 to (Self.SetSize(Result) - 1) do
    Self[r] := source[r];
end;
{$ENDIF}
