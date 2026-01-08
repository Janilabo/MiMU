{$IFDEF HELPERS}
function LineAmount: Integer; overload; cdecl;
function LineCount: Integer; overload; cdecl;
function LineCountEx(const lineBreak: string): Integer; overload; cdecl;
function LineCountEx(const lineBreak: TStringArray): Integer; overload; cdecl;
function LineCountEx: Integer; overload; cdecl;
function LineCountUpTo(const targetLine: Integer): Integer; overload; cdecl;
function LinePopulation: Integer; overload; cdecl;
function LineQuantity: Integer; overload; cdecl;
function LinesCount: Integer; overload; cdecl;
function LinesCounted: Integer; overload; cdecl;
function LinesTotal: Integer; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <LineAmount>
  @action: Returns the total number of lines in the string. Lines are determined by
           standard newline characters: CR (#13), LF (#10), and CRLF (#13#10).
  @note:
    - For an empty string (''), the result is 1, representing a single
      empty line.
    - Consecutive line breaks are counted as separate lines, producing
      multiple empty lines.
    - CRLF sequences are treated as a single line break.
    - The function performs a single forward scan of the string.
[==============================================================================}
function TStringHelper.LineAmount: Integer; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  Result := 1;
  i := 0;
  while (i.Increment <= l) do
    if ((Self[i] = #10) or (Self[i] = #13)) then
    begin
      Inc(Result);
      if ((Self[i] = #13) and (i < l) and (Self[i + 1] = #10)) then
        Inc(i);
    end;
end;

{==============================================================================]
  <LineCount>
  @action: Returns the total number of lines in the string.
           Counts trailing line breaks as a separate line.
  @note:
    - Line numbering is 1-based.
    - An empty string is considered to contain a single line.
    - Line breaks are recognized using all common conventions:
        * CRLF (#13#10)
        * LF   (#10)
        * CR   (#13)
      CRLF sequences are counted as a single line break.
    - A trailing line break adds an additional line.
    - This implementation scans using a single-pass pointer loop with
      case handling for CR and LF, skipping the LF of CRLF sequences.
    - No temporary allocations are performed.
[==============================================================================}
function TStringHelper.LineCount: Integer; overload; cdecl;
var
  S, C, E: PChar;
  L: Integer;
begin
  L := Length(Self);
  Result := 1;
  if (L = 0) then
    Exit;
  S := PChar(Self);
  C := S;
  E := (S + (L - 1));
  while (C <= E) do
  begin
    case C^ of
      #10: Inc(Result);
      #13:
      begin
        Inc(Result);
        if ((C < E) and (C[1] = #10)) then
          Inc(C);
      end;
    end;
    Inc(C);
  end;
end;

{==============================================================================]
  <LineCountEx>
  @action: Returns the number of lines in the string, using the specified
           line break string as delimiter.
  @note: Returns 0 if the string is empty.
[==============================================================================}
function TStringHelper.LineCountEx(const lineBreak: string): Integer; overload; cdecl;
begin
  Result := Self.LinesEx(lineBreak).Length;
end;

{==============================================================================]
  <LineCountEx>
  @action: Returns the number of lines in the string, using any of the provided
           line break strings in the TStringArray as delimiters.
  @note: Returns 0 if the string is empty or the delimiter array is empty.
[==============================================================================}
function TStringHelper.LineCountEx(const lineBreak: TStringArray): Integer; overload; cdecl;
begin
  Result := Self.LinesEx(lineBreak).Length;
end;

{==============================================================================]
  <LineCountEx>
  @action: Returns the number of lines in the string, using the default line
           breaks (#13#10, #13, #10) as delimiters.
  @note:   Returns 0 if the string is empty.
[==============================================================================}
function TStringHelper.LineCountEx: Integer; overload; cdecl;
begin
  Result := Self.LineCountEx([#13#10, #13, #10]);
end;

{==============================================================================]
  <LineCountUpTo>
  @action: Counts the number of lines in the string, stopping early once the specified
           target line number is reached.
  @note:
    - Line numbering is 1-based.
    - The function never returns a value greater than targetLine.
    - Line breaks are recognized in the following forms:
        * LF   (#10)
        * CR   (#13)
        * CRLF (#13#10) treated as a single line break
    - If targetLine < 1, the function returns 0.
    - If the string is empty, the function returns 1.
    - Designed for efficient early-exit use cases such as LineExists,
      LineClamp, or LineValid, avoiding a full line scan when unnecessary.
[==============================================================================}
function TStringHelper.LineCountUpTo(const targetLine: Integer): Integer; overload; cdecl;
var
  i, l: Integer;
begin
  if (targetLine < 1) then
    Exit(0);
  l := Length(Self);
  if (l = 0) then
    Exit(1);
  Result := 1;
  i := 0;
  while ((i.Increment <= l) and (Result < targetLine)) do
  case Self[i] of
    #10: Inc(Result);
    #13:
    begin
      Inc(Result);
      if ((i < l) and (Self[i + 1] = #10)) then
        Inc(i);
    end;
  end;
end;

{==============================================================================]
  <LinePopulation>
  @action: Returns the total number of logical lines contained in the string.
  @note:
    - Lines are delimited using standard newline characters:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single line break.
    - Consecutive line breaks produce empty lines, each counted separately.
    - For an empty string, the function returns 1, representing a
      single empty line.
    - The function uses a for loop and a boolean flag p to detect CRLF
      sequences efficiently.
[==============================================================================}
function TStringHelper.LinePopulation: Integer; overload; cdecl;
var
  i, l: Integer;
  p: Boolean;
begin
  l := Length(Self);
  Result := 1;
  p := False;
  for i := 1 to l do
  case (Self[i] = #13) of
    True:
    begin
      Inc(Result);
      p := True;
    end;
    False:
    begin
      if ((Self[i] = #10) and (not p)) then
        Inc(Result);
      p := False;
    end;
  end;
end;

{==============================================================================]
  <LineQuantity>
  @action: Returns the total number of logical lines contained in the string.
  @note:
    - Lines are delimited using standard newline conventions:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single line break.
    - Consecutive line breaks produce empty lines, each of which is counted.
    - For an empty string, the result is 1, representing a single
      empty line.
    - The function performs a single forward scan using PChar pointers,
      minimizing bounds checks and offering optimal performance for large
      strings.
[==============================================================================}
function TStringHelper.LineQuantity: Integer; overload; cdecl;
var
  P, E: PChar;
begin
  Result := 1;
  P := PChar(Self);
  E := (P + Length(Self));
  while (P < E) do
  begin
    case P^ of
      #13:
      begin
        Inc(Result);
        Inc(P);
        if ((P < E) and (P^ = #10)) then
          Inc(P);
        Continue;
      end;
      #10: Inc(Result);
    end;
    Inc(P);
  end;
end;

{==============================================================================]
  <LinesCount>
  @action: Counts the number of lines in a string.
           Each line is delimited by Windows (#13#10), Mac (#13), or Unix (#10) line breaks.
           Lines that end with a line break are counted, including a trailing empty line.
  @note: If the string is empty, it is considered to contain 1 line.
         This function handles mixed line endings and ensures that
         the last line is counted even if it does not end with a line break.
[==============================================================================}
function TStringHelper.LinesCount: Integer; overload; cdecl;
var
  i, l: Integer;
begin
  Result := 1;
  l := Length(Self);
  if (l = 0) then
    Exit;
  i := 0;
  while (i.Increment <= l) do
  case (Self[i] = #13) of
    True:
    begin
      Inc(Result);
      if ((i < l) and (Self[i + 1] = #10)) then
        Inc(i);
    end;
    False:
    if (Self[i] = #10) then
      Inc(Result);
  end;
end;

{==============================================================================]
  <LinesCounted>
  @action: Returns the total number of logical lines in the string.
  @note:
    - Line numbering is 1-based.
    - An empty string is considered to contain a single (empty) line.
    - Line breaks are detected using all common newline conventions:
        * CRLF (#13#10)
        * LF   (#10)
        * CR   (#13)
    - CRLF sequences are treated as a single logical line break.
    - A trailing line break increases the line count by one.
    - This implementation computes the result using character counting:
        Result = 1 + (CR count + LF count) − CRLF count
    - The function performs multiple passes over the string and is therefore
      less efficient than single-pass implementations for large strings.
    - No temporary strings are created, but the string is scanned three times.
[==============================================================================}
function TStringHelper.LinesCounted: Integer; overload; cdecl;
begin
  if (Length(Self) = 0) then
    Exit(1);
  Result := ((1 + (Self.Count(#10) + Self.Count(#13))) - Self.Count(#13#10));
end;

{==============================================================================]
  <LinesTotal>
  @action: Returns the total number of logical lines contained in the string.
  @note:
    - Lines are delimited using standard newline conventions:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single line break.
    - Consecutive line breaks produce empty lines, each of which is counted.
    - For an empty string, the result is 1, representing a single
      empty line.
    - The function performs a single forward scan of the string using indexed
      access.
[==============================================================================}
function TStringHelper.LinesTotal: Integer; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  Result := 1;
  i := 0;
  while (i.Increment <= l) do
  case (Self[i] = #13) of
    True:
    begin
      Inc(Result);
      if ((i < l) and (Self[i + 1] = #10)) then
        Inc(i);
    end;
    False:
    if (Self[i] = #10) then
      Inc(Result);
  end;
end;
{$ENDIF}