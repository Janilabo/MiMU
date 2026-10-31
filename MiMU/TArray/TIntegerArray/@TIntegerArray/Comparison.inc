{$IFDEF FUNCTIONS}
function Minor(const n: TIntegerArray): Integer; overload;
function Major(const n: TIntegerArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Minor>
  @action: Returns the minimum value in an array of integers (TIntegerArray) using a branchless iterative approach.
  @note: Returns High(Integer) if the array is empty. Iterates through the array elements, updating the running minimum using the branchless bitwise minimum operation.
[==============================================================================}
function Minor(const n: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := High(Integer);
  for i := 0 to High(n) do
    Result := (Result xor ((n[i] xor Result) and -Ord(n[i] < Result)));
end;

{==============================================================================]
  <Major>
  @action: Returns the maximum value in an array of integers (TIntegerArray) using a branchless iterative approach.
  @note: Returns Low(Integer) if the array is empty. Iterates through the array elements, updating the running maximum using the branchless bitwise maximum operation.
[==============================================================================}
function Major(const n: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := Low(Integer);
  for i := 0 to High(n) do
    Result := (Result xor ((n[i] xor Result) and -Ord(n[i] > Result)));
end;
{$ENDIF}
