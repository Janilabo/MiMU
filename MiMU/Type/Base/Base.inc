{$IFDEF TYPES}
MCompare = specialize TCompare<MType>;
MArray = array of MType;
M2DArray = array of MArray;
{$ENDIF}

{$IF DEFINED(HELPERS) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I Base.pph}
{$ENDIF}