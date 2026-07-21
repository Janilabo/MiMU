{$IFDEF METHODS}
function Employ(const source: TRange): Integer; overload;
function Ply(const source: TRange): Integer; overload;
function Use(const source: TRange): Integer; overload;
function Wield(const source: TRange): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Employ>
  @action: Initializes the current range instance with the boundaries of a source 
           range and returns its calculated size.
  @note: Leverages method chaining (fluent interface) by calling Self.Init(source). 
         Be aware that this operation mutates the state of the current instance 
         before reading its Size property.
[==============================================================================}
function TRange.Employ(const source: TRange): Integer; overload;
begin
  Result := Self.Init(source).Size;
end;

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

{==============================================================================]
  <Use>
  @action: Overwrites the current range with the values from a source range 
           and returns its calculated size.
  @note: Directly assigns the source record to Self before evaluating Size. 
         Relies on direct record assignment rather than invoking an Init method.
[==============================================================================}
function TRange.Use(const source: TRange): Integer; overload;
begin
  Self := source;
  Result := Self.Size;
end;

{==============================================================================]
  <Use>
  @action: Re-initializes the current range instance using its constructor with 
           a source range and returns its calculated size.
  @note: Invokes Self.Create(source) to reset/reconstruct the instance in-place 
         before reading its Size property.
[==============================================================================}
function TRange.Wield(const source: TRange): Integer; overload;
begin
  Self.Create(source);
  Result := Self.Size;
end;
{$ENDIF}
