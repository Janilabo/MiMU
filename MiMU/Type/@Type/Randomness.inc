{$IFDEF FUNCTIONS}
function RandOf(const A, B: MType): MType; overload;
function RandOf(const A, B, C: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <RandOf>
  @action: Returns A or B at random, each with an equal 1/2 chance.
  @note: Uses the global RNG, so results follow Randomize/RandSeed. Both
         arguments are evaluated before the call; the unchosen one is
         discarded. Equal arguments simply raise the odds of that value.
[==============================================================================}
function RandOf(const A, B: MType): MType; overload;
begin
  if (Random(2) = 0) then
    Result := A
  else
    Result := B;
end;

{==============================================================================]
  <RandOf>
  @action: Returns A, B or C at random, each with an equal 1/3 chance.
  @note: Uses the global RNG, so results follow Randomize/RandSeed. All
         arguments are evaluated before the call; the unchosen ones are
         discarded. Equal arguments simply raise the odds of that value.
[==============================================================================}
function RandOf(const A, B, C: MType): MType; overload;
begin
  case Random(3) of
    0: Result := A;
    1: Result := B;
    2: Result := C;
  end;
end;
{$ENDIF}
