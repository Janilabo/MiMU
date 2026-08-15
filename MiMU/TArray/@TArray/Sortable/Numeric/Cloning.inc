{$IFDEF HELPERS}
function Duped: MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Duped>
  @action: Returns a copy of the current array.  
           The resulting array contains the same elements in the same order as the original.
  @note:
    • The original array is not modified.  
    • Uses low-level memory copy (`Move`) for efficiency.  
    • Time complexity: O(n), where n is the length of the array.  
    • Space complexity: O(n) due to allocation of the new array.  
    • If the original array is empty, the result is also an empty array.
[==============================================================================}
function MArrayHelper.Duped: MArray; overload;
begin
  if (Result.SetSize(Self.Length) > 0) then
    Move(Self[0], Result[0], (Self.Length * SizeOf(MType)));
end;
{$ENDIF}