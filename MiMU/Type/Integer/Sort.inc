{$IFDEF FUNCTIONS}
function XORSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
function XORSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;

function iSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
function iSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <XORSort>
  @action: Conditionally sorts two Integer values in-place using XOR swap.
  @note: Swaps A and B only if they are out of order according to the
         specified sort direction.
         Returns True if a swap occurred, otherwise False.
         XOR swap assumes A and B refer to distinct storage locations.
[==============================================================================}
function XORSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := (oAscending and (A > B)) or ((not oAscending) and (A < B));
  if Result then
  begin
    A := (A xor B);
    B := (A xor B);
    A := (A xor B);
  end;
end;

{==============================================================================]
  <XORSort>
  @action: Conditionally sorts three Integer values in-place using XOR-based
           pairwise comparisons.
  @note: Sorting is performed by comparing and conditionally swapping all
         value pairs (A,B), (A,C), and (B,C).
         Returns True if at least one swap occurred.
         Order is ascending by default, descending if oAscending is False.
[==============================================================================}
function XORSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Integer(XORSort(A, B, oAscending)) + Integer(XORSort(A, C, oAscending)) + Integer(XORSort(B, C, oAscending))) > 0);
end;

{==============================================================================]
  <iSort>
  @action: Conditionally sorts two Integer values in-place using arithmetic
           swap (addition/subtraction).
  @note: Swaps A and B only if they are out of order according to the
         specified sort direction.
         Returns True if a swap occurred, otherwise False.
         Arithmetic swap may overflow if A + B exceeds Integer range.
[==============================================================================}
function iSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
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
  @action: Conditionally sorts three Integer values in-place using arithmetic
           pairwise comparisons.
  @note: Sorting is performed by comparing and conditionally swapping all
         value pairs (A,B), (A,C), and (B,C).
         Returns True if at least one swap occurred.
         Arithmetic swap may overflow if intermediate sums exceed Integer range.
[==============================================================================}
function iSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Integer(iSort(A, B, oAscending)) + Integer(iSort(A, C, oAscending)) + Integer(iSort(B, C, oAscending))) > 0);
end;
{$ENDIF}