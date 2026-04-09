{$IFDEF METHODS}
function Intro(const N: Integer = 1): TIntegerArray; overload;
function Outro(const N: Integer = 1): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Intro>
  @action: Returns the first N values of the range.
  @note: If N >= Size the full range is returned. N <= 0 returns empty array.
[==============================================================================}
function TRange.Intro(const N: Integer = 1): TIntegerArray; overload;
var
  i, d: Integer;
begin
  if (N < 1) then
    Exit([]);
  SetLength(Result, Min(N, Self.Size));
  d := IfThen(Self.Ascending, 1, -1);
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (i * d));
end;

{==============================================================================]
  <Outro>
  @action: Returns the last N values of the range.
  @note: If N >= Size the full range is returned. N <= 0 returns empty array.
[==============================================================================}
function TRange.Outro(const N: Integer = 1): TIntegerArray; overload;
var
  i, d, c: Integer;
begin
  if (N < 1) then
    Exit([]);
  c := Min(N, Self.Size);
  SetLength(Result, c);
  d := IfThen(Self.Ascending, 1, -1);
  for i := 0 to High(Result) do
    Result[i] := (Self.stop - ((c - 1 - i) * d));
end;
{$ENDIF}
