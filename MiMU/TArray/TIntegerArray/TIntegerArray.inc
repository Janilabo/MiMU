{$DEFINE Integer}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
{$I CIntegerArray.inc}
{$I XIntegerArray.inc}
{$ENDIF}

{$IFDEF HELPERS}
TIntegerArrayHelper = type helper for TIntegerArray
  {$I TIntegerArray.pph}
  class function Identity(const N: Integer = 1): TIntegerArray; overload; static;
  function Numberline: TIntegerArray;
  function Reinit: Integer; overload;
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I CIntegerArray.inc}
{$I TIntegerArray.pph}
{$I XIntegerArray.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Identity>
  @action: Creates a TIntegerArray of length N where each element equals its own index.
  @note: Suitable as the initial state for a disjoint-set parent array.
[==============================================================================}
class function TIntegerArrayHelper.Identity(const N: Integer = 1): TIntegerArray; overload; static;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Max(0, N)) do
    Result[i] := i;
end;

{==============================================================================]
  <Numberline>
  @action: Returns numberline of array arr.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Numberline: TIntegerArray;
var
  i, x, y: Integer;
  r: TRange;
begin
  y := High(Self);
  case y.Compare(0) of
    1:
    begin
      r.Create(Self[0], Self[0]);
      for x := 1 to y do
        if (Self[x] < r.start) then
          r.start := Self[x]
        else if (Self[x] > r.stop) then
          r.stop := Self[x];
      if (r.start <> r.stop) then
      begin
        SetLength(Result, r.Size);
        for i := r.start to r.stop do
          Result[i - r.start] := i;
      end else
        Result.Create(r.start);
    end;
    0: Result.Create(Self[0]);
    -1: SetLength(Result, 0);
  end;
end;

{==============================================================================]
  <Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Reinit: Integer; overload;
begin
  Result := Self.Size;
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Integer)), 0);
end;
{$ENDIF}

{$UNDEF Integer}
