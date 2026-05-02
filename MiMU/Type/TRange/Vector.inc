{$IFDEF METHODS}
function Ascount: Integer; overload;
function Ascounted: Integer; overload;
function Ascounting: Integer; overload;
function Descount: Integer; overload;
function Descounted: Integer; overload;
function Descounting: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
