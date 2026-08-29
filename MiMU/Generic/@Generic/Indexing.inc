{$IFDEF FUNCTIONS}
generic function Indexes<T>(const arr: array of T): TIntegerArray; overload;
generic function Indices<T>(const arr: array of T): TIntegerArray; overload;
generic function IDs<T>(const arr: array of T): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Indexes>
  @action: Generates an array of integer indexes corresponding to the input array.
  @note: The returned array has the same length as the input array, with values Low(arr) to High(arr).
[==============================================================================}
generic function Indexes<T>(const arr: array of T): TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Length(arr));
  l := Low(arr);
  for i := l to High(arr) do
    Result[i - l] := i;
end;

{==============================================================================]
  <Indices>
  @action: Returns an array containing all valid zero-based index values
           for the specified dynamic array.
  @note: Supports dynamic arrays only (passed via open array parameter).
         Allocates a new array with Length(arr) elements.
         Result range: 0 .. Length(arr) - 1.
         Time complexity: O(n). Space complexity: O(n).
[==============================================================================}
generic function Indices<T>(const arr: array of T): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := i;
end;

{==============================================================================]
  <IDs>
  @action: Returns an array containing sequential index values corresponding  
           to the valid element positions of the specified dynamic array.      
  @note: Supports dynamic arrays passed via open array parameter.           
         Result contains values: Low(arr) .. High(arr).                     
         Allocates a new dynamic array of size Length(arr). 
[==============================================================================}
generic function IDs<T>(const arr: array of T): TIntegerArray; overload;
var
  i, L, H: Integer;
begin
  L := Low(arr);
  H := High(arr);
  if (H < L) then
    Exit([]);
  SetLength(Result, ((H - L) + 1));
  for i := L to H do
    Result[i - L] := i;
end;
{$ENDIF}