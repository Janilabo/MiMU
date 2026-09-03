{$IFDEF METHODS}
function ToStr: string; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ToStr>
  @action: Converts TPoint to string.
  @note: (x,y)
[==============================================================================}
function TPoint.ToStr: string; overload;
begin
  Result := ('(' + IntToStr(Self.X) + ',' + IntToStr(Self.Y) + ')');
end;
{$ENDIF}