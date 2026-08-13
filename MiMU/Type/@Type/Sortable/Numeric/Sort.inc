{$IFDEF FUNCTIONS}
function iSort(var A, B: MType; const oAscending: Boolean = True): Boolean; overload;
function iSort(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <iSort>
  @action: Conditionally sorts two values in-place using arithmetic
           swap (addition/subtraction).
  @note: Swaps A and B only if they are out of order according to the
         specified sort direction.
         Returns True if a swap occurred, otherwise False.
         Arithmetic swap may overflow if A + B exceeds value range.
[==============================================================================}
function iSort(var A, B: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (A < B)));
  if Result then
  begin
    A := (A + B);
    B := (A - B);
    A := (A - B);
  end;
end;

{==============================================================================]
  <iSort>
  @action: Conditionally sorts three values in-place using arithmetic
           pairwise comparisons.
  @note: Sorting is performed by comparing and conditionally swapping all
         value pairs (A,B), (A,C), and (B,C).
         Returns True if at least one swap occurred.
         Arithmetic swap may overflow if intermediate sums exceed value range.
[==============================================================================}
function iSort(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Integer(iSort(A, B, oAscending)) + Integer(iSort(A, C, oAscending)) + Integer(iSort(B, C, oAscending))) > 0);
end;
{$ENDIF}