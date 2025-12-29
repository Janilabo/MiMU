{$IFDEF Skeleton_Swap}
begin
  Result := (A <> B);
  C := A;
  A := B;
  B := C;
end;
{$ENDIF}

{$IFDEF Skeleton_Max}
begin
  if (A > B) then
    Result := A
  else
    Result := B;
end;
{$ENDIF}

{$IFDEF Skeleton_Min}
begin
  if (A < B) then
    Result := A
  else
    Result := B;
end;
{$ENDIF}

{$IFDEF Skeleton_Cmpr}
begin
  Result := (Ord(Self > target) - Ord(Self < target));
end;
{$ENDIF}

{$IFDEF Skeleton_Compare}
begin
  if (Self = target) then
    Exit(0);
  if (Self > target) then
    Result := 1
  else
    Result := -1;
end;
{$ENDIF}

{$IFDEF Skeleton_Compared}
begin
  Result := (Ord(Self > target) - Ord(Self < target));
  if not oAscending then
    Result := -Result;
end;
{$ENDIF}

{$IFDEF Skeleton_CompareWith}
begin
  if (Self = target) then
    Exit(0);
  if oAscending then
    Result := IfThen((Self > target), 1, -1)
  else
    Result := IfThen((target > Self), 1, -1);
end;
{$ENDIF}

{$IFDEF Skeleton_CompareTo}
begin
  if (Self = target) then
    Exit(0);
  if oAscending then
    Result := ((Ord(Self > target) * 2) - 1)
  else
    Result := ((Ord(target > Self) * 2) - 1);
end;
{$ENDIF}


{$IFDEF Skeleton_Comparison}
begin
  if (A < B) then
    Exit(-1);
  if (A > B) then
    Exit(1);
  Result := 0;
end;
{$ENDIF}

{$IFDEF Skeleton_Sign}
begin
  if (Self = target) then
    Result := 0
  else
    if (Self < target) then
      Result := 1
    else
      Result := -1;
end;
{$ENDIF}

{$IFDEF Skeleton_Precede}
begin
  Result := ((aAscending and (Self <= target)) or ((not aAscending) and (Self >= target)));
end;
{$ENDIF}

{$IFDEF Skeleton_Ascending}
begin
  Result := (Self <= target);
end;
{$ENDIF}

{$IFDEF Skeleton_Descending}
begin
  Result := (Self >= target);
end;
{$ENDIF} 

{$IFDEF Skeleton_IfThen}
begin
  if state then
    Result := sTrue
  else
    Result := sFalse;
end;
{$ENDIF}

{$IFDEF Skeleton_Select}
begin
  if Self then
    Result := bTrue
  else
    Result := bFalse;
end;
{$ENDIF}

{$IFDEF Skeleton_Evaluate}
begin
  case Self of
    True: Result := bTrue;
    False: Result := bFalse;
  end;
end;
{$ENDIF}

{$IFDEF Skeleton_Increase}
begin
  Result := Self;
  Self := (Self + N);
end;
{$ENDIF}

{$IFDEF Skeleton_IncreaseB}
begin
  Result := Self;
  if B then
    Self := (Self + 1);
end;
{$ENDIF}

{$IFDEF Skeleton_Decrease}
begin
  Result := Self;
  Self := (Self - N);
end;
{$ENDIF}

{$IFDEF Skeleton_DecreaseB}
begin
  Result := Self;
  if B then
    Self := (Self - 1);
end;
{$ENDIF}

{$IFDEF Skeleton_Increment}
begin
  Self := (Self + N);
  Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_IncrementB}
begin
  if B then
    Self := (Self + 1);
  Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_Decrement}
begin
  Self := (Self - N);
  Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_DecrementB}
begin
  if B then
    Self := (Self - 1);
  Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_ClampMin}
begin
  if (Self < limit) then
    Result := limit
  else
    Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_ClampMax}
begin
  if (Self > limit) then
    Result := limit
  else
    Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_Clamp}
begin
  if (Self < minimum) then
    Result := minimum
  else
    if(Self > maximum) then
      Result := maximum
    else
      Result := Self;
end;
{$ENDIF}

{$IFDEF Skeleton_LimitMin}
begin
  Result := Max(Self, limit);
end;
{$ENDIF}

{$IFDEF Skeleton_LimitMax}
begin
  Result := Min(Self, limit);
end;
{$ENDIF}

{$IFDEF Skeleton_Limit}
begin
  Result := EnsureRange(Self, minimum, maximum);
end;
{$ENDIF}

{$IFDEF Skeleton_ConstraintMin}
begin
  Result := (Self < limit);
  if Result then
    Self := limit;
end;
{$ENDIF}

{$IFDEF Skeleton_ConstraintMax}
begin
  Result := (Self > limit);
  if Result then
    Self := limit;
end;
{$ENDIF}

{$IFDEF Skeleton_Constraint}
begin
  Result := (Self.ConstraintMin(minimum) or Self.ConstraintMax(maximum));
end;
{$ENDIF}