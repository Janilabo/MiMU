{$IFDEF HELPERS}
function IsPrime: Boolean;
function Prime: Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IsPrime>
  @action: Returns true if N is prime.
  @note: None.
[==============================================================================}
function TInt64Helper.IsPrime: Boolean;
var
  p: TInt64Array;
  i: Integer;
  j: Int64;
begin
  if (Self < 2) then
    Exit(False);
  p := [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31];
  for i := 0 to High(p) do
    if (Self = p[i]) then
      Exit(True)
    else if ((Self mod p[i]) = 0) then
      Exit(False);
  j := 30;
  repeat
    if (((Self mod j) = 0) or ((Self mod (j + 2)) = 0)) then
      Exit(False);
    Inc(j, 6);
  until ((j * j) > Self);
  Result := True;
end;

{==============================================================================]
  <Prime>
  @action: Returns true if N is prime.
  @note: None.
[==============================================================================}
function TInt64Helper.Prime: Boolean;
var
  i: Int64;
begin
  if ((Self = 2) or (Self = 3)) then
    Exit(True);
  if ((Self < 2) or ((Self mod 2) = 0) or ((Self mod 3) = 0)) then
    Exit(False);
  i := 5;
  repeat
    if (((Self mod i) = 0) or ((Self mod (i + 2)) = 0)) then
      Exit(False);
    i := (i + 6);
  until ((i * i) > Self);
  Result := True;
end;
{$ENDIF}