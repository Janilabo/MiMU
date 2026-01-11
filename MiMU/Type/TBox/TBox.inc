{$DEFINE TBox}{$I ../Defines.inc}

{$IFDEF TYPES}
{$I Enumerator.inc}
TBox = record
  X1, Y1, X2, Y2: Integer;
  {$UNDEF TYPES}{$DEFINE METHODS}{$I TBox.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
TBoxCompare = specialize TCompare<TBox>;
TBoxArray = array of TBox;
T2DBoxArray = array of TBoxArray;
{$ENDIF}

{$IFDEF HELPERS}
TBoxHelper = type helper for TBox
  {$I TBox.pph}
end;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I TBox.pph}
{$ENDIF}

{$UNDEF TBox}
