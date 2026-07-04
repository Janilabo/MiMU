{$IFDEF HELPERS}
function Colophon(const N: Integer = 1): MArray; overload;
function Epilogue(const N: Integer = 1): MArray; overload;
function Excerpt(const N: Integer = 1): MArray; overload;
function Header(const N: Integer = 1): MArray; overload;
function Prologue(const N: Integer = 1): MArray; overload;
function Trailer(const N: Integer = 1): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Colophon>
  @action: Removes and returns the last N-count of elements from `Self`, in reverse order.
  @note: Repeatedly calls the array's own `.Pop` helper; since Pop removes from the tail, the reversed order falls out naturally with no extra bookkeeping.
[==============================================================================}
function MArrayHelper.Colophon(const N: Integer = 1): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  for i := 0 to (Result.SetSize(IfThen((N > l), l, Max(0, N))) - 1) do
    Result[i] := Self.Pop;
end;

{==============================================================================]
  <Epilogue>
  @action: Removes and returns the last N-count of elements from `Self`, in reverse order.
  @note: Slices the tail with Copy(), then relies on `.Reversed` to flip element order.
[==============================================================================}
function MArrayHelper.Epilogue(const N: Integer = 1): MArray; overload;
var
  c, l: Integer;
begin
  l := Self.Length;
  c := IfThen((N > l), l, Max(0, N));
  Result := System.Copy(Self, (l - c), c).Reversed;
  Self.SetSize(l - c);
end;

{==============================================================================]
  <Excerpt>
  @action: Removes and returns the first N-count of elements from `Self`, preserving order.
  @note: Extracts the head via Copy(), then strips it from `Self` in place using the dynamic-array Delete() procedure.
[==============================================================================}
function MArrayHelper.Excerpt(const N: Integer = 1): MArray; overload;
var
  c, l: Integer;
begin
  l := Self.Length;
  c := IfThen((N > l), l, Max(0, N));
  Result := System.Copy(Self, 0, c);
  System.Delete(Self, 0, c);
end;

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
  <Prologue>
  @action: Removes and returns the first N-count of elements from `Self`, preserving order.
  @note: Uses the built-in Copy() function to slice the head and tail segments directly, avoiding manual index shifting entirely.
[==============================================================================}
function MArrayHelper.Prologue(const N: Integer = 1): MArray; overload;
var
  c, l: Integer;
begin
  l := Self.Length;
  c := IfThen((N > l), l, Max(0, N));
  Result := System.Copy(Self, 0, c);
  Self := System.Copy(Self, c, (l - c));
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
