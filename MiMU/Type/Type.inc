{$IF DEFINED(CLASSES) OR DEFINED(FUNCTIONS) OR DEFINED(HELPERS) OR DEFINED(IMPLEMENTATION)}
{$I Type.pph}
{$ENDIF}

{$IFDEF TYPES}
MPredicate = function(const item: MType): Boolean is nested;
{$ENDIF}