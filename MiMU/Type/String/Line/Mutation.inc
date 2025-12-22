{$IFDEF HELPERS}
function LineInsert(const lineNumber: Integer; const text: string): string; overload;
function LineReplace(const lineNumber: Integer; const text: string): string; overload;
function LineDelete(const lineNumber: Integer): string; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}