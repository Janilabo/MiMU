{$IFDEF HELPERS}
function Locations(const item: MType; const index: Integer = 2147483647): TIntegerArray; overload;
function Locations(const items: MArray; const index: Integer = 2147483647): TIntegerArray; overload;
function Locations: TIntegerArray; overload;
function Positions(const item: MType; const index: Integer = 0): TIntegerArray; overload;
function Positions(const items: MArray; const index: Integer = 0): TIntegerArray; overload;
function Positions: TIntegerArray; overload;
function Scan(const ID: TRange; const item: MType; const limit: Integer = 2147483647): TIntegerArray; overload;
function Scan(const ID: TIntegerArray; const item: MType; const limit: Integer = 2147483647): TIntegerArray; overload;
function Scan(const ID: TRange; const items: MArray; const limit: Integer = 2147483647): TIntegerArray; overload;
function Scan(const ID: TIntegerArray; const items: MArray; const limit: Integer = 2147483647): TIntegerArray; overload;
function SubarrayLocations(const pattern: MArray): TIntegerArray; overload;
function SubarrayPositions(const pattern: MArray): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Locations>
  @action: Returns last index positions from arr which matched with item.
  @note: None.
[==============================================================================}
function MArrayHelper.Locations(const item: MType; const index: Integer = 2147483647): TIntegerArray; overload;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Min(index, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if (Self[i] = item) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Locations>
  @action: Returns last index positions from arr which matches with items.
  @note: None.
[==============================================================================}
function MArrayHelper.Locations(const items: MArray; const index: Integer = 2147483647): TIntegerArray; overload;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Min(index, h);
  if ((h > -1) and (s > -1) and items.Exists) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if items.Contains(Self[i]) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Locations>
  @action: Simply returns arr indexes.
  @note: None.
[==============================================================================}
function MArrayHelper.Locations: TIntegerArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Self.Size);
  r := 0;
  for i := High(Result) downto 0 do
    Result[r.Increase] := i;
end;

{==============================================================================]
  <Positions>
  @action: Returns index positions from arr which matched with item.
  @note: None.
[==============================================================================}
function MArrayHelper.Positions(const item: MType; const index: Integer = 0): TIntegerArray; overload;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (Self[i] = item) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Positions>
  @action: Returns index positions from arr which matches with items.
  @note: None.
[==============================================================================}
function MArrayHelper.Positions(const items: MArray; const index: Integer = 0): TIntegerArray; overload;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and items.Populated) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if items.Contains(Self[i]) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Positions>
  @action: Simply returns arr indexes.
  @note: None.
[==============================================================================}
function MArrayHelper.Positions: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := i;
end;

{==============================================================================]
  <Scan>
  @action: Scans array for item by ID. Returns all the positions.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Scan(const ID: TRange; const item: MType; const limit: Integer = 2147483647): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  if Self.Populated then
  begin
    SetLength(Result, ID.Size);
    case ID.Ascending of
      True:
      for i := ID.start to ID.stop do
        if (r >= limit) then
	      Break
        else if (Self[i] = item) then
          Result[r.Increase] := i;
      False:
      for i := ID.start downto ID.stop do
        if (r >= limit) then
          Break
		else if (Self[i] = item) then
	      Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Scan>
  @action: Scans array for item by ID. Returns all the positions.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Scan(const ID: TIntegerArray; const item: MType; const limit: Integer = 2147483647): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  if Self.Empty then
  begin
    SetLength(Result, ID.Size);
    for i := 0 to High(ID) do
      if (r >= limit) then
        Break
      else if (Self[ID[i]] = item) then
	    Result[r.Increase] := ID[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Scan>
  @action: Scans array for items by ID. Returns all the positions.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Scan(const ID: TRange; const items: MArray; const limit: Integer = 2147483647): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  if (Self.Populated and items.Populated) then
  begin
    SetLength(Result, ID.Size);
    case ID.Ascending of
      True:
      for i := ID.start to ID.stop do
        if (r >= limit) then
          Break
        else if items.Contains(Self[i]) then
          Result[r.Increase] := i;
      False:
      for i := ID.start downto ID.stop do
        if (r >= limit) then
          Break
        else if items.Contains(Self[i]) then
          Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Scan>
  @action: Scans array for items by ID. Returns all the positions.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Scan(const ID: TIntegerArray; const items: MArray; const limit: Integer = 2147483647): TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  if (Self.Populated and items.Populated) then
  begin
    SetLength(Result, ID.Size);
    for i := 0 to High(ID) do
      if (r >= limit) then
        Break
      else if items.Contains(Self[ID[i]]) then
	    Result[r.Increase] := ID[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <SubarrayLocations>
  @action: Returns subarray positions in arr that match pattern exactly.
  @note: arr[0,1,2,0,1,2,3].([1,2]) => [4,1]	
[==============================================================================}
function MArrayHelper.SubarrayLocations(const pattern: MArray): TIntegerArray; overload;
var
  i, j, l, s, r, p: Integer;
begin
  l := Self.Length;
  p := pattern.Size;
  r := 0;
  if ((p > 0) and (p <= l)) then
  begin
    SetLength(Result, ((l - p) + 1));
    for i := (l - p) downto 0 do
    begin
      s := 0;
      for j := 0 to (p - 1) do
        if (Self[i + j] <> pattern[j]) then
          Break
        else
          s := (s + 1);
      if (s = p) then
        Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <SubarrayPositions>
  @action: Returns subarray positions in arr that match pattern exactly.
  @note: arr[0,1,2,0,1,2,3].([1,2]) => [1,4]	
[==============================================================================}
function MArrayHelper.SubarrayPositions(const pattern: MArray): TIntegerArray; overload;
var
  i, j, l, p, r: Integer;
  f: Boolean;
begin
  l := Self.Length;
  p := pattern.Size;
  r := 0;
  if ((p > 0) and (p <= l)) then
  begin
    SetLength(Result, ((l - p) + 1));
    for i := 0 to (l - p) do
    begin
      f := True;
      for j := 0 to (p - 1) do
        if (Self[i + j] <> pattern[j]) then
        begin
          f := False;
          Break;
        end;
      if f then
        Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}