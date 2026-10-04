{$IFDEF TYPES}
generic TCompare<T> = function(const A, B: T): Integer;
generic TPredicate<T> = function(const item: T): Boolean is nested;
{$ENDIF}

{$IF DEFINED(CLASSES) OR DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION) OR DEFINED(TYPES)}
{$I Generic.pph}
{$ENDIF}