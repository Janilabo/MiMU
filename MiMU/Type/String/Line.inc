{$IFDEF HELPERS}
function LineAmount: Integer; overload;
function LinesTotal: Integer; overload;
function LineQuantity: Integer; overload;
function LinePopulation: Integer; overload;
function LinesCount: Integer; overload;
function LineCount: Integer; overload;
function LinesCounted: Integer; overload;
function LineCountUpTo(const targetLine: Integer): Integer; overload;
function Lines: TStringArray; overload;
function LinesStr(const lineRange: TRange): string; overload;
function Lined: TStringArray; overload;
function LineArray: TStringArray; overload;
function LineArr: TStringArray; overload;
function LinesArray: TStringArray; overload;
function LinesArr: TStringArray; overload;
function LineList: TStringArray; overload;
function LinesList: TStringArray; overload;
function Line(const number: Integer): string; overload;
function LineStr(const lineNumber: Integer): string; overload;
function LineBreaks: TStringArray; overload;
function LineBreakArr: TStringArray; overload;
function LineAtPos(const position: Integer): Integer; overload;
function LineAtPosition(const position: Integer): Integer; overload;
function LineWithPosition(const position: Integer): Integer; overload;
function LineFromPosition(const position: Integer): Integer; overload;
function LineByPos(const position: Integer): Integer; overload;
function LineByPosition(const position: Integer): Integer; overload;
function LineByPosition2(const position: Integer): Integer; overload;
function LineByStringList(const position: Integer): Integer; overload;
function LineToPos(const line: Integer): Integer; overload;
function LineToPosition(const line: Integer): Integer; overload;
function LineNumberMap: TIntegerArray; overload;
function LineIndexes: TIntegerArray; overload;
function LineRanges: TRangeArray; overload;
function LineEndingRanges: TRangeArray; overload;
function LinePositions: TIntegerArray; overload;
function LineEndingPositions: TIntegerArray; overload;
function LineStartPosition(const lineNumber: Integer): Integer; overload;
function LineEndPosition(const lineNumber: Integer): Integer; overload;
function LineRange(const lineNumber: Integer): TRange; overload;
function LineInsert(const lineNumber: Integer; const text: string): string; overload;
function LineReplace(const lineNumber: Integer; const text: string): string; overload;
function LineDelete(const lineNumber: Integer): string; overload;
function LineIsEmpty(const lineNumber: Integer): Boolean; overload;
function LinesNormalized(const newLine: string = sLineBreak): string; overload;
function LineClamp(const lineNumber: Integer): Integer; overload;
function LineFixed(const lineNumber: Integer): Integer; overload;
function LineValid(const lineNumber: Integer): Boolean; overload;
function LineExists(const lineNumber: Integer): Boolean; overload;
function LineExisting(const lineNumber: Integer): Boolean; overload;
function LineExtant(const lineNumber: Integer): Boolean; overload;
function LineEx(const number: Integer; const lineBreak: string): string; overload;
function LineEx(const number: Integer; const lineBreak: TStringArray): string; overload;
function LineEx(const number: Integer): string; overload;
function LinesEx(const lineBreak: string): TStringArray; overload;
function LinesEx(const lineBreak: TStringArray): TStringArray; overload;
function LinesEx: TStringArray; overload;
function LineCountEx(const lineBreak: string): Integer; overload;
function LineCountEx(const lineBreak: TStringArray): Integer; overload;
function LineCountEx: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Lines>
  @action: Splits the string into an array of lines. Handles all standard line endings:
           CRLF (#13#10), CR (#13), and LF (#10). Each element of the resulting array
           corresponds to a single line of text, without including the line-ending characters.
  @note:
    - The function performs a single scan to count lines, preallocates the result
      array, and then fills it with each line, ensuring high efficiency.
    - CRLF sequences are treated as a single line break; CR followed by LF will
      not double-count.
    - For empty strings, the result is an array with a single empty string.
    - The line-ending characters are **not included** in the returned lines.
    - This implementation uses pointer arithmetic for efficiency in Free Pascal.
[==============================================================================}
function TStringHelper.Lines: TStringArray; overload;
var
  P, S, E: PChar;
  R: Integer;
begin
  R := 1;
  P := PChar(Self);
  E := (P + Length(Self));
  while (P < E) do
  case P^ of
    #13:
    begin
      Inc(R);
      Inc(P);
      if ((P < E) and (P^ = #10)) then
        Inc(P);
    end;
    #10:
    begin
      Inc(R);
      Inc(P);
    end;
  else
    Inc(P);
  end;
  SetLength(Result, R);
  R := 0;
  S := PChar(Self);
  P := S;
  while (P < E) do
  case P^ of
    #13, #10:
    begin
      Result[R.Increase] := Copy(Self, ((S - PChar(Self)) + 1), (P - S));
      if ((P^ = #13) and ((P + 1) < E) and ((P + 1)^ = #10)) then
        Inc(P);
      Inc(P);
      S := P;
    end;
  else
    Inc(P);
  end;
  if (S <= E) then
    Result[R] := Copy(Self, ((S - PChar(Self)) + 1), (E - S));
end;

{==============================================================================]
  <LinesStr>
  @action: Extracts and returns the substring spanning a contiguous range of lines,
           identified by a line-number range.
  @note:
    - The line range is 1-based and inclusive (lineRange.start to lineRange.stop).
    - Uses LineStartPosition to locate the first character of the starting line.
    - Uses LineEndPosition to locate the final character of the ending line.
    - If the starting line does not exist, an empty string is returned.
    - If the computed end position precedes the start position, an empty string
      is returned.
    - Line-ending characters outside the specified range are not included.
    - The original text within the specified line range is preserved verbatim.
[==============================================================================}
function TStringHelper.LinesStr(const lineRange: TRange): string; overload;
var
  S, E: Integer;
begin
  S := Self.LineStartPosition(lineRange.start);
  if (S = 0) then
    Exit('');
  E := Self.LineEndPosition(lineRange.stop);
  if E < S then
    Exit('');
  Result := Copy(Self, S, ((E - S) + 1));
end;

{==============================================================================]
  <LineArray>
  @action: Splits the string into an array of lines using a single-pass pointer-based
           scan. Handles all standard line endings (CRLF, CR, LF) correctly. Each
           array element corresponds to a line of text **without including the line-ending
           characters**.
  @note:
    - This function uses a two-phase approach: first it counts the number of lines
      to preallocate the result array, then fills the array using pointer arithmetic
      and SetString for efficiency.
    - CRLF sequences (#13#10) are treated as a single line break; lone CR (#13)
      or LF (#10) are also handled.
    - Empty strings return an array containing a single empty string.
    - This is similar in behavior to Lines, but uses SetString instead of
      Copy for slightly better performance with large strings.
    - Each line is **non-overlapping**; line endings are not included in the resulting
      strings.
[==============================================================================}
function TStringHelper.LineArray: TStringArray; overload;
var
  P, S, E: PChar;
  R: Integer;
begin
  R := 1;
  P := PChar(Self);
  E := (P + Length(Self));
  while (P < E) do
  case P^ of
    #13:
    begin
      Inc(R);
      Inc(P);
      if ((P < E) and (P^ = #10)) then
        Inc(P);
    end;
    #10:
    begin
      Inc(R);
      Inc(P);
    end;
  else
    Inc(P);
  end;
  SetLength(Result, R);
  R := 0;
  S := PChar(Self);
  P := S;
  while (P < E) do
  case P^ of
    #13, #10:
    begin
      SetString(Result[R.Increase], S, (P - S));
      if ((P^ = #13) and (P + 1 < E) and ((P + 1)^ = #10)) then
        Inc(P);
      Inc(P);
      S := P;
    end;
  else
    Inc(P);
  end;
  if (S <= E) then
    SetString(Result[R], S, (E - S));
end;

{==============================================================================]
  <LineArr>
  @action:
    Splits the string into an array of lines. Each line is extracted as a string
    without including the line-ending characters. Handles all standard line
    endings: CRLF (#13#10), CR (#13), and LF (#10).
  @note:
    - The function uses a single-pass pointer scan and dynamically grows the
      result array as lines are found.
    - CRLF sequences are treated as a single line break; lone CR or LF are also
      correctly handled.
    - For an empty string, the function returns an empty array.
    - The line-ending characters are not included in the returned lines.
    - This approach avoids pre-counting lines but may incur slight overhead
      from repeated array resizing when the number of lines is large.
[==============================================================================}
function TStringHelper.LineArr: TStringArray; overload;
var
  P, S, E: PChar;
begin
  SetLength(Result, 0);
  P := PChar(Self);
  E := (P + Length(Self));
  S := P;
  while (P < E) do
  case P^ of
    #13, #10:
    begin
      SetLength(Result, (Length(Result) + 1));
      SetString(Result[High(Result)], S, (P - S));
      if ((P^ = #13) and ((P + 1) < E) and ((P + 1)^ = #10)) then
        Inc(P);
      Inc(P);
      S := P;
    end;
  else
    Inc(P);
  end;
  if (S <= E) then
  begin
    SetLength(Result, (Length(Result) + 1));
    SetString(Result[High(Result)], S, (E - S));
  end;
end;

{==============================================================================]
  <LinesArray>
  @action: Splits the string into an array of lines, returning each line as a separate
           string element. Supports CR (#13), LF (#10), and CRLF (#13#10) line endings.
  @note:
    - Line-ending characters are **not included** in the resulting array elements.
    - Consecutive line breaks produce empty string elements in the array.
    - If the string ends with a line-ending character, a final empty string is
      included to represent the empty line.
    - The function dynamically appends lines to the result array during iteration.
    - Works correctly for empty strings (returns an empty array).
[==============================================================================}
function TStringHelper.LinesArray: TStringArray;
var
  S, P, L: Integer;
begin
  S := 1;
  L := Length(Self);
  while (S <= L) do
  begin
    P := S;
    while ((P <= L) and (not (Self[P] in [#10, #13]))) do
      Inc(P);
    Result := (Result + [Copy(Self, S, (P - S))]);
    if ((P <= L) and (Self[P] = #13) and (P < L) and (Self[P + 1] = #10)) then
      Inc(P);
    S := (P + 1);
  end;
  if ((L > 0) and (Self[L] in [#10, #13])) then
    Result := (Result + ['']);
end;

{==============================================================================]
  <LinesArr>
  @action: Splits the string into an array of lines, returning each line as a separate
           string element. Line-ending characters (CR, LF, or CRLF) are **not included**
           in the resulting array.
  @note:
    - Handles all standard line endings: CR (#13), LF (#10), and CRLF (#13#10).
    - Consecutive line breaks produce empty string elements in the array.
    - For an empty string, the result is an empty array.
    - The implementation preallocates the array for efficiency and fills it
      while scanning the string once.
    - Uses pointer arithmetic and indexing internally; the resulting array size
      is trimmed to the actual number of lines.
[==============================================================================}
function TStringHelper.LinesArr: TStringArray; overload;
var
  L, I, S, R: Integer;
begin
  L := Length(Self);
  S := 1;
  R := 0;
  SetLength(Result, (L + 1));
  I := 1;
  while (I <= L) do
  begin
    if ((Self[I] = #10) or (Self[I] = #13)) then
    begin
      Result[R.Increase] := Copy(Self, S, (I - S));
      if ((Self[I] = #13) and (I < L) and (Self[I + 1] = #10)) then
        Inc(I);
      S := (I + 1);
    end;
    Inc(I);
  end;
  if (S <= L) then
    Result[R.Increase] := Copy(Self, S, ((L - S) + 1))
  else if ((L > 0) and (Self[L] in [#10, #13])) then
    Result[R.Increase] := '';
  SetLength(Result, R);
end;

{==============================================================================]
  <LineList>
  @action: Converts a multi-line string into an array of strings.
           Each line in the string becomes an element in the resulting array.
  @note: Supports Windows (#13#10), Mac (#13), and Unix (#10) line breaks.
         Uses TStringList internally, which normalizes line endings to #13#10.
  @warning: If the string ends with a line break, the trailing empty line
            will be ignored. That is, an "empty last line" will not appear
            in the resulting array when using this TStringList-based version.
[==============================================================================}
function TStringHelper.LineList: TStringArray; overload;
var
  s: TStringList;
  i: Integer;
begin
  s := TStringList.Create;
  try
    s.Text := Self;
    SetLength(Result, s.Count);
    for i := 0 to (s.Count - 1) do
      Result[i] := s[i];
  finally
    s.Free;
  end;
end;

{==============================================================================]
  <LinesList>
  @action: Converts a multi-line string into an array of strings.
           Each line in the string becomes an element in the resulting array.
  @note: Supports Windows (#13#10), Mac (#13), and Unix (#10) line breaks.
         Uses TStringList internally, which normalizes line endings to #13#10.
  @warning: By default, TStringList.Text ignores a trailing empty line.
            This version adds an empty string at the end if the original
            string ends with a line break.
[==============================================================================}
function TStringHelper.LinesList: TStringArray; overload;
var
  s: TStringList;
  i, l: Integer;
begin
  s := TStringList.Create;
  try
    s.Text := Self;
    l := s.Count;
    if ((Length(Self) > 0) and ((Self[Length(Self)] = #13) or (Self[Length(Self)] = #10))) then
      Inc(l);
    SetLength(Result, l);
    for i := 0 to (s.Count - 1) do
      Result[i] := s[i];
    if (l > s.Count) then
      Result[l - 1] := '';
  finally
    s.Free;
  end;
end;

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
function TStringHelper.LineAmount: Integer; overload;
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
function TStringHelper.LinesTotal: Integer; overload;
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
function TStringHelper.LineQuantity: Integer; overload;
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
function TStringHelper.LinePopulation: Integer; overload;
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
  <LinesCount>
  @action: Counts the number of lines in a string.
           Each line is delimited by Windows (#13#10), Mac (#13), or Unix (#10) line breaks.
           Lines that end with a line break are counted, including a trailing empty line.
  @note: If the string is empty, it is considered to contain 1 line.
         This function handles mixed line endings and ensures that
         the last line is counted even if it does not end with a line break.
[==============================================================================}
function TStringHelper.LinesCount: Integer; overload;
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
function TStringHelper.LineCount: Integer; overload;
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
function TStringHelper.LinesCounted: Integer; overload;
begin
  if (Length(Self) = 0) then
    Exit(1);
  Result := ((1 + (Self.Count(#10) + Self.Count(#13))) - Self.Count(#13#10));
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
function TStringHelper.LineCountUpTo(const targetLine: Integer): Integer; overload;
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
  <LineExtant>
  @action: Determines whether the specified line number exists in the string.
  @note:
    - Line numbering is 1-based.
    - Returns True if the string contains at least lineNumber lines.
    - Returns False if lineNumber is less than 1 or exceeds the total number
      of lines in the string.
    - Uses LineCountUpTo internally to allow early termination and avoid a
      full line scan when possible.
    - Line breaks are recognized as LF (#10), CR (#13), and CRLF (#13#10),
      with CRLF treated as a single line break.
[==============================================================================}
function TStringHelper.LineExtant(const lineNumber: Integer): Boolean; overload;
begin
  Result := ((lineNumber > 0) and (Self.LineCountUpTo(lineNumber) >= lineNumber));
end;

{==============================================================================]
  <Lined>
  @action: Returns a TStringArray containing the text of each line in the string.
           Each array element corresponds to one line, excluding the line-ending characters.
  @note:
    - Lines are separated using standard newline characters:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single line break.
    - Empty lines are returned as empty strings.
    - Consecutive line breaks produce multiple empty lines in the array.
    - If the string is empty, the result is a single empty line.
    - The function performs a single forward scan of the string and allocates
      the result array once using LineAmount.
[==============================================================================}
function TStringHelper.Lined: TStringArray; overload;
var
  r, i, l, s: Integer;
begin
  SetLength(Result, Self.LineAmount);
  l := Length(Self);
  s := 1;
  r := 0;
  i := 0;
  while (i.Increment <= l) do
  case Self[i] of
    #13, #10:
    begin
      Result[r.Increase] := Copy(Self, s, (i - s));
      if ((Self[i] = #13) and (i < l) and (Self[i + 1] = #10)) then
        Inc(i);
      s := (i + 1);
    end;
  end;
  Result[r] := Copy(Self, s, ((l - s) + 1));
end;

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

{==============================================================================]
  <LineBreaks>
  @action: Returns the line break sequence associated with each logical line in the string.
  @note:
    - The result array contains one element per line.
    - Array index 0 corresponds to line 1, index 1 to line 2, and so on.
    - Each element contains the exact line break sequence that terminates
      that line:
        * #13#10 (CRLF)
        * #13     (CR)
        * #10     (LF)
    - If a line is not terminated by a line break (typically the last line),
      the corresponding array element is an empty string.
    - An empty string is treated as containing a single empty line and
      returns an array with one empty element.
    - Line breaks are detected using all common newline conventions.
    - The function performs a single forward scan and does not allocate
      temporary substrings.
[==============================================================================}
function TStringHelper.LineBreaks: TStringArray; overload;
var
  C, E: PChar;
  L, S: Integer;
begin
  S := Length(Self);
  if (S = 0) then
    Exit(['']);
  SetLength(Result, Self.LineCount);
  L := 0;
  C := PChar(Self);
  E := (C + (S - 1));
  while (C <= E) do
  begin
    case C^ of
      #13:
      if ((C < E) and (C[1] = #10)) then
      begin
        Result[L.Increase] := #13#10;
        Inc(C);
      end else
        Result[L.Increase] := #13;
      #10: Result[L.Increase] := #10;
    end;
    Inc(C);
  end;
  if (L < Length(Result)) then
    Result[L] := '';
end;

{==============================================================================]
  <LineBreakArr>
  @action: Returns the line break sequence associated with each logical line
           in the string.
  @note:
    - The result array contains one element per line.
    - Array index 0 corresponds to line 1, index 1 to line 2, and so on.
    - Each element contains the exact line break sequence that terminates
      the corresponding line:
        * #13#10 (CRLF)
        * #13     (CR)
        * #10     (LF)
    - If a line is not terminated by a line break (typically the last line),
      the corresponding array element is an empty string.
    - An empty string is treated as containing a single empty line and
      returns an array with one empty element.
    - Line breaks are detected using all common newline conventions.
    - The function performs a single forward scan and does not depend on
      LineCount or any other helper.
[==============================================================================}
function TStringHelper.LineBreakArr: TStringArray; overload;
var
  C, E: PChar;
  L, S: Integer;
begin
  S := Length(Self);
  if (S = 0) then
    Exit(['']);
  SetLength(Result, (S + 1));
  L := 0;
  C := PChar(Self);
  E := (C + (S - 1));
  while (C <= E) do
  begin
    case C^ of
      #13:
      if ((C < E) and (C[1] = #10)) then
      begin
        Result[L.Increase] := #13#10;
        Inc(C);
      end else
        Result[L.Increase] := #13;
      #10: Result[L.Increase] := #10;
    end;
    Inc(C);
  end;
  Result[L] := '';
  SetLength(Result, (L + 1));
end;  

{==============================================================================]
  <LineWithPosition>
  @action: Returns the 1-based line number that contains the character at the
           specified 1-based position within the string.
  @note:
    - Line numbering is 1-based.
    - The position parameter is interpreted as a 1-based character index.
    - If position <= 0, the function returns 0 to indicate an invalid position.
    - If the string is empty, the function returns 1 (the first line).
    - Line breaks are recognized using the LineIndexes array, which contains
      the start positions of each line.
    - The function performs a binary search over the line start positions,
      making it efficient even for large strings.
    - Leading, trailing, or consecutive line breaks are handled correctly:
        * A character that is part of a line break is considered to belong
          to the line it terminates.
        * The first line is correctly identified even if the string starts
          with CR, LF, or CRLF.
[==============================================================================}
function TStringHelper.LineWithPosition(const position: Integer): Integer; overload;
var
  M: Integer;
  I: TIntegerArray;
  R: TRange;
begin
  if (position <= 0) then
    Exit(0);
  Result := 1;
  if (Length(Self) < 1) then
    Exit;
  I := Self.LineIndexes;
  R.Create(0, High(I));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (I[M] <= position) then
    begin
      R.start := (M + 1);
      Result := R.start;
    end else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <LineFromPosition>
  @action: Returns the 1-based line number that contains the character at the
           specified 1-based position within the string.
  @note:
    - Line numbering is 1-based.
    - The position parameter is interpreted as a 1-based character index.
    - If position <= 0, the function returns 0 to indicate an invalid position.
    - If the string is empty, the function returns 1 (the single empty line).
    - If position exceeds the string length, it is clamped to Length(Self).
    - Line breaks are recognized using all common newline conventions:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single logical line break.
    - A line break belongs to the line it terminates; the next line begins
      at the character immediately following the full line break sequence.
    - The function performs a single forward scan up to (but not including)
      the target position, ensuring correct results even when the string
      starts with one or more line breaks.
    - No temporary strings or auxiliary arrays are allocated.
[==============================================================================}
function TStringHelper.LineFromPosition(const position: Integer): Integer; overload;
var
  S, E: PChar;
  P, L: Integer;
begin
  if (position <= 0) then
    Exit(0);
  L := Length(Self);
  if (L = 0) then
    Exit(1);
  P := IfThen((position > L), L, position);
  Result := 1;
  S := PChar(Self);
  E := ((S + P) - 1);
  while (S < E) do
  begin
    case S^ of
      #13:
      case (((S + 1) <= E) and (S[1] = #10)) of
	    True:
        begin
          if ((S + 1) < E) then
            Inc(Result);
          Inc(S);
        end;
        False: Inc(Result);
      end;
      #10: Inc(Result);
    end;
    Inc(S);
  end;
end;

{==============================================================================]
  <LineByPos>
  @action: Returns the 1-based line number corresponding to a given 1-based character
           position within the string.
  @note:
    - Line numbering is 1-based.
    - The position parameter is interpreted as a 1-based character index.
    - If position <= 0, the function returns 0 to indicate an invalid position.
    - If position exceeds the string length, it is clamped to Length(Self).
    - An empty string is treated as containing a single (empty) line and
      therefore returns 1.
    - Line breaks are detected using all common newline conventions:
        * CRLF (#13#10)
        * LF   (#10)
        * CR   (#13)
      CRLF sequences are counted as a single line break.
    - This overload uses multiple substring scans and is less efficient than
      LineByPosition for large strings.
[==============================================================================}
function TStringHelper.LineByPos(const position: Integer): Integer; overload;
var
  l: Integer;
  s: string;
begin
  if (position <= 0) then
    Exit(0);
  l := IfThen((position > Length(Self)), Length(Self), position);
  if (l < 1) then
    Exit(1);
  s := Copy(Self, 1, (l - 2));
  Result := s.Count(#13#10);
  Result := (Result + (s.Count(#10) - Result) + (s.Count(#13) - Result) + 1);
end;

{==============================================================================]
  <LineByPosition>
  @action: Returns the 1-based line number corresponding to a given 1-based character
           position within the string, using a single-pass scan.
  @note:
    - Line numbering is 1-based.
    - The position parameter is interpreted as a 1-based character index.
    - If position <= 0, the function returns 0 to indicate an invalid position.
    - If position exceeds the string length, it is clamped to Length(Self).
    - An empty string is treated as containing a single (empty) line and
      therefore returns 1.
    - Line breaks are detected using all common newline conventions:
        * CRLF (#13#10)
        * LF   (#10)
        * CR   (#13)
      CRLF sequences are counted as a single line break.
    - This overload performs a single linear pass up to the requested position
      and is optimized for performance and low memory overhead.
[==============================================================================}
function TStringHelper.LineByPosition(const position: Integer): Integer; overload;
var
  i, l: Integer;
begin
  if (position <= 0) then
    Exit(0);
  Result := 1;
  l := IfThen((position> Length(Self)), Length(Self), position);
  if (l = 0) then
    Exit;
  i := 0;
  while (i.Increment < l) do
  case Self[i] of
    #13:
    if not ((i < l) and (Self[i + 1] = #10)) then
      Inc(Result);
    #10: Inc(Result);
  end;
end;

{==============================================================================]
  <LineByPosition2>
  @action: Returns the 1-based line number corresponding to a given 1-based character
           position within the string, using a single-pass scan.
  @note:
    - Line numbering is 1-based.
    - The position parameter is interpreted as a 1-based character index.
    - If position <= 0, the function returns 0 to indicate an invalid position.
    - If position exceeds the string length, it is clamped to Length(Self).
    - An empty string is treated as containing a single (empty) line and
      therefore returns 1.
    - Line breaks are detected using all common newline conventions:
        * CRLF (#13#10)
        * LF   (#10)
        * CR   (#13)
      CRLF sequences are counted as a single line break.
    - This overload performs a single linear pass up to the requested position
      and is optimized for performance and low memory overhead.
[==============================================================================}
function TStringHelper.LineByPosition2(const position: Integer): Integer; overload;
var
  i, s, p: Integer;
begin
  if (position <= 0) then
    Exit(0);
  s := Length(Self);
  if (s = 0) then
    Exit(1);
  p := IfThen((position > s), s, position);
  Result := 1;
  i := 0;
  while (i.Increment < p) do
  case Self[i] of
    #13:
    if not ((i < s) and (Self[i + 1] = #10)) then
      Inc(Result);
    #10: Inc(Result);
  end;
end;

{==============================================================================]
  <LineAtPos>
  @action: Returns the 1-based line number that contains the character at the
           specified 1-based position within the string.
  @note:
    - Line numbering is 1-based.
    - The position parameter is interpreted as a 1-based character index.
    - If Position < 1, the function returns 0 to indicate an invalid position.
    - If the string is empty, the function returns 1 (the single empty line).
    - If Position exceeds the string length, it is clamped to Length(Self).
    - Line breaks are recognized using all common newline conventions:
        * CRLF (#13#10)
        * LF   (#10)
        * CR   (#13)
      CRLF sequences are counted as a single line break.
    - A line break is considered to belong to the line it terminates.
    - The function performs a single forward scan from the start of the string
      up to the specified position.
[==============================================================================}
function TStringHelper.LineAtPos(const position: Integer): Integer; overload;
var
  i, p: Integer;
begin
  if (position < 1) then
    Exit(0);
  Result := 1;
  p := IfThen((position > Length(Self)), Length(Self), position);
  for i := 2 to p do
    if ((Self[i - 1] = #10) or ((Self[i - 1] = #13) and (Self[i] <> #10))) then
      Inc(Result);
end;

{==============================================================================]
  <LineAtPosition>
  @action: Returns the 1-based line number that contains the character at the
           specified 1-based position within the string.
  @note:
    - Line numbering is 1-based.
    - The position parameter is interpreted as a 1-based character index.
    - If Position < 1, the function returns 0 to indicate an invalid position.
    - If the string is empty, the function returns 1 (the single empty line).
    - If Position exceeds the string length, it is clamped to Length(Self).
    - Line breaks are recognized using all common newline conventions:
        * CRLF (#13#10)
        * LF   (#10)
        * CR   (#13)
      CRLF sequences are treated as a single logical line break.
    - A line break is considered to belong to the line it terminates; the
      character immediately following a line break begins the next line.
    - The function performs a single forward scan from the start of the string
      up to the specified position and allocates no temporary memory.
[==============================================================================}
function TStringHelper.LineAtPosition(const position: Integer): Integer; overload;
var
  S, C, E: PChar;
  P, L: Integer;
begin
  if (position < 1) then
    Exit(0);
  Result := 1;
  L := Length(Self);
  if (L = 0) then
    Exit;
  P := IfThen((position > L), L, position);
  S := PChar(Self);
  C := (S + 1);
  E := (S + (P - 1));
  while (C <= E) do
  begin
    if ((C[-1] = #10) or ((C[-1] = #13) and (C^ <> #10))) then
      Inc(Result);
    Inc(C);
  end;
end;

{==============================================================================]
  <LineByStringList>
  @action: Converts a 1-based character position within the string into a 1-based
           line number. The string is interpreted as a list of lines using
           TStringList.Text, and line boundaries are determined by sLineBreak.
  @note:
    - If position <= 0, the function returns 0.
    - Line numbers are 1-based.
    - If position exceeds the total length of the string (including line
      breaks), the function returns the total number of lines.
    - Line length calculations include the length of sLineBreak for each line.
    - The method allocates a temporary TStringList on each call, which may be
      inefficient for high-frequency usage or large strings.
[==============================================================================}
function TStringHelper.LineByStringList(const position: Integer): Integer; overload;
var
  s: TStringList;
  i, r: Integer;
begin
  if (position <= 0) then
    Exit(0);
  s := TStringList.Create;
  try
    s.Text := Self;
    r := 0;
    for i := 0 to (s.Count - 1) do
    begin
      Inc(r, (Length(s[i]) + Length(sLineBreak)));
      if (position <= r) then
        Exit(i + 1);
    end;
    Result := s.Count;
  finally
    s.Free;
  end;
end;

{==============================================================================]
  <LineToPos>
  @action: Returns the 1-based character position corresponding to the start of a
           given 1-based line number within the string.
  @note:
    - Line numbering is 1-based.
    - The returned position is the index of the first character of the
      specified line.
    - If line < 1, the function returns 0 to indicate an invalid line number.
    - Line 1 always maps to position 1, even for an empty string.
    - If the requested line number does not exist within the string,
      the function returns 0.
    - Line breaks are detected using all common newline conventions:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single line break.
    - The function scans forward through the string, locating successive
      line break sequences until the requested line is reached.
    - The returned position points to the first character *after* the line
      break sequence that terminates the previous line.
[==============================================================================}
function TStringHelper.LineToPos(const line: Integer): Integer; overload;
var
  s: TStringArray;
  i, l, p, m, t, o: Integer;
begin
  if (line < 1) then
    Exit(0);
  Result := 1;
  t := (Length(Self) + 1);
  if ((t > 1) and (line > 1)) then
  begin
    l := 1;
    s := [#13#10, #13, #10];
    repeat
      m := t;
      for i := 0 to High(s) do
      begin
        p := Self.Position(s[i], Result);
        if ((p > 0) and (p < m)) then
        begin
          m := p;
          o := Length(s[i]);
        end;
      end;
      if (m < t) then
      begin
        Result := (m + o);
        Inc(l);
      end;
    until ((m = t) or (l >= line));
    if (l < line) then
      Result := 0;
  end;
end;

{==============================================================================]
  <LineToPosition>
  @action: Returns the 1-based character position corresponding to the start of a
           specified 1-based line number within the string.
  @note:
    - Line numbering is 1-based.
    - The returned value is the index of the first character of the requested
      line.
    - If line = 1, the function always returns 1.
    - If line < 1, the function returns 0 to indicate an invalid line number.
    - If the string is empty and line > 1, the function returns 0.
    - If the requested line does not exist within the string, the function
      returns 0.
    - Line breaks are recognized using all common newline conventions:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single logical line break.
    - The function performs a single forward pass through the string and
      does not allocate temporary strings.
    - The returned position always refers to the first character *after*
      the line break sequence terminating the previous line.
[==============================================================================}
function TStringHelper.LineToPosition(const line: Integer): Integer; overload;
var
  i, l, s, n: Integer;
begin
  if (line = 1) then
    Exit(1);
  s := Length(Self);
  if ((line < 1) or (s = 0)) then
    Exit(0);
  l := 1;
  i := 1;
  while (i.Increment <= s) do
  case Self[i] of
    #13:
    begin
      if ((i < s) and (Self[i + 1] = #10)) then
        n := (i.Increment + 1)
      else
        n := (i + 1);
      if (l.Increment = line) then
        Exit(n);
    end;
    #10:
    if (l.Increment = line) then
      Exit(i + 1);
  end;
  Result := 0;
end;

{==============================================================================]
  <LineNumberMap>
  @action: Returns a lookup table that maps each 1-based character position in the
           string to its corresponding 1-based line number.
  @note:
    - The returned array is indexed by character position (1-based).
    - Element [i] contains the line number of character i in the string.
    - The array length is Length(Self) + 1; index 0 is unused.
    - An empty string yields an array of length 1 with no valid character entries.
    - Line numbering starts at 1.
    - Line breaks are detected using all common newline conventions:
        * CRLF (#13#10) treated as a single line break
        * LF   (#10)
        * CR   (#13)
    - A line break character belongs to the line it terminates.
    - The resulting map is suitable for O(1) position-to-line lookups.
[==============================================================================}
function TStringHelper.LineNumberMap: TIntegerArray; overload;
var
  i, l, s: Integer;
begin
  s := Length(Self);
  SetLength(Result, (s + 1));
  l := 1;
  for i := 1 to s do
  begin
    Result[i] := l;
    case Self[i] of
      #10: Inc(l);
      #13:
      if not ((i < s) and (Self[i + 1] = #10)) then
        Inc(l);
    end;
  end;
end;

{==============================================================================]
  <LineIndexes>
  @action: Returns an array of 1-based character positions indicating the
           starting position of each logical line in the string.
  @note:
    - The returned array contains one entry per line.
    - Each element is a 1-based index into the string representing the first
      character of a line.
    - Line 1 always starts at position 1.
    - An empty string is treated as containing a single empty line and returns
      an array containing only [1].
    - Line breaks are detected using all common newline conventions:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single logical line break.
    - Empty lines are included and produce distinct entries in the array.
    - The returned array may be safely used with Line, LineByPosition, and
      LineToPosition helpers.
[==============================================================================}
function TStringHelper.LineIndexes: TIntegerArray; overload;
var
  i, l, r: Integer;
begin
  l := Length(Self);
  if (l = 0) then
    Exit([1]);
  r := 1;
  SetLength(Result, l);
  Result[0] := 1;
  i := 0;
  while (i.Increment <= l) do
  case Self[i] of
    #13:
    begin
      if ((i < l) and (Self[i + 1] = #10)) then
        Inc(i);
      Result[r.Increase] := (i + 1);
    end;
    #10: Result[r.Increase] := (i + 1);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <LineRanges>
  @action: Returns a TRangeArray representing the **content ranges of all lines**
           within the string. Each element corresponds to a single line’s content,
           excluding the line-ending characters.
  @note:
    - Line numbering is 1-based; ranges are expressed as 1-based positions within the string.
    - Empty lines produce **descending ranges**, where `start > stop`, to indicate zero-length content.
    - Line breaks are recognized using all common newline conventions:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single logical line break.
    - The function performs a single forward pass through the string.
    - The final line (even if empty) is always included.
    - Consumers should handle descending ranges appropriately when extracting
      content (e.g., Copy(Self, start, stop - start + 1) may return an empty string).
[==============================================================================}
function TStringHelper.LineRanges: TRangeArray; overload;
var
  i, l, s: Integer;
begin
  l := Length(Self);
  s := 1;
  SetLength(Result, 0);
  i := 0;
  while (i.Increment <= l) do
  case Self[i] of
    #13:
    begin
      Result.Supply(TRange.Construct(s, (i - 1)));
      if ((i < l) and (Self[i + 1] = #10)) then
        Inc(i);
      s := (i + 1);
    end;
    #10:
    begin
      Result.Supply(TRange.Construct(s, (i - 1)));
      s := (i + 1);
    end;
  end;
  Result.Supply(TRange.Construct(s, l));
end;

{==============================================================================]
  <LineEndingRanges>
  @action: Returns a TRangeArray representing the **line-ending ranges** within the
           string. Each element corresponds to a single line-ending sequence.
  @note:
    - Line breaks are recognized using:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single range.
    - Consecutive line breaks are represented as separate ranges.
    - The function performs a single forward pass through the string.
    - Returned ranges indicate the positions of the line-ending characters;
      line content is not included.
[==============================================================================}
function TStringHelper.LineEndingRanges: TRangeArray; overload;
var
  i, l, s: Integer;
begin
  l := Length(Self);
  SetLength(Result, 0);
  i := 0;
  while (i.Increment <= l) do
  case Self[i] of
    #13:
    begin
      s := i;
      if ((i < l) and (Self[i + 1] = #10)) then
        Inc(i);
      Result.Supply(TRange.Construct(s, i));
    end;
    #10: Result.Supply(TRange.Construct(i, i));
  end;
end;

{==============================================================================]
  <LinePositions>
  @action: Returns a TIntegerArray containing the 1-based starting positions of each
           line in the string. Each entry corresponds to the first character of a line's content.
  @note:
    - For an empty string, the result is [1], representing a single empty line.
    - Line breaks are recognized using all common newline conventions:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single line break.
    - Consecutive line breaks produce multiple entries in the array.
    - The function performs a single forward pass and dynamically grows the
      result array via arr.Supply.
[==============================================================================}
function TStringHelper.LinePositions: TIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  Result := [1];
  if (l = 0) then
    Exit;
  i := 0;
  while (i.Increment <= l) do
  case Self[i] of
    #13:
    begin
      if ((i < l) and (Self[i + 1] = #10)) then
        Inc(i);
      Result.Supply(i + 1);
    end;
    #10: Result.Supply(i + 1);
  end;
end;

{==============================================================================]
  <LineEndingPositions>
  @action: Returns a TIntegerArray containing the 1-based starting positions of each
           line-ending sequence in the string. Each entry corresponds to the first
           character of a CR, LF, or CRLF sequence.
  @note:
    - For an empty string, the result is an empty array [].
    - Line breaks are recognized using all common newline conventions:
        * CRLF (#13#10)
        * CR   (#13)
        * LF   (#10)
      CRLF sequences are treated as a single range.
    - Consecutive line breaks produce multiple entries.
    - The function performs a single forward pass and dynamically grows the
      result array via arr.Supply.
[==============================================================================}
function TStringHelper.LineEndingPositions: TIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, 0);
  i := 0;
  while (i.Increment <= l) do
  case Self[i] of
    #13:
    begin
      Result.Supply(i);
      if ((i < l) and (Self[i + 1] = #10)) then
        Inc(i);
    end;
    #10: Result.Supply(i);
  end;
end;

{==============================================================================]
  <LineStartPosition>
  @action:
    Returns the 1-based character index within the string where the specified
    line begins. Line numbering is 1-based and lines are detected using standard
    text line breaks.
  @note:
    - Supports LF (#10), CR (#13), and CRLF (#13#10) line endings.
    - If lineNumber < 1, the function returns 0.
    - If the string is empty, line 1 is considered to start at position 1.
    - If the requested line does not exist, the function returns 0.
    - The returned position is a character offset, not a byte offset.
[==============================================================================}
function TStringHelper.LineStartPosition(const lineNumber: Integer): Integer; overload;
var
  C, E: PChar;
  L: Integer;
begin
  if (lineNumber < 1) then
    Exit(0);
  Result := 1;
  if (Length(Self) = 0) then
    Exit;
  L := 1;
  C := PChar(Self);
  E := ((C + Length(Self)) - 1);
  while (C <= E) do
  begin
    if (L = lineNumber) then
      Exit(Result);
    case C^ of
      #10:
      begin
        Inc(L);
        Inc(Result);
      end;
      #13:
      begin
        Inc(L);
        Inc(Result);
        if ((C < E) and (C[1] = #10)) then
        begin
          Inc(C);
          Inc(Result);
        end;
      end;
    else
      Inc(Result);
    end;
    Inc(C);
  end;
  if (L = lineNumber) then
    Exit(Result);
  Result := 0;
end;

{==============================================================================]
  <LineEndPosition>
  @action:
    Returns the 1-based character index of the final character of the specified
    line, excluding any line break characters.
  @note:
    - Uses LineStartPosition to determine the beginning of the line.
    - If the requested line does not exist, the function returns 0.
    - If the line extends to the end of the string, the string length is returned.
    - Line terminators (#10, #13, or #13#10) are not included in the result.
[==============================================================================}
function TStringHelper.LineEndPosition(const lineNumber: Integer): Integer; overload;
var
  L: Integer;
begin
  Result := Self.LineStartPosition(lineNumber);
  if (Result = 0) then
    Exit;
  L := Length(Self);
  if (Result > L) then
    Exit(L);
  while ((Result <= L) and not (Self[Result] in [#10, #13])) do
    Inc(Result);
  Result := (Result - 1);
end;

{==============================================================================]
  <LineRange>
  @action:
    Returns the inclusive character range (start..stop) corresponding to the
    specified line within the string.
  @note:
    - The range is 1-based and inclusive.
    - If the requested line does not exist, both start and stop are set to 0.
    - Internally relies on LineStartPosition and LineEndPosition for consistency.
[==============================================================================}
function TStringHelper.LineRange(const lineNumber: Integer): TRange; overload;
begin
  Result.start := Self.LineStartPosition(lineNumber);
  if (Result.start > 0) then
    Result.stop := Self.LineEndPosition(lineNumber)
  else
    Result.stop := 0;
end;

{==============================================================================]
  <LineIsEmpty>
  @action: Determines whether the specified line contains only whitespace or is completely empty.
  @note:
    - Line numbering is 1-based.
    - Uses LineStr to extract the line content and Trim to remove leading and
      trailing whitespace before checking emptiness.
    - Returns True if the line is empty or contains only spaces, tabs, or other
      whitespace characters; otherwise, returns False.
    - If the specified line does not exist, the function returns True.
[==============================================================================}
function TStringHelper.LineIsEmpty(const lineNumber: Integer): Boolean; overload;
begin
  Result := (SysUtils.Trim(Self.LineStr(lineNumber)) = '');
end;

{==============================================================================]
  <LinesNormalized>
  @action:
    Normalizes all line endings in the string to a consistent format specified
    by the `newLine` parameter. Converts CR (#13), LF (#10), and CRLF (#13#10)
    sequences into the specified line-ending string.
  @note:
    - By default, `newLine` uses the platform-dependent line break (sLineBreak).
    - The function scans the string once and efficiently constructs a new string
      with normalized line endings.
    - Consecutive or mixed line endings in the original string are correctly
      converted without duplication.
    - The resulting string preserves all original text content, only adjusting
      line terminators.
    - An empty string input returns an empty string.
[==============================================================================}
function TStringHelper.LinesNormalized(const newLine: string = sLineBreak): string; overload;
var
  S, E: PChar;
  L, N, R, i: Integer;
begin
  L := Length(Self);
  if (L = 0) then
    Exit('');
  N := Length(newLine);
  SetLength(Result, (L * N));
  R := 0;
  S := PChar(Self);
  E := (S + L);
  while (S < E) do
  begin
    case S^ of
      #13:
      begin
        Inc(R, N);
        for i := 1 to N do
          Result[(R - N) + i] := newLine[i];
        Inc(S);
        if ((S < E) and (S^ = #10)) then
          Inc(S);
      end;
      #10:
      begin
        Inc(R, N);
        for i := 1 to N do
          Result[(R - N) + i] := newLine[i];
        Inc(S);
      end;
    else
      begin
        Inc(R);
        Result[R] := S^;
        Inc(S);
      end;
    end;
  end;
  SetLength(Result, R);
end;

{==============================================================================]
  <LineClamp>
  @action: Returns a line number clamped to the valid range of the string.
           If the requested line number is invalid (less than 1), returns 0.
           If the requested line number exceeds the total number of lines, returns 0.
           Otherwise, returns the requested line number.
  @note:
    - Line numbers are 1-based.
    - 0 indicates an invalid or non-existent line.
    - Useful for query functions that need to signal invalid lines.
[==============================================================================}
function TStringHelper.LineClamp(const lineNumber: Integer): Integer; overload;
begin
  if (lineNumber < 1) then
    Exit(0);
  Result := Self.LineCount;
  if (lineNumber > Result) then
    Exit;
  Result := lineNumber;
end;

{==============================================================================]
  <LineFixed>
  @action: Returns a line number adjusted to the valid range of the string.
           If the requested line number is less than 1, returns 1 (first line).
           If the requested line number exceeds the total number of lines, returns the last line.
           Otherwise, returns the requested line number.
  @note:
    - Line numbers are 1-based.
    - Never returns 0; always returns a valid line.
    - Useful for editor-like functions where a valid line must always be returned.
[==============================================================================}
function TStringHelper.LineFixed(const lineNumber: Integer): Integer; overload;
begin
  if (lineNumber < 1) then
    Exit(1);
  Result := Self.LineCount;
  if (lineNumber > Result) then
    Exit;
  Result := lineNumber;
end; 

{==============================================================================]
  <LineInsert>
  @action: Inserts the specified text as a new line at the given line number and returns
           the resulting string.
  @note:
    - Line numbering is 1-based.
    - The text is inserted immediately before the specified line.
    - A platform-dependent line break (sLineBreak) is automatically appended
      after the inserted text.
    - If the specified line does not exist, the text is appended to the end of
      the string followed by a line break.
    - Existing content is preserved and shifted as needed.
[==============================================================================}
function TStringHelper.LineInsert(const lineNumber: Integer; const text: string): string; overload;
var
  P: Integer;
begin
  P := Self.LineStartPosition(lineNumber);
  if (P = 0) then
    Exit(Self + text + sLineBreak);
  Result := Copy(Self, 1, (P - 1)) + text + sLineBreak + Copy(Self, P, High(Integer));
end;

{==============================================================================]
  <LineReplace>
  @action: Replaces the contents of a specified logical line with the supplied text.
  @note:
    - Line numbering is 1-based.
    - The line is identified using LineRange, and therefore follows the same
      newline semantics (CR, LF, CRLF).
    - Only the characters belonging to the line are replaced; the original
      line break sequence (if any) following the line is preserved.
    - If the specified line number does not exist, the original string is
      returned unchanged.
    - The replacement text is inserted verbatim and is not automatically
      terminated with a line break.
    - No normalization of line endings is performed.
    - This function allocates a new string containing the modified content.
[==============================================================================}
function TStringHelper.LineReplace(const lineNumber: Integer; const text: string): string; overload;
var
  R: TRange;
begin
  R := Self.LineRange(lineNumber);
  if (R.start = 0) then
    Exit(Self);
  Result := (Copy(Self, 1, (R.start - 1)) + text + Copy(Self, (R.stop + 1), High(Integer)));
end;

{==============================================================================]
  <LineDelete>
  @action: Deletes the specified line from the string and returns the resulting string.
  @note:
    - Line numbering is 1-based.
    - Uses LineRange to determine the start and end positions of the line.
    - If the specified line does not exist, the original string is returned
      unchanged.
    - Only the characters of the specified line are removed; line-ending
      characters of other lines are preserved.
    - Does not normalize or adjust remaining line breaks.
[==============================================================================}
function TStringHelper.LineDelete(const lineNumber: Integer): string; overload;
var
  R: TRange;
begin
  R := Self.LineRange(lineNumber);
  if (R.start = 0) then
    Exit(Self);
  Result := Copy(Self, 1, (R.start - 1)) + Copy(Self, (R.stop + 1), High(Integer));
end;

{==============================================================================]
  <LineValid>
  @action:
    Checks whether the given 1-based line number exists in the string.
  @note:
    - Line numbers are 1-based.
    - Returns True if 1 <= LineNumber <= LineCount.
    - Returns False if LineNumber < 1 or LineNumber > LineCount.
[==============================================================================}
function TStringHelper.LineValid(const lineNumber: Integer): Boolean; overload;
begin
  Result := ((lineNumber >= 1) and (lineNumber <= Self.LineCount));
end;

{==============================================================================]
  <LineExisting>
  @action:
    Determines whether the specified 1-based line number exists in the string.
  @note:
    - Line numbers are 1-based.
    - Returns True if the line exists, False otherwise.
    - An empty string is treated as containing exactly one (empty) line.
    - Recognizes CR (#13), LF (#10), and CRLF (#13#10) line breaks.
    - Uses early-exit optimization:
        * Exits True as soon as the requested line is reached.
        * Exits False when remaining characters cannot produce enough lines.
    - Runs in O(n) worst case, often much faster in practice.
[==============================================================================}
function TStringHelper.LineExisting(const lineNumber: Integer): Boolean; overload;
var
  i, l, c, n, r: Integer;
begin
  if (lineNumber < 1) then
    Exit(False);
  l := Length(Self);
  if (l = 0) then
    Exit(lineNumber = 1);
  c := 1;
  i := 0;
  while (i.Increment <= l) do
  begin
    if (c >= lineNumber) then
      Exit(True);
    n := (lineNumber - c);
    r := ((l - i) + 1);
    if (n > r) then
      Exit(False);
    case Self[i] of
      #10: Inc(c);
      #13:
      begin
        Inc(c);
        if ((i < l) and (Self[i + 1] = #10)) then
          Inc(i);
      end;
    end;
  end;
  Result := (c >= lineNumber);
end; 

{==============================================================================]
  <LineExists>
  @action:
    Determines whether the given 1-based line number exists in the string.
    Optimized: scans only until the requested line is found.
  @note:
    - Line numbers are 1-based.
    - Returns True if the requested line exists, False otherwise.
    - Efficient for large strings; does not count all lines.
[==============================================================================}
function TStringHelper.LineExists(const lineNumber: Integer): Boolean; overload;
var
  i, l, c: Integer;
begin
  if (lineNumber < 1) then
    Exit(False);
  l := Length(Self);
  if (l = 0) then
    Exit(lineNumber = 1);
  c := 1;
  i := 0;
  while ((i.Increment <= l) and (c < lineNumber)) do
  case Self[i] of
    #10: Inc(c);
    #13:
    begin
      Inc(c);
      if ((i < l) and (Self[i + 1] = #10)) then
        Inc(i);
    end;
  end;
  Result := (c >= lineNumber);
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
  <LinesEx>
  @action: Splits the string into an array of lines using the specified
           line break string as delimiter.
  @note: Returns an empty array if the string is empty or the delimiter
         is empty. Preserves the order of lines.
[==============================================================================}
function TStringHelper.LinesEx(const lineBreak: string): TStringArray; overload;
begin
  if ((Self = '') or (Length(lineBreak) = 0)) then
    Exit([]);
  Result := Self.Explode(lineBreak);
end;

{==============================================================================]
  <LinesEx>
  @action: Splits the string into an array of lines using any of the provided
           line break strings in the TStringArray as delimiters.
  @note: Returns an empty array if the string is empty or the delimiter
         array is empty. Preserves the order of lines.
[==============================================================================}
function TStringHelper.LinesEx(const lineBreak: TStringArray): TStringArray; overload;
begin
  if ((Self = '') or (lineBreak.Size = 0)) then
    Exit([]);
  Result := Self.Explode(lineBreak);
end;

{==============================================================================]
  <LinesEx>
  @action: Splits the string into lines using the default line breaks
           (#13#10, #13, #10) as delimiters.
  @note: Returns an empty array if the string is empty.
[==============================================================================}
function TStringHelper.LinesEx: TStringArray; overload;
begin
  Result := Self.LinesEx([#13#10, #13, #10]);
end;

{==============================================================================]
  <LineCountEx>
  @action: Returns the number of lines in the string, using the specified
           line break string as delimiter.
  @note: Returns 0 if the string is empty.
[==============================================================================}
function TStringHelper.LineCountEx(const lineBreak: string): Integer; overload;
begin
  Result := Self.LinesEx(lineBreak).Length;
end;

{==============================================================================]
  <LineCountEx>
  @action: Returns the number of lines in the string, using any of the provided
           line break strings in the TStringArray as delimiters.
  @note: Returns 0 if the string is empty or the delimiter array is empty.
[==============================================================================}
function TStringHelper.LineCountEx(const lineBreak: TStringArray): Integer; overload;
begin
  Result := Self.LinesEx(lineBreak).Length;
end;

{==============================================================================]
  <LineCountEx>
  @action: Returns the number of lines in the string, using the default line
           breaks (#13#10, #13, #10) as delimiters.
  @note:   Returns 0 if the string is empty.
[==============================================================================}
function TStringHelper.LineCountEx: Integer; overload;
begin
  Result := Self.LineCountEx([#13#10, #13, #10]);
end;
{$ENDIF}