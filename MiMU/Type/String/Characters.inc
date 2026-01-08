{$IFDEF HELPERS}
function BinaryCharSet: TCharArray; overload; cdecl;
function CharacterDict: TCharArray; overload; cdecl;
function CharacterSet: TCharArray; overload; cdecl;
function Charify: TCharArray; cdecl;
function Chars: TCharArray; cdecl;
function CharSet: TCharArray; overload; cdecl;
function DistinctCharacters: TCharArray; overload; cdecl;
function DistinctChars: TCharArray; overload; cdecl;
function IDs: TIntegerArray; overload; cdecl;
function IDs(const ID: TIntegerArray): TCharArray; overload; cdecl;
function IDs(const ID: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
function IDs(const ID: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;
function SetOfCharacters: TCharArray; overload; cdecl;
function SetOfChars: TCharArray; overload; cdecl;
function UniqueCharacters(const oAscending: Boolean = True): TCharArray; overload; cdecl;
function UniqueChars: TCharArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
function TStringHelper.BinaryCharSet: TCharArray; overload; cdecl;
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
  <CharacterDict>
  @action: Returns an array containing all unique characters present in the string.
  @note: Based on TDictionary
[==============================================================================}
function TStringHelper.CharacterDict: TCharArray; overload; cdecl;
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
  <CharacterSet>
  @action: Returns an array of all unique characters in this string. It first
           counts the unique values and then allocates the result array exactly
           once before populating it.
  @note: Efficient for 8-bit strings. Characters are returned in ascending
         ordinal order (0..255). Not suitable for UTF-8 strings.  
         Uses two passes over a 256-element Boolean array to determine count.
[==============================================================================}
function TStringHelper.CharacterSet: TCharArray; overload; cdecl;
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
  <Charify>
  @action: Returns characters of string as TCharArray.
  @note: None.
[==============================================================================}
function TStringHelper.Charify: TCharArray; cdecl;
begin
  SetLength(Result, Length(Self));
  if not Self.Empty then
    Move(Self[1], Result[0], (Length(Self) * SizeOf(Char)));
end;

{==============================================================================]
  <Chars>
  @action: Returns characters of string as TCharArray.
  @note: None.
[==============================================================================}
function TStringHelper.Chars: TCharArray; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Result) do
    Result[i] := Self[i + 1];
end;

{==============================================================================]
  <CharSet>
  @action: Returns an array of all unique characters (0–255) present in this
           string, using a fixed Boolean array of 256 elements for tracking.
  @note: Works correctly only for 8-bit AnsiStrings. The order of characters
         is ascending by ordinal value (0..255). May include control characters.
[==============================================================================}
function TStringHelper.CharSet: TCharArray; overload; cdecl;
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
  <CharacterDict>
  @action: Returns an array containing all unique characters present in the string.
  @note: Based on TDictionary
[==============================================================================}
function TStringHelper.DistinctCharacters: TCharArray; overload; cdecl;
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
  <DistinctChars>
  @action: Returns an array containing all unique characters present in the string.
  @note: Characters are deduplicated using a byte-level set and returned in
         ascending ordinal (0..255) order.
[==============================================================================}
function TStringHelper.DistinctChars: TCharArray; overload; cdecl;
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
  <IDs>
  @action: Returns indexes of string as TIntegerArray.
  @note: With empty string this function returns as []!
[==============================================================================}
function TStringHelper.IDs: TIntegerArray; overload; cdecl;
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
function TStringHelper.IDs(const ID: TIntegerArray): TCharArray; overload; cdecl;
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
function TStringHelper.IDs(const ID: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
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
function TStringHelper.IDs(const ID: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;
var
  i, l: Integer;
begin
  Result := Self.Chars;
  l := Length(items);
  for i := 0 to High(ID) do
    Result[ID[i] - 1] := items[i mod l];	
end;

{==============================================================================]
  <SetOfCharacters>
  @action: Extracts the unique characters from the string while preserving the order of their first occurrence.
  @note: Implements a simple O(n²) uniqueness check by scanning previously collected characters.
         The result array is trimmed to the number of unique characters.
[==============================================================================}
function TStringHelper.SetOfCharacters: TCharArray; overload; cdecl;
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
function TStringHelper.SetOfChars: TCharArray; overload; cdecl;
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
  <UniqueCharacters>
  @action: Returns an array of unique characters extracted from the string.
  @note: The characters are sorted ascending or descending (depending on the
         parameter) before duplicate removal, so the result is ordered by
         character code, not by the original string's order.
[==============================================================================}
function TStringHelper.UniqueCharacters(const oAscending: Boolean = True): TCharArray; overload; cdecl;
begin
  Result := Self.Charify;
  if (Result.Size > 1) then
  begin
    Result.QuickSort(oAscending);
    Result.Compress;
  end;
end;

{==============================================================================]
  <UniqueChars>
  @action: Returns an array of unique characters found in the string, preserving
           the **first-occurrence order**.
  @note: Works for any string, but uses a nested loop (O(n²) complexity),
         so it is less efficient for long strings. Suitable for small strings
         or when character order matters.
[==============================================================================}
function TStringHelper.UniqueChars: TCharArray; overload; cdecl;
var
  i, j, l: Integer;
  f: Boolean;
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
{$ENDIF}
