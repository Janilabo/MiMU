{$IFDEF HELPERS}
function X1s: TIntegerArray; overload;
function X1Values: TIntegerArray; overload;
function X2s: TIntegerArray; overload;
function X2Values: TIntegerArray; overload;
function Y1s: TIntegerArray; overload;
function Y1Values: TIntegerArray; overload;
function Y2s: TIntegerArray; overload;
function Y2Values: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <X1s>
  @action: Returns X1-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TBoxArrayHelper.X1s: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].X1;
end;

{==============================================================================]
  <X1Values>
  @action: Returns X1-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TBoxArrayHelper.X1Values: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].X1;
end;

{==============================================================================]
  <X2s>
  @action: Returns X2-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TBoxArrayHelper.X2s: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].X2;
end;

{==============================================================================]
  <X2Values>
  @action: Returns X2-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TBoxArrayHelper.X2Values: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].X2;
end;

{==============================================================================]
  <Y1s>
  @action: Returns Y1-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TBoxArrayHelper.Y1s: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Y1;
end;

{==============================================================================]
  <Y1Values>
  @action: Returns Y1-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TBoxArrayHelper.Y1Values: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].Y1;
end;

{==============================================================================]
  <Y2s>
  @action: Returns Y2-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TBoxArrayHelper.Y2s: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Y2;
end;

{==============================================================================]
  <Y2Values>
  @action: Returns Y2-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TBoxArrayHelper.Y2Values: TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].Y2;
end;
{$ENDIF}
