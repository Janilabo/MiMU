{$IFDEF FUNCTIONS}
generic function IncEx<T>(var values: array of T; const N: T = 1): Integer; overload;
generic function DecEx<T>(var values: array of T; const N: T = 1): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IncEx>
  @action: Increments every element in an open array by a specified value.
  @note: Operates directly on the passed array (var). Defaults to adding 1.
         Returns the total number of elements that were increased.
[==============================================================================}
generic function IncEx<T>(var values: array of T; const N: T = 1): Integer; overload;
var
  i: Integer;
begin
  Result := Length(values);
  for i := Low(values) to High(values) do
    values[i] := (values[i] + N);
end;

{==============================================================================]
  <DecEx>
  @action: Decrements every element in an open array by a specified value.
  @note: Operates directly on the passed array (var). Defaults to subtracting 1.
         Returns the total number of elements that were decreased.
[==============================================================================}
generic function DecEx<T>(var values: array of T; const N: T = 1): Integer; overload;
var
  i: Integer;
begin
  Result := Length(values);
  for i := Low(values) to High(values) do
    values[i] := (values[i] - N);
end;
{$ENDIF}
