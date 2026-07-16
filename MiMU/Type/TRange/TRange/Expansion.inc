{$IFDEF METHODS}
function Asclude(const val: Integer): Boolean; overload;
function Desclude(const val: Integer): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Asclude>
  @action: Conditionally expands an ascending range to include the specified value.
  @note: Only executes if start <= stop. If the value lies outside the current
         boundaries, updates start (if lower) or stop (if higher) and returns True.
         Otherwise, returns False.
[==============================================================================}
function TRange.Asclude(const val: Integer): Boolean; overload;
begin
  if (Self.start > Self.stop) then
    Result := False
  else if Self.start.Minate(val) then
    Exit(True)
  else
    Result := Self.stop.Maxate(val);
end;

{==============================================================================]
  <Desclude>
  @action: Conditionally expands a descending range to include the specified value.
  @note: Only executes if start >= stop. If the value lies outside the current
         boundaries, updates stop (if lower) or start (if higher) and returns True.
         Otherwise, returns False.
[==============================================================================}
function TRange.Desclude(const val: Integer): Boolean; overload;
begin
  if (Self.start < Self.stop) then
    Result := False
  else if Self.stop.Minate(val) then
    Exit(True)
  else
    Result := Self.start.Maxate(val);
end;
{$ENDIF}
