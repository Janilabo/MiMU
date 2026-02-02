{$IFDEF METHODS}
function At(const index: Integer = 0): Integer; overload;
function Elem(const index: Integer = 0): Integer; overload;
function Element(const index: Integer = 0): Integer; overload;
function Entry(const index: Integer = 0): Integer; overload;
function Fetch(const index: Integer = 0): Integer; overload;
function Get(const index: Integer = 0): Integer; overload;
function Member(const index: Integer = 0): Integer; overload;
function Nth(const index: Integer = 0): Integer; overload;
function ValueAt(const offset: Integer = 0): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <At>
  @action: Returns the value at the given zero-based offset from Start,
           moving forward for ascending ranges and backward for descending ranges.
  @note: No bounds checking is performed.
         Index values outside the range extent will extrapolate beyond Stop.
         Equivalent to direct offset addressing.
[==============================================================================}
function TRange.At(const index: Integer = 0): Integer; overload;
begin
  if Self.Ascending then
    Result := (Self.start + index)
  else
    Result := (Self.start - index);
end;

{==============================================================================]
  <Elem>
  @action: Returns the value at the given zero-based offset from Start,
           using the sign of the range direction.
  @note: Direction is determined by (Stop - Start).
         No bounds checking is performed.
[==============================================================================}
function TRange.Elem(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (Sign(Self.stop - Self.start) * index));
end;

{==============================================================================]
  <Element>
  @action: Returns the element at the given index, wrapping the index
           within the range size.
  @note: Index is taken modulo Size, allowing cyclic access.
         Negative indices are supported.
         Direction is respected (ascending or descending).
[==============================================================================}
function TRange.Element(const index: Integer = 0): Integer; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  i := (index mod s);
  if (i < 0) then
    i := (i + s);
  if Self.Descending then
    Result := (Self.start - i)
  else
    Result := (Self.start + i);
end;

{==============================================================================]
  <Entry>
  @action: Returns the value at the given offset from Start using
           bitwise arithmetic to account for direction.
  @note: Uses XOR and ordinal direction for branch-free computation.
         No bounds checking is performed.
[==============================================================================}
function TRange.Entry(const index: Integer = 0): Integer; overload;
var
  m: Integer;
begin
  m := -Ord(Self.Descending);
  Result := (Self.start + ((index xor m) - m));
end;

{==============================================================================]
  <Fetch>
  @action: Returns the value at the given offset from Start,
           explicitly branching on range direction.
  @note: Uses explicit control flow rather than expressions.
         No bounds checking is performed.
[==============================================================================}
function TRange.Fetch(const index: Integer = 0): Integer; overload;
label 
  forward, backward;
begin
  if Self.Ascending then
    goto forward
  else
    goto backward;   
forward:
  Result := (Self.start + index);
  Exit;
backward:
  Result := (Self.start - index);
end;

{==============================================================================]
  <Get>
  @action: Returns the value at the given offset from Start using
           a conditional multiplier based on direction.
  @note: Uses IfThen() for direction selection.
         No bounds checking is performed.
[==============================================================================}
function TRange.Get(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + (IfThen(Self.Descending, -1, 1) * index));
end;

{==============================================================================]
  <Member>
  @action: Returns the value at the given offset from Start using
           conditional selection on range direction.
  @note: Expressed using IfThen() with explicit branch semantics.
         No bounds checking is performed.
[==============================================================================}
function TRange.Member(const index: Integer = 0): Integer; overload;
begin
  Result := IfThen(Self.Ascending, (Self.start + index), (Self.start - index));
end;

{==============================================================================]
  <Nth>
  @action: Returns the N-th value from Start, respecting range direction,
           using ordinal arithmetic.
  @note: Direction is encoded via Ord(not Descending).
         No bounds checking is performed.
[==============================================================================}
function TRange.Nth(const index: Integer = 0): Integer; overload;
begin
  Result := (Self.start + ((Ord(not Self.Descending) * 2) - 1) * index);
end;

{==============================================================================]
  <ValueAt>
  @action: Returns the value at a specified offset from the start of the range, accounting for ascending or descending order.
  @note: Offset defaults to 0. The method assumes the caller ensures the offset stays within valid range bounds. Works for both ascending and descending ranges.
[==============================================================================}
function TRange.ValueAt(const offset: Integer = 0): Integer; overload;
begin
  case Self.Descending of
    False: Result := (start + offset);
    True: Result := (start - offset);
  end;
end;
{$ENDIF}