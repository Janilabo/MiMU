{$IFDEF HELPERS}
function Gated(const A, B: Integer): Boolean; overload;
function Palindrome: Boolean; overload;
function Palindromic: Boolean; overload;
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
