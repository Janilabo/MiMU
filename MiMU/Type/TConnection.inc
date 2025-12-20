{$DEFINE TConnection}{$I Configuration\Defines.inc}

{$IFDEF TYPES}
TConnection = record
  id1, id2: Integer;
  constructor Create(const index1, index2: Integer); overload;
  class function Construct(const index1, index2: Integer): TConnection; overload; static;
  function Build(const index1, index2: Integer): TConnection; overload;
end;
{$I Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TConnectionHelper = type helper for TConnection
  {$I Core.inc}
end;
{$ENDIF}

{$IFDEF OPERATORS}  
operator =(const a, b: TConnection): Boolean;
operator <>(const a, b: TConnection): Boolean;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I Core.inc}
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

operator =(const a, b: TConnection): Boolean;
begin
  Result := ((a.id1 = b.id1) and (a.id2 = b.id2));
end;

operator <>(const a, b: TConnection): Boolean;
begin
  Result := not (a = b);
end;
{$ENDIF}

{$UNDEF TConnection}