{$IF DEFINED(HELPERS) OR DEFINED(FUNCTIONS)}
{$I TArray.pph}
{$ENDIF}

{$IFDEF CLASSES}
{$IFDEF T1D}
class function Create(const item: MType; const aSize: Integer = 1): MArray; overload;
{$ENDIF}

{$IF DEFINED(TBS) AND DEFINED(Sortable)}
{$I TArray.pph}
{$ENDIF}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I TArray.pph}

{==============================================================================]
  <Create>
  @action: Creates array with item where size is length of the array.
  @note: item is placed on every index in result.
[==============================================================================}
class function T1D.Create(const item: MType; const aSize: Integer = 1): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Max(0, aSize));
  for i := 0 to High(Result) do
    Result[i] := item;
end;
{$ENDIF}
