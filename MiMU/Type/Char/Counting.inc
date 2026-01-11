{$IFDEF HELPERS}
function AmountIn(const target: string): Integer; overload;
function AppearsIn(const target: string): Integer; overload;
function CountIn(const target: string): Integer; overload;
function OccurrencesIn(const target: string): Integer; overload;
function Occurs(const target: string): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AmountIn>
  @action: Returns the number of occurrences of this character in the specified string.
  @note: Uses repeated StrScan calls; efficient when the character occurs infrequently.
[==============================================================================}
function TCharHelper.AmountIn(const target: string): Integer; overload;
var
  P, F: PChar;
begin
  Result := 0;
  if (target = '') then
    Exit;
  P := PChar(target);
  repeat
    F := StrScan(P, Self);
    if (F = nil) then
	  Exit;
    Inc(Result);
    P := (F + 1);
  until False;
end;

{==============================================================================]
  <AppearsIn>
  @action: Returns the number of times this character appears in the specified string.
  @note: Uses a linear scan with loop unrolling for improved performance; operates on code units.
[==============================================================================}
function TCharHelper.AppearsIn(const target: string): Integer; overload;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(target);
  E := (P + Length(target));
  while ((PtrUInt(E) - PtrUInt(P)) > 3) do
  begin
    Inc(Result, (Ord(P[0] = Self) + Ord(P[1] = Self) + Ord(P[2] = Self) + Ord(P[3] = Self)));
    Inc(P, 4);
  end;
  while (P < E) do
  begin
    Inc(Result, Ord(P^ = Self));
    Inc(P);
  end;
end;

{==============================================================================]
  <CountIn>
  @action: Returns the number of occurrences of this character (Self) within
           the specified target string.
  @note: Comparison is case-sensitive. No normalization or locale-specific
         rules are applied.
[==============================================================================}
function TCharHelper.CountIn(const target: string): Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 1 to Length(target) do
    Inc(Result, Ord(target[i] = Self));
end;

{==============================================================================]
  <OccurrencesIn>
  @action: Returns the number of times this character appears in the specified string.
  @note: Performs a linear scan of the string. Operates on code units, not grapheme clusters.
[==============================================================================}
function TCharHelper.OccurrencesIn(const target: string): Integer; overload;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(target);
  E := (P + Length(target));
  while (P < E) do
  begin
    if (P^ = Self) then
      Inc(Result);
    Inc(P);
  end;
end;

{==============================================================================]
  <Occurs>
  @action: Returns the number of times this character appears in the specified string.
  @note: Performs a linear scan of the string. Operates on code units, not grapheme clusters.
[==============================================================================}
function TCharHelper.Occurs(const target: string): Integer; overload;
var
  P, E: PChar;
begin
  Result := 0;
  P := PChar(target);
  E := (P + Length(target));
  while (P < E) do
  begin
    Result := (Result + Ord(P^ = Self));
    Inc(P);
  end;
end;
{$ENDIF}