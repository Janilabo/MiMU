{$DEFINE TBox}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
{$I Enumerator.inc}
TBox = record
  X1, Y1, X2, Y2: Integer;
  function GetEnumerator: TBoxEnumerator;
  {$DEFINE METHODS}{$I TBox.pph}{$UNDEF METHODS}  
end;
TBoxCompare = specialize TCompare<TBox>;
TBoxArray = array of TBox;
T2DBoxArray = array of TBoxArray;
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TBoxHelper = type helper for TBox
  {$I ../Type.inc}
  {$I TBox.pph}
end;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Type.inc}
{$I TBox.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I Enumerator.inc}

function TBox.GetEnumerator: TBoxEnumerator;
begin
  Result.Init(X1, Y1, X2, Y2);
end;
{$ENDIF}

{$UNDEF BASE}{$UNDEF TBox}
