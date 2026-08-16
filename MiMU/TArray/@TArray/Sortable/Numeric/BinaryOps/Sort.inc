{$IFDEF HELPERS}
function BinarySortedTo(const aAscending: Boolean = True): MArray; overload;
function BinarySortTo(const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinarySortedTo>
  @action: Returns a new array containing the elements of Self sorted via
           binary insertion sort, locating each element's position via
           numeric comparison (Sign of difference). Self is not modified.
  @note:
    - Sorts according to aAscending.
    - Ties are resolved rightward: a newly-placed element is inserted
      after any existing equal elements (stable).
    - For TInt64Array: Sign(s - Result[m]) can overflow when the operands'
      difference exceeds Int64's range. Not an issue for TIntegerArray
      or TDoubleArray.
[==============================================================================}
function MArrayHelper.BinarySortedTo(const aAscending: Boolean = True): MArray; overload;
var
  s: MType;
  i, j, m, n, o: Integer;
  r: TRange;
begin
  n := Self.Size;
  if (Result.SetSize(n) < 1) then
    Exit;
  Result[0] := Self[0];
  if (n < 2) then
    Exit;
  o := aAscending.Select(-1, 1);
  for i := 1 to (n - 1) do
  begin
    s := Self[i];
    r.Create(0, (i - 1));
    while r.Asceal do
    begin
      m := r.Pivot;
      if (Sign(s - Result[m]) = o) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    for j := (i - 1) downto r.start do
      Result[j + 1] := Result[j];
    Result[r.start] := s;
  end;
end;

{==============================================================================]
  <BinarySortTo>
  @action: BinarySort algorithm for arrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.BinarySortTo(const aAscending: Boolean = True): Integer; overload;
var
  s: MType;
  i, j, m, o: Integer;
  r: TRange;
begin
  Result := High(Self);
  if (Result < 1) then
    Exit;
  o := aAscending.Select(-1, 1);
  for i := 1 to Result do
  begin
    s := Self[i];
    r.Create(0, (i - 1));
    while r.Asceal do
    begin
      m := r.Pivot;
      if (Sign(s - Self[m]) = o) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    for j := (i - 1) downto r.start do
      Self[j + 1] := Self[j];
    Self[r.start] := s;
  end;
end;   
{$ENDIF}