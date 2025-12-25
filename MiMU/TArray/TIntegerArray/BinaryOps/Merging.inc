{$IFDEF HELPERS}
function BMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryCombine(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryCombined(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BMerge>
  @action: Combines two sorted integer arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function TIntegerArrayHelper.BMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  i.Create(0, items.Size);
  s.Create(0, Self.Size);
  SetLength(Result, (i.stop + s.stop));
  case aAscending of
    True:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] <= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
    False:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] >= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
  end;
  if (s.start < s.stop) then
    Move(Self[s.start], Result[l.Increase(s.Delta)], (s.Delta * SizeOf(Integer)));
  if (i.start < i.stop) then
    Move(items[i.start], Result[l], (i.Delta * SizeOf(Integer)));
end;

{==============================================================================]
  <BMerged>
  @action: Combines two sorted integer arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function TIntegerArrayHelper.BMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  s.Create(0, Self.Size);
  i.Create(0, items.Size);
  SetLength(Result, (s.stop + i.stop));
  while ((s.start < s.stop) and (i.start < i.stop)) do
    if Self[s.start].Precede(items[i.start], aAscending) then
      Result[l.Increase] := Self[s.start.Increase]
    else
      Result[l.Increase] := items[i.start.Increase];
  if (s.start < s.stop) then
    Move(Self[s.start], Result[l.Increase(s.Delta)], (s.Delta * SizeOf(Integer)));
  if (i.start < i.stop) then
    Move(items[i.start], Result[l], (i.Delta * SizeOf(Integer)));
end;

{==============================================================================]
  <BinaryMerge>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryMerge}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryMerge}

{==============================================================================]
  <BinaryMerged>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryMerged}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryMerged}

{==============================================================================]
  <BinaryCombine>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryCombine(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryCombine}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryCombine}

{==============================================================================]
  <BinaryCombined>
  @action: Merge two sorted arrays into one sorted array.
  @note: Both arrays must be sorted in the same order (ascending or descending).
         The result is a new array that combines both inputs, preserving order.
         Complexity: O(n + m)
[==============================================================================}
function TIntegerArrayHelper.BinaryCombined(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryCombined}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryCombined}
{$ENDIF}
