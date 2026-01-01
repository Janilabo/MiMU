{$DEFINE TConnection}{$I ../Defines.inc}

{$IFDEF TYPES}
TConnection = record
  id1, id2: Integer;
  {$DEFINE METHODS}{$I TConnection.pph}{$UNDEF METHODS}
end;
TConnectionCompare = specialize TCompare<TConnection>;
TConnectionArray = array of TConnection;
T2DConnectionArray = array of TConnectionArray;
{$ENDIF}

{$IFDEF HELPERS}
TConnectionHelper = type helper for TConnection
  {$I TConnection.pph}
end;
{$ENDIF}

{$IF DEFINED(OPERATORS) OR DEFINED(IMPLEMENTATION)}
{$I Operators.inc}
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I TConnection.pph}
{$ENDIF}

{$UNDEF TConnection}
