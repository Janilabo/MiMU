{$IFDEF HELPERS}
function Special: Boolean; overload;
function Unex: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Special>
  @action: Returns true if parity of every pair of adjacent element differs each other.
  @note: An element in each pair must be even and other must be odd.
[==============================================================================}
function TIntegerArrayHelper.Special: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i].Parity = Self[i - 1].Parity) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Unex>
  @action: Returns True if no two elements in the Integer array are equal to one
           another; False if any duplicate value exists.
  @note: Pigeonhole fast-reject: if the value range (h - l + 1) is smaller than the element count,
         a duplicate is guaranteed and no scan is needed.
         Otherwise uses a counting array over the range — O(n), no sort, no `<` required. Range span should stay bounded
         relative to array length; sparse high-range data makes `d` disproportionately large.
[==============================================================================}
function TIntegerArrayHelper.Unex: Boolean; overload;
var
  l, h, p, i, b, s: Integer;
  d: TBooleanArray;
begin
  s := Self.Length;
  if (s < 2) then
    Exit(True);
  Self.GetMinMax(l, h);
  b := ((h - l) + 1);
  if (b < s) then
    Exit(False);
  d.Create(b, False);
  for i := 0 to (s - 1) do
  begin
    p := (Self[i] - l);
    if d[p] then
      Exit(False);
    d[p] := True;
  end;
  Result := True;
end;
{$ENDIF}
