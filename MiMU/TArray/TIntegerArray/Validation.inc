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
function TIntegerArrayHelper.Pure(const allowed: TIntegerArray): Boolean; overload; var a: TIntegerArray; {$DEFINE Skeleton_Pure}{$I ../Skeletons.inc}{$UNDEF Skeleton_Pure}

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
