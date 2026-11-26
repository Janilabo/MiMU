{$IFDEF HELPERS}
function Adjentical: TIntegerArray; overload;
function Adupex: TIntegerArray; overload;
function Dupes: TIntegerArray; overload;
function Dupex: TIntegerArray; overload;
function Duplica: TIntegerArray; overload;
function Repex: TIntegerArray; overload;
function Uniques: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Adjentical>
  @action: Returns the indices of adjacent identical elements in the array.
  @note: Exits early with an empty array when `High(Self) < 1` (fewer than two
         elements). For `i` from `1` to `High(Self)`, each index where
         `Self[i] = Self[i - 1]` is recorded and trimmed to match count `r`.
[==============================================================================}
function MArrayHelper.Adjentical: TIntegerArray; overload;
var
  h, i, r: Integer;
begin
  h := High(Self);
  if (Result.SetSize(Max(0, h)) = 0) then
    Exit;
  r := 0;
  i := 0;
  while (i.Increment <= h) do
    while ((i <= h) and (Self[i] = Self[i - 1])) do
      Result[r.Increase] := i.Increase;
  SetLength(Result, r);
end;

{==============================================================================]
  <Adupex>
  @action: Returns the indices of consecutive duplicate elements in the array.
  @note: For each index `i` (from `1` to `High(Self)`), if `Self[i] = Self[i - 1]`,
         `i` is included in the returned array and trimmed to the exact match count.
[==============================================================================}
function MArrayHelper.Adupex: TIntegerArray; overload;
var
  i, c: Integer;
begin
  c := 0;
  for i := 1 to Result.SetSize(Max(0, (Self.Length - 1))) do
    if (Self[i] = Self[i - 1]) then
      Result[c.Increase] := i;
  SetLength(Result, c);
end;

{==============================================================================]
  <Dupex>
  @action: Returns the indices of duplicate elements in the array.
  @note: For each index `i` from `1` to `High(Self)`, if `Self[i]` matches any
         earlier element `Self[j]` (`0 <= j < i`), `i` is recorded once and
         the result is trimmed to the exact match count `r`.
[==============================================================================}
function MArrayHelper.Dupes: TIntegerArray; overload;
var
  i, j, r: Integer;
begin
  r := 0;
  for i := 1 to Result.SetSize(Max(0, (Self.Length - 1))) do
    for j := 0 to (i - 1) do
      if (Self[i] = Self[j]) then
      begin
        Result[r.Increase] := i;
        Break;
      end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Dupex>
  @action: Returns the indices of duplicate elements in the array.
  @note: Uses a `TDictionary<MType, Boolean>` seen-set to track previously
         encountered elements; when `Self[i]` is already present, index `i` is
         recorded and `Result` is trimmed to match count `r`.
[==============================================================================}
function MArrayHelper.Dupex: TIntegerArray; overload;
var
  i, r: Integer;
  d: specialize TDictionary<MType, Boolean>;
begin
  if (Result.SetSize(Max(0, (Self.Length - 1))) = 0) then
    Exit;
  r := 0;
  d := specialize TDictionary<MType, Boolean>.Create(Self.Length);
  try
    d.Add(Self[0], True);
    for i := 1 to High(Self) do
      if d.ContainsKey(Self[i]) then
        Result[r.Increase] := i
      else
        d.Add(Self[i], True);
  finally
    d.Free;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Duplica>
  @action: Returns the indices of consecutive duplicate elements in the array.
  @note: Exits early with an empty array when fewer than two elements exist.
         Tracks the preceding element in `s` (starting at `Self[0]`), records each
         index `i` (from `1` to `High(Self)`) where `Self[i] = s`, updates `s`
         when unequal, and trims the result to match count `r`.
[==============================================================================}
function MArrayHelper.Duplica: TIntegerArray; overload;
var
  i, r: Integer;
  s: MType;
begin
  if (Result.SetSize(Max(0, (Self.Length - 1))) = 0) then
    Exit;
  r := 0;
  s := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] = s) then
      Result[r.Increase] := i
    else
      s := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Repex>
  @action: Returns the indices of consecutive duplicate elements in the array.
  @note: Counts adjacent equal pairs (`Self[i] = Self[i - 1]`) in a first pass,
         sizes `Result` to the exact count, and populates matching indices in a
         second pass without trimming.
[==============================================================================}
function MArrayHelper.Repex: TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  for i := 1 to High(Self) do
    if (Self[i] = Self[i - 1]) then
      Inc(r);
  if (Result.SetSize(r) > 0) then
  for i := High(Self) downto 1 do
    if (Self[i] = Self[i - 1]) then
      Result[r.Decrement] := i;
end;

{==============================================================================]
  <Uniques>
  @action: Returns the indexes of unique array (arr) items.
  @note: None.
[==============================================================================}
function MArrayHelper.Uniques: TIntegerArray; overload;
var
  h, r, x, y: Integer;
  m: Boolean;
begin
  h := High(Self);
  if (Result.SetSize(h + 1) > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and (Self[x] = Self[y]));
        if m then
          Break;
      end;
      if not m then
        Result[r.Increase] := x;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;
{$ENDIF}