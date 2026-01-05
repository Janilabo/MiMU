{$IFDEF HELPERS}
function LineEndingPositions: TIntegerArray; overload;
function LineEndingRanges: TRangeArray; overload;
function LineIndexes: TIntegerArray; overload;
function LineNumberMap: TIntegerArray; overload;
function LinePositions: TIntegerArray; overload;
function LineRanges: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}