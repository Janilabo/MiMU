{$IFDEF HELPERS}
function Diversified: MArray; overload;
function DiversifiedEx(const dAscending: Boolean = True): MArray; overload;
function Purified(const dAscending: Boolean = True): MArray; overload;
function Purify(const dAscending: Boolean = True): Integer; overload;
function Uncluttered: MArray; overload;
function Unified(const dAscending: Boolean = True): MArray; overload;
function Unify(const dAscending: Boolean = True): Integer; overload;
function Unduplicated: MArray; overload;
function Uniqued: MArray; overload;
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
{$ENDIF}