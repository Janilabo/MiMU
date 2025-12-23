{$IFDEF TYPES}
function Extend(const val: Integer): Boolean;
function Absorb(const val: Integer): Boolean; overload; 
function Include(const val: Integer): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Extend>
  @action: Returns true TRange is extended with val (val is not yet in range)
  @note: None.
[==============================================================================}
function TRange.Extend(const val: Integer): Boolean;
begin
  case Self.Descending of
    True:
    if (val > Self.start) then
      Self.start := val
    else
      if (val < Self.stop) then
        Self.stop := val
      else
        Exit(False);
    False:
    if (val < Self.start) then
      Self.start := val
    else
      if (val > Self.stop) then
        Self.stop := val
      else
        Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <Include>
  @action: Expands the range to include the given value while preserving ascending/descending order.
  @note: If the value is already inside the range, the range remains unchanged.
[==============================================================================}
function TRange.Include(const val: Integer): TRange; overload;
begin
  Result := Self;
  case Result.Ascending of
    True:
    if (val < Result.start) then
      Result.start := val
    else
      if (val > Result.stop) then
        Result.stop := val;
    False:
    if (val < Result.stop) then
      Result.stop := val
    else
      if (val > Result.start) then
        Result.start := val;
  end;
end;

{==============================================================================]
  <Absorb>
  @action: Expands the range to include the given value while preserving ascending/descending order.
  @note: If the value is already inside the range, the range remains unchanged.
         Returns true if value was added in.
[==============================================================================}
function TRange.Absorb(const val: Integer): Boolean; overload;
var
  s: TRange;
begin
  s := Self;
  case Self.Ascending of
    True:
    if (val < Self.start) then
      Self.start := val
    else
      if (val > Self.stop) then
        Self.stop := val;
    False:
    if (val > Self.start) then
      Self.start := val
    else
      if (val < Self.stop) then
        Self.stop := val;
  end;
  Result := (Self <> s); 
end;
{$ENDIF}