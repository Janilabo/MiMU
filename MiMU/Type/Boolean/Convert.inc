{$IFDEF METHODS}
function Bitify(const a: Boolean): Integer; overload;
function Bitify(const a, b: Boolean): Integer; overload;
function Bitify(const a, b, c: Boolean): Integer; overload;
function Bitify(const a, b, c, d: Boolean): Integer; overload;
{$ENDIF}

{$IFDEF HELPERS}
function AsInteger: Integer;
function Binary: Char;
function BinaryDigit: Integer;
function Bit: Integer;
function Bitify: Integer;
function ToInteger: Integer;
function ToString: string;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  Result := IfThen(Self, '1', '0');
end;

{==============================================================================]
  <BinaryDigit>
  @action: Returns binary char from Boolean
  @note: True => 1 & False => 0
[==============================================================================}
function TBooleanHelper.BinaryDigit: Integer;
begin
  Result := IfThen(Self, 1, 0);
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
  Result := IfThen(Self, 1, 0);
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