{$IFDEF HELPERS}
function Fill(const item: MType; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Fill(const items: MArray; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
function Populate(const items: MArray; const times: Integer = 1): Boolean; overload;
function Populate(const item: MType; const times: Integer = 1): Boolean; overload;

function Exscribe(var target: MArray): Integer; overload;
function Inscribe(const source: MArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Fill>
  @action: Fills whole arr with item.
  @note: Returns the filled array.
[==============================================================================}
function MArrayHelper.Fill(const item: MType; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
var
  h, i, s, t: Integer;
begin
  s := Max(0, index);
  h := High(Self);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := Self[i];
end;

{==============================================================================]
  <Fill>
  @action: Fills whole arr with items.
  @note: None
[==============================================================================}
function MArrayHelper.Fill(const items: MArray; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload;
var
  h, i, s, t, l: Integer;
begin
  h := High(Self);
  l := items.Length;
  case l of
    0: Exit(Self.Copy);
    1: Exit(Self.Fill(items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[(index + i) mod (l - 1)];
  for i := (t + 1) to h do
    Result[i] := Self[i];
end;

{==============================================================================]
  <Populate>
  @action: Populates array with items, x-times.
  @note: Returns true if items is not empty and times is more than 0.
[==============================================================================}
function MArrayHelper.Populate(const items: MArray; const times: Integer = 1): Boolean; overload;
var
  i, j, l: Integer;
begin
  l := items.Length;
  Result := (Self.SetSize(l * times) > 0);
  if Result then
  for i := 0 to (l - 1) do
    for j := 0 to (times - 1) do
      Self[i + (j * l)] := items[i];
end;

{==============================================================================]
  <Populate>
  @action: Populates array with item, x-times.
  @note: Returns true if times is more than 0.
[==============================================================================}
function MArrayHelper.Populate(const item: MType; const times: Integer = 1): Boolean; overload;
var
  i: Integer;
begin;
  Result := (Self.SetSize(times) > 0);
  if Result then
  for i := 0 to (times - 1) do
    Self[i] := item;
end;

{==============================================================================]
  <Exscribe>
  @action: Copies/exports elements from the current array (Self) into a target array.
  @note: Assumes 'target' is already allocated with sufficient length.
         Returns the number of elements copied.
[==============================================================================}
function MArrayHelper.Exscribe(var target: MArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to (Result - 1) do
    target[i] := Self[i];
end;

{==============================================================================]
  <Inscribe>
  @action: Copies/imports elements from a source array into the current array (Self).
  @note: Assumes 'Self' is already allocated with sufficient length to hold the source data.
         Returns the number of elements copied.
[==============================================================================}
function MArrayHelper.Inscribe(const source: MArray): Integer; overload;
var
  i: Integer;
begin
  Result := source.Length;
  for i := 0 to (Result - 1) do
    Self[i] := source[i];
end;
{$ENDIF}