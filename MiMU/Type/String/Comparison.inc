{$IFDEF HELPERS}
function Compare(const target: string): Integer; inline;
function Sign(const target: string): Integer; inline;
function Precede(const target: string; const aAscending: Boolean): Boolean; overload;
function Ascending(const target: string): Boolean; inline;
function Descending(const target: string): Boolean; inline;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Max(const a, b: string): string; overload; inline;
function Min(const a, b: string): string; overload; inline;
function Comparison(const A, B: string): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Compare>
  @action: Compares str with target.
  @note: Results: 0=EQUAL, 1=str>target, -1=str<target
[==============================================================================}
function TStringHelper.Compare(const target: string): Integer; inline;
begin
  if (Self = target) then
    Exit(0);
  if (Self > target) then
    Result := 1
  else
    Result := -1;
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
function TStringHelper.Sign(const target: string): Integer; inline;
begin
  if (Self = target) then
    Result := 0
  else if (Self < target) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TStringHelper.Precede(const target: string; const aAscending: Boolean): Boolean; overload;
begin
  Result := ((aAscending and (Self <= target)) or ((not aAscending) and (Self >= target)));
end;

{==============================================================================]
  <Ascending>
  @action  Returns True if the helper’s value is less than or equal to         
           the given target value. Useful as a comparison predicate when        
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TStringHelper.Ascending(const target: string): Boolean; inline;
begin
  Result := (Self <= target);
end;

{==============================================================================]
  <Descending>
  @action: Returns True if the helper’s value is greater than or equal to
           the given target value. Use as a comparison predicate when
           sorting or merging arrays in descending order.
  @note: Pure comparison only; equivalent to Self >= target.
[==============================================================================}
function TStringHelper.Descending(const target: string): Boolean; inline;
begin
  Result := (Self >= target);
end;

function Max(const A, B: string): string; overload; inline;
begin
  if (A > B) then
    Result := A
  else
    Result := B;
end;

function Min(const A, B: string): string; overload; inline;
begin
  if (A < B) then
    Result := A
  else
    Result := B;
end;

function Comparison(const A, B: string): Integer; overload;
begin
  if (A < B) then
    Exit(-1);
  if (A > B) then
    Exit(1);
  Result := 0;
end;
{$ENDIF}
