{$IFDEF HELPERS}
function Implant(const source: MArray; const sAdjustment: Integer): Integer; overload;
function Implant(const source: MArray): Integer; overload;
function Plant(const source: MArray; const sAdjustment: Integer): Integer; overload;
function Plant(const source: MArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Implant>
  @action: Resizes Self to `source.Length + sAdjustment` (minimum 0), then copies
           `source` into Self position-for-position, without wrapping.
  @note: If Self is larger than `source`, the remaining elements retain their
         default value. Returns High(Self) after resizing.
[==============================================================================}
function MArrayHelper.Implant(const source: MArray; const sAdjustment: Integer): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Alloc(Max(0, (source.Length + sAdjustment)));
  for i := 0 to Min(High(source), Result) do
    Self[i] := source[i];
end;

{==============================================================================]
  <Implant>
  @action: Resizes Self to exactly `source.Length`, then copies every element of
           `source` into Self, position-for-position.
  @note: Overload without `sAdjustment` — Self ends up the same size as `source`,
         so no clipping or padding occurs. Returns High(Self) after resizing.
[==============================================================================}
function MArrayHelper.Implant(const source: MArray): Integer; overload;
begin
  for Result := 0 to Self.Alloc(source.Length) do
    Self[Result] := source[Result];
end;

{==============================================================================]
  <Plant>
  @action: Resizes Self to `source.Length + sAdjustment` (minimum 0), then fills
           Self by cyclically repeating `source` (wrapping via modulo) until every
           element is set.
  @note: If `source` is empty, Self is resized but left unfilled. Returns
         High(Self) after resizing.
[==============================================================================}
function MArrayHelper.Plant(const source: MArray; const sAdjustment: Integer): Integer; overload;
var
  i, s: Integer;
begin
  s := source.Length;
  Result := (Self.SetSize(Max(0, (s + sAdjustment))) - 1);
  if (s > 0) then
  for i := 0 to Result do
    Self[i] := source[i mod s];
end;

{==============================================================================]
  <Plant>
  @action: Resizes Self to exactly `source.Length`, then copies every element of
           `source` into Self, position-for-position.
  @note: Overload without `sAdjustment` — since Self ends up the same size as
         `source`, the cyclical wrap that distinguishes `Plant` from `Implant`
         never actually triggers (`i mod s` always equals `i` when Self and
         source are the same length). Returns High(Self) after resizing.
[==============================================================================}
function MArrayHelper.Plant(const source: MArray): Integer; overload;
begin
  for Result := 0 to (Self.SetSize(source.Length) - 1) do
    Self[Result] := source[Result];
end;
{$ENDIF}