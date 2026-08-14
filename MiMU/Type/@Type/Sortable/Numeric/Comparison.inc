{$IFDEF HELPERS}
function Comp(const target: MType): Integer; overload;
function CompareEx(const target: MType; const tolerance: MType = 0): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Comp>
  @action: Computes a clean three-way comparison between Self and a target 
           value using the sign of their mathematical difference.
  @note: Returns -1 if Self is less than target, 1 if greater, and 0 if equal. 
         By passing the arithmetic delta directly to the Sign function, this 
         method achieves zero-branch evaluation without the overhead of 
         lookup tables or conditional wrappers.
[==============================================================================}
function MTypeHelper.Comp(const target: MType): Integer; overload;
begin
  Result := Sign(Self - target);
end;

{==============================================================================]
  <CompareEx>
  @action: Returns True if the helper’s value is less than or equal to
           the given target value. Useful as a comparison predicate when
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function MTypeHelper.CompareEx(const target: MType; const tolerance: MType = 0): Integer; overload;
begin
  if (Abs(Self - target) <= tolerance) then
    Result := 0
  else if (Self < target) then
    Result := -1
  else
    Result := 1;
end;
{$ENDIF}
