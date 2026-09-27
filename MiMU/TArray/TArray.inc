{$IF DEFINED(HELPERS) OR DEFINED(FUNCTIONS)}
{$I TArray.pph}
{$ENDIF}

{$IFDEF CLASSES}
{$IFDEF T1D}
class function Create(const item: MType; const aSize: Integer = 1): MArray; overload;
{$ENDIF}

{$IF DEFINED(TBS) AND DEFINED(Sortable)}
class function Find(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
class function Find(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
class function Search(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
class function Search(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;

class function LowerBound(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
class function LowerBound(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
class function UpperBound(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
class function UpperBound(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
{$ENDIF}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I TArray.pph}

{$IFDEF Sortable}
class function TBinarySearch.Find(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
var
  L, R: Integer;
begin
  L := Min(Max(0, Min(indices.start, indices.stop)), (High(arr) + 1));
  R := Min(Max(indices.start, indices.stop), High(arr));
  while (L <= R) do
  begin
    Result := (L + ((R - L) shr 1));
    if (arr[Result] = item) then
      Exit;
    if ((ascending and (arr[Result] < item)) or ((not ascending) and (arr[Result] > item))) then
      L := (Result + 1)
    else
      R := (Result - 1);
  end;
  Result := -1;
end;

class function TBinarySearch.Find(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
begin
  Result := TBinarySearch.Find(arr, arr.Locale, item, ascending);
end;

class function TBinarySearch.Search(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
var
  l, h: Integer;
begin
  l := Min(Max(0, Min(indices.start, indices.stop)), arr.Length);
  h := Max(l, Min((Max(indices.start, indices.stop) + 1), arr.Length));
  case ascending of
    True:
    while (l < h) do
    begin
      Result := (l + ((h - l) div 2));
      if (arr[Result] = item) then
        Exit
      else if (arr[Result] < item) then
        l := (Result + 1)
      else
        h := Result;
    end;
    False:
    while (l < h) do
    begin
      Result := (l + ((h - l) div 2));
      if (arr[Result] = item) then
        Exit
      else if (arr[Result] > item) then
        l := (Result + 1)
      else
        h := Result;
    end;
  end;
  Result := -1;
end;

class function TBinarySearch.Search(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
begin
  Result := TBinarySearch.Search(arr, arr.Locale, item, ascending);
end;

class function TBinarySearch.LowerBound(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
var
  h, m: Integer;
begin
  Result := Min(Max(0, Min(indices.start, indices.stop)), arr.Length);
  h := Max(Result, Min((Max(indices.start, indices.stop) + 1), arr.Length));
  case ascending of
    True:
    while (Result < h) do
    begin
      m := (Result + ((h - Result) div 2));
      if (arr[m] < item) then
        Result := (m + 1)
      else
        h := m;
    end;
    False:
    while (Result < h) do
    begin
      m := (Result + ((h - Result) div 2));
      if (arr[m] > item) then
        Result := (m + 1)
      else
        h := m;
    end;
  end;
end;

class function TBinarySearch.LowerBound(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
begin
  Result := TBinarySearch.LowerBound(arr, arr.Locale, item, ascending);
end;

class function TBinarySearch.UpperBound(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
var
  h, m: Integer;
begin
  Result := Min(Max(0, Min(indices.start, indices.stop)), arr.Length);
  h := Max(Result, Min((Max(indices.start, indices.stop) + 1), arr.Length));
  case ascending of
    True:
    while (Result < h) do
    begin
      m := (Result + ((h - Result) div 2));
      if (arr[m] <= item) then
        Result := (m + 1)
      else
        h := m;
    end;
    False:
    while (Result < h) do
    begin
      m := (Result + ((h - Result) div 2));
      if (arr[m] >= item) then
        Result := (m + 1)
      else
        h := m;
    end;
  end;
end;

class function TBinarySearch.UpperBound(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
begin
  Result := TBinarySearch.UpperBound(arr, arr.Locale, item, ascending);
end;
{$ENDIF}

{==============================================================================]
  <Create>
  @action: Creates array with item where size is length of the array.
  @note: item is placed on every index in result.
[==============================================================================}
class function T1D.Create(const item: MType; const aSize: Integer = 1): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Max(0, aSize));
  for i := 0 to High(Result) do
    Result[i] := item;
end;
{$ENDIF}
