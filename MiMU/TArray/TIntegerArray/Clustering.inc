{$IFDEF HELPERS}
function Split(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Split(const diff: Integer): T2DIntegerArray; overload;
function Sblit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Sblit(const diff: Integer): T2DIntegerArray; overload;
function Groups(const aSorted: Boolean = False): T2DIntegerArray; overload;
function Group(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Group(const diff: Integer): T2DIntegerArray; overload;
function Groub(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Groub(const diff: Integer): T2DIntegerArray; overload;
function Clique(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Clique(const diff: Integer): T2DIntegerArray; overload;
function Knit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
function Knit(const diff: Integer): T2DIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Split>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) from each other.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Split(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a, b, h, l, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  r := 0;
  h := High(Self);
  if (h > -1) then
  begin
    SetLength(Result, (h + 1));
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (h > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to h do
      begin
        m := False;
        for a := 0 to (r - 1) do
        begin
          l := Result[a].Length;
          for b := 0 to (l - 1) do
	  begin
	    m := ((Self[i] = Result[a][b]) or s.Value(Abs(Self[i] - Result[a][b])));
	    if not m then
              Continue;
	    SetLength(Result[a], (l + 1));
            Result[a][l] := Self[i];
            Break;
          end;
	  if m then
	    Break;
        end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Split>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff) from each other.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Split(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Split(0, diff);
end;

{==============================================================================]
  <Sblit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) from each other.
  @note: Alternative for TIntegerArray_Split. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Sblit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a: TIntegerArray;
  i, j, r, l, k: Integer;
  m: Boolean;
  s: TRange;
begin
  if Self.Exists then
  begin
    a := Self.BinarySorted;
    SetLength(Result, a.Size);
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        l := Result[j].Length;
        for k := 0 to (l - 1) do
        begin
          m := ((a[i] = Result[j][k]) or s.Value(Abs(a[i] - Result[j][k])));
          if not m then
            Continue;
          SetLength(Result[j], (l + 1));
          Result[j][l] := a[i];
          Break;
        end;
	if m then
	  Break;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
    SetLength(a, 0);
  end else
    r := 0;
  SetLength(Result, r);
end;

{==============================================================================]
  <Sblit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff) from each other.
  @note: Alternative for TIntegerArray_Split. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Sblit(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Sblit(0, diff);
end;

{==============================================================================]
  <Groups>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the ones with same values.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Groups(const aSorted: Boolean = False): T2DIntegerArray; overload;
var
  i, l, g: Integer;
  a: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  if not aSorted then
    a := Self.QuickSorted
  else
    a := Self.Copy;
  a.BinaryPrune;
  SetLength(Result, 0);
  SetLength(Result, a.Size);
  for i := 0 to High(Self) do
  begin
    g := a.BinarySearch(Self[i]);
    l := Result[g].Length;
    SetLength(Result[g], (l + 1));
    Result[g][l] := Self[i];
  end;
end;

{==============================================================================]
  <Group>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) of the first integer value in the sub-array.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Group(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a, h, l, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  r := 0;
  h := High(Self);
  if (h > -1) then
  begin
    SetLength(Result, (h + 1));
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (h > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to h do
      begin
        m := False;
        for a := 0 to (r - 1) do
          if ((Self[i] = Result[a][0]) or s.Value(Abs(Self[i] - Result[a][0]))) then
          begin
            m := True;
            l := Result[a].Length;
            SetLength(Result[a], (l + 1));
            Result[a][l] := Self[i];
            Break;
          end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Group>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
           that are within a given difference/distance (diff) of the first integer value in the sub-array.
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Group(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Group(0, diff);
end;

{==============================================================================]
  <Groub>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff) of the first integer value in the sub-array.
  @note: Alternative for TIntegerArray_Group, based on array Binary Sorting.
[==============================================================================}
function TIntegerArrayHelper.Groub(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a: TIntegerArray;
  i, j, r, l: Integer;
  s: TRange;
  m: Boolean;
begin
  if Self.Exists then
  begin
    a := Self.BinarySorted;
    SetLength(Result, Self.Size);
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        if ((a[i] = Result[j][0]) or s.Value(Abs(a[i] - Result[j][0]))) then
        begin
          l := Result[j].Length;
          SetLength(Result[j], (l + 1));
          Result[j][l] := a[i];
          m := True;
          Break;
        end;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
  end else
    r := 0;
  SetLength(Result, r);
end;

{==============================================================================]
  <Groub>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
           that are within a given difference/distance (diff) of the first integer value in the sub-array.
  @note: Alternative for TIntegerArray_Group, based on array Binary Sorting.
[==============================================================================}
function TIntegerArrayHelper.Groub(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Groub(0, diff);
end;

{==============================================================================]
  <Clique>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff).
  @note: Strict splitting!
[==============================================================================}
function TIntegerArrayHelper.Clique(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a, b, h, l, i, r: Integer;
  m: Boolean;
  s: TRange;
begin
  r := 0;
  h := High(Self);
  if (h > -1) then
  begin
    SetLength(Result, (h + 1));
    SetLength(Result[0], 1);
    Result[0][0] := Self[0];
    if (h > 0) then
    begin
      r := 1;
      s.Build(minDiff, maxDiff);
      for i := 1 to h do
      begin
        m := False;
        for a := 0 to (r - 1) do
        begin
          l := Result[a].Length;
          m := True;
          for b := 0 to (l - 1) do
            if ((Self[i] = Result[a][b]) or (not m)) then
              Break
            else
              m := s.Value(Abs(Self[i] - Result[a][b]));
          if m then
          begin
            SetLength(Result[a], (l + 1));
            Result[a][l] := Self[i];
            Break;
          end;
        end;
        if not m then
          Result[r.Increase] := [Self[i]];
      end;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Clique>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff).
  @note: None
[==============================================================================}
function TIntegerArrayHelper.Clique(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Clique(0, diff);
end;

{==============================================================================]
  <Knit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference range (minDiff, maxDiff).
  @note: Alternative for TIntegerArray_Clique. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Knit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload;
var
  a: TIntegerArray;
  i, j, r, l, k: Integer;
  m: Boolean;
  s: TRange;
begin
  if Self.Exists then
  begin
    a := Self.BinarySorted;
    SetLength(Result, a.Size);
    SetLength(Result[0], 1);
    Result[0][0] := a[0];
    r := 1;
    s.Build(minDiff, maxDiff);
    for i := 1 to High(Self) do
    begin
      m := False;
      for j := 0 to (r - 1) do
      begin
        m := True;
        l := Result[j].Length;
        for k := 0 to (l - 1) do
          if ((a[i] = Result[j][k]) or (not m)) then
            Break
          else
            m := s.Value(Abs(a[i] - Result[j][k]));
        if m then
        begin
          SetLength(Result[j], (l + 1));
          Result[j][l] := a[i];
          Break;
        end;
      end;
      if not m then
        Result[r.Increase] := [a[i]];
    end;
    SetLength(a, 0);
  end else
    r := 0;
  SetLength(Result, r);
end;

{==============================================================================]
  <Knit>
  @action: Splits given TIntArray (arr) into T2DIntArray by grouping together the integer values
          that are within a given difference/distance (diff).
  @note: Alternative for TIntegerArray_Clique. Based on Binary Sorted array.
[==============================================================================}
function TIntegerArrayHelper.Knit(const diff: Integer): T2DIntegerArray; overload;
begin
  Result := Self.Knit(0, diff);
end;
{$ENDIF}
