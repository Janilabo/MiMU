{$IFDEF HELPERS}
function Gated(const A, B: Integer): Boolean; overload;
function Palindromal: Boolean; overload;
function Palindrome: Boolean; overload;
function Palindromean: Boolean; overload;
function Palindromed: Boolean; overload;
function Palindromer: Boolean; overload;
function Palindromic: Boolean; overload;
function Palindromical: Boolean; overload;
function Palindromix: Boolean; overload;
function Palindromous: Boolean; overload;
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
  <Palindromal>
  @action: Determines whether the current integer is a palindrome by extracting
           and comparing digit pairs at symmetric positions via `div`/`mod`.
  @note: Requires no buffer or string. Computes the digit count once as a
         positional power, then peels the outermost and innermost digits of each
         pair by dividing and modding by that power and 10 respectively.
         Shrinks the window by two positions per iteration.
[==============================================================================}
function TIntegerHelper.Palindromal: Boolean; overload;
var
  n, p, l, h: Integer;
begin
  n  := Abs(Self);
  p := 1;
  while ((n div p) >= 10) do
    p := (p * 10);
  while (n > 0) do
  begin
    h := (n div p);
    l := (n mod 10);
    if (h <> l) then
      Exit(False);
    n  := ((n mod p) div 10);
    p := (p div 100);
  end;
  Result := True;
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
  <Palindromean>
  @action: Determines whether the absolute value of the integer is a palindrome.
  @note: Works by constructing both the original number (c) and its reversed
         counterpart (r) digit by digit, then comparing them for equality.
[==============================================================================}
function TIntegerHelper.Palindromean: Boolean; overload;
var
  n, d, a, b, c, r: Integer;
begin
  n := Abs(Self);
  a := 1;
  b := 1;
  d := n;
  while (d >= 10) do
  begin
    b := (b * 10);
    d := (d div 10);
  end;
  c := 0;
  r := 0;
  while (n > 0) do
  begin
    d  := (n mod 10);
    c := (c + (d * a));
    r := (r + (d * b));
    a := (a * 10);
    b := (b div 10);
    n := (n div 10);
  end;
  Result := (c = r);
end;

{==============================================================================]
  <Palindromed>
  @action: Determines whether the absolute value of the integer is a palindrome
           using string manipulation.
  @note: Converts the absolute value of the integer to a string, reverses it,
         and compares it to the original string. By using Abs(), negative
         numbers (e.g., -121) are successfully evaluated as palindromes.
[==============================================================================}
function TIntegerHelper.Palindromed: Boolean; overload;
var
  s: string;
begin
  s := IntToStr(Abs(Self));
  Result := (s = s.Reversed);
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
  <Palindromix>
  @action: Determines whether the current integer is a palindrome using
           XOR-difference checks across symmetric digit positions.
  @note: A non-zero XOR between two symmetric characters guarantees mismatch.
         Uses the same two-pointer walk as Palindromous but through `Ord`
         values, making the bitwise intent structurally explicit.
[==============================================================================}
function TIntegerHelper.Palindromix: Boolean; overload;
var
  b: array[0..11] of Byte;
  n, l, i: Integer;
begin
  n := Abs(Self);
  l := 0;
  repeat
    b[l.Increase] := (n mod 10);
    n := (n div 10);
  until (n = 0);
  i := 0;
  while (i < (l - 1 - i)) do
    if ((b[i] xor b[l - 1 - i]) = 0) then
      Inc(i)
    else
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Palindromous>
  @action: Determines whether the current integer is a palindrome by scanning
           a stack-allocated digit buffer with two closing raw-memory pointers.
  @note: Zero heap allocation. Advances a `lo` pointer forward and a `hi`
         pointer backward through the buffer, halting early on first mismatch.
[==============================================================================}
function TIntegerHelper.Palindromous: Boolean; overload;
var
  b: array[0..11] of Char;
  l, h: PChar;
  n, s: Integer;
begin
  n := Abs(Self);
  s := 0;
  repeat
    b[s.Increase] := Char(Ord('0') + (n mod 10));
    n := (n div 10);
  until (n = 0);
  l := @b[0];
  h := @b[s - 1];
  while (l < h) do
  begin
    if (l^ <> h^) then
      Exit(False);
    Inc(l);
    Dec(h);
  end;
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
