{$IFDEF HELPERS}
function Reps(const N: Integer = 1): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Reps>
  @action: Generates an array of length N populated entirely with repetitions 
           of the Self integer value.
  @note: If N is less than 1, it exits early returning an empty array ([]). 
         Utilizes FillDWord for optimized, blazingly fast memory population 
         at the hardware/bit level.
[==============================================================================}
function TIntegerHelper.Reps(const N: Integer = 1): TIntegerArray; overload;
begin
  if (N < 1) then
    Exit([]);
  SetLength(Result, N);
  FillDWord(Result[0], Result.Length, DWord(Self));
end;
{$ENDIF}