{$IFDEF HELPERS}
function Ascending(const target: Integer): Boolean; overload;
function Cmp(const target: Integer): Integer; overload;
function Cmpr(const target: Integer): Integer; overload;
function Comp(const target: Integer): Integer; overload;
function Compare(const target: Integer): Integer; overload;
function CompareAt(const target: Integer): Integer; overload;
function Compared(const target: Integer; const oAscending: Boolean = True): Integer; overload;
function CompareEx(const target: Integer; const tolerance: Integer = 0): Integer; overload;
function Comparem(const target: Integer): Integer; overload;
function CompareTo(const target: Integer; const oAscending: Boolean = True): Integer; overload;
function CompareWith(const target: Integer; const oAscending: Boolean = True): Integer; overload;
function Comparify(const target: Integer): Integer; overload;
function Descending(const target: Integer): Boolean; overload;
function Over(const target: Integer): Boolean; overload;
function Oversize(const limit: Integer): Boolean; overload;
function Precede(const target: Integer; const aAscending: Boolean): Boolean; overload;
function Under(const target: Integer): Boolean; overload;
function Undersize(const limit: Integer): Boolean; overload;
function Unsign(const target: Integer = 0): Integer; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Comparison(const A, B: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascending>
  @action  Returns True if the helper’s value is less than or equal to
           the given target value. Useful as a comparison predicate when
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TIntegerHelper.Ascending(const target: Integer): Boolean; overload;
begin
  Result := (Self <= target);
end;

{==============================================================================]
  <Cmp>
  @action: Compares x with target target.
           Results: 0=EQUAL, 1=x>target, -1=x<target
  @note: None
[==============================================================================}
function TIntegerHelper.Cmp(const target: Integer): Integer; overload;
begin
  Result := (Integer(Self > target) - Integer(Self < target));
end;

{==============================================================================]
  <Cmpr>
  @action: Compares x with target target.
           Results: 0=EQUAL, 1=x>target, -1=x<target
  @note: None
[==============================================================================}
function TIntegerHelper.Cmpr(const target: Integer): Integer; overload;
begin
  Result := (Ord(Self > target) - Ord(Self < target));
end;

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
  <Compare>
  @action: Compares x with target target.
           Results: 0=EQUAL, 1=x>target, -1=x<target
  @note: None
[==============================================================================}
function TIntegerHelper.Compare(const target: Integer): Integer; overload;
begin
  if (Self = target) then
    Exit(0);
  if (Self > target) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <CompareAt>
  @action: Performs a standard three-way (trichotomous) comparison between 
           Self and the target value.
  @note: Returns -1 if Self is less than target, 1 if Self is greater than 
         target, and 0 if both values are perfectly equal. This is highly 
         useful as a clean, predictable sorting or routing primitive.
[==============================================================================}
function TIntegerHelper.CompareAt(const target: Integer): Integer; overload;
begin
  if (Self < target) then
    Result := -1
  else if (Self > target) then
    Result := 1
  else
    Result := 0;
end;

{==============================================================================]
  <Compared>
  @action: Compares x with target value.
           Results: 0=EQUAL
  @note: Supports ascending/descending
[==============================================================================}
function TIntegerHelper.Compared(const target: Integer; const oAscending: Boolean = True): Integer; overload;
begin
  Result := (Ord(Self > target) - Ord(Self < target));
  if not oAscending then
    Result := -Result;
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
  <CompareTo>
  @action: Compares x with target value.
           Results: 0=EQUAL
  @note: Supports ascending/descending
[==============================================================================}
function TIntegerHelper.CompareTo(const target: Integer; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Exit(0);
  if oAscending then
    Result := ((Ord(Self > target) * 2) - 1)
  else
    Result := ((Ord(target > Self) * 2) - 1);
end;

{==============================================================================]
  <CompareWith>
  @action: Compares x with target value.
           Results: 0=EQUAL
  @note: Supports ascending/descending
[==============================================================================}
function TIntegerHelper.CompareWith(const target: Integer; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Exit(0);
  if oAscending then
    Result := IfThen((Self > target), 1, -1)
  else
    Result := IfThen((target > Self), 1, -1);
end;

{==============================================================================]
  <Comparify>
  @action: Transforms the relationship between Self and a target value into 
           a normalized three-way positional scalar (-1, 0, 1).
  @note: Utilizing a single-line functional fold, this method evaluates the 
         less-than condition first, falling back onto a direct integer cast 
         of the greater-than boolean expression to eliminate nesting.
[==============================================================================}
function TIntegerHelper.Comparify(const target: Integer): Integer; overload;
begin
  Result := IfThen((Self < target), -1, Integer(Self > target));
end;

{==============================================================================]
  <Descending>
  @action: Returns True if the helper’s value is greater than or equal to
           the given target value. Use as a comparison predicate when
           sorting or merging arrays in descending order.
  @note: Pure comparison only; equivalent to Self >= target.
[==============================================================================}
function TIntegerHelper.Descending(const target: Integer): Boolean; overload;
begin
  Result := (Self >= target);
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

{==============================================================================]
  <Unsign>
  @action: Reversed three-way comparison between Self and target.
           Returns the opposite sign of a standard comparison, effectively
           negating the traditional -1,0,1 result.
  @note: Returns:
          1  if Self < target  (standard comparison would return -1)
          0  if Self = target  (standard comparison returns 0)
          -1 if Self > target  (standard comparison would return 1)
         This method is semantically equivalent to: -(Self.Compare(target))
         Perfect for descending order sorting or when reversed comparison logic
         is required without inverting the entire sorting algorithm.
[==============================================================================}
function TIntegerHelper.Unsign(const target: Integer = 0): Integer; overload;
begin
  if (Self = target) then
    Result := 0
  else if (Self < target) then
    Result := 1
  else
    Result := -1;
end;

function Comparison(const A, B: Integer): Integer; overload;
begin
  if (A < B) then
    Exit(-1);
  if (A > B) then
    Exit(1);
  Result := 0;
end;
{$ENDIF}
