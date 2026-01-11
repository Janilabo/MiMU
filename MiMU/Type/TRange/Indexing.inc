{$IFDEF METHODS}
function IDs: TIntegerArray; overload; 
function IDs(const dValue: Integer): Integer; overload; 
function IDs(const dVals: TIntegerArray): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IDs>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.IDs: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Area);
  for i := 0 to High(Result) do
    Result[i] := i;
end;

{==============================================================================]
  <IDs>
  @action: Returns TRange index by TRange value.
  @note: Returns -2147483648 if dValue does not exist in TRange.
[==============================================================================}
function TRange.IDs(const dValue: Integer): Integer; overload;
begin
  case Self.Ascending of
    True:
    if ((dValue < Self.start) or (dValue > Self.stop)) then
      Result := -2147483648
    else
      Result := (dValue - Self.start);
    False:
    if ((dValue > Self.start) or (dValue < Self.stop)) then
      Result := -2147483648
    else
      Result := (Self.start - dValue);
  end;
end;

{==============================================================================]
  <IDs>
  @action: Returns TRange index by TRange value.
  @note: Returns -2147483648 if dValue does not exist in TRange.
[==============================================================================}
function TRange.IDs(const dVals: TIntegerArray): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, (High(dVals) + 1));
  for i := 0 to High(dVals) do
    Result[i] := Self.IDs(dVals[i]);
end;
{$ENDIF}