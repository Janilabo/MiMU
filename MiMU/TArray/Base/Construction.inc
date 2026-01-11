{$IFDEF HELPERS}
function Build(const item: MType; const aSize: Integer = 1): MArray; overload;
function Create(const item: MType): MArray; overload;
function Create(const aSize: Integer; const item: MType): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
 <Build> 
 @action: Creates array with item where aSize is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
function MArrayHelper.Build(const item: MType; const aSize: Integer = 1): MArray; overload;
begin
  Result := Self.Create(aSize, item);
end;

{==============================================================================]
  <Create> 
  @action: Creates array with item, size as 1. Returns old Self.
  @note: [item]
[==============================================================================}
function MArrayHelper.Create(const item: MType): MArray; overload;
begin
  Result := Self.Clone;
  SetLength(Self, 1);
  Self[0] := item;
end;

{==============================================================================]
  <Create> 
  @action: Creates array with item where aSize is length of the array. Returns old Self.
  @note: item is placed on every index in result.
[==============================================================================}
function MArrayHelper.Create(const aSize: Integer; const item: MType): MArray; overload;
var
  i: Integer;
begin
  Result := Self.Clone;
  SetLength(Self, Max(0, aSize));
  for i := 0 to High(Self) do
    Self[i] := item;
end;
{$ENDIF}