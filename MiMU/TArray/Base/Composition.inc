{$IFDEF HELPERS}
function Overlay(const items: MArray; const index: Integer; const init: MType): MArray; overload; cdecl;
function Overlay(const items: MArray; const index: Integer = 0): MArray; overload; cdecl;
function Patch(const index: Integer; const items: MArray): Integer; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Overlay>
  @action: Overlays items to array index.
  @note: Returns the array with overlay action.		
[==============================================================================}
function MArrayHelper.Overlay(const items: MArray; const index: Integer; const init: MType): MArray; overload; cdecl;
var
  s, l, r, i, a, j: Integer;
begin
  l := items.Length;
  if (l = 0) then
    Exit(Self.Copy);
  s := Self.Size;
  r := IfThen((index < 0), Max((Abs(index) + s), l), Max(s, (index + l)));
  SetLength(Result, r);
  for i := 0 to (r - 1) do
    if not ((index <= 0) and (i < l)) then
    begin
      j := (i - index);
      if not ((index >= 0) and (j >= 0) and (j < l)) then
      begin
        a := IfThen((index < 0), (i - Abs(index)), i);
        if ((a >= 0) and (a < s)) then
          Result[i] := Self[a]
        else
          Result[i] := init;
      end else
        Result[i] := items[j];
    end else
      Result[i] := items[i];
end;

function MArrayHelper.Overlay(const items: MArray; const index: Integer = 0): MArray; overload; cdecl;
begin
  Result := Self.Overlay(items, index, Default(MType));
end;

{==============================================================================]
  <Patch>
  @action: Simply puts items to array index.
  @note: Uses SetLength incase index + items goes over the current length.
         If index is below 0 it will automatically set max length.
[==============================================================================}
function MArrayHelper.Patch(const index: Integer; const items: MArray): Integer; overload; cdecl;
var
  j, i: Integer;
begin
  if items.Empty then
    Exit(index);
  i := IfThen((index < 0), Self.Size, index);
  Result := (i + items.Size);
  if (Result > Self.Size) then
    SetLength(Self, Result);
  for j := 0 to High(items) do
    Self[i + j] := items[j];
end;
{$ENDIF}