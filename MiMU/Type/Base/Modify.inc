{$IFDEF HELPERS}
function Assign(const item: MType): MType; overload;
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
{$ENDIF}