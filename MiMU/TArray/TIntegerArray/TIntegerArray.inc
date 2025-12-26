{$DEFINE Integer}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TIA = class
public
  class function Init(var arr: TIntegerArray): Integer; overload; 
  class function Reverse(var arr: TIntegerArray): Boolean; overload; 
  class function Reversed(const arr: TIntegerArray): TIntegerArray; overload; 
  class function Unique(var arr: TIntegerArray): Integer; overload; 
  class function Combine(const A, B: TIntegerArray): TIntegerArray; overload;
end;
{$ENDIF}

{$IFDEF HELPERS}
TIntegerArrayHelper = type helper for TIntegerArray
  {$I ../TArray.inc}
  {$I TIntegerArray.pph}
  function Numberline: TIntegerArray;
  function Reinit: Integer; overload;
  function Attach(const items: TIntegerArray): Integer; overload;
  function Embed(const items: TIntegerArray; const index: Integer = 2147483647): Integer; overload; 
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../TArray.inc}
{$I TIntegerArray.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
        else
          if (Self[x] > r.stop) then
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

{==============================================================================]
  <Attach>
  @action: Appends all points from the given array to the end of Self.
           Returns the new total length of the array after appending.
  @note:   Uses Move() for efficiency since Integer is an unmanaged type.
           If the input array is empty, the function returns the current length
           of Self without modification.
[==============================================================================}
function TIntegerArrayHelper.Attach(const items: TIntegerArray): Integer; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  i := items.Size;
  if (i = 0) then
    Exit(l);
  Result := (l + i);
  SetLength(Self, Result);
  Move(items[0], Self[l], (i * SizeOf(Integer)));
end;

{==============================================================================]
  <Embed>
  @action: Inserts the contents of another integer array into the current array
           at the specified index. Existing elements from that position onward
           are shifted to make room for the new items.
  @note: If the index exceeds the current length, the items are appended.
         Passing an empty array leaves the original array unchanged.
         The function returns the new total element count.
[==============================================================================}
function TIntegerArrayHelper.Embed(const items: TIntegerArray; const index: Integer = 2147483647): Integer; overload;
var
  s, l, p, t: Integer;
begin
  s := Self.Size;
  l := items.Length;
  if (l = 0) then
    Exit(s);
  p := EnsureRange(index, 0, s);
  t := (s - p);
  SetLength(Self, (s + l));
  if (t > 0) then
    Move(Self[p], Self[p + l], (t * SizeOf(Integer)));
  Move(items[0], Self[p], (l * SizeOf(Integer)));
  Result := Self.Size;
end;

class function TIA.Init(var arr: TIntegerArray): Integer; overload; 
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], (Result * SizeOf(Integer)), 0);
end;

class function TIA.Unique(var arr: TIntegerArray): Integer; overload; 
var
  x, y, z: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  y := High(arr);
  if (y > 0) then
  begin
    z := 0;
    r := arr.Bounds;
    b.Create(r.Size, False);
    for x := 0 to y do
      if b[arr[x] - r.start].Enable then
        arr[z.Increase] := arr[x];
    SetLength(b, 0);
    SetLength(arr, z);
    Result := ((y + 1) - z);
  end else
    Result := 0;
end;

class function TIA.Reverse(var arr: TIntegerArray): Boolean; overload; 
var
  a: TIntegerArray;
  i: Integer;
begin
  Result := (Length(arr) > 1);
  if not Result then
    Exit;
  SetLength(a, Length(arr));
  for i := 0 to High(arr) do
    a[i] := arr[High(arr) - i];
  Move(a[0], arr[0], (Length(arr) * SizeOf(Integer)));
end;

class function TIA.Reversed(const arr: TIntegerArray): TIntegerArray; overload; 
var
  i, r: Integer;
begin
  SetLength(Result, Length(arr));
  if (Length(arr) = 0) then
    Exit;
  Move(arr[0], Result[0], (Length(arr) * SizeOf(Integer)));
  for i := 0 to (High(Result) div 2) do
  begin
    r := Result[i];
    Move(Result[High(Result) - i], Result[i], SizeOf(Integer));
    Move(r, Result[High(Result) - i], SizeOf(Integer));
  end;
end;

class function TIA.Combine(const A, B: TIntegerArray): TIntegerArray; overload; 
var
  x, y: Integer;
begin
  x := Length(A);
  y := Length(B);
  SetLength(Result, (x + y));
  if (x > 0) then
    Move(A[0], Result[0], (x * SizeOf(Integer)));
  if (y > 0) then
    Move(B[0], Result[x], (y * SizeOf(Integer)));
end;
{$ENDIF}

{$UNDEF BASE}{$UNDEF Integer}
