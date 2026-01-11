{$IFDEF HELPERS}
function Blend(const items: MArray; const index: Integer = 2147483647): MArray; overload;
function Combine(const b: MArray): MArray; overload;
function SwapMerged(var target: MArray): MArray; overload;
function SwappedMerge(var target: MArray): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Blend> 
  @action: Blends items with array, cleverly.
  @note: None.
[==============================================================================}
function MArrayHelper.Blend(const items: MArray; const index: Integer = 2147483647): MArray; overload;
var
  s, l, p, r, i: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit(items.Copy);
  l := items.Size;
  if (l = 0) then
    Exit(Self.Copy);
  case (index > 0) of
    True:
    begin
      p := index;
      if (p > s) then
        p := s;
      r := (p + l);
      SetLength(Result, r);
      for i := 0 to (p - 1) do
        Result[i] := Self[i];
      for i := 0 to (l - 1) do
        Result[p + i] := items[i];
    end;
	False:
    begin
      p := ((s + index) - 1);
      if (p < 0) then
        p := 0;
      r := (l + (s - p));
      SetLength(Result, r);
      for i := 0 to (l - 1) do
        Result[i] := items[i];
      for i := p to (s - 1) do
        Result[l + (i - p)] := Self[i];
    end;
  end;
end;

{==============================================================================]
  <Combine>
  @action: Combines arrays arr and b together as single array.
  @note: This is an alternative method. :)
[==============================================================================}
function MArrayHelper.Combine(const b: MArray): MArray; overload;
begin
  SetLength(Result, 0);
  Insert(Self, Result, 0);
  Insert(b, Result, Self.Size);
end;

{==============================================================================]
  <SwapMerged>
  @action: Swaps the contents of Self and target arrays manually using an
           auxiliary array, and returns a new array containing all elements
           from both arrays combined in the **original order** (before swap).
  @note: The swap is performed by copying elements from Self and target
         into a temporary array in reverse order, then assigning them back.
         This method works but is less efficient (O(n)) because every element
         is copied. Use this if the merged array should reflect the **pre-swap
         ordering**.
[==============================================================================}
function MArrayHelper.SwapMerged(var target: MArray): MArray; overload;
var
  r, t, s, i: Integer;
begin
  s := Self.Size;
  t := target.Size;
  r := (s + t);
  SetLength(Result, r);
  if (r = 0) then
    Exit;
  for i := High(target) downto 0 do
    Result[r.Decrement] := target[i];
  for i := High(Self) downto 0 do
    Result[r.Decrement] := Self[i];
  SetLength(Self, t);
  SetLength(target, s);
  for i := 0 to (t - 1) do
    Self[i] := Result[s + i];
  for i := 0 to (s - 1) do
    target[i] := Result[i];
end;

{==============================================================================]
  <SwappedMerge>
  @action: Swaps the contents of Self and target arrays using the reference
           swap method (Self.Swapped), and returns a new array containing all
           elements from both arrays combined in the **post-swap order**.
  @note: This implementation is more efficient (O(1) for the swap) because
         it swaps references rather than copying elements individually.
         The merged array is then constructed by iterating over Self and
         target. This is preferred for large dynamic arrays, and the
         resulting array reflects the swapped positions of Self and target.
[==============================================================================}
function MArrayHelper.SwappedMerge(var target: MArray): MArray; overload;
var
  t, s, i: Integer;
begin
  s := Self.Size;
  t := target.Size;
  SetLength(Result, (s + t));
  if ((s + t) = 0) then
    Exit;
  Self.Swapped(target);
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(target) do
    Result[t + i] := target[i];
end;
{$ENDIF}