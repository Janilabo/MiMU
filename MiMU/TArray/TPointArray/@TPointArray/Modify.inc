{$IFDEF HELPERS}
function XsTo(const value: Integer = 0): Integer; overload;
function YsTo(const value: Integer = 0): Integer; overload;
function XsAs(const value: Integer = 0): TPointArray; overload;
function YsAs(const value: Integer = 0): TPointArray; overload;
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
{$ENDIF}
