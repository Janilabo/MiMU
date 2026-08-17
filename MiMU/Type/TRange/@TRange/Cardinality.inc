{$IFDEF METHODS}
function Ascally: Integer; overload;
function Asco: Integer; overload;
function Ascount: Integer; overload;
function Ascounted: Integer; overload;
function Ascounting: Integer; overload;
function Ascize: Integer; overload;
function Asquant: Integer; overload;
function Asquantify: Integer; overload;
function Descally: Integer; overload;
function Desco: Integer; overload;
function Descount: Integer; overload;
function Descounted: Integer; overload;
function Descounting: Integer; overload;
function Descize: Integer; overload;
function Desquant: Integer; overload;
function Desquantify: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascally>
  @action: Returns the inclusive count for the ascending range orientation,
           guarded by validity.
  @note: Logic: if Asceal then Size else 0. Unlike Ascounted/Ascize, this
         does not assume the range is validly oriented — it checks Asceal
         first and returns 0 for a non-ascending or invalid range, rather
         than an arithmetic result that may be meaningless or negative.
[==============================================================================}
function TRange.Ascally: Integer; overload;
begin
  if Self.Asceal then
    Result := Self.Size
  else
    Result := 0;
end;

{==============================================================================]
  <Asco>
  @action: Returns the inclusive count for the ascending range orientation.
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
  <Ascize>
  @action: Returns the inclusive count for the ascending range orientation.
  @note: Logic: (Stop - Start) + 1. Computed directly from start/stop rather
         than via the Delta property, unlike Ascounted.
[==============================================================================}
function TRange.Ascize: Integer; overload;
begin
  Result := ((Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Asquant>
  @action: Returns the inclusive count for the ascending range orientation.
  @note: Logic: -(-(Delta) - 1), algebraically equivalent to (Delta + 1) but
         computed via double negation rather than direct addition.
[==============================================================================}
function TRange.Asquant: Integer; overload;
begin
  Result := -(-(Self.Delta) - 1);
end;

{==============================================================================]
  <Asquantify>
  @action: Returns the inclusive count for the ascending range orientation.
  @note: Logic: (Stop + 1) - Start. The +1 is applied to Stop before the
         subtraction rather than to the difference afterward, distinct in
         evaluation order from Ascize/Ascounted.
[==============================================================================}
function TRange.Asquantify: Integer; overload;
begin
  Result := ((Self.stop + 1) - Self.start);
end;

{==============================================================================]
  <Descally>
  @action: Returns the inclusive count for the descending range orientation,
           guarded by validity.
  @note: Mirrors Ascally's guarded-validity contract for the descending case.
[==============================================================================}
function TRange.Descally: Integer; overload;
begin
  if Self.Desceal then
    Result := Self.Size
  else
    Result := 0;
end;

{==============================================================================]
  <Desco>
  @action: Returns the inclusive count for the descending range orientation.
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
  @action: Returns the Descending Count (inclusive size) of the range.
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
function TRange.Descounting: Integer; overload;
begin
  Result := Max(0, (Self.Contra + 1));
end;

{==============================================================================]
  <Descize>
  @action: Returns the inclusive count for the descending range orientation.
  @note: Logic: (Start - Stop) + 1. Computed directly from start/stop rather
         than via the Contra property, unlike Descounted.
[==============================================================================}
function TRange.Descize: Integer; overload;
begin
  Result := ((Self.start - Self.stop) + 1);
end;

{==============================================================================]
  <Desquant>
  @action: Returns the inclusive count for the descending range orientation.
  @note: Logic: -(-(Contra) - 1), algebraically equivalent to (Contra + 1)
         but computed via double negation rather than direct addition.
[==============================================================================}
function TRange.Desquant: Integer; overload;
begin
  Result := -(-(Self.Contra) - 1);
end;

{==============================================================================]
  <Desquantify>
  @action: Returns the inclusive count for the descending range orientation.
  @note: Logic: (Start + 1) - Stop. The +1 is applied to Start before the
         subtraction rather than to the difference afterward, distinct in
         evaluation order from Descize/Descounted.
[==============================================================================}
function TRange.Desquantify: Integer; overload;
begin
  Result := ((Self.start + 1) - Self.stop);
end;
{$ENDIF}
