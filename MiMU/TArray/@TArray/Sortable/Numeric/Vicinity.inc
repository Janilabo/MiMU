{$IFDEF HELPERS}
function ClosestPair(var A, B: MType; const rAscending: Boolean = True): MType; overload;
function NearestPair(var A, B: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ClosestPair>
  @action: Finds the two closest elements in value within an array.            
  @note: Sorts the array in O(N log N) time and performs a single linear pass
         to locate the minimum distance. Returns the distance and
         assigns the closest elements to the reference parameters A and B.
[==============================================================================}
function MArrayHelper.ClosestPair(var A, B: MType; const rAscending: Boolean = True): MType; overload;
var
  r: MArray;
  i, s: Integer;
  d: MType;
begin
  s := Self.Length;
  if (s < 2) then
    Exit(-1);
  r := Self.QuickSorted(rAscending);
  A := r[0];
  B := r[1];
  Result := Abs(r[1] - r[0]);
  for i := 2 to (s - 1) do
  begin
    d := Abs(r[i] - r[i - 1]);
    if (d < Result) then
    begin
      Result := d;
      A := r[i - 1];
      B := r[i];
      if (Result = 0) then
        Exit;
    end;
  end;
end;

{==============================================================================]
  <NearestPair>
  @action: Finds the two closest elements in value within an array using an
           exhaustive O(N^2) nested loop comparison.
   @note: Avoids array sorting entirely and uses O(1) auxiliary space. Best
          suited only for very small collections (e.g., N < 50) where sort
          overhead is undesirable. Returns distance and sets parameters A and B.
[==============================================================================}
function MArrayHelper.NearestPair(var A, B: MType): MType; overload;
var
  i, j, s: Integer;
  d: MType;
begin
  s := Self.Length;
  if (s < 2) then
    Exit(-1);
  {$IFDEF DOUBLE}
    Result := MaxDouble;
  {$ELSE}
    Result := High(MType);
  {$ENDIF}
  for i := 0 to (s - 2) do
    for j := (i + 1) to (s - 1) do
    begin
      d := Abs(Self[j] - Self[i]);
      if (d < Result) then
      begin
        Result := d;
        A := Self[i];
        B := Self[j];
        if (Result = 0) then
          Exit;
      end;
    end;
end;
{$ENDIF}
