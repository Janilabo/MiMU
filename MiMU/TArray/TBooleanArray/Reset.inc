{$IFDEF HELPERS}
function Reinit: Integer; overload;
{$ENDIF}

{$IFDEF METHODS}
class function Init(var arr: TBooleanArray): Integer; overload; 
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           setting all booleans to False, while keeping the current length unchanged.
  @note: Works safely because Boolean is an unmanaged type (1 byte per element).
[==============================================================================}
function TBooleanArrayHelper.Reinit: Integer; overload;
begin
  Result := Self.Size;
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Boolean)), 0);
end;

class function CBooleanArray.Init(var arr: TBooleanArray): Integer; overload;
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], Result, 0);
end;
{$ENDIF}
