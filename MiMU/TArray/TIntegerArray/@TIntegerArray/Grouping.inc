{$IFDEF HELPERS}
function Consortium(const oAscending: Boolean = True): T2DIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Consortium>
  @action: Groups duplicate integers into 2D sub-arrays using a O(N + Range) 
          counting/histogram distribution strategy.
  @note: 
    - Non-sorting grouping: Uses min/max boundary detection (`Boundify`) to allocate 
      a direct frequency table `c` across range `(h - l + 1)`, avoiding comparison-based 
      sorting ($O(N)$ bucket allocation).
    - Multi-pass execution:
      1. Range & Frequency Pass: Scans elements to populate value occurrence counts into `c`.
      2. Index Mapping Pass: Populates lookup map `z` based on sort direction (`oAscending`), 
         assigning dense row indices `g` to unique existing values.
      3. Memory Pre-allocation: Directly sizes each row `Result[z[i]]` to exact frequency `c[i]`.
      4. Direct Population Pass: Iterates `Self` linearly to place elements into mapped rows 
         using dynamic offset array `t`.
    - Trade-off: Provides optimal speed for small integer ranges; memory usage scales 
      with value spread `(Max - Min)` rather than element count `N`.
[==============================================================================}
function TIntegerArrayHelper.Consortium(const oAscending: Boolean = True): T2DIntegerArray; overload;
var
  s, i, l, h, r, g, v: Integer;
  c, z, t: TIntegerArray;
begin
  s := Self.Boundify(l, h);
  if (s = 0) then
    Exit;
  r := ((h - l) + 1);
  SetLength(c, r);
  for i := 0 to (s - 1) do
    Inc(c[Self[i] - l]);
  g := 0;
  case oAscending of
    True:
    for i := 0 to z.Alloc(r) do
      if (c[i] > 0) then
        z[i] := g.Increase;
    False:
    for i := z.Alloc(r) downto 0 do
      if (c[i] > 0) then
        z[i] := g.Increase;
  end;
  SetLength(Result, g);
  for i := 0 to (r - 1) do
    if (c[i] > 0) then
      SetLength(Result[z[i]], c[i]);
  SetLength(t, g);
  for i := 0 to (s - 1) do
  begin
    v := (Self[i] - l);
    Result[z[v]][t[z[v]].Increase] := Self[i];
  end;
end;
{$ENDIF}
