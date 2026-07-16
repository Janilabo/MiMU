{$IFDEF HELPERS}
function Astricly: Boolean; overload;
function Destricly: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Astricly>
  @action: ?
  @note: ?
[==============================================================================}
function TIntegerArrayHelper.Astricly: Boolean; overload;
var
  p, e: PInteger;
begin
  if (Self.Length < 2) then
    Exit(False);
  p := @Self[0];
  e := @Self[High(Self)];
  while (p < e) do
  begin
    if (p^ >= (p + 1)^) then
      Exit(False);
    Inc(p);
  end;
  Result := True;
end;

{==============================================================================]
  <Destricly>
  @action: ?
  @note: ?
[==============================================================================}
function TIntegerArrayHelper.Destricly: Boolean; overload;
var
  p, e: PInteger;
begin
  if (Self.Length < 2) then
    Exit(False);
  p := @Self[0];
  e := @Self[High(Self)];
  while (p < e) do
  begin
    if (p^ <= (p + 1)^) then
      Exit(False);
    Inc(p);
  end;
  Result := True;
end;
{$ENDIF}