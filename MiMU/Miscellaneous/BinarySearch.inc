{$IFDEF FUNCTIONS}
function BinaryContains(const arr: TIntegerArray; const item: Integer; const ascending: Boolean = True): Boolean; overload;
function BinaryContains(const arr: TDoubleArray; const item: Double; const ascending: Boolean = True): Boolean; overload;
function BinaryContains(const arr: TStringArray; const item: string; const ascending: Boolean = True): Boolean; overload;
function BinaryContains(const arr: TCharArray; const item: Char; const ascending: Boolean = True): Boolean; overload;
function BinaryContains(const arr: TPointArray; const item: TPoint; const ascending: Boolean = True): Boolean; overload;
function BinarySearch(const arr: TIntegerArray; const item: Integer; const ascending: Boolean = True): Integer; overload;
function BinarySearch(const arr: TDoubleArray; const item: Double; const ascending: Boolean = True): Integer; overload;
function BinarySearch(const arr: TStringArray; const item: string; const ascending: Boolean = True): Integer; overload;
function BinarySearch(const arr: TCharArray; const item: Char; const ascending: Boolean = True): Integer; overload;
function BinarySearch(const arr: TPointArray; const item: TPoint; const ascending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function BinaryContains(const arr: TIntegerArray; const item: Integer; const ascending: Boolean = True): Boolean; overload; {$I Skeletons/BinaryContains.inc}
function BinaryContains(const arr: TDoubleArray; const item: Double; const ascending: Boolean = True): Boolean; overload; {$I Skeletons/BinaryContains.inc}
function BinaryContains(const arr: TStringArray; const item: string; const ascending: Boolean = True): Boolean; overload; {$I Skeletons/BinaryContains.inc}
function BinaryContains(const arr: TCharArray; const item: Char; const ascending: Boolean = True): Boolean; overload; {$I Skeletons/BinaryContains.inc}
function BinaryContains(const arr: TPointArray; const item: TPoint; const ascending: Boolean = True): Boolean; overload;
var
  L, H, M: Integer;
begin
  L := 0;
  H := High(arr);
  while (L <= H) do
  begin
    M := (L + ((H - L) shr 1));
    if ((ascending and (arr[M] < item)) or ((not ascending) and (arr[M] > item))) then
      L := (M + 1)
    else if ((ascending and (arr[M] > item)) or ((not ascending) and (arr[M] < item))) then
      H := (M - 1)
    else
      Exit(True);
  end;
  Result := False;
end;

function BinarySearch(const arr: TIntegerArray; const item: Integer; const ascending: Boolean = True): Integer; overload; {$I Skeletons/BinarySearch.inc}
function BinarySearch(const arr: TDoubleArray; const item: Double; const ascending: Boolean = True): Integer; overload; {$I Skeletons/BinarySearch.inc}
function BinarySearch(const arr: TStringArray; const item: string; const ascending: Boolean = True): Integer; overload; {$I Skeletons/BinarySearch.inc}
function BinarySearch(const arr: TCharArray; const item: Char; const ascending: Boolean = True): Integer; overload; {$I Skeletons/BinarySearch.inc}
function BinarySearch(const arr: TPointArray; const item: TPoint; const ascending: Boolean = True): Integer; overload;
var
  L, H, M: Integer;
begin
  L := 0;
  H := High(arr);
  while (L <= H) do
  begin
    M := (L + ((H - L) shr 1));
    if ((ascending and (arr[M] < item)) or ((not ascending) and (arr[M] > item))) then
      L := (M + 1)
    else if ((ascending and (arr[M] > item)) or ((not ascending) and (arr[M] < item))) then
      H := (M - 1)
    else
      Exit(M);
  end;
  Result := -1;
end;
{$ENDIF}