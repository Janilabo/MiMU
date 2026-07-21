{$IFDEF METHODS}
function Ply(const source: TRange): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ply>
  @action: Copies source's start and stop bounds into Self, adopting its range
  @note: Since TRange is a value type (plain start/stop fields), this is a
         full field copy. Self and source remain fully independent after
         this call.
[==============================================================================}
function TRange.Ply(const source: TRange): Integer; overload;
begin
  Self.start := source.start;
  Self.stop := source.stop;
  Result := Self.Size;
end;
{$ENDIF}
