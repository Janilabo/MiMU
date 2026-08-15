{$IFDEF HELPERS}
function GetMinMax(var AMin, AMax: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <GetMinMax>
  @action: Computes the inclusive range (minimum and maximum values) of the 
           array in a single linear pass.
  @note: 
    - Returns True if the array contains elements; otherwise returns False.
    - Uses Math.Min and Math.Max which can be faster than branching on 
      modern CPUs.
    - Complexity: O(n) time, O(1) space.
    - If the array has one element, AMin and AMax will be equal.
[==============================================================================}
function MArrayHelper.GetMinMax(var AMin, AMax: MType): Boolean; overload;
var
  i: Integer;
  s: MType;
begin
  Result := (Self.Length > 0);
  if not Result then
    Exit;
  AMin := Self[0];
  AMax := Self[0];
  for i := 1 to High(Self) do
  begin
    s := Self[i];
    AMin := Min(AMin, s);
    AMax := Max(AMax, s);
  end;
end;
{$ENDIF}
