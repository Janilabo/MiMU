{$IFDEF HELPERS}
function Absorb(const source: M2DArray): Integer; overload;
function Alias(const source: M2DArray): Integer; overload;
function Use(const source: M2DArray): Integer; overload;
function Employ(const source: M2DArray): Integer; overload;
function Ply(const source: M2DArray): Integer; overload;
function Requisition(const source: M2DArray): Integer; overload;
function Update(const target: M2DArray): Integer; overload;
function Wield(const source: M2DArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Absorb>
  @action: Deep-copies source into Self, resizing Self's outer array to match
           source's row count, resizing each row to match its corresponding source row,
           and copying every element individually. Returns the total number of
           elements copied across all rows.
  @note: Self receives a fully independent copy at both the outer-array and
         row level; mutating Self (or any of its rows) afterward does not affect
         source. Rows that resize to zero length (source row was empty) contribute
         nothing to Result. Uses a manual nested loop rather than System.Copy,
         Concat, or Insert.
[==============================================================================}
function M2DArrayHelper.Absorb(const source: M2DArray): Integer; overload;
var
  i, j: Integer;
begin
  Result := 0;
  for i := 0 to (Self.SetSize(source.Length) - 1) do
    if (Self[i].SetSize(source[i].Length) > 0) then
    begin
      Inc(Result, Self[i].Length);
      for j := 0 to High(Self[i]) do
        Self[i][j] := source[i][j];
    end;
end;

{==============================================================================]
  <Alias>
  @action: Aliases Self to source via reference assignment; no row copy
  @note: Self and source share the same underlying rows after this call.
         Mutating either one (including any individual row) affects both.
         O(1) — cheap, but non-owning at both the row and outer-array level.
[==============================================================================}
function M2DArrayHelper.Alias(const source: M2DArray): Integer; overload;
begin
  Result := source.Length;
  Self := source;
end;

{==============================================================================]
  <Use>
  @action: Aliases Self to source via reference assignment; no row copy
  @note: Self and source share the same underlying rows after this call.
         Mutating either one (including any individual row) affects both.
         O(1) — cheap, but non-owning at both the row and outer-array level.
[==============================================================================}
function M2DArrayHelper.Use(const source: M2DArray): Integer; overload;
begin
  Self := source;
  Result := Self.Length;
end;

{==============================================================================]
  <Employ>
  @action: Deep-copies source into Self, resizing Self to match source's
           length and independently copying every row via System.Copy
  @note: Self receives a fully independent copy at both the outer-array and
         row level; mutating Self (or any of its rows) afterward does not
         affect source. Self fully owns the resulting data. The outer array
         is duplicated via the RTL's built-in Copy(), then each row is
         individually re-copied to avoid row-level aliasing.
[==============================================================================}
function M2DArrayHelper.Employ(const source: M2DArray): Integer; overload;
var
  i: Integer;
begin
  Self := System.Copy(source, 0, source.Length);
  for i := 0 to High(Self) do
    Self[i] := System.Copy(source[i], 0, source[i].Length);
  Result := Self.Length;
end;

{==============================================================================]
  <Ply>
  @action: Deep-copies source into Self via Concat against an empty array at
           the outer level, then independently copies every row
  @note: Self receives a fully independent copy at both the outer-array and
         row level; mutating Self (or any of its rows) afterward does not
         affect source. Self fully owns the resulting data. Outer replacement
         is routed through Concat as in the 1D version; rows are re-copied
         afterward to avoid row-level aliasing, since Concat alone only
         duplicates row references.
[==============================================================================}
function M2DArrayHelper.Ply(const source: M2DArray): Integer; overload;
var
  i: Integer;
begin
  Self := System.Concat(M2DArray(nil), source);
  for i := 0 to High(Self) do
    Self[i] := System.Concat(MArray(nil), source[i]);
  Result := Self.Length;
end;

{==============================================================================]
  <Requisition>
  @action: Deep-copies source into Self by clearing Self and inserting
           source's full contents via the RTL's array Insert procedure at
           the outer level, then independently copying every row
  @note: Self receives a fully independent copy at both the outer-array and
         row level; mutating Self (or any of its rows) afterward does not
         affect source. Self fully owns the resulting data. Outer replacement
         uses Insert/splice as in the 1D version; rows are re-copied
         afterward, since Insert alone only duplicates row references.
[==============================================================================}
function M2DArrayHelper.Requisition(const source: M2DArray): Integer; overload;
var
  i: Integer;
begin
  SetLength(Self, 0);
  Insert(source, Self, 0);
  for i := 0 to High(Self) do
  begin
    SetLength(Self[i], 0);
    Insert(source[i], Self[i], 0);
  end;
  Result := Self.Length;
end;

{==============================================================================]
  <Update>
  @action: Overwrites Self with a deep copy of target and returns the new
           length.
  @note: Mutates Self by reassignment; target's outer array and every one of
         its rows are duplicated via System.Copy, so Self and target remain
         fully independent — at both the outer-array and row level — after
         the call. Differs from the M2DArray-returning overload only in its
         return value.
[==============================================================================}
function M2DArrayHelper.Update(const target: M2DArray): Integer; overload;
var
  i: Integer;
begin
  M2DArray(Self) := System.Copy(target);
  for i := 0 to High(Self) do
    Self[i] := System.Copy(target[i]);
  Result := Self.Length;
end;

{==============================================================================]
  <Wield>
  @action: Deep-copies source into Self, resizing Self to match source's
           length and copying every row independently
  @note: Self receives a fully independent copy at both the outer-array and
         row level; mutating Self (or any of its rows) afterward does not
         affect source. O(n*m) — costs a full row-by-row element copy, but
         Self fully owns the resulting data. Uses each row's own Wield to
         perform the per-row deep copy, rather than a bare reference
         assignment (which would only copy row pointers).
[==============================================================================}
function M2DArrayHelper.Wield(const source: M2DArray): Integer; overload;
var
  r: Integer;
begin
  Result := source.Length;
  for r := 0 to (Self.SetSize(Result) - 1) do
    Self[r].Wield(source[r]);
end;
{$ENDIF}
