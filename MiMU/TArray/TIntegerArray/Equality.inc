{$IFDEF HELPERS}
function Concordant(const target: TIntegerArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Concordant>
  @action: Compares the current integer array with a target array using block
           memory evaluation. Returns True if they are perfectly equal.
  @note: Highly optimized approach utilizing Free Pascal's 'CompareMem' intrinsic.
         Directly matches binary blocks in memory for maximum throughput.
         Returns False immediately if lengths vary.
[==============================================================================}
function TIntegerArrayHelper.Concordant(const target: TIntegerArray): Boolean; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (l <> target.Length) then
    Exit(False);
  if (l = 0) then
    Exit(True);
  Result := CompareMem(@Self[0], @target[0], (l * SizeOf(Self[0])));
end; 
{$ENDIF}