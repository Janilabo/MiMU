{$IFDEF HELPERS}
function ExtractEven: TIntegerArray; overload;
function FilterEven: TIntegerArray; overload;
function ExtractOdd: TIntegerArray; overload;
function FilterOdd: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ExtractEven>
  @action: Returns even values from array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.ExtractEven: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if Self[i].Even then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <FilterEven>
  @action: Returns array without even values
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.FilterEven: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if not Self[i].Even then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <ExtractOdd>
  @action: Returns odd values from array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.ExtractOdd: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if Self[i].Odd then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <FilterOdd>
  @action: Returns array without odd values
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.FilterOdd: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  l := 0;
  for i := 0 to High(Self) do
    if not Self[i].Odd then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;
{$ENDIF}
