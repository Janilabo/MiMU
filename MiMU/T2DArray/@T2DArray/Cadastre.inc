{$IFDEF HELPERS}
function Cadastre: TRangeArray; overload;
function Plat: TRangeArray; overload;
function Survey: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cadastre>
  @action: Returns a TRangeArray where each element is the index boundary 
           range of the corresponding row.
  @note: Uses Result.Alloc to size and obtain the high bound in one step, 
         then fills forward via a plain ascending loop, constructing a 
         TRange(0, High(row)) for each row in turn.
[==============================================================================}
function M2DArrayHelper.Cadastre: TRangeArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := TRange.Construct(0, High(Self[i]));
end;

{==============================================================================]
  <Plat>
  @action: Returns a TRangeArray where each element is the index boundary 
           range of the corresponding row.
  @note: Reuses Ambit's branchless boolean-to-integer trick per row instead 
         of an explicit conditional, avoiding any if/else or IfThen call.
[==============================================================================}
function M2DArrayHelper.Plat: TRangeArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := TRange.Construct(-Integer(Self[i].Empty), High(Self[i]));
end;

{==============================================================================]
  <Survey>
  @action: Returns a TRangeArray where each element is the index boundary 
           range of the corresponding row.
  @note: Uses Result.Alloc to size and obtain the high bound in one step. 
         Unlike Cadastre, this explicitly checks each row's length and 
         constructs TRange(-1, -1) for empty rows.
[==============================================================================}
function M2DArrayHelper.Survey: TRangeArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
    if (Self[i].Length > 0) then
      Result[i] := TRange.Construct(0, High(Self[i]))
	else
	  Result[i] := TRange.Construct(-1, -1);
end;
{$ENDIF}
