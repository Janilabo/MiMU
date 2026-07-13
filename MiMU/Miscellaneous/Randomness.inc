{$IFDEF FUNCTIONS}
function Arbitrium: Boolean; overload;
function Bool(const threshold: Double = 0.5): Boolean; overload;
function Chance: Boolean; overload;
function Digitry: Byte; overload;
function Fate: Boolean; overload;
function Fortunal(const aMin, aMax: Integer; const target: Integer; const Limit: Integer = High(Integer)): Integer; overload;
function Fortune(const N: Integer; const target: Integer; const limit: Integer = High(Integer)): Integer; overload;
function GenerateDigit: Byte; overload;
function Guess: Boolean; overload;
function IsHeads: Boolean; overload;
function IsTails: Boolean; overload;
function Luck(const pool: UInt32 = 4294967295): Boolean; overload;
function Maybe: Boolean; overload;
function Misfortunal(const aMin, aMax: Integer; const target: Integer; const limit: Integer = High(Integer)): Integer; overload;
function Misfortune(const N: Integer; const target: Integer; const limit: Integer = High(Integer)): Integer; overload;
function Perchance(const tWeight, fWeight: Integer): Boolean; overload;
function Perhaps: Boolean; overload;
function Possibly: Boolean; overload;
function R0_1: Byte; overload;
function R0_9: Byte; overload;
function R0_99: Byte; overload;
function R1_9: Byte; overload;
function R1_99: Byte; overload;
function R10_99: Byte; overload;
function Rand(const R: Integer = 2): Integer; overload;
function Randice(const N: Integer; var A, B: Integer): Boolean; overload;
function RandDigit: Byte; overload;
function Randify(const R: Integer = 2): Integer; overload;
function RandIn(const R: Integer = 2; const N: Integer = 2): Integer; overload;
function Rando(const R: Integer = 2): Integer; overload;
function Random2: Boolean; overload;
function Random2(const x: Integer; const r: Integer = 2): Integer; overload;
function Randomal(const rSize: Integer = 1): TDoubleArray; overload;
function RandomB: Boolean; overload;
function RandomBit: Byte; overload;
function RandomBool: Boolean; overload;
function RandomCenter(const R: Integer; const sharpness: Double = 2.0): Integer; overload;
function RandomCode(const digitCount: Byte = 1): Int64; overload;
function RandomDigit: Byte; overload;
function RandomEx(const l: Integer = 2): Integer; overload;
function RandomHigh(const R: Integer = 2; const biasStrength: Double = 2.0): Integer; overload;
function RandomLeft(const R: Integer = 2): Integer; overload;
function RandomLow(const R: Integer = 2; const biasStrength: Double = 2.0): Integer; overload;
function RandomLower(const R: Integer = 2): Integer; overload;
function RandomMax(const x: Integer; const r: Integer = 2): Integer; overload;
function RandomMean(const x: Integer; const sample: Integer = 10): Integer; overload;
function RandomMid(const R: Integer): Integer; overload;
function RandomMiddle(const R: Integer): Integer; overload;
function RandomMin(const x: Integer; const r: Integer = 2): Integer; overload;
function RandomNumber(const digitCount: Byte = 1): Int64; overload;
function Randomish(const R: Integer = 2): Integer; overload;
function RandomRight(const R: Integer = 2): Integer; overload;
function RandomSample(const x: Integer; const size: Integer): TIntegerArray; overload;
function RandomUpper(const R: Integer = 2): Integer; overload;
function RandomValue(const maxDigits: Byte = 1): Int64; overload;
function Randouble(const N: Integer; var A, B: Integer): Boolean; overload;
function RandOut(const R: Integer = 2; const N: Integer = 2): Integer; overload;
function Rign: Integer; overload;
function Toss: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Arbitrium>
  @action: Returns a random Boolean value (True or False).
  @note: Uses a low-level memory overlay (`absolute`) to map a random Byte (0 or 1) 
         directly to a Boolean state, bypassing conditional branching logic.
[==============================================================================}
function Arbitrium: Boolean; overload;
var
  r: Byte;
  b: Boolean absolute r;
begin
  r := Random(2);
  Result := b;
end;

{==============================================================================]
  <Bool>
  @action: Returns true based on a probability threshold between 0.0 and 1.0.
  @note: Passing 0.5 creates a 50/50 chance. Safe against negative thresholds.
[==============================================================================}
function Bool(const threshold: Double = 0.5): Boolean; overload;
begin
  Result := ((threshold > 0) and (Random < threshold));
end;

{==============================================================================]
  <Chance>
  @action: Returns a 50/50 boolean outcome using an integer parity check.
  @note: Evaluates whether a random number up to MaxInt is even.
[==============================================================================}
function Chance: Boolean; overload;
begin
  Result := (((Random(High(Integer))) mod 2) = 0);
end;

{==============================================================================]
  <Digitry>
  @action: Returns a single Byte digit from 0 to 9 using a branching decision tree.
  @note: Distributes odds unevenly across two primary paths (high/low groups) 
         to mimic a binomial profile while bypassing a linear 9-step loop.
[==============================================================================}
function Digitry: Byte; overload;
begin
  if RandomBool then
  begin
    Result := (5 + (RandomBit + RandomBit));
    if RandomBool then
      Inc(Result, (RandomBit + RandomBit));
  end else
  begin
    Result := (RandomBit + RandomBit);
    if RandomBool then
      Inc(Result, (RandomBit + RandomBit));
  end;
end;

{==============================================================================]
  <Fate>
  @action: Returns a 50/50 boolean flag by truncating a scaled floating-point random number.
  @note: Scales the 0.0-1.0 float range up to 2.0 and drops the decimal to isolate a 0 or 1.
[==============================================================================}
function Fate: Boolean; overload;
begin
  Result := (Trunc(Random * 2) = 1);
end;

{==============================================================================]
  <Fortunal>
  @action: Range-bounded sibling of Fortune — measures a lucky streak,
           counting consecutive RandomRange(aMin, aMax+1) draws that equal
           `target`, stopping at the first miss or at `Limit`.
  @note: Short-circuits to `limit` when (aMin = aMax) and (target = aMin),
         since every draw is then guaranteed to equal `target` — mirrors
         Fortune's (N <= 1) and (target = 0) guard for the same reason.
[==============================================================================}
function Fortunal(const aMin, aMax: Integer; const target: Integer; const Limit: Integer = High(Integer)): Integer; overload;
begin
  if ((aMin = aMax) and (target = aMin)) then
    Exit(limit);
  Result := 0;
  while ((Result < limit) and (RandomRange(aMin, (aMax + 1)) = target)) do
    Inc(Result);
end;

{==============================================================================]
  <Fortune>
  @action: Measures a lucky streak — counts consecutive Random(N) draws that
           equal `target`, stopping at the first miss or at `Limit`, whichever comes first.
  @note: Short-circuits to `limit` when (N <= 1) and (target = 0), since
         Random(N) is guaranteed to equal 0 on every draw in that degenerate
         case — this avoids looping needlessly (and avoids relying on the
         undefined behavior of Random(0)) when the streak is trivially maximal.
[==============================================================================}
function Fortune(const N: Integer; const target: Integer; const limit: Integer = High(Integer)): Integer; overload;
begin
  if ((N <= 1) and (target = 0)) then
    Exit(limit);
  Result := 0;
  while ((Result < limit) and (Random(N) = target)) do
    Inc(Result);
end;

{==============================================================================]
  <GenerateDigit>
  @action: Returns a single Byte digit from 0 to 9 using a fast bitwise population count.
  @note: Packs 9 independent RandomBit choices into a 32-bit register, then shifts 
         and masks the bits to accumulate a centrally-biased binomial sum.
[==============================================================================}
function GenerateDigit: Byte; overload;
var
  R: UInt32;
begin
  Result := 0;
  R := (RandomBit or (RandomBit shl 1) or (RandomBit shl 2) or (RandomBit shl 3) or (RandomBit shl 4) or (RandomBit shl 5) or (RandomBit shl 6) or (RandomBit shl 7) or (RandomBit shl 8));
  while (R > 0) do
  begin
    Inc(Result, (R and 1));
    R := (R shr 1);
  end;
end;

{==============================================================================]
  <Guess>
  @action: Returns a 50/50 boolean outcome by selecting from a static boolean lookup array.
  @note: Uses a zero-indexed 2-element array to map Random(2) directly to a flag.
[==============================================================================}
function Guess: Boolean; overload;
const
  B: array[0..1] of Boolean = (False, True);
begin
  Result := B[Random(2)];
end;

{==============================================================================]
  <IsHeads>
  @action: Simulates a coin toss, returning True if the result is "Heads".
  @note: Uses a 50/50 pseudo-random distribution. Equivalent to rolling a 1 
         on a 0-1 range.
[==============================================================================}
function IsHeads: Boolean; overload;
begin
  Result := (Random(2) in [1]);
end;

{==============================================================================]
  <IsTails>
  @action: Simulates a coin toss, returning True if the result is "Tails".
  @note: Uses a 50/50 pseudo-random distribution. Equivalent to rolling a 0 
         on a 0-1 range.
[==============================================================================}
function IsTails: Boolean; overload;
begin
  Result := (Random(2) in [0]); 
end;

{==============================================================================]
  <Luck>
  @action: Simulates a luck-based chance check by comparing two independent 
           pseudo-random rolls from the specified pool.
  @note: Returns True if the first roll strictly beats the second roll. 
         Defaults to the maximum value of UInt32 (4294967295). Due to the 
         possibility of identical rolls resulting in False, the true success 
         rate is marginally below 50%.
[==============================================================================}
function Luck(const pool: UInt32 = 4294967295): Boolean; overload;
begin
  Result := (Random(pool) > Random(pool));
end;

{==============================================================================]
  <Maybe>
  @action: Returns a pseudo-random boolean based on the system uptime clock.
  @note: Fast and unseeded; relies on the lowest bit of the millisecond counter.
[==============================================================================}
function Maybe: Boolean; overload;
begin
  Result := ((GetTickCount64 and 1) = 0);
end;

{==============================================================================]
  <Misfortunal>
  @action: Range-bounded sibling of Misfortune — measures a dry spell,
           counting consecutive RandomRange(aMin, aMax+1) draws that do NOT
           equal `target`, stopping the instant `target` is drawn or at `Limit`.
  @note: Short-circuits to `limit` when `target` falls outside
         [aMin, aMax], since it can then never be drawn — mirrors
         Misfortune's out-of-[0,N) guard for the same reason.
[==============================================================================}
function Misfortunal(const aMin, aMax: Integer; const target: Integer; const limit: Integer = High(Integer)): Integer; overload;
begin
  if ((target < aMin) or (target > aMax)) then
    Exit(limit);
  Result := 0;
  while ((Result < limit) and (RandomRange(aMin, (aMax + 1)) <> target)) do
    Inc(Result);
end;

{==============================================================================]
  <Misfortune>
  @action: Measures a dry spell — counts consecutive Random(N) draws that
           do NOT equal `target`, stopping the instant `target` is finally drawn
           (or at `limit`, whichever comes first).
  @note: Short-circuits to `Limit` when `target` falls outside [0, N),
         since Random(N) can then never equal it — the streak is guaranteed to
         run the full length, so the loop is skipped entirely.
[==============================================================================}
function Misfortune(const N: Integer; const target: Integer; const limit: Integer = High(Integer)): Integer; overload;
begin
  if ((target < 0) or (target >= N)) then
    Exit(limit);
  Result := 0;
  while ((Result < limit) and (Random(N) <> target)) do
    Inc(Result);
end;

{==============================================================================]
  <Perchance>
  @action: Determines a boolean outcome using relative true vs false weights.
  @note: Potential divide-by-zero risk if both weights are passed as 0.
[==============================================================================}
function Perchance(const tWeight, fWeight: Integer): Boolean; overload;
begin
  Result := (Random(tWeight + fWeight) < tWeight);
end;

{==============================================================================]
  <Perhaps>
  @action: Returns a 50/50 boolean flag by evaluating a random integer's lowest bit.
  @note: A fast, bitwise alternative to modulo that yields perfect binary odds.
[==============================================================================}
function Perhaps: Boolean; overload;
begin
  Result := ((Random(High(Integer)) and 1) = 1);
end;

{==============================================================================]
  <Possibly>
  @action: Returns a 50/50 boolean flag by rounding a floating-point random number.
  @note: Relies on banker's rounding rules if Random returns exactly 0.5.
[==============================================================================}
function Possibly: Boolean; overload;
begin
  Result := (Round(Random) = 1);
end;

{==============================================================================]
  <R0_1>
  @action: Returns a random Byte value of either 0 or 1.
  @note: Uses a uniform distribution over a range of 2 possible outcomes.
[==============================================================================}
function R0_1: Byte; overload;
begin
  Result := Random(2);
end;

{==============================================================================]
  <R0_9>
  @action: Returns a random single-digit Byte value from 0 to 9 inclusive.
  @note: Uses a uniform distribution over a range of 10 possible outcomes.
[==============================================================================}
function R0_9: Byte; overload;
begin
  Result := Random(10);
end;

{==============================================================================]
  <R0_99>
  @action: Returns a random double-digit Byte value from 0 to 99 inclusive.
  @note: Uses a uniform distribution over a range of 100 possible outcomes.
[==============================================================================}
function R0_99: Byte; overload;
begin
  Result := Random(100);
end;

{==============================================================================]
  <R1_9>
  @action: Returns a random single-digit Byte value from 1 to 9 inclusive.
  @note: Shifts a uniform 0-8 range up by 1 to eliminate 0 from the pool.
[==============================================================================}
function R1_9: Byte; overload;
begin
  Result := (Random(9) + 1);
end;

{==============================================================================]
  <R1_99>
  @action: Returns a random non-zero Byte value from 1 to 99 inclusive.
  @note: Shifts a uniform 0-98 range up by 1 to eliminate 0 from the pool.
[==============================================================================}
function R1_99: Byte; overload;
begin
  Result := (Random(99) + 1);
end;

{==============================================================================]
  <R10_99>
  @action: Returns a random strict two-digit Byte value from 10 to 99 inclusive.
  @note: Shifts a uniform 0-89 range up by 10 to clear single-digit values.
[==============================================================================}
function R10_99: Byte; overload;
begin
  Result := (Random(90) + 10);
end;

{==============================================================================]
  <Rand>
  @action: Returns a random integer between 0 and R-1, preserving sign.
  @note: Uses Math.Sign. Negative values of R return a negative random range.
[==============================================================================}
function Rand(const R: Integer = 2): Integer; overload;
begin
  case Sign(R) of
    0: Exit(0);
    1: Result := Random(R);
    -1: Result := -(Random(-R));
  end;
end;

{==============================================================================]
  <Randice>
  @action: Draws two independent random integers from [0, N) into A and B;
           returns True if they differ.
  @note: A and B are always assigned regardless of the result. N follows
         Random()'s convention: the upper bound is exclusive. Logically the
         inverse of Randouble (Randice = not Randouble for the same draw),
         kept as a separate named function rather than a negation for
         call-site readability.
[==============================================================================}
function Randice(const N: Integer; var A, B: Integer): Boolean; overload;
begin
  A := Random(N);
  B := Random(N);
  Result := (A <> B);
end;

{==============================================================================]
  <RandDigit>
  @action: Returns a single Byte digit from 0 to 9 using a fast bit-weighted combination.
  @note: Uses 5 independent RandomBit calls paired with scalar multipliers to match 
         the 0-9 range while maintaining a central bell-curve bias.
[==============================================================================}
function RandDigit: Byte; overload;
begin
  Result := (RandomBit + (RandomBit * 4) + (RandomBit * 2) + (RandomBit * 2));
  if (Result < 9) then
    Inc(Result, RandomBit);
end;

{==============================================================================]
  <Randify>
  @action: Mirror behavior to Rand; returns a sign-preserved random integer.
  @note: Uses an explicit if-else branch chain instead of a sign case.
[==============================================================================}
function Randify(const R: Integer = 2): Integer; overload;
begin
  if (R > 0) then
    Result := Random(R)
  else if (R < 0) then
    Result := -Random(-R)
  else
    Result := 0;
end;

{==============================================================================]
  <RandIn>
  @action: Biases results lower by picking the lowest value from N samples.
  @note: Preserves the sign of R. Utilizes a custom helper method `i.Increase`.
[==============================================================================}
function RandIn(const R: Integer = 2; const N: Integer = 2): Integer; overload;
var
  i, v: Integer;
begin
  if (N < 1) then
    Exit(Rand(R));
  v := Abs(R);
  Result := Random(v);
  i := 0;
  while ((Result > 0) and (i.Increase < N)) do
    Result := Min(Result, Random(v));
  if (R < 0) then
    Result := -Result;
end;

{==============================================================================]
  <Rando>
  @action: Returns a sign-preserved random integer using absolute manipulation.
  @note: Multiplies a positive random result by the original sign value.
[==============================================================================}
function Rando(const R: Integer = 2): Integer; overload;
begin
  if (R = 0) then
    Exit(0);
  Result := (Random(Abs(R)) * Sign(R));
end;

{==============================================================================]
  <Random2>
  @action: Returns a 50/50 boolean outcome by XOR-mixing two independent random bits.
  @note: Combines two separate RandomBit draws so the result depends on their
         disagreement rather than either value alone, preserving perfect binary odds.
[==============================================================================}
function Random2: Boolean; overload;
begin
  Result := ((RandomBit xor RandomBit) = 1);
end;

{==============================================================================]
  <Random2>
  @action: Burns a random number of generator cycles before returning a result.
  @note: Used to disrupt sequential predictability patterns in standard Random.
[==============================================================================}
function Random2(const x: Integer; const r: Integer = 2): Integer; overload;
var
  i: Integer;
begin
  for i := 1 to Random(r + 1) do
    Random(x);
  Result := Random(x);
end;

{==============================================================================]
  <Randomal>
  @action: Allocates a 1D array of a specified size and fills it with pseudo-random 
           floating-point numbers between 0.0 and 1.0.
  @note: Automatically handles negative or invalid sizes by defaulting to an empty 
         array via `Max(0, rSize)`. If no size parameter is provided, it defaults 
         to generating a single-element array.
[==============================================================================}
function Randomal(const rSize: Integer = 1): TDoubleArray; overload;
var
  i: Integer;
begin
  for i := 0 to (Result.SetSize(Max(0, rSize)) - 1) do
    Result[i] := Random;
end;

{==============================================================================]
  <RandomB>
  @action: Returns a 50/50 boolean flag by checking if Random(2) equals 1.
  @note: Explicit conditional mapping alternative to RandomBool.
[==============================================================================}
function RandomB: Boolean; overload;
begin
  Result := (Random(2) = 1);
end;

{==============================================================================]
  <RandomBit>
  @action: Returns a random bit value as a Byte (0 or 1).
  @note: Performance-optimized via a bitwise AND mask on a native 32-bit
         random integer, isolating the lowest bit with zero division overhead.
[==============================================================================}
function RandomBit: Byte; overload;
begin
  Result := Byte(Random(MaxInt) and 1);
end;

{==============================================================================]
  <RandomBool>
  @action: Directly typecasts Random(2) into a native Pascal Boolean.
  @note: Returns False for 0 and True for 1 via explicit compiler casting.
[==============================================================================}
function RandomBool: Boolean; overload;
begin
  Result := Boolean(Random(2));
end;

{==============================================================================]
  <RandomCenter>
  @action: Generates a random integer from 0 to R - 1, sharply centered around the middle of the range.
  @note: Generalization of RandomMiddle. Applies the Central Limit Theorem by averaging multiple uniform random variables ($s$ iterations).
         Higher `sharpness` creates a narrower, bell-curve (Gaussian-like) distribution.
[==============================================================================}
function RandomCenter(const R: Integer; const sharpness: Double = 2.0): Integer; overload;
var
  t: Double;
  i, s: Integer;
begin
  if ((R < 2) or (sharpness <= 0)) then
    Exit(0);
  s := Max(2, Round(sharpness * 2));
  t := 0;
  for i := 1 to s do
    t := (t + Random);
  Result := Floor((t / s) * R);
  if (Result < 0) then
    Result := 0
  else if (Result >= R) then
    Result := (R - 1);
end; 

{==============================================================================]
  <RandomCode>
  @action: Generates a random multi-digit Int64 code sequence via mathematical accumulation.
  @note: Ensures the leading digit is never zero (1-9) so the full digit length is preserved.
[==============================================================================}
function RandomCode(const digitCount: Byte = 1): Int64; overload;
var
  i: Integer;
begin
  if (digitCount > 0) then
  begin
    Result := (Random(9) + 1);
    for i := 2 to digitCount do
      Result := ((Result * 10) + Random(10));
  end else
    Result := 0;
end;

{==============================================================================]
  <RandomDigit>
  @action: Returns a single Byte digit from 0 to 9 using a binomial distribution loop.
  @note: Evaluates 9 independent random boolean passes, resulting in a number sequence
         heavily biased toward the central values of 4 and 5.
[==============================================================================}
function RandomDigit: Byte; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 1 to 9 do
    if RandomBool then
      Inc(Result);
end;

{==============================================================================]
  <RandomEx>
  @action: Returns a sign-preserved random integer using explicit bounds checks.
  @note: Negative values of l return a negative result range via an inverse flip.
[==============================================================================}
function RandomEx(const l: Integer = 2): Integer; overload;
begin
  if (l > -1) then
    Result := Random(l)
  else
    Result := (Random(Abs(l)) * -1);
end;

{==============================================================================]
  <RandomHigh>
  @action: Generates a random integer from 0 to R - 1, biased toward R - 1 with a configurable bias strength.
  @note: Generalization of RandomRight. A higher `biasStrength` (> 1.0) pushes results closer to R - 1,
         while a value of 1.0 yields a uniform distribution.
[==============================================================================}
function RandomHigh(const R: Integer = 2; const biasStrength: Double = 2.0): Integer; overload;
begin
  if ((R < 2) or (biasStrength <= 0)) then
    Exit(0);
  Result := ((R - 1) - Floor(Power(Random, biasStrength) * R));
  if (Result < 0) then
    Result := 0
  else if (Result >= R) then
    Result := (R - 1);
end;

{==============================================================================]
  <RandomLeft>
  @action: Generates a random integer from 0 to R - 1, heavily biased toward 0 (the left side of the range).
  @note: Uses a quadratic distribution ($Random^2$) to cluster results near the lower bound. Clamped between 0 and R - 1.
[==============================================================================}
function RandomLeft(const R: Integer = 2): Integer; overload;
begin
  if (R < 2) then
    Exit(0);
  Result := Floor(Power(Random, 2.0) * R);
  if (Result < 0) then
    Result := 0
  else if (Result >= R) then
    Result := (R - 1);
end;

{==============================================================================]
  <RandomLow>
  @action: Generates a random integer from 0 to R - 1, biased toward 0 with a configurable bias strength.
  @note: Generalization of RandomLeft. A higher `biasStrength` (> 1.0) pushes results closer to 0,
         while a value of 1.0 yields a uniform distribution.
[==============================================================================}
function RandomLow(const R: Integer = 2; const biasStrength: Double = 2.0): Integer; overload;
begin
  if ((R < 2) or (biasStrength <= 0)) then
    Exit(0);
  Result := Floor(Power(Random, biasStrength) * R);
  if (Result < 0) then
    Result := 0
  else if (Result >= R) then
    Result := (R - 1);
end;

{==============================================================================]
  <RandomLower>
  @action: Biases results down toward zero by taking the lower of 2 samples.
  @note: Simple fixed-pass variation of a downward probability curve.
[==============================================================================}
function RandomLower(const R: Integer = 2): Integer; overload;
begin
  Result := Min(Random(R), Random(R));
end;

{==============================================================================]
  <RandomMax>
  @action: Sample-based filtering that picks the single highest random result.
  @note: Runs 'r' iterations. Starts from lowest possible 32-bit signed integer.
[==============================================================================}
function RandomMax(const x: Integer; const r: Integer = 2): Integer; overload;
var
  i: Integer;
begin
  Result := -2147483648;
  for i := 1 to r do
    Result := Max(Result, Random(x));
end;

{==============================================================================]
  <RandomMean>
  @action: Returns a central-tendency value by averaging an array of random samples.
  @note: Generates a normal bell curve distribution around the center of x.
[==============================================================================}
function RandomMean(const x: Integer; const sample: Integer = 10): Integer; overload;
begin
  Result := Round(RandomSample(x, sample).Mean);
end;

{==============================================================================]
  <RandomMid>
  @action: Generates a random integer from 0 to R - 1, gently biased toward the middle of the range.
  @note: Implements a median-of-three selection. It samples three independent uniform random variables and returns the median value,
         resulting in a smooth, symmetric distribution that drops off at the boundaries.
[==============================================================================}
function RandomMid(const R: Integer): Integer; overload;
var
  a: TIntegerArray;
begin
  if (R < 2) then
    Exit(0);
  a := [Random(R), Random(R), Random(R)];
  Sort3(a[0], a[1], a[2]);
  Result := a[1];
end;

{==============================================================================]
  <RandomMiddle>
  @action: Generates a random integer from 0 to R - 1, biased toward the center of the range.
  @note: Averages two independent random uniform variables, creating a symmetric,
         triangular probability distribution centered around $(R - 1) / 2$.
[==============================================================================}
function RandomMiddle(const R: Integer): Integer; overload;
var
  u, v: Double;
begin
  if (R < 2) then
    Exit(0);
  u := Random;
  v := Random;
  Result := Floor(((u + v) / 2) * R);
  if (Result < 0) then
    Result := 0
  else if (Result >= R) then
    Result := (R - 1);
end;

{==============================================================================]
  <RandomMin>
  @action: Sample-based filtering that picks the single lowest random result.
  @note: Runs 'r' iterations. Starts from highest possible 32-bit signed integer.
[==============================================================================}
function RandomMin(const x: Integer; const r: Integer = 2): Integer; overload;
var
  i: Integer;
begin
  Result := 2147483647;
  for i := 1 to r do
    Result := Min(Result, Random(x));
end;

{==============================================================================]
  <RandomNumber>
  @action: Generates a random multi-digit Int64 number using string building and ASCII manipulation.
  @note: Uses string allocation and StrToUInt64. The first digit is constrained to '1'-'9' (ASCII 49-57).
[==============================================================================}
function RandomNumber(const digitCount: Byte = 1): Int64; overload;
var
  s: string;
  i: Integer;
begin
  if (digitCount < 1) then
    Exit(0);
  SetLength(s, digitCount);
  s[1] := Char(49 + Random(9));
  for i := 2 to digitCount do
    s[i] := Char(48 + Random(10));
  Result := StrToInt64(s);
end;

{==============================================================================]
  <Randomish>
  @action: Sign-aware random generator using a fast bit-shift sign check.
  @note: Tests the 31st bit to determine if R is a negative value.
[==============================================================================}
function Randomish(const R: Integer = 2): Integer; overload;
begin
  if (R = 0) then
    Exit(0);
  Result := Random(Abs(R));
  if ((R shr 31) <> 0) then
    Result := -Result;
end;

{==============================================================================]
  <RandomRight>
  @action: Generates a random integer from 0 to R - 1, heavily biased toward R - 1 (the right side of the range).
  @note: Inverts the quadratic distribution of RandomLeft to cluster results near the upper bound. Clamped between 0 and R - 1.
[==============================================================================}
function RandomRight(const R: Integer = 2): Integer; overload;
begin
  if (R < 2) then
    Exit(0);
  Result := ((R - 1) - Floor(Power(Random, 2.0) * R));
  if (Result < 0) then
    Result := 0
  else if (Result >= R) then
    Result := (R - 1);
end;

{==============================================================================]
  <RandomSample>
  @action: Populates a dynamic TIntegerArray with an arbitrary size of random integers.
  @note: Allocates and initializes the result array instantly using SetLength.
[==============================================================================}
function RandomSample(const x: Integer; const size: Integer): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, size);
  for i := 0 to High(Result) do
    Result[i] := Random(x);
end;

{==============================================================================]
  <RandomUpper>
  @action: Biases results up toward R by taking the higher of 2 samples.
  @note: Simple fixed-pass variation of an upward probability curve.
[==============================================================================}
function RandomUpper(const R: Integer = 2): Integer; overload;
begin
  Result := Max(Random(R), Random(R));
end;

{==============================================================================]
  <RandomValue>
  @action: Returns a random number between 0 and (10^maxDigits - 1)
  @note: Leading zeros are stripped, so the result may have fewer digits than maxDigits.
         Example: RandomValue(5) could return 42 (not 00042)
         Maximum safe digits is 18 for Int64 (9,223,372,036,854,775,807)
         Returns 0 if maxDigits < 1
         Returns High(Int64) if maxDigits > 18
[==============================================================================}
function RandomValue(const maxDigits: Byte = 1): Int64; overload;
var
  s: string;
  i: Integer;
begin
  if (maxDigits < 1) then
    Exit(0);
  if maxDigits > 19 then
    Exit(High(Int64));
  SetLength(s, maxDigits);
  for i := 1 to maxDigits do
    s[i] := Char(48 + Random(10));
  Result := StrToInt64(s);
end;

{==============================================================================]
  <Randouble>
  @action: Draws two independent random integers from [0, N) into A and B;
           returns True if they match.
  @note: A and B are always assigned regardless of the result. N follows
         Random()'s convention: the upper bound is exclusive.
[==============================================================================}
function Randouble(const N: Integer; var A, B: Integer): Boolean; overload;
begin
  A := Random(N);
  B := Random(N);
  Result := (A = B);
end;

{==============================================================================]
  <RandOut>
  @action: Biases results higher toward the upper bound across N samples.
  @note: Retains original sign structure. Inverse behavior counterpart to RandIn.
[==============================================================================}
function RandOut(const R: Integer = 2; const N: Integer = 2): Integer; overload;
var
  i, m, v: Integer;
begin
  if (N < 1) then
    Exit(Rand(R));
  v := Abs(R);
  m := (v - 1);
  Result := Random(v);
  i := 0;
  while ((Result < m) and (i.Increase < N)) do
    Result := Max(Result, Random(v));
  if (R < 0) then
    Result := -Result;
end;

{==============================================================================]
  <Rign>
  @action: Returns a random sign/directional multiplier (-1, 0, or 1).
  @note: Useful for handling random coordinate steps or directional shifts.
[==============================================================================}
function Rign: Integer; overload;
begin
  Result := (Random(3) - 1);
end;

{==============================================================================]
  <Toss>
  @action: Returns a non-zero polar flip value (-1 or 1).
  @note: Perfect for forcing a coin flip to go strictly left or right.
[==============================================================================}
function Toss: Integer; overload;
begin
  Result := ((Random(2) * 2) - 1);
end;
{$ENDIF}
