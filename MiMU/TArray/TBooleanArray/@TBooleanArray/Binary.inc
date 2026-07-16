{$IFDEF FUNCTIONS}
function Binared(const arr: TBooleanArray): string; overload;
function Binariate(const arr: TBooleanArray): string; overload;
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
{==============================================================================]
  <Binared>
  @action: Converts a TBooleanArray into a formatted binary digits string 
           using the native system formatting engine.
  @note: Manually populates a dynamic array of TVarRec records with integer-cast 
         ordinal values, matching the precise memory structure required by 
         Format to generate a contiguous '0' and '1' character string.
[==============================================================================}
function Binared(const arr: TBooleanArray): string; overload;
var
  l, i: Integer;
  a: TConstArray;
begin
  l := Length(arr);
  SetLength(a, l);
  for i := 0 to (l - 1) do
  begin
    a[i].VType := vtInteger;
    a[i].VInteger := Ord(arr[i]);
  end;
  Result := Format(DupeString('%d', l), a);
end;

{==============================================================================]
  <Binariate>
  @action: Transmutes a TBooleanArray into a binary digits string via low-level 
           direct memory pointer manipulation.
  @note: Bypasses standard indexing entirely by writing ASCII character offsets 
         (0 + 48 = '0', 1 + 48 = '1') straight into the allocated string memory 
         buffer using a moving PChar pointer for maximum execution velocity.
[==============================================================================}
function Binariate(const arr: TBooleanArray): string; overload;
var
  p: PChar;
  i: Integer;
begin
  SetLength(Result, Length(arr));
  p := PChar(Result);
  for i := 0 to High(arr) do
  begin
    p^ := Chr(Ord(arr[i]) + 48);
    Inc(p);
  end;
end;

{==============================================================================]
  <Binaried>
  @action: Converts a TBooleanArray into a binary digits string using the native 
           SysUtils boolean-to-string transformation utility.
  @note: Relies on BoolToStr string lookups to dynamically fetch '1' or '0' 
         strings based on state, extracting the first character of the return 
         buffer to populate the target string indexes.
[==============================================================================}
function Binaried(const arr: TBooleanArray): string; overload;
var
  i, l: Integer;
begin
  l := arr.Length;
  SetLength(Result, l);
  for i := 1 to l do
    Result[i] := BoolToStr(arr[i - 1], '1', '0')[1];
end;

{==============================================================================]
  <Binarify>
  @action: Evaluates a TBooleanArray into a binary digits string using conditional 
           branch lookup functions.
  @note: Employs standard StrUtils.IfThen ternary evaluations to map true/false 
         states into string constants, copying the character results sequentially.
[==============================================================================}
function Binarify(const arr: TBooleanArray): string; overload;
var
  i, l: Integer;
begin
  l := arr.Length;
  SetLength(Result, l);
  for i := 1 to l do
    Result[i] := IfThen(arr[i - 1], '1', '0');
end;

{==============================================================================]
  <Binarize>
  @action: Translates a TBooleanArray into a binary digits string using a 
           zero-branch constant character matrix lookup.
  @note: The gold standard for high-performance array helpers. Completely avoids 
         conditional branching and function calls by using boolean values directly 
         as array indexing keys to dump '0' and '1' literals straight to memory.
[==============================================================================}
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
