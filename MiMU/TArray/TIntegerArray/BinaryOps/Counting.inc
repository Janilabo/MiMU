{$IFDEF HELPERS}
function BinaryCount(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryCount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
function BinaryAmount(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryAmount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
function BinaryLowerCount(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryHigherCount(const value: Integer; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCount>
  @action: Binary Count function for TIntegerArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryCount(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryCount}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryCount}

function TIntegerArrayHelper.BinaryCount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  r: TRange;
begin
  if Self.Empty then
    Exit(0);
  r := x.Normalize;
  Result := Self.BinaryLeftmost(r, aAscending);
  if (Result > -1) then
    Result := ((Self.BinaryRightmost(r, aAscending) - Result) + 1)
  else
    Result := 0;
end;

{==============================================================================]
  <BinaryAmount>
  @action: Returns count of x
  @note: Alternative for BinaryCount
[==============================================================================}
function TIntegerArrayHelper.BinaryAmount(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  s: TRange;
  M, f, l: Integer;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  s.Create(0, High(Self));
  f := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M] = x) of
      True:
      begin
        f := M;
        s.stop := (M - 1);
      end;
      False:
      if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  if (f = -1) then
    Exit(0);
  s.Create(f, High(Self));
  l := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M] = x) of
      True:
      begin
        l := M;
        s.start := (M + 1);
      end;
      False:
      if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  Result := ((l - f) + 1);
end;

function TIntegerArrayHelper.BinaryAmount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  r, s: TRange;
  M, f, l: Integer;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  r := x.Normalize;
  s.Create(0, High(Self));
  f := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case InRange(Self[M], r.start, r.stop) of
      True:
      begin
        f := M;
        s.stop := (M - 1);
      end;
      False:
      if ((aAscending and (Self[M] < r.start)) or ((not aAscending) and (Self[M] > r.stop))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  if (f = -1) then
    Exit(0);
  s.Create(f, High(Self));
  l := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case InRange(Self[M], r.start, r.stop) of
      True:
      begin
        l := M;
        s.start := (M + 1);
      end;
      False:
      if ((aAscending and (Self[M] < r.start)) or ((not aAscending) and (Self[M] > r.stop))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  Result := ((l - f) + 1);
end;

{==============================================================================]
  <BinaryLowerCount>
  @action: Returns the number of elements in the array strictly less than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TIntegerArrayHelper.BinaryLowerCount(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLowerCount}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLowerCount}

{==============================================================================]
  <BinaryHigherCount>
  @action: Returns the number of elements in the array strictly greater than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TIntegerArrayHelper.BinaryHigherCount(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryHigherCount}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryHigherCount}
{$ENDIF}
