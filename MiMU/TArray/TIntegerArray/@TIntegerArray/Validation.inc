{$IFDEF HELPERS}
function Echo: Boolean; overload;
function Isotropic: Boolean; overload;
function Pure(const allowed: TIntegerArray): Boolean; overload;
function Special: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Echo>
  @action: Determines if the array is symmetrical (a palindrome) by comparing 
           elements from both ends simultaneously.
  @note: 
    - Strategy: Employs a dual-pointer "converging" approach. The 'S' (Start) 
      pointer moves forward while the 'E' (End) pointer moves backward.
    - Efficiency: O(N) time complexity with a 0.5x iteration factor. 
      Exits immediately (False) at the first point of divergence.
    - Performance: Highly optimized; avoids the overhead of array index 
      calculations and bounds checking by using raw PInteger dereferencing.
    - Safety: Returns True for empty arrays or single-element arrays, as 
      they are inherently symmetrical.
[==============================================================================}
function TIntegerArrayHelper.Echo: Boolean; overload;
var
  S, E: PInteger;
begin
  if (Self.Length < 2) then
    Exit(True);
  S := @Self[0];
  E := @Self[High(Self)];
  while (S < E) do
  begin
    if (S^ <> E^) then
	  Exit(False);
    Inc(S);
    Dec(E);
  end;
  Result := True;
end;

{==============================================================================]
  <Isotropic>
  @action: Validates symmetry by performing a bitwise comparison between the 
           source array and a reversed replica.
  @note: 
    - Strategy: Uses a "Mirror-Clone" technique. It creates a temporary 
      reversed instance and compares the two memory blocks in bulk.
    - Consistency: Relies on 'CompareMem', which is a high-speed RTL 
      primitive often optimized with SIMD (SSE/AVX) instructions.
    - Memory: O(N) overhead due to the creation of the 'R' array.
[==============================================================================}
function TIntegerArrayHelper.Isotropic: Boolean; overload;
var
  L: Integer;
  R: TIntegerArray;
begin
  L := Self.Length;
  if (L < 2) then
    Exit(True);
  R := Self.Reversed;
  Result := CompareMem(@Self[0], @R[0], (L * SizeOf(Integer)));
end;

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
function TIntegerArrayHelper.Special: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i].Parity = Self[i - 1].Parity) then
      Exit(False);
  Result := True;
end;
{$ENDIF}
