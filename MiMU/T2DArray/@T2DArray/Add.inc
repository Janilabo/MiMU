{$IFDEF HELPERS}
function Supply(const item: MType): Integer; overload;
function Supply(const items: MArray): Integer; overload;
function Supply(const items: M2DArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Supply>
  @action: Wraps a single scalar item into a 1D array row and appends it to the end of the 2D array.
  @note: Returns the index of the newly added row.
[==============================================================================}
function M2DArrayHelper.Supply(const item: MType): Integer; overload;
begin
  Result := Self.Alloc(Self.Length + 1);
  Self[Result] := [item];
end;

{==============================================================================]
  <Supply>
  @action: Appends a 1D array as a new row to the end of the 2D array by copying its elements.
  @note: Returns the index of the newly added row.
[==============================================================================}
function M2DArrayHelper.Supply(const items: MArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Size;
  SetLength(Self, (Result + 1));
  SetLength(Self[Result], items.Length);
  for i := 0 to High(items) do
    Self[Result][i] := items[i];
end;

{==============================================================================]
  <Supply>
  @action: Appends multiple 1D array rows from another 2D array to the end of this 2D array.
  @note: Returns the starting index where the new rows were inserted, or -1 if the input array is empty.
[==============================================================================}
function M2DArrayHelper.Supply(const items: M2DArray): Integer; overload;
var
  i: Integer;
begin
  if (items.Length = 0) then
    Exit(-1);
  Result := Self.Length;
  SetLength(Self, (Result + items.Length));
  for i := 0 to High(items) do
    Self[Result + i] := items[i];
end;
{$ENDIF}