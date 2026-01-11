{$IFDEF HELPERS}
function Line(const number: Integer): string; overload;
function LineEx(const number: Integer; const lineBreak: string): string; overload;
function LineEx(const number: Integer; const lineBreak: TStringArray): string; overload;
function LineEx(const number: Integer): string; overload;
function LineStr(const lineNumber: Integer): string; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Line>
  @action: Returns the text of the specified line number from the string,
           using standard text line break characters (#13, #10, or #13#10)
           as delimiters.
  @note: Line numbers are 1-based. Empty lines are valid and may be returned.
         Returns an empty string if the requested line number is less than 1,
         the string is empty, or the specified line does not exist. Handles
         mixed line endings and treats CRLF (#13#10) as a single line break.
[==============================================================================}
function TStringHelper.Line(const number: Integer): string; overload;
var
  i, s, n, l: Integer;
begin
  l := Length(Self);
  Result := '';
  if ((number < 1) or (l = 0)) then
    Exit;
  n := 1;
  s := 1;
  i := 0;
  while (i.Increment <= l) do
    if ((Self[i] = #10) or (Self[i] = #13)) then
    begin
      if (n = number) then
        Exit(Copy(Self, s, (i - s)));
      Inc(n);
      if ((Self[i] = #13) and (i < Length(Self)) and (Self[i + 1] = #10)) then
        Inc(i);
      s := (i + 1);
    end;
  if (n = number) then
    Result := Copy(Self, s, ((Length(Self) - s) + 1));
end;

{==============================================================================]
  <LineEx>
  @action: Returns the specified line number from the string, using the
           given line break delimiter string to split lines.
  @note: Line numbers are 1-based. Returns an empty string if the number
         is less than 1, the string is empty, or the line does not exist.
[==============================================================================}
function TStringHelper.LineEx(const number: Integer; const lineBreak: string): string; overload;
var
  r: TStringArray;
begin
  Result := '';
  if ((number < 1) or (Self = '')) then
    Exit;
  r := Self.Explode(lineBreak, (number + 1));
  if (r.Size >= number) then
    Result := r[number - 1];
end;

{==============================================================================]
  <LineEx>
  @action: Returns the specified line number from the string, using one of
           the provided line break delimiters in the TStringArray.
  @note: Line numbers are 1-based. Returns an empty string if the number
         is less than 1, the string is empty, or the line does not exist.
[==============================================================================}
function TStringHelper.LineEx(const number: Integer; const lineBreak: TStringArray): string; overload;
var
  r: TStringArray;
begin
  Result := '';
  if ((number < 1) or (Self = '')) then
    Exit;
  r := Self.Explode(lineBreak, (number + 1));
  if (r.Size >= number) then
    Result := r[number - 1];
end;

{==============================================================================]
  <LineEx>
  @action: Returns the specified line number from the string, using common
           line break sequences (#13#10, #13, #10) as delimiters.
  @note: Line numbers are 1-based. Returns an empty string if the number
         is less than 1 or the string is empty.
[==============================================================================}
function TStringHelper.LineEx(const number: Integer): string; overload;
begin
  Result := Self.LineEx(number, [#13#10, #13, #10]);
end;

{==============================================================================]
  <LineStr>
  @action: Returns the textual contents of the specified line from the string,
           excluding any line break characters.
  @note:
    - Line numbering is 1-based.
    - Internally uses LineRange to determine the line boundaries.
    - If the requested line does not exist, an empty string is returned.
    - Line terminators (#10, #13, or #13#10) are not included in the result.
[==============================================================================}
function TStringHelper.LineStr(const lineNumber: Integer): string; overload;
var
  R: TRange;
begin
  R := Self.LineRange(lineNumber);
  if ((R.start < 1) or (R.stop < R.start)) then
    Exit('');
  Result := Copy(Self, R.start, R.Size);
end;
{$ENDIF}