{$IFDEF HELPERS}
function Ascension(const target: Integer = 0): TIntegerArray; overload;
function Descension(const target: Integer = 0): TIntegerArray; overload;
function Downstairs(const target: Integer = 0): TIntegerArray; overload;
function Rebound(const target: Integer = 0): TIntegerArray; overload;
function Stairs(const target: Integer = 0): TIntegerArray; overload;
function Steppify(const sCount: Integer = 0): TIntegerArray; overload;
function Upstairs(const target: Integer = 0): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascension>
  @action: Generates an ascending sequence array of integers starting from Self 
           up to and including the target value.
  @note: If Self is greater than target, it exits early returning only [Self]. 
         Uses direct pointer arithmetic to populate the array sequentially in 
         memory for optimized performance.
[==============================================================================}
function TIntegerHelper.Ascension(const target: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
  P: PInteger;
begin
  if (Self > target) then
    Exit([Self]);
  SetLength(Result, ((target - Self) + 1));
  P := @Result[0];
  for i := 0 to High(Result) do
  begin
    P^ := (Self + i);
    Inc(P);
  end;
end;

{==============================================================================]
  <Descension>
  @action: Generates a descending sequence array of integers starting from Self 
           down to and including the target value.
  @note: If Self is less than target, it exits early returning only [Self]. 
         Uses direct pointer arithmetic to populate the array sequentially in 
         memory for optimized performance.
[==============================================================================}
function TIntegerHelper.Descension(const target: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
  P: PInteger;
begin
  if (Self < target) then
    Exit([Self]);
  SetLength(Result, ((Self - target) + 1));
  P := @Result[0];
  for i := 0 to High(Result) do
  begin
    P^ := (Self - i);
    Inc(P);
  end;
end;

{==============================================================================]
  <Downstairs>
  @action: Generates a descending sequence array of integers starting from Self
           down to and including the target value.
  @note: If Self is less than target, the loop bounds collapse and it returns
         an array containing only [Self].
[==============================================================================}
function TIntegerHelper.Downstairs(const target: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, (Max(0, (Self - target)) + 1));
  for i := 0 to High(Result) do
    Result[i] := (Self - i);
end;

{==============================================================================]
  <Rebound>
  @action: Returns an ascending then descending (or vice versa) sequence
           between Self and target, returning back to Self.
  @note: 5.Rebound(8) -> [5,6,7,8,7,6,5]
         8.Rebound(5) -> [8,7,6,5,6,7,8]
[==============================================================================}
function TIntegerHelper.Rebound(const target: Integer = 0): TIntegerArray; overload;
var
  s, t: TIntegerArray;
  d, i: Integer;
begin
  d := Abs(target - Self);
  t := Self.Stairs(target);
  s := target.Stairs(Self);
  SetLength(Result, ((d * 2) + 1));
  for i := 0 to d do
    Result[i] := t[i];
  for i := 1 to d do
    Result[d + i] := s[i];
end;

{==============================================================================]
  <Stairs>
  @action: Generates a continuous sequence array of integers starting from Self
           moving toward and including the target value.
  @note: Dynamically routes the direction. If Self is greater than target, it
         routes via Downstairs; otherwise, it routes via Upstairs. Unlike the
         directional methods, this will never collapse to a single-element
         array unless Self = target.
[==============================================================================}
function TIntegerHelper.Stairs(const target: Integer = 0): TIntegerArray; overload;
begin
  if (Self > target) then
    Result := Self.Downstairs(target)
  else
    Result := Self.Upstairs(target);
end;

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

{==============================================================================]
  <Upstairs>
  @action: Generates an ascending sequence array of integers starting from Self
           up to and including the target value.
  @note: If Self is greater than target, the loop bounds collapse and it returns
         an array containing only [Self].
[==============================================================================}
function TIntegerHelper.Upstairs(const target: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, (Max(0, (target - Self)) + 1));
  for i := 0 to High(Result) do
    Result[i] := (Self + i);
end;
{$ENDIF}
