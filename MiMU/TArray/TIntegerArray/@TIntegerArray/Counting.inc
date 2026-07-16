{$IFDEF HELPERS}
function Countage(const value: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Countage>
  @action: Counts the total number of times a specific integer value occurs in the array.
  @note: Leverages pointer arithmetic (PInteger) to sequentially traverse the array 
         in memory for optimized performance. Returns 0 if the array is empty.
[==============================================================================}
function TIntegerArrayHelper.Countage(const value: Integer): Integer; overload;
var
  p: PInteger;
  i: Integer;
begin
  Result := 0;
  if (Self.Length = 0) then 
    Exit;
  p := @Self[0];
  for i := 0 to High(Self) do
  begin
    if (p^ = value) then
	  Inc(Result);
    Inc(p);
  end;
end;
{$ENDIF}
