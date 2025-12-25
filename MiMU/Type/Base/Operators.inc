{$IFDEF FUNCTIONS}
function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload; inline;
function Swap(var A, B: MType): Boolean; overload; inline;
{$IFDEF Sortable}
function Swop(var A, B: MType; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B: MType; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function Swap(var A, B: MType): Boolean; overload; inline; var C: MType; {$DEFINE Skeleton_Swap}{$I ../Skeletons.inc}{$UNDEF Skeleton_Swap}

function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload; inline; {$DEFINE Skeleton_IfThen}{$I ../Skeletons.inc}{$UNDEF Skeleton_IfThen}

{$IFDEF Sortable}
function Swop(var A, B: MType; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<MType>(A, B, oAscending); end;
function Swop(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<MType>(A, B, C, oAscending); end;

function Sort(var A, B: MType; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<MType>(A, B, oAscending); end;
function Sort(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<MType>(A, B, C, oAscending); end;
{$ENDIF}
{$ENDIF}