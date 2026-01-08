{$IFDEF HELPERS}
function Fill(const item: MType; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload; cdecl;
function Fill(const items: MArray; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload; cdecl;
function Populate(const items: MArray; const times: Integer = 1): Boolean; overload; cdecl;
function Populate(const item: MType; const times: Integer = 1): Boolean; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Fill>
  @action: Fills whole arr with item.
  @note: Returns the filled array.
[==============================================================================}
function MArrayHelper.Fill(const item: MType; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload; cdecl;
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
function MArrayHelper.Fill(const items: MArray; const index: Integer = 0; const count: Integer = 2147483647): MArray; overload; cdecl;
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
function MArrayHelper.Populate(const items: MArray; const times: Integer = 1): Boolean; overload; cdecl;
var
  i, j, l: Integer;
begin
  l := items.Length;
  SetLength(Self, (l * times));
  Result := (Self.Size > 0);
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
function MArrayHelper.Populate(const item: MType; const times: Integer = 1): Boolean; overload; cdecl;
var
  i: Integer;
begin;
  SetLength(Self, times);
  Result := (Self.Size > 0);
  if Result then
  for i := 0 to (times - 1) do
    Self[i] := item;
end;
{$ENDIF}