{$IFDEF HELPERS}
function BSort(const aAscending: Boolean = True): Integer;
function BinarySort(const aAscending: Boolean = True): Integer;
function BinarySorted(const aAscending: Boolean = True): TIntegerArray;
function BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
function BinaryInsertSorted(const oAscending: Boolean = True): TIntegerArray; overload;
function BinaryCountingSort(const aAscending: Boolean = True; const maxRange: Integer = 2000): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BSort>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BSort(const aAscending: Boolean = True): Integer; var a: Integer; {$DEFINE Skeleton_BSort}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BSort}

{==============================================================================]
  <BinarySort>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.BinarySort(const aAscending: Boolean = True): Integer; var a: Integer; {$DEFINE Skeleton_BinarySort}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySort}

{==============================================================================]
  <BinarySorted>
  @action: BinarySort algorithm for TIntegerArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TIntegerArrayHelper.BinarySorted(const aAscending: Boolean = True): TIntegerArray; var a: Integer; {$DEFINE Skeleton_BinarySorted}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySorted}

function TIntegerArrayHelper.BinaryInsertSorted(const oAscending: Boolean = True): TIntegerArray; overload; var K: Integer; {$DEFINE Skeleton_BinaryInsertSorted}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryInsertSorted}
function TIntegerArrayHelper.BinaryInsertSort(const oAscending: Boolean = True): Integer; overload; var K: Integer; {$DEFINE Skeleton_BinaryInsertSort}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryInsertSort}

{==============================================================================]
  <BinaryCountingSort>
  @action: Sorts the integer array using a hybrid approach that combines counting sort
           for densely clustered values with binary insertion for outliers.
           Automatically adapts to the data distribution based on the maxRange parameter.
  @note: 
    - If the range of array values is smaller than or equal to maxRange, a full counting
      sort is applied.
    - If the range exceeds maxRange, the method counts values within a central cluster
      (centered at the array’s midpoint) and uses binary insertion for values outside
      that cluster.
    - Supports ascending (default) or descending order.
    - Handles negative and positive integers.
    - The counting array size is bounded by maxRange + 1 to avoid excessive memory usage.
[==============================================================================}
function TIntegerArrayHelper.BinaryCountingSort(const aAscending: Boolean = True; const maxRange: Integer = 2000): Integer;
var
  c, l: TIntegerArray;
  i, j, r, o: Integer;
  m: TRange;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  m := Self.Bounds(r);
  case (r <= maxRange) of
    True:
    begin
      SetLength(c, r);
      for i := 0 to High(Self) do
        Inc(c[Self[i] - m.start]);
      j := 0;
      case aAscending of
        True:
        for i := 0 to (r - 1) do
          while (c[i].Decrease > 0) do
            Self[j.Increase] := (i + m.start);
        False:
        for i := r - 1 downto 0 do
          while (c[i].Decrease > 0) do
            Self[j.Increase] := (i + m.start);
      end;
    end;
    False:
    begin
      o := m.Center;
      r := 200;
      SetLength(c, ((r * 2) + 1));
      SetLength(l, 0);
      for i := 0 to High(Self) do
        if InRange(Self[i], (o - r), (o + r)) then
          Inc(c[Self[i] - (o - r)])
        else
          l.BinaryAppend(Self[i]);
      j := 0;
      case aAscending of
        True:
        begin
          for i := 0 to High(c) do
            while (c[i].Decrease > 0) do
              Self[j.Increase] := ((o - r) + i);
          for i := 0 to High(l) do
            Self[j.Increase] := l[i];
        end;
        False:
        begin
          for i := High(c) downto 0 do
            while (c[i].Decrease > 0) do
              Self[j.Increase] := ((o - r) + i);
          for i := High(l) downto 0 do
            Self[j.Increase] := l[i];
        end;
      end;
    end;
  end;
end;
{$ENDIF}
