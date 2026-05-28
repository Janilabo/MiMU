{$IFDEF HELPERS}
function Gated(const A, B: Integer): Boolean; overload;
function Resides(const A, B: Integer): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Gated>
  @action: Determines whether the current integer value falls within the 
           inclusive perimeter defined by checkpoints A and B.
  @note: Uses a sign-multiplying algebraic trick: (Self - A) * (Self - B) <= 0.
         This evaluates to True only when Self is between A and B (inclusive) 
         because one factor must be positive and the other negative (or zero).
         Naturally handles unordered checkpoints (A > B or A < B).
[==============================================================================}
function TIntegerHelper.Gated(const A, B: Integer): Boolean; overload;
begin
  Result := ((Self - A) * (Self - B) <= 0);
end;

{==============================================================================]
  <Resides>
  @action: Determines whether the current integer value lies within the 
           inclusive range defined by boundaries A and B.
  @note: Uses a single unsigned (Cardinal) comparison by shifting the entire 
         range down to 0, removing the need for separate lower and upper 
         bound checks. Automatically handles unordered bounds (A > B or A < B).
[==============================================================================}
function TIntegerHelper.Resides(const A, B: Integer): Boolean; overload;
var
  m: Integer;
begin
  m := Min(A, B);
  Result := (Cardinal(Self - m) <= Cardinal(Max(A, B) - m));
end;
{$ENDIF}
