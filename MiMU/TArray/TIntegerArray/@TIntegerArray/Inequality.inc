{$IFDEF HELPERS}
function Disparate(const target: TIntegerArray): Boolean; overload;
function Incomparable(const target: TIntegerArray): Boolean; overload;
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

{==============================================================================]
  <Incomparable>
  @action: Compares the current integer array with a target array using 64-bit
           pointer casting. Returns True if they differ.
  @note: Pairs two 32-bit integers into a single 64-bit chunk (`PInt64`) to
         halve loop iterations. Aborts early returning True on the first
         found discrepancy or length mismatch. Automatically cleans up trailing
         odd elements.
[==============================================================================}
function TIntegerArrayHelper.Incomparable(const target: TIntegerArray): Boolean; overload;
var
  l, i, d: Integer;
  s, t: PInt64;
begin
  l := Self.Length;
  if (l <> target.Length) then
    Exit(True);
  d := (l div 2);
  s := PInt64(@Self[0]);
  t := PInt64(@target[0]);
  for i := 0 to (d - 1) do
  begin
    if (s^ <> t^) then
      Exit(True);
    Inc(s);
    Inc(t);
  end;
  if ((l mod 2) <> 0) then
    Result := (Self[l - 1] <> target[l - 1])
  else
    Result := False;
end;
{$ENDIF}