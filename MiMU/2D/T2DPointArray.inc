{$DEFINE MType := TPoint}
{$DEFINE MArray := TPointArray}
{$DEFINE M2DArray := T2DPointArray}
{$DEFINE MHelper := T2DPointArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
T2DPointArrayHelper = type helper for T2DPointArray
  {$I Core.inc}
  function AllBounds: TBoxArray; overload;
  function AllBounds(var aBounds: TBox): TBoxArray; overload;
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AllBounds>
  @action: Returns an array containing the bounding box of each point in the array.
  @note: Each element in the result corresponds to the bounds of a single point.
[==============================================================================}
function T2DPointArrayHelper.AllBounds: TBoxArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Bounds;
end;

{==============================================================================]
  <AllBounds(var aBounds)>
  @action: Returns an array of per-point bounding boxes and outputs the overall bounding box covering all points.
  @note: The 'aBounds' parameter receives the minimal bounding box enclosing all individual boxes.
[==============================================================================}
function T2DPointArrayHelper.AllBounds(var aBounds: TBox): TBoxArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  if (Self.Length > 0) then
  begin
    aBounds := Self[0].Bounds;
    Result[0] := aBounds;
    for i := 1 to High(Self) do
    begin
      Result[i] := Self[i].Bounds;
      aBounds.X1 := Min(Result[i].X1, aBounds.X1);
      aBounds.Y1 := Min(Result[i].Y1, aBounds.Y1);
      aBounds.X2 := Max(Result[i].X2, aBounds.X2);
      aBounds.Y2 := Max(Result[i].Y2, aBounds.Y2);
    end;
  end else
    aBounds.Create(-2147483648);
end;
{$ENDIF}