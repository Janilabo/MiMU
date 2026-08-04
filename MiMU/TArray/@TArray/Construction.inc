{$IFDEF HELPERS}
function Build(const item: MType; const aSize: Integer = 1): MArray; overload;
function Create(const item: MType): MArray; overload;
function Create(const aSize: Integer; const item: MType): MArray; overload;
function Establish(const aSize: UInt32 = 0): Boolean; overload;
class function Forge(const rItem: MType; const rSize: Integer = 1): MArray; overload; static;
function Seed(const item: MType; const rSize: Integer = 1): Integer; overload;
class function Seeded(const item: MType; const rSize: Integer = 1): MArray; overload; static;
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
  <Establish>
  @action: Allocates the array to a specified size and returns whether the resulting capacity is non-zero.
  @note: Uses `SetSize` to establish array capacity. Returns True if `aSize > 0`, otherwise False.
[==============================================================================}
function MArrayHelper.Establish(const aSize: UInt32 = 0): Boolean; overload;
begin
  Result := (Self.SetSize(aSize) > 0);
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
  for i := 0 to Result.Alloc(rSize) do
    Result[i] := rItem;
end;

{==============================================================================]
  <Seed>
  @action: Resets Self to `rSize` copies of `item`, returning the new length.
  @note: rSize < 1 empties Self; rSize = 1 sets Self to a single-element array.
[==============================================================================}
function MArrayHelper.Seed(const item: MType; const rSize: Integer = 1): Integer; overload;
var
  r: Integer;
begin
  case rSize.Compare(1) of
    -1: Self := [];
    0: Self := [item];
    1:
    for r := 0 to Self.Alloc(rSize) do
      Self[r] := item;
  end;
  Result := Self.Length;
end;

{==============================================================================]
  <Seeded>
  @action: Constructs and returns a new array of `rSize` copies of `item`.
  @note: Class-constructor sibling of `Seed`.
[==============================================================================}
class function MArrayHelper.Seeded(const item: MType; const rSize: Integer = 1): MArray; overload;
var
  r: Integer;
begin
  case rSize.Compare(1) of
    -1: Result := [];
    0: Result := [item];
    1:
    for r := 0 to Result.Alloc(rSize) do
      Result[r] := item;
  end;
end;
{$ENDIF}
