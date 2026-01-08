{$IFDEF HELPERS}
function LineClamp(const lineNumber: Integer): Integer; overload; cdecl;
function LineExisting(const lineNumber: Integer): Boolean; overload; cdecl;
function LineExists(const lineNumber: Integer): Boolean; overload; cdecl;
function LineExtant(const lineNumber: Integer): Boolean; overload; cdecl;
function LineFixed(const lineNumber: Integer): Integer; overload; cdecl;
function LineIsEmpty(const lineNumber: Integer): Boolean; overload; cdecl;
function LineValid(const lineNumber: Integer): Boolean; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
function TStringHelper.LineClamp(const lineNumber: Integer): Integer; overload; cdecl;
begin
  if (lineNumber < 1) then
    Exit(0);
  Result := Self.LineCount;
  if (lineNumber > Result) then
    Exit;
  Result := lineNumber;
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
function TStringHelper.LineExisting(const lineNumber: Integer): Boolean; overload; cdecl;
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
function TStringHelper.LineExists(const lineNumber: Integer): Boolean; overload; cdecl;
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
function TStringHelper.LineExtant(const lineNumber: Integer): Boolean; overload; cdecl;
begin
  Result := ((lineNumber > 0) and (Self.LineCountUpTo(lineNumber) >= lineNumber));
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
function TStringHelper.LineFixed(const lineNumber: Integer): Integer; overload; cdecl;
begin
  if (lineNumber < 1) then
    Exit(1);
  Result := Self.LineCount;
  if (lineNumber > Result) then
    Exit;
  Result := lineNumber;
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
function TStringHelper.LineIsEmpty(const lineNumber: Integer): Boolean; overload; cdecl;
begin
  Result := (SysUtils.Trim(Self.LineStr(lineNumber)) = '');
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
function TStringHelper.LineValid(const lineNumber: Integer): Boolean; overload; cdecl;
begin
  Result := ((lineNumber >= 1) and (lineNumber <= Self.LineCount));
end; 
{$ENDIF}