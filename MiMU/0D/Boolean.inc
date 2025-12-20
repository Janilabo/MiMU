{$DEFINE MType := Boolean}
{$DEFINE MArray := TBooleanArray}
{$DEFINE M2DArray := T2DBooleanArray}
{$DEFINE MCompare := TBooleanCompare}
{$DEFINE MHelper := TBooleanHelper}
{$UNDEF Sortable}

{$IFDEF TYPES}
{$I Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TBooleanHelper = type helper for Boolean
  {$I Core.inc}
  {$I Boolean\Convert.inc}
  {$I Boolean\Operation.inc}
  function Shuffle: Boolean;
  {$I Boolean\Select.inc}
  {$I Boolean\State.inc}
end;
{$ENDIF}

{$IFDEF METHODS}
{$I Boolean\Convert.inc}
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I Core.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}

{==============================================================================]
  <Shuffle>
  @action: Randomizes Self and then returns it.
  @note: None
[==============================================================================}
function TBooleanHelper.Shuffle: Boolean; 
begin
  Self := (Random(2) = 0);
  Result := Self;
end;

{$I Boolean\Operation.inc}
{$I Boolean\Select.inc}
{$I Boolean\State.inc}
{$I Boolean\Convert.inc}
{$ENDIF}