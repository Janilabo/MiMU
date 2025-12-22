{$IFDEF HELPERS}
function Boxed(const xRadius, yRadius: Integer): TBox; overload;
function Boxed(const radius: Integer = 0): TBox; overload;
function ToBox(const width, height: Integer): TBox; overload;
function ToBox(const size: Integer = 0): TBox; overload;
function Boxify(const width, height: Integer): TBox; overload;
function Boxify(const size: Integer = 0): TBox; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Boxed>
  @action: Creates a square/rectangular box centered on the point,
           extending by xRadius horizontally and yRadius vertically.
  @note: Useful for defining an area of influence around a point.
[==============================================================================}
function TPointHelper.Boxed(const xRadius, yRadius: Integer): TBox; overload;
begin
  Result.X1 := (Self.X - xRadius);
  Result.Y1 := (Self.Y - yRadius);
  Result.X2 := (Self.X + xRadius);
  Result.Y2 := (Self.Y + yRadius);
end;

function TPointHelper.Boxed(const radius: Integer = 0): TBox; overload;
begin
  Result := Self.Boxed(radius, radius);
end;

{==============================================================================]
  <ToBox>
  @action: Creates a box using the point as the top-left corner (origin),
           extending rightward by width and downward by height.
  @note: Negative width/height make the box extend left/up instead.
[==============================================================================}
function TPointHelper.ToBox(const width, height: Integer): TBox; overload;
begin
  Result.X1 := IfThen((width < 0), (Self.X - width), Self.X);
  Result.Y1 := IfThen((height < 0), (Self.Y - height), Self.Y);
  Result.X2 := IfThen((width < 0), Self.X, (Self.X + width));
  Result.Y2 := IfThen((height < 0), Self.Y, (Self.Y + height));
end;

function TPointHelper.ToBox(const size: Integer = 0): TBox; overload;
begin
  Result := Self.ToBox(size, size);
end;

{==============================================================================]
  <Boxify>
  @action: Returns a box centered on the point with the specified width and height.
  @note: The box expands equally in all directions from the point’s center.
[==============================================================================}
function TPointHelper.Boxify(const width, height: Integer): TBox; overload;
var
  w, h: Integer;
begin
  w := (width div 2);
  h := (height div 2);
  Result.X1 := (Self.X - w);
  Result.Y1 := (Self.Y - h);
  Result.X2 := (Self.X + (width - w));
  Result.Y2 := (Self.Y + (height - h));
end;

function TPointHelper.Boxify(const size: Integer = 0): TBox; overload;
begin
  Result := Self.Boxify(size, size);
end;
{$ENDIF}