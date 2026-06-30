{$IFDEF HELPERS}
function Desize(out excess: MArray; const aSize: Integer = 0): Integer; overload;
function Desize(const aSize: Integer = 0): Integer; overload;
function Fit: Integer; overload;
function Fit(const aSize: Integer): Integer; overload;
function Fit(const aBounds: TRange): Integer; overload;
function GetLength: Integer; overload;
function Length: Integer; overload;
function Lengthex(const aSize: Integer = 0): Integer; overload;
function LengthTo(const N: Integer): Integer; overload;
function Relength(const aSize: Integer = 0): Integer; overload;
function Relength(out backup: MArray; const aSize: Integer = 0): Integer; overload;
function Resize(const aChange: Integer): Integer; overload;
function Resize(const aChange: Integer; const null: MType): Integer; overload;
function Resizement(const aChange: Integer = 0): Integer; overload;
function Resizement(const aChange: Integer; const null: MType): Integer; overload;
function SetLen(const aSize: Integer = 1): Integer; overload;
function SetSize(const sSize: Integer = 1): Integer; overload;
function SetSize(const sSize: Integer; const iCreated: MType): Integer; overload;
function Size: Integer; overload;
function Size(const aSize: Integer): MArray; overload;
function Size(const aSize: Integer; const null: MType): MArray; overload;
function SizeTo(const N: Integer): Integer; overload;
function Sizex(out data: MArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Desize>
  @action: Resizes the dynamic array to the specified target size. If the array 
           shrinks, the truncated elements are captured in the 'excess' array.
           Returns the net change in length (negative for shrinkage, positive for growth).
  @note: By default, if aSize is omitted, it defaults to 0 (clearing the array). 
         If the array grows or stays the same size, the 'excess' array is not 
         populated.
[==============================================================================}
function MArrayHelper.Desize(out excess: MArray; const aSize: Integer = 0): Integer; overload;
var
  s, l: Integer;
begin
  s := Max(0, aSize);
  l := Self.Length;
  Result := (s - l);
  if (l > s) then
    excess := Self.Copy(s, -Result);
  SetLength(Self, s);
end;

{==============================================================================]
  <Desize>
  @action: Resizes the dynamic array to the specified target size and returns 
           the net change in length (negative for shrinkage, positive for growth).
  @note: By default, if aSize is omitted, it defaults to 0 (clearing the array).
         This overload quickly resizes the array without preserving discarded data.
[==============================================================================}
function MArrayHelper.Desize(const aSize: Integer = 0): Integer; overload;
var
  s: Integer;
begin
  s := Max(0, aSize);
  Result := (s - Self.Length);
  SetLength(Self, s);
end;

{==============================================================================]
  <Fit>
  @action: Returns array length.
  @note: Alternative.
[==============================================================================}
function MArrayHelper.Fit: Integer; overload;
begin
  Result := ((High(Self) - Low(Self)) + 1);
end;

{==============================================================================]
  <Fit>
  @action: Resizes the array to aSize (sets length safely).
  @note: Returns the length that was set to Self. Negative sizes are clamped to 0.
[==============================================================================}
function MArrayHelper.Fit(const aSize: Integer): Integer; overload;
begin
  Result := Max(0, aSize);
  SetLength(Self, Result);
end;

{==============================================================================]
  <Fit>
  @action: Resizes the array to fit within the specified range.
  @note:
    - Returns the final array length.
    - If current length is below b.start → array grows to b.start.
    - If current length is above b.stop → array shrinks to b.stop.
    - If current length is within the range → no change.
    - Negative lengths are clamped to 0.
[==============================================================================}
function MArrayHelper.Fit(const aBounds: TRange): Integer; overload;
var
  l: Integer;
  b: TRange;
begin
  l := Self.Length;
  b := aBounds.Normalize.ClampMin(0);
  if (l < b.start) then
    Result := b.start
  else
    if (l > b.stop) then
      Result := b.stop
    else
      Result := l;	
  if (Result <> l) then
    SetLength(Self, Result);
end;

{==============================================================================]
  <GetLength>
  @action: Calculates and returns the total number of elements (the length) of the array instance.
  @note: Safely handles nil (unassigned) instances by returning 0, and uses High(Self) + 1 to determine the count.
[==============================================================================}
function MArrayHelper.GetLength: Integer; overload;
begin
  if (Self = nil) then
    Exit(0); 
  Result := (High(Self) + 1);
end;

{==============================================================================]
  <Length>
  @action: Simply Result := System.Length(arr);
  @note: None.
[==============================================================================}
function MArrayHelper.Length: Integer; overload;
begin
  Result := System.Length(Self);
end;

{==============================================================================]
  <Lengthex>
  @action: Sets the array to a new length and returns the previous length.
           The name combines "Length" with "ex" (meaning former/previous).
  @param aSize: Desired new length. If negative, the array is set to length 0.
                Default is 0, making the array empty and returning its former size.
  @return: The length of the array before the resize (the "ex‑length").
  @note: The operation is performed in‑place. Use IfThen to clamp negative values.
         Time complexity O(1) (only resizes, no element copying unless shrinking).
[==============================================================================}
function MArrayHelper.Lengthex(const aSize: Integer = 0): Integer; overload;
begin
  Result := Self.Length;
  SetLength(Self, IfThen((aSize > -1), aSize, 0));
end;

{==============================================================================]
  <LengthTo>
  @action: Resizes the array to exactly N elements. Automatically handles 
           truncation if N is smaller than the current length, or explicitly 
           initializes new elements to their default value if N is larger.
  @note: Guarantees N is at least 0. Returns the newly established length of 
         the array.
[==============================================================================}
function MArrayHelper.LengthTo(const N: Integer): Integer; overload;
var
  i, l: Integer;
begin
  Result := Max(N, 0);
  l := Self.Length;
  SetLength(Self, Result);
  for i := l to (Result - 1) do
    Self[i] := Default(MType);
end;

{==============================================================================]
  <Relength>
  @action: Resizes the dynamic array to the specified size and returns the 
           difference (delta) between the new length and the original length.
  @note: A positive return value indicates the array grew, while a negative 
         value indicates it shrank. Negative input for aSize is safely 
         clamped to 0. Defaults to 0 if no size is provided.
[==============================================================================}
function MArrayHelper.Relength(const aSize: Integer = 0): Integer; overload;
begin
  Result := Self.Length;
  SetLength(Self, Max(0, aSize));
  Result := (Self.Length - Result);
end;

{==============================================================================]
  <Relength>
  @action: Creates a complete copy of the current array into the 'backup' 
           parameter, then resizes the array to the specified size. Returns 
           the difference (delta) between the new and original lengths.
  @note: By default, if aSize is omitted, it defaults to 0 (clearing the array).
         The 'backup' parameter will hold the exact state of the entire array 
         prior to the resize operation.
[==============================================================================}
function MArrayHelper.Relength(out backup: MArray; const aSize: Integer = 0): Integer; overload;
begin
  backup := Self.Clone;
  Result := Self.Relength(aSize);
end;

{==============================================================================]
  <Resize>
  @action: Updates's arr length with aChange.
  @note: aChange > 0 => Result will give how many elements were added
         aChange < 0 => Result will give how many elements got deleted (it will be negative value!)
         aChange = 0 => Returns 0.
[==============================================================================}
function MArrayHelper.Resize(const aChange: Integer): Integer; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Self, (l + aChange));
  Result := (Self.Size - l);
end;

{==============================================================================]
  <Resize>
  @action: Updates's arr length with aChange.
  @note: aChange > 0 => Result will give how many elements were added
         aChange < 0 => Result will give how many elements got deleted (it will be negative value!)
         aChange = 0 => Returns 0.
         Supports null for filling created indexes.
[==============================================================================}
function MArrayHelper.Resize(const aChange: Integer; const null: MType): Integer; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Self, aChange);
  Result := (Self.Size - l);
  for i := 0 to (Result - 1) do
    Self[l + i] := null;
end;

{==============================================================================]
  <Resizement>
  @action: Resizes the array by a signed amount (positive = grow, negative = shrink,
           zero = no change). Returns the new length with overflow protection.
  @note: Uses a case statement based on the sign of aChange.
         - If aChange = 0: returns current length without modification.
         - If aChange > 0: sets new length = old + aChange, clamped to MaxInt
           (2,147,483,647) to prevent overflow during addition.
         - If aChange < 0: sets new length = Max(0, old + aChange) (never below 0).
         The operation is in‑place. This overload does not initialize new elements.
[==============================================================================}
function MArrayHelper.Resizement(const aChange: Integer = 0): Integer; overload;
begin
  case aChange.Compare(0) of
    0: Result := Self.Length;
    1: Result := Self.SetSize(Min(MaxInt, (Int64(Self.Length) + aChange)));
    -1: Result := Self.SetSize(Max(0, (Self.Length + aChange)));
  end;
end;

{==============================================================================]
  <Resizement>
  @action: Resizes the array by a signed amount. If growing, fills the new
           elements with a specified value. If shrinking, simply truncates.
  @param aChange: Positive = grow by that many, negative = shrink by that many,
                  zero = no change.
  @param null: Value to assign to any newly created elements (when growing).
  @return: New length of the array after resizing.
  @note: In‑place operation. Uses the integer‑only Resizement overload for the
         actual resize, then fills new positions. The parameter name 'null' is
         appropriate for pointer/reference types; for value types consider
         'defaultValue' or 'fillValue'.
[==============================================================================}
function MArrayHelper.Resizement(const aChange: Integer; const null: MType): Integer; overload;
var
  l, i: Integer;
begin
  if (aChange = 0) then
    Exit(Self.Length);
  if (aChange > 0) then
  begin
    l := Self.Length;
    Result := Self.Resizement(aChange);
	if (Result > l) then
	for i := l to (Result - 1) do
      Self[i] := null;
  end else
    Result := Self.Resizement(aChange);
end;

{==============================================================================]
  <SetLen>
  @action: Changes the length of the dynamic array. Returns the original length
           of the array before the resizing operation.
  @note: If aSize is a negative number, the array will be cleared (set to 0).
         The parameter defaults to 1 if omitted.
[==============================================================================}
function MArrayHelper.SetLen(const aSize: Integer = 1): Integer; overload;
begin
  Result := Self.Length;
  if (aSize > -1) then
    SetLength(Self, aSize)
  else
    SetLength(Self, 0);
end;

{==============================================================================]
  <SetSize>
  @action: Resizes the dynamic array to the specified number of elements.
  @note: If sSize is 0 or negative, the array is cleared. Existing data is 
         preserved if the array is expanded. Uses Math unit for Max().
		 By default sets size as 1!
[==============================================================================}
function MArrayHelper.SetSize(const sSize: Integer = 1): Integer; overload;
begin
  SetLength(Self, Max(0, sSize));
  Result := Self.Length;
end;

{==============================================================================]
  <SetSize>
  @action: Resizes the array and initializes any newly created elements.
  @note: If the array grows, indices from the old length to the new length 
         are populated with iCreated. If it shrinks, no initialization occurs.
[==============================================================================}
function MArrayHelper.SetSize(const sSize: Integer; const iCreated: MType): Integer; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Self, Max(0, sSize));
  Result := Self.Length;
  for i := l to (Result - 1) do
    Self[i] := iCreated;
end;

{==============================================================================]
  <Size>
  @action: Returns array length.
  @note: Simply Result := Length(arr);
[==============================================================================}
function MArrayHelper.Size: Integer; overload;
begin
  Result := ((High(Self) - Low(Self)) + 1);
end;

{==============================================================================]
  <Size>
  @action: Set's arr length to aSize.
  @note: None.
[==============================================================================}
function MArrayHelper.Size(const aSize: Integer): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, aSize);
  for i := 0 to (Min(l, aSize) - 1) do
    Result[i] := Self[i];
end;

{==============================================================================]
  <Size>
  @action: Set's arr length to size.
  @note: Uses null for created indexes.
[==============================================================================}
function MArrayHelper.Size(const aSize: Integer; const null: MType): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, aSize);
  for i := 0 to (Min(l, aSize) - 1) do
    Result[i] := Self[i];
  for i := l to (aSize - 1) do
    Result[i] := null;
end;

{==============================================================================]
  <SizeTo>
  @action: Resizes the array to contain exactly N elements. Truncates trailing 
           elements if N is smaller than the current length, or pads the array 
           with default values if N is larger.
  @note: Guarantees N is at least 0. Returns the newly established length of 
         the array.
[==============================================================================}
function MArrayHelper.SizeTo(const N: Integer): Integer; overload;
begin
  Result := Max(N, 0);
  if (Result < Self.Length) then
    System.Delete(Self, Result, (Self.Length - Result))
  else
    while (Self.Length < Result) do
      System.Insert(Default(MType), Self, Self.Length);
end;

{==============================================================================]
  <Sizex>
  @action: Duplicates the current array into the 'data' parameter and returns the element count.
  @note: Safely handles nil (unassigned) instances by clearing 'data' and returning 0. 
         Otherwise, allocates matching memory for 'data' and copies elements via a loop.
[==============================================================================}
function MArrayHelper.Sizex(out data: MArray): Integer; overload;
var
  i: Integer;
begin
  if (Self = nil) then
  begin
    SetLength(data, 0);
    Exit(0);
  end;
  Result := (High(Self) + 1);
  SetLength(data, Result);
  for i := 0 to (Result - 1) do
    data[i] := Self[i];
end;
{$ENDIF}
