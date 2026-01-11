{$IFDEF METHODS}
function All: TIntegerArray; overload;
function AsArray: TIntegerArray; overload;
function Digits: TIntegerArray; overload; 
function Digits(const dIndex: Integer): Integer; overload; 
function Digits(const dIDs: TIntegerArray): TIntegerArray; overload;
function Elements: TIntegerArray; 
function Enumerate: TIntegerArray;
function Enumerated: TIntegerArray;
function Extract: TIntegerArray; overload; 
function Extracted: TIntegerArray; overload;
function Ints: TIntegerArray; 
function Items: TIntegerArray;
function Materialize: TIntegerArray;
function Numbers: TIntegerArray;
function Recursed: TIntegerArray; overload;
function Sequence: TIntegerArray;
function Steps: TIntegerArray; overload;
function TIA: TIntegerArray;
function ToArray: TIntegerArray;
function Unfold: TIntegerArray; overload;
function Unpack: TIntegerArray; overload; 
function Unwrap: TIntegerArray; overload; 
function Unzip: TIntegerArray; overload;
function Values: TIntegerArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <All>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.All: TIntegerArray; overload;
var
  i, j: Integer;
  p: PInteger;
begin
  if (Self.start = Self.stop) then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  j := IfThen((Self.start <= Self.stop), 1, -1);
  p := PInteger(Result);
  i := Self.start;
  while (i <> (Self.stop + j)) do
  begin
    p^ := i;
    Inc(p);
    Inc(i, j);
  end;
end;

{==============================================================================]
  <AsArray>
  @action: Two-way alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.AsArray: TIntegerArray; overload;
var
  h, i, l: Integer;
begin
  if (Self.start = Self.stop) then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  h := High(Result);
  l := ((h + 1) div 2);
  i := 0;
  case Self.Ascending of
    True:
    repeat
      Result[i] := (Self.start + i);
      Result[h - i] := (Self.stop - i);
    until (i.Increment > l);
    False:
    repeat
      Result[i] := (Self.start - i);
      Result[h - i] := (Self.stop + i);
    until (i.Increment > l);
  end;
  if h.Even then
    Result[i] := IfThen(Self.Ascending, (Self.start + i), (Self.start - i));
end;

{==============================================================================]
  <Digits>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Digits: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Sign(Self.stop - Self.start);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (i * s));
end;

{==============================================================================]
  <Digits>
  @action: Returns digit from TRange by index.
  @note: None.
[==============================================================================}
function TRange.Digits(const dIndex: Integer): Integer; overload;
begin
  if ((dIndex < 0) or (dIndex >= Self.Area)) then
    Result := -2147483648
  else
    if Self.Ascending then
      Result := (Self.start + dIndex)
    else
      Result := (Self.start - dIndex);
end;

{==============================================================================]
  <Digits>
  @action: Returns digits from TRange by indexes.
  @note: None.
[==============================================================================}
function TRange.Digits(const dIDs: TIntegerArray): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, (High(dIDs) + 1));
  for i := 0 to High(dIDs) do
    Result[i] := Self.Digits(dIDs[i]);
end;

{==============================================================================]
  <Elements>
  Explanation: Returns TBox points as TPointArray.
  Example: Alternative method.
[==============================================================================}
function TRange.Elements: TIntegerArray;
var
  i: specialize TList<Integer>;
  e: Integer;
begin
  i := specialize TList<Integer>.Create;
  try
    case Self.Ascending of
      True:
      for e := Self.start to Self.stop do
        i.Add(e);
      False:
      for e := Self.start downto Self.stop do
        i.Add(e);
    end;
    Result := i.ToArray;
  finally
    i.Free;
  end;
end;

{==============================================================================]
  <Enumerate>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Enumerate: TIntegerArray;
var
  i: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  SetLength(Result, 0);
  case Self.Ascending of
    True:
    for i := Self.start to Self.stop do
      Result := (Result + [i]);
    False:
    for i := Self.start downto Self.stop do
      Result := (Result + [i]);
  end;
end;

{==============================================================================]
  <Enumerated>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Enumerated: TIntegerArray;
var
  n, i: Integer;
begin
  Result := Self.Reserve;
  i := 0;
  for n in Self do
    Result[i.Increase] := n;
end;

{==============================================================================]
  <Extract>
  @action: Extracts TRange as TIntegerArray. 
  @note: None.
[==============================================================================}
function TRange.Extract: TIntegerArray; overload;
var
  i, c, s: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  s := IfThen((Self.stop > Self.start), 1, -1);
  c := (Abs(Self.stop - Self.start) + 1);
  SetLength(Result, c);
  for i := 0 to (c - 1) do
    Result[i] := (Self.start + (i * s));
end;

{==============================================================================]
  <Extracted>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Extracted: TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := (Self.Start + i);
  if Self.Descending then
    Result.Reverse;
end;

{==============================================================================]
  <Ints>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Ints: TIntegerArray;
var
  i, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  case Self.Descending of
    True:
    for i := 0 to High(Result) do
      Result[(l - i) - 1] := (i + Self.stop);
    False:
    for i := 0 to High(Result) do
      Result[i] := (i + Self.start);
  end;
end;

{==============================================================================]
  <Items>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Items: TIntegerArray;
var
  i, s: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  s := IfThen(Self.Descending, -1, 1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (s * i));
end;

{==============================================================================]
  <Materialize>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Materialize: TIntegerArray;
var
  i, s, v: Integer;
  p: PInteger;
begin
  s := IfThen(Self.Ascending, 1, -1);
  SetLength(Result, Self.Size);
  v := Self.Start;
  p := @Result[0];
  for i := 0 to High(Result) do
  begin
    p^ := v.Increase(s);
    Inc(p);
  end;
end;

{==============================================================================]
  <Numbers>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Numbers: TIntegerArray;
var
  i, r, s: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  s := IfThen(Self.Descending, -1, 1);
  SetLength(Result, Self.Size);
  r := 0;
  i := Self.start;
  while (((s = 1) and (i <= Self.stop)) or ((s = -1) and (i >= Self.stop))) do
    Result[r.Increase] := i.Increase(s);
end;

{==============================================================================]
  <Recursed>
  @action: Returns digits of the given range.
  @note: Recursion-based.
[==============================================================================}
function TRange.Recursed: TIntegerArray; overload;
  function BR(const rStart, rStop: Integer): TIntegerArray;
  begin
    if (rStart = rStop) then
      Exit([rStart]);
    Result := BR(rStart, (rStop - Sign(rStop - rStart)));
    SetLength(Result, (Result.Size + 1));
    Result[High(Result)] := rStop;
  end;
begin
  Result := BR(Self.start, Self.stop);
end;

{==============================================================================]
  <Sequence>
  @action: Returns digits from TRange.
  @note: None.
[==============================================================================}
function TRange.Sequence: TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  case Self.Descending of
    False:
    for i := 0 to High(Result) do
      Result[i] := (Self.start + i);
    True:
    for i := 0 to High(Result) do
      Result[i] := (Self.start - i);
  end;
end;

{==============================================================================]
  <Steps>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Steps: TIntegerArray; overload;
var
  i, s: Integer;
  p: PInteger;
begin
  s := IfThen((Self.start < Self.stop), 1, -1);
  Result := Self.Reserve;
  p := @Result[0];
  p^ := Self.start;
  Inc(p);
  for i := 1 to High(Result) do
  begin
    p^ := ((p - 1)^ + s);
    Inc(p);
  end;
end;

{==============================================================================]
  <TIA>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.TIA: TIntegerArray;
var
  i, l, d: Integer;
begin
  l := Self.Capacity;
  SetLength(Result, l);
  if Self.Plural then
  begin
    d := Sign(Self.stop - Self.start);
    for i := 0 to ((l - 1) div 2) do
    begin
      Result[i] := (Self.start + (i * d));
      Result[(l - 1) - i] := (Self.stop - (i * d));
    end;
  end else
    Result[0] := Self.start;
end;

{==============================================================================]
  <ToArray>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.ToArray: TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  case Self.Descending of
    False:
    for i := Self.start to Self.stop do
      Result[i - Self.start] := i;
    True:
    for i := Self.start downto Self.stop do
      Result[Self.start - i] := i;
  end;
end;

{==============================================================================]
  <Unfold>
  @action: Recursion-based alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.Unfold: TIntegerArray; overload;
  procedure F2W(const R: TRange; const L, H: Integer; const A: Boolean; var arr: TIntegerArray);
  begin
    if (L > H) then
      Exit;
    case A of
      True:
      begin
        arr[L] := (R.start + L);
        arr[H] := (R.stop - L);
      end;
      False:
      begin
        arr[L] := (R.start - L);
        arr[H] := (R.stop + L);
      end;
    end;
    F2W(R, (L + 1), (H - 1), A, arr);
  end;
begin
  if (Self.start = Self.stop) then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  F2W(Self, 0, High(Result), Self.Ascending, Result);
end;

{==============================================================================]
  <Unpack>
  @action: Two-way alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.Unpack: TIntegerArray; overload;
var
  s, i: Integer;
  o: Boolean;
begin
  s := Self.Size;
  SetLength(Result, s);
  o := Self.Ascending;
  for i := 0 to (s - 1) do
    if (i < (s div 2)) then
      Result[i] := o.Select((Self.start + i), (Self.start - i))
    else
      Result[i] := o.Select((Self.stop - ((s - 1) - i)), (Self.stop + ((s - 1) - i)));
end;

{==============================================================================]
  <Unwrap>
  @action: Two-way alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.Unwrap: TIntegerArray; overload;
var
  s, h, i: Integer;
  a: Boolean;
begin
  s := Self.Size;
  SetLength(Result, s);
  h := ((s + 1) div 2);
  a := Self.Ascending;
  for i := 0 to (h - 1) do
  case a of
    True:
    begin
      Result[i] := (Self.start + i);
      Result[(s - 1) - i] := (Self.stop - i);
    end;
    False:
    begin
      Result[i] := (Self.start - i);
      Result[(s - 1) - i] := (Self.stop + i);
    end;
  end;
end;

{==============================================================================]
  <Unzip>
  @action: Two-way alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.Unzip: TIntegerArray; overload;
var
  r: TRange;
begin
  if (Self.start = Self.stop) then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  r.Create(0, High(Result));
  case Self.Ascending of
    True:
    repeat
      Result[r.start] := (Self.start + r.start);
      Result[r.stop] := (Self.stop - r.start);
    until (r.start.Increment > r.stop.Decrement);
    False:
    repeat
      Result[r.start] := (Self.start - r.start);
      Result[r.stop] := (Self.stop + r.start);
    until (r.start.Increment > r.stop.Decrement);
  end;
end;

{==============================================================================]
  <Values>
  @action: Returns values of the given range.
  @note: None.
[==============================================================================}
function TRange.Values: TIntegerArray;
var
  i, r: Integer;
begin
  r := 0;
  SetLength(Result, Self.Size);
  case Self.Ascending of
    False:
    for i := Self.start downto Self.stop do
      Result[r.Increase] := i;
    True:
    for i := Self.start to Self.stop do
      Result[r.Increase] := i;
  end;
end;
{$ENDIF}