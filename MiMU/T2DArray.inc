{==============================================================================]
 <var.T2DArray(size1D, size2D: Integer): T2DArray>
 @action: Creates 2D array with Self.
 @note: None.
[==============================================================================}
{$IFDEF var_T2DArray}
var
  i, j: Integer;
begin
  SetLength(Result, size1D);
  for i := 0 to High(Result) do
  begin
    SetLength(Result[i], size2D);
	for j := 0 to High(Result[i]) do
      Result[i][j] := Self;
  end;
end;
{$ENDIF}

{==============================================================================]
 <arr.Blank(parts: Integer): T2DArray>
 @action: Returns true if array is blank (no inventory, only empty indexes of []).
 @note: Blank array could be for example [[], [], []]. Returns false if array contains any items.
        NOTE: Returns false if array is empty (1D Length = 0)!
 [==============================================================================}
{$IFDEF T2DArray_Blank}
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if (Length(Self[i]) > 0) then
	  Exit(False);
  Result := (Length(Self) > 0);
end;
{$ENDIF}

{==============================================================================]
 <T2D.Create(size1D, size2D: Integer; item: VarType)>
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
{$IFDEF T2D_Create}
var
  i, j, s: Integer;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;
{$ENDIF}

{==============================================================================]
 <arr.Empty: Boolean>
 @action: Returns true if array is empty (Length = 0).
 @note: None.
[==============================================================================}
{$IFDEF T2DArray_Empty}
begin
  Result := (Length(Self) = 0);
end;
{$ENDIF}

{==============================================================================]
 <arr.Size(lengths: TIntegerArray): Int64>
 @action: Returns actual Length for 2D array. Stores Length's of 2D part, of the arr, to lengths variable.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
{$IFDEF T2DArray_Size1}
var
  i: Integer;
begin
  Result := 0;
  SetLength(lengths, Length(Self));
  for i := 0 to High(Self) do
  begin
    lengths[i] := Length(Self[i]);
    Result := (Result + lengths[i]);
  end;
end;
{$ENDIF}


{==============================================================================]
 <arr.Size: Int64>
 @action: Returns actual Length for 2D array.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
{$IFDEF T2DArray_Size2}
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := (Result + Length(Self[i]));
end;
{$ENDIF}

{==============================================================================]
 <arr.Size(aSize: Integer): Int64>
 @action: Sets length to 1D part of the 2D array and returns the actual size of arr (element count)
 @note: None.
[==============================================================================}
{$IFDEF T2DArray_Size3}
var
  i: Integer;
begin
  SetLength(Self, aSize);
  Result := 0;
  for i := 0 to High(Self) do
    Result := (Result + Length(Self[i]));
end;
{$ENDIF}

{==============================================================================]
 <arr.Size(size1D, size2D: Integer): Int64>
 @action: Returns actual Length for 2D array.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
{$IFDEF T2DArray_Size4}
begin
  SetLength(Self, size1D, size2D);
  Result := (Max(0, size1D) * Max(0, size2D));
end;
{$ENDIF}

{==============================================================================]
 <arr.Merge: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
{$IFDEF T2DArray_Merge}
var
  i, j, l: Integer;
begin
  l := Result.Size(Self.Size);
  if (l > 0) then
  for i := High(Self) downto 0 do
    for j := High(Self[i]) downto 0 do
      Result[l.Decrement] := Self[i][j];
end;
{$ENDIF}
