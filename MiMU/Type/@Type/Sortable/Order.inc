{$IFDEF FUNCTIONS}
function Order3(const A, B, C: MType): Integer; overload;
function Triorder(const A, B, C: MType): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Order3>
  @action: Returns an integer code indicating the sorting state of three items.
  @note: Returns 1 if the items are strictly or non-strictly ascending (A <= B <= C).
         Returns -1 if the items are strictly or non-strictly descending (A >= B >= C).
         Returns 0 if all items are equal, or if the values are unsorted/mixed.
[==============================================================================}
function Order3(const A, B, C: MType): Integer; overload;
begin
  if ((A = B) and (B = C)) then
    Exit(0);
  if ((A <= B) and (B <= C)) then
    Exit(1);
  if ((A >= B) and (B >= C)) then
    Exit(-1);
  Result := 0;
end;

{==============================================================================]
  <Triorder>
  @action: Determines the sorting order or monotonicity of three values (A, B, C).
  @note: Returns 1 for ascending/non-decreasing order, -1 for descending/non-increasing order, and 0 if the values are unordered or fluctuating.
[==============================================================================}
function Triorder(const A, B, C: MType): Integer; overload;
begin
  if ((A <= B) and (B <= C)) then
    Result := 1
  else if ((A >= B) and (B >= C)) then
    Result := -1
  else
    Result := 0;
end;
{$ENDIF}
