{$IFDEF HELPERS}
function Which(const A, B: MType): Integer; overload;
function Which(const A, B, C: MType): Integer; overload;
function Which(const A, B, C, D: MType): Integer; overload;
function Which(const N: MArray; const fallback: Integer = -1): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Which>
  @action: Returns the zero-based index of Self among two options (A=0, B=1), or -1 if unmapped.
  @note: Evaluates sequentially from left to right and returns on the first match.
[==============================================================================}
function MTypeHelper.Which(const A, B: MType): Integer; overload;
begin
  if (Self = A) then
    Result := 0
  else if (Self = B) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Which>
  @action: Returns the zero-based index of Self among three options (A=0, B=1, C=2), or -1 if unmapped.
  @note: Evaluates sequentially from left to right and returns on the first match.
[==============================================================================}
function MTypeHelper.Which(const A, B, C: MType): Integer; overload;
begin
  if (Self = A) then
    Result := 0
  else if (Self = B) then
    Result := 1
  else if (Self = C) then
    Result := 2
  else
    Result := -1;
end;

{==============================================================================]
  <Which>
  @action: Returns the zero-based index of Self among four options (A=0, B=1, C=2, D=3), or -1 if unmapped.
  @note: Evaluates sequentially from left to right and returns on the first match.
[==============================================================================}
function MTypeHelper.Which(const A, B, C, D: MType): Integer; overload;
begin
  if (Self = A) then
    Result := 0
  else if (Self = B) then
    Result := 1
  else if (Self = C) then
    Result := 2
  else if (Self = D) then
    Result := 3
  else
    Result := -1;
end;

{==============================================================================]
  <Which>
  @action: Searches for Self within an array of targets and returns its zero-based index.
  @note: Returns the specified fallback value (defaulting to -1) if no matching element is found.
[==============================================================================}
function MTypeHelper.Which(const N: MArray; const fallback: Integer = -1): Integer; overload;
begin
  for Result := 0 to High(N) do
    if (Self = N[Result]) then
	  Exit;
  Result := fallback;
end;
{$ENDIF}
