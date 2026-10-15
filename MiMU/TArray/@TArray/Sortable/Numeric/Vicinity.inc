{$IFDEF HELPERS}
function ClosestPair(var A, B: MType; const rAscending: Boolean = True): MType; overload;
function ClosestValues(var A, B: MType; const oAscending: Boolean = True): MType; overload;
function NearestPair(var A, B: MType): MType; overload;
function NearestValues(var A, B: MType; const oAscending: Boolean = True): MType; overload;
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
  <ClosestValues>
  @action: Find the two closest adjacent elements in a pre-sorted array (in ascending or descending order) and return the minimum difference,
           assigning the elements to A and B.
  @note: 
    - Requires Sorting: The array must be pre-sorted in the direction specified by oAscending (True for ascending, False for descending).
      Because it only checks adjacent elements, it will not find the closest values if the array contains arbitrary or unsorted data.
    - Early Exit on Length: Returns -1 if the array length is less than 2.
    - Early Exit on Zero Difference: Instantly terminates and returns 0 if it encounters two identical adjacent elements.
[==============================================================================}
function MArrayHelper.ClosestValues(var A, B: MType; const oAscending: Boolean = True): MType; overload;
var
  i, s: Integer;
  p, c, d: MType;
begin
  s := Self.Length;
  if (s < 2) then
    Exit(-1);
  p := Self[0];
  c := Self[1];
  A := p;
  B := c;
  case oAscending of
    True:
    begin
      Result := (c - p);
      for i := 2 to (s - 1) do
      begin
        if (Result = 0) then
          Exit;
        p := c;
        c := Self[i];
        d := (c - p);
        if (d < Result) then
        begin
          Result := d;
          A := p;
          B := c;
        end;
      end;
    end;
    False:
    begin
      Result := (p - c);
      for i := 2 to (s - 1) do
      begin
        if (Result = 0) then
          Exit;
        p := c;
        c := Self[i];
        d := (p - c);
        if (d < Result) then
        begin
          Result := d;
          A := p;
          B := c;
        end;
      end;
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

{==============================================================================]
  <NearestValues>
  @action: Find the two closest adjacent elements in a pre-sorted array and return the minimum difference.
  @note: Streamlined version that avoids code duplication for ascending/descending orders.
[==============================================================================}
function MArrayHelper.NearestValues(var A, B: MType; const oAscending: Boolean = True): MType; overload;
var
  i, s: Integer;
  d: MType;
begin
  s := Self.Length;
  if s < 2 then
    Exit(-1);
  A := Self[0];
  B := Self[1];
  if oAscending then
    Result := (Self[1] - Self[0])
  else
    Result := (Self[0] - Self[1]);
  for i := 2 to (s - 1) do
  begin
    if Result = 0 then
      Exit;
    if oAscending then
      d := (Self[i] - Self[i - 1])
    else
      d := (Self[i - 1] - Self[i]);
    if (d < Result) then
    begin
      Result := d;
      A := Self[i - 1];
      B := Self[i];
    end;
  end;
end;
{$ENDIF}
