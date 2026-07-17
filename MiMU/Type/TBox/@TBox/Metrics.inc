{$IFDEF METHODS}
function Circumference: Integer; overload;
function Diagonal: Double; overload;
function Perim: Integer; overload;
function Perimeter: Integer; overload;
function Population(const scale: Integer = 1): Integer; overload;
function Ratio: Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Circumference>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Circumference: Integer; overload;
begin
  Result := ((Self.Width - 1) shl 1) + ((Self.Height - 1) shl 1);
end;

{==============================================================================]
  <Diagonal>
  @action: Returns diagonal size of bx.
  @note: None.
[==============================================================================}
function TBox.Diagonal: Double; overload;
begin
  Result := Sqrt(Sqr(Self.Width) + Sqr(Self.Height));
end;

{==============================================================================]
  <Perim>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Perim: Integer; overload;
begin
  Result := (2 * (Pred(Self.Width) + Pred(Self.Height)));
end;

{==============================================================================]
  <Perimeter>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Perimeter: Integer; overload;
begin
  Result := ((2 * (Self.Width + Self.Height)) - 4);
end;

{==============================================================================]
  <Population>
  @action: Returns the number of discrete elements contained in the box after
           uniform integer scaling.
  @note: The population is computed using inclusive bounds:
         ((X2 − X1 + 1) × scale) × ((Y2 − Y1 + 1) × scale).
         No validation or clamping is performed; negative extents or scale
         values will yield negative results.
[==============================================================================}
function TBox.Population(const scale: Integer = 1): Integer; overload;
begin
  Result := ((((Self.X2 - Self.X1) + 1) * scale) * (((Self.Y2 - Self.Y1) + 1) * scale));
end;

{==============================================================================]
  <Ratio>
  @action: Returns ratio of Width to Height.
  @note: None.
[==============================================================================}
function TBox.Ratio: Double; overload;
begin
  Result := (Self.Width / Self.Height);
end;
{$ENDIF}
