{$IFDEF METHODS}
function StartIs(const item: Integer): Boolean; overload;
function StartIs(const items: TIntegerArray): Boolean; overload;
function StartIs(const items: TRange): Boolean; overload;
function StopIs(const item: Integer): Boolean; overload;
function StopIs(const items: TIntegerArray): Boolean; overload;
function StopIs(const items: TRange): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <StopIs>
  @action: Checks if the start boundary of the range matches a specific value.
  @note: Returns True if Self.start is exactly equal to the provided item.
[==============================================================================}
function TRange.StartIs(const item: Integer): Boolean; overload;
begin
  Result := (Self.start = item);
end;

{==============================================================================]
  <StopIs>
  @action: Checks if the start boundary matches any value within an array.
  @note: Iterates through the collection and returns True on the first match.
[==============================================================================}
function TRange.StartIs(const items: TIntegerArray): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(items) do
    if (items[i] = Self.start) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <StopIs>
  @action: Checks if the start boundary falls anywhere within a secondary target range.
  @note: Evaluates boundary containment using the target range's Contains method.
[==============================================================================}
function TRange.StartIs(const items: TRange): Boolean; overload;
var
  i: Integer;
begin
  Result := items.Contains(Self.start);
end;

{==============================================================================]
  <StopIs>
  @action: Checks if the stop boundary of the range matches a specific value.
  @note: Returns True if Self.stop is exactly equal to the provided item.
[==============================================================================}
function TRange.StopIs(const item: Integer): Boolean; overload;
begin
  Result := (Self.stop = item);
end;

{==============================================================================]
  <StopIs>
  @action: Checks if the stop boundary matches any value within an array.
  @note: Iterates through the collection and returns True on the first match.
[==============================================================================}
function TRange.StopIs(const items: TIntegerArray): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(items) do
    if (items[i] = Self.stop) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <StopIs>
  @action: Checks if the stop boundary falls anywhere within a secondary target range.
  @note: Evaluates boundary containment using the target range's Contains method.
[==============================================================================}
function TRange.StopIs(const items: TRange): Boolean; overload;
var
  i: Integer;
begin
  Result := items.Contains(Self.stop);
end;
{$ENDIF}
