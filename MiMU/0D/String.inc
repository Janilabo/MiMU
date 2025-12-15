{$DEFINE TVar := string}
{$DEFINE TArr := TStringArray}
{$DEFINE T2DArr := T2DStringArray}
{$DEFINE THelper := TStringHelper}
{$DEFINE Sortable}

{$IFDEF TYPES}
TStringArray = array of string;
T2DStringArray = array of TStringArray;
{$ENDIF}

{$IFDEF HELPERS}
TStringHelper = type helper for string
  {$I Core.inc}
  function CountOf(const item: Char): Integer; overload;
  function AmountOf(const item: Char): Integer; overload;
  function Occurs(const item: Char): Integer; overload;
  function Occurrences(const item: Char): Integer; overload;
  function After(const s: string; const index: Integer = 1): string; overload;
  function After(const index: Integer; const count: Integer = 2147483647): string; overload;
  function Ahead(const s: string; const index: Integer = 2147483647): string; overload;
  function Ahead(const index: Integer; const count: Integer = 2147483647): string; overload;
  function Before(const s: string; const index: Integer = 1): string; overload;
  function Before(const index: Integer; const count: Integer = 2147483647): string; overload;
  function Behind(const s: string; const index: Integer = 2147483647): string; overload;
  function Behind(const index: Integer; const count: Integer = 2147483647): string; overload;
  function Blank: Boolean;
  function Amount(const s: string; const overlap: Boolean = True; const index: Integer = 2147483647): Integer;
  function IsAt(const s: string; const index: Integer = 1): Boolean;
  function At(const s: string; const index: Integer = 1): Boolean; inline;
  function At2(const s: string; const index: Integer = 1): Boolean;
  function AtP(const s: string; const index: Integer = 1): Boolean;
  function AtPos(const s: string; const index: Integer = 1): Boolean;
  function AtPosEx(const s: string; const index: Integer = 1): Boolean;
  function AtPosition(const s: string; const index: Integer = 1): Boolean;
  function AtIndex(const s: string; const index: Integer = 1): Boolean;
  function Between(const s1, s2: string; const index: Integer = 1): string;
  function Chars: TCharArray;
  function Charify: TCharArray;
  function Chop: TCharArray; overload;
  function Chop(const delimiter: Char): TStringArray; overload;
  function Split: TCharArray; overload;
  function Split(const delimiter: Char): TStringArray; overload;
  function CharSet: TCharArray; overload;
  function CharacterSet: TCharArray; overload;
  function BinaryCharSet: TCharArray; overload;
  function SetOfCharacters: TCharArray; overload;
  function SetOfChars: TCharArray; overload;
  function UniqueChars: TCharArray; overload;
  function UniqueCharacters(const oAscending: Boolean = True): TCharArray; overload;
  function DistinctChars: TCharArray; overload;
  function DistinctCharacters: TCharArray; overload;
  function CharacterDict: TCharArray; overload;
  function Chunk(const a, b: Integer): string;
  function Center(const size: Integer; const fill: Char = #32): string;
  function Compare(const target: string): Integer; inline;
  function Sign(const target: string): Integer; inline;
  function Precede(const target: string; const aAscending: Boolean): Boolean; overload;
  function Ascending(const target: string): Boolean; inline;
  function Descending(const target: string): Boolean; inline;
  function Contains(const s: string; const index: Integer = 1): Boolean;
  function Count(const s: string; const overlap: Boolean = True; const index: Integer = 1): Integer;
  function CountIn(const target: string): Integer; overload;
  function CountedIn(const target: string; const overlap: Boolean = True): Integer; overload;
  function Duplicate(const x: Integer = 2): string;
  function Duplicated(const x: Integer; const glue: string): string;
  function Empty: Boolean;
  function EndsWith(const s: string): Boolean;
  function EndWith(const s: string; const index: Integer = 2147483647): Boolean;
  function Exch(const aIndex, bIndex: Integer): Boolean;
  function Exchange(const aIndex, bIndex: Integer): Boolean;
  function Exists: Boolean;
  function Explode: TCharArray; overload;
  function Explode(const d: string; const limit: Integer = -1): TStringArray; overload;
  function Explode(const d: TStringArray; const limit: Integer = -1): TStringArray; overload;
  function Tokenized(const d: Char = #32): TStringArray; overload;
  function Delimited(const d: Char = #32): TStringArray; overload;
  function Find(const s: string; const index: Integer = 1): Integer;
  function Flip: string;
  function FromLeft(const count: Integer; const index: Integer = 1): string;
  function FromRight(const count: Integer; const index: Integer = 2147483647): string;
  function Get(const index: Integer; const count: Integer): string; inline;
  function IDs: TIntegerArray; overload;
  function IDs(const ID: TIntegerArray): TCharArray; overload;
  function IDs(const ID: TIntegerArray; const item: Char): TCharArray; overload;
  function IDs(const ID: TIntegerArray; const items: TCharArray): TCharArray; overload;
  function Includes(const s: string; const index: Integer = 2147483647): Boolean;
  function Loc(const s: string; const index: Integer = 2147483647): Integer;
  function Location(const s: string; const index: Integer = 2147483647): Integer;
  function Pick(const index: Integer; const count: Integer = 2147483647): string;
  function Pos(const s: string; const index: Integer = 1): Integer;
  function Position(const s: string; const index: Integer = 1): Integer;
  function Search(const s: string; const index: Integer = 1): Integer;
  function PregQuote(const regex: string = '.\+*?[^]$(){}=!<>|:-'): string;
  function Quotatation: string;
  function Reverse: Boolean;
  function Reversed: string;
  function Slice(const a, b: Integer): string;
  function StartsWith(const s: string): Boolean;
  function StartWith(const s: string; const index: Integer = 1): Boolean;
  function Stuff(const s: string; const iFrom, iCount: Integer): string;
  function TrimLeft(const t: Char = #32): string;
  function TrimRight(const t: Char = #32): string;
  function Trim(const t: Char = #32): string;
  function AsTRange: TRange;
  function Void: Boolean;
  function ToTRange(const glueRange: string = '..'; const openRange: Char = '['; const closeRange: Char = ']'): TRange;
  function IsBinary(const emptyTrue: Boolean = True): Boolean;
  function BoolifyBinary: TBooleanArray;
  function MadeOf(const allowed: TCharArray): Boolean;
  function FreeOf(const forbidden: TCharArray): Boolean;
  function BuiltWithout(const forbidden: TCharArray): Boolean;
  function Consists(const allowed: TCharArray): Boolean;
  function Pure(const allowed: TCharArray): Boolean;
  function BuiltWith(const blocks: TCharArray): Boolean;
  function CountTokens(const items: TStringArray): Integer; overload;
  function TokensCount(const items: TStringArray): Integer; overload;
  function LineAmount: Integer; overload;
  function LinesTotal: Integer; overload;
  function LineQuantity: Integer; overload;
  function LinePopulation: Integer; overload;
  function LineCount: Integer; overload;
  function Lines: TStringArray; overload;
  function Lined: TStringArray; overload;
  function LineArray: TStringArray; overload;
  function LineArr: TStringArray; overload;
  function LineList: TStringArray; overload;
  function LinesList: TStringArray; overload;
  function Line(const number: Integer): string; overload;
  function LineWithPosition(const position: Integer): Integer; overload;
  function LineFromPosition(const position: Integer): Integer; overload;
  function LineByPos(const position: Integer): Integer; overload;
  function LineByPosition(const position: Integer): Integer; overload;
  function LineByPosition2(const position: Integer): Integer; overload;
  function LineToPos(const line: Integer): Integer; overload;
  function LineToPosition(const line: Integer): Integer; overload;
  function LineIndexes: TIntegerArray; overload;
  function LineRanges: TRangeArray; overload;
  function LineEndingRanges: TRangeArray; overload;
  function LinePositions: TIntegerArray; overload;
  function LineEndingPositions: TIntegerArray; overload;
  function LineEx(const number: Integer; const lineBreak: string): string; overload;
  function LineEx(const number: Integer; const lineBreak: TStringArray): string; overload;
  function LineEx(const number: Integer): string; overload;
  function LinesEx(const lineBreak: string): TStringArray; overload;
  function LinesEx(const lineBreak: TStringArray): TStringArray; overload;
  function LinesEx: TStringArray; overload;
  function LineCountEx(const lineBreak: string): Integer; overload;
  function LineCountEx(const lineBreak: TStringArray): Integer; overload;
  function LineCountEx: Integer; overload;
end;
{$ENDIF}

{$IFDEF METHODS}
function Max(const a, b: string): string; overload; inline;
function Min(const a, b: string): string; overload; inline;
function Comparison(const A, B: string): Integer; overload;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I Core.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <CountOf>
  @action: Returns the number of occurrences of the specified character.
  @note: Performs a straightforward linear scan. Suitable for general use.
[==============================================================================}
function TStringHelper.CountOf(const item: Char): Integer; overload;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(Self);
  E := (P + Length(Self));
  while (P < E) do
  begin
    if (P^ = item) then
      Inc(Result);
    Inc(P);
  end;
end;

{==============================================================================]
  <AmountOf>
  @action: Returns how many times the specified character appears in the string.
  @note: Equivalent to CountOf but expressed with repeat/until iteration.
[==============================================================================}
function TStringHelper.AmountOf(const item: Char): Integer; overload;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(Self);
  E := (P + Length(Self));
  if (P < E) then
  repeat
    if (P^ = item) then
      Inc(Result);
    Inc(P);
  until (P = E);
end;

{==============================================================================]
  <Occurs>
  @action: Counts occurrences of the specified character using indexed access.
  @note: Uses 1-based string indexing; clear and simple but slightly slower.
[==============================================================================}
function TStringHelper.Occurs(const item: Char): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 1 to Length(Self) do
    if (Self[i] = item) then
      Inc(Result);
end;

{==============================================================================]
  <Occurrences>
  @action: Returns the number of occurrences of the specified character.
  @note: Optimized approach using loop unrolling for improved performance.
[==============================================================================}
function TStringHelper.Occurrences(const item: Char): Integer; overload;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(Self);
  E := (P + Length(Self));
  while ((PtrUInt(E) - PtrUInt(P)) >= 4) do
  begin
    Result := (Result + (Ord(P[0] = item)) + Ord(P[1] = item) + Ord(P[2] = item) + Ord(P[3] = item));
    Inc(P, 4);
  end;
  while (P < E) do
  begin
    if (P^ = item) then
      Inc(Result);
    Inc(P);
  end;
end;

{==============================================================================]
  <After>
  @action: Returns string that is found after s in str.
  @note: None
[==============================================================================}
function TStringHelper.After(const s: string; const index: Integer = 1): string; overload;
var
  p: Integer;
begin
  p := Self.Pos(s, index);
  if (p > 0) then
    Result := Copy(Self, (p + Length(s)), Length(Self))
  else
    Result := '';
end;

{==============================================================================]
  <After>
  @action: Returns string that is found after index in str.
  @note: None
[==============================================================================}
function TStringHelper.After(const index: Integer; const count: Integer = 2147483647): string; overload;
begin
  if ((index >= 0) and (index < Length(Self)) and (count > 0)) then
    Result := Copy(Self, (index + 1), count)
  else
    Result := '';
end;

{==============================================================================]
  <Ahead>
  @action: Returns string that is ahead the s in str.
  @note: None
[==============================================================================}
function TStringHelper.Ahead(const s: string; const index: Integer = 2147483647): string; overload;
var
  p: Integer;
begin
  p := Self.Loc(s, index);
  if (p > 0) then
    Result := Copy(Self, 1, (p - 1))
  else
    Result := '';
end;

{==============================================================================]
  <Ahead>
  @action: Returns string that is ahead the index in str.
  @note: None
[==============================================================================}
function TStringHelper.Ahead(const index: Integer; const count: Integer = 2147483647): string; overload;
var
  c: Integer;
begin
  if ((index > 1) and (count > 0)) then
  begin
    c := Min(count, (index - 1));
    Result := Copy(Self, (index - c), c);
  end else
    Result := '';
end;

{==============================================================================]
  <Amount>
  @action: Simply returns the amount of s in str.
  @note: Contains support for overlapping (overlap)
[==============================================================================}
function TStringHelper.Amount(const s: string; const overlap: Boolean = True; const index: Integer = 2147483647): Integer;
var
  p, o: Integer;
  c: string;
begin
  Result := 0;
  c := Copy(Self, 1, index);
  o := overlap.Select(1, Length(s));
  p := (1 - o);
  repeat
    p := c.Find(s, (p + o));
    if (p > 0) then
      Inc(Result);
  until (p < 1);
end;

{==============================================================================]
  <IsAt>
  @action: Evaluates whether the substring s matches the characters of the
           current string beginning at the specified 1-based index by performing
           a raw memory comparison via CompareMem.
  @note: Performs no boundary checks on Self or index; the caller must ensure
         that the referenced range is valid. Provides extremely low overhead
         and represents the fastest practical implementation when safety is
         managed externally.
[==============================================================================}
function TStringHelper.IsAt(const s: string; const index: Integer = 1): Boolean;
begin
  Result := CompareMem((PChar(Self) + (index - 1)), PChar(s), (Length(s) * SizeOf(Char)));
end;

{==============================================================================]
  <At>
  @action: Checks if string s is at index position in str.
  @note: UNSAFE: Minimal checking for efficiency!
[==============================================================================}
function TStringHelper.At(const s: string; const index: Integer = 1): Boolean; inline;
var
  i: Integer;
begin
  for i := 1 to Length(s) do
    if (Self[((index) + i) - 1] <> s[i]) then
      Exit(False);
  Result := (Length(s) > 0);
end;

{==============================================================================]
  <At2>
  @action: Compares the substring s with the characters of the current string
           starting at the specified 1-based index using a decrementing-length
           loop and raw pointer iteration.
  @note: Performs no validation of the receiver’s bounds; the caller must
         guarantee that index and Length(s) reference valid memory within
         Self. Uses minimal loop overhead and a countdown-based termination
         condition, making this an efficient but unsafe low-level routine.
[==============================================================================}
function TStringHelper.At2(const s: string; const index: Integer = 1): Boolean;
var
  a, b: PChar;
  l: Integer;
begin
  l := Length(s);
  if (l = 0) then
    Exit(False);
  a := (PChar(Self) + (index - 1));
  b := PChar(s);
  repeat
    if (a^ <> b^) then
      Exit(False);
    Inc(a);
    Inc(b);
  until (l.Decrement = 0);
  Result := True;
end;

{==============================================================================]
  <AtP>
  @action: Evaluates whether the substring s matches the characters of the
           current string beginning at the specified 1-based index by performing
           a raw pointer-based sequential comparison.
  @note: Performs no boundary validation on Self; caller must ensure that
         index and Length(s) reference valid memory within the string.
         Uses direct pointer arithmetic and is optimized for maximum speed
         with minimal overhead, but is inherently unsafe if misused.
[==============================================================================}
function TStringHelper.AtP(const s: string; const index: Integer = 1): Boolean;
var
  a, b, c: PChar;
  l: Integer;
begin
  l := Length(s);
  if (l = 0) then
    Exit(False);
  a := (PChar(Self) + (index - 1));
  b := PChar(s);
  c := (b + l);
  while (b < c) do
  begin
    if (a^ <> b^) then
      Exit(False);
    Inc(a);
    Inc(b);
  end;
  Result := True;
end;

{==============================================================================]
  <AtPos>
  @action: Determines whether the substring s matches the content of the
           current string starting at the specified 1-based index.
  @note: Performs full bounds checking and uses Copy for comparison, which
         is safe but allocates a temporary substring.
[==============================================================================}
function TStringHelper.AtPos(const s: string; const index: Integer = 1): Boolean;
begin
  Result := ((index > 0) and (Length(s) > 0) and (((index + Length(s)) - 1) <= Length(Self)) and (Copy(Self, index, Length(s)) = s));
end;

{==============================================================================]
  <AtPosEx>
  @action: Determines whether the substring s matches the content of the
           current string starting at the specified 1-based index.
  @note: Based on PosEx
[==============================================================================}
function TStringHelper.AtPosEx(const s: string; const index: Integer = 1): Boolean;
begin
  Result := ((Length(s) > 0) and (index > 0) and (PosEx(s, Self, index) = index));
end;

{==============================================================================]
  <AtPosition>
  @action: Checks whether the substring s is present at the specified 1-based
           index in the current string using a direct memory comparison.
  @note: Validates bounds but avoids temporary allocations by using
         CompareMem, providing a faster, low-overhead comparison.
[==============================================================================}
function TStringHelper.AtPosition(const s: string; const index: Integer = 1): Boolean;
var
  l: Integer;
begin
  l := Length(s);
  if ((l = 0) or (index < 1) or (((index + l) - 1) > Length(Self))) then
    Exit(False);
  Result := CompareMem(@Self[index], @s[1], (l * SizeOf(Char)));
end;

{==============================================================================]
  <AtIndex>
  @action: Determines whether the substring s matches the content of the
           current string beginning at the specified 1-based index by performing
           a direct character-by-character comparison.
  @note: Avoids temporary string allocation and uses an early check on the
         first character for efficiency. Performs full boundary validation and
         is suitable for performance-sensitive contexts where readability and
         safety must both be preserved.
[==============================================================================}
function TStringHelper.AtIndex(const s: string; const index: Integer = 1): Boolean;
var
  i, l: Integer;
begin
  l := Length(s);
  if ((l = 0) or (index < 1) or (((index + l) - 1) > Length(Self)) or (Self[index] <> s[1])) then
    Exit(False);
  for i := 2 to l do
    if (Self[(index + i) - 1] <> s[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Before>
  @action: Returns string that is found before s in str.
  @note: None
[==============================================================================}
function TStringHelper.Before(const s: string; const index: Integer = 1): string; overload;
var
  p: Integer;
begin
  p := Self.Pos(s, index);
  if (p > 0) then
    Result := Copy(Self, 1, (p - 1))
  else
    Result := '';
end;

{==============================================================================]
  <Before>
  @action: Returns string that is found before index in str.
  @note: None
[==============================================================================}
function TStringHelper.Before(const index: Integer; const count: Integer = 2147483647): string; overload;
var
  c: Integer;
begin
  if ((index > 1) and (count > 0)) then
  begin
    c := Min(count, (index - 1));
    Result := Copy(Self, (index - c), c);
  end else
    Result := '';
end;

{==============================================================================]
  <Behind>
  @action: Returns string (with count) that is behind the s in str.
  @note: None
[==============================================================================}
function TStringHelper.Behind(const s: string; const index: Integer = 2147483647): string; overload;
var
  p: Integer;
begin
  p := Self.Loc(s, index);
  if (p > 0) then
    Result := Copy(Self, (p + Length(s)), Length(Self))
  else
    Result := '';
end;

{==============================================================================]
  <Behind>
  @action: Returns string (with count) that is behind the index in str.
  @note: None
[==============================================================================}
function TStringHelper.Behind(const index: Integer; const count: Integer = 2147483647): string; overload;
begin
  if (index >= 0) and (index < Length(Self)) and (count > 0) then
    Result := Copy(Self, (index + 1), count)
  else
    Result := '';
end;

{==============================================================================]
  <Between>
  @action: Returns the string between s1 and s2 in str.
  @note: Supports offset (index).
[==============================================================================}
function TStringHelper.Between(const s1, s2: string; const index: Integer = 1): string;
var
  b, e, l: Integer;
begin
  b := Self.Find(s1, index);
  if (b = 0) then
    Exit('');
  l := Length(s1);
  e := Self.Find(s2, (b + l));
  if (e = 0) then
    Exit('');
  Result := Self.Get((b + l), (e - (b + l)));
end;

{==============================================================================]
  <Void>
  @action: Returns true if string is empty (Length is 0).
  @note: None.
[==============================================================================}
function TStringHelper.Void: Boolean;
begin
  Result := (Self = '');
end;

{==============================================================================]
  <Empty>
  @action: Returns true if string is empty (Length is 0).
  @note: None.
[==============================================================================}
function TStringHelper.Empty: Boolean;
begin
  Result := (Length(Self) = 0);
end;

{==============================================================================]
  <Blank>
  @action: Returns true if string is empty or consists of whitespaces only.
  @note: None.
[==============================================================================}
function TStringHelper.Blank: Boolean;
var
  i: Integer;
begin
  for i := 1 to Length(Self) do
    if not CharInSet(Self[i], [' ', #9, #10, #13]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Exists>
  @action: Returns true if string is not empty.
  @note: Length(str) > 0.
[==============================================================================}
function TStringHelper.Exists: Boolean;
begin
  Result := (Length(Self) > 0);
end;

{==============================================================================]
  <Center>
  @action: Returns str centered with fill characters where size is the length of the Result.
  @note: Supports custom filling character by fill!
[==============================================================================}
function TStringHelper.Center(const size: Integer; const fill: Char = #32): string;
var
  l, p: Integer;
begin
  l := Length(Self);
  if (l >= size) then
    Result := Self
  else
    if (l > 0) then
    begin
      p := (((size - l) div 2) + 1);
      Result := (StringOfChar(fill, (p - 1)) + Self + StringOfChar(fill, ((size - (p + l)) + 1)));
    end else
      Result := StringOfChar(fill, size);
end;

{==============================================================================]
  <Chars>
  @action: Returns characters of string as TCharArray.
  @note: None.
[==============================================================================}
function TStringHelper.Chars: TCharArray;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Result) do
    Result[i] := Self[i + 1];
end;

{==============================================================================]
  <Charify>
  @action: Returns characters of string as TCharArray.
  @note: None.
[==============================================================================}
function TStringHelper.Charify: TCharArray;
begin
  SetLength(Result, Length(Self));
  if not Self.Empty then
    Move(Self[1], Result[0], (Length(Self) * SizeOf(Char)));
end;

{==============================================================================]
  <Chop>
  @action: Returns characters of string as TCharArray.
  @note: None.
[==============================================================================}
function TStringHelper.Chop: TCharArray; overload;
var
  p: PChar;
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  p := PChar(Self);
  for i := 0 to (l - 1) do
  begin
    Result[i] := p^;
    Inc(p);
  end;
end;

{==============================================================================]
  <Chop>
  @action: Splits the string into substrings using the specified delimiter character.
           Each occurrence of the delimiter divides the string, producing an array
           of substrings. The delimiter itself is not included in the output.
  @note: - Consecutive delimiters produce empty substrings.
         - Leading or trailing delimiters result in empty strings at the start or end.
         - Uses Self.Count(d) to determine the number of delimiters; ensure this helper exists.
[==============================================================================}
function TStringHelper.Chop(const delimiter: Char): TStringArray; overload;
var
  s, i, l: Integer;
begin
  if (Length(Self) = 0) then
    Exit([]);
  SetLength(Result, (Self.Count(delimiter) + 1));
  s := 1;
  l := 0;
  for i := 1 to Length(Self) do
    if (Self[i] = delimiter) then
    begin
      Result[l.Increase] := Copy(Self, s, (i - s));
      s := (i + 1);
    end;
  Result[l] := Copy(Self, s, ((Length(Self) - s) + 1));
end;

{==============================================================================]
  <Split>
  @action: Converts the string into an array of characters (TCharArray),
           where each element of the array is a single character from the string.
  @note: - The resulting array length is equal to the length of the string.
         - Characters are placed in the same order as in the original string.
[==============================================================================}
function TStringHelper.Split: TCharArray; overload;
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l + 1];
end;

{==============================================================================]
  <Split>
  @action: Splits the string into substrings using the specified delimiter character.
           Each occurrence of the delimiter separates the string, and the substrings
           are returned as a TStringArray.
  @note:   - If the string is empty, returns an empty array.
           - Consecutive delimiters produce empty strings in the result array.
           - The delimiter itself is not included in the resulting substrings.
[==============================================================================}
function TStringHelper.Split(const delimiter: Char): TStringArray; overload;
var
  p, r: Integer;
  s: string;
begin
  if (Length(Self) = 0) then
    Exit([]);
  r := 0;
  s := Copy(Self, 1, Length(Self));
  p := s.Pos(delimiter);
  while (p > 0) do
  begin
    SetLength(Result, (r + 1));
    Result[r.Increase] := Copy(s, 1, (p - 1));
    s := Copy(s, (p + 1), High(Integer));
    p := s.Pos(delimiter);
  end;
  SetLength(Result, (r + 1));
  Result[r] := s;
end;

{==============================================================================]
  <Tokenized>
  @action: Splits the current string into an array of substrings using the
           specified delimiter character d. Returns all segments between
           occurrences of d.
  @note:   Consecutive delimiters produce empty substrings. The order of
           elements in the resulting array corresponds to their order in
           the original string. Preallocates the result array based on the
           count of delimiter occurrences for efficiency.
[==============================================================================}
function TStringHelper.Tokenized(const d: Char = #32): TStringArray; overload;
var
  s, i, l: Integer;
begin
  SetLength(Result, (Self.Count(d) + 1));
  s := 1;
  l := 0;
  for i := 1 to Length(Self) do
    if (Self[i] = d) then
    begin
      Result[l.Increase] := Copy(Self, s, (i - s));
      s := (i + 1);
    end;
  Result[l] := Copy(Self, s, ((Length(Self) - s) + 1));
end;

{==============================================================================]
  <Delimited>
  @action: Splits the current string into an array of substrings using the
           specified delimiter character `d`. Returns all segments between
           occurrences of `d`, preserving their order.
  @note: Consecutive delimiters produce empty substrings. Uses `Copy` and
         `Delete` to extract segments iteratively. Returns an empty array
         if the original string is empty. Slightly less efficient than
         preallocated approaches for very long strings due to repeated
         memory shifting by `Delete`.
[==============================================================================}
function TStringHelper.Delimited(const d: Char = #32): TStringArray; overload;
var
  t: string;
  p, c: Integer;
begin
  if (Length(Self) = 0) then
    Exit([]);
  t := Copy(Self, 1, Length(Self));
  c := 0;
  SetLength(Result, (t.Count(d) + 1));
  p := t.Pos(d);
  while (p > 0) do
  begin
    Result[c.Increase] := Copy(t, 1, (p - 1));
    Delete(t, 1, p);
    p := t.Pos(d);
  end;
  Result[c] := t;
end;

{==============================================================================]
  <CharSet>
  @action: Returns an array of all unique characters (0–255) present in this
           string, using a fixed Boolean array of 256 elements for tracking.
  @note: Works correctly only for 8-bit AnsiStrings. The order of characters
         is ascending by ordinal value (0..255). May include control characters.
[==============================================================================}
function TStringHelper.CharSet: TCharArray; overload;
var
  i, l: Integer;
  c: TBooleanArray;
begin
  if (Length(Self) = 0) then
    Exit([]);
  c := T1D.Create(False, 256);
  for i := 1 to Length(Self) do
    c[Ord(Self[i])] := True;
  SetLength(Result, Min(Length(Self), 256));
  l := 0;
  for i := 0 to 255 do
    if c[i] then
      Result[l.Increase] := Char(i);
  SetLength(Result, l);
end;

{==============================================================================]
  <CharacterSet>
  @action: Returns an array of all unique characters in this string. It first
           counts the unique values and then allocates the result array exactly
           once before populating it.
  @note: Efficient for 8-bit strings. Characters are returned in ascending
         ordinal order (0..255). Not suitable for UTF-8 strings.  
         Uses two passes over a 256-element Boolean array to determine count.
[==============================================================================}
function TStringHelper.CharacterSet: TCharArray; overload;
var
  i, c: Integer;
  u: TBooleanArray;
begin
  if (Length(Self) = 0) then
    Exit([]);
  u := T1D.Create(False, 256);
  for i := 1 to Length(Self) do
    u[Ord(Self[i])] := True;
  c := 0;
  for i := 0 to 255 do
    if u[i] then
      Inc(c);
  SetLength(Result, c);
  c := 0;
  for i := 0 to 255 do
    if u[i] then
      Result[c.Increase] := Char(i);
end;

{==============================================================================]
  <BinaryCharSet>
  @action: Returns an array of unique characters present in the string (`Self`),
           using a dynamic binary/integer array to track uniqueness. Characters
           are stored in the result array in ascending ordinal order based on
           their first insertion into the binary array.
  @note: - Works for 8-bit AnsiStrings; may not produce correct results for
           multibyte or UTF-8 strings.
         - Uses `BinaryGrow` to insert characters without duplicates.
         - May be less efficient than a fixed-size Boolean array for strings
           with many repeated characters, due to dynamic array operations.
         - Characters are returned in the order defined by the binary array
           insertion logic, not necessarily by first occurrence in the string.
[==============================================================================}
function TStringHelper.BinaryCharSet: TCharArray; overload;
var
  i: Integer;
  c: TIntegerArray;
begin
  if (Length(Self) = 0) then
    Exit([]);
  SetLength(c, 0);
  for i := 1 to Length(Self) do
    c.BinaryGrow(Ord(Self[i]));
  SetLength(Result, Length(c));
  for i := 0 to High(c) do
    Result[i] := Char(c[i]);
end;

{==============================================================================]
  <SetOfCharacters>
  @action: Extracts the unique characters from the string while preserving the order of their first occurrence.
  @note: Implements a simple O(n²) uniqueness check by scanning previously collected characters.
         The result array is trimmed to the number of unique characters.
[==============================================================================}
function TStringHelper.SetOfCharacters: TCharArray; overload;
var
  i, j, l: Integer;
  f: Boolean;
begin
  SetLength(Result, Length(Self));
  l := 0;
  for i := 1 to Length(Self) do
  begin
    f := False;
    for j := 0 to (l - 1) do
      if (Result[j] = Self[i]) then
      begin
        f := True;
        Break;
      end;
    if not f then
      Result[l.Increase] := Self[i];
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <SetOfChars>
  @action: Returns the set of unique characters contained in the string, preserving first-occurrence order.
  @note: Uses a slightly different control flow from SetOfCharacters,
         starting with the first character pre-initialized. Runtime characteristics are equivalent (O(n²)).
[==============================================================================}
function TStringHelper.SetOfChars: TCharArray; overload;
var
  i, j, h: Integer;
begin
  SetLength(Result, Length(Self));
  if (Length(Self) = 0) then
    Exit;
  Result[0] := Self[1];
  h := 0;
  for i := 2 to Length(Self) do
    for j := 0 to h do
      if (Result[j] = Self[i]) then
        Break
      else if (j = h) then
        Result[h.Increment] := Self[i];
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <UniqueChars>
  @action: Returns an array of unique characters found in the string, preserving
           the **first-occurrence order**.
  @note: Works for any string, but uses a nested loop (O(n²) complexity),
         so it is less efficient for long strings. Suitable for small strings
         or when character order matters.
[==============================================================================}
function TStringHelper.UniqueChars: TCharArray; overload;
var
  i, j, l: Integer;
  f: Boolean;
  c: Char;
begin
  if (Length(Self) = 0) then
    Exit([]);
  Result := T1D.Create(Self[1], 256);
  l := 1;
  for i := 2 to Length(Self) do
  begin
    f := False;
    for j := 1 to l do
    begin
      f := (Self[i] = Result[j]);
      if f then
        Break;
    end;
    if not f then
      Result[l.Increase] := Self[i];
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <UniqueCharacters>
  @action: Returns an array of unique characters extracted from the string.
  @note: The characters are sorted ascending or descending (depending on the
         parameter) before duplicate removal, so the result is ordered by
         character code, not by the original string's order.
[==============================================================================}
function TStringHelper.UniqueCharacters(const oAscending: Boolean = True): TCharArray; overload;
begin
  Result := Self.Charify;
  if (Result.Size > 1) then
  begin
    Result.QuickSort(oAscending);
    Result.Compress;
  end;
end;

{==============================================================================]
  <DistinctChars>
  @action: Returns an array containing all unique characters present in the string.
  @note: Characters are deduplicated using a byte-level set and returned in
         ascending ordinal (0..255) order.
[==============================================================================}
function TStringHelper.DistinctChars: TCharArray; overload;
var
  b: set of Byte;
  i, c: Integer;
begin
  b := [];
  for i := 1 to Length(Self) do
    Include(b, Ord(Self[i]));
  c := 0;
  for i := 0 to 255 do
    if i in b then
      Inc(c);
  SetLength(Result, c);
  c := 0;
  for i := 0 to 255 do
    if i in b then
      Result[c.Increase] := Char(i);
end;

{==============================================================================]
  <CharacterDict>
  @action: Returns an array containing all unique characters present in the string.
  @note: Based on TDictionary
[==============================================================================}
function TStringHelper.DistinctCharacters: TCharArray; overload;
var
  s: set of Byte;
  i, c: Integer;
begin
  s := [];
  SetLength(Result, Length(Self));
  c := 0;
  for i := 1 to Length(Self) do
    if not (Ord(Self[i]) in s) then
    begin
      Include(s, Ord(Self[i]));
      Result[c.Increase] := Self[i];
    end;
  SetLength(Result, c);
end;

{==============================================================================]
  <CharacterDict>
  @action: Returns an array containing all unique characters present in the string.
  @note: Based on TDictionary
[==============================================================================}
function TStringHelper.CharacterDict: TCharArray; overload;
var
  d: specialize TDictionary<Char, Boolean>;
  c: Char;
  i: Integer;
begin
  d := specialize TDictionary<Char, Boolean>.Create;
  try
    for c in Self do
      if not d.ContainsKey(c) then
        d.Add(c, True);
    SetLength(Result, d.Count);
    i := 0;
    for c in d.Keys do
      Result[i.Increase] := c;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Chunk>
  @action: Returns chunk of string between a and b.
  @note: Supports reversed chunk, when a is higher than b.
[==============================================================================}
function TStringHelper.Chunk(const a, b: Integer): string;
var
  i, l, x, y: Integer;
begin
  l := Length(Self);
  x := a;
  y := b;
  if (x < 0) then
    x := 0;
  if (x > (l + 1)) then
    x := (l + 1);
  if (y < 0) then
    y := 0;
  if (y > (l + 1)) then
    y := (l + 1);
  if (x < y) then
    Result := Copy(Self, (x + 1), ((y - x) - 1))
  else
    if (x <> y) then
    begin
      SetLength(Result, ((x - y) - 1));
      for i := (x - 1) downto (y + 1) do
        Result[x - i] := Self[i];
    end else
      Result := '';
end;

{==============================================================================]
  <Compare>
  @action: Compares str with target.
  @note: Results: 0=EQUAL, 1=str>target, -1=str<target
[==============================================================================}
function TStringHelper.Compare(const target: string): Integer; inline; {$DEFINE Skeleton_Compare}{$I Skeletons.inc}{$UNDEF Skeleton_Compare}

{==============================================================================]
  <Sign>
  @action: Compares the current string (Self) with a target string and returns
          a directional sign indicating whether the target is greater, equal,
          or smaller than Self.
  @note: Returns:
         1  if Self < target (target is larger → ascending)
         0  if Self = target (no change)
         -1  if Self > target (target is smaller → descending)
         Useful for detecting sequence direction, ordering, or range computation.
[==============================================================================}
function TStringHelper.Sign(const target: string): Integer; inline; {$DEFINE Skeleton_Sign}{$I Skeletons.inc}{$UNDEF Skeleton_Sign}

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TStringHelper.Precede(const target: string; const aAscending: Boolean): Boolean; overload; {$DEFINE Skeleton_Precede}{$I Skeletons.inc}{$UNDEF Skeleton_Precede}

{==============================================================================]
  <Ascending>
  @action  Returns True if the helper’s value is less than or equal to         
           the given target value. Useful as a comparison predicate when        
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TStringHelper.Ascending(const target: string): Boolean; inline; {$DEFINE Skeleton_Ascending}{$I Skeletons.inc}{$UNDEF Skeleton_Ascending}

{==============================================================================]
  <Descending>
  @action: Returns True if the helper’s value is greater than or equal to
           the given target value. Use as a comparison predicate when
           sorting or merging arrays in descending order.
  @note: Pure comparison only; equivalent to Self >= target.
[==============================================================================}
function TStringHelper.Descending(const target: string): Boolean; inline; {$DEFINE Skeleton_Descending}{$I Skeletons.inc}{$UNDEF Skeleton_Descending}

{==============================================================================]
  <Contains>
  @action: Returns true if s can be found in str.
  @note: Starts search from index position.!
[==============================================================================}
function TStringHelper.Contains(const s: string; const index: Integer = 1): Boolean;
var
  i, l: Integer;
begin
  l := Length(s);
  for i := Max(1, index) to ((Length(Self) - l) + 1) do
    if (Copy(Self, i, l) = s) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Count>
  @action: Counts the number of occurrences of this string (`Self`) as a substring
           within the specified target string. Overlapping occurrences are considered.
  @note: The search is case-sensitive. If the length of Self is greater than
         the length of the target, the result is zero. This implementation
         uses a naive O(n*m) substring search algorithm, where n = Length(target)
         and m = Length(Self), so it may be inefficient for long strings.
[==============================================================================}
function TStringHelper.Count(const s: string; const overlap: Boolean = True; const index: Integer = 1): Integer;
var
  p, o: Integer;
  c: string;
begin
  Result := 0;
  c := Copy(Self, index, ((Length(Self) - index) + 1));
  o := overlap.Select(1, Length(s));
  p := (1 - o);
  repeat
    p := c.Find(s, (p + o));
    if (p > 0) then
      Inc(Result);
  until (p < 1);
end;

{==============================================================================]
  <CountIn>
  @action: Counts the number of occurrences of this string (`Self`) as a substring
           within the specified target string. Overlapping occurrences are considered.
  @note: The search is case-sensitive. If the length of Self is greater than
         the length of the target, the result is zero. This implementation
         uses a naive O(n*m) substring search algorithm, where n = Length(target)
         and m = Length(Self), so it may be inefficient for long strings.
[==============================================================================}
function TStringHelper.CountIn(const target: string): Integer; overload;
var
  i, j, l: Integer;
begin
  Result := 0;
  l := Length(Self);
  if InRange(l, 1, Length(target)) then
  for i := 1 to ((Length(target) - l) + 1) do
    for j := 1 to l do
      if (Self[j] <> target[(i + j) - 1]) then
        Break
      else if ((j = l) and (Self[j] = target[(i + j) - 1])) then
        Inc(Result);
end;

{==============================================================================]
  <CountedIn>
  @action: Counts the number of occurrences of this string (`Self`) as a substring
           within the specified target string. Supports optional counting of
           overlapping occurrences.
  @note - The search is case-sensitive.
        - If `overlap` is True, overlapping occurrences are counted.
        - If `overlap` is False, occurrences are counted without overlaps
          (i.e., the search skips ahead by the length of the substring after
          each match).
        - Uses a naive O(n*m) substring search algorithm (n = Length(target),
          m = Length(Self)); may be inefficient for long strings.
        - If Self is empty or longer than target, the result is 0.
[==============================================================================}
function TStringHelper.CountedIn(const target: string; const overlap: Boolean = True): Integer; overload;
var
  i, j, l, s, o: Integer;
begin
  Result := 0;
  l := Length(Self);
  if not InRange(l, 1, Length(target)) then
    Exit;
  s := ((Length(target) - l) + 1);
  i := 0;
  o := overlap.Select(0, (l - 1));
  while (i.Increase < s) do
    for j := 1 to l do
    case (Self[j] <> target[(i + j) - 1]) of
      False:
      if ((j = l) and (Self[j] = target[(i + j) - 1])) then
      begin
        Inc(Result);
        Inc(i, o);
      end;
      True: Break;
    end;
end;

{==============================================================================]
  <Duplicate>
  @action: Returns str * x (duplicated) times. Example: ('ha', 3) => 'hahaha'
  @note: None
[==============================================================================}
function TStringHelper.Duplicate(const x: Integer = 2): string;
var
  i: Integer;
begin
  Result := '';
  for i := 1 to x do
    Result := (Result + Self);
end;

{==============================================================================]
  <Duplicated>
  @action: Returns str * x times. Example: ('ha', 3, ' ') => 'ha ha ha'
           Places glue between the str positions to result.
  @note: Supports custom glue addition between duplicated str's.
[==============================================================================}
function TStringHelper.Duplicated(const x: Integer; const glue: string): string;
var
  i: Integer;
begin
  Result := '';
  if (x > 0) then
    if (x > 1) then
    begin
      for i := 1 to (x - 1) do
        Result := (Result + Self + glue);
      Result := (Result + Self);
    end else
      Result := Self;
end;

{==============================================================================]
  <EndsWith>
  @action: Returns True if str ends with s.
  @note: None
[==============================================================================}
function TStringHelper.EndsWith(const s: string): Boolean;
var
  l, t: Integer;
begin
  l := Length(s);
  t := Length(Self);
  Result := ((l > 0) and (t >= l) and Self.At(s, ((t - l) + 1)));
end;

{==============================================================================]
  <EndWith>
  @action: Returns true if s was found in str and it was set as the ending of the str.
  @note: Supports offset.
[==============================================================================}
function TStringHelper.EndWith(const s: string; const index: Integer = 2147483647): Boolean;
var
  p: Integer;
begin
  p := Self.Loc(s, index);
  Result := (p > 0);
  if Result then
    Self := Copy(Self, 1, ((p + Length(s)) - 1));
end;

{==============================================================================]
  <Exch(aIndex, bIndex: Integer): Boolean>
  @action: Fast version of Exchange().
  @note: Unsafe, no checking.
[==============================================================================}
function TStringHelper.Exch(const aIndex, bIndex: Integer): Boolean;
var
  c: Char;
begin
  Result := (Self[aIndex] <> Self[bIndex]);
  c := Self[aIndex];
  Self[aIndex] := Self[bIndex];
  Self[bIndex] := c;
end;

{==============================================================================]
  <Exchange(aIndex, bIndex: Integer): Boolean>
  @action: Swap items aIndex and bIndex in string.
  @note: Returns true with success.
[==============================================================================}
function TStringHelper.Exchange(const aIndex, bIndex: Integer): Boolean;
var
  l: Integer;
  c: Char;
begin
  l := Length(Self);
  Result := ((l > 1) and (aIndex <> bIndex) and InRange(aIndex, 1, l) and InRange(bIndex, 1, l) and (Self[aIndex] <> Self[bIndex]));
  if Result then
  begin
    c := Self[aIndex];
    Self[aIndex] := Self[bIndex];
    Self[bIndex] := c;
  end;
end;

{==============================================================================]
  <Explode>
  @action: Simply "explodes" string to TCharArray.
  @note: None.
[==============================================================================}
function TStringHelper.Explode: TCharArray; overload;
var
  p: PChar;
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  p := PChar(Self);
  for i := 0 to (l - 1) do
  begin
    Result[i] := p^;
    Inc(p);
  end;
end;

{==============================================================================]
  <Explode>
  @action: Explodes str with delimiter (d).
  @note: Explodes up to (maximum) limit. Limit as -1 means no limits.
[==============================================================================}
function TStringHelper.Explode(const d: string; const limit: Integer = -1): TStringArray; overload;
var
  a, b, l, p, r, s, t: Integer;
  m: Boolean;
begin
  SetLength(Result, 1);
  l := Length(Self);
  s := Length(d);
  if ((l > 0) and (s > 0)) then
  begin
    a := 1;
    p := 1;
    r := 0;
    if (limit = -1) then
      t := l
    else
      t := limit;
    while (((r + 1) < t) and ((a + s - 1) <= l)) do
    begin
      m := True;
      for b := 1 to s do
      begin
        if (Self[(a + b) - 1] <> d[b]) then
        begin
          m := False;
          Break;
        end;
      end;
      if m then
      begin
        Result[r.Increase] := Copy(Self, p, (a - p));
        p := (a + s);
        a := (p - 1);
        SetLength(Result, (r + 1));
      end;
      Inc(a);
    end;
    Result[r] := Copy(Self, p, ((l - p) + 1));
  end else
    Result[0] := '';
end;

{==============================================================================]
  <Explode>
  @action: Explodes str with delimiters (d).
  @note: Explodes up to (maximum) limit. Limit as -1 means no limits.
[==============================================================================}
function TStringHelper.Explode(const d: TStringArray; const limit: Integer = -1): TStringArray; overload;
var
  i, j, p, l, f, c: Integer;
  s, x: string;
  r: Boolean;
begin
  case ((Self = '') or (Length(d) = 0)) of
    False:
    begin
      SetLength(Result, 0);
      p := 1;
      c := 0;
      r := False;
      while not r do
      begin
        f := 0;
        l := 0;
        for i := 0 to High(d) do
        begin
          x := d[i];
          if (x = '') then
            Continue;
          j := Self.Find(x, p);
          if (j > 0) and ((f = 0) or (j < f)) then
          begin
            f := j;
            l := Length(x);
          end;
        end;
        if ((f > 0) and ((limit = -1) or (c < (limit - 1)))) then
        begin
          s := Copy(Self, p, (f - p));
          SetLength(Result, (c + 1));
          Result[c.Increase] := s;
          p := (f + l);
        end else
        begin
          SetLength(Result, (c + 1));
          Result[c] := Copy(Self, p, ((Length(Self) - p) + 1));
          r := True;
        end;
      end;
    end;
    True:
    begin
      SetLength(Result, 1);
      Result[0] := Self;
    end;
  end;
end;

{==============================================================================]
  <Flip>
  @action: Returns reversed str.
  @note: None
[==============================================================================}
function TStringHelper.Flip: string;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := l downto 1 do
    Result[i] := Self[(l - i) + 1];
end;

{==============================================================================]
  <FromLeft>
  @action: Returns string from left with count of characters.
  @note: None
[==============================================================================}
function TStringHelper.FromLeft(const count: Integer; const index: Integer = 1): string;
begin
  Result := Copy(Self, index, count);
end;

{==============================================================================]
  <FromRight>
  @action: Returns string from right with count of characters.
  @note: None
[==============================================================================}
function TStringHelper.FromRight(const count: Integer; const index: Integer = 2147483647): string;
begin
  Result := Copy(Self, ((Min(Length(Self), index) - count) + 1), count);
end;

{==============================================================================]
  <Get>
  @action: Fast method for getting substring from string index position by size.
  @note: UNSAFE! Minimal checks for efficiency.
[==============================================================================}
function TStringHelper.Get(const index: Integer; const count: Integer): string; inline;
var
  i: Integer;
begin
  SetLength(Result, count);
  for i := 1 to count do
    Result[i] := Self[(index + i) - 1];
end;

{==============================================================================]
  <IDs>
  @action: Returns indexes of string as TIntegerArray.
  @note: With empty string this function returns as []!
[==============================================================================}
function TStringHelper.IDs: TIntegerArray; overload;
var
  r: TRange;
begin
  if (Length(Self) > 0) then
  begin
    r := Self.AsTRange;
    Result := r.TIA;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <IDs>
  @action: Returns indexes of string as TCharArray.
  @note: Unsafe method without failsafes, use with care!
[==============================================================================}
function TStringHelper.IDs(const ID: TIntegerArray): TCharArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(ID));
  for i := 0 to High(Result) do
    Result[i] := Self[ID[i]];
end;

{==============================================================================]
  <IDs>
  @action: Returns indexes of string as TCharArray. Replaces character of str from IDs with item.
  @note: Unsafe method without failsafes, use with care!
[==============================================================================}
function TStringHelper.IDs(const ID: TIntegerArray; const item: Char): TCharArray; overload;
var
  i: Integer;
begin
  Result := Self.Chars;
  for i := 0 to High(ID) do
    Result[ID[i] - 1] := item;
end;

{==============================================================================]
  <IDs>
  @action: Returns indexes of string as TCharArray. Replaces character of str from IDs with item.
  @note: Unsafe method without failsafes, use with care!
[==============================================================================}
function TStringHelper.IDs(const ID: TIntegerArray; const items: TCharArray): TCharArray; overload;
var
  i, l: Integer;
begin
  Result := Self.Chars;
  l := Length(items);
  for i := 0 to High(ID) do
    Result[ID[i] - 1] := items[i mod l];	
end;

{==============================================================================]
  <Includes>
  @action: Returns true if s can be found in str.
  @note: Starts backwards search from index position.!
[==============================================================================}
function TStringHelper.Includes(const s: string; const index: Integer = 2147483647): Boolean;
var
  i, l: Integer;
begin
  l := Length(s);
  for i := Min(index, ((Length(Self) - l) + 1)) downto 1 do
    if (Copy(Self, i, l) = s) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Pick>
  @action: Method for getting substring from string index position by count.
  @note: Contains some failsafes, alternative for String_Get.
[==============================================================================}
function TStringHelper.Pick(const index: Integer; const count: Integer = 2147483647): string;
var
  s, i, p: Integer;
begin
  i := Max(index, 1);
  s := Min(((Length(Self) - i) + 1), count);
  SetLength(Result, s);
  for p := 1 to s do
    Result[p] := Self[(i + p) - 1];
end;

{==============================================================================]
  <Pos>
  @action: Returns first position of s string in str.
  @note: Starts search from index position.!
[==============================================================================}
function TStringHelper.Pos(const s: string; const index: Integer = 1): Integer;
begin
  for Result := Max(1, index) to ((Length(Self) - Length(s)) + 1) do
    if Self.At(s, Result) then
      Exit;
  Result := 0;
end;

{==============================================================================]
  <Loc>
  @action: Returns last position of s string in str.
  @note: Starts search from index position.!
[==============================================================================}
function TStringHelper.Loc(const s: string; const index: Integer = 2147483647): Integer;
begin
  for Result := Min(index, ((Length(Self) - Length(s)) + 1)) downto 1 do
    if Self.At(s, Result) then
      Exit;
  Result := 0;
end;

{==============================================================================]
  <Location>
  @action: Returns last position of s string in str.
  @note: Starts search from index position. -1 means str length!
[==============================================================================}
function TStringHelper.Location(const s: string; const index: Integer = 2147483647): Integer;
var
  a, b, o: Integer;
begin
  a := Length(Self);
  b := Length(s);
  if (index = -1) then
    o := ((a - b) + 1)
  else
    o := Max(1, index);
  if ((a > 0) and (b > 0) and (b <= a)) then
  for Result := o downto 1 do
    if Self.At(s, Result) then
      Exit;
  Result := 0;
end;

{==============================================================================]
  <Position>
  @action: Returns s position from str. Starts scanning from start.
           If s doesn't exist in str, Result will be set as 0.
  @note: Supports custom index as scan start.
[==============================================================================}
function TStringHelper.Position(const s: string; const index: Integer = 1): Integer;
var
  a, b, i: Integer;
begin
  if (index < 2) then
    Exit(Self.Pos(s));
  a := Length(Self);
  b := Length(s);
  if ((a > 0) and (b > 0) and (b <= a)) then
  for Result := index to ((a - b) + 1) do
  begin
    i := 1;
    while ((i <= b) and (Self[(Result + i) - 1] = s[i])) do
      i := (i + 1);
    if (i > b) then
      Exit;
  end;
  Result := 0;
end;

{==============================================================================]
  <Find>
  @action: Returns first position of s string in str.
  @note: Alternative for Pos().
[==============================================================================}
function TStringHelper.Find(const s: string; const index: Integer = 1): Integer;
var
  i, j, a, b: Integer;
begin
  Result := 0;
  a := Length(Self);
  b := Length(s);
  if ((a = 0) or (b = 0) or (b > a) or (index < 1) or (index > ((a - b) + 1))) then
    Exit;
  for i := index to (a - b + 1) do
    for j := 1 to b do
      if (Self[(i + j) - 1] <> s[j]) then
        Break
      else
        if (j = b) then
          Exit(i);
end;

{==============================================================================]
  <Search>
  @action: Returns first position of s string in str.
  @note: Alternative for Pos().
[==============================================================================}
function TStringHelper.Search(const s: string; const index: Integer = 1): Integer;
var
  i, j, a, b: Integer;
begin
  Result := 0;
  a := Length(Self);
  b := Length(s);
  if ((a = 0) or (b = 0) or (b > a) or (index < 1) or (index > ((a - b) + 1))) then
    Exit;
  i := index;
  while (i <= ((a - b) + 1)) do
  begin
    j := 1;
    while ((j <= b) and (Self[(i + j) - 1] = s[j])) do
      Inc(j);
    if (j > b) then
      Exit(i);
    Inc(i);
  end;
end;

{==============================================================================]
  <Reverse>
  @action: Returns reversed str.
  @note: None
[==============================================================================}
function TStringHelper.Reverse: Boolean;
var
  i, l: Integer;
  c: Char;
begin
  l := Length(Self);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
  begin
    c := Self[i + 1];
    Self[i + 1] := Self[l - i];
    Self[l - i] := c;
  end;
end;

{==============================================================================]
  <Reversed>
  @action: Returns reversed str.
  @note: None
[==============================================================================}
function TStringHelper.Reversed: string;
var
  i, l, m: Integer;
begin
  l := Length(Self);
  if (l > 1) then
  begin
    SetLength(Result, l);
    m := Floor(l / 2);
    for i := 1 to m do
    begin
      Result[i] := Self[(l - i) + 1];
      Result[(l - i) + 1] := Self[i];
    end;
    if not ((l mod 2) = 0) then
      Result[m + 1] := Self[m + 1];
  end else
    Result := Self;
end;

{==============================================================================]
  <Slice>
  @action: Returns slice of string with a and b.
  @note: Supports reversed slice, when a is higher than b.
[==============================================================================}
function TStringHelper.Slice(const a, b: Integer): string;
var
  i, l, x, y: Integer;
begin
  l := Length(Self);
  if (l > 0) then
  begin
    x := a;
    y := b;
    if (x < 1) then
      x := 1;
    if (x > l) then
      x := l;
    if (y < 1) then
      y := 1;
    if (y > l) then
      y := l;
    if (x < y) then
      Result := Copy(Self, x, ((y - x) + 1))
    else
      if (x <> y) then
      begin
        SetLength(Result, ((x - y) + 1));
        for i := x downto y do
          Result[(x - i) + 1] := Self[i];
      end else
        Result := Copy(Self, x, 1);
  end else
    Result := '';
end;

{==============================================================================]
  <StartsWith>
  @action: Returns True if str starts with s.
  @note: None
[==============================================================================}
function TStringHelper.StartsWith(const s: string): Boolean;
begin
  Result := ((s <> '') and (Length(Self) >= Length(s)) and Self.At(s));
end;

{==============================================================================]
  <StartWith>
  @action: Returns true if s was found in str and it was set as the beginning of the str.
  @note: None
[==============================================================================}
function TStringHelper.StartWith(const s: string; const index: Integer = 1): Boolean;
var
  p: Integer;
begin
  p := Self.Find(s, index);
  Result := (p > 0);
  if Result then
    Self := Copy(Self, p, (Length(Self) - (p - 1)));
end;

{==============================================================================]
  <Stuff>
  @action: Returns str stuffed with s. Starting from iFrom and ending to iFrom + iCount.
  @note: Places s to iFrom position and replaces iCount amount of next characters in str with s.
[==============================================================================}
function TStringHelper.Stuff(const s: string; const iFrom, iCount: Integer): string;
begin
  Result := Copy(Self, 1, Length(Self));
  Delete(Result, iFrom, iCount);
  Insert(s, Result, iFrom);
end;

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
  <TrimLeft>
  @action: Returns str with left-side trimmed/cleaned of t.
  @note: None
[==============================================================================}
function TStringHelper.TrimLeft(const t: Char = #32): string;
var
  i, l: Integer;
begin
  l := Length(Self);
  for i := 1 to l do
    if (Self[i] <> t) then
      Exit(Copy(Self, i, ((l + 1) - i)));
  Result := '';
end;

{==============================================================================]
  <TrimRight>
  @action: Returns str with right-side trimmed/cleaned of t.
  @note: None
[==============================================================================}
function TStringHelper.TrimRight(const t: Char = #32): string;
var
  i, l: Integer;
begin
  l := Length(Self);
  for i := l downto 1 do
    if (Self[i] <> t) then
      Exit(Copy(Self, 1, i));
  Result := '';
end;

{==============================================================================]
  <Trim>
  @action: Returns str with left-side and right-side trimmed/cleaned of t.
  @note: None
[==============================================================================}
function TStringHelper.Trim(const t: Char = #32): string;
var
  i, l, x, y: Integer;
begin
  Result := '';
  l := Length(Self);
  if (l > 0) then;
  begin
    y := 0;
    for i := l downto 1 do
      if (Self[i] = t) then
        Inc(y)
      else
        Break;
    if (y = l) then
      Exit;
    x := 0;
    for i := 1 to l do
      if (Self[i] = t) then
        Inc(x)
      else
        Break;
    if (l <= (x + y)) then
      Exit;
    SetLength(Result, (l - (x + y)));
    for i := x to ((l - y) - 1) do
      Result[(i - x) + 1] := Self[i + 1];
  end;
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

{==============================================================================]
  <MadeOf>
  @action: Returns true if str is made with only allowed characters.
  @note: None.
[==============================================================================}
function TStringHelper.MadeOf(const allowed: TCharArray): Boolean;
var
  i: Integer;
begin
  if allowed.Empty then
    Exit(False);
  for i := 1 to Length(Self) do
    if not allowed.Contains(Self[i]) then
      Exit(False);
  Result := Self.Exists;
end;

{==============================================================================]
  <FreeOf>
  @action: Returns true if str is built without forbidden characters.
  @note: None.
[==============================================================================}
function TStringHelper.FreeOf(const forbidden: TCharArray): Boolean;
var
  i: Integer;
begin
  if forbidden.Exists then
  for i := Length(Self) downto 1 do
    if forbidden.Contains(Self[i]) then
      Exit(False);
  Result := Self.Exists;
end;

{==============================================================================]
  <BuiltWithout> 
  @action: Checks if array arr does not have any forbidden items.
  @note: None.
[==============================================================================}
function TStringHelper.BuiltWithout(const forbidden: TCharArray): Boolean;
var
  i, j: Integer;
begin
  if forbidden.Exists then
  for i := 1 to Length(Self) do
    for j := 0 to High(forbidden) do
      if (Self[i] = forbidden[j]) then
        Exit(False);
  Result := True;
end;

{==============================================================================]
  <Consists>
  @action: Returns true if str is made with only allowed characters.
  @note: None.
[==============================================================================}
function TStringHelper.Consists(const allowed: TCharArray): Boolean;
var
  i: Integer;
  m: TBooleanArray;
begin
  if (allowed.Empty or Self.Empty) then
    Exit(False);
  m.Create(256, False);
  for i := 0 to High(allowed) do
    m[Ord(allowed[i])] := True;
  for i := 1 to Length(Self) do
    if not m[Ord(Self[i])] then
      Exit(False);
  Result := True;
end; 

{==============================================================================]
  <Pure>
  @action: Returns true if str is made with only allowed characters.
  @note: None.
[==============================================================================}
function TStringHelper.Pure(const allowed: TCharArray): Boolean;
begin
  Result := Self.Chars.Ordinals.Pure(allowed.Ordinals);
end;

{==============================================================================]
  <BuiltWith>
  @action: Returns true is string is built with blocks.
  @note: This function requires blocks array to be unique (no duplicates allowed for it).
[==============================================================================}
function TStringHelper.BuiltWith(const blocks: TCharArray): Boolean;
var
  i, p: Integer;
  u: TBooleanArray;
begin
  if (Self.Empty or blocks.Empty) then
    Exit(False);
  SetLength(u, Length(blocks));
  for i := 1 to Length(Self) do
  begin
    p := blocks.Pos(Self[i]);
    if (p = -1) then
      Exit(False);
    u[p] := True;
  end;
  for i := 0 to High(blocks) do
    if not u[i] then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <CountTokens>
  @action: Counts the number of non-overlapping occurrences of the specified token
           strings in the string. Scans left-to-right, matching the first token that
           fits at each position.
  @note:
    - Tokens are tested in the order provided; first match wins.
    - Overlapping tokens must be ordered from longest to shortest to avoid
      double-counting (e.g., #13#10 before #13 and #10).
    - Returns 0 if the string is empty or no tokens match.
[==============================================================================}
function TStringHelper.CountTokens(const items: TStringArray): Integer; overload;
label
  ContinueScan;
var
  i, l, j, s: Integer;
begin
  Result := 0;
  s := Length(Self);
  i := 1;
  while (i <= s) do
  begin
    for j := 0 to High(items) do
    begin
      l := Length(items[j]);
      if (((l > 0) and (i + l - 1 <= s)) and CompareMem(@Self[i], @items[j][1], (l * SizeOf(Char)))) then
      begin
        Inc(Result);
        Inc(i, l);
        goto ContinueScan;
      end;
    end;
    Inc(i);
    ContinueScan:
  end;
end;

{==============================================================================]
  <TokensCount>
  @action: Counts the number of non-overlapping occurrences of the specified token
           strings within the string. This version is provided for cases where a
           noun-first style is preferred over the verb-first form CountTokens.
  @note:
    - Tokens are tested in the order provided; the first matching token is
      counted at each position.
    - Overlapping tokens must be ordered from longest to shortest to prevent
      double-counting (e.g., #13#10 before #13 and #10).
    - The function performs a single left-to-right scan and advances the
      position by the full length of the matched token.
    - Returns 0 if the string is empty or no tokens are matched.
    - Matches are non-overlapping; once a token is matched, shorter tokens
      starting at the same position are ignored.
[==============================================================================}
function TStringHelper.TokensCount(const items: TStringArray): Integer; overload;
var
  i, j, l, s: Integer;
  m: Boolean;
begin
  Result := 0;
  s := Length(Self);
  i := 1;
  while (i <= s) do
  begin
    m := False;
    for j := 0 to High(items) do
    begin
      l := Length(items[j]);
      if (((l > 0) and (i + l - 1 <= s)) and CompareMem(@Self[i], @items[j][1], (l * SizeOf(Char)))) then
      begin
        Inc(Result);
        Inc(i, l);
        m := True;
        Break;
      end;
    end;
    if not m then
      Inc(i);
  end;
end;

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
  <LineCount>
  @action: Counts the number of lines in a string.
           Each line is delimited by Windows (#13#10), Mac (#13), or Unix (#10) line breaks.
           Lines that end with a line break are counted, including a trailing empty line.
  @note: If the string is empty, it is considered to contain 1 line.
         This function handles mixed line endings and ensures that
         the last line is counted even if it does not end with a line break.
[==============================================================================}
function TStringHelper.LineCount: Integer; overload;
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
    M := R.Central;
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

function Max(const A, B: string): string; overload; inline; {$DEFINE Skeleton_Max}{$I Skeletons.inc}{$UNDEF Skeleton_Max}
function Min(const A, B: string): string; overload; inline; {$DEFINE Skeleton_Min}{$I Skeletons.inc}{$UNDEF Skeleton_Min}
function Comparison(const A, B: string): Integer; overload; {$DEFINE Skeleton_Comparison}{$I Skeletons.inc}{$UNDEF Skeleton_Comparison}
{$ENDIF}
