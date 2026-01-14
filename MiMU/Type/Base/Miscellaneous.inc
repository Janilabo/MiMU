{$IFDEF FUNCTIONS}
function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload;
function Swap(var A, B: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload;
begin
  if state then
    Result := sTrue
  else
    Result := sFalse;
end;

function Swap(var A, B: MType): Boolean; overload;
var
  C: MType;
begin
  Result := (A <> B);
  C := A;
  A := B;
  B := C;
end;
{$ENDIF}