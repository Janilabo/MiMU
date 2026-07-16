{$IFDEF HELPERS}
function Among(const items: MArray): Boolean; overload;
function Amongst(const items: MArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Among>
  @action: Determines whether the current value matches any of the discrete
           elements provided in an array collection.
  @note: Useful for checking membership against a specific, non-contiguous set
         of values (e.g., matching mathematical powers or specific state IDs).
[==============================================================================}
function MTypeHelper.Among(const items: MArray): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(items) do
    if (Self = items[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Amongst>
  @action: Checks if the current MType instance matches any element contained 
           within a given array of MType structures.
  @note: Uses a highly efficient, branchless reverse-traversal loop powered by 
         an inlined generic Iff selector. If a match occurs, the loop index 
         is mathematically plunged deep into the negative spectrum (via a max 
         32-bit signed integer subtraction), causing immediate loop exit 
         without CPU branch mispredictions.
[==============================================================================}
function MTypeHelper.Amongst(const items: MArray): Boolean; overload;
var
  i: Integer;
begin
  i := High(items);
  while (i > -1) do
    i := (i - specialize Iff<Integer>((Self = items[i]), 2147483647, 1));
  Result := (i < -1);
end;
{$ENDIF}
