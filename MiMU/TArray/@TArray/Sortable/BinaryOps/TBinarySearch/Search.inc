{$IFDEF CLASSES}
class function Find(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
class function Find(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
class function Search(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
class function Search(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
