{$IFDEF HELPERS}
function Starting: TIntegerArray; overload;
function Stopping: TIntegerArray; overload;
function Starts: TIntegerArray; overload;
function Stops: TIntegerArray; overload;
function StartValues: TIntegerArray; overload;
function StopValues: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Starting>
  @action: Returns start values from TRange array.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Starting: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].start;
end;

{==============================================================================]
  <Stopping>
  @action: Returns stop values from TRange array.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Stopping: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].stop;
end;

{==============================================================================]
  <Starts>
  @action: Returns start-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Starts: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].start;
end;

{==============================================================================]
  <Stops>
  @action: Returns stop-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.Stops: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].stop;
end;

{==============================================================================]
  <StartValues>
  @action: Returns start-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.StartValues: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].start;
end;

{==============================================================================]
  <StopValues>
  @action: Returns stop-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.StopValues: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].stop;
end;
{$ENDIF}
