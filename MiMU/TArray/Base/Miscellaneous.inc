{$IFDEF HELPERS}
function Domain: TRange; overload;
function Pad(const N: Integer = 0): Integer; overload;
function Padded(const N: Integer = 0): MArray; overload;
function Sample(const sSize: Integer): MArray; overload;
function Zigzag(const zAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Domain>
  @action: Returns the valid index range of the array.
  @note:
    - If the array is empty, start and stop are set to -1.
    - Otherwise, start = 0 and stop = Length(Self) - 1.
[==============================================================================}
function MArrayHelper.Domain: TRange; overload;
begin
  Result.stop := (Self.Size - 1);
  if (Result.stop = -1) then
    Result.start := -1
  else
    Result.start := 0;
end;

{==============================================================================]
  <Pad>
  @action: Expands the array in-place by the absolute value of N elements,
           filling the newly created slots with default values. Returns the
           new length of the array.
  @note: If N is positive, default elements are appended to the right (end).
         If N is negative, default elements are prepended to the left (beginning),
         shifting the original elements to the right.
[==============================================================================}
function MArrayHelper.Pad(const N: Integer = 0): Integer; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (N = 0) then
    Exit(l);
  case (N < 0) of
    True:
    begin
      Result := Self.SetSize(l + -N);
	  for i := (l - 1) downto 0 do
        Self[i + -N] := Self[i];
      for i := 0 to (-N - 1) do
        Self[i] := Default(MType);
    end;
    False:
    begin
      Result := Self.SetSize(l + N);
      for i := 0 to (N - 1) do
        Self[i + l] := Default(MType);
    end;
  end;
end;

{==============================================================================]
  <Padded>
  @action: Creates a new array expanded by the absolute value of N elements, 
           filling the newly created slots with default values.
  @note: If N is positive, default elements are appended to the right (end). 
         If N is negative, default elements are prepended to the left (beginning), 
         shifting the original elements to the right.
[==============================================================================}
function MArrayHelper.Padded(const N: Integer = 0): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  case (N < 0) of
    True:
    begin
      SetLength(Result, (l + -N));
      for i := 0 to (-N - 1) do
        Result[i] := Default(MType);
      for i := 0 to (l - 1) do
        Result[i + -N] := Self[i];
    end;
    False:
    begin
      SetLength(Result, (l + N));
      for i := 0 to (l - 1) do
        Result[i] := Self[i];
      for i := 0 to (N - 1) do
        Result[i + l] := Default(MType);
    end;
  end;
end;

{==============================================================================]
  <Sample>
  @action: Returns sample from array by sSize.
  @note: None.
[==============================================================================}
function MArrayHelper.Sample(const sSize: Integer): MArray; overload;
var
  i: Integer;
  r: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  r := Self.Domain.Sample(sSize);
  SetLength(Result, r.Size);
  for i := 0 to High(Result) do
    Result[i] := Self[r[i]];
end;

{==============================================================================]
  <Zigzag>
  @action: Creates a new array whose elements are taken alternately from the
           start and end of the source array, producing an outside-in “zigzag” order.
  @note: For odd-length arrays, the middle element appears last.
[==============================================================================}
function MArrayHelper.Zigzag(const zAscending: Boolean = True): MArray; overload;
var
  l, r: Integer;
  s: TRange;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, l);
  r := 0;
  s.Create(0, (l - 1));
  case zAscending of
    True:
    repeat
      Result[r.Increase] := Self[s.start];
      Result[r.Increase] := Self[s.stop];
    until (s.start.Increment >= s.stop.Decrement);
    False:
    repeat
      Result[r.Increase] := Self[s.stop];
      Result[r.Increase] := Self[s.start];
    until (s.start.Increment >= s.stop.Decrement);
  end;
  if (s.start = s.stop) then
    Result[r] := Self[s.stop];
end;
{$ENDIF}