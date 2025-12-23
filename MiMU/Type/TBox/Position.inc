{$IFDEF METHODS}
function Centered(const toArea: TBox): TBox; 
function CenterVertically(const toArea: TBox): TBox; 
function CenterHorizontally(const toArea: TBox): TBox;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Centered>
  Explanation: Returns bx (by the dimensions) centered to area.
  @note: None.
[==============================================================================}
function TBox.Centered(const toArea: TBox): TBox;
var
  w, h: Integer;
begin
  Self.Size(w, h);
  Result.X1 := (toArea.X1 + ((toArea.Width - w) div 2));
  Result.Y1 := (toArea.Y1 + ((toArea.Height - h) div 2));
  Result.X2 := (Result.X1 + (w - 1));
  Result.Y2 := (Result.Y1 + (h - 1));
end;

{==============================================================================]
  <CenterVertically>
  Explanation: Returns bx centered vertically to area.
  @note: None.
[==============================================================================}
function TBox.CenterVertically(const toArea: TBox): TBox;
var
  h: Integer;
begin
  h := Self.Height;
  Result.X1 := Self.X1;
  Result.Y1 := (toArea.Y1 + ((toArea.Height - h) div 2));
  Result.X2 := Self.X2;
  Result.Y2 := (Result.Y1 + (h - 1));
end;

{==============================================================================]
  <CenterHorizontally>
  Explanation: Returns bx centered horizontally to area.
  @note: None.
[==============================================================================}
function TBox.CenterHorizontally(const toArea: TBox): TBox;
var
  w: Integer;
begin
  w := Self.Width;
  Result.X1 := (toArea.X1 + ((toArea.Width - w) div 2));
  Result.X2 := (Result.X1 + (w - 1));
  Result.Y1 := Self.Y1;
  Result.Y2 := Self.Y2;
end;
{$ENDIF}