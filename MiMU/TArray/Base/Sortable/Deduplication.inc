{$IFDEF HELPERS}
function Cleaned(const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cleaned>
  @action: Returns a sorted copy of the array with all duplicate elements removed.
  @note: Uses an in-place deduplication algorithm after sorting to ensure a 
         unique set of values. Ideal for normalizing boundary data before 
         performing continuity or gap analysis.
[==============================================================================}
function MArrayHelper.Cleaned(const oAscending: Boolean = True): MArray; overload;
var
  i, r: Integer;
begin
  case Self.Length of
    0: Exit([]);
    1: Exit(Self.Copy);
  end;
  Result := Self.QuickSorted(oAscending);
  r := 1;
  for i := 1 to High(Result) do
    if (Result[i] <> Result[r - 1]) then
      Result[r.Increase] := Result[i];
  SetLength(Result, r);
end;
{$ENDIF}