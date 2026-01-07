{$IFDEF TYPES}
XIntegerArray = record
  data: TIntegerArray;

  class function Implicit(const arr: TIntegerArray): XIntegerArray; static;
  class operator Explicit(const ext: XIntegerArray): TIntegerArray;
    
  function Length: Integer;
  function IsEmpty: Boolean;
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
class function XIntegerArray.Implicit(const arr: TIntegerArray): XIntegerArray;
begin
  Result.data := arr;
end;

class operator XIntegerArray.Explicit(const ext: XIntegerArray): TIntegerArray;
begin
  Result := ext.data;
end;

function XIntegerArray.Length: Integer;
begin
  Result := System.Length(Self.data);
end;

function XIntegerArray.IsEmpty: Boolean;
begin
  Result := (System.Length(Self.data) = 0);
end;
{$ENDIF}
