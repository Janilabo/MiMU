{$IFDEF HELPERS}
function Weld(const A, B: MArray; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Weld>
  @action: Merges two pre-sorted arrays A and B into Self as a single sorted
           array, returning High(Self).
  @note: A and B must each be pre-sorted (to oAscending) for the result to
         be valid. Stable: on ties, elements from A precede elements from B.
[==============================================================================}
function MArrayHelper.Weld(const A, B: MArray; const oAscending: Boolean = True): Integer; overload;
var
  i: Integer;
  l, r: TRange;
begin
  if A.Empty then
    Exit(B.Data(Self));
  if B.Empty then
    Exit(A.Data(Self));
  Result := Self.SetSize(A.Length + B.Length);
  l.Create(0, A.Length);
  r.Create(0, B.Length);
  i := 0;
  while ((l.start < l.stop) and (r.start < r.stop)) do
    if ((oAscending and (A[l.start] <= B[r.start])) or ((not oAscending) and (A[l.start] >= B[r.start]))) then
      Self[i.Increase] := A[l.start.Increase]
    else
      Self[i.Increase] := B[r.start.Increase];
  while (l.start < l.stop) do
    Self[i.Increase] := A[l.start.Increase];
  while (r.start < r.stop) do
    Self[i.Increase] := B[r.start.Increase];
end;
{$ENDIF}