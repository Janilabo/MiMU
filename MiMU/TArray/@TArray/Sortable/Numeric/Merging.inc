{$IFDEF FUNCTIONS}
function Joined(const A, B: MArray): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Joined>
  @action: Concatenates two arrays (A and B) into one, preserving each
           array's existing element order. No sorting, no comparisons — purely
           positional concatenation via raw memory copy.
  @note: Uses Move for performance; only safe because numeric types are unmanaged
         (fixed-size, non-reference-counted) element type.
[==============================================================================}
function Joined(const A, B: MArray): MArray; overload;
var
  x, y: Integer;
begin
  x := A.Length;
  y := B.Length;
  SetLength(Result, (x + y));
  if (x > 0) then
    Move(A[0], Result[0], (x * SizeOf(MType)));
  if (y > 0) then
    Move(B[0], Result[x], (y * SizeOf(MType)));
end;
{$ENDIF}