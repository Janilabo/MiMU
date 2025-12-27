{$IFDEF HELPERS}
{$I Base.pph}
{$ENDIF}

{$IFDEF CLASSES}
{$IFDEF T1D}
class function Create(const item: MType; const aSize: Integer = 1): MArray; overload;
{$ENDIF}

{$IF DEFINED(TBS) AND DEFINED(Sortable)}
class function Search(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
{$ENDIF}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I Base.pph}

{$IFDEF Sortable}
class function TBinarySearch.Search(const arr: MArray; const item: MType; const ascending: Boolean = True): Integer; overload;
var
  L, R, M: Integer;
begin
  Result := -1;
  L := 0;
  R := High(arr);
  while (L <= R) do
  begin
    M := (L + ((R - L) shr 1));
    if (arr[M] = item) then
      Exit(M);
    if ((ascending and (arr[M] < item)) or ((not ascending) and (arr[M] > item))) then
      L := (M + 1)
    else
      R := (M - 1);
  end;
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