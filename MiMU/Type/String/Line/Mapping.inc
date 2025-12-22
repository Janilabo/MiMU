{$IFDEF HELPERS}
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
function LineStartPosition(const lineNumber: Integer): Integer; overload;
function LineEndPosition(const lineNumber: Integer): Integer; overload;
function LineRange(const lineNumber: Integer): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}