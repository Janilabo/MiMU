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
{$ENDIF}