{$DEFINE string}{$I ../Defines.inc}

{$IFDEF TYPES}
TStringCompare = function(const A, B: string): Integer;
TStringArray = array of string;
T2DStringArray = array of TStringArray;
{$ENDIF}

{$IFDEF HELPERS}
TStringHelper = type helper for string
  {$I String.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I String.pph}
{$ENDIF}

{$UNDEF string}
