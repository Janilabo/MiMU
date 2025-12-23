{$DEFINE TCircle}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TCircle = record
  Center: TPoint;
  Radius: Double; 
  {$DEFINE METHODS}{$I TCircle.pph}{$UNDEF METHODS}
end;
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TCircleHelper = type helper for TCircle
  {$I ../Type.inc}
end;
{$ENDIF}

{$IFDEF OPERATORS}
operator =(const a, b: TCircle): Boolean;
operator <>(const a, b: TCircle): Boolean;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS)}
{$I ../Type.inc}
{$I TCircle.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
operator =(const a, b: TCircle): Boolean;
begin
  Result := ((a.Center = b.Center) and (a.Radius = b.Radius));
end;

operator <>(const a, b: TCircle): Boolean;
begin
  Result := not (a = b);
end;
{$ENDIF}

{$UNDEF BASE}{$UNDEF TCircle}