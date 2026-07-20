{$IFDEF HELPERS}
function Build(const item: MType; const aSize: Integer = 1): MArray; overload;
function Create(const item: MType): MArray; overload;
function Create(const aSize: Integer; const item: MType): MArray; overload;
class function Forge(const rItem: MType; const rSize: Integer = 1): MArray; overload; static;
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
  for i := 0 to Self.Alloc(Max(0, aSize)) do
    Self[i] := item;
end;

{==============================================================================]
  <Create>
  @action: Initializes a new array of a specified size, populated with a 
           default element.
  @note: If rSize is less than 1, returns an empty array. Useful for 
         pre-allocating and "priming" an array with a specific value.
[==============================================================================}
class function MArrayHelper.Forge(const rItem: MType; const rSize: Integer = 1): MArray; overload;
var
  i: Integer;
begin
  if (rSize < 1) then
    Exit([]);
  SetLength(Result, rSize);
  for i := 0 to (rSize - 1) do
    Result[i] := rItem;
end;
{$ENDIF}
