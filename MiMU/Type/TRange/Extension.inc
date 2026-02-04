{$IFDEF METHODS}
function Absorb(const val: Integer): Boolean; overload;
function Extend(const val: Integer): Boolean; overload;
function Extend(const target: TRange): Boolean; overload;
function ExtendMax(const val: Integer): Boolean; overload;
function ExtendMin(const val: Integer): Boolean; overload;
function Include(const val: Integer): TRange; overload;
function Include(const target: TRange): TRange; overload;
function IncludeMax(const val: Integer): TRange; overload;
function IncludeMin(const val: Integer): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Absorb>
  @action: Expands the range to include the given value while preserving ascending/descending order.
  @note: If the value is already inside the range, the range remains unchanged.
         Returns true if value was added in.
[==============================================================================}
function TRange.Absorb(const val: Integer): Boolean; overload;
var
  s: TRange;
begin
  s := Self;
  case Self.Ascending of
    True:
    if (val < Self.start) then
      Self.start := val
    else if (val > Self.stop) then
      Self.stop := val;
    False:
    if (val > Self.start) then
      Self.start := val
    else if (val < Self.stop) then
      Self.stop := val;
  end;
  Result := (Self <> s);
end;

{==============================================================================]
  <Extend>
  @action: Returns true TRange is extended with val (val is not yet in range)
  @note: None.
[==============================================================================}
function TRange.Extend(const val: Integer): Boolean; overload;
begin
  case Self.Descending of
    True:
    if (val > Self.start) then
      Self.start := val
    else if (val < Self.stop) then
      Self.stop := val
    else
      Exit(False);
    False:
    if (val < Self.start) then
      Self.start := val
    else if (val > Self.stop) then
      Self.stop := val
    else
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <Extend>
  @action: Expands the current range so that it fully contains the target range.
           The method works for both ascending and descending ranges.
           - For ascending ranges, it adjusts Start and/or Stop if the target
             extends beyond the current bounds.
           - For descending ranges, it adjusts Start and/or Stop accordingly
             to maintain the descending order.
  @note:
    - The target range is first normalized before comparison.
    - The current range is modified only if at least one bound needs
      to be extended.
    - The function returns True if the range changed; otherwise, False.
    - Equality comparison is used to detect modifications (`Self <> r`).
[==============================================================================}
function TRange.Extend(const target: TRange): Boolean; overload;
var
  n, r: TRange;
begin
  r := Self;
  n := target.Normalize;
  case Self.Descending of
    True:
	begin
      if (n.stop > Self.start) then
        Self.start := n.stop;
      if (n.start < Self.stop) then
        Self.stop := n.start;
    end;
    False:
	begin
      if (n.start < Self.start) then
        Self.start := n.start;
      if (n.stop > Self.stop) then
        Self.stop := n.stop;
    end;
  end;
  Result := (Self <> r);
end;

{==============================================================================]
  <ExtendMax>
  @action: Extends the upper bound of the range if the supplied value lies
           outside the current maximum in the direction of the range.
           For ascending ranges, this extends Stop.
           For descending ranges, this extends Start.
  @note: The range is modified only if the value truly expands it.
         If the value is inside or equal to the current bounds, the
         range remains unchanged and the function returns False.
[==============================================================================}
function TRange.ExtendMax(const val: Integer): Boolean; overload;
begin
  case Self.Descending of
    True:
    if (val > Self.start) then
      Self.start := val
    else
      Exit(False);
    False:
    if (val > Self.stop) then
      Self.stop := val
    else
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <ExtendMin>
  @action: Extends the lower bound of the range if the supplied value lies
           outside the current minimum in the direction of the range.
           For ascending ranges, this extends Start.
           For descending ranges, this extends Stop.
  @note: The range is modified only if the value truly expands it.
         If the value is inside or equal to the current bounds, the
         range remains unchanged and the function returns False.
[==============================================================================}
function TRange.ExtendMin(const val: Integer): Boolean; overload;
begin
  case Self.Descending of
    True:
    if (val < Self.stop) then
      Self.stop := val
    else
      Exit(False);
    False:
    if (val < Self.start) then
      Self.start := val
    else
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <Include>
  @action: Expands the range to include the given value while preserving ascending/descending order.
  @note: If the value is already inside the range, the range remains unchanged.
[==============================================================================}
function TRange.Include(const val: Integer): TRange; overload;
begin
  if Self.Ascending then
    Result.Create(Min(Self.Minimum, val), Max(Self.Maximum, val))
  else
    Result.Create(Max(Self.Maximum, val), Min(Self.Minimum, val));
end;

{==============================================================================]
  <Include>
  @action: Returns a new range that fully encompasses both the current range
           and the target range.
           - For ascending ranges, the new range's Start is the smaller of the
             two ranges' starts, and Stop is the larger of the two ranges' stops.
           - For descending ranges, the new range's Start is the larger of the
             two ranges' starts (or stops, depending on descending order), and
           Stop is the smaller of the two.
  @note:
    - The target range is normalized before inclusion.
    - The original ranges (`Self` and `target`) are not modified.
    - This function always returns a range that contains both ranges,
      regardless of their relative positions or directions.
[==============================================================================}
function TRange.Include(const target: TRange): TRange; overload;
var
  r: TRange;
begin
  r := target.Normalize;
  if Self.Ascending then
    Result.Create(Min(Self.Minimum, r.start), Max(Self.Maximum, r.stop))
  else
    Result.Create(Max(Self.Maximum, r.stop), Min(Self.Minimum, r.start));
end;

{==============================================================================]
  <IncludeMax>
  @action: Ensures that the upper bound of the range is at least <val>,
           expanding the range outward if necessary.
  @note: The range is never reduced. If <val> is already within the range,
         the original range is returned unchanged. Works correctly for
         both ascending and descending ranges.
[==============================================================================}
function TRange.IncludeMax(const val: Integer): TRange; overload;
begin
  if Self.Ascending then
    Result.Create(Self.start, Max(Self.Maximum, val))
  else
    Result.Create(Max(Self.Maximum, val), Self.stop);
end;

{==============================================================================]
  <IncludeMin>
  @action: Ensures that the lower bound of the range is at most <val>,
           expanding the range outward if necessary.
  @note: The range is never reduced. If <val> is already within the range,
         the original range is returned unchanged. Works correctly for
         both ascending and descending ranges.
[==============================================================================}
function TRange.IncludeMin(const val: Integer): TRange; overload;
begin
  if Self.Ascending then
    Result.Create(Min(Self.Minimum, val), Self.stop)
  else
    Result.Create(Self.start, Min(Self.Minimum, val));
end;
{$ENDIF}
