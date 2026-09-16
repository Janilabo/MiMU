{$IFDEF HELPERS}
function Diversified: MArray; overload;
function DiversifiedEx(const dAscending: Boolean = True): MArray; overload;
function Purified(const dAscending: Boolean = True): MArray; overload;
function Purify(const dAscending: Boolean = True): Integer; overload;
function Uncluttered: MArray; overload;
function Unduplicated: MArray; overload;
function Unified(const dAscending: Boolean = True): MArray; overload;
function Unify(const dAscending: Boolean = True): Integer; overload;
function Unik: MArray; overload;
function Uniqalize: Integer; overload;
function Uniqly: MArray; overload;
function Uniqual: MArray; overload;
function Uniqued: MArray; overload;
function Uniquify: MArray; overload;
function Uniqular: MArray; overload;
function Uniset: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Diversified>
  @action: Alternative for Unique methods
  @note: None.
[==============================================================================}
function MArrayHelper.Diversified: MArray; overload;
var
  d: specialize TDictionary<MType, Boolean>;
  i: Integer;
  k: MType;
begin
  d := specialize TDictionary<MType, Boolean>.Create;
  try
    for i := 0 to High(Self) do
      if not d.ContainsKey(Self[i]) then
        d.Add(Self[i], True);
    SetLength(Result, d.Count);
    i := 0;
    for k in d.Keys do
      Result[i.Increase] := k;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <DiversifiedEx>
  @action: Alternative for Unique methods
  @note: None.
[==============================================================================}
function MArrayHelper.DiversifiedEx(const dAscending: Boolean = True): MArray; overload;
var
  l: specialize TList<MType>;
  d: specialize TDictionary<MType, Boolean>;
  i: Integer;
begin
  l := specialize TList<MType>.Create;
  d := specialize TDictionary<MType, Boolean>.Create;
  try
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
      False:
      for i := High(Self) downto 0 do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
    end;
    Result := l.ToArray;
  finally
    d.Free;
    l.Free;
  end;
end;

{==============================================================================]
  <Purified>
  @action: Returns array with unique items
  @note: None.
[==============================================================================}
function MArrayHelper.Purified(const dAscending: Boolean = True): MArray; overload;
var
  d: specialize TDictionary<MType, Boolean>;
  l: specialize TList<MType>;
  i: Integer;
begin
  d := specialize TDictionary<MType, Boolean>.Create;
  l := specialize TList<MType>.Create;
  try
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
      False:
      for i := High(Self) downto 0 do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
    end;
    Result := l.ToArray;
  finally
    d.Free;
    l.Free;
  end;
end;

{==============================================================================]
  <Purify>
  @action: Removes duplicates
  @note: None
[==============================================================================}
function MArrayHelper.Purify(const dAscending: Boolean = True): Integer; overload;
var
  d: specialize TDictionary<MType, Boolean>;
  c: MArray;
  i: Integer;
begin
  d := specialize TDictionary<MType, Boolean>.Create;
  Result := 0;
  try
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
	      Self[Result.Increase] := Self[i];
        end;
      False:
      begin
        c := Self.Copy;
        for i := High(c) downto 0 do
          if not d.ContainsKey(c[i]) then
          begin
            d.Add(c[i], True);
	        Self[Result.Increase] := c[i];
          end;
      end;
    end;
  finally
    d.Free;
  end;
  SetLength(Self, Result);
end;

{==============================================================================]
  <Uncluttered>
  @action: Removes all duplicates from arr.
  @note: Returns the number of items that were removed.
[==============================================================================}
function MArrayHelper.Uncluttered: MArray; overload;
type
  TDict = specialize TDictionary<MType, Boolean>;
var
  d: TDict;
  r, i, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  d := TDict.Create;
  try
    SetLength(Result, l);
    r := 0;
    for i := 0 to (l - 1) do
      if not d.ContainsKey(Self[i]) then
      begin
        d.Add(Self[i], True);
        Result[r.Increase] := Self[i];
      end;
    if ((l - r) > 0) then
      SetLength(Result, r);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Unduplicated>
  @action: Removes all duplicates from arr.
  @note: Returns the number of items that were removed.
[==============================================================================}
function MArrayHelper.Unduplicated: MArray; overload;
var
  a, l, i, j: Integer;
  m: Boolean;
begin
  Result := Self.Copy;
  l := Result.Length;
  if (l < 2) then
    Exit;
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := (Result[i] = Result[j]);
      if m then
        Break;
    end;
    if m then
      Continue;
    Result[a.Increment] := Result[i];
  end;
  if ((l - (a + 1)) > 0) then
    SetLength(Result, (a + 1));
end;

{==============================================================================]
  <Unified>
  @action: Uniques array
  @note: None.
 [==============================================================================}
function MArrayHelper.Unified(const dAscending: Boolean = True): MArray; overload;
var
  d: specialize TDictionary<MType, Byte>;
  i, n: Integer;
begin
  d := specialize TDictionary<MType, Byte>.Create;
  try
    SetLength(Result, Self.Size);
    n := 0;
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], 0);
          Result[n.Increase] := Self[i];
        end;
      False:
      for i := High(Self) downto 0 do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], 0);
          Result[n.Increase] := Self[i];
        end;
    end;
    SetLength(Result, n);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Unify>
  @action: Uniques array
  @note: None.
 [==============================================================================}
function MArrayHelper.Unify(const dAscending: Boolean = True): Integer; overload;
var
  s: MArray;
  d: specialize TDictionary<MType, Byte>;
  l, i: Integer;
begin
  d := specialize TDictionary<MType, Byte>.Create;
  Result := 0;
  try
    l := Self.Length;
    case dAscending of
      False:
      begin
        s := Self.Copy;
        for i := (l - 1) downto 0 do
          if not d.ContainsKey(Self[i]) then
          begin
            d.Add(Self[i], 0);
            Self[Result.Increase] := s[i];
          end;
      end;
      True:
      for i := 0 to (l - 1) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], 0);
          Self[Result.Increase] := Self[i];
        end;
    end;
    SetLength(Self, Result);
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Unik>
  @action: Returns a new array containing unique elements by checking each item against all subsequent positions and appending only its last occurrence.
  @note: Operates in quadratic O(n²) time with O(1) auxiliary memory. Preserves relative order based on the final occurrence of each distinct value.
[==============================================================================}
function MArrayHelper.Unik: MArray; overload;
var
  h, i, j, r: Integer;
  f: Boolean;
begin
  r := 0;
  h := High(Self);
  for i := 0 to Result.Alloc(h + 1) do
  begin
    f := False;
    for j := (i + 1) to h do
      if (Self[i] = Self[j]) then
      begin
        f := True;
        Break;
      end;
    if not f then
      Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Uniqalize>
  @action: Removes duplicate elements in-place by shifting remaining items left, shrinking the array, and returning the new length.
  @note: Operates in quadratic O(n²) time with O(1) auxiliary space. Preserves original element order without allocating secondary array memory.
[==============================================================================}
function MArrayHelper.Uniqalize: Integer; overload;
var
  i, r, l: Integer;
begin
  Result := Self.Length;
  r := 0;
  while (r < Result) do
  begin
    l := (r + 1);
    while (l < Result) do
    case (Self[l] = Self[r]) of
      True:
      begin
        for i := l to (Result - 2) do
          Self[i] := Self[i + 1];
        Dec(Result);
      end;
      False: Inc(l);
    end;
    Inc(r);
  end;
  SetLength(Self, Result);
end;

{==============================================================================]
  <Uniqly>
  @action: Returns a new array containing unique elements by tracking duplicate matches in a boolean mask and building the result in reverse order.
  @note: Operates in quadratic O(n²) time with O(n) auxiliary memory. Preserves original insertion order while avoiding inline memory shifts.
[==============================================================================}
function MArrayHelper.Uniqly: MArray; overload;
var
  d: TBooleanArray;
  h, i, r, k: Integer;
begin
  r := Self.Length;
  h := High(Self);
  SetLength(d, r);
  for i := 0 to h do
    if not d[i] then
    for k := (i + 1) to h do
      if (Self[i] = Self[k]) then
      begin
        d[k] := True;
        Dec(r);
      end;
  SetLength(Result, r);
  for i := h downto 0 do
    if not d[i] then
      Result[r.Decrement] := Self[i];
end;

{==============================================================================]
  <Uniqual>
  @action: Removes duplicate elements from the array while preserving original relative order.
  @note: Uses nested linear iteration (O(N^2)) to return a new array containing only the first occurrence of each unique item.
[==============================================================================}
function MArrayHelper.Uniqual: MArray; overload;
var
  h, i, j, s: Integer;
  r: TIntegerArray;
  f: Boolean;
begin
  s := Self.Length;
  if (s < 2) then
    Exit(Self.Cloned);
  SetLength(r, s);
  h := 0;
  r[0] := 0;
  for i := 1 to (s - 1) do
  begin
    for j := 0 to h do
    begin
      f := (Self[r[j]] = Self[i]);
      if f then
        Break;
    end;
    if not f then
      r[h.Increment] := i;
  end;
  for i := 0 to Result.Alloc(h + 1) do
    Result[i] := Self[r[i]];
end;

{==============================================================================]
  <Uniqued>
  @action: Removes all duplicates from arr.
  @note: Returns the unique version of arr.
[==============================================================================}
function MArrayHelper.Uniqued: MArray; overload;
var
  i, j, l, c: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if (Self[i] <> Result[j]) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
        Result[c.Increase] := Self[i];
    end;
    SetLength(Result, c);
  end;
end;

{==============================================================================]
  <Uniquify>
  @action: Returns a new array containing only the unique elements of Self, maintaining original insertion order and truncating allocation to the distinct count.
  @note: Operates in O(n^2) time using a linear search. Potential index out-of-bounds issue if r.Increase is evaluated as a pre-increment.
[==============================================================================}
function MArrayHelper.Uniquify: MArray; overload;
var
  r, l, i: Integer;
begin
  r := 0;
  for i := 0 to Result.Alloc(Self.Length) do
  begin
    l := 0;
    while ((l < r) and (Result[l] <> Self[i])) do
      Inc(l);
    if (l = r) then
      Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Uniqular>
  @action: Returns a new array containing only unique elements with duplicates removed.
  @note: Preserves original relative order by checking for duplicates in reverse (O(N^2) time) and allocating the exact result size.
[==============================================================================}
function MArrayHelper.Uniqular: MArray; overload;
var
  h, i, j, s: Integer;
  r: TIntegerArray;
  f: Boolean;
begin
  s := Self.Length;
  if (s < 2) then
    Exit(Self.Cloned);
  SetLength(r, s);
  h := 0;
  r[0] := 0;
  for i := 1 to (s - 1) do
  begin
    for j := h downto 0 do
    begin
      f := (Self[r[j]] = Self[i]);
      if f then
        Break;
    end;
    if not f then
      r[h.Increment] := i;
  end;
  for i := 0 to Result.Alloc(h + 1) do
    Result[i] := Self[r[i]];
end;

{==============================================================================]
  <Uniset>
  @action: Deduplicates elements in-place within Self while maintaining original order,
           returning the new count of distinct items and trimming the array size.
  @note: Overwrites duplicate elements directly inside Self by using Result as the write index pointer.
         Operates in O(n^2) time via linear scan.
[==============================================================================}
function MArrayHelper.Uniset: Integer; overload;
var
  i, s: Integer;
  f: Boolean;
begin
  Result := 0;
  for i := 0 to High(Self) do
  begin
    f := False;
    for s := 0 to (Result - 1) do
      if (Self[s] = Self[i]) then
      begin
        f := True;
        Break;
      end;
    if not f then
      Self[Result.Increase] := Self[i];
  end;
  SetLength(Self, Result);
end;
{$ENDIF}