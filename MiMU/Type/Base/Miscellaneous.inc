{$IFDEF FUNCTIONS}
function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload;
function Lefreq(const A, B, C: MType): MType; overload;
function Mofreq(const A, B, C: MType): MType; overload;
function Resift(const A, B, C: MType; const reference: MType): MType; overload;
function Sift(const A, B, C: MType; const reference: MType): MType; overload;
function Swap(var A, B: MType): Boolean; overload;
{$ENDIF}

{$IFDEF HELPERS}
function AsIs(out output: MType): MType; overload;
function Now(out target: MType): MType; overload;
function Svvap(var target: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsIs>
  @action: Copies the current type instance (Self) into the out parameter 'output' using the Assign method,
           then returns the output parameter as the function result.
  @note:   The 'out' modifier means 'output' is treated as uninitialized upon entry;
           the Assign method must handle this correctly (e.g., by creating or clearing the target instance).
		   The returned value is the same as 'output', allowing chaining or immediate use.
		   This overload likely complements other AsIs overloads with different parameter types.
[==============================================================================}
function MTypeHelper.AsIs(out output: MType): MType; overload;
begin
  Result := output.Assign(Self);
end;

{==============================================================================]
  <IfThen>
  @action: Returns one of two values depending on the evaluation of a boolean expression.
  @note: Acts as a functional ternary operator. Both source values must be of the same type.
[==============================================================================}
function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload;
begin
  if state then
    Result := sTrue
  else
    Result := sFalse;
end;

{==============================================================================]
  <Lefreq>
  @action: Returns the least frequent (minority) value among three arguments.
  @note: If all three values are unique, the first argument (A) is returned as the default tie-breaker.
[==============================================================================}
function Lefreq(const A, B, C: MType): MType; overload;
begin
  if (A = B) then
    Result := C
  else if (A = C) then
    Result := B
  else if (B = C) then
    Result := A
  else
    Result := A;
end;

{==============================================================================]
  <Mofreq>
  @action: Returns the most frequent (majority) value among three arguments.
  @note: If all three values are unique, the first argument (A) is returned as the default tie-breaker.
[==============================================================================}
function Mofreq(const A, B, C: MType): MType; overload;
begin
  if ((A = B) or (A = C)) then
    Result := A
  else if (B = C) then
    Result := B
  else
    Result := A;
end;

{==============================================================================]
  <Now>
  @action: Captures the current value of the instance into the out parameter
           and returns the instance unchanged (Self).
  @param: target Receives a copy of the current value.
  @return: The original instance (Self) for method chaining.
  @note: Does not mutate Self. Useful for saving state before a series of
         mutations, e.g.: Value.Now(saved).Assign(New).Clear;
[==============================================================================}
function MTypeHelper.Now(out target: MType): MType; overload;
begin
  target := Self;
  Result := Self;
end;

{==============================================================================]
  <Resift>
  @action: Returns the first argument from the right that differs from a specified reference value, falling back to the initial argument.
  @note: Evaluates arguments sequentially in reverse order (C, then B). If both match the reference, the default fallback (A) is returned.
[==============================================================================}
function Resift(const A, B, C: MType; const reference: MType): MType; overload;
begin
  if (C <> reference) then
    Result := C
  else if (B <> reference) then
    Result := B
  else
    Result := A;
end;

{==============================================================================]
  <Sift>
  @action: Returns the first argument that differs from a specified reference value, falling back to the final argument.
  @note: Evaluates arguments sequentially (A, then B). If both match the reference, the default fallback (C) is returned.
[==============================================================================}
function Sift(const A, B, C: MType; const reference: MType): MType; overload;
begin
  if (A <> reference) then
    Result := A
  else if (B <> reference) then
    Result := B
  else
    Result := C;
end;

{==============================================================================]
  <Swap>
  @action: Exchanges the values of two variables and returns whether an actual change took place.
  @note: The boolean result is True if the initial values were different, and False if they were already identical.
[==============================================================================}
function Swap(var A, B: MType): Boolean; overload;
var
  C: MType;
begin
  Result := (A <> B);
  C := A;
  A := B;
  B := C;
end;

{==============================================================================]
  <Svvap>
  @action: Mutually exchanges the values of Self and Target, then returns 
           the original value of Self.
  @note: Highly efficient state-exchange pattern. Because it returns the 
         historical value of Self before the swap took place, it allows for 
         fluent "fetch-and-replace" assignment operations in a single line.
[==============================================================================}
function MTypeHelper.Svvap(var target: MType): MType; overload;
begin
  Result := Self;
  Self := target;
  target := Result;
end;
{$ENDIF}