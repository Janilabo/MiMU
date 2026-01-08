{$IFDEF HELPERS}
function Ascending(const target: Char): Boolean; cdecl; inline;
function Compare(const target: Char): Integer; cdecl; inline;
function Descending(const target: Char): Boolean; cdecl; inline;
function Precede(const target: Char; const aAscending: Boolean): Boolean; overload; cdecl;
function Sign(const target: Char): Integer; cdecl; inline;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Comparison(const A, B: Char): Integer; overload; cdecl;
function Max(const a, b: Char): Char; overload; cdecl; inline;
function Min(const a, b: Char): Char; overload; cdecl; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascending>
  @action  Returns True if the helper’s value is less than or equal to         
           the given target value. Useful as a comparison predicate when        
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TCharHelper.Ascending(const target: Char): Boolean; cdecl; inline;
begin
  Result := (Self <= target);
end;

{==============================================================================]
  <Compare>
  @action: Compares char with target.
  @note: Results: 0=EQUAL, 1=char>target, -1=char<target
[==============================================================================}
function TCharHelper.Compare(const target: Char): Integer; cdecl; inline;
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
function TCharHelper.Descending(const target: Char): Boolean; cdecl; inline;
begin
  Result := (Self >= target);
end;

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TCharHelper.Precede(const target: Char; const aAscending: Boolean): Boolean; overload; cdecl;
begin
  Result := ((aAscending and (Self <= target)) or ((not aAscending) and (Self >= target)));
end;

{==============================================================================]
  <Sign>
  @action: Compares the current string (Self) with a target string and returns
           a directional sign indicating whether the target is greater, equal,
           or smaller than Self.
  @note: Returns:
         1  if Self < target (target is larger → ascending)
         0  if Self = target (no change)
         -1  if Self > target (target is smaller → descending)
         Useful for detecting sequence direction, ordering, or range computation.
[==============================================================================}
function TCharHelper.Sign(const target: Char): Integer; cdecl; inline;
begin
  if (Self = target) then
    Result := 0
  else if (Self < target) then
    Result := 1
  else
    Result := -1;
end;

function Comparison(const A, B: Char): Integer; overload; cdecl;
begin
  if (A < B) then
    Exit(-1);
  if (A > B) then
    Exit(1);
  Result := 0;
end;

function Max(const A, B: Char): Char; overload; cdecl; inline;
begin
  if (A > B) then
    Result := A
  else
    Result := B;
end;

function Min(const A, B: Char): Char; overload; cdecl; inline;
begin
  if (A < B) then
    Result := A
  else
    Result := B;
end;
{$ENDIF}