{==============================================================================]
 <Boolean_Random>
 @action: Returns random boolean.
 @note: None
[==============================================================================}

function Boolean_Random: Boolean; cdecl; inline;
begin
  Result := (Random(2) = 0);
end;

{==============================================================================]
 <Boolean_X>
 @action: If (X = True) then Result := trueX else Result := falseX; 
 @note: Returns trueX or falseX based on the X-condition.
[==============================================================================}

function Boolean_X(const X: Boolean; const trueX, falseX: Boolean): Boolean; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: Int32): Int32; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: Int64): Int64; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: Double): Double; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: string): string; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: Char): Char; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: TPoint): TPoint; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: TBox): TBox; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: TRange): TRange; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;