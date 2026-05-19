{$IFDEF HELPERS}
function Steppify(const sCount: Integer = 0): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Steppify>
  @action: Generates a contiguous arithmetic sequence array of integers starting
           from Self, moving by a length of sCount.
  @note: Automatically handles directional scaling. A positive sCount increments 
         forward, a negative sCount decrements backward, and 0 returns an array 
         containing only Self. Resulting array length is always Abs(sCount) + 1.
[==============================================================================}
function TIntegerHelper.Steppify(const sCount: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
begin
  case sCount.Compare(0) of
    0: Exit([Self]);
    -1:
    begin
      SetLength(Result, (-sCount + 1));
      for i := 0 to High(Result) do
        Result[i] := (Self - i);
    end;
    1:
    begin
      SetLength(Result, (sCount + 1));
      for i := 0 to High(Result) do
        Result[i] := (Self + i);
    end;
  end;
end;
{$ENDIF}