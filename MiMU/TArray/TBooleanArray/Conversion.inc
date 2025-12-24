{$IFDEF HELPERS}
function Digits: TIntegerArray; overload;
function Str(const separator: string; const strTrue: string = 'True'; strFalse: string = 'False'): string; overload;
function Str: string; overload;
function Text(const strTrue, strFalse, separator: string): string; overload;
function Text(const strTrue: string = 'True'; strFalse: string = 'False'): string; overload;
function TIA(const valTrue: Integer = 1; const valFalse: Integer = 0): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Digits>
  @action: Returns TBooleanArray as Integers.
  @note: [True, False] => [1, 0].
[==============================================================================}
function TBooleanArrayHelper.Digits: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Ord(Self[i]);
end;

{==============================================================================]
  <Str>
  @action: Returns TBooleanArray as string.
  @note: Supports custom separator & True / False strings.
[==============================================================================}
function TBooleanArrayHelper.Str(const separator: string; const strTrue: string = 'True'; strFalse: string = 'False'): string; overload;
var
  i: Integer;
begin
  Result := '[';
  for i := 0 to High(Self) do
    if Self[i] then
      Result := (Result + strTrue + separator)
    else
      Result := (Result + strFalse + separator);
  if not (separator = '') then
    SetLength(Result, (System.Length(Result) - System.Length(separator)));
  Result := (Result + ']');
end;

function TBooleanArrayHelper.Str: string; overload;
begin
  Result := Self.Str(', ');
end;

{==============================================================================]
  <Text>
  @action: Returns TBooleanArray as string.
  @note: Supports custom separator & True / False strings.
[==============================================================================}
function TBooleanArrayHelper.Text(const strTrue, strFalse, separator: string): string; overload;
var
  i: Integer;
begin
  Result := '[';
  for i := 0 to High(Self) do
    if Self[i] then
      Result := (Result + strTrue + separator)
    else
      Result := (Result + strFalse + separator);
  if not (separator = '') then
    SetLength(Result, (System.Length(Result) - System.Length(separator)));
  Result := (Result + ']');
end;

function TBooleanArrayHelper.Text(const strTrue: string = 'True'; strFalse: string = 'False'): string; overload;
begin
  Result := Self.Text(strTrue, strFalse, ', ');
end;

{==============================================================================]
  <TIA>
  @action: Returns TBooleanArray as Integers.
  @note: [True, False] => [1, 0].
[==============================================================================}
function TBooleanArrayHelper.TIA(const valTrue: Integer = 1; const valFalse: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    if Self[i] then
      Result[i] := valTrue
    else
      Result[i] := valFalse;
end;
{$ENDIF}
