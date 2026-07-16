{$IFDEF METHODS}
function Blanco: TBox;
function Frame(var fWidth, fHeight: Integer): TBox; overload;
function Frame: TBox; overload;
function Localize: TPoint;
function Localized: TBox;
function Template: TBox; 
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Blanco>
  @action: Returns a copy of the box translated so that its top-left corner
           lies at the origin (0,0).
  @note: This is a non-mutating operation. The resulting box preserves the
         original width and height but has zero-based coordinates. Equivalent
         to translating the box by (-X1, -Y1).
[==============================================================================}
function TBox.Blanco: TBox;
var
  o: TPoint;
begin
  o := Point(-Self.X1, -Self.Y1);
  Result := Box((Self.X1 + o.X), (Self.Y1 + o.Y), (Self.X2 + o.X), (Self.Y2 + o.Y));
end;

{==============================================================================]
  <Frame>
  @action: Returns the frame of TBox
  @note: Dimensional box of the TBox. Based on Width and Height.
[==============================================================================}
function TBox.Frame(var fWidth, fHeight: Integer): TBox; overload;
begin
  fWidth := Self.Width;
  fHeight := Self.Height;
  Result := Box(0, 0, (fWidth - 1), (fHeight - 1));
end;

{==============================================================================]
  <Frame>
  @action: Returns the frame of TBox
  @note: Dimensional box of the TBox. Based on Width and Height.
[==============================================================================}
function TBox.Frame: TBox; overload;
begin
  Result := Box(0, 0, (Self.Width - 1), (Self.Height - 1));
end;

{==============================================================================]
  <Localize>
  @action: Converts the box in place to local (zero-based) coordinates and
           returns the original top-left offset.
  @note: This is a mutating operation. After the call, X1 and Y1 are zero and
         X2/Y2 represent width and height. The returned point can be used to
         restore or re-apply the original position.
[==============================================================================}
function TBox.Localize: TPoint;
begin
  Result := Point(Self.X1, Self.Y1);
  Self.X1 := 0;
  Self.Y1 := 0;
  Dec(Self.X2, Result.X);
  Dec(Self.Y2, Result.Y);
end;

{==============================================================================]
  <Localized>
  @action: Returns a zero-based copy of the box with identical extents.
  @note: Functionally equivalent to <Template>, but implemented via relative
         coordinate adjustment rather than explicit subtraction. Does not
         modify the original instance.
[==============================================================================}
function TBox.Localized: TBox;
begin
  Result := Self;
  Dec(Result.X2, Result.X1);
  Dec(Result.Y2, Result.Y1);
  Result.X1 := 0;
  Result.Y1 := 0;
end;

{==============================================================================]
  <Template>
  @action: Returns a zero-based box representing only the dimensions
           (width and height) of the original box.
  @note: Position information is discarded. The result always starts at
         (0,0) with X2 = Width and Y2 = Height. Non-mutating.
[==============================================================================}
function TBox.Template: TBox;
begin
  Result.X1 := 0;
  Result.Y1 := 0;
  Result.X2 := (Self.X2 - Self.X1);
  Result.Y2 := (Self.Y2 - Self.Y1);
end;
{$ENDIF}