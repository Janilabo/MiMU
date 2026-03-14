{$IFDEF HELPERS}
function BinaryInsertion(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySupply(const item: MType; const aAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryInsertion>
  @action: Inserts an item into a sorted array while preserving order.
  @note: Array must already be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns index where the element was inserted.
[==============================================================================}
function MArrayHelper.BinaryInsertion(const item: MType; const oAscending: Boolean = True): Integer; overload;
procedure I(var arr: MArray; const index: Integer; const value: MType);
var
  a, N: Integer;
begin
  N := System.Length(arr);
  SetLength(arr, (N + 1));
  for a := N downto (index + 1) do
    arr[a] := arr[a - 1];
  arr[index] := value;
end;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := R.start;
  I(Self, Result, item);
end;

{==============================================================================]
  <BinarySupply>
  @action: Inserts the item x into the array at the correct position to maintain
           sorted order. Supports both ascending and descending order.
  @note:
    • The array must already be sorted according to aAscending.  
    • If aAscending = True, ascending order is assumed;  
      if aAscending = False, descending order is assumed.  
    • The value is not inserted if it already exists in the array.  
    • Returns True if the value was inserted, False if it already exists.  
    • Search complexity: O(log n).  
    • Insertion (element shift) complexity: O(n).  
    • Overall complexity: O(n).  
    • The array is resized when insertion occurs.
[==============================================================================}
function MArrayHelper.BinarySupply(const item: MType; const aAscending: Boolean = True): Boolean; overload;
var
  m, i, o: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
  begin
    m := r.Pivot;
	if ((aAscending and (Self[m] < item)) or ((not aAscending) and (Self[m] > item))) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((Self.Size = r.start) or (Self[r.start] <> item));
  if not Result then
    Exit;
  SetLength(Self, (Self.Size + 1));
  for i := High(Self) downto (r.start + 1) do
    Self[i] := Self[i - 1];
  Self[r.start] := item;
end;
{$ENDIF}