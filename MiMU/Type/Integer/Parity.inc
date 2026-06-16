{$IFDEF HELPERS}
function Even: Boolean; overload;
function EvenNumber: Boolean; overload;
function IsEven: Boolean; overload;
function IsOdd: Boolean; overload;
function Odd: Boolean; overload;
function OddNumber: Boolean; overload;
function Parity: Byte; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Parity>
  @action: Returns the Integer Parity Bit as Byte.
  @note: 0 = even, 1 = odd.
[==============================================================================}
function TIntegerHelper.Parity: Byte; overload;
begin
  Result := (Self mod 2);
end;
{$ENDIF}