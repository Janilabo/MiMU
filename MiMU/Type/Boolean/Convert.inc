{$IFDEF FUNCTIONS}
function Binared(const A, B: Boolean): string; overload;
function Binaried(const A, B: Boolean): string; overload;
function Binarify(const A, B: Boolean): string; overload;
function Binarize(const A, B: Boolean): string; overload;
function Bitify(const a: Boolean): Integer; overload;
function Bitify(const a, b: Boolean): Integer; overload;
function Bitify(const a, b, c: Boolean): Integer; overload;
function Bitify(const a, b, c, d: Boolean): Integer; overload;
{$ENDIF}

{$IFDEF HELPERS}
function AsInteger: Integer;
function Binary: Char;
function Binaryc: Char;
function BinaryChar: Char;
function BinaryDigit: Integer;
function Binchared: Char;
function Bit: Integer;
function Bitify: Integer;
function Ordinal: Byte; overload;
function ToInteger: Integer;
function ToString: string;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function Binared(const A, B: Boolean): string; overload;
begin
  Result := Format('%d%d', [Ord(A), Ord(B)]);
end;

function Binaried(const A, B: Boolean): string; overload;
begin
  Result := (BoolToStr(A, '1', '0') + BoolToStr(B, '1', '0'));
end;

function Binarify(const A, B: Boolean): string; overload;
begin
  Result := (IfThen(A, '1', '0') + IfThen(B, '1', '0'));
end;

function Binarize(const A, B: Boolean): string; overload;
const
  C: array[Boolean] of Char = ('0', '1');
begin
  Result := (C[A] + C[B]);
end;

function Bitify(const a: Boolean): Integer; overload;
begin
  if a then
    Result := 1
  else
    Result := 0;
end;

function Bitify(const a, b: Boolean): Integer; overload;
begin
  Result := ((Bitify(a) shl 1) or Bitify(b));
end;

function Bitify(const a, b, c: Boolean): Integer; overload;
begin
  Result := ((Bitify(a) shl 2) or (Bitify(b) shl 1) or Bitify(c));
end;

function Bitify(const a, b, c, d: Boolean): Integer; overload;
begin
  Result := ((Bitify(a) shl 3) or (Bitify(b) shl 2) or (Bitify(c) shl 1) or Bitify(d));
end;

{==============================================================================]
  <AsInteger>
  @action: Returns Self as Integer.
  @note: False => 0 | True => 1
[==============================================================================}
function TBooleanHelper.AsInteger: Integer;
begin
  Result := Integer(Self);
end;

{==============================================================================]
  <Binary>
  @action: Returns binary char based on boolean state.
  @note: True => '1', False => '0'.
[==============================================================================}
function TBooleanHelper.Binary: Char;
begin
  Result := Self.IfThen('1', '0');
end;

{==============================================================================]
  <Binaryc>
  @action: Returns binary char based on boolean state.
  @note: True => '1', False => '0'.
[==============================================================================}
function TBooleanHelper.Binaryc: Char;
begin
  Result := Chr(Ord(Self) + 48);
end; 

{==============================================================================]
  <BinaryChar>
  @action: Returns binary char based on boolean state.
  @note: True => '1', False => '0'.
[==============================================================================}
function TBooleanHelper.BinaryChar: Char;
begin
  Result := BoolToStr(Self, '1', '0')[1];
end;

{==============================================================================]
  <BinaryDigit>
  @action: Returns binary char from Boolean
  @note: True => 1 & False => 0
[==============================================================================}
function TBooleanHelper.BinaryDigit: Integer;
begin
  Result := Self.IfThen(1, 0);
end;

{==============================================================================]
  <Binchared>
  @action: Returns binary char from Boolean
  @note: True => 1 & False => 0
[==============================================================================}
function TBooleanHelper.Binchared: Char;
begin
  Result := Char(Ord('0') or (Ord(Self) and 1));
end;

{==============================================================================]
  <Bit>
  @action: Bit for helper booleans.
  @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.Bit: Integer;
begin
  Result := (Integer(Self) and 1);
end;

{==============================================================================]
  <Bitify>
  @action: Bitify for helper booleans.
  @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.Bitify: Integer;
begin
  Result := Self.IfThen(1, 0);
end;

{==============================================================================]
  <Ordinal>
  @action: Extracts the underlying ordinal value of the Boolean as a Byte.
  @note: Uses a defensive bitwise mask (and 1) to guarantee a strict return 
         value of 0 or 1, neutralizing uninitialized or corrupt memory states.
[==============================================================================}
function TBooleanHelper.Ordinal: Byte; overload;
begin
  Result := (Ord(Self) and 1);
end;

{==============================================================================]
  <ToInteger>
  @action: Returns integer based on state of Self.
  @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.ToInteger: Integer;
begin
  case Self of
    True: Result := 1;
    False: Result := 0;
  end;
end;

{==============================================================================]
  <ToString>
  @action: Returns string of Self.
  @note: True => 'True', False => 'False'.
[==============================================================================}
function TBooleanHelper.ToString: string;
begin
  if Self then
    Result := 'True'
  else
    Result := 'False';
end;
{$ENDIF}
