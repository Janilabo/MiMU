{$IFDEF FUNCTIONS}
{$IFDEF Sortable}
function Swop(var A, B: MType; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B: MType; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$IFDEF Sortable}
function Swop(var A, B: MType; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<MType>(A, B, oAscending); end;
function Swop(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<MType>(A, B, C, oAscending); end;

function Sort(var A, B: MType; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<MType>(A, B, oAscending); end;
function Sort(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<MType>(A, B, C, oAscending); end;
{$ENDIF}
{$ENDIF}