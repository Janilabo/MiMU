{$IFDEF HELPERS}
function Alike(const A, B: MType): Integer; overload;
function Alike(const A, B, C: MType): Integer; overload;
function Alike(const A, B, C, D: MType): Integer; overload;
function Alike(const N: MArray; const fallback: Integer = -1): Integer; overload;
function Hindmost(const A, B: MType): Integer; overload;
function Hindmost(const A, B, C: MType): Integer; overload;
function Hindmost(const A, B, C, D: MType): Integer; overload;
function Hindmost(const N: MArray; const fallback: Integer = -1): Integer; overload;
function Unalike(const A, B: MType): Integer; overload;
function Unalike(const A, B, C: MType): Integer; overload;
function Unalike(const A, B, C, D: MType): Integer; overload;
function Unalike(const N: MArray; const fallback: Integer = -1): Integer; overload;
function Which(const A, B: MType): Integer; overload;
function Which(const A, B, C: MType): Integer; overload;
function Which(const A, B, C, D: MType): Integer; overload;
function Which(const N: MArray; const fallback: Integer = -1): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Alike>
  @action: Returns the zero-based index of Self among two options (A=0, B=1), or -1 if unmapped.
  @note: Evaluates sequentially from left to right and returns on the first match.
[==============================================================================}
function MTypeHelper.Alike(const A, B: MType): Integer; overload;
begin
  if (Self = A) then
    Exit(0);
  if (Self = B) then
    Exit(1);
  Result := -1;
end;

{==============================================================================]
  <Alike>
  @action: Returns the zero-based index of Self among three options (A=0, B=1, C=2), or -1 if unmapped.
  @note: Evaluates sequentially from left to right and returns on the first match.
[==============================================================================}
function MTypeHelper.Alike(const A, B, C: MType): Integer; overload;
begin
  if (Self = A) then
    Exit(0);
  if (Self = B) then
    Exit(1);
  if (Self = C) then
    Exit(2);
  Result := -1;
end;

{==============================================================================]
  <Alike>
  @action: Returns the zero-based index of Self among four options (A=0, B=1, C=2, D=3), or -1 if unmapped.
  @note: Evaluates sequentially from left to right and returns on the first match.
[==============================================================================}
function MTypeHelper.Alike(const A, B, C, D: MType): Integer; overload;
begin
  if (Self = A) then
    Exit(0);
  if (Self = B) then
    Exit(1);
  if (Self = C) then
    Exit(2);
  if (Self = D) then
    Exit(3);
  Result := -1;
end;

{==============================================================================]
  <Alike>
  @action: Searches for Self within an array of targets and returns its zero-based index.
  @note: Returns the specified fallback value (defaulting to -1) if no matching element is found.
[==============================================================================}
function MTypeHelper.Alike(const N: MArray; const fallback: Integer = -1): Integer; overload;
begin
  Result := N.Pos(Self);
  if (Result = -1) then 
    Result := fallback;
end;

{==============================================================================]
  <Hindmost>
  @action: Returns the zero-based index of Self among two options (A=0, B=1), or -1 if unmapped.
  @note: Identical mapping to Which, but evaluated so that if multiple options are
  equal to one another, the later-declared option wins (right-to-left resolution).
[==============================================================================}
function MTypeHelper.Hindmost(const A, B: MType): Integer; overload;
begin
  if (Self = B) then
    Result := 1
  else if (Self = A) then
    Result := 0
  else
    Result := -1;
end;

{==============================================================================]
  <Hindmost>
  @action: Returns the zero-based index of Self among three options (A=0, B=1, C=2), or -1 if unmapped.
  @note: Identical mapping to Which, but evaluated right-to-left so ties resolve to the later option.
[==============================================================================}
function MTypeHelper.Hindmost(const A, B, C: MType): Integer; overload;
begin
  if (Self = C) then
    Result := 2
  else if (Self = B) then
    Result := 1
  else if (Self = A) then
    Result := 0
  else
    Result := -1;
end;

{==============================================================================]
  <Hindmost>
  @action: Returns the zero-based index of Self among four options (A=0, B=1, C=2, D=3), or -1 if unmapped.
  @note: Identical mapping to Which, but evaluated right-to-left so ties resolve to the later option.
[==============================================================================}
function MTypeHelper.Hindmost(const A, B, C, D: MType): Integer; overload;
begin
  if (Self = D) then
    Result := 3
  else if (Self = C) then
    Result := 2
  else if (Self = B) then
    Result := 1
  else if (Self = A) then
    Result := 0
  else
    Result := -1;
end;

{==============================================================================]
  <Hindmost>
  @action: Searches for Self within an array of targets and returns the index of the LAST matching element.
  @note: Scans back-to-front; returns the specified fallback value (defaulting to -1) if no match is found.
[==============================================================================}
function MTypeHelper.Hindmost(const N: MArray; const fallback: Integer = -1): Integer; overload;
begin
  for Result := High(N) downto 0 do
    if (Self = N[Result]) then
      Exit;
  Result := fallback;
end;

{==============================================================================]
  <Unalike>
  @action: Returns the zero-based index of the first of two options that Self does NOT equal, or -1 if Self equals both.
  @note: Mirror-image of Alike; evaluates sequentially left to right, returning on the first mismatch.
[==============================================================================}
function MTypeHelper.Unalike(const A, B: MType): Integer; overload;
begin
  if (Self <> A) then
    Exit(0);
  if (Self <> B) then
    Exit(1);
  Result := -1;
end;

{==============================================================================]
  <Unalike>
  @action: Returns the zero-based index of the first of three options that Self does NOT equal, or -1 if Self equals all.
  @note: Mirror-image of Alike; evaluates sequentially left to right, returning on the first mismatch.
[==============================================================================}
function MTypeHelper.Unalike(const A, B, C: MType): Integer; overload;
begin
  if (Self <> A) then
    Exit(0);
  if (Self <> B) then
    Exit(1);
  if (Self <> C) then
    Exit(2);
  Result := -1;
end;

{==============================================================================]
  <Unalike>
  @action: Returns the zero-based index of the first of four options that Self does NOT equal, or -1 if Self equals all.
  @note: Mirror-image of Alike; evaluates sequentially left to right, returning on the first mismatch.
[==============================================================================}
function MTypeHelper.Unalike(const A, B, C, D: MType): Integer; overload;
begin
  if (Self <> A) then
    Exit(0);
  if (Self <> B) then
    Exit(1);
  if (Self <> C) then
    Exit(2);
  if (Self <> D) then
    Exit(3); 
  Result := -1;
end;

{==============================================================================]
  <Unalike>
  @action: Searches an array of targets and returns the index of the first element Self does NOT equal.
  @note: Returns the specified fallback value (defaulting to -1) if Self equals every element (or the array is empty).
[==============================================================================}
function MTypeHelper.Unalike(const N: MArray; const fallback: Integer = -1): Integer; overload;
begin
  for Result := 0 to High(N) do
    if (Self <> N[Result]) then
      Exit;
  Result := fallback;
end;

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
