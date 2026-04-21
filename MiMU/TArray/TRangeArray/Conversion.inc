{$IFDEF HELPERS}
function Digitize: TIntegerArray; overload;
function T2DIA: T2DIntegerArray;
function TIA: TIntegerArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Digitize>
  @action: Converts the range structures into a flat sequence of all contained
           integers, preserving the direction (polarity) of each range.
  @note:
    - Pass 1: Accumulates total capacity to prevent reallocations.
    - Pass 2: Uses a reverse-fill sentinel (r.Decrement) to inject values.
    - Result: A "digitized" version of the coordinate data.
[==============================================================================}
function TRangeArrayHelper.Digitize: TIntegerArray; overload;
var
  i, r, s: Integer;
begin
  r := 0;
  for i := 0 to High(Self) do
    Inc(r, Self[i].Size);
  SetLength(Result, r);
  if (r = 0) then
    Exit;
  for i := High(Self) downto 0 do
  case Self[i].Ascending of
    True:
    for s := Self[i].stop downto Self[i].start do
      Result[r.Decrement] := s;
    False:
    for s := Self[i].stop to Self[i].start do
      Result[r.Decrement] := s;
  end;
end; 

{==============================================================================]
  <T2DIA>
  @action: Returns TRanges from arr as T2DIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.T2DIA: T2DIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
   for i := 0 to High(Self) do
    Result[i] := Self[i].TIA;
end;

{==============================================================================]
  <TIA>
  @action: Returns TRanges from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArrayHelper.TIA: TIntegerArray;
var
  i, j, l: Integer;
  r: TIntegerArray;
begin
  l := 0;
  for i := 0 to High(Self) do
    l := (l + Self[i].Size);
  SetLength(Result, l);
  for i := High(Self) downto 0 do
  begin
    r := Self[i].TIA;
    for j := High(r) downto 0 do
      Result[l.Decrement] := r[j];
  end;
end;
{$ENDIF}
