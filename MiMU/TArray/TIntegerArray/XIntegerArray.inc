{$IFDEF TYPES}
XIntegerArray = record
  data: TIntegerArray;
  class operator Explicit(const ext: XIntegerArray): TIntegerArray;
  class function Implicit(const arr: TIntegerArray): XIntegerArray; static;
  function IsEmpty: Boolean;
  function Length: Integer;
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
class operator XIntegerArray.Explicit(const ext: XIntegerArray): TIntegerArray;
begin
  Result := ext.data;
end;

class function XIntegerArray.Implicit(const arr: TIntegerArray): XIntegerArray;
begin
  Result.data := arr;
end;

function XIntegerArray.IsEmpty: Boolean;
begin
  Result := (System.Length(Self.data) = 0);
end;

function XIntegerArray.Length: Integer;
begin
  Result := System.Length(Self.data);
end;
{$ENDIF}
