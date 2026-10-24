{$IFDEF HELPERS}
function Levied(const map: TIntegerArray): MArray; overload;
function Scattered(const map: TIntegerArray): MArray; overload;
function Levy(const map: TIntegerArray): Integer; overload;
function Scatter(const map: TIntegerArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Levied>
  @action: Returns a new array with elements gathered from Self according to the index map (Result[i] := Self[map[i]]).
  @note: Out-of-place operation. Self remains unmodified. Returns an empty array if lengths do not match.
[==============================================================================}
function MArrayHelper.Levied(const map: TIntegerArray): MArray; overload;
var
  i: Integer;
begin
  if (Self.Length <> map.Length) then
    Exit([]);
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := Self[map[i]];
end;

{==============================================================================]
  <Scattered>
  @action: Returns a new array with elements from Self scattered to positions specified by the index map (Result[map[i]] := Self[i]).
  @note: Out-of-place operation. Self remains unmodified. Inverse mapping of Levied. Returns an empty array if lengths do not match.
[==============================================================================}
function MArrayHelper.Scattered(const map: TIntegerArray): MArray; overload;
var
  i: Integer;
begin
  if (Self.Length <> map.Length) then
    Exit([]);
  for i := 0 to Result.Alloc(Self.Length) do
    Result[map[i]] := Self[i];
end;

{==============================================================================]
  <Levy>
  @action: Permutes the elements of Self in-place using the index map (gather permutation).
  @note: In-place operation using cycle decomposition to avoid extra array allocation. Modifies Self directly.
         Returns Self.Length on success, or 0 if lengths mismatch.
[==============================================================================}
function MArrayHelper.Levy(const map: TIntegerArray): Integer; overload;
var
  d: TBooleanArray;
  s: MType;
  i, j, k: Integer;
begin
  if (Self.Length <> map.Length) then
    Exit(0);
  Result := Self.Length;
  for i := 0 to d.Alloc(Result) do
    if not d[i] then
    begin
      j := i;
      s := Self[i];
      k := map[j];
      while (k <> i) do
      begin
        Self[j] := Self[k];
        d[j] := True;
        j := k;
        k := map[j];
      end;
      Self[j] := s;
      d[j] := True;
    end;
end;

{==============================================================================]
  <Scatter>
  @action: Permutes the elements of Self in-place using the index map (scatter permutation).
  @note: In-place operation using cycle decomposition. Modifies Self directly. Inverse in-place operation of Levy. Returns Self.Length on success, or 0 if lengths mismatch.
[==============================================================================}
function MArrayHelper.Scatter(const map: TIntegerArray): Integer; overload;
var
  d: TBooleanArray;
  s, t: MType;
  i, j, k: Integer;
begin
  if (Self.Length <> map.Length) then
    Exit(0);
  Result := Self.Length;
  for i := 0 to d.Alloc(Result) do
    if not d[i] then
    begin
      j := i;
      s := Self[i];
      repeat
        k := map[j];
        t := Self[k];
        Self[k] := s;
        s := t;
        d[j] := True;
        j := k;
      until (j = i);
    end; 
end;
{$ENDIF}