{$I Defines.inc}

{$IFDEF T1D}
  class function Create(const item: XVar; const aSize: Integer = 1): XArr; overload; cdecl;
{$ENDIF}

{$IFDEF T2D}
  class function Create(const item: XVar; const size1D: Integer = 1; const size2D: Integer = 1): X2DArr; overload; cdecl;
{$ENDIF}
