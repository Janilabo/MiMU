{$IFDEF HELPERS}
function Assign(const item: MType): MType; overload;
function Clear: MType; overload;
function Configure(const source: MType): MType; overload;
function IO(const input, output: MType): MType; overload;
function IO(const input: MType): MType; overload;
function SetIf(const condition: Boolean; const val: MType): MType; overload;
function TradeIf(const condition: Boolean; const new: MType): MType; overload;
function Xchange(const target: MType): MType; overload;
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
  <Configure>
  @action: Overwrites the state of this instance with the values from the 
           source instance via an atomic value assignment.
  @note: Returns a complete snapshot of this instance's original state prior 
         to the configuration update. Safe for managed records.
[==============================================================================}
function MTypeHelper.Configure(const source: MType): MType; overload;
var
  s: MType;
begin
  s := source;
  Result := Self;
  Self := s;
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

{==============================================================================]
  <SetIf>
  @action: Assigns val to Self if condition is True, then returns Self.
  @param: condition Boolean predicate that controls assignment.
  @param: val The value to assign when condition is True.
  @return: Self (the mutated or unchanged instance) for chaining.
  @note: Does not return the previous value. For capturing old state, use TradeIf.
[==============================================================================}
function MTypeHelper.SetIf(const condition: Boolean; const val: MType): MType; overload;
begin
  if condition then
    Self := val;
  Result := Self;
end;

{==============================================================================]
  <TradeIf>
  @action: Conditionally overwrites Self with NextValue if the condition is 
           met (True), always returning the original historical value of Self.
  @note: Highly efficient state-capture mutation pattern. Serves as a 
         conditional transaction: it updates the instance inline while 
         safely yielding the pre-mutation state for history or undo tracking.
[==============================================================================}
function MTypeHelper.TradeIf(const condition: Boolean; const new: MType): MType; overload;
begin
  Result := Self;
  if condition then
    Self := new;
end;

{==============================================================================]
  <Xchange>
  @action: Replaces the current instance with a new target value and returns the original state.
  @note: Acts as an atomic-style swap (destructive read). Essential for value types (records) to hand off state in a single line.
[==============================================================================}
function MTypeHelper.Xchange(const target: MType): MType; overload;
begin
  Result := Self;
  Self := target;
end;
{$ENDIF}