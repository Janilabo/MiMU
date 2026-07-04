{$IFDEF HELPERS}
function Header(const N: Integer = 1): MArray; overload;
function Trailer(const N: Integer = 1): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Header>
  @action: Removes and returns the first N-count of elements from `Self`, preserving order.
  @note: Shifts the remaining elements down to fill the gap, then shrinks `Self`.
[==============================================================================}
function MArrayHelper.Header(const N: Integer = 1): MArray; overload;
var
  i, c, l: Integer;
begin
  l := Self.Length;
  c := Result.SetSize(IfThen((N > l), l, Max(0, N)));
  for i := 0 to (c - 1) do
    Result[i] := Self[i];
  for i := c to (l - 1) do
    Self[i - c] := Self[i];
  Self.SetSize(l - c);
end;

{==============================================================================]
  <Trailer>
  @action: Removes and returns the last N-count of elements from `Self`, in reverse order.
  @note: Since elements are taken from the tail, order comes out reversed; `Self` is truncated directly with no shift needed.
[==============================================================================}
function MArrayHelper.Trailer(const N: Integer = 1): MArray; overload;
var
  i, s, c, l: Integer;
begin
  l := Self.Length;
  c := Result.SetSize(IfThen((N > l), l, Max(0, N)));
  s := (l - 1);
  for i := 0 to (c - 1) do
    Result[i] := Self[s - i];
  Self.SetSize(l - c);
end;
{$ENDIF}
