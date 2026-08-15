{$DEFINE Double}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CDoubleArray = class
public
  {$UNDEF TYPES}{$DEFINE METHODS}{$I TDoubleArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
TDoubleArrayHelper = type helper for TDoubleArray
  {$I TDoubleArray.pph}
  function Reinit: Integer; overload;
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I TDoubleArray.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.Reinit: Integer; overload;
begin
  Result := Self.Size;
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Double)), 0);
end;
{$ENDIF}

{$UNDEF Double}
