{$IFDEF HELPERS}
function AnEven: Boolean; overload;
function AnOdd: Boolean; overload;
function Even: Boolean; overload;
function Even2: Boolean; overload;
function Evenly: Boolean; overload;
function EvenNumber: Boolean; overload;
function Evensy: Boolean; overload;
function EvenValue: Boolean; overload;
function IsEven: Boolean; overload;
function IsOdd: Boolean; overload;
function Odd: Boolean; overload;
function Odd2: Boolean; overload;
function Oddly: Boolean; overload;
function OddNumber: Boolean; overload;
function Oddsy: Boolean; overload;
function OddValue: Boolean; overload;
function Parity: Byte; overload;
function ParityEven: Boolean; overload;
function ParityOdd: Boolean; overload;
function Unodd: Boolean; overload;
function Uneven: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AnEven>
  @action: ?
  @note: ?
[==============================================================================}
function TIntegerHelper.AnEven: Boolean; overload;
begin
  Result := (Self = (Self shr 1) shl 1);
end;

{==============================================================================]
  <AnOdd>
  @action: ?
  @note: ?
[==============================================================================}
function TIntegerHelper.AnOdd: Boolean; overload;
begin
  Result := not Self.AnEven;
end;

{==============================================================================]
  <Even>
  @action: Returns true if Integer value x is an even number.
  @note: None
[==============================================================================}
function TIntegerHelper.Even: Boolean; overload;
begin
  Result := ((Self mod 2) = 0);
end;

{==============================================================================]
  <Even>
  @action: Returns true if Integer value x is an even number.
  @note: None
[==============================================================================}
function TIntegerHelper.Even2: Boolean; overload;
begin
  Result := not System.Odd(Self);
end;

{==============================================================================]
  <Evenly>
  @action: Reports whether `Self` is an even integer.
  @note: Uses `Abs` before the parity check, so negative even values (e.g. `-4`) correctly return `True`.
[==============================================================================}
function TIntegerHelper.Evenly: Boolean; overload;
begin
  Result := ((Abs(Self) and 1) = 0);
end;

{==============================================================================]
  <EvenNumber>
  @action: Checks whether the current integer value is an even number.
  @note: Uses integer division arithmetic to determine parity. Returns True 
         if the value is divisible by 2 with no remainder, otherwise False.
[==============================================================================}
function TIntegerHelper.EvenNumber: Boolean; overload;
begin
  Result := (((Self div 2) * 2) = Self);
end;

{==============================================================================]
  <Evensy>
  @action: Determines whether the integer is an even number by inspecting its 
           last digit.
  @note: Converts the integer to a string and checks if the final character 
         is an even digit ('0', '2', '4', '6', or '8').
[==============================================================================}
function TIntegerHelper.Evensy: Boolean; overload;
begin
  Result := (IntToStr(Self).Taily in ['0', '2', '4', '6', '8']);
end;

{==============================================================================]
  <EvenValue>
  @action: Checks whether the integer value is even.
  @note: Evaluates truth by comparing a floating-point division (0.5 * Self) 
         against an integer truncation division (Self div 2).
[==============================================================================}
function TIntegerHelper.EvenValue: Boolean; overload;
begin
  Result := ((0.5 * Self) = (Self div 2));
end;

{==============================================================================]
  <IsEven>
  @action: Returns true if Integer value x is an even number.
  @note: None
[==============================================================================}
function TIntegerHelper.IsEven: Boolean; overload;
begin
  Result := ((Self and 1) = 0);
end;

{==============================================================================]
  <IsOdd>
  @action: Returns true if Integer value x is an odd number.
  @note: None
[==============================================================================}
function TIntegerHelper.IsOdd: Boolean; overload;
begin
  Result := ((Self and 1) = 1);
end;

{==============================================================================]
  <Odd>
  @action: Returns true if Integer value x is an odd number.
  @note: None
[==============================================================================}
function TIntegerHelper.Odd: Boolean; overload;
begin
  Result := ((Self mod 2) <> 0);
end;

{==============================================================================]
  <Odd>
  @action: Returns true if Integer value x is an odd number.
  @note: None
[==============================================================================}
function TIntegerHelper.Odd2: Boolean; overload;
begin
  Result := System.Odd(Self);
end;

{==============================================================================]
  <Oddly>
  @action: Reports whether `Self` is an odd integer.
  @note: Defined as the negation of `Evenly`, so it inherits the same sign-safe behavior for negative values.
[==============================================================================}
function TIntegerHelper.Oddly: Boolean; overload;
begin
  Result := not Self.Evenly;
end;

{==============================================================================]
  <OddNumber>
  @action: Checks whether the current integer value is an odd number.
  @note: Evaluates parity by logically inverting the result of the EvenNumber 
         helper function. Returns True if the value is odd, otherwise False.
[==============================================================================}
function TIntegerHelper.OddNumber: Boolean; overload;
begin
  Result := not Self.EvenNumber;
end;

{==============================================================================]
  <Oddsy>
  @action: Determines whether the integer is an odd number by inspecting its 
           last digit.
  @note: Converts the integer to a string and checks if the final character 
         is an odd digit ('1', '3', '5', '7', or '9').
[==============================================================================}
function TIntegerHelper.Oddsy: Boolean; overload;
begin
  Result := (IntToStr(Self).Taily in ['1', '3', '5', '7', '9']);
end;

{==============================================================================]
  <OddValue>
  @action: Checks whether the integer value is odd.
  @note: Evaluates truth by comparing a floating-point division (0.5 * Self) 
         against an integer truncation division (Self div 2). Returns the 
         inverse of EvenValue.
[==============================================================================}
function TIntegerHelper.OddValue: Boolean; overload;
begin
  Result := ((0.5 * Self) <> (Self div 2));
end;

{==============================================================================]
  <Parity>
  @action: Returns the Integer Parity Bit as Byte.
  @note: 0 = even, 1 = odd.
[==============================================================================}
function TIntegerHelper.Parity: Byte; overload;
begin
  Result := (Self mod 2);
end;

{==============================================================================]
  <Even>
  @action: Returns true if Integer value x is an even number.
  @note: None
[==============================================================================}
function TIntegerHelper.ParityEven: Boolean; overload;
begin
  Result := (Self.Parity = 0);
end;

{==============================================================================]
  <Odd>
  @action: Returns true if Integer value x is an odd number.
  @note: None
[==============================================================================}
function TIntegerHelper.ParityOdd: Boolean; overload;
begin
  Result := (Self.Parity = 1);
end;

{==============================================================================]
  <Unodd>
  @action: Checks if the integer is an even number.
  @note: Returns True if the number is even, and False if it is odd. 
         Uses bitwise XOR logic to determine parity.
[==============================================================================}
function TIntegerHelper.Unodd: Boolean; overload;
begin
  Result := ((Self xor 1) = (Self + 1));
end;

{==============================================================================]
  <Uneven>
  @action: Checks if the integer is an odd number.
  @note: Returns True if the number is odd, and False if it is even. 
         This is the strict logical inverse of Unodd.
[==============================================================================}
function TIntegerHelper.Uneven: Boolean; overload;
begin
  Result := not ((Self xor 1) = (Self + 1));
end;
{$ENDIF}
