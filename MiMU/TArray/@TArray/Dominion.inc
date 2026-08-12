{$IFDEF HELPERS}
function Capture(var source: MArray): Integer; overload;
function Release(var target: MArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Capture>
  @action: Resizes Self to match source's length, copies all of source's
    elements into Self, then empties source. Self takes full ownership of
    the contents; source is left with nothing.
  @note: Returns the new length of Self (== original length of source).
[==============================================================================}
function MArrayHelper.Capture(var source: MArray): Integer; overload;
var
  s: Integer;
begin
  Result := Self.SetSize(source.Length);
  for s := 0 to (Result - 1) do
    Self[s] := source[s];
  SetLength(source, 0);
end;

{==============================================================================]
  <Release>
  @action: Resizes target to match Self's length, copies all of Self's
    elements into target, then empties Self. target takes full ownership of
    the contents; Self is left with nothing.
  @note: Returns the new length of target (== original length of Self).
[==============================================================================}
function MArrayHelper.Release(var target: MArray): Integer; overload;
var
  s: Integer;
begin
  Result := target.SetSize(Self.Length);
  for s := 0 to (Result - 1) do
    target[s] := Self[s];
  SetLength(Self, 0);
end;
{$ENDIF}
