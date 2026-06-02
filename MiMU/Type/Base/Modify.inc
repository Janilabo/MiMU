{$IFDEF HELPERS}
function Assign(const item: MType): MType; overload;
function Clear: MType; overload;
function IO(const input, output: MType): MType; overload;
function IO(const input: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Assign>
  @action: Mutates the current type instance by assigning it a new item value,
           while simultaneously passing that same value through as the
           function result.
  @param: item The new item value to store and pass through.
  @return: The identical item value passed in through the item parameter.
  @note: In-place mutation of 'Self'. Designed for fluid inline assignments
         directly inside conditional statements or loop expressions.
[==============================================================================}
function MTypeHelper.Assign(const item: MType): MType; overload;
begin
  Result := item;
  Self := item;
end;

{==============================================================================]
  <Clear>
  @action: Resets the current instance to its default (zero-initialized) value
           and returns the value that was previously stored.
  @note: Uses Default(MType) to obtain the zero-initialized value for any type
         (ordinals → 0, strings → '', objects → nil, records → all fields zeroed).
         The previous value is returned, enabling state capture before clearing.
         This method mutates the instance (Self) in-place.
[==============================================================================}
function MTypeHelper.Clear: MType; overload;
begin
  Result := Self;
  Self := Default(MType);
end;

{==============================================================================]
  <IO>
  @action: Simultaneously assigns an input value to the instance (Self) 
           and returns a distinct output value.
  @note: Used as a fluent inline initializer to collapse multiple variable 
         assignments into a single expression (e.g., initializing loop counters 
         and bounds at the same time).
[==============================================================================}
function MTypeHelper.IO(const input, output: MType): MType; overload;
begin
  Result := output;
  Self := input;
end;

{==============================================================================]
  <IO>
  @action: Captures and returns the current value of the instance (Self) 
           while simultaneously updating it with a new input value.
  @note: Acts as an atomic state-transition utility. It is used to cleanly 
         extract an existing state, object reference, or resource handle 
         before overwriting it.
[==============================================================================}
function MTypeHelper.IO(const input: MType): MType; overload;
begin
  Result := Self;
  Self := input;
end;
{$ENDIF}