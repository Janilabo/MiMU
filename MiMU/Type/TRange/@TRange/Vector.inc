{$IFDEF METHODS}
function Asco: Integer; overload;
function Ascount: Integer; overload;
function Ascounted: Integer; overload;
function Ascounting: Integer; overload;
function Desco: Integer; overload;
function Descount: Integer; overload;
function Descounted: Integer; overload;
function Descounting: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Asco>
  @action: Returns the inclusive count for the descending range orientation.
  @note: Logic: (Delta + 1). Optimized via (Delta - not 0).
[==============================================================================}
function TRange.Asco: Integer; overload;
begin
  Result := (Self.Delta - not 0);
end;

{==============================================================================]
  <Ascount>
  @action: Returns the Ascending Count (inclusive size) of the range.
  @note: Logic: ((Stop - Start) * 1) + 1.
[==============================================================================}
function TRange.Ascount: Integer; overload;
begin
  Result := Self.Sizection(1);
end;

{==============================================================================]
  <Ascounted>
  @action: Returns the Ascending Count (inclusive size) of the range.
  @note: Logic: ((Stop - Start) * 1) + 1.
[==============================================================================}
function TRange.Ascounted: Integer; overload;
begin
  Result := (Self.Delta + 1);
end;

{==============================================================================]
  <Ascounting>
  @action: Returns the strict ascending count of elements in the range.
  @note: Logic: Max(0, Delta + 1). 
         Ensures a non-negative result based on forward traversal distance.
[==============================================================================}
function TRange.Ascounting: Integer; overload;
begin
  Result := Max(0, (Self.Delta + 1));
end;

{==============================================================================]
  <Desco>
  @action: Returns the inclusive count for the ascending range orientation.
  @note: Logic: (Contra + 1). Optimized via (Contra - not 0).
[==============================================================================}
function TRange.Desco: Integer; overload;
begin
  Result := (Self.Contra - not 0);
end;

{==============================================================================]
  <Descount>
  @action: Returns the Descending Count (inclusive size) of the range.
  @note: Logic: ((Stop - Start) * -1) + 1. Effectively (Start - Stop) + 1.
[==============================================================================}
function TRange.Descount: Integer; overload;
begin
  Result := Self.Sizection(-1);
end;

{==============================================================================]
  <Descounted>
  @action: Returns the Ascending Count (inclusive size) of the range.
  @note: Logic: ((Stop - Start) * 1) + 1.
[==============================================================================}
function TRange.Descounted: Integer; overload;
begin
  Result := (Self.Contra + 1);
end;

{==============================================================================]
  <Descounting>
  @action: Returns the strict descending count of elements in the range.
  @note: Logic: Max(0, Contra + 1). 
         Calculates the size as if the range orientation were reversed.
[==============================================================================}
function TRange.Descounting: Integer;
begin
  Result := Max(0, (Self.Contra + 1));
end;
{$ENDIF}
