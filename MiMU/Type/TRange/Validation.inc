{$IFDEF METHODS}
function Exceeds(const maxElements: Integer): Boolean; cdecl;
function Insufficient(const minElements: Integer): Boolean; cdecl;
function Uniform(const val: Integer): Boolean; overload; cdecl;
function Uniform: Boolean; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Exceeds>
  @action: Returns true if TRange contains more than maxElements.
  @note: TRange Exceeds maximum elements.
[==============================================================================}
function TRange.Exceeds(const maxElements: Integer): Boolean; cdecl;
begin
  Result := (Self.Size > maxElements);
end;

{==============================================================================]
  <Insufficient>
  @action: Returns true if TRange contains less than minElements.
  @note: TRange is behind minimum elements.
[==============================================================================}
function TRange.Insufficient(const minElements: Integer): Boolean; cdecl;
begin
  Result := (Self.Size < minElements);
end;

{==============================================================================]
  <Uniform>
  @action: Checks whether both endpoints of the range equal the specified value.
  @note: Returns True only if (Start = Stop = val).
[==============================================================================}
function TRange.Uniform(const val: Integer): Boolean; overload; cdecl;
begin
  Result := ((Self.start = val) and (Self.stop = val));
end;

{==============================================================================]
  <Uniform>
  @action: Checks whether the range’s start and stop positions are equal.
  @note: Returns True if (Start = Stop).
[==============================================================================}
function TRange.Uniform: Boolean; overload; cdecl;
begin
  Result := (Self.start = Self.stop);
end;
{$ENDIF}