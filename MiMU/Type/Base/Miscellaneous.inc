{$IFDEF FUNCTIONS}
function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload; inline;
function Swap(var A, B: MType): Boolean; overload; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload; inline;
begin
  if state then
    Result := sTrue
  else
    Result := sFalse;
end;

function Swap(var A, B: MType): Boolean; overload; inline;
var
  C: MType;
begin
  Result := (A <> B);
  C := A;
  A := B;
  B := C;
end;
{$ENDIF}