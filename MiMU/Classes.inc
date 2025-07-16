{$I Defines.inc}

{$IFDEF T1D}
  class function Resize(var arr: XArr; const aChange: Integer): Integer; overload; cdecl;
  class function Resize(var arr: XArr; const aChange: Integer; const null: XVar): Integer; overload; cdecl;
{$ENDIF}

{$IFDEF T2D}
  class function Create(const size1D, size2D: Integer; const item: XVar): X2DArr; overload; cdecl;
{$ENDIF}
