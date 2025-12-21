{$IFDEF HELPERS}
function Lines: TStringArray; overload;
function LinesStr(const lineRange: TRange): string; overload;
function Lined: TStringArray; overload;
function LineArray: TStringArray; overload;
function LineArr: TStringArray; overload;
function LinesArray: TStringArray; overload;
function LinesArr: TStringArray; overload;
function LineList: TStringArray; overload;
function LinesList: TStringArray; overload;
function LinesNormalized(const newLine: string = sLineBreak): string; overload;
function LinesEx(const lineBreak: string): TStringArray; overload;
function LinesEx(const lineBreak: TStringArray): TStringArray; overload;
function LinesEx: TStringArray; overload;
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
{$ENDIF}