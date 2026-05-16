{$IFDEF METHODS}
function Normalize: TBox; overload;
function Normalized: TBox; overload;
function Normally: TBox; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Normalize>
  @action: Returns a new box with X1<=X2 and Y1<=Y2.
  @note: Non-destructive - useful for sanitizing input.
[==============================================================================}
function TBox.Normalize: TBox; overload;
begin
  Result.X1 := Min(Self.X1, Self.X2);
  Result.X2 := Max(Self.X1, Self.X2);
  Result.Y1 := Min(Self.Y1, Self.Y2);
  Result.Y2 := Max(Self.Y1, Self.Y2);
end;

{==============================================================================]
  <Normalized>
  @action: Returns a normalized copy of the bounding box where X1 <= X2 and 
           Y1 <= Y2, ensuring valid dimensions for geometric operations.
  @note: Maps coordinate inversion states into a 2-character stack-allocated
         binary string ('00' to '11') to selectively swap inverted axes using 
         a compile-time constant lookup and a string case evaluation.
[==============================================================================}
function TBox.Normalized: TBox; overload;
const
  BOOL_CHAR: array[Boolean] of Char = ('0', '1');
begin
  case (BOOL_CHAR[Self.X1 > Self.X2] + BOOL_CHAR[Self.Y1 > Self.Y2]) of
    '01':
    begin
      Result.X1 := Self.X1;
      Result.Y1 := Self.Y2;
      Result.X2 := Self.X2;
      Result.Y2 := Self.Y1;
    end;
    '10':
    begin
      Result.X1 := Self.X2;
      Result.Y1 := Self.Y1;
      Result.X2 := Self.X1;
      Result.Y2 := Self.Y2;
    end;
    '11':
    begin
      Result.X1 := Self.X2;
      Result.Y1 := Self.Y2;
      Result.X2 := Self.X1;
      Result.Y2 := Self.Y1;
    end;
  else
    Result := Self;
  end;
end;

{==============================================================================]
  <Normally>
  @action: Returns a normalized copy of the bounding box by ensuring the 
           starting coordinates (X1, Y1) represent the true top-left corner 
           and the ending coordinates (X2, Y2) represent the bottom-right.
  @note: Uses independent conditional checks for each axis and relies on 
         a 'Swap' routine to flip coordinates in-place if they are inverted, 
         making it highly efficient and easy to read.
[==============================================================================}
function TBox.Normally: TBox; overload;
begin
  Result := Self;
  if (Result.X1 > Result.X2) then
    Swap(Result.X1, Result.X2);
  if (Result.Y1 > Result.Y2) then
    Swap(Result.Y1, Result.Y2);
end;
{$ENDIF}
