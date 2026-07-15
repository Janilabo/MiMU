{$IFDEF METHODS}
function Atomic: Boolean; overload;
function Degenerate: Boolean; overload;
function IsSingle: Boolean; overload;
function IsSingleton: Boolean; overload;
function IsSingular: Boolean; overload;
function Singleton: Boolean; overload;
function Singular: Boolean; overload;

function Composite: Boolean; overload;
function Directional: Boolean; overload;
function IsDirectional: Boolean; overload;
function IsInterval: Boolean; overload;
function IsPlural: Boolean; overload;
function Multiple: Boolean; overload;
function Plural: Boolean; overload;
function Proper: Boolean; overload;
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
  <Degenerate>
  @action: Determines whether the range has collapsed into a single point.
  @note: Returns True if the Minimum and Maximum boundaries are equal; otherwise, returns False.
[==============================================================================}
function TRange.Degenerate: Boolean; overload;
begin
  Result := (Self.Minimum = Self.Maximum);
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
  <IsSingleton>
  @action: Checks whether the range represents a single, unique point where the start and stop boundaries are equal.
  @note: Returns True if start equals stop; otherwise, returns False.
[==============================================================================}
function TRange.IsSingleton: Boolean; overload;
begin
  Result := (Self.start.Compare(Self.stop) = 0);
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
  <Directional>
  @action: Determines whether the range has a non-zero direction or vector.
  @note: 
    - Returns True if the Direction property is not equal to 0 (indicating movement).
    - Returns False if the range is stationary or degenerate (Direction = 0).
[==============================================================================}
function TRange.Directional: Boolean; overload;
begin
  Result := (Self.Direction <> 0);
end;

{==============================================================================]
  <IsDirectional>
  @action: Checks whether the range has a defined, non-zero direction.
  @note: 
    - Returns True if the Direction is not equal to 0.
    - Represents the logical equivalent of checking if the range is non-degenerate.
[==============================================================================}
function TRange.IsDirectional: Boolean; overload;
begin
  Result := not (Self.Direction = 0);
end;

{==============================================================================]
  <IsInterval>
  @action: Determines whether the range spans a valid, non-zero interval.
  @note: 
    - Returns True if the Maximum boundary is strictly greater than the Minimum boundary.
    - Returns False if the range is a single point (degenerate) or represents an empty set.
[==============================================================================}
function TRange.IsInterval: Boolean; overload;
begin
  Result := (Self.Maximum > Self.Minimum);
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
  <Proper>
  @action: Determines whether the range is a valid, non-degenerate proper interval.
  @note: 
    - Returns True strictly when the Minimum boundary is less than the Maximum boundary.
    - Returns False if the range is a single point (Minimum = Maximum) or inverted/invalid.
[==============================================================================}
function TRange.Proper: Boolean; overload;
begin
  Result := (Self.Minimum < Self.Maximum);
end;
{$ENDIF}
