{$IFDEF HELPERS}
function Falses: TIntegerArray; overload;
function Trues: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Falses>
  @action: Returns Indexes of arr where state is False.
  @note: [True, False, True, False] => [1,3]
[==============================================================================}
function TBooleanArrayHelper.Falses: TIntegerArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Self.Size);
  r := 0;
  for i := 0 to High(Self) do
    if not Self[i] then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;

{==============================================================================]
  <Trues>
  @action: Returns Indexes of arr where state is True.
  @note: [True, False, True, False] => [0,2]
[==============================================================================}
function TBooleanArrayHelper.Trues: TIntegerArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Self.Size);
  r := 0;
  for i := 0 to High(Self) do
    if (Self[i] = True) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;
{$ENDIF}
