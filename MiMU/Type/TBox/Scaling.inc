{$IFDEF METHODS}
function Expand(const change: Integer = 1): TBox; overload; 
function Expand(const target: TBox): TBox; overload; 
function Shrink(const change: Integer = 1): TBox; overload; 
function Shrink(const target: TBox): TBox; overload; 
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Expand>
  @action: Returns bx that has been expanded fully by change.
  @note: Works with positive values only.
[==============================================================================}
function TBox.Expand(const change: Integer = 1): TBox; overload;
begin
  if (change < 1) then
    Exit(Self);
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

function TBox.Expand(const target: TBox): TBox; overload;
begin
  Result.X1 := Min(Self.X1, target.X1);
  Result.Y1 := Min(Self.Y1, target.Y1);
  Result.X2 := Max(Self.X2, target.X2);
  Result.Y2 := Max(Self.Y2, target.Y2);
end;

{==============================================================================]
  <Shrink>
  @action: Returns bx that has been shrinked fully by change.
  @note: Works with positive values only. UNSAFE method, no checks!
[==============================================================================}
function TBox.Shrink(const change: Integer = 1): TBox; overload;
begin
  if (change < 1) then
    Exit(Self);
  Result.X1 := (Self.X1 + change);
  Result.Y1 := (Self.Y1 + change);
  Result.X2 := (Self.X2 - change);
  Result.Y2 := (Self.Y2 - change);
end;

function TBox.Shrink(const target: TBox): TBox; overload;
begin
  Result.X1 := Max(Self.X1, target.X1);
  Result.Y1 := Max(Self.Y1, target.Y1);
  Result.X2 := Min(Self.X2, target.X2);
  Result.Y2 := Min(Self.Y2, target.Y2);
end;
{$ENDIF}