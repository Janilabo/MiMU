{$IFDEF HELPERS}
function Advance: Boolean; overload;
function Progress: Boolean; overload;
function Regress: Boolean; overload;
function Retreat: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Advance>
  @action: Shifts the integer one unit outward from zero based on its current sign 
           (increments positive values, decrements negative values). Returns True 
           if the value was shifted, or False if the value was already 0.
  @note: In-place mutation. Uses an explicit early-exit conditional path. Treats 0 
         as a neutral state that lacks a heading, leaving it unchanged.
[==============================================================================}
function TIntegerHelper.Advance: Boolean; overload;
begin
  if (Self = 0) then
    Exit(False)
  else if (Self > 0) then
    Inc(Self)
  else
    Dec(Self);
  Result := True;
end;

{==============================================================================]
  <Progress>
  @action: Moves the integer one unit further away from zero based on its current sign.
           Returns True if mutated, or False if the number is 0.
  @note: In-place mutation. Uses a modern, predicate-first assignment style to pre-calculate 
         the Result flag before evaluating directional sign branching.
[==============================================================================}
function TIntegerHelper.Progress: Boolean; overload;
begin
  Result := (Self <> 0);
  if not Result then
    Exit;
  if (Self > 0) then
    Inc(Self)
  else
	Dec(Self);
end;

{==============================================================================]
  <Regress>
  @action: Moves the integer one unit closer to zero based on its current sign.
           Returns True if mutated, or False if the number is already 0.
  @note: In-place mutation. Uses a modern, predicate-first assignment style to pre-calculate 
         the Result flag before evaluating directional sign branching. Excellent for 
         handling state decay or cooling down metrics.
[==============================================================================}
function TIntegerHelper.Regress: Boolean; overload;
begin
  Result := (Self <> 0);
  if not Result then
    Exit;
  if (Self > 0) then 
    Dec(Self) 
  else 
    Inc(Self);
end;

{==============================================================================]
  <Retreat>
  @action: Shifts the integer one unit inward toward zero based on its current sign 
           (decrements positive values, increments negative values). Returns True 
           if the value was shifted, or False if the value was already 0.
  @note: In-place mutation. Uses an explicit early-exit conditional path. Treats 0 
         as an absolute home base or floor that cannot be pulled back any further.
[==============================================================================}
function TIntegerHelper.Retreat: Boolean; overload;
begin
  if (Self = 0) then
    Exit(False)
  else if (Self < 0) then
    Inc(Self)
  else
    Dec(Self);
  Result := True;
end;
{$ENDIF}
