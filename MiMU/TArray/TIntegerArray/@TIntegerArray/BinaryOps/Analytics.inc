{$IFDEF HELPERS}
function BinaryQuantile(const aProbability: Double = 0.5): Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryQuantile>
  @action: Returns the quantile value corresponding to the specified probability
           using linear interpolation between adjacent elements of a sorted
           integer array.
  @note: The array must be sorted in ascending order. If the array is empty
         the function returns 0.0. The probability should normally be in the
         range [0,1] (e.g. 0.5 = median).
[==============================================================================}
function TIntegerArrayHelper.BinaryQuantile(const aProbability: Double = 0.5): Double; overload;
var
  p: Double;
  l, h, s: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit(0.0);
  p := (aProbability * (s - 1));
  l := Trunc(p);
  h := Ceil(p);
  if (l = h) then
    Result := Self[l]
  else
    Result := (Self[l] + (p - l) * (Self[h] - Self[l]));
end;
{$ENDIF}
