{$IFDEF HELPERS}
function Containing(const R: TRange; const strictly: Boolean = False): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Containing>
  @action: Determines whether the array contains a range equal to the specified
           target range.
           Performs a linear scan and returns True upon the first match according
           to the selected equality semantics.
  @note:
    - Comparison is delegated to TRange.Coequal:
        * strictly = True:
            Exact match on (start, stop).
        * strictly = False:
            Match on normalized bounds (logical equivalence).
    - Algorithm:
        * Iterates from index 0 to High(Self).
        * Exits early on first successful match.
    - Complexity:
        * Time:  O(n)
        * Space: O(1)
    - Behavior:
        * Returns True if any element satisfies Coequal(R, strictly).
        * Returns False if no match is found.
    - Characteristics:
        * Order-independent.
        * Short-circuit evaluation minimizes average-case cost.
    - Notes:
        * Despite the name, this checks for equality (set membership),
          not geometric containment (i.e. does NOT test whether R is
          inside another range).
        * For true containment semantics, a separate interval inclusion
          check (e.g. R ⊆ Self[i]) would be required.
[==============================================================================}
function TRangeArrayHelper.Containing(const R: TRange; const strictly: Boolean = False): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
  if Self[i].Coequal(R, strictly) then
    Exit(True);
  Result := False;
end;
{$ENDIF}
