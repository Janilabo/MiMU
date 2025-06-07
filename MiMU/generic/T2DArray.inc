{==============================================================================]
 <T2DArray_Blank(arr: TArray; parts: Int32): T2DArray>
 @action: Returns true if array is blank (no inventory, only empty indexes of []).
 @note: Blank array could be for example [[], [], []]. Returns false if array contains any items.
        NOTE: Returns false if array is empty (1D Length = 0)!
 [==============================================================================}
{$IFDEF T2DArray_Blank}
var
  i: Int32;
begin
  for i := 0 to High(arr) do
    if (Length(arr[i]) > 0) then
	  Exit(False);
  Result := (Length(arr) > 0);
end;
{$ENDIF}

{==============================================================================]
 <T2DTArray_Create(size1D, size2D: Int32; item: VarType)> 
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
{$IFDEF T2DArray_Create}
var
  i, j, s: Int32;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;
{$ENDIF}

{==============================================================================]
 <T2DArray_Empty(arr: T2DArray): Boolean> 
 @action: Returns true if array is empty (Length = 0).
 @note: None.
[==============================================================================}
{$IFDEF T2DArray_Empty}
begin
  Result := (Length(arr) = 0);
end;
{$ENDIF}

{==============================================================================]
 <T2DArray_Length(arr: T2DArray; lengths: TIntegerArray): Int64> 
 @action: Returns actual Length for 2D array. Stores Length's of 2D part, of the arr, to lengths variable.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
{$IFDEF T2DArray_Length1}
var
  i: Int32;
begin
  Result := 0;
  SetLength(lengths, Length(arr));
  for i := 0 to High(arr) do
  begin
    lengths[i] := Length(arr[i]);
	Result := (Result + lengths[i]);
  end;
end;
{$ENDIF}


{==============================================================================]
 <T2DArray_Length(arr: T2DArray): Int64> 
 @action: Returns actual Length for 2D array.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
{$IFDEF T2DArray_Length2}
var
  i: Int32;
begin
  Result := 0;
  for i := 0 to High(arr) do
    Result := (Result + Length(arr[i]));
end;
{$ENDIF}

{==============================================================================]
 <T2DArray_Merge(arr: T2DArray): TArray> 
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
{$IFDEF T2DArray_Merge}
var
  i, j, l: Int32;
begin
  l := 0;
  for i := 0 to High(arr) do
    l := (l + Length(arr[i]));
  SetLength(Result, l);
  for i := High(arr) downto 0 do
    for j := High(arr[i]) downto 0 do
    begin
      Dec(l);
      Result[l] := arr[i][j];
    end;
end;
{$ENDIF}