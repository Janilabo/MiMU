{==============================================================================]
  <TCharHelper.Compare>
  @action: Compares char with target.
  @note: Results: 0=EQUAL, 1=char>target, -1=char<target
[==============================================================================}
function TCharHelper.Compare(const target: Char): Integer; cdecl; inline; {$DEFINE Skeleton_Compare}{$I config\Skeletons.inc}{$UNDEF Skeleton_Compare}

{==============================================================================]
  <TCharHelper.Str>
  @action: Returns Char as string with size.
  @note: size * Char.
[==============================================================================}
function TCharHelper.Str(const size: Integer = 1): string; cdecl;
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
  <TCharHelper.ToStr>
  @action: Returns Char as string with size.
  @note: size * Char.
[==============================================================================}
function TCharHelper.ToStr(const size: Integer = 1): string; cdecl;
var
  i: Integer;
begin
  Result := '';
  for i := 1 to size do
    Result := (Result + Self);
end;