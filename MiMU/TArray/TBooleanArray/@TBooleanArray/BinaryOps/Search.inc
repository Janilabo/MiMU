{$IFDEF HELPERS}
function BinaryExplore(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
function BinaryFind(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
function BinarySearch(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
function BinarySeek(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================|
  <BinaryExplore>
  @action: Searches for 'item' by galloping inward from both ends at once.
  @note: O(log min(i, H-i)) — no prior assumption about which end the
          transition is closer to.
[==============================================================================}
function TBooleanArrayHelper.BinaryExplore(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
var
  H, F, B, L, R, M: Integer;
begin
  H := High(Self);
  if (H < 0) then
    Exit(-1);
  if (Self[0] = item) then
    Exit(0);
  if (Self[H] = item) then
    Exit(H);
  F := 1;
  B := 1;
  repeat
    if ((F <= H) and (Self[F] = item)) then
    begin
      L := (F div 2);
      R := Min(F, H);
      Break;
    end;
    if ((B <= H) and (Self[H - B] = item)) then
    begin
      R := (H - (B div 2));
      L := Max((H - B), 0);
      Break;
    end;
    if ((F > H) and (B > H)) then
      Exit(-1);
    if (F <= H) then
      F := (F * 2);
    if (B <= H) then
      B := (B * 2);
  until False;
  while (L <= R) do
  begin
    M := (L + (R - L) div 2);
    if (Self[M] = item) then
      Exit(M);
    if (item = oAscending) then
      L := (M + 1)
    else
      R := (M - 1);
  end;
  Result := -1;
end;  

{==============================================================================|
  <BinaryFind>
  @action: Returns an arbitrary matching index in O(1) time by checking array
           boundaries rather than running a loop.
  @note: TBooleanArray.BinarySearch (O(1) Branchless Boundary Check)
[==============================================================================}
function TBooleanArrayHelper.BinaryFind(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
var
  H: Integer;
begin
  Result := High(Self);
  if (Result = -1) then
    Exit;
  if (Self[Result] = item) then
    Exit;
  if (Self[0] = item) then
    Exit(0);
  Result := -1;
end;

{==============================================================================|
  <BinarySearch>
  @action: Searches for item in a sorted TBooleanArray.
  @note: Returns an index where item occurs, or -1 if item is not found.
[==============================================================================}
function TBooleanArrayHelper.BinarySearch(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
var
  L, R, M: Integer;
begin
  L := 0;
  R := High(Self);
  while (L <= R) do
  begin
    M := (L + (R - L) div 2);
    if (Self[M] = item) then
      Exit(M);
    if (item = oAscending) then
      L := (M + 1)
    else
      R := (M - 1);
  end;
  Result := -1;
end;

{==============================================================================|
  <BinarySeek>
  @action: Searches for 'item' using Exponential (Galloping) Search.
  @note: O(log i) complexity where i is the index of the first occurrence.
[==============================================================================}
function TBooleanArrayHelper.BinarySeek(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
var
  H, B, L, R, M: Integer;
begin
  H := High(Self);
  if (H < 0) then
    Exit(-1);
  if (Self[0] = item) then
    Exit(0);
  B := 1;
  while ((B <= H) and (Self[B] <> item)) do
    B := (B * 2);
  L := (B div 2);
  R := Min(B, H);
  while (L <= R) do
  begin
    M := (L + (R - L) div 2);
    if (Self[M] = item) then
      Exit(M);
    if (item = oAscending) then
      L := (M + 1)
    else
      R := (M - 1);
  end;
  Result := -1;
end;
{$ENDIF}
