{$IFDEF TYPES}
generic TIndexed<T> = record
  index: UInt32;
  item: T;
  constructor Create(const AIndex: UInt32; const AItem: T);
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Create>
  @action: Initializes a new TIndexed instance with a given index and item.
  @note: Assigns the position index and payload value to the record fields.
[==============================================================================}
constructor TIndexed.Create(const AIndex: UInt32; const AItem: T);
begin
  Self.index := AIndex;
  Self.item := AItem;
end;
{$ENDIF}