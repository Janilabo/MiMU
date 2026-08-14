{$IFDEF FUNCTIONS}
function Compare(const A, B: MType): Integer; overload;
function Comparison(const A, B: MType): Integer; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Cmp(const target: MType): Integer; overload;
function Cmpr(const target: MType): Integer; overload;
function Compare(const target: MType): Integer; overload;
function CompareAt(const target: MType): Integer; overload;
function Comparem(const target: MType): Integer; overload;
function Comparify(const target: MType): Integer; overload;
function Decompare(const target: MType): Integer; overload;

function Compared(const target: MType; const oAscending: Boolean = True): Integer; overload;
function CompareTo(const target: MType; const oAscending: Boolean = True): Integer; overload;
function CompareWith(const target: MType; const oAscending: Boolean = True): Integer; overload;

function Battle(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Clash(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Compete(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Contest(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Duel(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Trial(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Versus(const target: MType; const oAscending: Boolean = True): Integer; overload;

function Asceal(const target: MType): Boolean; overload;
function Ascending(const target: MType): Boolean; overload;
function Desceal(const target: MType): Boolean; overload;
function Descending(const target: MType): Boolean; overload;

function Precede(const target: MType; const oAscending: Boolean = True): Boolean; overload;
function Succeed(const target: MType; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function Compare(const A, B: MType): Integer; overload;
begin
  if (A > B) then
    Exit(1);
  if (A < B) then
    Exit(-1);
  Result := 0;
end;

function Comparison(const A, B: MType): Integer; overload;
begin
  if (A < B) then
    Exit(-1);
  if (A > B) then
    Exit(1);
  Result := 0;
end;

{==============================================================================]
  <Cmp>
  @action: Compares Self with target target.
           Results: 0=EQUAL, 1=Self>target, -1=Self<target
  @note: None
[==============================================================================}
function MTypeHelper.Cmp(const target: MType): Integer; overload;
begin
  Result := (Integer(Self > target) - Integer(Self < target));
end;

{==============================================================================]
  <Cmpr>
  @action: Compares Self with target target.
           Results: 0=EQUAL, 1=Self>target, -1=Self<target
  @note: None
[==============================================================================}
function MTypeHelper.Cmpr(const target: MType): Integer; overload;
begin
  Result := (Ord(Self > target) - Ord(Self < target));
end;

{==============================================================================]
  <Compare>
  @action: Compares Self with target target.
           Results: 0=EQUAL, 1=Self>target, -1=Self<target
  @note: None
[==============================================================================}
function MTypeHelper.Compare(const target: MType): Integer; overload;
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
function MTypeHelper.CompareAt(const target: MType): Integer; overload;
begin
  if (Self < target) then
    Result := -1
  else if (Self > target) then
    Result := 1
  else
    Result := 0;
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
function MTypeHelper.Comparem(const target: MType): Integer; overload;
const
  COMP_MATRIX: array[Boolean, Boolean] of Integer = ((0, -1), (1, 0));
begin
  Result := COMP_MATRIX[(Self > target), (Self < target)];
end;

{==============================================================================]
  <Comparify>
  @action: Transforms the relationship between Self and a target value into 
           a normalized three-way positional scalar (-1, 0, 1).
  @note: Utilizing a single-line functional fold, this method evaluates the 
         less-than condition first, falling back onto a direct integer cast 
         of the greater-than boolean expression to eliminate nesting.
[==============================================================================}
function MTypeHelper.Comparify(const target: MType): Integer; overload;
begin
  Result := IfThen((Self < target), -1, Integer(Self > target));
end;

{==============================================================================]
  <Decompare>
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
function MTypeHelper.Decompare(const target: MType): Integer; overload;
begin
  if (Self = target) then
    Result := 0
  else if (Self < target) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Compared>
  @action: Compares Self with target value.
  @note: Supports ascending/descending
[==============================================================================}
function MTypeHelper.Compared(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := (Ord(Self > target) - Ord(Self < target));
  if not oAscending then
    Result := -Result;
end;

{==============================================================================]
  <CompareTo>
  @action: Compares Self with target value.
  @note: Supports ascending/descending
[==============================================================================}
function MTypeHelper.CompareTo(const target: MType; const oAscending: Boolean = True): Integer; overload;
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
  @action: Compares Self with target value.
  @note: Supports ascending/descending
[==============================================================================}
function MTypeHelper.CompareWith(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Exit(0);
  if oAscending then
    Result := IfThen((Self > target), 1, -1)
  else
    Result := IfThen((target > Self), 1, -1);
end;

{==============================================================================]
  <Battle>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Battle(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Result := 0
  else if oAscending then
    Result := IfThen((Self > target), 1, -1)
  else
    Result := IfThen((Self > target), -1, 1);
end;

{==============================================================================]
  <Clash>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Clash(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Result := 0
  else if (Self > target) then
    Result := ((Ord(oAscending) * 2) - 1)
  else
    Result := -((Ord(oAscending) * 2) - 1);
end;

{==============================================================================]
  <Compete>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Compete(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := (oAscending.Sign * Self.Compare(target));
end;

{==============================================================================]
  <Contest>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Contest(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Exit(0);
  if oAscending then
    if (Self > target) then
	  Exit(1)
	else
      Exit(-1);
  if (Self < target) then
    Exit(1);
  Result := -1;
end;

{==============================================================================]
  <Duel>
  @action: Compares two items honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both items are equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Duel(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := (Ord(Self > target) - Ord(Self < target));
  if not oAscending then
    Result := -Result;
end;

{==============================================================================]
  <Trial>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Trial(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Exit(0);
  if ((oAscending and (Self > target)) or ((not oAscending) and (Self < target))) then
    Exit(1);
  Result := -1;
end;

{==============================================================================]
  <Versus>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Versus(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Result := 0
  else if ((Self > target) xor (not oAscending)) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Asceal> (Asce)nding or Equ(al).
  @action: Checks if the current instance is less than or equal to the target instance.
  @note: Performs an ascending comparison inclusive of equality (Self <= target).
[==============================================================================}
function MTypeHelper.Asceal(const target: MType): Boolean; overload;
begin
  Result := (Self <= target);
end;

{==============================================================================]
  <Ascending>
  @action: Checks if the current instance is strictly less than the target instance.
  @note: Performs a strict ascending comparison (Self < target).
[==============================================================================}
function MTypeHelper.Ascending(const target: MType): Boolean; overload;
begin
  Result := (Self < target);
end;

{==============================================================================]
  <Desceal> (Desce)nding or Equ(al).
  @action: Checks if the current instance is greater than or equal to the target instance.
  @note: Performs a descending comparison inclusive of equality (Self >= target).
[==============================================================================}
function MTypeHelper.Desceal(const target: MType): Boolean; overload;
begin
  Result := (Self >= target);
end;

{==============================================================================]
  <Descending>
  @action: Checks if the current instance is strictly greater than the target instance.
  @note: Performs a strict descending comparison (Self > target).
[==============================================================================}
function MTypeHelper.Descending(const target: MType): Boolean; overload;
begin
  Result := (Self > target);
end;

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function MTypeHelper.Precede(const target: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and (Self <= target)) or ((not oAscending) and (Self >= target)));
end;

{==============================================================================]
  <Succeed>
  @action: Determines whether the current item should succeed the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self > target for ascending order or Self < target for descending order.
         Strict complement of Precede — never True when Self equals target.
[==============================================================================}
function MTypeHelper.Succeed(const target: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and (Self > target)) or ((not oAscending) and (Self < target)));
end;
{$ENDIF}
