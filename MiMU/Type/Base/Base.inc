{$IFDEF TYPES}
MCompare = specialize TCompare<MType>;
MArray = array of MType;
M2DArray = array of MArray;
{$ENDIF}

{$IF DEFINED(CLASSES) OR DEFINED(FUNCTIONS) OR DEFINED(HELPERS) OR DEFINED(IMPLEMENTATION)}
{$I Base.pph}
{$ENDIF}