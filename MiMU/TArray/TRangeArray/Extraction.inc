{$IFDEF HELPERS}
function Deconstruct: TIntegerArray; overload;
function Disassemble: TIntegerArray; overload;
function Spit: TIntegerArray; overload;
function Starting: TIntegerArray; overload;
function Starts: TIntegerArray; overload;
function StartValues: TIntegerArray; overload;
function Stopping: TIntegerArray; overload;
function Stops: TIntegerArray; overload;
function StopValues: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Deconstruct>
  @action: Flattens the TRangeArray into a linear array of integers.
  @note: Breaks each TRange record into its constituent start/stop fields, 
         preserving the original sequence (Start0, Stop0, Start1, Stop1...).
[==============================================================================}
function TRangeArrayHelper.Deconstruct: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, (Self.Length * 2));
  for i := 0 to High(Self) do
  begin
    Result[i * 2] := Self[i].start;
    Result[(i * 2) + 1] := Self[i].stop;
  end;
end;

{==============================================================================]
  <Disassemble>
  @action: Performs a high-speed memory copy of range boundaries into a flat array.
  @note: Uses a block memory move to extract start/stop fields. The resulting 
         array length is exactly twice the length of the source array.
[==============================================================================}
function TRangeArrayHelper.Disassemble: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, (l * 2));
  if (l > 0) then
    Move(Self[0], Result[0], (l * SizeOf(TRange)));
end;

{==============================================================================]
  <Spit>
  @action: Deconstructs the range array into a flat TIntegerArray.
  @note: Every range [A..B] becomes two separate entries in the resulting 
         array. This "spits" the raw coordinate data out of the structures.
[==============================================================================}
function TRangeArrayHelper.Spit: TIntegerArray; overload;
var
  P: PRange;
  i: Integer;
begin
  SetLength(Result, (Self.Length * 2));
  if Self.Empty then
    Exit;
  P := @Self[0];
  for i := 0 to High(Self) do
  begin
    Result[i * 2] := P^.start;
    Result[(i * 2) + 1] := P^.stop;
    Inc(P);
  end;
end;

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
