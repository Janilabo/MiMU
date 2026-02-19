{$IFDEF HELPERS}
function Duped: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Duped>
  @action: Returns a copy of the current integer array.  
           The resulting array contains the same elements in the same order as the original.
  @note:
    • The original array is not modified.  
    • Uses low-level memory copy (`Move`) for efficiency.  
    • Time complexity: O(n), where n is the length of the array.  
    • Space complexity: O(n) due to allocation of the new array.  
    • If the original array is empty, the result is also an empty array.
[==============================================================================}
function TIntegerArrayHelper.Duped: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l > 0) then
    Move(Self[0], Result[0], (l * SizeOf(Integer)));
end;
{$ENDIF}