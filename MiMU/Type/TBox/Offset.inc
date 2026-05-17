{$IFDEF METHODS}
function Offset(const bXS, bYS, bXE, bYE: Integer): TBox; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Offset>
  @action: Returns a new TBox whose edges are offset from Self by the
           specified deltas.
  @note: Offsets are applied independently to each edge (X1, Y1, X2, Y2).
         This method does not normalize or validate the resulting box.
         Self remains unchanged.
[==============================================================================}
function TBox.Offset(const bXS, bYS, bXE, bYE: Integer): TBox; overload;
begin
  Result.X1 := (Self.X1 + bXS);
  Result.Y1 := (Self.Y1 + bYS);
  Result.X2 := (Self.X2 + bXE);
  Result.Y2 := (Self.Y2 + bYE);
end;
{$ENDIF}
