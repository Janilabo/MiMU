{$IFDEF HELPERS}
function Firsty: MType; overload;
function Firsty(const null: MType): MType; overload;
function Heady: MType; overload;
function Lasty: MType; overload;
function Lasty(const null: MType): MType; overload;
function Taily: MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Firsty>
  @action: Returns the first element (index 0) of the array.
  @note: If the array is empty, the function returns an uninitialized or 
         default value.
[==============================================================================}
function MArrayHelper.Firsty: MType; overload;
begin
  if (Self.Length > 0) then
    Result := Self[0];
end;

{==============================================================================]
  <Firsty>
  @action: Returns the first element of the array, or a provided 
           fallback value if the array is empty.
  @note: Returns null with empty arrays.
[==============================================================================}
function MArrayHelper.Firsty(const null: MType): MType; overload;
begin
  if Self.Empty then
    Result := null
  else
    Result := Self[0];
end;

{==============================================================================]
  <Heady>
  @action: Returns the head (first element) of the array.
  @note: Fast access via index 0. Will throw an out-of-bounds error if the 
         array is completely empty.
[==============================================================================}
function MArrayHelper.Heady: MType; overload;
begin
  Result := Self[0];
end;

{==============================================================================]
  <Lasty>
  @action: Returns the last element of the array.
  @note: If the array is empty, the function returns an uninitialized or 
         default value for MType.
[==============================================================================}
function MArrayHelper.Lasty: MType; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (l > 0) then
    Result := Self[l - 1];
end;

{==============================================================================]
  <Lasty>
  @action: Returns the last element of the array, or a provided fallback 
           value if the array is empty.
  @note: Safe alternative to the parameterless Lasty when dealing with empty arrays.
[==============================================================================}
function MArrayHelper.Lasty(const null: MType): MType; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Result := null
  else
    Result := Self[l - 1];
end;

{==============================================================================]
  <Taily>
  @action: Returns the tail (last element) of the array.
  @note: Uses High() to target the final index. Will throw a range check error 
         if the array is empty.
[==============================================================================}
function MArrayHelper.Taily: MType; overload;
begin
  Result := Self[High(Self)];
end;
{$ENDIF}
