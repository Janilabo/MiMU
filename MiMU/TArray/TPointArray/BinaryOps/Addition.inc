{$IFDEF HELPERS}
function BinaryInsert(const item: TPoint; const allowDuplicates: Boolean = True): Integer; overload;
function BinaryAppend(const item: TPoint; const allowDuplicates: Boolean = True): Integer; overload;
function BinarySupply(const item: TPoint): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryInsert>
  @action: Inserts a specified point into a sorted TPointArray while maintaining
           lexicographic order.
  @note: - The array must be sorted in ascending lexicographic order by X, then by Y,
           consistent with TPoint.Compare.
         - If allowDuplicates = False, no insertion occurs if the point already exists.
         - Returns the index of the inserted or existing point.
[==============================================================================}
function TPointArrayHelper.BinaryInsert(const item: TPoint; const allowDuplicates: Boolean = True): Integer; overload;
var
  H, M: Integer;
begin
  Result := 0;
  H := High(Self);
  while (Result <= H) do
  begin
    M := ((Result + H) div 2);
    case Self[M].Compare(item) of
      -1: Result := (M + 1);
      1: H := (M - 1);
      0:
      if allowDuplicates then
        Result := (M + 1)
      else
        Exit(M);
    end;
  end;
  Insert(item, Self, Result);
end;

{==============================================================================]
  <BinaryAppend>
  @action: Appends a specified point to the end of a sorted TPointArray if it is greater
           than the last point, otherwise performs a BinaryInsert.
  @note: - The array must be sorted in ascending lexicographic order by X, then by Y,
           consistent with TPoint.Compare.
         - If allowDuplicates = False, duplicates are ignored.
         - Returns the index of the inserted or existing point.
[==============================================================================}
function TPointArrayHelper.BinaryAppend(const item: TPoint; const allowDuplicates: Boolean = True): Integer; overload;
begin
  if not (Self.Empty or (Self[High(Self)].Compare(item) < 0)) then
    Exit(Self.BinaryInsert(item, allowDuplicates));
  Result := Self.Size;
  Self.Supply(item);
end;

{==============================================================================]
  <BinarySupply>
  @action: Inserts a specified point into the sorted TPointArray while preserving
           ascending lexicographic order by X, then Y.
  @note: - The array must already be sorted in ascending order consistent with
           TPoint.Compare.
         - Uses BinaryPosL to determine the correct insertion position.
         - Shifts subsequent elements to make room for the new point.
         - Returns the index at which the point was inserted.
[==============================================================================}
function TPointArrayHelper.BinarySupply(const item: TPoint): Integer; overload;
var
  i: Integer;
begin
  Result := Self.BinaryPosL(item);
  SetLength(Self, (Self.Size + 1));
  for i := High(Self) downto (Result + 1) do
    Self[i] := Self[i - 1];
  Self[Result] := item;
end;
{$ENDIF}
