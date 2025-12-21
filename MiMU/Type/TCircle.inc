{$DEFINE TCircle}{$I ./Configuration/Defines.inc}

{$IFDEF TYPES}
TCircle = record
  Center: TPoint;
  Radius: Double; 
  {$I ./TCircle/TCircle.inc}
end;
{$I ./Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TCircleHelper = type helper for TCircle
  {$I ./Core.inc}
end;
{$ENDIF}

{$IFDEF OPERATORS}
operator =(const a, b: TCircle): Boolean;
operator <>(const a, b: TCircle): Boolean;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ./Core.inc}
{$I ./TCircle/TCircle.inc}
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

{$UNDEF TCircle}