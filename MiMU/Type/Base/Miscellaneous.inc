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
function Broadcast(out a, b: MType): MType; overload;
function Broadcast(out a, b, c: MType): MType; overload;
function Broadcast(out a, b, c, d: MType): MType; overload;
function Broadcast(const p: array of MPointer): MType; overload;
function Coalesce(const alternative: MType): MType; overload;
function Counteract(const A, B: MType): Boolean; overload;
function Counterpart(const A, B: MType): MType; overload;
function Into(const p: array of MPointer): MType; overload;
function Now(out target: MType): MType; overload;
function Plant(const p: array of MPointer): Integer; overload;
function Store(var a: MType): MType; overload;
function Store(var a, b: MType): MType; overload;
function Store(var a, b, c: MType): MType; overload;
function Store(var a, b, c, d: MType): MType; overload;
function Store(const p: array of MPointer): MType; overload;
function Svvap(var target: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsIs>
  @action: Copies the current type instance (Self) into the out parameter 'output' using the Assign method,
           then returns the output parameter as the function result.
  @note: The 'out' modifier means 'output' is treated as uninitialized upon entry;
         the Assign method must handle this correctly (e.g., by creating or clearing the target instance).
	     The returned value is the same as 'output', allowing chaining or immediate use.
         This overload likely complements other AsIs overloads with different parameter types.
[==============================================================================}
function MTypeHelper.AsIs(out output: MType): MType; overload;
begin
  Result := output.Assign(Self);
end;

{==============================================================================]
  <Broadcast>
  @action: Copies the value of the current instance ('Self') to multiple external 
           variables or memory locations simultaneously.
  @note: This method supports two patterns: individual 'out' parameters for explicit 
         variables, and an open array of 'MPointer' types to dynamically distribute 
         the value to an arbitrary number of heap-allocated destinations while 
         safely ignoring 'nil' references.
[==============================================================================}
function MTypeHelper.Broadcast(out a, b: MType): MType; overload;
begin
  a := Self;
  b := Self;
  Result := Self;
end;

function MTypeHelper.Broadcast(out a, b, c: MType): MType; overload;
begin
  a := Self;
  b := Self;
  c := Self;
  Result := Self;
end;

function MTypeHelper.Broadcast(out a, b, c, d: MType): MType; overload;
begin
  a := Self;
  b := Self;
  c := Self;
  d := Self;
  Result := Self;
end;

function MTypeHelper.Broadcast(const p: array of MPointer): MType; overload;
var
  i: Integer;
begin
  for i := Low(p) to High(p) do
    if (p[i] <> nil) then
      p[i]^ := Self;
  Result := Self;
end;

{==============================================================================]
  <Coalesce>
  @action: Returns Self if it contains a non-default value; otherwise, returns 
           the specified alternative fallback value.
  @note: Universal type-safe null/zero safety net. Emulates database-style 
         coalescing logic, allowing fluent inline defaults for uninitialized 
         or empty variables without manual conditional nesting.
[==============================================================================}
function MTypeHelper.Coalesce(const alternative: MType): MType; overload;
begin
  if (Self <> Default(MType)) then
    Result := Self
  else
    Result := alternative;
end;

{==============================================================================]
  <Counteract>
  @action: Evaluates the value in-place against a binary pair (A and B). If it 
           matches A, it mutates to B; if it matches B, it mutates to A. 
           Returns True if a state transition occurred.
  @note: Destructive core operation. Acts as a strict domain-gated state flipper. 
         Out-of-bounds values that match neither parameter remain completely 
         unmodified and return False.
[==============================================================================}
function MTypeHelper.Counteract(const A, B: MType): Boolean; overload;
var
  S: MType;
begin
  S := Self;
  if (Self = A) then
    Self := B
  else if (Self = B) then
    Self := A;
  Result := (Self <> S);
end;

{==============================================================================]
  <Counterpart>
  @action: Evaluates the value against a binary pair (A and B) and returns its 
           matching opposite. If the value equals A, it yields B; if it equals 
           B, it yields A. Otherwise, it passes the original value through.
  @note: Pure expression function. This method operates entirely without side 
         effects, leaving the underlying instance completely unmodified.
[==============================================================================}
function MTypeHelper.Counterpart(const A, B: MType): MType; overload;
begin
  if (Self = A) then
    Result := B
  else if (Self = B) then
    Result := A
  else
    Result := Self;
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
  <Into>
  @action: Copies the current instance value ('Self') into each 'MType' memory 
           location provided in the pointer array and returns 'Self'.
  @note: Uses a clean 'for..in' enumeration to cycle through the array. Unlike the 
         'Plant' or 'Broadcast' variants, this implementation assumes all pointers 
         in the array are valid and initialized; passing a 'nil' pointer will 
         cause an access violation runtime error.
[==============================================================================}
function MTypeHelper.Into(const p: array of MPointer): MType; overload;
var
  s: MPointer;
begin
  for s in p do
    s^ := Self;
  Result := Self;
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
  <Plant>
  @action: Distributes the current instance value ('Self') to an open array of 
           'MType' pointers and returns the total number of successfully 
           updated targets.
  @note: Safely bypasses any 'nil' pointers elements within the array. The 
         returned integer reflects only the active memory locations that 
         successfully received the value, rather than the raw length of the 
         passed array.
[==============================================================================}
function MTypeHelper.Plant(const p: array of MPointer): Integer; overload;
var
  h, l, i: Integer;
begin
  h := High(p);
  l := Low(p);
  Result := ((h - l) + 1);
  for i := l to h do
    if (p[i] <> nil) then
      p[i]^ := Self
    else
      Dec(Result);
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
  <Store>
  @action: Sequentially processes and stores multiple 'MType' variables into the 
           current instance by cascading calls to the 'Now' method.
  @note: Uses a fluent, method-chaining pattern. Because the parameters are passed 
         by reference ('var'), the underlying 'Now' method may modify the passed 
         variables or update internal state dependencies between them.
[==============================================================================}
function MTypeHelper.Store(var a: MType): MType; overload;
begin
  Result := Self.Now(a);
end;

function MTypeHelper.Store(var a, b: MType): MType; overload;
begin
  Result := Self.Now(a).Now(b);
end;

function MTypeHelper.Store(var a, b, c: MType): MType; overload;
begin
  Result := Self.Now(a).Now(b).Now(c);
end;

function MTypeHelper.Store(var a, b, c, d: MType): MType; overload;
begin
  Result := Self.Now(a).Now(b).Now(c).Now(d);
end;

function MTypeHelper.Store(const p: array of MPointer): MType; overload;
var
  i: Integer;
begin
  Result := Self;
  for i := Low(p) to High(p) do
    Result := Result.Now(p[i]^);
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
