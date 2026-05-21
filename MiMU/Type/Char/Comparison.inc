{$IFDEF HELPERS}
function Ascending(const target: Char): Boolean;
function Compare(const target: Char): Integer;
function Descending(const target: Char): Boolean;
function Precede(const target: Char; const aAscending: Boolean): Boolean; overload;
function Unsign(const target: Char): Integer;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Comparison(const A, B: Char): Integer; overload;
function Max(const a, b: Char): Char; overload;
function Min(const a, b: Char): Char; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascending>
  @action  Returns True if the helper’s value is less than or equal to
           the given target value. Useful as a comparison predicate when
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TCharHelper.Ascending(const target: Char): Boolean;
begin
  Result := (Self <= target);
end;

{==============================================================================]
  <Compare>
  @action: Compares char with target.
  @note: Results: 0=EQUAL, 1=char>target, -1=char<target
[==============================================================================}
function TCharHelper.Compare(const target: Char): Integer;
begin
  if (Self = target) then
    Exit(0);
  if (Self > target) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Descending>
  @action: Returns True if the helper’s value is greater than or equal to
           the given target value. Use as a comparison predicate when
           sorting or merging arrays in descending order.
  @note: Pure comparison only; equivalent to Self >= target.
[==============================================================================}
function TCharHelper.Descending(const target: Char): Boolean;
begin
  Result := (Self >= target);
end;

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TCharHelper.Precede(const target: Char; const aAscending: Boolean): Boolean; overload;
begin
  Result := ((aAscending and (Self <= target)) or ((not aAscending) and (Self >= target)));
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
function TCharHelper.Unsign(const target: Char): Integer;
begin
  if (Self = target) then
    Result := 0
  else if (Self < target) then
    Result := 1
  else
    Result := -1;
end;

function Comparison(const A, B: Char): Integer; overload;
begin
  if (A < B) then
    Exit(-1);
  if (A > B) then
    Exit(1);
  Result := 0;
end;

function Max(const A, B: Char): Char; overload;
begin
  if (A > B) then
    Result := A
  else
    Result := B;
end;

function Min(const A, B: Char): Char; overload;
begin
  if (A < B) then
    Result := A
  else
    Result := B;
end;
{$ENDIF}