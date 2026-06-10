{$IFDEF HELPERS}
function Disparate(const target: TIntegerArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Disparate>
  @action: Compares the current integer array with a target array using block 
           memory evaluation. Returns True if they differ.
  @note: Highly optimized approach utilizing Free Pascal's 'CompareMem' intrinsic. 
         Bypasses element-by-element loops by directly scanning the raw binary data 
         blocks in memory. Returns True immediately if lengths vary.
[==============================================================================}
function TIntegerArrayHelper.Disparate(const target: TIntegerArray): Boolean; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (l <> target.Length) then
    Exit(True);
  if (l = 0) then
    Exit(False);
  Result := not CompareMem(@Self[0], @target[0], (l * SizeOf(Self[0])));
end;
{$ENDIF}