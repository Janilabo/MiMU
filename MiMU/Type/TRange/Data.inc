{$IFDEF METHODS}
function Startment(out rIDs, rValues: TIntegerArray): Integer; overload;
function Startment(out rIDs: TIntegerArray): TIntegerArray; overload;
function StartStop(out rIDs: TIntegerArray; out rValues: TIntegerArray): Integer; overload;
function StartStop(out rIDs: TIntegerArray): TIntegerArray; overload;
function StartTilStop(out rIDs: TIntegerArray; out rValues: TIntegerArray): Integer; overload;
function StartTilStop(out rIDs: TIntegerArray): TIntegerArray; overload;
function Stopment(out rIDs, rValues: TIntegerArray): Integer; overload;
function Stopment(out rIDs: TIntegerArray): TIntegerArray; overload;
function StopStart(out rIDs: TIntegerArray; out rValues: TIntegerArray): Integer; overload;
function StopStart(out rIDs: TIntegerArray): TIntegerArray; overload;
function StopTilStart(out rIDs: TIntegerArray; out rValues: TIntegerArray): Integer; overload;
function StopTilStart(out rIDs: TIntegerArray): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Startment>
  @action: Populates arrays with values starting from the Start value and 
           moving forward through the range.
  @param: rIDs - Receives sequential index values (0, 1, 2, ...)
  @param: rValues - Receives calculated values from Start moving toward Stop
  @return: Number of elements populated (Size of the range)
  @note: Uses pointer optimization for faster array access.
         Example: Range(1, 5) → Values: [1, 2, 3, 4, 5]
         Example: Range(5, 1) → Values: [5, 4, 3, 2, 1]
[==============================================================================}
function TRange.Startment(out rIDs, rValues: TIntegerArray): Integer; overload;
var
  r, s: PInteger;
  i, d: Integer;
begin
  Result := Self.Size;
  SetLength(rIDs, Result);
  SetLength(rValues, Result);
  r := @rIDs[0];
  s := @rValues[0];
  d := Self.Direction;
  for i := 0 to (Result - 1) do
  begin
    r[i] := i;
    s[i] := (Self.start + (i * d));
  end;
end;

{==============================================================================]
  <Startment>
  @action: Returns a new array populated from Start moving toward Stop.
  @param: rIDs - Receives sequential index values
  @return: New array containing the range values
  @note: Convenience overload that creates the values array automatically.
[==============================================================================}
function TRange.Startment(out rIDs: TIntegerArray): TIntegerArray; overload;
begin
  Self.Startment(rIDs, Result);
end;

{==============================================================================]
  <StartStop>
  @action: Populates parallel arrays with zero-based indices and range values
           traversing from Start to Stop (ascending order).
  @param: rIDs - Output array receiving sequential indices [0, 1, 2, ..., Size-1]
  @param: rValues - Output array receiving actual range values from Self.start 
                    to Self.stop (inclusive)
  @return: Size of the range (length of both arrays)
  @note: • If range is singular, both arrays contain single elements [0] and [start]
         • rIDs[i] always equals i for all valid indices
         • rValues[0] = Self.start, then each subsequent value increments by Direction
         • Direction = +1 for ascending ranges, -1 for descending ranges
         • Arrays are automatically resized to match Self.Size
         • For descending ranges, values still go Start→Stop (e.g., 10→1)
[==============================================================================}
function TRange.StartStop(out rIDs: TIntegerArray; out rValues: TIntegerArray): Integer; overload;
var
  i, d: Integer;
begin
  Result := Self.Size;
  SetLength(rIDs, Result);
  SetLength(rValues, Result);
  rIDs[0] := 0;
  rValues[0] := Self.start;
  if (Result = 1) then
    Exit;
  d := Self.Direction;
  for i := 1 to (Result - 1) do
  begin
    rIDs[i] := i;
    rValues[i] := (rValues[i - 1] + d);
  end;
end;

{==============================================================================]
  <StartStop>
  @action: Returns range values traversing from Start to Stop while also
           populating the corresponding indices via output parameter.
  @param: rIDs - Output array receiving sequential indices [0, 1, 2, ..., Size-1]
  @return: Array of range values from Self.start to Self.stop (ascending order)
  @note: • Convenience overload that returns values directly as function result
         • Calls the primary StartStop(var, var) implementation internally
         • rIDs[i] always equals i for all valid indices
         • Functional equivalent to:
             SetLength(rIDs, Size); SetLength(Result, Size);
             Result[0] := Self.start; rIDs[0] := 0;
             for i := 1 to Size-1 do begin
               rIDs[i] := i;
               Result[i] := Result[i-1] + Direction;
             end;
         • Ideal for inline expressions where values are needed immediately
         • Example: MyValues := MyRange.StartStop(MyIndices);
[==============================================================================}
function TRange.StartStop(out rIDs: TIntegerArray): TIntegerArray; overload;
begin
  Self.StartStop(rIDs, Result);
end;

{==============================================================================]
  <StartTilStop>
  @action: Populates the arrays with values traversing from the Start value 
           until reaching the Stop value, following the range's natural direction.
  @param: rIDs - Receives sequential index values (0, 1, 2, ...)
  @param: rValues - Receives the calculated range values from Start to Stop
  @return: The total number of elements populated (Size of the range)
  @note: The arrays are automatically resized to fit the range.
         Example: Range(1, 5) produces Values: [1, 2, 3, 4, 5]
         Example: Range(5, 1) produces Values: [5, 4, 3, 2, 1]
[==============================================================================}
function TRange.StartTilStop(out rIDs: TIntegerArray; out rValues: TIntegerArray): Integer; overload;
var
  i, d: Integer;
begin
  Result := Self.Size;
  SetLength(rIDs, Result);
  SetLength(rValues, Result);
  rIDs[0] := 0;
  rValues[0] := Self.start;
  d := Self.Direction;
  for i := 1 to (Result - 1) do
    rValues[i] := (Self.start + (rIDs[i].Increment(i) * d));
end;

function TRange.StartTilStop(out rIDs: TIntegerArray): TIntegerArray; overload;
begin
  Self.StartTilStop(rIDs, Result);
end;

{==============================================================================]
  <Stopment>
  @action: Populates arrays with values starting from the Stop value and 
           moving backward through the range.
  @param: rIDs - Receives sequential index values (0, 1, 2, ...)
  @param: rValues - Receives calculated values from Stop moving toward Start
  @return: Number of elements populated (Size of the range)
  @note: Uses pointer optimization for faster array access.
         Example: Range(1, 5) → Values: [5, 4, 3, 2, 1]
         Example: Range(5, 1) → Values: [1, 2, 3, 4, 5]
[==============================================================================}
function TRange.Stopment(out rIDs, rValues: TIntegerArray): Integer; overload;
var
  r, s: PInteger;
  i, d: Integer;
begin
  Result := Self.Size;
  SetLength(rIDs, Result);
  SetLength(rValues, Result);
  r := @rIDs[0];
  s := @rValues[0];
  d := Self.Direction;
  for i := 0 to (Result - 1) do
  begin
    r[i] := i;
    s[i] := (Self.stop - (i * d));
  end;
end;

{==============================================================================]
  <Stopment>
  @action: Returns a new array populated from Stop moving toward Start.
  @param: rIDs - Receives sequential index values
  @return: New array containing the range values (reversed orientation)
  @note: Convenience overload that creates the values array automatically.
[==============================================================================}
function TRange.Stopment(out rIDs: TIntegerArray): TIntegerArray; overload;
begin
  Self.Stopment(rIDs, Result);
end;

{==============================================================================]
  <StopStart>
  @action: Populates parallel arrays with zero-based indices and range values
           traversing from Stop to Start (descending order).
  @param: rIDs - Output array receiving sequential indices [0, 1, 2, ..., Size-1]
  @param: rValues - Output array receiving actual range values from Self.stop 
                    down to Self.start (inclusive, descending)
  @return: Size of the range (length of both arrays)
  @note: • If range is singular, both arrays contain single elements [0] and [stop]
         • rIDs[i] always equals i for all valid indices (same as StartStop)
         • rValues[0] = Self.stop, then each subsequent value decrements by Direction
         • Direction = +1 for ascending ranges, -1 for descending ranges
         • For ascending ranges (1→10), values go 10→9→8→...→1
         • For descending ranges (10→1), values go 1→2→3→...→10 (reversed)
         • Arrays are automatically resized to match Self.Size
[==============================================================================}
function TRange.StopStart(out rIDs: TIntegerArray; out rValues: TIntegerArray): Integer; overload;
var
  i, d: Integer;
begin
  Result := Self.Size;
  SetLength(rIDs, Result);
  SetLength(rValues, Result);
  rIDs[0] := 0;
  rValues[0] := Self.stop;
  if (Result = 1) then
    Exit;
  d := Self.Direction;
  for i := 1 to (Result - 1) do
  begin
    rIDs[i] := i;
    rValues[i] := (rValues[i - 1] - d);
  end;
end;

{==============================================================================]
  <StopStart>
  @action: Returns range values traversing from Stop to Start while also
           populating the corresponding indices via output parameter.
  @param: rIDs - Output array receiving sequential indices [0, 1, 2, ..., Size-1]
  @return: Array of range values from Self.stop down to Self.start (descending order)
  @note: • Convenience overload that returns values directly as function result
         • Calls the primary StopStart(var, var) implementation internally
         • rIDs[i] always equals i for all valid indices (same as StartStop)
         • Functional equivalent to:
             SetLength(rIDs, Size); SetLength(Result, Size);
             Result[0] := Self.stop; rIDs[0] := 0;
             for i := 1 to Size-1 do begin
               rIDs[i] := i;
               Result[i] := Result[i-1] - Direction;
             end;
         • Ideal for inline expressions where reverse-ordered values are needed
         • Example: ReverseValues := MyRange.StopStart(MyIndices);
[==============================================================================}
function TRange.StopStart(out rIDs: TIntegerArray): TIntegerArray; overload;
begin
  Self.StopStart(rIDs, Result);
end;

{==============================================================================]
  <StopTilStart>
  @action: Populates the arrays with values traversing from the Stop value 
           backward until reaching the Start value, opposite the range's natural direction.
  @param: rIDs - Receives sequential index values (0, 1, 2, ...)
  @param: rValues - Receives the calculated range values from Stop to Start
  @return: The total number of elements populated (Size of the range)
  @note: The arrays are automatically resized to fit the range.
         Example: Range(1, 5) produces Values: [5, 4, 3, 2, 1]
         Example: Range(5, 1) produces Values: [1, 2, 3, 4, 5]
[==============================================================================}
function TRange.StopTilStart(out rIDs: TIntegerArray; out rValues: TIntegerArray): Integer; overload;
var
  i, d: Integer;
begin
  Result := Self.Size;
  SetLength(rIDs, Result);
  SetLength(rValues, Result);
  rIDs[0] := 0;
  rValues[0] := Self.stop;
  d := Self.Direction;
  for i := 1 to (Result - 1) do
    rValues[i] := (Self.stop - (rIDs[i].Increment(i) * d));
end;

function TRange.StopTilStart(out rIDs: TIntegerArray): TIntegerArray; overload;
begin
  Self.StopTilStart(rIDs, Result);
end;
{$ENDIF}