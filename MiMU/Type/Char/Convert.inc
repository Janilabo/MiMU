{$IFDEF HELPERS}
function Str(const size: Integer = 1): string;
function ToStr(const size: Integer = 1): string;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Str>
  @action: Returns Char as string with size.
  @note: size * Char.
[==============================================================================}
function TCharHelper.Str(const size: Integer = 1): string; 
var
  i: Integer;
begin
  if (size < 1) then
    Exit('');
  SetLength(Result, size);
  for i := 1 to size do
    Result[i] := Self;
end;

{==============================================================================]
  <ToStr>
  @action: Returns Char as string with size.
  @note: size * Char.
[==============================================================================}
function TCharHelper.ToStr(const size: Integer = 1): string; 
var
  i: Integer;
begin
  Result := '';
  for i := 1 to size do
    Result := (Result + Self);
end;
{$ENDIF}