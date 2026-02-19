{$IFDEF HELPERS}
function Replace(const old, new: MType): MArray; overload;
function Replace(const old, new: MType; const exceptions: TIntegerArray): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Replace>
  @action: Returns a new array based on the current array, where all occurrences
           of `old` are replaced with `new`. The original array is not modified.
  @note: Replacement is performed element-wise across the entire array.
         Order of elements is preserved. The resulting array has the
         same length as the original.
[==============================================================================}
function MArrayHelper.Replace(const old, new: MType): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    if (Self[i] = old) then
      Result[i] := new
    else
      Result[i] := Self[i];
end;

{==============================================================================]
  <Replace>
  @action: Returns a new array based on the current array, where all occurrences
           of `old` are replaced with `new`, except at positions (indexes) listed in
           the `exceptions` array. Positions in `exceptions` retain their
           original values.
  @note: Replacement is performed element-wise across the array, preserving
         order. Elements at indices specified in `exceptions` are skipped
         and left unchanged. The resulting array has the same length as
         the original. The original array is not modified.
[==============================================================================}
function MArrayHelper.Replace(const old, new: MType; const exceptions: TIntegerArray): MArray; overload;
var
  h, i: Integer;
  e: TIntegerArray;
  r: MArray;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  if Self.Empty then
    Exit;
  e := exceptions.ExtractValues(TRange.Construct(0, h));
  SetLength(r, e.Length);
  for i := 0 to High(e) do
    r[i] := Self[i];
  for i := 0 to h do
    if (Self[i] = old) then
      Result[i] := new
    else
      Result[i] := Self[i];
  for i := 0 to High(r) do
    Result[e[i]] := r[i];
end;
{$ENDIF}