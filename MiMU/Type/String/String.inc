{$DEFINE string}{$I ../Defines.inc}

{$IFDEF TYPES}
TStringCompare = specialize TCompare<string>;
TStringArray = array of string;
T2DStringArray = array of TStringArray;
{$ENDIF}

{$IFDEF HELPERS}
TStringHelper = type helper for string
  {$I ../Base/Base.inc}
  {$I String.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I String.pph}
{$ENDIF}

{$UNDEF string}
