{==============================================================================]
  <TStringArrayHelper.Span>
  @action: Returns total length of TStringArray strings combined together.
  @note: None.
[==============================================================================}
function TStringArrayHelper.Span: Integer; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result.Increase(Length(Self[i]));
end;

{==============================================================================]
  <TStringArrayHelper.Concat>
  @action: Joins all the strings of array as single string.
  @note: Chaining.
[==============================================================================}
function TStringArrayHelper.Concat: string; cdecl;
var
  i, j, l: Integer;
begin
  l := 0;
  SetLength(Result, Self.Span);
  for i := 0 to High(Self) do
    for j := 1 to Length(Self[i]) do
      Result[l.Increment] := Self[i][j];
end;

{==============================================================================]
  <TStringArrayHelper.Concatenate>
  @action: Joins all the strings of array as single string.
  @note: Chaining.
[==============================================================================}
function TStringArrayHelper.Concatenate: string; cdecl;
var
  s: TStringBuilder;
  i: Integer;
begin
  s := TStringBuilder.Create;
  try
    s.Capacity := Self.Span;
    for i := 0 to High(Self) do
      s.Append(Self[i]);
    Result := s.ToString;
  finally
    s.Free;
  end;
end;

{==============================================================================]
  <TStringArrayHelper.Flatten>
  @action: Joins all the strings of array as single string.
  @note: Chaining.
         Warning: This algorithm is not recommended for lengthy string arrays!
		          Very inefficient...
[==============================================================================}
function TStringArrayHelper.Flatten: string; cdecl;
var
  i: SizeInt;
begin
  Result := '';
  for i := 0 to High(Self) do
    Result := (Result + Self[i]);
end;
