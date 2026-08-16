{$IFDEF HELPERS}
function BinaryGrow(const x: TRange; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryGrow>
  @action: Inserts a range of integer values into a sorted array using binary 
           search, keeping the array ordered. Returns the total number of 
           elements successfully added/inserted.
  @note: Iterates through all discrete values from x.Minimum to x.Maximum and 
         accumulates the return count of the single-element BinaryGrow method.
[==============================================================================}
function TIntegerArrayHelper.BinaryGrow(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  s: Integer;
begin
  Result := 0;
  for s := x.Minimum to x.Maximum do
    Result.Increase(Self.BinaryGrow(s, aAscending));
end;
{$ENDIF}
