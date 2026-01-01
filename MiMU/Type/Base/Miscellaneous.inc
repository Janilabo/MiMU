{$IFDEF FUNCTIONS}
function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload; inline;
function Swap(var A, B: MType): Boolean; overload; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function IfThen(const state: Boolean; const sTrue, sFalse: MType): MType; overload; inline; {$DEFINE Skeleton_IfThen}{$I ../Skeletons.inc}{$UNDEF Skeleton_IfThen}

function Swap(var A, B: MType): Boolean; overload; inline; var C: MType; {$DEFINE Skeleton_Swap}{$I ../Skeletons.inc}{$UNDEF Skeleton_Swap}
{$ENDIF}