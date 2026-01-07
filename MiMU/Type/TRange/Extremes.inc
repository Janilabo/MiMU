{$IFDEF METHODS}
function Bottom: Integer; overload;
function First: Integer; overload;
function Higher: Integer; overload;
function Highest: Integer;
function Last: Integer; overload;
function Left: Integer; overload;
function Lower: Integer; overload;
function Lowest: Integer;
function Maxima: Integer;
function Maximal: Integer;	
function Maximum: Integer;
function Minima: Integer;
function Minimal: Integer;	
function Minimum: Integer;
function Right: Integer; overload;
function Top: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bottom>
  @action: Returns the smaller of `start` and `stop` (the lower bound of the range).
  @note:
    - Implemented using a `case` statement on the Boolean expression `(start < stop)`.
    - Handles ascending and descending ranges, including negative numbers.
    - Fully portable across Free Pascal, Delphi, and PascalScript.
    - Equivalent in behavior to `if start <= stop then Result := start else Result := stop;` 
      or `Result := Min(start, stop);`.
[==============================================================================}
function TRange.Bottom: Integer; overload;
begin
  case (Self.start < Self.stop) of
    True:  Result := Self.start;
    False: Result := Self.stop;
  end;
end;

{==============================================================================]
  <First>
  @action: Returns the smaller of start and stop, regardless of order.
  @note: Can be computed branchlessly using arithmetic: (start + stop - Abs(start - stop)) div 2.
         Equivalent to Low/Min. Watch for potential integer overflow.
[==============================================================================}
function TRange.First: Integer; overload;
begin
  Result := (((Self.start + Self.stop) - Abs(Self.start - Self.stop)) div 2);
end;

{==============================================================================]
  <Higher>
  @action: Returns the larger of `start` and `stop` (the upper bound of the range).
  @note: Implemented using a branchless bitwise arithmetic trick.
[==============================================================================}
function TRange.Higher: Integer; overload;
begin
  Result := ((Self.start * Ord(Self.start >= Self.stop)) + (Self.stop * Ord(Self.start < Self.stop)));
end;

{==============================================================================]
  <Highest>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Highest: Integer;
begin
  Result := Max(Self.stop, Self.start);
end;

{==============================================================================]
  <Last>
  @action: Returns the larger of start and stop, regardless of order.
  @note: Can be computed branchlessly using arithmetic: (start + stop + Abs(start - stop)) div 2.
         Equivalent to High/Max. Watch for potential integer overflow.
[==============================================================================}
function TRange.Last: Integer; overload;
begin
  Result := (((Self.start + Self.stop) + Abs(Self.start - Self.stop)) div 2);
end;

{==============================================================================]
  <Left>
  @action: Returns the lower endpoint of the range, regardless of whether the
           original start/stop values form an ascending or descending range.
  @note: This is a derived, normalized boundary. It does not reflect the
         caller’s declared direction; it always represents the smaller value.
[==============================================================================}
function TRange.Left: Integer; overload;
begin
  Result := IfThen((Self.start <= Self.stop), Self.start, Self.stop);
end;

{==============================================================================]
  <Lower>
  @action: Returns the smaller of `start` and `stop` (the lower bound of the range).
  @note: Implemented using a branchless bitwise arithmetic trick.
[==============================================================================}
function TRange.Lower: Integer; overload;
begin
  Result := ((Self.start * Ord(Self.start <= Self.stop)) + (Self.stop * Ord(Self.start > Self.stop)));
end;

{==============================================================================]
  <Lowest>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Lowest: Integer;
begin
  Result := Min(Self.start, Self.stop);
end;

{==============================================================================]
  <Maxima>
  @action: Returns the larger of `start` and `stop`, regardless of ordering.
  @note: Implements a branchless maximum operation using bitwise arithmetic.
[==============================================================================}
function TRange.Maxima: Integer;
begin
  Result := (Self.start xor ((Self.start xor Self.stop) and ((Self.start - Self.stop) shr 31)));
end;

{==============================================================================]
  <Maximal>
  @action: Returns the larger of the two endpoints (`start` and `stop`) of the range.
           Effectively, this is the right-side of the range on a number line.
  @note:
    - Uses a branchless array indexing trick.
    - Works for ranges where start <= stop (ascending) or start > stop (descending).
    - Equivalent to Max(Self.start, Self.stop) but written without a function call.
[==============================================================================}
function TRange.Maximal: Integer;
var
  v: TIntegerArray;
begin
  v := [Self.start, Self.stop];
  Result := v[Integer(Self.start < Self.stop)];
end;

{==============================================================================]
  <Maximum>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Maximum: Integer;
begin
  if (Self.start < Self.stop) then
    Result := Self.stop
  else
    Result := Self.start;
end;

{==============================================================================]
  <Minima>
  @action: Returns the smaller of `start` and `stop`, regardless of ordering.
  @note: Implements a branchless minimum operation using bitwise arithmetic.
[==============================================================================}
function TRange.Minima: Integer;
begin
  Result := (Self.stop xor ((Self.start xor Self.stop) and ((Self.start - Self.stop) shr 31)));
end;

{==============================================================================]
  <Minimal>
  @action: Returns the smaller of the two endpoints (`start` and `stop`) of the range.
           Effectively, this is the left-side of the range on a number line.
  @note:
    - Uses a branchless array indexing trick.
    - Works for ranges where start <= stop (ascending) or start > stop (descending).
    - Equivalent to Min(Self.start, Self.stop) but written without a function call.
[==============================================================================}
function TRange.Minimal: Integer;
var
  v: TIntegerArray;
begin
  v := [Self.start, Self.stop];
  Result := v[Integer(Self.start > Self.stop)];
end;

{==============================================================================]
  <Minimum>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Minimum: Integer;
begin
  if (Self.stop > Self.start) then
    Result := Self.start
  else
    Result := Self.stop;
end;

{==============================================================================]
  <Right>
  @action: Returns the upper endpoint of the range, independent of the direction
           in which the range was specified.
  @note: This value is always the larger of start/stop. It defines the
         normalized right-hand boundary used for length calculations
         and ordered interval operations.
[==============================================================================}
function TRange.Right: Integer; overload;
begin
  Result := IfThen((Self.start >= Self.stop), Self.start, Self.stop);
end;

{==============================================================================]
  <Top>
  @action: Returns the larger of `start` and `stop` (the upper bound of the range).
  @note:
    - Implemented using a `case` statement on the Boolean expression `(stop > start)`.
    - Handles ascending and descending ranges, including negative numbers.
    - Fully portable across Free Pascal, Delphi, and PascalScript.
    - Equivalent in behavior to `if start >= stop then Result := start else Result := stop;`
      or `Result := Max(start, stop);`.
[==============================================================================}
function TRange.Top: Integer; overload;
begin
  case (Self.stop > Self.start) of
    True: Result := Self.stop;
    False: Result := Self.start;
  end;
end; 
{$ENDIF}