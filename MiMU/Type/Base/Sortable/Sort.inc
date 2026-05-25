{$IFDEF FUNCTIONS}
function Sort3(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
function Trisort(var A, B, C: MType; const oAscending: Boolean = True): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Sort3>
  @action: Sorts three values in place
  @note: Uses bubble-sort logic optimized for 3 elements
[==============================================================================}
function Sort3(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
  function F(var X, Y: MType): Byte;
  begin
    Result := Byte((oAscending and (X > Y)) or ((not oAscending) and (X < Y)));
    if (Result = 1) then
      Swap(X, Y);
  end;
begin
  Result := ((F(A, B) + F(B, C) + F(A, B)) > 0);
end;

{==============================================================================]
  <Trisort>
  @action: Reorders three mutable variables in-place using a 3-element sorting network.
  @note: Since A, B, and C are passed as reference parameters (`var`), their original values 
         are permanently updated. `oAscending` switches the order direction.
  @result: The first element of the newly sorted sequence (the minimum value if 
           `oAscending` is True, or the maximum value if `oAscending` is False).
[==============================================================================}
function Trisort(var A, B, C: MType; const oAscending: Boolean = True): MType; overload;
var
  D: MType;
begin
  if ((oAscending and (A > B)) or ((not oAscending) and (A < B))) then
    Swap(A, B);
  if ((oAscending and (B > C)) or ((not oAscending) and (B < C))) then
    Swap(B, C);
  if ((oAscending and (A > B)) or ((not oAscending) and (A < B))) then
    Swap(A, B);
  Result := A;
end;
{$ENDIF}