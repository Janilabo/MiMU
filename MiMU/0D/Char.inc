{$DEFINE TVar := Char}
{$DEFINE TArr := TCharArray}
{$DEFINE T2DArr := T2DCharArray}
{$DEFINE TCmp := TCharCompare}
{$DEFINE THelper := TCharHelper}
{$DEFINE Sortable}

{$IFDEF TYPES}
{$I Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
{$I Core.inc}
  function Compare(const target: Char): Integer; inline;
  function Sign(const target: Char): Integer; inline;
  function Precede(const target: Char; const aAscending: Boolean): Boolean; overload;
  function Ascending(const target: Char): Boolean; inline;
  function Descending(const target: Char): Boolean; inline;
  function Str(const size: Integer = 1): string;
  function ToStr(const size: Integer = 1): string;
  function IsNumber: Boolean;
  function IsNumeric: Boolean;
  function IsLower: Boolean;
  function IsUpper: Boolean;
  function IsLowercase: Boolean;
  function IsUppercase: Boolean;
  function IsLetter: Boolean;
  function Swapcase: Char;
  function Upper: Char;
  function Lower: Char;
  function CountIn(const target: string): Integer; overload;
  function OccurrencesIn(const target: string): Integer; overload;
  function Occurs(const target: string): Integer; overload;
  function AmountIn(const target: string): Integer; overload;
  function AppearsIn(const target: string): Integer; overload;
  function Tokenize(const str: string): TStringArray; overload;
end;
{$ENDIF}

{$IFDEF METHODS}
function Max(const a, b: Char): Char; overload; inline;
function Min(const a, b: Char): Char; overload; inline;
function Comparison(const A, B: Char): Integer; overload;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I Core.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Compare>
  @action: Compares char with target.
  @note: Results: 0=EQUAL, 1=char>target, -1=char<target
[==============================================================================}
function TCharHelper.Compare(const target: Char): Integer; inline; {$DEFINE Skeleton_Compare}{$I Skeletons.inc}{$UNDEF Skeleton_Compare}

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
function TCharHelper.Sign(const target: Char): Integer; inline; {$DEFINE Skeleton_Sign}{$I Skeletons.inc}{$UNDEF Skeleton_Sign}

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TCharHelper.Precede(const target: Char; const aAscending: Boolean): Boolean; overload; {$DEFINE Skeleton_Precede}{$I Skeletons.inc}{$UNDEF Skeleton_Precede}

{==============================================================================]
  <Ascending>
  @action  Returns True if the helper’s value is less than or equal to         
           the given target value. Useful as a comparison predicate when        
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TCharHelper.Ascending(const target: Char): Boolean; inline; {$DEFINE Skeleton_Ascending}{$I Skeletons.inc}{$UNDEF Skeleton_Ascending}

{==============================================================================]
  <Descending>
  @action: Returns True if the helper’s value is greater than or equal to
           the given target value. Use as a comparison predicate when
           sorting or merging arrays in descending order.
  @note: Pure comparison only; equivalent to Self >= target.
[==============================================================================}
function TCharHelper.Descending(const target: Char): Boolean; inline; {$DEFINE Skeleton_Descending}{$I Skeletons.inc}{$UNDEF Skeleton_Descending}

{==============================================================================]
  <Str>
  @action: Returns Char as string with size.
  @note: size * Char.
[==============================================================================}
function TCharHelper.Str(const size: Integer = 1): string; 
var
  i: Integer;
begin
  if (size < 1) then
    Exit('');
  SetLength(Result, size);
  for i := 1 to size do
    Result[i] := Self;
end;

{==============================================================================]
  <ToStr>
  @action: Returns Char as string with size.
  @note: size * Char.
[==============================================================================}
function TCharHelper.ToStr(const size: Integer = 1): string; 
var
  i: Integer;
begin
  Result := '';
  for i := 1 to size do
    Result := (Result + Self);
end;

{==============================================================================]
  <IsNumber>
  @action: Returns true if Char is a number.
  @note: None.
[==============================================================================}
function TCharHelper.IsNumber: Boolean; 
begin
  Result := ((Self >= '0') and (Self <= '9'));
end;

{==============================================================================]
  <IsNumeric>
  @action: Returns true if Char is a number.
  @note: None.
[==============================================================================}
function TCharHelper.IsNumeric: Boolean; 
begin
  Result := InRange(Ord(Self), 48, 57);
end;

{==============================================================================]
  <IsLower>
  @action: Returns true if Char is part of lowercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLower: Boolean; 
begin
  Result := InRange(Ord(Self), 97, 122);
end;

{==============================================================================]
  <IsUpper>
  @action: Returns true if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsUpper: Boolean; 
begin
  Result := InRange(Ord(Self), 65, 90);
end;

{==============================================================================]
  <IsLowercase>
  @action: Returns true if Char is part of lowercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLowercase: Boolean; 
begin
  Result := ((Self >= 'a') and (Self <= 'z'));
end;

{==============================================================================]
  <IsUppercase>
  @action: Returns true if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsUppercase: Boolean; 
begin
  Result := ((Self >= 'A') and (Self <= 'Z'));
end;

{==============================================================================]
  <IsLetter>
  @action: Returns true if Char is part of lowercased or uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLetter: Boolean; 
var
  o: Integer;
begin
  o := Ord(Self);
  Result := (InRange(o, 65, 90) or InRange(o, 97, 122));
end;

{==============================================================================]
  <Swapcase>
  @action: Swaps casing of Char, if it is part of letters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.Swapcase: Char; 
var
  o: Integer;
begin
  o := Ord(Self);
  if InRange(o, 65, 90) then
    Result := Char(o + 32)
  else
    if InRange(o, 97, 122) then
      Result := Char(o - 32)
    else
      Result := Self;
end;

{==============================================================================]
  <Upper>
  @action: Uppers char casing if Char is part of lowercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.Upper: Char; 
var
  o: Integer;
begin
  o := Ord(Self);
  if InRange(o, 97, 122) then
    Result := Char(o - 32)
  else
    Result := Self;
end;

{==============================================================================]
  <Lower>
  @action: Lowers char casing if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.Lower: Char; 
var
  o: Integer;
begin
  o := Ord(Self);
  if InRange(o, 65, 90) then
    Result := Char(o + 32)
  else
    Result := Self;
end;

function Max(const A, B: Char): Char; overload; inline; {$DEFINE Skeleton_Max}{$I Skeletons.inc}{$UNDEF Skeleton_Max}
function Min(const A, B: Char): Char; overload; inline; {$DEFINE Skeleton_Min}{$I Skeletons.inc}{$UNDEF Skeleton_Min}

function Comparison(const A, B: Char): Integer; overload; {$DEFINE Skeleton_Comparison}{$I Skeletons.inc}{$UNDEF Skeleton_Comparison}

{==============================================================================]
  <CountIn>
  @action: Returns the number of occurrences of this character (Self) within
           the specified target string.
  @note: Comparison is case-sensitive. No normalization or locale-specific
         rules are applied.
[==============================================================================}
function TCharHelper.CountIn(const target: string): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 1 to Length(target) do
    Inc(Result, Ord(target[i] = Self));
end;

{==============================================================================]
  <OccurrencesIn>
  @action: Returns the number of times this character appears in the specified string.
  @note: Performs a linear scan of the string. Operates on code units, not grapheme clusters.
[==============================================================================}
function TCharHelper.OccurrencesIn(const target: string): Integer; overload;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(target);
  E := (P + Length(target));
  while (P < E) do
  begin
    if (P^ = Self) then
      Inc(Result);
    Inc(P);
  end;
end;

{==============================================================================]
  <Occurs>
  @action: Returns the number of times this character appears in the specified string.
  @note: Performs a linear scan of the string. Operates on code units, not grapheme clusters.
[==============================================================================}
function TCharHelper.Occurs(const target: string): Integer; overload;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(target);
  E := (P + Length(target));
  while (P < E) do
  begin
    Result := (Result + Ord(P^ = Self));
    Inc(P);
  end;
end;

{==============================================================================]
  <AmountIn>
  @action: Returns the number of occurrences of this character in the specified string.
  @note: Uses repeated StrScan calls; efficient when the character occurs infrequently.
[==============================================================================}
function TCharHelper.AmountIn(const target: string): Integer; overload;
var
  P, F: PChar;
begin
  Result := 0;
  if (target = '') then
    Exit;
  P := PChar(target);
  repeat
    F := StrScan(P, Self);
    if (F = nil) then
	  Exit;
    Inc(Result);
    P := (F + 1);
  until False;
end;

{==============================================================================]
  <AppearsIn>
  @action: Returns the number of times this character appears in the specified string.
  @note: Uses a linear scan with loop unrolling for improved performance; operates on code units.
[==============================================================================}
function TCharHelper.AppearsIn(const target: string): Integer; overload;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(target);
  E := (P + Length(target));
  while ((PtrUInt(E) - PtrUInt(P)) > 3) do
  begin
    Inc(Result, (Ord(P[0] = Self) + Ord(P[1] = Self) + Ord(P[2] = Self) + Ord(P[3] = Self)));
    Inc(P, 4);
  end;
  while (P < E) do
  begin
    Inc(Result, Ord(P^ = Self));
    Inc(P);
  end;
end;

function TCharHelper.Tokenize(const str: string): TStringArray; overload;
var
  s, i, l: Integer;
begin
  if (Length(str) = 0) then
    Exit([]);
  SetLength(Result, (str.Count(Self) + 1));
  s := 1;
  l := 0;
  for i := 1 to Length(str) do
  begin
    if (str[i] <> Self) then
      Continue;
    Result[l.Increase] := Copy(str, s, (i - s));
    s := (i + 1);
  end;
  Result[l] := Copy(str, s, ((Length(str) - s) + 1));
end;
{$ENDIF}