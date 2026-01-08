{$IFDEF METHODS}
function Even: Boolean; overload; cdecl;
function EvenCount: Integer; overload; cdecl;
function Evened: TIntegerArray; overload; cdecl;
function Evens: Integer; overload; cdecl;
function Evenz: TIntegerArray; overload; cdecl;
function Odd: Boolean; overload; cdecl;
function OddCount: Integer; overload; cdecl;
function Odded: TIntegerArray; overload; cdecl;
function Odds: Integer; overload; cdecl;
function Oddz: TIntegerArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Even>
  @action: Returns True when the size of the range is an even integer.
  @note: Delegates to Self.Size.Even; no side effects.
[==============================================================================}
function TRange.Even: Boolean; overload; cdecl;
begin
  Result := Self.Size.Even;
end;

{==============================================================================]
  <EvenCount>
  @action: Returns the number of even integers within the range (including both start and stop).
  @note: Works for ascending, descending, and single-element ranges. Handles negative numbers correctly.
[==============================================================================}
function TRange.EvenCount: Integer; overload; cdecl;
var
  f, l: Integer;
begin
  Result := Self.Direction;
  if (Result = 0) then
    Exit(IfThen(Self.start.Even, 1, 0));
  f := IfThen(Self.start.Even, Self.start, (Self.start + Result));
  l := IfThen(Self.stop.Even, Self.stop, (Self.stop - Result));
  if not (((Result > 0) and (f > l)) or ((Result < 0) and (f < l))) then
    Result := Abs((l - f) div 2) + 1;
end;

{==============================================================================]
  <Evened>
  @action: Produces an array containing all even integers within the range,
           ordered according to the range direction.
  @note: The first element is aligned to the nearest even boundary starting
         from `start`, then values progress by ±2 depending on whether the
         range is ascending or descending.
[==============================================================================}
function TRange.Evened: TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Self.Evens);
  if (Result.Length = 0) then
    Exit;
  Result[0] := Self.start;
  if Self.start.Odd then
    Result[0] := (Result[0] + Self.Direction);
  case Self.Ascending of
    True:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] + 2);
    False:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] - 2);
  end;
end;

{==============================================================================]
  <Evens>
  @action: Computes the total number of even integers contained within the range.
  @note: The computation is O(1) and works for both ascending and descending
         ranges. The result is inclusive of both endpoints.
[==============================================================================}
function TRange.Evens: Integer; overload; cdecl;
var
  r: TRange;
begin
  r := Self.Normalize;
  if r.start.Odd then
    Inc(r.start);
  if r.stop.Odd then
    Dec(r.stop);
  if (r.start > r.stop) then
    Result := 0
  else
    Result := (((r.stop - r.start) div 2) + 1);
end;

{==============================================================================]
  <TRange.Evenz>
  @action: Returns an array of all even integers within the range (from start to stop).
  @note:
    - Works for ascending, descending, and single-element ranges.
    - Handles negative numbers correctly.
    - Uses Direction to step properly through the range.
    - Skips the first element if it is odd.
[==============================================================================}
function TRange.Evenz: TIntegerArray; overload; cdecl;
var
  i, s, d: Integer;
begin
  SetLength(Result, Self.EvenCount);
  if (Result.Size = 0) then
    Exit;
  d := Self.Direction;
  s := Self.start;
  if s.Odd then
    s := (s + d);
  for i := 0 to High(Result) do
    Result[i] := s.Increase(2 * d);
end;

{==============================================================================]
  <Odd>
  @action: Returns True when the size of the range is an odd integer.
  @note: Delegates to Self.Size.Odd; no side effects.
[==============================================================================}
function TRange.Odd: Boolean; overload; cdecl;
begin
  Result := Self.Size.Odd;
end;

{==============================================================================]
  <OddCount>
  @action: Returns the number of odd integers within the range (including both start and stop).
  @note: Calculated as the total range size minus the number of even numbers. Works for ascending, descending, and negative ranges.
[==============================================================================}
function TRange.OddCount: Integer; overload; cdecl;
begin
  Result := (Self.Size - Self.EvenCount);
end;

{==============================================================================]
  <Odded>
  @action: Produces an array containing all odd integers within the range,
           ordered according to the range direction.
  @note: The first element is aligned to the nearest odd boundary starting
         from `start`, then values progress by ±2 depending on the direction
         of the range.
[==============================================================================}
function TRange.Odded: TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Self.Odds);
  if (Result.Length = 0) then
    Exit;
  Result[0] := Self.start;
  if Self.start.Even then
    Result[0] := (Result[0] + Self.Direction);
  case Self.Ascending of
    True:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] + 2);
    False:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] - 2);
  end;
end;

{==============================================================================]
  <Odds>
  @action: Computes the total number of odd integers contained within the range.
  @note: Determined as (RangeSize - Evens), ensuring correctness regardless
         of range direction or endpoint parity.
[==============================================================================}
function TRange.Odds: Integer; overload; cdecl;
begin
  Result := (Self.Size - Self.Evens);
end;

{==============================================================================]
  <TRange.Oddz>
  @action: Returns an array of all odd integers within the range (from start to stop).
  @note:
    - Works for ascending, descending, and single-element ranges.
    - Handles negative numbers correctly.
    - Uses Direction to step properly through the range.
    - Skips the first element if it is even.
[==============================================================================}
function TRange.Oddz: TIntegerArray; overload; cdecl;
var
  i, s, d: Integer;
begin
  SetLength(Result, Self.OddCount);
  if (Result.Size = 0) then
    Exit;
  d := Self.Direction;
  s := Self.start;
  if s.Even then
    s := (s + d);
  for i := 0 to High(Result) do
    Result[i] := s.Increase(2 * d);
end;
{$ENDIF}