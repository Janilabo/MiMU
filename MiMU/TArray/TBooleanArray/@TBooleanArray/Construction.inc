{$IFDEF HELPERS}
class function Falsex(const ASize: UInt32 = 0): TBooleanArray; overload; static;
class function Truex(const ASize: UInt32 = 0): TBooleanArray; overload; static;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Falsex>
  @action: Creates and returns a new TBooleanArray of the given size, filled entirely with False.
  @note: Returns an empty array if ASize is 0.
[==============================================================================}
class function TBooleanArrayHelper.Falsex(const ASize: UInt32 = 0): TBooleanArray; overload;
var
  i: Integer;
begin
  for i := 0 to (Result.Alloc(ASize) - 1) do
    Result[i] := False;
end;

{==============================================================================]
  <Truex>
  @action: Creates and returns a new TBooleanArray of the given size, filled entirely with True.
  @note: Returns an empty array if ASize is 0.
[==============================================================================}
class function TBooleanArrayHelper.Truex(const ASize: UInt32 = 0): TBooleanArray; overload;
var
  i: Integer;
begin
  for i := 0 to (Result.Alloc(ASize) - 1) do
    Result[i] := True;
end;
{$ENDIF}
