{$IFDEF HELPERS}
class function Andify(const aLeft, aRight: TBooleanArray): TBooleanArray; overload; static;
class function Nandify(const aLeft, aRight: TBooleanArray): TBooleanArray; overload; static;
class function Ordify(const aLeft, aRight: TBooleanArray): TBooleanArray; overload; static;
class function Xordify(const aLeft, aRight: TBooleanArray): TBooleanArray; overload; static;

function AllFalse: Boolean; overload;
function AllTrue: Boolean; overload;
function AnyFalse: Boolean; overload;
function AnyTrue: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Andify>
  @action: Performs an element-wise logical AND operation between two TBooleanArrays.
  @note: Returns an array sized to the minimum length of the two input arrays,
         containing the result of aLeft[i] and aRight[i].
[==============================================================================}
class function TBooleanArrayHelper.Andify(const aLeft, aRight: TBooleanArray): TBooleanArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Min(aLeft.Length, aRight.Length)) do
    Result[i] := (aLeft[i] and aRight[i]);
end;

{==============================================================================]
  <Nandify>
  @action: Performs an element-wise logical NAND operation between two TBooleanArrays.
  @note: Returns an array sized to the minimum length of the two input arrays,
         containing the result of not (aLeft[i] and aRight[i]).
[==============================================================================}
class function TBooleanArrayHelper.Nandify(const aLeft, aRight: TBooleanArray): TBooleanArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Min(aLeft.Length, aRight.Length)) do
    Result[i] := not (aLeft[i] and aRight[i]);
end;

{==============================================================================]
  <Ordify>
  @action: Performs an element-wise logical OR operation between two TBooleanArrays.
  @note: Returns an array sized to the minimum length of the two input arrays,
         containing the result of aLeft[i] or aRight[i].
[==============================================================================}
class function TBooleanArrayHelper.Ordify(const aLeft, aRight: TBooleanArray): TBooleanArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Min(aLeft.Length, aRight.Length)) do
    Result[i] := (aLeft[i] or aRight[i]);
end;

{==============================================================================]
  <Xordify>
  @action: Performs an element-wise logical XOR operation between two TBooleanArrays.
  @note: Returns an array sized to the minimum length of the two input arrays,
         containing the result of aLeft[i] xor aRight[i].
[==============================================================================}
class function TBooleanArrayHelper.Xordify(const aLeft, aRight: TBooleanArray): TBooleanArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Min(aLeft.Length, aRight.Length)) do
    Result[i] := (aLeft[i] xor aRight[i]);
end;

{==============================================================================]
  <AllFalse>
  @action: Checks if all elements in the boolean array are False.
  @note: Returns True only if the array is non-empty and every element is False.
         Returns False if the array is empty or contains any True value.
		 Short-circuits on the first True.
[==============================================================================}
function TBooleanArrayHelper.AllFalse: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if Self[i] then
	  Exit(False);
  Result := (Self.Length > 0);
end;

{==============================================================================]
  <AllTrue>
  @action: Checks if all elements in the boolean array are True.
  @note: Returns True only if the array is non-empty and every element is True.
         Returns False if the array is empty or contains any False value.
		 Short-circuits on the first False.
[==============================================================================}
function TBooleanArrayHelper.AllTrue: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i] then
	  Exit(False);
  Result := (Self.Length > 0);
end;

{==============================================================================]
  <AnyFalse>
  @action: Checks if at least one element in the boolean array is False.
  @note: Returns True if any element is False, and False otherwise.
         Short-circuits on the first False value.
[==============================================================================}
function TBooleanArrayHelper.AnyFalse: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i] then
	  Exit(True);
  Result := False;
end;

{==============================================================================]
  <AnyTrue>
  @action: Checks if at least one element in the boolean array is True.
  @note: Returns True if any element is True, and False otherwise. Short-circuits on the first True value.
[==============================================================================}
function TBooleanArrayHelper.AnyTrue: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if Self[i] then
	  Exit(True);
  Result := False;
end;
{$ENDIF}
