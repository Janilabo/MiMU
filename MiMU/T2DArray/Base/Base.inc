{$IFDEF HELPERS}
{$I Base.pph}
{$ENDIF}

{$IFDEF T2D}
class function Create(const item: MType; const size1D: Integer = 1; const size2D: Integer = 1): M2DArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I Base.pph}

{==============================================================================]
  <Create>
  @action: Creates array with item where size is length of the array.
  @note: item is placed on every index in result.
[==============================================================================}
class function T2D.Create(const item: MType; const size1D: Integer = 1; const size2D: Integer = 1): M2DArray; overload; cdecl;
var
  i, j, s: Integer;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;
{$ENDIF}
