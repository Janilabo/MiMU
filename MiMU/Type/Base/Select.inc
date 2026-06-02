{$IFDEF HELPERS}
function When(const condition: Boolean; const fallback: MType): MType; overload;
function Unless(const condition: Boolean; const fallback: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <When>
  @action: Returns Self if the condition is met (True), otherwise returns 
           the specified fallback value.
  @note: Streamlines inline fluent conditional evaluations, replacing clunky 
         ternary simulations or verbose if/then blocks.
[==============================================================================}
function MTypeHelper.When(const condition: Boolean; const fallback: MType): MType; overload;
begin
  if condition then 
    Result := Self 
  else 
    Result := fallback;
end;

{==============================================================================]
  <Unless>
  @action: Returns Self unless the condition prevents it (True), in which 
           case it returns the specified fallback value (fallback).
  @note: Pairs perfectly with 'When' to evaluate negative assertions without 
         forcing the developer to clutter expressions with 'not' operators.
[==============================================================================}
function MTypeHelper.Unless(const condition: Boolean; const fallback: MType): MType; overload;
begin
  if not condition then 
    Result := Self 
  else
    Result := fallback;
end;
{$ENDIF}
