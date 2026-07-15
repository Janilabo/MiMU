{$IFDEF METHODS}
function Atomic: Boolean; overload;
function Composite: Boolean; overload;
function IsPlural: Boolean; overload;
function IsSingle: Boolean; overload;
function IsSingular: Boolean; overload;
function Multiple: Boolean; overload;
function Plural: Boolean; overload;
function Singleton: Boolean; overload;
function Singular: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Atomic>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Atomic: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) = 0);
end;

{==============================================================================]
  <Composite>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Composite: Boolean; overload;
begin
  Result := not (Self.start = Self.stop);
end;

{==============================================================================]
  <IsPlural>
  @action: Checks if the range contains more than one element.
  @note: Returns True if Start does not equal Stop.
[==============================================================================}
function TRange.IsPlural: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) <> 0);
end;

{==============================================================================]
  <IsSingle>
  @action: Determines whether the range represents a single point.
  @note: 
    - Returns True if start and stop are equal.
    - Uses a branchless equality check via XOR:
        (start xor stop) = 0
      which holds only when both values are identical.
[==============================================================================}
function TRange.IsSingle: Boolean; overload;
begin
  Result := ((Self.start xor Self.stop) = 0);
end;

{==============================================================================]
  <IsSingular>
  @action: Checks if the range contains exactly one element.
  @note: Returns True if Start equals Stop.
         Can be used to optimize operations on singleton ranges or avoid unnecessary iteration.
[==============================================================================}
function TRange.IsSingular: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) = 0);
end;

{==============================================================================]
  <Multiple>
  @action: Determines whether the range contains more than one value.
  @note: 
    - Returns True if Size > 1.
    - Represents the logical complement of Singleton.
    - Assumes Size reflects the number of discrete values within the range.
[==============================================================================}
function TRange.Multiple: Boolean; overload;
begin
  Result := (Self.Size > 1);
end;

{==============================================================================]
  <Plural>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Plural: Boolean; overload;
begin
  Result := (Self.start <> Self.stop);
end;

{==============================================================================]
  <Singleton>
  @action: Determines whether the range contains exactly one value.
  @note: 
    - Returns True if the range size is equal to 1.
    - Assumes Size is defined as the count of discrete values within [start, stop].
    - For continuous ranges, prefer equality check (start = stop) instead.
[==============================================================================}
function TRange.Singleton: Boolean; overload;
begin
  Result := (Self.Size = 1);
end;

{==============================================================================]
  <Singular>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Singular: Boolean; overload;
begin
  Result := (Self.start = Self.stop);
end;
{$ENDIF}
