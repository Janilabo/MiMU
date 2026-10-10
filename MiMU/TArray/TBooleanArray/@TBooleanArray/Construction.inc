{$IFDEF HELPERS}
class function Falsex(const ASize: UInt32 = 0): TBooleanArray; overload; static;
class function Truex(const ASize: UInt32 = 0): TBooleanArray; overload; static;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Falsepeated(const N: UInt32 = 1): TBooleanArray; overload;
function Truepeated(const N: UInt32 = 1): TBooleanArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Falsepeated>
  @action: Creates and returns a TBooleanArray of size N with all elements set to False.
  @note: Allocates and populates the array using the specified size.
[==============================================================================}
function Falsepeated(const N: UInt32 = 1): TBooleanArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(N) do
    Result[i] := False;
end;

{==============================================================================]
  <Truepeated>
  @action: Creates and returns a TBooleanArray of size N with all elements set to True.
  @note: Allocates and populates the array using the specified size.
[==============================================================================}
function Truepeated(const N: UInt32 = 1): TBooleanArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(N) do
    Result[i] := True;
end;

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
