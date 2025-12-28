{$DEFINE TBox}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TBoxEnumerator = record
private
  FX, FY, XStart, YStart, XStop, YStop: Integer;
  FFirst: Boolean;
public
  constructor Init(const AX1, AY1, AX2, AY2: Integer);
  function MoveNext: Boolean;
  function GetCurrent: TPoint;
  property Current: TPoint read GetCurrent;
end;
TBox = record
  X1, Y1, X2, Y2: Integer;
  {$DEFINE METHODS}{$I TBox.pph}{$UNDEF METHODS}
  function GetEnumerator: TBoxEnumerator;  
end;
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TBoxHelper = type helper for TBox
  {$I ../Type.inc}
  {$I TBox.pph}
end;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Type.inc}
{$I TBox.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
constructor TBoxEnumerator.Init(const AX1, AY1, AX2, AY2: Integer);
begin
  XStart := AX1;
  XStop := AX2;
  YStart := AY1;
  YStop := AY2;
  FX := (XStart - 1);
  FY := YStart;
  FFirst := True;
end;

function TBoxEnumerator.MoveNext: Boolean;
begin
  if FFirst then
  begin
    FFirst := False;
    FX := XStart;
    Result := True;
    Exit;
  end;
  Inc(FX);
  if (FX > XStop) then
  begin
    FX := XStart;
    Inc(FY);
  end;
  Result := (FY <= YStop);
end;

function TBoxEnumerator.GetCurrent: TPoint;
begin
  Result := Point(FX, FY);
end;

function TBox.GetEnumerator: TBoxEnumerator;
begin
  Result.Init(X1, Y1, X2, Y2);
end;
{$ENDIF}

{$UNDEF BASE}{$UNDEF TBox}
