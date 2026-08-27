{$IFDEF HELPERS}
function Ordery: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ordery>
  @action: Determines whether Self is monotonic (non-decreasing or
           non-increasing) in either direction, without reporting which,
           using the sign of each adjacent difference rather than a
           comparator. Numeric-only tier — the difference-sign sibling of
           `Orderion`/`AtOrder`, which are both ordered-only (comparator-
           based). Trivially True for length < 2.
  @note: `Self[i + 1] - Self[i]` can overflow for integer MTypes near the
         range boundaries (e.g. Low(Integer) and High(Integer) adjacent),
         producing a wrong sign and a wrong result — a real risk given the
         overflow bugs already caught elsewhere in the digit-counting
         Int64 variants. Comparator-based `AtOrder`/`Orderion` don't have
         this exposure since they never compute a difference.
[==============================================================================}
function MArrayHelper.Ordery: Boolean; overload;
var
  s, p: MType;
  i: Integer;
begin
  p := 0;
  for i := 0 to (High(Self) - 1) do
  begin
    s := Sign(Self[i + 1] - Self[i]);
    if (s <> 0) then
    begin
      if ((p <> 0) and (s <> p)) then
        Exit(False);
      p := s;
    end;
  end;
  Result := True;
end;
{$ENDIF}