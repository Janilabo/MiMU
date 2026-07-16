{$IFDEF HELPERS}
function Unzip(var startArr, stopArr: TIntegerArray): Integer;
function Zip(const startArr, stopArr: TIntegerArray): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Unzip>
  @action: Stores arr start and stop values to startArr and stopArr.
  @note: Returns Length(arr).
[==============================================================================}
function TRangeArrayHelper.Unzip(var startArr, stopArr: TIntegerArray): Integer;
var
  i: Integer;
begin
  Result := Self.Length;
  SetLength(startArr, Result);
  SetLength(stopArr, Result);
  for i := 0 to (Result - 1) do
  begin
    startArr[i] := Self[i].start;
    stopArr[i] := Self[i].stop;
  end;
end;

{==============================================================================]
  <Zip>
  @action: Zips TPointArray with startArr and stopArr.
  @note: Uses minimum length(!), if startArr differs from stopArr size.
[==============================================================================}
function TRangeArrayHelper.Zip(const startArr, stopArr: TIntegerArray): Integer;
var
  i: Integer;
begin
  Result := Min(startArr.Size, stopArr.Size);
  SetLength(Self, Result);
  for i := 0 to (Result - 1) do
  begin
    Self[i].start := startArr[i];
    Self[i].stop := stopArr[i];
  end;
end;
{$ENDIF}
