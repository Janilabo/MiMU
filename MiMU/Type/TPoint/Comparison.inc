{$IFDEF METHODS}
function Ahead(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
function Behind(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
function Cmp(const target: TPoint): Integer; overload; cdecl;
function Comp(const target: TPoint): Integer; overload; cdecl;
function Compare(const target: TPoint): Integer; overload; cdecl;
function Compared(const target: TPoint): Integer; overload; cdecl;
function CompareX(const target: TPoint): Integer; cdecl;
function CompareY(const target: TPoint): Integer; cdecl;
function Comparison(const target: TPoint): Integer; overload; cdecl;
function CompX(const target: TPoint): Integer; cdecl;
function CompY(const target: TPoint): Integer; cdecl;
function Higher(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
function Lower(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
function Over(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
function Under(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
function XComp(const target: TPoint): Integer; cdecl; inline;
function XCompare(const target: TPoint): Integer; cdecl;
function YComp(const target: TPoint): Integer; cdecl; inline;
function YCompare(const target: TPoint): Integer; cdecl;
{$ENDIF}

{$IFDEF HELPERS}
function Sign(const target: TPoint): Integer; overload; cdecl; inline;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Compare(const A, B: TPoint): Integer; overload; cdecl;
function Comparison(const A, B: TPoint): Integer; overload; cdecl;
function Max(const A, B: TPoint): TPoint; overload; cdecl;
function Min(const A, B: TPoint): TPoint; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Sign>
  @action: Compares the current TPoint (Self) with a target TPoint and returns
           a directional sign indicating whether the target is greater, equal,
           or smaller than Self.
  @note: Returns:
         1  if Self < target (target is larger → ascending)
         0  if Self = target (no change)
         -1  if Self > target (target is smaller → descending)
         Useful for detecting sequence direction, ordering, or range computation.
[==============================================================================}
function TPointHelper.Sign(const target: TPoint): Integer; overload; cdecl; inline;
begin
  if (Self = target) then
    Result := 0
  else if (Self < target) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Ahead>
  @action: Returns True if Self is "ahead" of the target in scanline order.
  @note: "Ahead" means higher Y (or X if Y equal) for ascending order, opposite for descending.
[==============================================================================}
function TPoint.Ahead(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  if (Self.Y <> target.Y) then
  case oAscending of
    True: Exit(Self.Y > target.Y);
    False: Exit(Self.Y < target.Y);
  end;
  if oAscending then
    Result := (Self.X > target.X)
  else
    Result := (Self.X < target.X);
end;

{==============================================================================]
  <Behind>
  @action: Returns True if Self is "behind" the target in scanline order.
  @note: "Behind" means lower Y (or X if Y equal) for ascending order, opposite for descending.
[==============================================================================}
function TPoint.Behind(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  if (Self.Y <> target.Y) then
  case oAscending of
    True: Exit(Self.Y < target.Y);
    False: Exit(Self.Y > target.Y);
  end;
  if oAscending then
    Result := (Self.X < target.X)
  else
    Result := (Self.X > target.X);
end;

{==============================================================================]
  <Cmp>
  @action: Compares two points lexicographically by X then Y.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both coordinates are equal.
[==============================================================================}
function TPoint.Cmp(const target: TPoint): Integer; overload; cdecl;
begin
  Result := Sign(X - target.X);
  if (Result = 0) then
    Result := Sign(Y - target.Y);
end;

{==============================================================================]
  <Comp>
  @action: Compares two points lexicographically by X then Y.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both coordinates are equal.
[==============================================================================}
function TPoint.Comp(const target: TPoint): Integer; overload; cdecl;
begin
  Result := IfThen((X <> target.X), (Ord(X > target.X) - Ord(X < target.X)), (Ord(Y > target.Y) - Ord(Y < target.Y)));
end;

{==============================================================================]
  <Compare>
  @action: Compares two points lexicographically by X then Y.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both coordinates are equal.
[==============================================================================}
function TPoint.Compare(const target: TPoint): Integer; overload; cdecl;
begin
  if (Self = target) then
    Exit(0);
  if (Self < target) then
    Exit(-1);
  Result := 1;
end;

{==============================================================================]
  <Compared>
  @action: Compares two points lexicographically by X then Y.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both coordinates are equal.
[==============================================================================}
function TPoint.Compared(const target: TPoint): Integer; overload; cdecl;
begin
  if (X <> target.X) then
    Exit(Ord(X > target.X) - Ord(X < target.X));
  if (Y <> target.Y) then
    Exit(Ord(Y > target.Y) - Ord(Y < target.Y));
  Result := 0;
end;

{==============================================================================]
  <CompareX>
  @action: Compares two points by their Y coordinate only.
  @note: - Returns -1 if Self.Y < target.Y, 1 if Self.Y > target.Y, and 0 if equal.
         - The X coordinate is ignored.
[==============================================================================}
function TPoint.CompareX(const target: TPoint): Integer; cdecl;
begin
  Result := (Ord(Self.X > target.X) - Ord(Self.X < target.X));
end;

{==============================================================================]
  <CompareY>
  @action: Compares two points by their Y coordinate only.
  @note: - Returns -1 if Self.Y < target.Y, 1 if Self.Y > target.Y, and 0 if equal.
         - The X coordinate is ignored.
[==============================================================================}
function TPoint.CompareY(const target: TPoint): Integer; cdecl;
begin
  Result := (Ord(Self.Y > target.Y) - Ord(Self.Y < target.Y));
end;

{==============================================================================]
  <Comparison>
  @action: Compares two points lexicographically by X then Y.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both coordinates are equal.
[==============================================================================}
function TPoint.Comparison(const target: TPoint): Integer; overload; cdecl;
begin
  if ((Self.X = target.X) and (Self.Y = target.Y)) then
    Exit(0);
  if (Self.X < target.X) then
    Exit(-1);
  if (Self.X > target.X) then
    Exit(1);
  if (Self.Y < target.Y) then
    Exit(-1);
  if (Self.Y > target.Y) then
    Exit(1);
end;

{==============================================================================]
  <CompX>
  @action: Compares two points by their X coordinate only.
  @note: - Returns -1 if Self.X < target.X, 1 if Self.X > target.X, and 0 if equal.
         - The Y coordinate is ignored.
[==============================================================================}
function TPoint.CompX(const target: TPoint): Integer; cdecl;
begin
  Result := Sign(Self.X - target.X);
end;

{==============================================================================]
  <CompY>
  @action: Compares two points by their Y coordinate only.
  @note: - Returns -1 if Self.Y < target.Y, 1 if Self.Y > target.Y, and 0 if equal.
         - The X coordinate is ignored.
[==============================================================================}
function TPoint.CompY(const target: TPoint): Integer; cdecl;
begin
  Result := Sign(Self.Y - target.Y);
end;

{==============================================================================]
  <Higher>
  @action: Returns True if Self follows target in scanline order.
  @note: Comparison is Y-major, then X; ordering direction is controlled by oAscending.
[==============================================================================}
function TPoint.Higher(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  if (Self.Y <> target.Y) then
    Exit((oAscending and (Self.Y > target.Y)) or ((not oAscending) and (Self.Y < target.Y)));
  Result := ((oAscending and (Self.X > target.X)) or ((not oAscending) and (Self.X < target.X)));
end;

{==============================================================================]
  <Lower>
  @action: Returns True if Self precedes target in scanline order.
  @note: Comparison is Y-major, then X; ordering direction is controlled by oAscending.
[==============================================================================}
function TPoint.Lower(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  if (Self.Y <> target.Y) then
    Exit((oAscending and (Self.Y < target.Y)) or ((not oAscending) and (Self.Y > target.Y)));
  Result := ((oAscending and (Self.X < target.X)) or ((not oAscending) and (Self.X > target.X)));
end;

{==============================================================================]
  <Over>
  @action: Returns True if Self follows target in scanline order.
  @note: Comparison is Y-major then X; ordering direction is controlled by oAscending.
[==============================================================================}
function TPoint.Over(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  if (Self.Y <> target.Y) then
    Result := IfThen(oAscending, (Self.Y > target.Y), (Self.Y < target.Y))
  else
    Result := IfThen(oAscending, (Self.X > target.X), (Self.X < target.X));
end;

{==============================================================================]
  <Under>
  @action: Returns True if Self precedes target in scanline order.
  @note: Comparison is Y-major then X; ordering direction is controlled by oAscending.
[==============================================================================}
function TPoint.Under(const target: TPoint; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  if (Self.Y <> target.Y) then
    Result := IfThen(oAscending, (Self.Y < target.Y), (Self.Y > target.Y))
  else
    Result := IfThen(oAscending, (Self.X < target.X), (Self.X > target.X));
end;

{==============================================================================]
  <XComp>
  @action: Compares two points by their X coordinates only.
  @note: Returns -1 if Self.X < target.X, 1 if Self.X > target.X, or 0 if equal.
[==============================================================================}
function TPoint.XComp(const target: TPoint): Integer; cdecl; inline;
begin
  if (Self.X < target.X) then
    Result := -1
  else
    if (Self.X > target.X) then
	  Result := 1
    else
	  Result := 0;
end;

{==============================================================================]
  <XCompare>
  @action: Compares two points primarily by X coordinate, then by Y as a tiebreaker.
  @note: Useful for X-major ordering or sorting points left-to-right, then top-to-bottom.
[==============================================================================}
function TPoint.XCompare(const target: TPoint): Integer; cdecl;
begin
  if (Self.X < target.X) then
    Exit(-1)
  else
    if (Self.X > target.X) then
      Exit(1)
    else
      if (Self.Y < target.Y) then
        Exit(-1)
      else
        if (Self.Y > target.Y) then
          Exit(1);
  Result := 0;
end;

{==============================================================================]
  <YComp>
  @action: Compares two points by their Y coordinates only.
  @note: Returns -1 if Self.Y < target.Y, 1 if Self.Y > target.Y, or 0 if equal.
[==============================================================================}
function TPoint.YComp(const target: TPoint): Integer; cdecl; inline;
begin
  if (Self.Y < target.Y) then
    Result := -1
  else
    if (Self.Y > target.Y) then
	  Result := 1
    else
	  Result := 0;
end;

{==============================================================================]
  <YCompare>
  @action: Compares two points primarily by Y coordinate, then by X as a tiebreaker.
  @note: Useful for Y-major ordering or sorting points top-to-bottom, then left-to-right.
[==============================================================================}
function TPoint.YCompare(const target: TPoint): Integer; cdecl;
begin
  if (Self.Y < target.Y) then
    Exit(-1)
  else
    if (Self.Y > target.Y) then
      Exit(1)
    else
      if (Self.X < target.X) then
        Exit(-1)
      else
        if (Self.X > target.X) then
          Exit(1);
  Result := 0;
end;

function Compare(const A, B: TPoint): Integer; overload; cdecl;
begin
  if (A.Y < B.Y) then
    Exit(-1);
  if (A.Y > B.Y) then
    Exit(1);
  if (A.X < B.X) then
    Exit(-1);
  if (A.X > B.X) then
    Exit(1);
  Result := 0;
end;

function Comparison(const A, B: TPoint): Integer; overload; cdecl;
begin
  if (A < B) then
    Exit(-1);
  if (A > B) then
    Exit(1);
  Result := 0;
end;

function Max(const A, B: TPoint): TPoint; overload; cdecl;
begin
  if ((A.Y > B.Y) or ((A.Y = B.Y) and (A.X > B.X))) then
    Result := A
  else
    Result := B;
end;

function Min(const A, B: TPoint): TPoint; overload; cdecl;
begin
  if ((A.Y < B.Y) or ((A.Y = B.Y) and (A.X < B.X))) then
    Result := A
  else
    Result := B;
end;
{$ENDIF}