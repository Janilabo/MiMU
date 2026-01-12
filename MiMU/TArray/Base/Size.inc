{$IFDEF HELPERS}
function Fit: Integer; overload;
function Fit(const aSize: Integer): Integer; overload;
function Fit(const aBounds: TRange): Integer; overload;
function Length: Integer; overload;
function Resize(const aChange: Integer): Integer; overload;
function Resize(const aChange: Integer; const null: MType): Integer; overload;
function Size: Integer; overload;
function Size(const aSize: Integer): MArray; overload;
function Size(const aSize: Integer; const null: MType): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Len>
  @action: Simply Result := System.Length(arr);
  @note: None.
[==============================================================================}
function MArrayHelper.Length: Integer; overload;
begin
  Result := System.Length(Self);
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
{$ENDIF}