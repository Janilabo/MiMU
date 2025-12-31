{$IFDEF TYPES}
TRangeEnumerator = record
private
  FCurrent, FStop, FStep: Integer;
  FFirst: Boolean;
public
  constructor Init(const AStart, AStop: Integer);
  function MoveNext: Boolean;
  property Current: Integer read FCurrent;
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
constructor TRangeEnumerator.Init(const AStart, AStop: Integer);
begin
  FStop := AStop;
  if (AStart <= AStop) then
    FStep := 1
  else
    FStep := -1;
  FCurrent := (AStart - FStep);
  FFirst := True;
end;

function TRangeEnumerator.MoveNext: Boolean;
begin
  Inc(FCurrent, FStep);
  Result := ((FStep > 0) and (FCurrent <= FStop) or (FStep < 0) and (FCurrent >= FStop));
end;
{$ENDIF}