{$IFDEF HELPERS}
function LineBreakArr: TStringArray; overload;
function LineBreaks: TStringArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}