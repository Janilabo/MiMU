{$IFDEF HELPERS}
function Rand: Integer; overload;
function Rand0m: Integer; overload;
function Randed: Integer; overload;
function RandomRange: Integer; overload;
function Randomsy: Integer; overload;
function Randsy: Integer; overload;
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
  <Rand0m>
  @action: Generates a random integer between 0 and Self (inclusive) using a binomial distribution loop.
  @note: Unlike a uniform distribution where every number has an equal chance, this method heavily 
         favors values close to the middle of the range (Self / 2) due to the Central Limit Theorem.
[==============================================================================}
function TIntegerHelper.Rand0m: Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  case Sign(Self) of
    1:
    for i := 0 to (Self - 1) do
      Result := (Result + Integer(RandomBool));
    -1:
    for i := (Self + 1) to 0 do
      Result := (Result - Integer(RandomBool));
  end;
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

{==============================================================================]
  <Randomsy>
  @action: Generates a uniform random integer between 0 and Self (inclusive).
  @note: Bypasses 32-bit Random() limits and handles all overflow edge cases
         like Low(Integer) and High(Integer) flawlessly.
[==============================================================================}
function TIntegerHelper.Randomsy: Integer; overload;
var
  a, r: Int64;
begin
  if (Self = 0) then
    Exit(0);
  a := Abs(Self);
  r := Trunc(Random * (a + 1));
  if (r > a) then
    r := a;
  if (Self > 0) then
    Result := Integer(r)
  else
    Result := Integer(-r);
end;

{==============================================================================]
  <Randsy>
  @action: Generates a lightweight, uniform random integer between 0 and Self (inclusive).
  @note: Uses fast 32-bit native branching. Note that this version can throw 
         overflow errors if Self is exactly High(Integer) or Low(Integer).
[==============================================================================}
function TIntegerHelper.Randsy: Integer; overload;
begin
  case Sign(Self) of
    0: Result := 0;
    1: Result := Random(Self + 1);
    -1: Result := -Random(Abs(Self) + 1);
  end;
end;
{$ENDIF}
