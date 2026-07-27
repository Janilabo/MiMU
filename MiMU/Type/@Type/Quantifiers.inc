{$IFDEF HELPERS}
function IfAll(const items: MArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
function IfAny(const items: MArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
function IfNone(const items: MArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
function IfSome(const items: MArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <InAll>
  @action: Evaluates whether EVERY item in the array equals Self.
  @note: Returns Self if the condition match equals wanted, otherwise returns fallback.
[==============================================================================}
function MTypeHelper.IfAll(const items: MArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  i: MType;
  b: Boolean;
begin
  b := (items.Length > 0);
  for i in items do
    if (i <> Self) then
    begin
      b := False;
      Break;
    end;
  if (b = wanted) then
    Result := Self
  else
    Result := fallback;
end;

{==============================================================================]
  <InAny>
  @action: Evaluates whether AT LEAST ONE item in the array equals Self.
  @note: Returns Self if the condition match equals wanted, otherwise returns fallback.
[==============================================================================}
function MTypeHelper.IfAny(const items: MArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  i: MType;
  b: Boolean;
begin
  b := False;
  for i in items do
    if (i = Self) then
    begin
      b := True;
      Break;
    end;
  if (b = wanted) then
    Result := Self
  else
    Result := fallback;
end;

{==============================================================================]
  <InNone>
  @action: Evaluates whether NO items in the array equal Self.
  @note: Returns Self if the condition match equals wanted, otherwise returns fallback.
[==============================================================================}
function MTypeHelper.IfNone(const items: MArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  i: MType;
  b: Boolean;
begin
  b := True;
  for i in items do
    if (i = Self) then
    begin
      b := False;
      Break;
    end;
  if (b = wanted) then
    Result := Self
  else
    Result := fallback;
end;

{==============================================================================]
  <InSome>
  @action: Evaluates whether SOME (at least one, but not all) items in the array equal Self.
  @note: Returns Self if the condition match equals wanted, otherwise returns fallback.
[==============================================================================}
function MTypeHelper.IfSome(const items: MArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  i: MType;
  m, n: Boolean;
  b: Boolean;
begin
  m := False;
  n := False;
  if (items.Length > 1) then
  for i in items do
  begin
    if (i = Self) then
      m := True
    else
      n := True;
    if (m and n) then
      Break;
  end;
  b := (m and n);
  if (b = wanted) then
    Result := Self
  else
    Result := fallback;
end;
{$ENDIF}
