{$IFDEF FUNCTIONS}
function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload; cdecl; inline;
function Swap(var A, B: MType): Boolean; overload; cdecl; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload; cdecl; inline;
begin
  if state then
    Result := sTrue
  else
    Result := sFalse;
end;

function Swap(var A, B: MType): Boolean; overload; cdecl; inline;
var
  C: MType;
begin
  Result := (A <> B);
  C := A;
  A := B;
  B := C;
end;
{$ENDIF}