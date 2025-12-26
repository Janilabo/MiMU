{$IFDEF HELPERS}
function BinaryExists(const item: TPoint): Boolean; overload;
function BinaryContains(const item: TPoint): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryExists>
  @action: Performs a binary search for a specified point in a sorted TPointArray.
  @note: Returns True if the matching point is found.
[==============================================================================}
function TPointArrayHelper.BinaryExists(const item: TPoint): Boolean; overload;
  function BS(const L, R: Integer): Boolean;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(False);
    M := (L + ((R - L) div 2));
    case Self[M].Compare(item) of
      0: Exit(True);
      1: Result := BS(L, (M - 1));
      -1: Result := BS((M + 1), R);
    end;
  end;
begin
  Result := BS(0, High(Self));
end;

{==============================================================================]
  <BinarySearch>
  @action: Performs a binary search for a specified point in a sorted TPointArray.
  @note: - The array must be sorted in ascending lexicographic order by X, then by Y,
           consistent with TPoint.Compare.
         - Returns the index of the matching point if found, or -1 if not found.
[==============================================================================}
function TPointArrayHelper.BinaryContains(const item: TPoint): Boolean; overload;
begin
  Result := (Self.BinarySearch(item) > -1);
end;
{$ENDIF}
