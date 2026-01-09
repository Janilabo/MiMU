{$IFDEF FUNCTIONS}
{$IFDEF Sortable}
function Sort(var A, B: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
function Sort(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
function Swop(var A, B: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
function Swop(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
{$ENDIF}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$IFDEF Sortable}
function Sort(var A, B: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (A < B)));
  if Result then
    Swap(A, B);
end;

function Sort(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
  function DoSwap(var X, Y: MType): Boolean;
  var
    Z: MType;
  begin
    Z := X;
    X := Y;
    Y := Z;
    Result := True;
  end;
begin
  Result := False;
  if ((oAscending and (A > B)) or ((not oAscending) and (A < B))) then
    Result := DoSwap(A, B);
  if ((oAscending and (A > C)) or ((not oAscending) and (A < C))) then
    Result := DoSwap(A, C);
  if ((oAscending and (B > C)) or ((not oAscending) and (B < C))) then
    Result := DoSwap(B, C);
end;

function Swop(var A, B: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
var
 S: MType;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (B > A)));
  if not Result then
    Exit;
  S := A;
  A := B;
  B := S;
end;

function Swop(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
var
  S: MType;
procedure SwapIf(var X, Y: MType);
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
{$ENDIF}
{$ENDIF}