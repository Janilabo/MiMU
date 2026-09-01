{$IFDEF HELPERS}
function SplitAtLeast(var rest: MArray; const target: MType): Integer; overload;
function SplitAtMost(var rest: MArray; const target: MType): Integer; overload;

function SplitAbove(var rest: MArray; const target: MType): Integer; overload;
function SplitBelow(var rest: MArray; const target: MType): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SplitAtLeast>
  @action: Partitions Self in place, keeping elements >= `target` in Self and
           moving the rest into `rest`. Returns the new length of Self.
  @note: Ordered-only tier. Relative order within each group is preserved
         (stable). Elements equal to `target` remain in Self.
[==============================================================================}
function MArrayHelper.SplitAtLeast(var rest: MArray; const target: MType): Integer; overload;
var
  i, r, s: Integer;
begin
  s := Self.Length;
  r := 0;
  Result := 0;
  for i := 0 to rest.Alloc(s) do
    if (Self[i] >= target) then
      Self[Result.Increase] := Self[i]
    else
      rest[r.Increase] := Self[i];
  if (Result < s) then
    SetLength(Self, Result);
  if (r < s) then
    SetLength(rest, r);
end;

{==============================================================================]
  <SplitAtMost>
  @action: Partitions Self in place, keeping elements <= `target` in Self and
           moving the rest into `rest`. Returns the new length of Self.
  @note: Ordered-only tier. Relative order within each group is preserved
         (stable). Elements equal to `target` remain in Self.
[==============================================================================}
function MArrayHelper.SplitAtMost(var rest: MArray; const target: MType): Integer; overload;
var
  i, r, s: Integer;
begin
  s := Self.Length;
  r := 0;
  Result := 0;
  for i := 0 to rest.Alloc(s) do
    if (Self[i] <= target) then
      Self[Result.Increase] := Self[i]
    else
      rest[r.Increase] := Self[i];
  if (Result < s) then
    SetLength(Self, Result);
  if (r < s) then
    SetLength(rest, r);
end;

{==============================================================================]
  <SplitAbove>
  @action: Partitions Self in place, keeping elements > `target` in Self and
           moving the rest into `rest`. Returns the new length of Self.
  @note: Ordered-only tier. Relative order within each group is preserved
         (stable). Elements equal to `target` move into `rest`.
[==============================================================================}
function MArrayHelper.SplitAbove(var rest: MArray; const target: MType): Integer; overload;
var
  i, r, s: Integer;
begin
  s := Self.Length;
  r := 0;
  Result := 0;
  for i := 0 to rest.Alloc(s) do
    if (Self[i] > target) then
      Self[Result.Increase] := Self[i]
    else
      rest[r.Increase] := Self[i];
  if (Result < s) then
    SetLength(Self, Result);
  if (r < s) then
    SetLength(rest, r);
end;

{==============================================================================]
  <SplitBelow>
  @action: Partitions Self in place, keeping elements < `target` in Self and
           moving the rest into `rest`. Returns the new length of Self.
  @note: Ordered-only tier. Relative order within each group is preserved
         (stable). Elements equal to `target` move into `rest`.
[==============================================================================}
function MArrayHelper.SplitBelow(var rest: MArray; const target: MType): Integer; overload;
var
  i, r, s: Integer;
begin
  s := Self.Length;
  r := 0;
  Result := 0;
  for i := 0 to rest.Alloc(s) do
    if (Self[i] < target) then
      Self[Result.Increase] := Self[i]
    else
      rest[r.Increase] := Self[i];
  if (Result < s) then
    SetLength(Self, Result);
  if (r < s) then
    SetLength(rest, r);
end;
{$ENDIF}
