{$IFDEF METHODS}
function Bitify(const a: Boolean): Integer; overload; cdecl; inline;
function Bitify(const a, b: Boolean): Integer; overload; cdecl;
function Bitify(const a, b, c: Boolean): Integer; overload; cdecl;
function Bitify(const a, b, c, d: Boolean): Integer; overload; cdecl;
{$ENDIF}

{$IFDEF HELPERS}
function AsInteger: Integer; cdecl;
function Binary: Char; cdecl;
function BinaryDigit: Integer; cdecl;
function Bit: Integer; inline; cdecl;
function Bitify: Integer; cdecl;
function ToInteger: Integer; cdecl;
function ToString: string; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function Bitify(const a: Boolean): Integer; overload; cdecl; inline;
begin
  if a then
    Result := 1
  else
    Result := 0;
end;

function Bitify(const a, b: Boolean): Integer; overload; cdecl;
begin
  Result := ((Bitify(a) shl 1) or Bitify(b));
end;

function Bitify(const a, b, c: Boolean): Integer; overload; cdecl;
begin
  Result := ((Bitify(a) shl 2) or (Bitify(b) shl 1) or Bitify(c));
end;

function Bitify(const a, b, c, d: Boolean): Integer; overload; cdecl;
begin
  Result := ((Bitify(a) shl 3) or (Bitify(b) shl 2) or (Bitify(c) shl 1) or Bitify(d));
end;

{==============================================================================]
  <AsInteger>
  @action: Returns Self as Integer.
  @note: False => 0 | True => 1
[==============================================================================}
function TBooleanHelper.AsInteger: Integer; cdecl;
begin
  Result := Integer(Self);
end;

{==============================================================================]
  <Binary>
  @action: Returns binary char based on boolean state.
  @note: True => '1', False => '0'.
[==============================================================================}
function TBooleanHelper.Binary: Char; cdecl;
begin
  Result := IfThen(Self, '1', '0');
end;

{==============================================================================]
  <BinaryDigit>
  @action: Returns binary char from Boolean
  @note: True => 1 & False => 0
[==============================================================================}
function TBooleanHelper.BinaryDigit: Integer; cdecl;
begin
  Result := IfThen(Self, 1, 0);  
end;

{==============================================================================]
  <Bit>
  @action: Bit for helper booleans.
  @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.Bit: Integer; cdecl; inline;
begin
  Result := (Integer(Self) and 1);
end;

{==============================================================================]
  <Bitify>
  @action: Bitify for helper booleans.
  @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.Bitify: Integer; cdecl;
begin
  Result := IfThen(Self, 1, 0);
end;

{==============================================================================]
  <ToInteger>
  @action: Returns integer based on state of Self.
  @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.ToInteger: Integer; cdecl;
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
function TBooleanHelper.ToString: string; cdecl;
begin
  if Self then
    Result := 'True'
  else
    Result := 'False';
end;
{$ENDIF}