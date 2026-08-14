{$IFDEF HELPERS}
function AsIDs(const aAscending: Boolean = True): TIntegerArray; overload;
function AsIDs(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function AsIndexes(const aAscending: Boolean = True): TIntegerArray; overload;
function AsIndexes(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function AsIndices(const aAscending: Boolean = True): TIntegerArray; overload;
function AsIndices(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function GetIDs: TIntegerArray; overload;
function GetIDs(const sIndex: Integer): TIntegerArray; overload;
function ID(const aAscending: Boolean = True): TIntegerArray; overload;
function ID(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function IDs(const aAscending: Boolean = True): TIntegerArray; overload;
function IDs(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function Indeca: TIntegerArray; overload;
function Indeca(const sIndex: Integer): TIntegerArray; overload;
function Indexa: TIntegerArray; overload;
function Indexa(const sIndex: Integer): TIntegerArray; overload;
function Indexed(const aAscending: Boolean = True): TIntegerArray; overload;
function Indexed(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function Indexes(const aAscending: Boolean = True): TIntegerArray; overload;
function Indexes(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function Indexing(const aAscending: Boolean = True): TIntegerArray; overload;
function Indexing(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function Indexment: TIntegerArray; overload;
function Indexment(const sIndex: Integer): TIntegerArray; overload;
function Indiced(const aAscending: Boolean = True): TIntegerArray; overload;
function Indiced(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function Indices(const aAscending: Boolean = True): TIntegerArray; overload;
function Indices(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function Indicia: TIntegerArray; overload;
function Indicia(const sIndex: Integer): TIntegerArray; overload;
function Indicing: TIntegerArray; overload;
function Indicing(const sIndex: Integer): TIntegerArray; overload;
function LoadID(var target: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
function LoadID(var target: TIntegerArray; const sIndex: Integer; const aAscending: Boolean = True): Integer; overload;
function LoadIDs(var target: TIntegerArray): Integer; overload;
function LoadIDs(var target: TIntegerArray; const sIndex: Integer): Integer; overload;
function LoadIndexes(var target: TIntegerArray): Integer; overload;
function LoadIndexes(var target: TIntegerArray; const sIndex: Integer): Integer; overload;
function LoadIndices(var target: TIntegerArray): Integer; overload;
function LoadIndices(var target: TIntegerArray; const sIndex: Integer): Integer; overload;
function Slots: TIntegerArray; overload;
function Slots(const sIndex: Integer): TIntegerArray; overload;
function ToIDs(const aAscending: Boolean = True): TIntegerArray; overload;
function ToIDs(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function ToIndexes: TIntegerArray; overload;
function ToIndexes(const sIndex: Integer): TIntegerArray; overload;
function ToIndices(const aAscending: Boolean = True): TIntegerArray; overload;
function ToIndices(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsIDs>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Pointer-based fill with early-exit shortcuts for length 0 and 1. 
         Ascending and descending are two separate loops selected via case, 
         each walking the pointer forward while writing increasing or 
         decreasing values.
[==============================================================================}
function M2DArrayHelper.AsIDs(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l: Integer;
  P: PInteger;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
	1: Exit([0]);
  end;
  SetLength(Result, l);
  P := @Result[0];
  case aAscending of
    True:
    for i := 0 to (l - 1) do
    begin
      P^ := i;
      Inc(P);
    end;
	False:
	for i := (l - 1) downto 0 do
    begin
      P^ := i;
      Inc(P);
    end;
  end;
end;

{==============================================================================]
  <AsIDs>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.AsIDs on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.AsIDs(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].AsIDs(aAscending);
end;

{==============================================================================]
  <AsIndexes>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Builds the result via dynamic append (Supply) rather than pre-sizing. 
         Uses a self-mutating counter (i.Increment / l.Decrement) as the loop 
         condition and the value pushed in the same expression.
[==============================================================================}
function M2DArrayHelper.AsIndexes(const aAscending: Boolean = True): TIntegerArray; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([0]);
  end;
  SetLength(Result, 0);
  i := -1;
  case aAscending of
    True:
    while (i.Increment < l) do
      Result.Supply(i);
    False:
    while (l.Decrement > i) do
      Result.Supply(l);
  end;
end;

{==============================================================================]
  <AsIndexes>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.AsIndexes on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.AsIndexes(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].AsIndexes(aAscending);
end;

{==============================================================================]
  <AsIndices>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Uses a label/goto short-circuit for the empty case instead of Exit. 
         Ascending fills via pointer walk; descending fills the same 
         pointer walk but writes values from a self-decrementing counter 
         (l.Decrement) rather than a separate index variable.
[==============================================================================}
function M2DArrayHelper.AsIndices(const aAscending: Boolean = True): TIntegerArray; overload;
label
  ready;
var
  i, l: Integer;
  P: PInteger;
begin
  l := Result.SetSize(Self.Length);
  if (l < 1) then
    goto ready;
  P := PInteger(Result);
  case aAscending of
    True:
    for i := 0 to (l - 1) do
    begin
      P^ := i;
      Inc(P);
    end;
    False:
    repeat
      P^ := l.Decrement;
      Inc(P);
    until (l = 0);
  end;
  ready:
end;

{==============================================================================]
  <AsIndices>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.AsIndices on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.AsIndices(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].AsIndices(aAscending);
end;

{==============================================================================]
  <GetIDs>
  @action: Returns an array of row indices [0..Length-1] for the 2D array, 
           ascending only.
  @note: Manually unrolls the fill loop by 4 elements per iteration, then 
         handles any remaining 0-3 elements in a trailing loop. No 
         aAscending parameter — this variant is ascending-only.
[==============================================================================}
function M2DArrayHelper.GetIDs: TIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([0]);
  end;
  SetLength(Result, l);
  i := 0;
  while (i <= (l - 4)) do
  begin
    Result[i] := i;
    Result[i + 1] := (i + 1);
    Result[i + 2] := (i + 2);
    Result[i + 3] := (i + 3);
    Inc(i, 4);
  end;
  for i := i to (l - 1) do
    Result[i] := i;
end;

{==============================================================================]
  <GetIDs>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.GetIDs on Self[sIndex]. 
[==============================================================================}
function M2DArrayHelper.GetIDs(const sIndex: Integer): TIntegerArray; overload;
begin
  Result := Self[sIndex].GetIDs;
end;

{==============================================================================]
  <ID>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Formula-based fill — computes a base offset and step direction once 
         (b, s) outside the loop, then derives each element as (b + s*i) 
         with no per-iteration branching.
[==============================================================================}
function M2DArrayHelper.ID(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l, b, s: Integer;
begin
  l := Result.SetSize(Self.Length);
  b := (Integer(not aAscending) * (l - 1));
  s := IfThen(aAscending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := (b + (s * i));
end;

{==============================================================================]
  <ID>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.ID on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.ID(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].ID(aAscending);
end;

{==============================================================================]
  <IDs>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Uses Result.Alloc to size and obtain the high bound in one step. 
         Ascending fills directly by index; descending fills using a 
         mirrored-index expression (Result[h - i] := i) rather than a 
         separate reverse loop.
[==============================================================================}
function M2DArrayHelper.IDs(const aAscending: Boolean = True): TIntegerArray; overload;
var
  h, i: Integer;
begin
  case aAscending of
    True:
    for i := 0 to Result.Alloc(Self.Length) do
      Result[i] := i;
    False:
	begin
	  h := Result.Alloc(Self.Length);
      for i := h downto 0 do
        Result[h - i] := i;
	end;
  end;
end;

{==============================================================================]
  <IDs>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.IDs on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.IDs(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].IDs(aAscending);
end;

{==============================================================================]
  <Indeca>
  @action: Returns an array of row indices [0..Length-1] for the 2D array, 
           ascending only.
  @note: Manually unrolls the fill loop by 4 using a custom Increment(4) 
         step method, processing the bulk of the array in 4-wide batches 
         before a trailing loop handles the remainder.
[==============================================================================}
function M2DArrayHelper.Indeca: TIntegerArray; overload;
var
  l, i, r: Integer;
begin
  l := Result.SetSize(Self.Length);
  r := ((l div 4) * 4);
  i := -4;
  while (i.Increment(4) < r) do
  begin
    Result[i] := i;
    Result[i + 1] := (i + 1);
    Result[i + 2] := (i + 2);
    Result[i + 3] := (i + 3);
  end;
  Dec(i);
  while (i.Increment < l) do
    Result[i] := i;
end;

{==============================================================================]
  <Indeca>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.Indeca on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Indeca(const sIndex: Integer): TIntegerArray; overload;
begin
  Result := Self[sIndex].Indeca;
end;

{==============================================================================]
  <Indexa>
  @action: Returns an array of row indices [0..Length-1] for the 2D array, 
           ascending only.
  @note: Pointer-based fill with an early exit for the empty case. No 
         aAscending parameter — ascending-only.
[==============================================================================}
function M2DArrayHelper.Indexa: TIntegerArray; overload;
var
  i: Integer;
  P: PInteger;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  P := @Result[0];
  for i := 0 to High(Result) do
  begin
    P^ := i;
    Inc(P);
  end;
end;

{==============================================================================]
  <Indexa>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.Indexa on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Indexa(const sIndex: Integer): TIntegerArray; overload;
begin
  Result := Self[sIndex].Indexa;
end;

{==============================================================================]
  <Indexed>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Guards on Self.Populated before doing any work. Iterates backward 
         via a self-decrementing counter (l.Decrement); ascending writes 
         Result[l] := l directly, descending writes to a mirrored position 
         so the stored sequence still reads in reverse order.
[==============================================================================}
function M2DArrayHelper.Indexed(const aAscending: Boolean = True): TIntegerArray; overload;
var
  l: Integer;
begin
  l := Result.SetSize(Self.Length);
  if (l > 0) then
  case aAscending of
    True:
    while (l.Decrement > -1) do
      Result[l] := l;
    False:
    while (l.Decrement > -1) do
      Result[(Self.Size - l) - 1] := l;
  end;
end;

{==============================================================================]
  <Indexed>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.Indexed on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Indexed(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].Indexed(aAscending);
end;

{==============================================================================]
  <Indexes>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Single loop with the ascending/descending choice re-evaluated via 
         IfThen on every iteration, rather than being decided once before 
         the loop.
[==============================================================================}
function M2DArrayHelper.Indexes(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Result.SetSize(Self.Length);
  for i := 0 to (l - 1) do
    Result[i] := IfThen(aAscending, i, ((l - i) - 1));
end;

{==============================================================================]
  <Indexes>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.Indexes on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Indexes(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].Indexes(aAscending);
end;

{==============================================================================]
  <Indexing>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Fills recursively via a nested divide-and-conquer procedure (RI) 
         that splits the range at its midpoint until reaching single 
         elements, rather than iterating linearly.
[==============================================================================}
function M2DArrayHelper.Indexing(const aAscending: Boolean = True): TIntegerArray; overload;
procedure RI(var return: TIntegerArray; const L, R: Integer);
var
  M: Integer;
begin
  if (L > R) then
    Exit;
  if (L = R) then
  begin
    if aAscending then
      return[L] := L
    else
      return[L] := (High(return) - L);
    Exit;
  end;
  M := (L + ((R - L) div 2));
  RI(return, L, M);
  RI(return, (M + 1), R);
end;
begin
  if (Result.SetSize(Self.Size) > 0) then
    RI(Result, 0, High(Self));
end;

{==============================================================================]
  <Indexing>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.Indexing on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Indexing(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].Indexing(aAscending);
end;

{==============================================================================]
  <Indexment>
  @action: Returns an array of row indices [0..Length-1] for the 2D array, 
           ascending only.
  @note: Two-pointer walk converging from both ends (l upward, r downward), 
         writing both Result[l] := l and Result[r] := r each iteration. 
         No aAscending parameter — the identity fill makes direction moot.
[==============================================================================}
function M2DArrayHelper.Indexment: TIntegerArray; overload;
var
  l, r: Integer;
begin
  l := -1;
  r := Result.SetSize(Self.Length);
  while (l.Increment <= r.Decrement) do
  begin
    Result[l] := l;
    Result[r] := r;
  end;
end;

{==============================================================================]
  <Indexment>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.Indexment on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Indexment(const sIndex: Integer): TIntegerArray; overload;
begin
  Result := Self[sIndex].Indexment;
end;

{==============================================================================]
  <Indiced>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Two-pointer walk using a TRange (r.start/r.stop) rather than raw 
         integers. Ascending writes each pointer's own value; descending 
         swaps the two values across the pointers.
[==============================================================================}
function M2DArrayHelper.Indiced(const aAscending: Boolean = True): TIntegerArray; overload;
var
  r: TRange;
begin
  if (Result.SetSize(Self.Size) = 0) then
    Exit;
  r.Create(0, High(Self));
  case aAscending of
    True:
    repeat
      Result[r.start] := r.start;
      Result[r.stop] := r.stop;
    until (r.start.Increment > r.stop.Decrement);
    False:
    repeat
      Result[r.start] := r.stop;
      Result[r.stop] := r.start;
    until (r.start.Increment > r.stop.Decrement);
  end;
end;

{==============================================================================]
  <Indiced>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.Indiced on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Indiced(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].Indiced(aAscending);
end;

{==============================================================================]
  <Indices>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Uses Low(Self)/High(Self) directly rather than Length, and decides 
         ascending vs. descending once via case before the loop rather than 
         per-iteration.
[==============================================================================}
function M2DArrayHelper.Indices(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l, h: Integer;
begin
  l := Low(Self);
  h := High(Self);
  if (Result.SetSize((h - l) + 1) > 0) then
  case aAscending of
    False:
    for i := l to h do
      Result[h - i] := i;
	True:
    for i := l to h do
      Result[i - l] := i;
  end;
end;

{==============================================================================]
  <Indices>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.Indices on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Indices(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].Indices(aAscending);
end;

{==============================================================================]
  <Indicia>
  @action: Returns an array of row indices [0..Length-1] for the 2D array, 
           ascending only.
  @note: Delegates entirely to TRange.Construct(0, High(Self)).ToArray rather 
         than filling manually. No aAscending parameter.
[==============================================================================}
function M2DArrayHelper.Indicia: TIntegerArray; overload;
begin
  if Self.Empty then
    Exit([]);
  Result := TRange.Construct(0, High(Self)).ToArray;
end;

{==============================================================================]
  <Indicia>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.Indicia on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Indicia(const sIndex: Integer): TIntegerArray; overload;
begin
  Result := Self[sIndex].Indicia;
end;

{==============================================================================]
  <Indicing>
  @action: Returns an array of row indices [0..Length-1] for the 2D array, 
           ascending only.
  @note: Two-pointer convergence from both ends (l upward, h downward), 
         writing identity values at both positions each pass, with a 
         separate check afterward to fill the single middle element when 
         the length is odd.
[==============================================================================}
function M2DArrayHelper.Indicing: TIntegerArray; overload;
var
  l, h: Integer;
begin
  l := -1;
  h := Result.SetSize(Self.Length);
  while (l.Increment < h.Decrement) do
  begin
    Result[l] := l;
    Result[h] := h;
  end;
  if (l = h) then
    Result[l] := l;
end;

{==============================================================================]
  <Indicing>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.Indicing on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Indicing(const sIndex: Integer): TIntegerArray; overload;
begin
  Result := Self[sIndex].Indicing;
end;

{==============================================================================]
  <LoadID>
  @action: Fills target with row indices [0..Length-1] for the 2D array and 
           returns the count.
  @note: Writes into a caller-supplied var array rather than returning a new 
         one, only resizing target if its length differs. Pointer-based, 
         with separate ascending/descending loops.
[==============================================================================}
function M2DArrayHelper.LoadID(var target: TIntegerArray; const aAscending: Boolean = True): Integer; overload;
var
  i: Integer;
  P: PInteger;
begin
  Result := Self.Length;
  if (target.Length <> Result) then
    SetLength(target, Result);
  if (Result = 0) then
    Exit;
  P := @target[0];
  case aAscending of
    True:
    for i := 0 to (Result - 1) do
    begin
      P^ := i;
      Inc(P);
    end;
	False:
	for i := (Result - 1) downto 0 do
    begin
      P^ := i;
      Inc(P);
    end;
  end;
end;

{==============================================================================]
  <LoadID>
  @action: Fills target with column indices for the row at sIndex and 
           returns the count.
  @note: Delegates to the 1D MArrayHelper.LoadID on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.LoadID(var target: TIntegerArray; const sIndex: Integer; const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self[sIndex].LoadID(target, aAscending);
end;

{==============================================================================]
  <LoadIDs>
  @action: Fills target with row indices [0..Length-1] for the 2D array, 
           ascending only, and returns the count.
  @note: Same pointer-based, var-target pattern as LoadID, but with no 
         aAscending parameter.
[==============================================================================}
function M2DArrayHelper.LoadIDs(var target: TIntegerArray): Integer; overload;
var
  i: Integer;
  P: PInteger;
begin
  Result := Self.Length;
  if (target.Length <> Result) then
    SetLength(target, Result);
  if (Result = 0) then
    Exit;
  P := @target[0];
  for i := 0 to (Result - 1) do
  begin
    P^ := i;
    Inc(P);
  end;
end;

{==============================================================================]
  <LoadIDs>
  @action: Fills target with column indices for the row at sIndex and 
           returns the count.
  @note: Delegates to the 1D MArrayHelper.LoadIDs on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.LoadIDs(var target: TIntegerArray; const sIndex: Integer): Integer; overload;
begin
  Result := Self[sIndex].LoadIDs(target);
end;

{==============================================================================]
  <LoadIndexes>
  @action: Fills target with row indices [0..Length-1] for the 2D array, 
           ascending only, and returns the count.
  @note: Plain indexed loop, no pointer arithmetic, no aAscending parameter.
[==============================================================================}
function M2DArrayHelper.LoadIndexes(var target: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  if (target.Length <> Result) then
    SetLength(target, Result);
  for i := 0 to (Result - 1) do
    target[i] := i;
end;

{==============================================================================]
  <LoadIndexes>
  @action: Fills target with column indices for the row at sIndex and 
           returns the count.
  @note: Delegates to the 1D MArrayHelper.LoadIndexes on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.LoadIndexes(var target: TIntegerArray; const sIndex: Integer): Integer; overload;
begin
  Result := Self[sIndex].LoadIndexes(target);
end;

{==============================================================================]
  <LoadIndices>
  @action: Fills target with row indices [0..Length-1] for the 2D array, 
           ascending only, and returns the count.
  @note: Manually unrolls the fill loop by 4 elements per iteration, then 
         handles the remainder in a trailing loop. No aAscending parameter.
[==============================================================================}
function M2DArrayHelper.LoadIndices(var target: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  if (target.Length <> Result) then
    SetLength(target, Result);
  if (Result = 0) then
    Exit;
  i := 0;
  while (i <= (Result - 4)) do
  begin
    target[i] := i;
    target[i + 1] := (i + 1);
    target[i + 2] := (i + 2);
    target[i + 3] := (i + 3);
    Inc(i, 4);
  end;
  while (i < Result) do
  begin
    target[i] := i;
    Inc(i);
  end;
end;

{==============================================================================]
  <LoadIndices>
  @action: Fills target with column indices for the row at sIndex and 
           returns the count.
  @note: Delegates to the 1D MArrayHelper.LoadIndices on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.LoadIndices(var target: TIntegerArray; const sIndex: Integer): Integer; overload;
begin
  Result := Self[sIndex].LoadIndices(target);
end;

{==============================================================================]
  <Slots>
  @action: Returns an array of row indices [0..Length-1] for the 2D array, 
           ascending only.
  @note: Uses Result.Alloc to size and obtain the high bound, then a single 
         plain loop assigning identity values. No aAscending parameter.
[==============================================================================}
function M2DArrayHelper.Slots: TIntegerArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := i;
end;

{==============================================================================]
  <Slots>
  @action: Returns an array of column indices for the row at sIndex, 
           ascending only.
  @note: Delegates to the 1D MArrayHelper.Slots on Self[sIndex]. Unlike most 
         other sIndex overloads here, this one has no aAscending parameter 
         either, staying consistent with the base overload.
[==============================================================================}
function M2DArrayHelper.Slots(const sIndex: Integer): TIntegerArray; overload;
begin
  Result := Self[sIndex].Slots;
end;

{==============================================================================]
  <ToIDs>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Uses a recurrence relation via label/goto — each element is derived 
         from the previous one (Result[i] := Result[i-1] + step) rather than 
         computed independently.
[==============================================================================}
function M2DArrayHelper.ToIDs(const aAscending: Boolean = True): TIntegerArray; overload;
label
  filling;
var
  i, s, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([0]);
  end;
  SetLength(Result, l);
  s := IfThen(aAscending, 1, -1);
  Result[0] := IfThen(aAscending, 0, (l - 1));
  i := 1;
  filling:
  Result[i] := (Result[i - 1] + s);
  if (i.Increment < l) then
    goto filling;
end;

{==============================================================================]
  <ToIDs>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.ToIDs on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.ToIDs(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].ToIDs(aAscending);
end;

{==============================================================================]
  <ToIndexes>
  @action: Returns an array of row indices [0..Length-1] for the 2D array, 
           ascending only.
  @note: Uses Result.Alloc combined with Low(Self) as the loop's starting 
         offset rather than assuming a zero-based lower bound. No 
         aAscending parameter.
[==============================================================================}
function M2DArrayHelper.ToIndexes: TIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Low(Self);
  for i := l to Result.Alloc(Self.Length) do
    Result[i - l] := i;
end;

{==============================================================================]
  <ToIndexes>
  @action: Returns an array of column indices for the row at sIndex, 
           ascending only.
  @note: Delegates to the 1D MArrayHelper.ToIndexes on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.ToIndexes(const sIndex: Integer): TIntegerArray; overload;
begin
  Result := Self[sIndex].ToIndexes;
end;

{==============================================================================]
  <ToIndices>
  @action: Returns an array of row indices [0..Length-1] for the 2D array.
  @note: Fills the array back-to-front (from the last index toward the 
         first) via a recurrence relation and label/goto, regardless of 
         ascending/descending — only the values written differ by direction, 
         not the traversal order.
[==============================================================================}
function M2DArrayHelper.ToIndices(const aAscending: Boolean = True): TIntegerArray; overload;
label
  filling;
var
  s, h, r: Integer;
begin
  h := High(Self);
  case h of
    -1: Exit([]);
    0: Exit([0]);
  end;
  SetLength(Result, (h + 1));
  s := IfThen(aAscending, -1, 1);
  r := IfThen(aAscending, (h + 1), -1);
  filling:
  Result[h] := r.Increment(s);
  if (h.Decrement > -1) then
    goto filling;
end;

{==============================================================================]
  <ToIndices>
  @action: Returns an array of column indices for the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.ToIndices on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.ToIndices(const sIndex: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
begin
  Result := Self[sIndex].ToIndices(aAscending);
end;
{$ENDIF}
