{$IFDEF HELPERS}
function Concordant(const target: TIntegerArray): Boolean; overload;
function Comparable(const target: TIntegerArray): Boolean; overload;
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

{==============================================================================]
  <Comparable>
  @action: Compares the current integer array with a target array using 64-bit
           pointer casting. Returns True if they match perfectly.
  @note: Pairs two 32-bit integers into a single 64-bit chunk (`PInt64`) to
         halve loop iterations. Aborts early returning False if any mismatch
         or length variance is discovered. Evaluates trailing odd elements
         on final pass.
[==============================================================================}
function TIntegerArrayHelper.Comparable(const target: TIntegerArray): Boolean; overload;
var
  l, i, d: Integer;
  s, t: PInt64;
begin
  l := Self.Length;
  if (l <> target.Length) then
    Exit(False);
  if (l = 0) then
    Exit(True);
  d := (l div 2);
  s  := PInt64(@Self[0]);
  t := PInt64(@target[0]);
  for i := 0 to (d - 1) do
  begin
    if (s^ <> t^) then
      Exit(False);
    Inc(s);
    Inc(t);
  end;
  if ((l mod 2) <> 0) then
    Result := (Self[l - 1] = target[l - 1])
  else
    Result := True;
end;
{$ENDIF}