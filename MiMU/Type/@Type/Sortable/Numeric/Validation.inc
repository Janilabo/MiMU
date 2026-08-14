{$IFDEF HELPERS}
function Gated(const A, B: MType): Boolean; overload;
function Resides(const A, B: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Gated>
  @action: Determines whether the current Self value falls within the
           inclusive perimeter defined by checkpoints A and B.
  @note: Uses a sign-multiplying algebraic trick: (Self - A) * (Self - B) <= 0.
         This evaluates to True only when Self is between A and B (inclusive)
         because one factor must be positive and the other negative (or zero).
         Naturally handles unordered checkpoints (A > B or A < B).
[==============================================================================}
function MTypeHelper.Gated(const A, B: MType): Boolean; overload;
begin
  Result := ((Self - A) * (Self - B) <= 0);
end;

{==============================================================================]
  <MTypeHelper>
  @action: Determines whether the current Self value lies within the 
           inclusive range defined by boundaries A and B.
  @note: Direct comparison against Min(A, B) and Max(A, B). Automatically 
         handles unordered bounds (A > B or A < B). Unlike the Integer 
         overload, no single-comparison trick applies to floating point.
[==============================================================================}
function MTypeHelper.Resides(const A, B: MType): Boolean; overload;
begin
  Result := ((Self >= Min(A, B)) and (Self <= Max(A, B)));
end;
{$ENDIF}
