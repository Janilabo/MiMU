{$IFDEF HELPERS}
function BitMax: Integer;
function Unbitify: TBooleanArray; overload;
function Unbitify(const bCount: Integer): TBooleanArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BitMax>
  @action: Returns maximum bit index
  @note: Returns -1 with negatives.
[==============================================================================}
function TIntegerHelper.BitMax: Integer;
var
  i: Integer;
begin
  if (Self < 0) then
    Exit(-1);
  if (Self > 0) then
  for i := 31 downto 0 do
    if ((Self shr i) <> 0) then
      Exit(i);
  Result := 0;
end;

{==============================================================================]
  <Unbitify>
  @action: Returns array of Booleans by bits.
  @note: None.
[==============================================================================}
function TIntegerHelper.Unbitify: TBooleanArray; overload;
var
  c, i, s: Integer;
begin
  if (Self < 0) then
    Exit([]);
  s := Self;
  c := (s.BitMax + 1);
  SetLength(Result, c);
  for i := (c - 1) downto 0 do
  begin
    Result[i] := ((s and 1) <> 0);
    s := (s shr 1);
  end;
end;

{==============================================================================]
  <Unbitify>
  @action: Returns array of Booleans by bits.
  @note: None.
[==============================================================================}
function TIntegerHelper.Unbitify(const bCount: Integer): TBooleanArray; overload;
var
  i, s: Integer;
begin
  if ((Self < 0) or (bCount < 1)) then
    Exit([]);
  s := Self;
  SetLength(Result, bCount);
  for i := (bCount - 1) downto 0 do
  begin
    Result[i] := ((s and 1) <> 0);
    s := (s shr 1);
  end;
end;
{$ENDIF}