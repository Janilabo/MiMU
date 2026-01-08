{$IFDEF METHODS}
function Build(const index1, index2: Integer): TConnection; overload; cdecl;
class function Construct(const index1, index2: Integer): TConnection; overload; cdecl; static;
constructor Create(const index1, index2: Integer); overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function TConnection.Build(const index1, index2: Integer): TConnection; overload; cdecl;
begin
  Self.id1 := index1;
  Self.id2 := index2;
  Result := Self;
end;

class function TConnection.Construct(const index1, index2: Integer): TConnection; overload; cdecl;
begin
  Result.id1 := index1;
  Result.id2 := index2;
end;

{==============================================================================]
  <Create>
  @action: Creates TConnection with index1 and index2.
  @note: None.
[==============================================================================}
constructor TConnection.Create(const index1, index2: Integer); overload;
begin
  Self.id1 := index1;
  Self.id2 := index2;
end;
{$ENDIF}