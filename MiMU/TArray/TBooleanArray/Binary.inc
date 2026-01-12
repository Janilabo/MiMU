{$IFDEF HELPERS}
function Binary: string;
function BinaryDigits: TIntegerArray;
function BinaryStr: string;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Binary>
  @action: Returns binary string from Boolean Array
  @note: [True, False] => '10' & [False, True] => '01'
[==============================================================================}
function TBooleanArrayHelper.Binary: string;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Binary;
end;

{==============================================================================]
  <BinaryDigits>
  @action: Returns binary digits from Boolean Array
  @note: [True, False] => [1, 0] & [False, True] => [0, 1]
[==============================================================================}
function TBooleanArrayHelper.BinaryDigits: TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := IfThen(Self[i], 1, 0);
end;

{==============================================================================]
  <BinaryStr>
  @action: Returns binary string from Boolean Array
  @note: [True, False] => '10' & [False, True] => '01'
[==============================================================================}
function TBooleanArrayHelper.BinaryStr: string;
var
  i: Integer;
begin
  Result := '';
  for i := 0 to High(Self) do
    Result := (Result + IfThen(Self[i], '1', '0'));
end;
{$ENDIF}
