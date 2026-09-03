{$IFDEF METHODS}
function ToStr: string; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ToStr>
  @action: Converts TBox to string.
  @note: (x1,y1,x2,y2)
[==============================================================================}
function TBox.ToStr: string; overload;
begin
  Result := ('(' + IntToStr(Self.X1) + ',' + IntToStr(Self.Y1) + ',' + IntToStr(Self.X2) + ',' + IntToStr(Self.Y2) + ')');
end;
{$ENDIF}