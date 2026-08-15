{$IFDEF HELPERS}
function Countage(const value: MType): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Countage>
  @action: Counts the total number of times a specific value occurs in the array.
  @note: Leverages pointer arithmetic to sequentially traverse the array 
         in memory for optimized performance. Returns 0 if the array is empty.
[==============================================================================}
function MArrayHelper.Countage(const value: MType): Integer; overload;
var
  p: MPointer;
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
