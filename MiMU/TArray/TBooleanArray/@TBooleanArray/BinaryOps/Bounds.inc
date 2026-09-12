{$IFDEF HELPERS}
function Binary1st(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
function BinaryLst(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================|
  <Binary1st>
  @action: Returns the VERY FIRST occurrence index of item.
  @note: O(log N) Single-Boundary Binary Search.
[==============================================================================}
function TBooleanArrayHelper.Binary1st(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
var
  H, L, R, M: Integer;
begin
  H := High(Self);
  if (H = -1) then
    Exit(-1);
  if (Self[0] = item) then
    Exit(0);
  if (Self[H] <> item) then
    Exit(-1);
  L := 0;
  R := H;
  Result := -1;
  while (L <= R) do
  begin
    M := (L + (R - L) div 2);
    case (Self[M] = item) of
      True:
      begin
        Result := M;
        R := (M - 1);
      end;
      False:
      if (item = oAscending) then
        L := (M + 1)
      else
        R := (M - 1);
    end;
  end;
end;

{==============================================================================|
  <BinaryLst>
  @action: Returns the VERY LAST index of item in a sorted TBooleanArray.
  @note: Returns -1 if item is not found in the array.
[==============================================================================}
function TBooleanArrayHelper.BinaryLst(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
var
  H, L, R, M: Integer;
begin
  H := High(Self);
  if (H = -1) then
    Exit(-1);
  if (Self[H] = item) then
    Exit(H);
  if (Self[0] <> item) then
    Exit(-1);
  L := 0;
  R := H;
  Result := -1;
  while (L <= R) do
  begin
    M := (L + (R - L) div 2);
    case (Self[M] = item) of
      True:
      begin
        Result := M;
        L := (M + 1);
      end;
      False:
      if (item = oAscending) then
        L := (M + 1)
      else
        R := (M - 1);
    end;
  end;
end;
{$ENDIF}
