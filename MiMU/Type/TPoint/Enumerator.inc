{$IFDEF TYPES}
TPointEnumerator = record
private
  FCurrent, FIndex: Integer;
  FX, FY: Integer;
public
  constructor Init(const AX, AY: Integer);
  function MoveNext: Boolean;
  property Current: Integer read FCurrent;
end;
{$ENDIF}

{$IFDEF METHODS}
function GetEnumerator: TPointEnumerator;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
constructor TPointEnumerator.Init(const AX, AY: Integer);
begin
  FX := AX;
  FY := AY;
  FIndex := -1;
  FCurrent := 0;
end;

function TPointEnumerator.MoveNext: Boolean;
begin
  Inc(FIndex);
  Result := (FIndex < 2);
  if Result then
  case FIndex of
    0: FCurrent := FX;
    1: FCurrent := FY;
  end;
end;

{==============================================================================]
  <GetEnumerator>
  @action: Creates and returns an enumerator that iterates through the X and Y
           coordinates of the point in that order.
  @note: This allows using TPoint in for-in loops to access X, then Y.
[==============================================================================}
function TPoint.GetEnumerator: TPointEnumerator;
begin
  Result.Init(Self.X, Self.Y);
end;
{$ENDIF}