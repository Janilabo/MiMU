{$IFDEF HELPERS}
function Assign(const item: MType): MType; overload;
function IO(const input, output: MType): MType; overload;
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
  <IO>
  @action: Simultaneously assigns an input value to the instance (Self) 
           and returns a distinct output value.
  @note: Used as a fluent inline initializer to collapse multiple variable 
         assignments into a single expression (e.g., initializing loop counters 
         and bounds at the same time).
[==============================================================================}
function MTypeHelper.IO(const input, output: MType): MType; overload;
begin
  Self := input;
  Result := output;
end;
{$ENDIF}