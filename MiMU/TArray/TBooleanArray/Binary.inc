{$IFDEF FUNCTIONS}
function Binared(const arr: TBooleanArray): string; overload;
function Binaried(const arr: TBooleanArray): string; overload;
function Binarify(const arr: TBooleanArray): string; overload;
function Binarize(const arr: TBooleanArray): string; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Binary: string;
function BinaryDigits: TIntegerArray;
function BinaryStr: string;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function Binared(const arr: TBooleanArray): string; overload;
  function Recvar: TConstArray;
  var
    i: Integer;
  begin
    SetLength(Result, Length(arr));
    for i := 0 to High(arr) do
    begin
      Result[i].VType := vtInteger;
      Result[i].VInteger := Ord(arr[i]);
    end;
  end;
begin
  Result := Format(DupeString('%d', arr.Length), Recvar);
end;

function Binaried(const arr: TBooleanArray): string; overload;
var
  i, l: Integer;
begin
  l := arr.Length;
  SetLength(Result, l);
  for i := 1 to l do
    Result[i] := BoolToStr(arr[i - 1], '1', '0')[1];
end;

function Binarify(const arr: TBooleanArray): string; overload;
var
  i, l: Integer;
begin
  l := arr.Length;
  SetLength(Result, l);
  for i := 1 to l do
    Result[i] := IfThen(arr[i - 1], '1', '0');
end;

function Binarize(const arr: TBooleanArray): string; overload;
const
  C: array[Boolean] of Char = ('0', '1');
var
  i, l: Integer;
begin
  l := arr.Length;
  SetLength(Result, l);
  for i := 1 to l do
    Result[i] := C[arr[i - 1]];
end;

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
