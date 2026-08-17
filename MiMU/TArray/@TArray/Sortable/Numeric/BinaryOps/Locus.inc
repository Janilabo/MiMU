{$IFDEF HELPERS}
function BinaryLocation(const item: MType; const aAscending: Boolean = True): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryLocation>
  @action: Returns the contiguous index range [start, stop] of all elements
           equal to item in a sorted array. If not found, returns (-1, -1).
  @note: Works with sorted arrays (aAscending or descending), using a
         multiplicative direction trick (o * Self[m]) rather than branching.
         MType must be numeric (supports *); use the ordered-only overload
         for non-numeric MType.
[==============================================================================}
function MArrayHelper.BinaryLocation(const item: MType; const aAscending: Boolean = True): TRange; overload;
var
  h, m, o: Integer;
  f: Boolean;
begin
  f := False;
  h := High(Self);
  Result.Create(0, h);
  o := aAscending.Select(1, -1);
  while (Result.Asceal and (not f)) do
  begin
    m := Result.Pivot;
    f := ((o * Self[m]) = (o * item));
    if f then
    begin
      Result.Create(m, m);
      while ((Result.start > 0) and (Self[Result.start - 1] = item)) do
        Dec(Result.start);
      while ((Result.stop < h) and (Self[Result.stop + 1] = item)) do
        Inc(Result.stop);
    end else if ((o * Self[m]) < (o * item)) then
      Result.start := (m + 1)
    else
      Result.stop := (m - 1);
  end;
  if not f then
    Result.Create(-1, -1);
end;
{$ENDIF}
