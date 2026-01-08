{$IFDEF HELPERS}
function Tokenize(const str: string): TStringArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function TCharHelper.Tokenize(const str: string): TStringArray; overload; cdecl;
var
  s, i, l: Integer;
begin
  if (Length(str) = 0) then
    Exit([]);
  SetLength(Result, (str.Count(Self) + 1));
  s := 1;
  l := 0;
  for i := 1 to Length(str) do
  begin
    if (str[i] <> Self) then
      Continue;
    Result[l.Increase] := Copy(str, s, (i - s));
    s := (i + 1);
  end;
  Result[l] := Copy(str, s, ((Length(str) - s) + 1));
end;
{$ENDIF}