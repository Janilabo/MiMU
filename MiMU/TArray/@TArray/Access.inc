{$IFDEF HELPERS}
function Head: MType; overload;
function Head(out item: MType): Integer; overload;
function Tail: MType; overload;
function Tail(out item: MType): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Head>
  @action: Returns the first element (index 0) of the array.
  @note: Unguarded O(1) read, caller MUST guarantee Length > 0 to avoid Access Violation.
[==============================================================================}
function MArrayHelper.Head: MType; overload;
begin
  Result := Self[0];
end;

{==============================================================================]
  <Head>
  @action: Extracts the first element (index 0) into 'item' and returns 0.
  @note: Guarded O(1) execution. Returns -1 and leaves 'item' unassigned if array is empty.
[==============================================================================}
function MArrayHelper.Head(out item: MType): Integer; overload;
begin
  Result := Min(0, High(Self));
  if (Result > -1) then
    item := Self[Result];
end;

{==============================================================================]
  <Tail>
  @action: Returns the last element (index High(Self)) of the array.
  @note: Unguarded O(1) read, caller MUST guarantee Length > 0 to avoid Access Violation.
[==============================================================================}
function MArrayHelper.Tail: MType; overload;
begin
  Result := Self[High(Self)];
end;

{==============================================================================]
  <Tail>
  @action: Extracts the last element (index High) into 'item' and returns High(Self).
  @note: Guarded O(1) execution. Returns -1 and leaves 'item' unassigned if array is empty.
[==============================================================================}
function MArrayHelper.Tail(out item: MType): Integer; overload;
begin
  Result := High(Self);
  if (Result > -1) then
    item := Self[Result];
end;
{$ENDIF}