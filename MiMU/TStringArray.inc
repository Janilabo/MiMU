{$DEFINE string}{$I config\Defines.inc}

{$IFDEF INTERFACE}
{$ENDIF}

{$IFDEF HELPERS}
type
  TStringArrayHelper = type helper for TStringArray
    {$I config\1D.inc}
    function Tally: Int64;
    function Concat: string;
    function Concatenate: string;
    function Flatten: string;
    function Glue: string;
  end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\1D.inc}

{==============================================================================]
  <Tally>
  @action: Returns total length of TStringArray strings combined together.
  @note: None.
[==============================================================================}
function TStringArrayHelper.Tally: Int64;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result.Increase(System.Length(Self[i]));
end;

{==============================================================================]
  <Concat>
  @action: Joins all the strings of array as single string.
  @note: Chaining.
[==============================================================================}
function TStringArrayHelper.Concat: string;
var
  i, j, l: Integer;
begin
  l := 0;
  SetLength(Result, Self.Tally);
  for i := 0 to High(Self) do
    for j := 1 to System.Length(Self[i]) do
      Result[l.Increment] := Self[i][j];
end;

{==============================================================================]
  <Concatenate>
  @action: Joins all the strings of array as single string.
  @note: Chaining.
[==============================================================================}
function TStringArrayHelper.Concatenate: string;
var
  s: TStringBuilder;
  i: Integer;
begin
  s := TStringBuilder.Create;
  try
    s.Capacity := Self.Tally;
    for i := 0 to High(Self) do
      s.Append(Self[i]);
    Result := s.ToString;
  finally
    s.Free;
  end;
end;

{==============================================================================]
  <Flatten>
  @action: Joins all the strings of array as single string.
  @note: Chaining.
         Warning: This algorithm is not recommended for lengthy string arrays!
		          Very inefficient...
[==============================================================================}
function TStringArrayHelper.Flatten: string;
var
  i: SizeInt;
begin
  Result := '';
  for i := 0 to High(Self) do
    Result := (Result + Self[i]);
end;

{==============================================================================]
  <Glue>
  @action: Joins all the strings of array as single string.
  @note: Chaining.
[==============================================================================}
function TStringArrayHelper.Glue: string;
var
  c: TCharArray;
  i, p, l: Integer;
begin
  l := Self.Tally;
  SetLength(c, l);
  p := 0;
  for i := 0 to High(Self) do
    if (Self[i] <> '') then
    begin
      Move(Self[i][1], c[p], System.Length(Self[i]) * SizeOf(Char));
      Inc(p, System.Length(Self[i]));
    end;
  SetString(Result, PChar(@c[0]), l);
end;
{$ENDIF}

{$UNDEF string}
