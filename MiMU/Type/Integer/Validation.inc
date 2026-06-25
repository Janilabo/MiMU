{$IFDEF HELPERS}
function Gated(const A, B: Integer): Boolean; overload;
function Palindrome: Boolean; overload;
function Palindromer: Boolean; overload;
function Palindromic: Boolean; overload;
function Palindromical: Boolean; overload;
function Palindromy: Boolean; overload;
function Resides(const A, B: Integer): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Gated>
  @action: Determines whether the current integer value falls within the 
           inclusive perimeter defined by checkpoints A and B.
  @note: Uses a sign-multiplying algebraic trick: (Self - A) * (Self - B) <= 0.
         This evaluates to True only when Self is between A and B (inclusive) 
         because one factor must be positive and the other negative (or zero).
         Naturally handles unordered checkpoints (A > B or A < B).
[==============================================================================}
function TIntegerHelper.Gated(const A, B: Integer): Boolean; overload;
begin
  Result := ((Self - A) * (Self - B) <= 0);
end;

{==============================================================================]
  <Palindrome>
  @action: Determines whether the current integer reads the same forward and backward.
  @note: Uses `Abs` to isolate digits ignoring the sign.
         Utilizes an `Int64` storage registry (`r`) to safely prevent integer overflow exceptions when reversing large non-palindrome numbers.
[==============================================================================}
function TIntegerHelper.Palindrome: Boolean; overload;
var
  n: Integer;
  r: Int64;
begin
  n := Abs(Self);
  r := 0;
  while (n > 0) do
  begin
    r := ((r * 10) + (n mod 10));
    n := (n div 10);
  end;
  Result := (Abs(Self) = r);
end;

{==============================================================================]
  <Palindromer>
  @action: Determines whether the current integer is a palindrome using a recursive, accumulator-based reversing method.
  @note: Highly stable implementation. By accumulating the completely reversed number (`rev`) down the recursive stack,
         it avoids the leading/middle zero truncation bugs inherent to digit-stripping algorithms.
[==============================================================================}
function TIntegerHelper.Palindromer: Boolean; overload;
  function P(val, rev: Integer): Integer;
  begin
    if (val = 0) then
      Exit(rev);
    Result := P((val div 10), ((rev * 10) + (val mod 10)));
  end;
var
  s: Integer;
begin
  s := Abs(Self);
  Result := (s = P(s, 0));
end;

{==============================================================================]
  <Palindromic>
  @action: Determines whether the current integer reads the same forward and backward using string conversion.
  @note: Highly compatible across different Free Pascal compiler modes.
         Converts the absolute value to a string using `IntToStr` to eliminate integer overflow risks when verifying large numbers.
[==============================================================================}
function TIntegerHelper.Palindromic: Boolean; overload;
var
  s: string;
  i, l: Integer;
begin
  s := IntToStr(Abs(Self));
  l := Length(s);
  for i := 1 to (l div 2) do
    if (s[i] <> s[l - i + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Palindromical>
  @action: Checks for a palindrome using a fixed stack buffer for maximum speed.
  @note: Avoids heap allocation completely by manually building a character array.
[==============================================================================}
function TIntegerHelper.Palindromical: Boolean; overload;
var
  b: array[0..11] of Char;
  n, l, i: Integer;
begin
  n := Abs(Self);
  if (n < 10) then
    Exit(True);
  l := 0;
  while (n > 0) do
  begin
    b[l.Increase] := Char(Ord('0') + (n mod 10));
    n := (n div 10);
  end;
  for i := 0 to ((l div 2) - 1) do
    if (b[i] <> b[l - 1 - i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Palindromy>
  @action: Determines whether the current integer is a palindrome by reversing and comparing only its trailing half.
  @note: Highly optimized approach. Cuts execution time in half,
         and completely avoids 32-bit integer overflow by stopping extraction precisely at the numerical midpoint.
[==============================================================================}
function TIntegerHelper.Palindromy: Boolean; overload;
var
  s, r: Integer;
begin
  s := Abs(Self);
  if ((s <> 0) and ((s mod 10) = 0)) then
    Exit(False);
  r := 0;
  while (s > r) do
  begin
    r := ((r * 10) + (s mod 10));
    s := (s div 10);
  end;
  Result := ((s = r) or (s = (r div 10)));
end;

{==============================================================================]
  <Resides>
  @action: Determines whether the current integer value lies within the 
           inclusive range defined by boundaries A and B.
  @note: Uses a single unsigned (Cardinal) comparison by shifting the entire 
         range down to 0, removing the need for separate lower and upper 
         bound checks. Automatically handles unordered bounds (A > B or A < B).
[==============================================================================}
function TIntegerHelper.Resides(const A, B: Integer): Boolean; overload;
var
  m: Integer;
begin
  m := Min(A, B);
  Result := (Cardinal(Self - m) <= Cardinal(Max(A, B) - m));
end;
{$ENDIF}
