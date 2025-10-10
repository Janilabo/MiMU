{$DEFINE Char}{$I config\Defines.inc}

{==============================================================================]
  <TCharHelper.Compare>
  @action: Compares char with target.
  @note: Results: 0=EQUAL, 1=char>target, -1=char<target
[==============================================================================}
function TCharHelper.Compare(const target: Char): Integer; inline; {$DEFINE Skeleton_Compare}{$I config\Skeletons.inc}{$UNDEF Skeleton_Compare}

{==============================================================================]
 <TCharHelper.Precede>
 @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
 @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TCharHelper.Precede(const target: Char; const aAscending: Boolean): Boolean; overload; {$DEFINE Skeleton_Precede}{$I config\Skeletons.inc}{$UNDEF Skeleton_Precede}

{==============================================================================]
 <TCharHelper.Ascending>
 @action  Returns True if the helper’s value is less than or equal to         
          the given target value. Useful as a comparison predicate when        
          sorting or merging arrays in ascending order.
 @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TCharHelper.Ascending(const target: Char): Boolean; inline; {$DEFINE Skeleton_Ascending}{$I config\Skeletons.inc}{$UNDEF Skeleton_Ascending}

{==============================================================================]
 <TCharHelper.Descending>
 @action: Returns True if the helper’s value is greater than or equal to
          the given target value. Use as a comparison predicate when
          sorting or merging arrays in descending order.
 @note: Pure comparison only; equivalent to Self >= target.
[==============================================================================}
function TCharHelper.Descending(const target: Char): Boolean; inline; {$DEFINE Skeleton_Descending}{$I config\Skeletons.inc}{$UNDEF Skeleton_Descending}

{==============================================================================]
  <TCharHelper.Str>
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
  <TCharHelper.ToStr>
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
  <TCharHelper.IsNumber>
  @action: Returns true if Char is a number.
  @note: None.
[==============================================================================}
function TCharHelper.IsNumber: Boolean; 
begin
  Result := ((Self >= '0') and (Self <= '9'));
end;

{==============================================================================]
  <TCharHelper.IsNumeric>
  @action: Returns true if Char is a number.
  @note: None.
[==============================================================================}
function TCharHelper.IsNumeric: Boolean; 
begin
  Result := InRange(Ord(Self), 48, 57);
end;

{==============================================================================]
  <TCharHelper.IsLower>
  @action: Returns true if Char is part of lowercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLower: Boolean; 
begin
  Result := InRange(Ord(Self), 97, 122);
end;

{==============================================================================]
  <TCharHelper.IsUpper>
  @action: Returns true if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsUpper: Boolean; 
begin
  Result := InRange(Ord(Self), 65, 90);
end;

{==============================================================================]
  <TCharHelper.IsLowercase>
  @action: Returns true if Char is part of lowercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsLowercase: Boolean; 
begin
  Result := ((Self >= 'a') and (Self <= 'z'));
end;

{==============================================================================]
  <TCharHelper.IsUppercase>
  @action: Returns true if Char is part of uppercased characters
  @note: Limited to ASCII.
[==============================================================================}
function TCharHelper.IsUppercase: Boolean; 
begin
  Result := ((Self >= 'A') and (Self <= 'Z'));
end;

{==============================================================================]
  <TCharHelper.IsLetter>
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
  <TCharHelper.Swapcase>
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
  <TCharHelper.Upper>
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
  <TCharHelper.Lower>
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

{$UNDEF Char}