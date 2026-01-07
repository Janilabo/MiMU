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

{$IFDEF METHODS}
function GetEnumerator: TRangeEnumerator;
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

{==============================================================================]
  <GetEnumerator>
  @action: Creates and returns an enumerator that iterates through all integer
           values contained in the range, following the iteration rules defined
           by TRangeEnumerator.
  @note: The iteration order and behavior (ascending, descending, inclusive, or
         normalized) are determined entirely by TRangeEnumerator.Init. This
         function performs no normalization and passes the range endpoints
         exactly as stored.
[==============================================================================}
function TRange.GetEnumerator: TRangeEnumerator;
begin
  Result.Init(start, stop);
end;
{$ENDIF}