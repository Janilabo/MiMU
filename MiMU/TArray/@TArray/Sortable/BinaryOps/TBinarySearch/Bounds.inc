{$IFDEF CLASSES}
class function LowerBound(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
class function LowerBound(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
class function UpperBound(const arr: MArray; const indices: TRange; const item: MType; const ascending: Boolean = True): Integer; overload;
class function UpperBound(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
