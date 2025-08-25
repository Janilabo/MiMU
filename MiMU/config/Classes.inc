{$I Defines.inc}

{$IFDEF T1D}
  class function Create(const item: TVar; const aSize: Integer = 1): TArr; overload; cdecl;
{$ENDIF}

{$IFDEF T2D}
  class function Create(const item: TVar; const size1D: Integer = 1; const size2D: Integer = 1): T2DArr; overload; cdecl;
{$ENDIF}
