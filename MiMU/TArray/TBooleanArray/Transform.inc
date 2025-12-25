{$IFDEF HELPERS}
function Toggle: TBooleanArray; overload;
function Opposite: TBooleanArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Toggle>
  @action: Returns opposite version of arr.
  @note: [True, False] => [False, True].
[==============================================================================}
function TBooleanArrayHelper.Toggle: TBooleanArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := (not Self[i]);
end;

{==============================================================================]
  <Opposite>
  @action: Returns opposite version of arr.
  @note: [True, False] => [False, True].
[==============================================================================}
function TBooleanArrayHelper.Opposite: TBooleanArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    if Self[i] then
      Result[i] := False
	else
	  Result[i] := True;
end;
{$ENDIF}
