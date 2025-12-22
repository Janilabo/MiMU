{$IFDEF TYPES}
constructor Create(const index1, index2: Integer); overload;
class function Construct(const index1, index2: Integer): TConnection; overload; static;
function Build(const index1, index2: Integer): TConnection; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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

class function TConnection.Construct(const index1, index2: Integer): TConnection; overload;
begin
  Result.id1 := index1;
  Result.id2 := index2;
end;

function TConnection.Build(const index1, index2: Integer): TConnection; overload;
begin
  Self.id1 := index1;
  Self.id2 := index2;
  Result := Self;
end;
{$ENDIF}