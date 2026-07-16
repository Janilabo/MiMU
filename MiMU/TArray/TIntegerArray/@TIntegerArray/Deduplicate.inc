{$IFDEF HELPERS}
function Undupe: TIntegerArray; overload;
function Unduped: TIntegerArray; overload;
function Unduplicate: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Undupe>
  @action: Removes duplicates from array arr and returns the count of deleted items.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Undupe: TIntegerArray; overload;
begin
  Result := Self.Copy;
  CIntegerArray.Unique(Result);
end;

{==============================================================================]
  <Unduped>
  @action: Removes duplicates from array arr and returns it.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Unduped: TIntegerArray; overload;
var
  i, l: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  l := 0;
  if Self.Exists then
  begin
    SetLength(Result, Self.Size);
    r := Self.Bounds;
	b.Create(r.Size, False);
    for i := 0 to High(Self) do
      if b[Self[i] - r.start].Enable then
        Result[l.Increase] := Self[i];
    SetLength(b, 0);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Unduplicate>
  @action: Removes all duplicate elements from the array, leaving only the
           first occurrence of each value. The operation modifies the array
           in place.
  @note: - Returns the number of elements removed.  
         - Preserves the original order of first occurrences.  
         - Uses a temporary Boolean array to track which values have been
           seen (based on the array’s bounds).  
         - If the array is empty or contains a single element, no changes
           are made and the result is 0.
[==============================================================================}
function TIntegerArrayHelper.Unduplicate: Integer; overload;
var
  x, y, z: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  y := High(Self);
  if (y > 0) then
  begin
    z := 0;
    r := Self.Bounds;
    b.Create(r.Size, False);
    for x := 0 to y do
    begin
      if b[Self[x] - r.start] then
        Continue;
      b[Self[x] - r.start] := True;
      Self[z.Increase] := Self[x];
    end;
    SetLength(b, 0);
    SetLength(Self, z);
    Result := ((y + 1) - z);
  end else
    Result := 0;
end;
{$ENDIF}
