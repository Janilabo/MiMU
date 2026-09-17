{$IFDEF HELPERS}
function ShellSort(const aAscending: Boolean = True): Integer; overload;
function ShellSorted(const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ShellSort>
  @action: ShellSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.ShellSort(const aAscending: Boolean = True): Integer; overload;
var
  x, a, b, l, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    case (Result > 1) of
      True:
      begin
        l := Self.Length;
        x := 0;
        while (x < (l div 3)) do
          x := ((x * 3) + 1);
        while (x >= 1) do
        begin
          for a := x to (l - 1) do
          begin
            b := a;
            while ((b >= x) and (Sign(Self[b].Compare(Self[b - x])) = o)) do
	    begin
              Exchange(b, (b - x));
	      b.Decrease(x);
	    end;
          end;
          x := (x div 3);
        end;
      end;
      False:
      if (Sign(Self[1].Compare(Self[0])) = o) then
        Exchange(0, 1);
    end;
  end;
end;

{==============================================================================]
  <ShellSorted>
  @action: Returns a new cloned array sorted using the Shell Sort algorithm 
           without modifying the original array instance.
  @note: - Uses Shell's original gap sequence starting at N / 2 and halving
           (g = g div 2) until g = 0.
         - Executes g-gap insertion sort internally for each pass, branching
           on `oAscending` to avoid runtime conditional checks inside loops.
         - Complexity: O(N²) worst-case time complexity using standard N/2 gap
           sequence; O(N) space complexity to allocate the cloned result array.
[==============================================================================}
function MArrayHelper.ShellSorted(const oAscending: Boolean = True): MArray; overload;
var
  g, h, i, j: Integer;
  r: MType;
begin
  Result := Self.Cloned;
  if (Result.Length < 2) then
    Exit;
  h := High(Self);
  g := ((h + 1) div 2);
  case oAscending of
    True:
    while (g > 0) do
    begin
      for i := g to h do
      begin
        r := Result[i];
        j := i;
        while ((j >= g) and (Result[j - g] > r)) do
        begin
          Result[j] := Result[j - g];
          Dec(j, g);
        end;
        Result[j] := r;
      end;
      g := (g div 2);
    end;
    False:
    while (g > 0) do
    begin
      for i := g to h do
      begin
        r := Result[i];
        j := i;
        while ((j >= g) and (Result[j - g] < r)) do
        begin
          Result[j] := Result[j - g];
          Dec(j, g);
        end;
        Result[j] := r;
      end;
      g := (g div 2);
    end;
  end;
end;
{$ENDIF}