{$DEFINE TPoint}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
CPointArray = class
public
  class function Init(var arr: TPointArray): Integer; overload; 
  class function Unique(var arr: TPointArray): Integer; overload; 
  class function Create(const xRange, yRange: TRange): TPointArray; overload; 
  class function Create(const xRange, yRange: TRange; const offset: TPoint): TPointArray; overload; 
  class function Create(const xValues, yValues: TIntegerArray): TPointArray; overload; 
  class function Create(const xValues, yValues: TIntegerArray; const offset: TPoint): TPointArray; overload; 
end;
{$ENDIF}

{$IFDEF HELPERS}
TPointArrayHelper = type helper for TPointArray
  {$I ../TArray.inc}
  {$I TPointArray.pph}
  function Reinit: Integer; overload;
  function Pure(const allowed: TPointArray): Boolean; overload;
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../TArray.inc}
{$I TPointArray.pph}
{$IFNDEF CLASSES}
{$DEFINE FField := X}{$I ../F.inc}
{$DEFINE FField := Y}{$I ../F.inc}
{$ENDIF}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           setting all TPoint elements to (0,0), while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Reinit: Integer; 
begin
  Result := Self.Size;
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(TPoint)), 0);
end;

function TPointArrayHelper.Pure(const allowed: TPointArray): Boolean; overload; var a: TPointArray; {$DEFINE Skeleton_Pure}{$I ../Skeletons.inc}{$UNDEF Skeleton_Pure}

class function CPointArray.Init(var arr: TPointArray): Integer; overload; 
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], (Result * SizeOf(TPoint)), 0);
end;

class function CPointArray.Unique(var arr: TPointArray): Integer; overload; 
var
  i, r, l, w, h: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  l := Length(arr);
  if (l > 1) then
  begin
    r := 0;
    b := arr.Bounds(w, h);
    m := T2D.Create(False, w, h);
    for i := 0 to (l - 1) do
      if m[arr[i].X - b.X1][arr[i].Y - b.Y1].Enable then
        arr[r.Increase] := arr[i];
    SetLength(arr, r);
    SetLength(m, 0);
  end;
  Result := (l - Length(arr));
end;

class function CPointArray.Create(const xRange, yRange: TRange): TPointArray; overload; 
var
  x, y, i: Integer;
begin
  SetLength(Result, (xRange.Size * yRange.Size));
  i := 0;
  for y in yRange do
    for x in xRange do
      Result[i.Increase] := Point(x, y);
end;

class function CPointArray.Create(const xRange, yRange: TRange; const offset: TPoint): TPointArray; overload; 
var
  x, y, i: Integer;
begin
  SetLength(Result, (xRange.Size * yRange.Size));
  i := 0;
  for y in yRange do
    for x in xRange do
      Result[i.Increase] := Point((x + offset.X), (y + offset.Y));
end;

class function CPointArray.Create(const xValues, yValues: TIntegerArray): TPointArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, Min(Length(xValues), Length(yValues)));
  for i := 0 to High(Result) do
    Result[i] := Point(xValues[i], yValues[i]);	
end;

class function CPointArray.Create(const xValues, yValues: TIntegerArray; const offset: TPoint): TPointArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, Min(Length(xValues), Length(yValues)));
  for i := 0 to High(Result) do
    Result[i] := Point((xValues[i] + offset.X), (yValues[i] + offset.Y));	
end;
{$ENDIF}

{$UNDEF BASE}{$UNDEF TPoint}
