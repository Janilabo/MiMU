{$IFDEF METHODS}
function Resize(const change: Integer): TBox; cdecl;
function ResizeBottom(const change: Integer): TBox; cdecl;
function ResizeBottomLeft(const change: Integer): TBox; cdecl;
function ResizeBottomRight(const change: Integer): TBox; cdecl;
function ResizeHorizontally(const change: Integer): TBox; cdecl;
function ResizeLeft(const change: Integer): TBox; cdecl;
function ResizeRight(const change: Integer): TBox; cdecl;
function ResizeTop(const change: Integer): TBox; cdecl;
function ResizeTopLeft(const change: Integer): TBox; cdecl;
function ResizeTopRight(const change: Integer): TBox; cdecl;
function ResizeVertically(const change: Integer): TBox; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Resize>
  @action: Returns bx that has been resized fully by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.Resize(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <ResizeBottom>
  @action: Returns bx that has been resized from bottom by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeBottom(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := Self.X2;
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <ResizeBottomLeft>
  @action: Returns bx that has been resized from bottom-left by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeBottomLeft(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := Self.Y1;
  Result.X2 := Self.X2;
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <ResizeBottomRight>
  @action: Returns bx that has been resized from bottom-right by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeBottomRight(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <ResizeHorizontally>
  @action: Returns bx that has been resized horizontally by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeHorizontally(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeLeft>
  @action: Returns bx that has been resized from left-side by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeLeft(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := Self.Y1;
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeRight>
  @action: Returns bx that has been resized from right-side by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeRight(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeTop>
  @action: Returns bx that has been resized horizontally by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeTop(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeTopLeft>
  @action: Returns bx that has been resized from top-left by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeTopLeft(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeTopRight>
  @action: Returns bx that has been resized from top-right by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeTopRight(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <ResizeVertically>
  @action: Returns bx that has been resized vertically by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBox.ResizeVertically(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := (Self.Y2 + change);
end;
{$ENDIF}