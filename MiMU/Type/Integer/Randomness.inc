{$IFDEF HELPERS}
function Rand: Integer; overload;
function Randed: Integer; overload;
function RandomRange: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Rand>
  @action: Random() with support for negative Range (based on x value).
  @note: None
[==============================================================================}
function TIntegerHelper.Rand: Integer; overload;
begin
  Result := Random(Abs(Self));
  if (Self < 0) then
    Result := (Result * -1);
end;

{==============================================================================]
  <Randed>
  @action: Generates a random integer between 0 and the current integer value, inclusive of both bounds.
  @note: Overloaded function. Explicitly preserves the sign and handles zero without throwing an error.
[==============================================================================}
function TIntegerHelper.Randed: Integer; overload;
begin
  if (Self = 0) then
    Result := 0
  else if (Self > 0) then
    Result := Random(Self + 1)
  else
    Result := -Random(Abs(Self) + 1);
end;

{==============================================================================]
  <RandomRange>
  @action: Generates a random integer between 0 and the current integer value (inclusive of both bounds).
  @note: Overloaded function. Automatically orders the boundaries depending on whether the instance is positive or negative.
[==============================================================================}
function TIntegerHelper.RandomRange: Integer; overload;
begin
  if (Self < 0) then
    Result := Math.RandomRange(Self, 1)
  else
    Result := Math.RandomRange(0, (Self + 1));
end;
{$ENDIF}
