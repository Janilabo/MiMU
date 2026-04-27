{$IFDEF HELPERS}
function Evert: Boolean; overload;
function Everted: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Evert>
  @action: Reverses the array elements in-place using a dual-pointer swap.
  @note:
    - Efficiency: Operates at O(1) space complexity.
    - Speed: Uses raw PInteger dereferencing for optimal CPU throughput.
[==============================================================================}
function TIntegerArrayHelper.Evert: Boolean; overload;
var
  S, E: PInteger;
  H, R: Integer;
begin
  H := High(Self);
  Result := (H > 0);
  if not Result then
    Exit;
  S := @Self[0];
  E := @Self[H];
  while (S < E) do
  begin
    R := S^;
    S^ := E^;
    E^ := R;
    Inc(S);
    Dec(E);
  end;
end;

{==============================================================================]
  <Everted>
  @action: Returns a reversed clone of the array.
  @note:
    - Strategy: Employs a single-pass pointer stream (Tail-to-Head) to
      populate the result.
    - Safety: Non-mutating; ideal for immutable data patterns.
[==============================================================================}
function TIntegerArrayHelper.Everted: TIntegerArray; overload;
var
  S, D: PInteger;
  i, L: Integer;
begin
  L := Self.Length;
  if (L < 2) then
    Exit(Self.Copy);
  SetLength(Result, L);
  S := @Self[L - 1];
  D := @Result[0];
  for i := 1 to L do
  begin
    D^ := S^;
    Inc(D);
    Dec(S);
  end;
end;
{$ENDIF}