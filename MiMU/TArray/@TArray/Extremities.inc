{$IFDEF HELPERS}
function Bookendify(const aPrefix, aSuffix: MArray): Integer; overload;

function Bookended(const aPrefix, aSuffix: MArray): Boolean; overload;

function Prefixem(const aPrefix: MArray): Boolean; overload;
function Prefixy(const aPrefix: MArray): Boolean; overload;
function Suffixem(const aSuffix: MArray): Boolean; overload;
function Suffixy(const aSuffix: MArray): Boolean; overload;

function Limitem(const aFix: MType): Boolean; overload;
function Limitem(const aFix: MArray): Boolean; overload;
function Marginatem(const aFix: MArray): Boolean; overload;
function Marginates(const aFix: MArray): Boolean; overload;
function Marginatez(const aFix: MArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================
  <Bookendify>
  @action: Checks if the array is bookended by aPrefix and aSuffix.
  @note: Returns -1 on failure. On success, returns the exact length of the
         inner payload residing between the prefix and suffix.
==============================================================================}
function MArrayHelper.Bookendify(const aPrefix, aSuffix: MArray): Integer; overload;
var
  p, s, l: Integer;
begin
  p := aPrefix.Length;
  s := aSuffix.Length;
  l := Self.Length;
  if ((p + s) > l) then
    Exit(-1);
  if not Self.Prefixem(aPrefix) or not Self.Suffixem(aSuffix) then
    Exit(-1);
  Result := (l - p - s);
end;

{==============================================================================
  <Bookended>
  @action: Returns True if the array starts with the specified aPrefix sequence 
           and ends with the specified aSuffix sequence.
  @note: Ensures combined lengths do not exceed array bounds to prevent overlap, 
         then composes Prefixy and Suffixy for optimal short-circuiting.
==============================================================================}
function MArrayHelper.Bookended(const aPrefix, aSuffix: MArray): Boolean; overload;
begin
  Result := (((aPrefix.Length + aSuffix.Length) <= Self.Length) and Self.Prefixy(aPrefix) and Self.Suffixy(aSuffix));
end;

{==============================================================================
  <Prefixem>
  @action: Returns True if the array starts with the specified sub-array sequence.
  @note: Performs an early-exit index-by-index comparison of the prefix.
==============================================================================}
function MArrayHelper.Prefixem(const aPrefix: MArray): Boolean; overload;
var
  l, i: Integer;
begin
  l := aPrefix.Length;
  if ((l = 0) or (l > Self.Length)) then
    Exit(False);
  for i := 0 to (l - 1) do
    if (Self[i] <> aPrefix[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================
  <Prefixy>
  @action: Returns True if the array starts with the specified sub-array sequence.
  @note: Streamlined verb-transform variant designed for compositional pipelines; 
         assumes prior or internal sizing validity.
==============================================================================}
function MArrayHelper.Prefixy(const aPrefix: MArray): Boolean; overload;
var
  l, i: Integer;
begin
  for i := 0 to High(aPrefix) do
    if (Self[i] <> aPrefix[i]) then
      Exit(False);
  Result := (aPrefix.Length > 0);
end;

{==============================================================================
  <Suffixem>
  @action: Returns True if the array ends with the specified sub-array sequence.
  @note: Performs an early-exit index-by-index comparison of the suffix.
==============================================================================}
function MArrayHelper.Suffixem(const aSuffix: MArray): Boolean; overload;
var
  l, s, i: Integer;
begin
  l := aSuffix.Length;
  s := Self.Length;
  if ((l = 0) or (l > s)) then
    Exit(False);
  for i := 0 to (l - 1) do
    if (Self[s - l + i] <> aSuffix[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================
  <Suffixy>
  @action: Returns True if the array ends with the specified sub-array sequence.
  @note: Streamlined verb-transform variant designed for compositional pipelines; 
         computes offset indices dynamically from the tail.
==============================================================================}
function MArrayHelper.Suffixy(const aSuffix: MArray): Boolean; overload;
var
  l, s, i: Integer;
begin
  l := aSuffix.Length;
  s := Self.Length;
  for i := 0 to (l - 1) do
    if (Self[s - l + i] <> aSuffix[i]) then
      Exit(False);
  Result := (l > 0);
end;

{==============================================================================
  <Limitem>
  @action: Checks if the given aFix matches either the first or last element of the array.
  @note: Uses case branching on High(Self).Compare(0) to efficiently handle empty, single-element, and multi-element arrays.
==============================================================================}
function MArrayHelper.Limitem(const aFix: MType): Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  case h.Compare(0) of
    -1: Result := False;
     0: Result := (Self[0] = aFix);
     1: Result := ((Self[0] = aFix) or (Self[h] = aFix));
  end;
end;

{==============================================================================
  <Limitem>
  @action: Returns True if the beginning (prefix) or the ending (suffix) of the
           array exactly equals the provided sub-array aFix.
  @note: Verifies sequence equality against the outer boundaries of the array.
==============================================================================}
function MArrayHelper.Limitem(const aFix: MArray): Boolean; overload;
var
  l, s, i: Integer;
begin
  l := aFix.Length;
  if (l = 0) then
    Exit(False);
  s := Self.Length;
  if (l > s) then
    Exit(False);
  Result := True;
  for i := 0 to (l - 1) do
    if (Self[i] <> aFix[i]) then
    begin
      Result := False;
      Break;
    end;
  if not Result then
  for i := 0 to (l - 1) do
    if (Self[s - l + i] <> aFix[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================
  <Marginatem>
  @action: Returns True if the beginning (prefix) or ending (suffix) of the array 
           exactly matches the specified sub-array aFix.
  @note: Employs a high-performance dual-scan loop using integer helper increments 
         to check both boundaries simultaneously, short-circuiting early or 
         pivoting to a single-track scan when a candidate fails.
==============================================================================}
function MArrayHelper.Marginatem(const aFix: MArray): Boolean; overload;
var
  k, l, i: Integer;
  p, s: Boolean;
begin
  k := aFix.Length;
  l := Self.Length;
  if ((k = 0) or (k > l)) then
    Exit(False);
  p := True;
  s := True;
  i := -1;
  while (i.Increment < k) do
  begin
    if (Self[i] <> aFix[i]) then
      p := False;
    if (Self[l - k + i] <> aFix[i]) then
      s := False;
    if not p and not s then
      Exit(False);
    if not p then
    begin
      while (i.Increment < k) do
        if (Self[l - k + i] <> aFix[i]) then
          Exit(False);
      Exit(True);
    end;
    if not s then
    begin
      while (i.Increment < k) do
        if (Self[i] <> aFix[i]) then
          Exit(False);
      Exit(True);
    end;
  end;
  Result := (p or s);
end;

{==============================================================================
  <Marginates>
  @action: Returns True if the beginning (prefix) or ending (suffix) of the array 
           exactly matches the specified sub-array aFix.
  @note: Evaluates the prefix first. If the prefix does not fully match, it 
         seamlessly falls back to validate the suffix in a unified flow.
==============================================================================}
function MArrayHelper.Marginates(const aFix: MArray): Boolean; overload;
var
  l, s, i, r: Integer;
begin
  l := aFix.Length;
  if (l = 0) then
    Exit(False);
  s := Self.Length;
  if (l > s) then
    Exit(False);
  r := 0;
  for i := 0 to (l - 1) do
    if (Self[i] <> aFix[i]) then
      Break
    else
      Inc(r);
  if not (r = l) then
  for i := 0 to (l - 1) do
    if (Self[s - l + i] <> aFix[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================
  <Marginatez>
  @action: Returns True if the beginning (prefix) or ending (suffix) of the array 
           exactly matches the specified sub-array aFix.
  @note: Uses a Merge-style dual-scan first loop for both tracks, then hands off 
         to a single-track continuation for whichever candidate remains plausible.
==============================================================================}
function MArrayHelper.Marginatez(const aFix: MArray): Boolean; overload;
var
  k, l, i: Integer;
  p, s: Boolean;
begin
  k := aFix.Length;
  l := Self.Length;
  if ((k = 0) or (k > l)) then
    Exit(False);
  p := True;
  s := True;
  i := -1;
  while (i.Increment < k) do
  begin
    if (p and (Self[i] <> aFix[i])) then
      p := False;
    if (s and (Self[l - k + i] <> aFix[i])) then
      s := False;
    if not p and not s then
      Exit(False);
    if not p or not s then
      Break;
  end;
  if not p and s then
  begin
    while (i.Increment < k) do
      if (Self[l - k + i] <> aFix[i]) then
        Exit(False);
    Exit(True);
  end;
  if p and not s then
  begin
    while (i.Increment < k) do
      if (Self[i] <> aFix[i]) then
        Exit(False);
    Exit(True);
  end;
  Result := (p or s);
end;
{$ENDIF}
