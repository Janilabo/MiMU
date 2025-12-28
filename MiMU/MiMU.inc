{$IF DEFINED(TYPES) OR DEFINED(HELPERS) OR DEFINED(CLASSES)}
type
{$ENDIF}

{$IF (NOT DEFINED(TBS)) AND (NOT DEFINED(T1D)) AND (NOT DEFINED(T2D))}
  {$I Type/Type.inc}
  {$I Miscellaneous/Randomness.inc}
{$ENDIF}

{$IFNDEF T2D}
  {$IFDEF T1D}
  T1D = class
  public
  {$ENDIF}
  {$IFDEF TBS}
  TBinarySearch = class
  public
  {$ENDIF}
  {$I TArray/TArray.inc}
{$ENDIF}

{$IFNDEF T1D}
  {$IFDEF T2D}
  T2D = class
  public
  {$ENDIF}
  {$i T2DArray/T2DArray.inc}
{$ENDIF}

{$IFDEF CLASSES}
end;
{$ENDIF} 