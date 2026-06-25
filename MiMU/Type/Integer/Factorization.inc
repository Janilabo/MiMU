{$IFDEF HELPERS}
function Divisors: TIntegerArray; overload;
function Factors: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Divisors>
  @action: Returns an array of all positive divisors of Self, including Self itself.
  @note:
    - If Self = 0, returns an empty array.
    - The divisors are calculated by iterating from 1 to Abs(Self) and checking modulo.
    - The resulting array contains only positive numbers and is in ascending order.
    - May be less efficient for large numbers compared to a square-root optimized method.
[==============================================================================}
function TIntegerHelper.Divisors: TIntegerArray; overload;
var
  a, i, r: Integer;
begin
  r := 0;
  if (Self <> 0) then
  begin
    a := Abs(Self);
    SetLength(Result, ((a div 2) + 1));
    for i := 1 to a do
      if ((Self mod i) = 0) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Factors>
  @action: Returns an array of all positive factors of Self (equivalent to divisors),
           optimized using the square root method.
  @note:
    - If Self = 0, returns an empty array.
    - Iterates from 1 to Trunc(Sqrt(Abs(Self))) to find factor pairs.
    - Adds both i and Abs(Self) div i when i divides Self.
    - Resulting array is sorted in ascending order using QuickSort.
    - More efficient than naive Divisors method for large numbers.
[==============================================================================}
function TIntegerHelper.Factors: TIntegerArray;
var
  i, r, a: Integer;
begin
  a := Abs(Self);
  if (a = 0) then
    Exit([]);
  SetLength(Result, ((a div 2) + 1));
  r := 0;
  for i := 1 to Trunc(Sqrt(a)) do
  begin
    if not ((a mod i) = 0) then
      Continue;
    Result[r.Increase] := i;
    if (i <> (a div i)) then
      Result[r.Increase] := (a div i);
  end;
  SetLength(Result, r);
  Result.QuickSort;
end;
{$ENDIF}