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
  Result := specialize Sort<MType>(A, B, oAscending);
end;

function Sort(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := specialize Sort<MType>(A, B, C, oAscending);
end;

function Swop(var A, B: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := specialize Swop<MType>(A, B, oAscending);
end;

function Swop(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := specialize Swop<MType>(A, B, C, oAscending);
end;
{$ENDIF}
{$ENDIF}