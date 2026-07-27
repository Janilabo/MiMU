{$IFDEF HELPERS}
function Among(const A, B: MType): Boolean; overload;
function Among(const A, B, C: MType): Boolean; overload;
function Among(const A, B, C, D: MType): Boolean; overload;
function Among(const items: MArray): Boolean; overload;
function Amongst(const items: MArray): Boolean; overload;
function Amongst(const A, B: MType): Boolean; overload;
function Amongst(const A, B, C: MType): Boolean; overload;
function Amongst(const A, B, C, D: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Among>
  @action: Returns True if Self matches either of two options.
  @note: Pure membership test; does not report position, only presence.
[==============================================================================}
function MTypeHelper.Among(const A, B: MType): Boolean; overload;
begin
  Result := ((Self = A) or (Self = B));
end;

{==============================================================================]
  <Among>
  @action: Returns True if Self matches any of three options.
  @note: Pure membership test; does not report position, only presence.
[==============================================================================}
function MTypeHelper.Among(const A, B, C: MType): Boolean; overload;
begin
  Result := ((Self = A) or (Self = B) or (Self = C));
end;

{==============================================================================]
  <Among>
  @action: Returns True if Self matches any of four options.
  @note: Pure membership test; does not report position, only presence.
[==============================================================================}
function MTypeHelper.Among(const A, B, C, D: MType): Boolean; overload;
begin
  Result := ((Self = A) or (Self = B) or (Self = C) or (Self = D));
end;

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
  @action: Checks whether Self matches any of the specified values.
  @note: Evaluates up to two parameters and short-circuits on the first match.
[==============================================================================}
function MTypeHelper.Amongst(const A, B: MType): Boolean; overload;
begin
  if not (Self = A) then
    if not (Self = B) then
	  Exit(False);
  Result := True;
end;

{==============================================================================]
  <Amongst>
  @action: Checks whether Self matches any of the specified values.
  @note: Evaluates up to three parameters and short-circuits on the first match.
[==============================================================================}
function MTypeHelper.Amongst(const A, B, C: MType): Boolean; overload;
begin
  if not (Self = A) then
    if not (Self = B) then
	  if not (Self = C) then
	    Exit(False);
  Result := True;
end;

{==============================================================================]
  <Amongst>
  @action: Checks whether Self matches any of the specified values.
  @note: Evaluates up to four parameters and short-circuits on the first match.
[==============================================================================}
function MTypeHelper.Amongst(const A, B, C, D: MType): Boolean; overload;
begin
  if not (Self = A) then
    if not (Self = B) then
	  if not (Self = C) then
	    if not (Self = D) then
	      Exit(False);
  Result := True;
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
