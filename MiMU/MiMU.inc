{$IFNDEF IMPLEMENTATION}
  {$DEFINE TYPES}
  type
  {$I Type/Type.inc}
  {$I TArray/TArray.inc}
  {$i T2DArray/T2DArray.inc}
  {$UNDEF TYPES}

  {$DEFINE OPERATORS}
  {$I Type/Type.inc}
  {$UNDEF OPERATORS}

  {$DEFINE HELPERS}
  type
  {$I Type/Type.inc}
  {$I TArray/TArray.inc}
  {$i T2DArray/T2DArray.inc}
  {$UNDEF HELPERS}

  {$DEFINE FUNCTIONS}
  {$I Type/Type.inc}
  {$I TArray/TArray.inc}
  {$i T2DArray/T2DArray.inc}
  {$I Miscellaneous/Randomness.inc}
  {$UNDEF FUNCTIONS}

  {$DEFINE CLASSES}
  type
  {$DEFINE TBS}
    TBinarySearch = class
    public
    {$I TArray/TArray.inc}
    end;
  {$UNDEF TBS}
  {$DEFINE T1D}
    T1D = class
    public
    {$I TArray/TArray.inc}
    end;
  {$UNDEF T1D}
  {$DEFINE T2D}
    T2D = class
    public
    {$i T2DArray/T2DArray.inc}
    end;
  {$UNDEF T2D}
  {$UNDEF CLASSES}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
  {$I Type/Type.inc}
  {$I TArray/TArray.inc}
  {$i T2DArray/T2DArray.inc}
  {$I Miscellaneous/Randomness.inc}
{$ENDIF}