{$DEFINE TBox}{$I config\Defines.inc}

{$IFDEF INTERFACE}
{$ENDIF}

{$IFDEF HELPERS}
type
  HArr = type helper for TArr {$I config\1D.inc}
    function X1s: TIntegerArray; overload;
    function X2s: TIntegerArray; overload;
    function Y1s: TIntegerArray; overload;
    function Y2s: TIntegerArray; overload;
    function X1Values: TIntegerArray; overload;
    function X2Values: TIntegerArray; overload;
    function Y1Values: TIntegerArray; overload;
    function Y2Values: TIntegerArray; overload;
    function Unzip(var x1Arr, y1Arr, x2Arr, y2Arr: TIntegerArray): Integer;
    function Zip(const x1Arr, y1Arr, x2Arr, y2Arr: TIntegerArray): Integer;
    function Bounds: TBox; overload;
    function Boundaries: TBox; overload;
  end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(INTERFACE)} 
{$DEFINE FField := X1}{$I config\F.inc}
{$DEFINE FField := Y1}{$I config\F.inc}
{$DEFINE FField := X2}{$I config\F.inc}
{$DEFINE FField := Y2}{$I config\F.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\1D.inc}

{==============================================================================]
  <X1s>
  @action: Returns X1-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TBoxArrayHelper.X1s: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].X1;
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
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].X2;
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
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].Y1;
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
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].Y2;
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
  l := Length(Self);
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].X1;
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
  l := Length(Self);
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].X2;
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
  l := Length(Self);
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].Y1;
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
  l := Length(Self);
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].Y2;
end;

{==============================================================================]
  <Unzip>
  @action: Stores arr X1/X2 and Y1/Y2 values to x1/x2Arr and y1/y2Arr.
  @note: Returns Length(arr).
[==============================================================================}
function TBoxArrayHelper.Unzip(var x1Arr, y1Arr, x2Arr, y2Arr: TIntegerArray): Integer;
var
  i: Integer;
begin
  Result := Length(Self);
  specialize SetSize<Integer>(x1Arr, y1Arr, x2Arr, y2Arr, Result);
  for i := 0 to (Result - 1) do
    Self[i].Unzip(x1Arr[i], y1Arr[i], x2Arr[i], y2Arr[i]);
end;

{==============================================================================]
  <Zip>
  @action: Zips TBoxArray with x1/x2Arr and y1/y2Arr.
  @note: Uses minimum length(!), if xArr differs from yArr size.
[==============================================================================}
function TBoxArrayHelper.Zip(const x1Arr, y1Arr, x2Arr, y2Arr: TIntegerArray): Integer;
var
  i: Integer;
begin
  Result := Min(Min(Length(x1Arr), Length(x2Arr)), Min(Length(y1Arr), Length(y2Arr)));
  SetLength(Self, Result);
  for i := 0 to (Result - 1) do
    Self[i] := Box(x1Arr[i], y1Arr[i], x2Arr[i], y2Arr[i]);
end;

{==============================================================================]
  <Bounds>
  @action: Returns bounds of all boxes in array
  @note: None.
[==============================================================================}
function TBoxArrayHelper.Bounds: TBox; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result := Self[0];
  for i := 1 to High(Self) do
  begin
    Result.X1 := Min(Self[i].X1, Result.X1);
    Result.Y1 := Min(Self[i].Y1, Result.Y1);
    Result.X2 := Max(Self[i].X2, Result.X2);
    Result.Y2 := Max(Self[i].Y2, Result.Y2);
  end;
end;

{==============================================================================]
  <Boundaries>
  @action: Returns bounds of all boxes in array
  @note: None.
[==============================================================================}
function TBoxArrayHelper.Boundaries: TBox; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result := Self[0];
  for i := 1 to High(Self) do
  begin
    if (Result.X1 > Self[i].X1) then
	  Result.X1 := Self[i].X1;
    if (Result.Y1 > Self[i].Y1) then
	  Result.Y1 := Self[i].Y1;
	if (Result.X2 < Self[i].X2) then
	  Result.X2 := Self[i].X2;
    if (Result.Y2 < Self[i].Y2) then
	  Result.Y2 := Self[i].Y2;
  end;
end;
{$ENDIF}

{$UNDEF TBox}