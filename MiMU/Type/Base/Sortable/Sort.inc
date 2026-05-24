{$IFDEF FUNCTIONS}
function Sort3(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Sort3>
  @action: Sorts three values in place
   note: Uses bubble-sort logic optimized for 3 elements
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
{$ENDIF}