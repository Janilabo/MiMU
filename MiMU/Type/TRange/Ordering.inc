{$IFDEF METHODS}
function Asc: TIntegerArray; overload; cdecl;
function Ascend: TRange; cdecl;
function Ascended: TRange; cdecl;
function Desc: TIntegerArray; overload; cdecl;
function Descend: TRange; cdecl;
function Descended: TRange; cdecl;
function Order(const oAscending: Boolean = True): Boolean; overload; cdecl;
function Ordered(const oAscending: Boolean = True): TRange; overload; cdecl;
function Sort(const oAscending: Boolean = True): Boolean; overload; cdecl;
function Sorted(const oAscending: Boolean = True): TRange; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Asc>
  @action: Returns an ascending sequence of integers from Start to Stop.
  @note: If Start > Stop, the order is still ascending (from the smaller to the larger value).
[==============================================================================}
function TRange.Asc: TIntegerArray; overload; cdecl;
var
  l, h, i: Integer;
begin
  SetLength(Result, Self.Size(l, h));
  for i := 0 to (h - l) do
    Result[i] := (l + i);
end;

{==============================================================================]
  <Ascend>
  @action: Returns ascending TRange of Self.
  @note: None.
[==============================================================================}
function TRange.Ascend: TRange; cdecl;
begin
  Result.start := Min(Self.start, Self.stop);
  Result.stop := Max(Self.stop, Self.start);
end;

{==============================================================================]
  <Ascended>
  @action: Returns TRange in ascending order.
  @note: None.
[==============================================================================}
function TRange.Ascended: TRange; cdecl;
begin
  if (Self.stop > Self.start) then
    Result.Create(Self.start, Self.stop)
  else
    Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <Desc>
  @action: Returns a descending sequence of integers from Stop down to Start.
  @note: If Start < Stop, the order is still descending (from the larger to the smaller value).
[==============================================================================}
function TRange.Desc: TIntegerArray; overload; cdecl;
var
  l, h, i: Integer;
begin
  SetLength(Result, Self.Size(l, h));
  for i := 0 to (h - l) do
    Result[i] := (h - i);
end;

{==============================================================================]
  <Descend>
  @action: Returns descending TRange of Self.
  @note: None.
[==============================================================================}
function TRange.Descend: TRange; cdecl;
begin
  Result.start := Max(Self.stop, Self.start);
  Result.stop := Min(Self.start, Self.stop);
end;

{==============================================================================]
  <Descended>
  @action: Returns TRange in descending order.
  @note: None.
[==============================================================================}
function TRange.Descended: TRange; cdecl;
begin
  if (Self.start > Self.stop) then
    Result.Create(Self.start, Self.stop)
  else
    Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <Order>
  @action: Sorts the current TRange in-place according to oAscending.
           Returns True if a swap of Start and Stop was performed.
           Uses arithmetic trick with Ord() to determine order.
  @note: In-place version of Ordered; efficient, works for both ascending and descending.
[==============================================================================}
function TRange.Order(const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := (((Ord(oAscending) * 2 - 1) * (Self.Stop - Self.Start)) < 0);
  if Result then
    Swap(Self.start, Self.stop);
end;

{==============================================================================]
  <Ordered>
  @action: Returns a new TRange with Start and Stop ordered according to oAscending.
           Uses arithmetic trick with Ord() to determine order.
  @note: Functional version; does NOT modify the current record. Works for both ascending and descending.
[==============================================================================}
function TRange.Ordered(const oAscending: Boolean = True): TRange; overload; cdecl;
begin
  if (((Ord(oAscending) * 2 - 1) * (Self.Stop - Self.Start)) >= 0) then
    Result.Create(Self.Start, Self.Stop)
  else
    Result.Create(Self.Stop, Self.Start);
end;

{==============================================================================]
  <Sort>
  @action: Sorts the current TRange in-place according to oAscending.
           Returns True if a swap of Start and Stop was performed.
  @note: If oAscending=True, Start <= Stop after call; if False, Start >= Stop.
[==============================================================================}
function TRange.Sort(const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := ((oAscending and (Self.start > Self.stop)) or ((not oAscending) and (Self.stop > Self.start)));
  if Result then
    Swap(Self.stop, Self.start);
end;

{==============================================================================]
  <Sorted>
  @action: Returns a new TRange with Start and Stop ordered according to aAscending.
           Does NOT modify the current record.
  @note: If aAscending=True, ensures Start <= Stop; if False, Start >= Stop.
[==============================================================================}
function TRange.Sorted(const oAscending: Boolean = True): TRange; overload; cdecl;
begin
  if ((oAscending and (Self.start > Self.stop)) or ((not oAscending) and (Self.start < Self.stop))) then
    Result.Create(Self.stop, Self.start)
  else
    Result.Create(Self.start, Self.stop);
end;
{$ENDIF}