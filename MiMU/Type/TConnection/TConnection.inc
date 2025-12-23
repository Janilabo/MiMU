{$DEFINE TConnection}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TConnection = record
  id1, id2: Integer;
  {$I TConnection.pph}
end;
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TConnectionHelper = type helper for TConnection
  {$I ../Type.inc}
end;
{$ENDIF}

{$IFDEF OPERATORS}  
operator =(const a, b: TConnection): Boolean;
operator <>(const a, b: TConnection): Boolean;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS)}
{$I ../Type.inc}
{$I TConnection.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
operator =(const a, b: TConnection): Boolean;
begin
  Result := ((a.id1 = b.id1) and (a.id2 = b.id2));
end;

operator <>(const a, b: TConnection): Boolean;
begin
  Result := not (a = b);
end;
{$ENDIF}

{$UNDEF BASE}{$UNDEF TConnection}
