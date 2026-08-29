{$IFDEF FUNCTIONS}
generic function Swap<T>(var A, B: T): Boolean; overload;
generic function Swappify<T>(var current: T; var target: T): T; overload;
generic function Swop<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
generic function Swop<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
generic function Arrange<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
generic function Arrange<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
generic function Trade<T>(var A, B: T): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Swap>
  @action: Swaps the values of two variables of any type T.
  @note: Returns True if the values were different before the swap, False otherwise.
         Requires that type T supports the <> operator.
[==============================================================================}
generic function Swap<T>(var A, B: T): Boolean; overload;
var
  C: T;
begin
  Result := (A <> B);
  C := A;
  A := B;
  B := C;
end;

{==============================================================================]
  <Swappify>
  @action: Mutually exchanges the values of Current and Target, then returns 
           the original historical value of Current.
  @note: Universal type-safe state-exchange pipeline utilizing generics. 
         Because it captures the pre-swap state of Current as the function result, 
         it enables fluent "fetch-and-replace" assignment chains for any data type.
[==============================================================================}
generic function Swappify<T>(var current: T; var target: T): T; overload;
begin
  Result := current;
  current := target;
  target := Result;
end;

{==============================================================================]
  <Swop>
  @action: Swaps two variables A and B if they are out of order according to the specified ascending flag.
  @note: Returns True if a swap occurred, False otherwise.
[==============================================================================}
generic function Swop<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
var
 S: T;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (B > A)));
  if not Result then
    Exit;
  S := A;
  A := B;
  B := S;
end;

{==============================================================================]
  <Swop>
  @action: Arranges three variables A, B, C in order according to the ascending flag by performing minimal swaps.
  @note: Returns True if any swap occurred, False otherwise.
[==============================================================================}
generic function Swop<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
var
  S: T;
procedure SwapIf(var X, Y: T);
begin
  if ((oAscending and (X > Y)) or ((not oAscending) and (X < Y))) then
  begin
    S := X;
    X := Y;
    Y := S;
    Result := True;
  end;
end;
begin
  Result := False;
  SwapIf(A, B);
  SwapIf(A, C);
  SwapIf(B, C);
end;

{==============================================================================]
  <Arrange>
  @action: Ensures that the two items A and B are in the specified order (ascending or descending).
           Performs a swap if necessary.
  @note: Returns True if a swap occurred, False otherwise.
         This function only arranges the two values; it does not sort arrays or larger collections.
[==============================================================================}
generic function Arrange<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (A < B)));
  if Result then
    specialize Swap<T>(A, B);
end;

{==============================================================================]
  <Arrange>
  @action: Ensures that the three items A, B, and C are arranged relative to each other according
           to the specified order (ascending or descending).
           Performs minimal swaps to enforce ordering between the three items.
  @note: Returns True if any swaps occurred, False otherwise.
         This function does not perform a full sort; it only arranges the three values
         relative to each other.
[==============================================================================}
generic function Arrange<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := (specialize Arrange<T>(A, B) or specialize Arrange<T>(A, C) or specialize Arrange<T>(B, C));
end;

{==============================================================================]
  <Trade>
  @action: Swaps two variables if their memory addresses are different.
  @note: Returns True if a swap occurred, False otherwise.
[==============================================================================}
generic function Trade<T>(var A, B: T): Boolean; overload;
var
  C: T;
begin
  Result := (@A <> @B);
  if Result then
  begin
    C := A;
    A := B;
    B := C;
  end;
end;
{$ENDIF}