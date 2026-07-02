{$IFDEF HELPERS}
function Consume: MArray; overload;
function Decant: MArray; overload;
function Discharge: MArray; overload;
function Drain: MArray; overload;
function Evacuate: MArray; overload;
function Loot: MArray; overload;
function Withdraw: MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Consume>
  @action: Produces a fresh copy of `Self`'s contents via `System.Concat`
    with an empty array, then empties `Self`.
  @note: `Concat` always allocates a new array, even when concatenating
    with `[]`, so this guarantees `Result` is an independent buffer rather
    than a shared reference.
[==============================================================================}
function MArrayHelper.Consume: MArray; overload;
begin
  Result := System.Concat(Self, []);
  SetLength(Self, 0);
end;

{==============================================================================]
  <Decant>
  @action: Pours the array contents entirely into the result and zeroes out the original reference.
  @note: Implements a true zero-overhead pointer transfer ($O(1)$) by assigning the raw reference to Result and breaking the source reference via `nil`.
[==============================================================================}
function MArrayHelper.Decant: MArray; overload;
begin
  Result := Self;
  Self := nil;
end;

{==============================================================================]
  <Discharge>
  @action: Extracts all elements from the source array into a new instance while stripping them from the original source.
  @note: Leverages the native `Delete` procedure to truncate the source array to zero length after performing an element-by-element copy.
[==============================================================================}
function MArrayHelper.Discharge: MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  for i := 0 to (Result.SetSize(l) - 1) do
    Result[i] := Self[i];
  if (l > 0) then
    System.Delete(Self, 0, l);
end;

{==============================================================================]
  <Drain>
  @action: Copies the array's contents into `Result`, then empties `Self`.
  @note: `Self` is left with length 0 after the call. Use when ownership of
    the contents should transfer to the caller without leaving a live
    duplicate behind in `Self`.
[==============================================================================}
function MArrayHelper.Drain: MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Result) do
    Result[i] := Self[i];
  SetLength(Self, 0);
end;

{==============================================================================]
  <Evacuate>
  @action: Copies all elements from the source array into a new instance using deep recursion, then zeroes out the source array.
  @note: Executes a post-order traversal via the call stack (`R`), assigning elements in reverse order (from last to first) before truncating the source length to zero.
[==============================================================================}
function MArrayHelper.Evacuate: MArray; overload;
  procedure R(index: Integer);
  begin
    if (index > High(Self)) then
      Exit;
    R(Index + 1);
    Result[Index] := Self[Index];
  end;
begin
  if (Result.SetSize(Self.Length) > 0) then
    R(0);
  SetLength(Self, 0);
end;

{==============================================================================]
  <Loot>
  @action: Instantly transfers ownership of the array data to the caller and zeroes out the source array.
  @note: Uses a zero-cost pointer swap via an uninitialized local variable (`e`) to clear the source without freeing or reallocating memory.
[==============================================================================}
function MArrayHelper.Loot: MArray; overload;
var
  e: MArray;
begin
  Result := Self;
  Self := e;
end;

{==============================================================================]
  <Withdraw>
  @action: Takes ownership of the array's underlying reference, then finalizes
    `Self`, releasing its hold on the data.
  @note: Because dynamic arrays are reference-counted, `Result := Self` does
    not copy the elements — it merely adds a reference. `Finalize(Self)`
    then decrements Self's reference and resets it to `nil`, leaving
    `Result` as the sole owner of the original buffer. This is a true
    move (no element-copying), distinct from `Drain`, which explicitly
    duplicates the contents via `Copy` before emptying `Self`.
[==============================================================================}
function MArrayHelper.Withdraw: MArray; overload;
begin
  Result := Self;
  Finalize(Self);
end;
{$ENDIF}
