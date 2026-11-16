{$IFDEF HELPERS}
function Prefixem(const item: MArray): Boolean; overload;
function Suffixem(const item: MArray): Boolean; overload;

function Limitem(const item: MType): Boolean; overload;
function Limitem(const item: MArray): Boolean; overload;
function Marginatem(const item: MArray): Boolean; overload;
function Marginates(const item: MArray): Boolean; overload;
function Marginatez(const item: MArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================
  <Prefixem>
  @action: Returns True if the array starts with the specified sub-array sequence.
  @note: Performs an early-exit index-by-index comparison of the prefix.
==============================================================================}
function MArrayHelper.Prefixem(const item: MArray): Boolean; overload;
var
  l, i: Integer;
begin
  l := item.Length;
  if ((l = 0) or (l > Self.Length)) then
    Exit(False);
  for i := 0 to (l - 1) do
    if (Self[i] <> item[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================
  <Suffixem>
  @action: Returns True if the array ends with the specified sub-array sequence.
  @note: Performs an early-exit index-by-index comparison of the suffix.
==============================================================================}
function MArrayHelper.Suffixem(const item: MArray): Boolean; overload;
var
  l, s, i: Integer;
begin
  l := item.Length;
  s := Self.Length;
  if ((l = 0) or (l > s)) then
    Exit(False);
  for i := 0 to (l - 1) do
    if (Self[s - l + i] <> item[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================
  <Limitem>
  @action: Checks if the given item matches either the first or last element of the array.
  @note: Uses case branching on High(Self).Compare(0) to efficiently handle empty, single-element, and multi-element arrays.
==============================================================================}
function MArrayHelper.Limitem(const item: MType): Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  case h.Compare(0) of
    -1: Result := False;
     0: Result := (Self[0] = item);
     1: Result := ((Self[0] = item) or (Self[h] = item));
  end;
end;

{==============================================================================
  <Limitem>
  @action: Returns True if the beginning (prefix) or the ending (suffix) of the
           array exactly equals the provided sub-array item.
  @note: Verifies sequence equality against the outer boundaries of the array.
==============================================================================}
function MArrayHelper.Limitem(const item: MArray): Boolean; overload;
var
  l, s, i: Integer;
begin
  l := item.Length;
  if (l = 0) then
    Exit(False);
  s := Self.Length;
  if (l > s) then
    Exit(False);
  Result := True;
  for i := 0 to (l - 1) do
    if (Self[i] <> item[i]) then
    begin
      Result := False;
      Break;
    end;
  if not Result then
  for i := 0 to (l - 1) do
    if (Self[s - l + i] <> item[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================
  <Marginatem>
  @action: Returns True if the beginning (prefix) or ending (suffix) of the array 
           exactly matches the specified sub-array item.
  @note: Employs a high-performance dual-scan loop using integer helper increments 
         to check both boundaries simultaneously, short-circuiting early or 
         pivoting to a single-track scan when a candidate fails.
==============================================================================}
function MArrayHelper.Marginatem(const item: MArray): Boolean; overload;
var
  k, l, i: Integer;
  p, s: Boolean;
begin
  k := item.Length;
  l := Self.Length;
  if ((k = 0) or (k > l)) then
    Exit(False);
  p := True;
  s := True;
  i := -1;
  while (i.Increment < k) do
  begin
    if (Self[i] <> item[i]) then
      p := False;
    if (Self[l - k + i] <> item[i]) then
      s := False;
    if not p and not s then
      Exit(False);
    if not p then
    begin
      while (i.Increment < k) do
        if (Self[l - k + i] <> item[i]) then
          Exit(False);
      Exit(True);
    end;
    if not s then
    begin
      while (i.Increment < k) do
        if (Self[i] <> item[i]) then
          Exit(False);
      Exit(True);
    end;
  end;
  Result := (p or s);
end;

{==============================================================================
  <Marginates>
  @action: Returns True if the beginning (prefix) or ending (suffix) of the array 
           exactly matches the specified sub-array item.
  @note: Evaluates the prefix first. If the prefix does not fully match, it 
         seamlessly falls back to validate the suffix in a unified flow.
==============================================================================}
function MArrayHelper.Marginates(const item: MArray): Boolean; overload;
var
  l, s, i, r: Integer;
begin
  l := item.Length;
  if (l = 0) then
    Exit(False);
  s := Self.Length;
  if (l > s) then
    Exit(False);
  r := 0;
  for i := 0 to (l - 1) do
    if (Self[i] <> item[i]) then
      Break
    else
      Inc(r);
  if not (r = l) then
  for i := 0 to (l - 1) do
    if (Self[s - l + i] <> item[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================
  <Marginatez>
  @action: Returns True if the beginning (prefix) or ending (suffix) of the array 
           exactly matches the specified sub-array item.
  @note: Uses a Merge-style dual-scan first loop for both tracks, then hands off 
         to a single-track continuation for whichever candidate remains plausible.
==============================================================================}
function MArrayHelper.Marginatez(const item: MArray): Boolean; overload;
var
  k, l, i: Integer;
  p, s: Boolean;
begin
  k := item.Length;
  l := Self.Length;
  if ((k = 0) or (k > l)) then
    Exit(False);
  p := True;
  s := True;
  i := -1;
  while (i.Increment < k) do
  begin
    if (p and (Self[i] <> item[i])) then
      p := False;
    if (s and (Self[l - k + i] <> item[i])) then
      s := False;
    if not p and not s then
      Exit(False);
    if not p or not s then
      Break;
  end;
  if not p and s then
  begin
    while (i.Increment < k) do
      if (Self[l - k + i] <> item[i]) then
        Exit(False);
    Exit(True);
  end;
  if p and not s then
  begin
    while (i.Increment < k) do
      if (Self[i] <> item[i]) then
        Exit(False);
    Exit(True);
  end;
  Result := (p or s);
end;
{$ENDIF}
