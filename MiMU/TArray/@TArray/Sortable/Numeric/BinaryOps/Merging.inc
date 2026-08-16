{$IFDEF HELPERS}
function BinaryFusion(const items: MArray; const aAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryFusion>
  @action: Merges two sorted arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function MArrayHelper.BinaryFusion(const items: MArray; const aAscending: Boolean = True): MArray; overload;
var
  l: specialize TFPGList<MType>;
  r: Integer;
  s, i: TRange;
begin
  l := specialize TFPGList<MType>.Create;
  try
    i.Create(0, items.Size);
    s.Create(0, Self.Size);
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if ((aAscending and (Self[s.start] <= items[i.start])) or ((not aAscending) and (Self[s.start] >= items[i.start]))) then
        l.Add(Self[s.start.Increase])
      else
        l.Add(items[i.start.Increase]);
    while (s.start < s.stop) do
      l.Add(Self[s.start.Increase]);
    while (i.start < i.stop) do
      l.Add(items[i.start.Increase]);
    for r := 0 to Result.Alloc(l.Count) do
      Result[r] := l[r];
  finally
    l.Free;
  end;
end;
{$ENDIF}
