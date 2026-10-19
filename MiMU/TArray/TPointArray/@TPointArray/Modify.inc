{$IFDEF HELPERS}
function XsTo(const value: Integer = 0): Integer; overload;
function XsTo(const source: TPointArray): Integer; overload;
function YsTo(const value: Integer = 0): Integer; overload;
function YsTo(const source: TPointArray): Integer; overload;
function XsAs(const value: Integer = 0): TPointArray; overload;
function XsAs(const source: TPointArray): TPointArray; overload;
function YsAs(const value: Integer = 0): TPointArray; overload;
function YsAs(const source: TPointArray): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <XsTo>
  @action: Sets the X-coordinate of every point in the TPointArray to value.
  @note: Mutates Self. Returns the number of points modified (Self.Length).
[==============================================================================}
function TPointArrayHelper.XsTo(const value: Integer = 0): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to (Result - 1) do
    Self[i].X := value;
end;

{==============================================================================]
  <XsTo>
  @action: Copies the X coordinates from a source TPointArray into this TPointArray.
  @note: Returns the number of elements copied (the minimum length of both arrays).
[==============================================================================}
function TPointArrayHelper.XsTo(const source: TPointArray): Integer; overload;
var
  i: Integer;
begin
  Result := Min(Self.Length, source.Length);
  for i := 0 to (Result - 1) do
    Self[i].X := source[i].X;
end;

{==============================================================================]
  <YsTo>
  @action: Sets the Y-coordinate of every point in the TPointArray to value.
  @note: Mutates Self. Returns the number of points modified (Self.Length).
[==============================================================================}
function TPointArrayHelper.YsTo(const value: Integer = 0): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  for i := 0 to (Result - 1) do
    Self[i].Y := value;
end;

{==============================================================================]
  <XsTo>
  @action: Copies the Y coordinates from a source TPointArray into this TPointArray.
  @note: Returns the number of elements copied (the minimum length of both arrays).
[==============================================================================}
function TPointArrayHelper.YsTo(const source: TPointArray): Integer; overload;
var
  i: Integer;
begin
  Result := Min(Self.Length, source.Length);
  for i := 0 to (Result - 1) do
    Self[i].Y := source[i].Y;
end;

{==============================================================================]
  <XsAs>
  @action: Returns a copy of the TPointArray with every X-coordinate set to value.
  @note: Self is left unchanged. Y-coordinates and point order are preserved.
[==============================================================================}
function TPointArrayHelper.XsAs(const value: Integer = 0): TPointArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
  begin
    Result[i].X := value;
    Result[i].Y := Self[i].Y;
  end;
end;

{==============================================================================]
  <XsAs>
  @action: Returns a new TPointArray with X coordinates from the source array 
           and Y coordinates from this array.
  @note: If the source array is shorter than this array, the remaining X coordinates 
         are kept from this array. If longer, extra source elements are ignored.
[==============================================================================}
function TPointArrayHelper.XsAs(const source: TPointArray): TPointArray; overload;
var
  i, s: Integer;
begin
  s := source.Length;
  for i := 0 to Result.Alloc(Self.Length) do
  begin
    if (i < s) then
      Result[i].X := source[i].X
	else
	  Result[i].X := Self[i].X;
    Result[i].Y := Self[i].Y;
  end;
end;

{==============================================================================]
  <YsTo>
  @action: Returns a copy of the TPointArray with every Y-coordinate set to value.
  @note: Self is left unchanged. X-coordinates and point order are preserved.
[==============================================================================}
function TPointArrayHelper.YsAs(const value: Integer = 0): TPointArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
  begin
    Result[i].X := Self[i].X;
    Result[i].Y := value;
  end;
end;

{==============================================================================]
  <YsTo>
  @action: Returns a new TPointArray with Y coordinates from the source array 
           and X coordinates from this array.
  @note: If the source array is shorter than this array, the remaining Y coordinates 
         are kept from this array. If longer, extra source elements are ignored.
[==============================================================================}
function TPointArrayHelper.YsAs(const source: TPointArray): TPointArray; overload;
var
  i, s: Integer;
begin
  s := source.Length;
  for i := 0 to Result.Alloc(Self.Length) do
  begin
    if (i < s) then
      Result[i].X := source[i].X
	else
	  Result[i].X := Self[i].X;
    Result[i].Y := Self[i].Y;
  end;
end;
{$ENDIF}
