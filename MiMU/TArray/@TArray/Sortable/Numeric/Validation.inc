{$IFDEF HELPERS}
function Isotropic: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
function MArrayHelper.Isotropic: Boolean; overload;
var
  L: Integer;
  R: MArray;
begin
  L := Self.Length;
  if (L < 2) then
    Exit(True);
  R := Self.Reversed;
  Result := CompareMem(@Self[0], @R[0], (L * SizeOf(MType)));
end;
{$ENDIF}
