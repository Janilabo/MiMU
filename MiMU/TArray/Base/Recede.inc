{$IFDEF HELPERS}
function Recede: MArray; overload;
function Recoil: MArray; overload;
function Repulse: MArray; overload;
function Retreat: MArray; overload;
function Wrench: MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Recede>
  @action: Copies elements into a new array in reverse order using a two-pointer approach, then clears the original array.
  @note: Destructive operation. The calling array will be empty (Length = 0) after execution.
[==============================================================================}
function MArrayHelper.Recede: MArray; overload;
var
  l, h: Integer;
begin
  l := -1;
  h := Result.SetSize(Self.Length);
  while (l.Increment <= h.Decrement) do
  begin
    Result[h] := Self[l];
    Result[l] := Self[h];
  end;
  Self.SetSize(0);
end;

{==============================================================================]
  <Recoil>
  @action: Reverses the order of elements into a new array and clears the original array.
  @note: Destructive operation. The calling array will be empty (Length = 0) after execution.
[==============================================================================}
function MArrayHelper.Recoil: MArray; overload;
var
  h, i: Integer;
begin
  h := (Result.SetSize(Self.Length) - 1);
  for i := 0 to h do
    Result[i] := Self[h - i];
  Self.SetSize(0);
end;

{==============================================================================]
  <Repulse>
  @action: Copies `Self` into `Result` in reverse order, emptying `Self` in the process.
  @note: Order-reversing variant of the Relocation family; walks `Self` downto 0 and writes sequentially into `Result`,
         then truncates `Self` in one shot. No `Pop`, no mirrored-index math — the baseline/canonical Recede implementation.
[==============================================================================}
function MArrayHelper.Repulse: MArray; overload;
var
  i, r: Integer;
begin
  Result.SetSize(Self.Length);
  r := 0;
  for i := High(Self) downto 0 do
    Result[r.Increase] := Self[i];
  Self.SetSize(0);
end;

{==============================================================================]
  <Retreat>
  @action: Copies `Self` into `Result` in reverse order, emptying `Self` in the process.
  @note: Order-reversing variant of the Relocation family; uses `Pop` to drain `Self` from the back, so `Result` ends up in reverse original order.
[==============================================================================}
function MArrayHelper.Retreat: MArray; overload;
var
  i: Integer;
begin
  for i := 0 to (Result.SetSize(Self.Length) - 1) do
    Result[i] := Self.Pop;
end;

{==============================================================================]
  <Wrench>
  @action: Reverses the array by utilizing the internal Reversed property/method and clears the original array.
  @note: Destructive operation. The calling array will be empty (Length = 0) after execution.
[==============================================================================}
function MArrayHelper.Wrench: MArray; overload;
begin
  Result := Self.Reversed;
  Self.SetSize(0);
end;
{$ENDIF}
