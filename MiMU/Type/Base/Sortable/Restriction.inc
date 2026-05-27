{$IFDEF HELPERS}
function Cap(const sMinimum, sMaximum: MType): Boolean; overload;
function CapMax(const sMaximum: MType): Boolean; overload;
function CapMin(const sMinimum: MType): Boolean; overload;
function Capped(const sMinimum, sMaximum: MType): MType; overload;
function CappedMax(const sMaximum: MType): MType; overload;
function CappedMin(const sMinimum: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cap>
  @action: Constrains the instance item within a specified minimum and maximum range, modifying the value in-place.
  @note: Returns True if the value was altered to fit within the boundaries, or False if no changes were made.
[==============================================================================}
function MTypeHelper.Cap(const sMinimum, sMaximum: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  if (Self < sMinimum) then
    Self := sMinimum
  else if (Self > sMaximum) then
    Self := sMaximum;
  Result := (s <> Self);
end;

{==============================================================================]
  <CapMax>
  @action: Constrains the instance item within a specified maximum range, modifying the value in-place.
  @note: Returns True if the value was altered to fit within the boundaries, or False if no changes were made.
[==============================================================================}
function MTypeHelper.CapMax(const sMaximum: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  if (Self > sMaximum) then
    Self := sMaximum;
  Result := (s <> Self);
end;

{==============================================================================]
  <CapMin>
  @action: Constrains the instance item within a specified minimum range, modifying the value in-place.
  @note: Returns True if the value was altered to fit within the boundaries, or False if no changes were made.
[==============================================================================}
function MTypeHelper.CapMin(const sMinimum: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  if (Self < sMinimum) then
    Self := sMinimum;
  Result := (s <> Self);
end;

{==============================================================================]
  <Capped>
  @action: Returns a copy of the item constrained within a specified minimum and maximum range.
  @note: Returns the minimum boundary if Self is lower, or the maximum if Self is higher.
[==============================================================================}
function MTypeHelper.Capped(const sMinimum, sMaximum: MType): MType; overload;
begin
  if (Self < sMinimum) then
    Exit(sMinimum);
  if (Self > sMaximum) then
    Exit(sMaximum);
  Result := Self;
end;

{==============================================================================]
  <CappedMax>
  @action: Returns a copy of the item constrained within a specified maximum range.
  @note: Returns the minimum boundary if Self is lower, or the maximum if Self is higher.
[==============================================================================}
function MTypeHelper.CappedMax(const sMaximum: MType): MType; overload;
begin
  if (Self > sMaximum) then
    Exit(sMaximum);
  Result := Self;
end;

{==============================================================================]
  <CappedMin>
  @action: Returns a copy of the item constrained within a specified minimum range.
  @note: Returns the minimum boundary if Self is lower, or the maximum if Self is higher.
[==============================================================================}
function MTypeHelper.CappedMin(const sMinimum: MType): MType; overload;
begin
  if (Self < sMinimum) then
    Exit(sMinimum);
  Result := Self;
end;
{$ENDIF}
