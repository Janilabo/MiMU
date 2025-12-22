{$IFDEF HELPERS}
function Quotatation: string;
function PregQuote(const regex: string = '.\+*?[^]$(){}=!<>|:-'): string;
function AsTRange: TRange;
function ToTRange(const glueRange: string = '..'; const openRange: Char = '['; const closeRange: Char = ']'): TRange;
function IsBinary(const emptyTrue: Boolean = True): Boolean;
function BoolifyBinary: TBooleanArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Quotatation>
  @action: Returns the quoted version of str.
  @note: None
[==============================================================================}
function TStringHelper.Quotatation: string;
begin
  Result := ('''' + StringReplace(Self, '''', '''''', [rfReplaceAll]) + '''');
end;

{==============================================================================]
  <PregQuote>
  @action: Returns string with all characters escaped that are part of the regular expression syntax.
  @note: Based on the character set...
[==============================================================================}
function TStringHelper.PregQuote(const regex: string = '.\+*?[^]$(){}=!<>|:-'): string;
var
  l, i: Integer;
begin
  Result := Self;
  l := Length(Self);
  if (l > 0) then
  for i := l downto 1 do
    if (regex.Pos(Self[i]) > 0) then
      Insert('\', Result, i);
end;

{==============================================================================]
  <AsTRange>
  @action: Returns indexes of string as TRange.
  @note: With empty string this function returns as 0..0!
[==============================================================================}
function TStringHelper.AsTRange: TRange;
begin
  Result.Build(Min(1, Length(Self)), Length(Self));
end;

{==============================================================================]
 <ToTRange>
 @action: Converts string to TRange.
 @note: None
[==============================================================================}
function TStringHelper.ToTRange(const glueRange: string = '..'; const openRange: Char = '['; const closeRange: Char = ']'): TRange;
var
  s: string;
  p: Integer;
begin
  s := Self.Trim;
  if ((s <> '') and (s[1] in ['[', '(', '{', '<'])) then
    Delete(s, 1, 1);
  if ((s <> '') and (s[Length(s)] in [']', ')', '}', '>'])) then
    Delete(s, Length(s), 1);
  p := s.Pos(glueRange);
  if (p = 0) then
    Exit(Result.Create(-2147483648));
  Result.Create(StrToInt(Copy(s, 1, (p - 1)).Trim), StrToInt(Copy(s, (p + Length(glueRange)), 2147483647).Trim));
end;

{==============================================================================]
  <IsBinary>
  @action: Returns true if str contains only 0's and 1's
  @note: If str is empty and emptyTrue is True, then this function returns True with empty strings.
[==============================================================================}
function TStringHelper.IsBinary(const emptyTrue: Boolean = True): Boolean;
var
  i: Integer;
begin
  if (Self = '') then
    Exit(emptyTrue);
  for i := 1 to Length(Self) do
    if not (Self[i] in ['0', '1']) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <BoolifyBinary>
  @action: '10101' => [True, False, True, False, True]
  @note: Considers only '1' as True, everything else as False.
[==============================================================================}
function TStringHelper.BoolifyBinary: TBooleanArray;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 1 to Length(Self) do
    Result[i - 1] := (Self[i] = '1');
end;
{$ENDIF}