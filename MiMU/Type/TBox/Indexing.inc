{$IFDEF TYPES}
function IDs: TIntegerArray; overload; 
function IDs(const p: TPoint): Integer; overload; 
function IDs(const p: TPointArray): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IDs>
  @action: Returns TBox indexes as TIntegerArray
  @note: None.
[==============================================================================}
function TBox.IDs: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Area);
  for i := 0 to (Self.Area - 1) do
    Result[i] := i;
end;

{==============================================================================]
  <IDs>
  @action: Returns TBox index with TPoint p.
  @note: -1 if p is not part of TBox.
[==============================================================================}
function TBox.IDs(const p: TPoint): Integer; overload;
begin
  if not Self.Contains(p) then
    Exit(-1);
  Result := (((p.Y - Self.Y1) * Self.Width) + (p.X - Self.X1));
end;

{==============================================================================]
  <IDs>
  @action: Returns TBox indexes with TPointArray p.
  @note: -1 if p is not part of TBox.
[==============================================================================}
function TBox.IDs(const p: TPointArray): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(p));
  for i := 0 to High(p) do
    Result[i] := Self.IDs(p[i]);
end;
{$ENDIF}