{$IFDEF HELPERS}
function Complement(const target: TRange): TRangeArray; overload;
function Concut(const target: TRange): TRangeArray; overload;
function Cutout(const target: TRange): TRangeArray; overload;
function Disjunct(const other: TRange): TRangeArray; overload;
function Disjunction(const other: TRange): TRangeArray; overload;
function Exclave(const universe: TRange): TRangeArray; overload;
function Exor(const target: TRange): TRangeArray; overload;
function Xored(const target: TRange): TRangeArray; overload;
function Xorify(const target: TRange): TRangeArray; overload;
function Xorred(const other: TRange): TRangeArray; overload;
{$ENDIf}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Complement>
  @action: Performs a relative set difference (Self \ target). Returns an 
           array of ranges representing the portions of 'Self' that are 
           not covered by 'target'.
  @param: target - The range to be "subtracted" from the current instance.
  @return: A TRangeArray containing 0, 1, or 2 ranges depending on the 
           overlap topology.
  @note: - Discrete Logic: Uses +/- 1 offsets, assuming integer-like step 
           boundaries.
         - Normalization: Automatically handles ranges where start > stop.
         - Total Overlap: Returns an empty array if 'target' encompasses 'Self'.
[==============================================================================}
function TRangeHelper.Complement(const target: TRange): TRangeArray; overload;
var
  s, t: TRange;
begin
  SetLength(Result, 0);
  s := Self.Normalized;
  t := target.Normalized;
  if ((t.stop < s.start) or (t.start > s.stop)) then
    Exit([Self]);
  if (t.start > s.start) then
    Result.Supply(TRange.Construct(s.start, (t.start - 1)));
  if (t.stop < s.stop) then
    Result.Supply(TRange.Construct((t.stop + 1), s.stop));
end;

{==============================================================================]
  <Concut>
  @action: Conjoins adjacent ranges or cuts out the shared overlap between Self
           and target, returning an array of 0 to 2 disjoint, non-adjacent
           TRange segments in ascending order.
  @note: Normalizes ascending/descending bounds internally before computing
         exclusive intervals. Returns an empty array if both normalized ranges
         span the exact same interval. Directly adjacent ranges are merged into
         a single continuous segment, separated disjoint ranges are returned as
         two ascending segments, and overlapping ranges return only their
         non-shared outer edges.
[==============================================================================}
function TRangeHelper.Concut(const target: TRange): TRangeArray; overload;
var
  s, t: TRange;
  c: Integer;
begin
  s := Self.Normalize;
  t := target.Normalize;
  if (((s.stop + 1) = t.start) or ((t.stop + 1) = s.start)) then
    Exit([TRange.Construct(Min(s.start, t.start), Max(s.stop, t.stop))]);
  if (s.stop < t.start) then
    Exit([s, t]);
  if (t.stop < s.start) then
    Exit([t, s]);
  SetLength(Result, 2);
  c := 0;
  if (s.start <> t.start) then
    Result[c.Increase] := TRange.Construct(Min(s.start, t.start), (Max(s.start, t.start) - 1));
  if (s.stop <> t.stop) then
    Result[c.Increase] := TRange.Construct((Min(s.stop, t.stop) + 1), Max(s.stop, t.stop));
  SetLength(Result, c);
end;

{==============================================================================]
  <Cutout>
  @action: Subtracts the target range from Self, returning the remaining pieces.
  @return: A TRangeArray containing:
           - 0 elements: If Self was completely consumed by target.
           - 1 element:  If Self was clipped at one end or not hit at all.
           - 2 elements: If the target punched a hole through the middle of Self.
[==============================================================================}
function TRangeHelper.Cutout(const target: TRange): TRangeArray; overload;
var
  s, t: TRange;
  procedure C(const A, B: Integer);
  begin
    SetLength(Result, (Result.Length + 1));
    if Self.Asceal then
      Result[High(Result)] := TRange.Construct(A, B)
    else
      Result[High(Result)] := TRange.Construct(B, A);
  end;
begin
  if not Self.Intersects(target) then
    Exit([Self]);
  s := Self.Normalized;
  t := target.Normalized;
  SetLength(Result, 0);
  if (s.start < t.start) then
    C(s.start, (t.start - 1));
  if (s.stop > t.stop) then
    C((t.stop + 1), s.stop);
  if Self.Descending then
    Result.Reverse;
end;

{==============================================================================]
  <Disjunct>
  @action: Returns an array of ranges representing the symmetric difference 
           between two ranges (the areas where they do not overlap).
  @note: Uses normalized versions of both ranges. Returns 0 to 2 range segments 
         representing the "outer" parts of the combined span.
[==============================================================================}
function TRangeHelper.Disjunct(const other: TRange): TRangeArray; overload;
var
  s, o: TRange;
  a, b: Integer;
begin
  SetLength(Result, 0);
  s := Self.Normalized;
  o := other.Normalized;
  a := Min(s.start, o.start);
  b := (Max(s.start, o.start) - 1);
  if (a <= b) then
    Result.Supply(TRange.Construct(a, b));
  a := (Min(s.stop, o.stop) + 1);
  b := Max(s.stop, o.stop);
  if (a <= b) then
    Result.Supply(TRange.Construct(a, b));
end;

{==============================================================================]
  <Disjunction>
  @action: Returns the symmetric difference (XOR) of two ranges
  @note: Elements that belong to exactly one range, not both.
         Result is 0, 1, or 2 disjoint ranges sorted left-to-right.
  @examples:
    // Partial overlap
    TRange(1, 10).Disjunction(TRange(5, 15))  -> [(1,4), (11,15)]
    
    // Complete containment
    TRange(1, 10).Disjunction(TRange(3, 7))   -> [(1,2), (8,10)]
    
    // Identical ranges
    TRange(1, 10).Disjunction(TRange(1, 10))  -> []
    
    // Adjacent ranges (touching)
    TRange(1, 5).Disjunction(TRange(6, 10))   -> [(1,5), (6,10)]
    
    // One range completely inside another (touching boundary)
    TRange(1, 10).Disjunction(TRange(1, 5))   -> [(6,10)]
    
    // Disjoint ranges (no overlap)
    TRange(1, 5).Disjunction(TRange(7, 10))   -> [(1,5), (7,10)]
    
    // Single element ranges
    TRange(5, 5).Disjunction(TRange(5, 5))    -> []
    TRange(5, 5).Disjunction(TRange(3, 3))    -> [(3,3), (5,5)]
    
    // Descending ranges (automatically normalized)
    TRange(10, 1).Disjunction(TRange(5, 15))  -> [(1,4), (11,15)]
[==============================================================================}
function TRangeHelper.Disjunction(const other: TRange): TRangeArray; overload;
var
  s, o: TRange;
  b, e, l, r: Integer;
begin
  SetLength(Result, 0);
  s := Self.Normalized;
  o := other.Normalized;
  l := Min(s.start, o.start);
  r := Max(s.stop, o.stop);
  b := Max(s.start, o.start);
  e := Min(s.stop, o.stop);
  if (b > e) then
    Exit([s, o]);
  if (l < b) then
    Result.Supply(TRange.Construct(l, (b - 1)));
  if (e < r) then
    Result.Supply(TRange.Construct((e + 1), r));
end;

{==============================================================================]
  <Exclave>
  @action: Returns the portion(s) of a universe range that fall outside Self.
  @note:
    - Normalizes both Self and universe first, so direction (ascending/
      descending) of either range doesn't affect the calculation.
    - Can produce zero, one, or two resulting ranges depending on where Self
      sits relative to universe:
        * Self fully covers universe        -> empty result (0 ranges)
        * Self touches one edge of universe -> one resulting range
        * Self sits strictly inside universe -> two resulting ranges
    - Uses r.Increase as a fused post-increment index/counter, writing into
      Result[r] then advancing r in a single expression per branch.
[==============================================================================}
function TRangeHelper.Exclave(const universe: TRange): TRangeArray; overload;
var
  r: Integer;
  s, u: TRange;
begin
  s := Self.Normalized;
  u := universe.Normalized;
  SetLength(Result, 2);
  r := 0;
  if (s.start > u.start) then
    Result[r.Increase].Create(u.start, Min((s.start - 1), u.stop));
  if (s.stop < u.stop) then
    Result[r.Increase].Create(Max((s.stop + 1), u.start), u.stop);
  SetLength(Result, r);
end;


{==============================================================================]
  <Exor>
  @action: Computes the symmetric difference between ranges A and B, returning
           an array of 0 to 2 disjoint, non-adjacent TRange segments containing
           all values present in either A or B, but not both.
  @note: Normalizes ascending/descending bounds internally before computing
         exclusive intervals. Returns an empty array if A and B span the exact
         same interval. If A and B are disjoint, both normalized ranges are
         returned in ascending order, unless they are directly adjacent, in
         which case they are merged into a single range. For overlapping
         ranges, only the outer edges are returned, never the shared middle.
[==============================================================================}
function TRangeHelper.Exor(const target: TRange): TRangeArray; overload;
var
  s, t: TRange;
begin
  Result := [];
  s := Self.Normalize;
  t := target.Normalize;
  if (s = t) then
    Exit;
  if (s.stop < t.start) then
  begin
    if ((s.stop + 1) = t.start) then
      Exit([TRange.Construct(s.start, t.stop)]);
    Exit([s, t]);
  end;
  if (t.stop < s.start) then
  begin
    if ((t.stop + 1) = s.start) then
      Exit([TRange.Construct(t.start, s.stop)]);
    Exit([t, s]);
  end;
  if (s.start <> t.start) then
    Result := (Result + [TRange.Construct(Min(s.start, t.start), (Max(s.start, t.start) - 1))]);
  if (s.stop <> t.stop) then
    Result := (Result + [TRange.Construct((Min(s.stop, t.stop) + 1), Max(s.stop, t.stop))]);
end;

{==============================================================================]
  <Xored>
  @action: Computes the symmetric difference between Self and target, returning
           an array of 0 to 2 disjoint, ascending TRange segments containing
           all values present in either range, but not both.
  @note: Normalizes ascending/descending bounds internally before computing
         exclusive intervals. Returns an empty array if both normalized ranges
         span the exact same interval. If the ranges are disjoint (including
         directly adjacent ranges), both normalized segments are returned in
         ascending order without merging. For overlapping ranges, only the
         non-shared outer edge segments are returned.
[==============================================================================}
function TRangeHelper.Xored(const target: TRange): TRangeArray; overload;
var
  s, t: TRange;
  z, i, j: Integer;
  p: array[0..3] of Integer;
begin
  Result := [];
  s := Self.Normalize;
  t := target.Normalize;
  if (s = t) then
    Exit;
  p[0] := s.start;
  p[1] := (s.stop + 1);
  p[2] := t.start;
  p[3] := (t.stop + 1);
  for i := 1 to 3 do
  begin
    z := p[i];
    j := (i - 1);
    while ((j >= 0) and (p[j] > z)) do
    begin
      p[j + 1] := p[j];
      Dec(j);
    end;
    p[j + 1] := z;
  end;
  if (p[0] < p[1]) then
    Result := (Result + [TRange.Construct(p[0], (p[1] - 1))]);
  if (p[2] < p[3]) then
    Result := (Result + [TRange.Construct(p[2], (p[3] - 1))]);
end;

{==============================================================================]
  <Xorify>
  @action: Computes the symmetric difference between Self and target, returning
           an array of 0 to 2 disjoint, non-adjacent TRange segments in
           ascending order containing values present in either range, but not
           both.
  @note: Normalizes ascending/descending bounds internally before computing
         exclusive intervals. Returns an empty array if both normalized ranges
         span the exact same interval. Directly adjacent ranges are merged into
         a single continuous segment, separated disjoint ranges are returned as
         two ascending segments, and overlapping ranges return only their
         non-shared outer edges.
[==============================================================================}
function TRangeHelper.Xorify(const target: TRange): TRangeArray; overload;
var
  l, h, s, t: TRange;
begin
  s := Self.Normalize;
  t := target.Normalize;
  l := TRange.Construct(Min(s.start, t.start), Min(s.stop, t.stop));
  h := TRange.Construct(Max(s.start, t.start), Max(s.stop, t.stop));
  if ((l.stop + 1) < h.start) then
    Exit([TRange.Construct(l.start, l.stop), TRange.Construct(h.start, h.stop)]);
  if ((l.stop + 1) = h.start) then
    Exit([TRange.Construct(l.start, h.stop)]);
  Result := [];
  if (l.start < h.start) then
    Result := (Result + [TRange.Construct(l.start, (h.start - 1))]);
  if (l.stop < h.stop) then
    Result := (Result + [TRange.Construct((l.stop + 1), h.stop)]);
end;

{==============================================================================]
  <Xorred>
  @action: Returns elements that are in either range but not in both
  @note: Result may be 0, 1, or 2 disjoint ranges
  @example:
    TRange(1, 10).Xorred(TRange(5, 15))  -> [(1,4), (11,15)]
    TRange(1, 10).Xorred(TRange(3, 7))   -> [(1,2), (8,10)]
    TRange(1, 10).Xorred(TRange(1, 10))  -> []
[==============================================================================}
function TRangeHelper.Xorred(const other: TRange): TRangeArray; overload;
var
  s, o: TRange;
begin
  SetLength(Result, 0);
  s := Self.Normalized;
  o := other.Normalized;
  if ((s.stop < o.start) or (o.stop < s.start)) then
    Exit([s, o]);
  if ((s.start >= o.start) and (s.stop <= o.stop)) then
  begin
    if (s.start > o.start) then
      Result.Supply(TRange.Construct(o.start, (s.start - 1)));
    if (s.stop < o.stop) then
      Result.Supply(TRange.Construct((s.stop + 1), o.stop));
    Exit;
  end;
  if ((o.start >= s.start) and (o.stop <= s.stop)) then
  begin
    if (o.start > s.start) then
      Result.Supply(TRange.Construct(s.start, (o.start - 1)));
    if (o.stop < s.stop) then
      Result.Supply(TRange.Construct((o.stop + 1), s.stop));
    Exit;
  end;
  if (s.start < o.start) then
    Result.Supply(TRange.Construct(s.start, (o.start - 1)))
  else if (o.start < s.start) then
    Result.Supply(TRange.Construct(o.start, (s.start - 1)));
  if (s.stop > o.stop) then
    Result.Supply(TRange.Construct((o.stop + 1), s.stop))
  else if (o.stop > s.stop) then
    Result.Supply(TRange.Construct((s.stop + 1), o.stop));
end;
{$ENDIF}
