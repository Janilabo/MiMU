{$IFDEF HELPERS}
function Circumferences: TIntegerArray; overload;
function Perims: TIntegerArray; overload;
function Perimeters: TIntegerArray; overload;
function Perimetrals: TIntegerArray; overload;
function Perimetrics: TIntegerArray; overload;
function Perimetrys: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Circumferences>
  @action: Returns an array containing the circumference calculation for each box in the array.
  @note: Uses bitwise shifts (`shl 1`) to double the adjusted dimensions (`Width - 1` and `Height - 1`).
[==============================================================================}
function TBoxArrayHelper.Circumferences: TIntegerArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := (((Self[i].Width - 1) shl 1) + ((Self[i].Height - 1) shl 1));
end;

{==============================================================================]
  <Perims>
  @action: Returns perimeter calculations for each box in the array with a degenerate box fallback.
  @note: Uses total area (`w * h`) if width or height is <= 1, otherwise computes `2 * (Pred(w) + Pred(h))`.
[==============================================================================}
function TBoxArrayHelper.Perims: TIntegerArray; overload;
var
  w, h, i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
  begin
    w := Self[i].Width;
    h := Self[i].Height;
    if ((w <= 1) or (h <= 1)) then
      Result[i] := (w * h)
	else
      Result[i] := (2 * (Pred(w) + Pred(h)));
  end;
end;

{==============================================================================]
  <Perimeters>
  @action: Returns perimeter calculations for each box in the array using standard corner-adjusted formulas.
  @note: Uses total area (`w * h`) if width or height is <= 1, otherwise computes `(2 * (w + h)) - 4`.
[==============================================================================}
function TBoxArrayHelper.Perimeters: TIntegerArray; overload;
var
  w, h, i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
  begin
    w := Self[i].Width;
    h := Self[i].Height;
    if ((w <= 1) or (h <= 1)) then
      Result[i] := (w * h)
	else
      Result[i] := ((2 * (w + h)) - 4);
  end;
end;

{==============================================================================]
  <Perimetrals>
  @action: Returns an array containing the total number of distinct pixels forming the outer border shell of each box.
  @note: Computes total area minus inner area using `Max(0, Width - 2) * Max(0, Height - 2)`.
[==============================================================================}
function TBoxArrayHelper.Perimetrals: TIntegerArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := (Self[i].Area - (Max(0, (Self[i].Width - 2)) * Max(0, (Self[i].Height - 2))));
end;

{==============================================================================]
  <Perimetrics>
  @action: Returns perimeter calculations for each box using an edge-summation approach.
  @note: Uses total area (`w * h`) if width or height is <= 1, otherwise computes `(2 * w) + (2 * Max(0, h - 2))`.
[==============================================================================}
function TBoxArrayHelper.Perimetrics: TIntegerArray; overload;
var
  w, h, i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
  begin
    w := Self[i].Width;
    h := Self[i].Height;
    if ((w <= 1) or (h <= 1)) then
      Result[i] := (w * h)
	else
      Result[i] := ((2 * w) + (2 * Max(0, (h - 2))));
  end;
end;

{==============================================================================]
  <Perimetrys>
  @action: Returns border shell size calculations for each box via total area minus interior area subtraction.
  @note: Uses total area if width or height is <= 2, otherwise subtracts the inner core area `(w - 2) * (h - 2)`.
[==============================================================================}
function TBoxArrayHelper.Perimetrys: TIntegerArray; overload;
var
  w, h, i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
  begin
    w := Self[i].Width;
    h := Self[i].Height;
    if ((w <= 2) or (h <= 2)) then
      Result[i] := (w * h)
    else
      Result[i] := ((w * h) - ((w - 2) * (h - 2)));
  end;
end;
{$ENDIF}
