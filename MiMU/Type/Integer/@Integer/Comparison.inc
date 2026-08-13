{$IFDEF HELPERS}
function Comp(const target: Integer): Integer; overload;
function CompareEx(const target: Integer; const tolerance: Integer = 0): Integer; overload;
function Comparem(const target: Integer): Integer; overload;
function Over(const target: Integer): Boolean; overload;
function Oversize(const limit: Integer): Boolean; overload;
function Precede(const target: Integer; const aAscending: Boolean): Boolean; overload;
function Under(const target: Integer): Boolean; overload;
function Undersize(const limit: Integer): Boolean; overload;
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
function TIntegerHelper.Comp(const target: Integer): Integer; overload;
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
function TIntegerHelper.CompareEx(const target: Integer; const tolerance: Integer = 0): Integer; overload;
begin
  if (Abs(Self - target) <= tolerance) then
    Result := 0
  else if (Self < target) then
    Result := -1
  else
    Result := 1;
end;

{==============================================================================]
  <Comparem>
  @action: Performs a branchless three-way comparison between Self and the 
           target value using a pre-computed matrix lookup.
  @note: By mapping the boolean outcomes of (Self > target) and (Self < target) 
         directly into a 2x2 multi-dimensional array matrix, this method 
         eliminates conditional jump instructions (if/else). This maximizes 
         CPU pipeline efficiency in performance-critical loops or sorting algorithms.
[==============================================================================}
function TIntegerHelper.Comparem(const target: Integer): Integer; overload;
const
  COMP_MATRIX: array[Boolean, Boolean] of Integer = ((0, -1), (1, 0));
begin
  Result := COMP_MATRIX[(Self > target), (Self < target)];
end;

{==============================================================================]
  <Over>
  @action: Returns true if x is higher than target.
  @note: None
[==============================================================================}
function TIntegerHelper.Over(const target: Integer): Boolean; overload;
begin
  Result := not (target <= Self);
end;

{==============================================================================]
  <Oversize>
  @action: Returns true if x is higher than limit.
  @note: None
[==============================================================================}
function TIntegerHelper.Oversize(const limit: Integer): Boolean; overload;
begin
  Result := (Self > limit);
end;

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TIntegerHelper.Precede(const target: Integer; const aAscending: Boolean): Boolean; overload;
begin
  Result := ((aAscending and (Self <= target)) or ((not aAscending) and (Self >= target)));
end;

{==============================================================================]
  <Under>
  @action: Returns true if x is lower than target.
  @note: None
[==============================================================================}
function TIntegerHelper.Under(const target: Integer): Boolean; overload;
begin
  Result := not (target >= Self);
end;

{==============================================================================]
  <Undersize>
  @action: Returns true if x is lower than limit.
  @note: None
[==============================================================================}
function TIntegerHelper.Undersize(const limit: Integer): Boolean; overload;
begin
  Result := (Self < limit);
end;
{$ENDIF}
