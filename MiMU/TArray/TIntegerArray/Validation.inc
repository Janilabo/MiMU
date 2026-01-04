{$IFDEF HELPERS}
function Pure(const allowed: TIntegerArray): Boolean; overload;
function Special: Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Pure>
  @action: Returns true if arr is made with only allowed items.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Pure(const allowed: TIntegerArray): Boolean; overload;
var
  a: TIntegerArray;
  i: Integer;
begin
  if allowed.Empty then
    Exit(False);
  a := allowed.QuickSorted;
  for i := 0 to High(Self) do
    if not a.BinaryContains(Self[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Special>
  @action: Returns true if parity of every pair of adjacent element differs each other.
  @note: An element in each pair must be even and other must be odd.
[==============================================================================}
function TIntegerArrayHelper.Special: Boolean;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i].Parity = Self[i - 1].Parity) then
      Exit(False);
  Result := True;
end;
{$ENDIF}
