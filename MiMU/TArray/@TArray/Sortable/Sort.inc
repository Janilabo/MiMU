{$IFDEF HELPERS}
function ToOrder(const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ToOrder>
  @action: Sorts an array by decomposing it into monotonic sub-arrays and 
          recombining them via a k-way merge (Patience / Cascade Sort).
  @note: 
  - Pipeline approach: Executes Self.AsPiles to partition elements into sorted 
    piles, then calls MergeK to merge them back into a single sorted 1D array.
  - Achieves full sorting without a traditional QuickSort pass, leveraging 
    existing structural monotonicity in the source array.
  - Returns a sorted copy of Self according to the oAscending flag.
[==============================================================================}
function MArrayHelper.ToOrder(const oAscending: Boolean = True): MArray; overload;
begin
  Result := Self.AsPiles(oAscending).MergeK(oAscending);
end;
{$ENDIF}
