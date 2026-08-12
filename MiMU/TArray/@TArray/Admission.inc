{$IFDEF HELPERS}
function Berth(const aIndex: UInt32 = 0): Integer; overload;
function Lodge(const aIndex: UInt32 = 0): Integer; overload;
function Vacate(const aIndex: UInt32 = 0): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Berth>
  @action: Clamps aIndex to [0, Length], shifts all elements from that
           position onward one slot to the right, and returns the
           now-vacant index.
  @note: Does not write a value into the opened slot — pair with an
         assignment (or a future `Admit`) to complete the insertion.
[==============================================================================}
function MArrayHelper.Berth(const aIndex: UInt32 = 0): Integer; overload;
var
  s: Integer;
begin
  Result := Min(Integer(aIndex), Self.Length);
  for s := Self.Alloc(Self.Length + 1) downto (Result + 1) do
    Self[s] := Self[s - 1];
end;

{==============================================================================]
  <Lodge>
  @action: Clamps aIndex to [0, High(Self)] after growing the array by
           one element, then shifts all elements from that position
           onward one slot to the right, returning the now-vacant index.
  @note: Does not write a value into the opened slot — pair with an
         assignment (or a future `Admit`) to complete the insertion.
[==============================================================================}
function MArrayHelper.Lodge(const aIndex: UInt32 = 0): Integer; overload;
var
  s: Integer;
begin
  Result := Min(Integer(aIndex), Self.Alloc(Self.Length + 1));
  for s := High(Self) downto (Result + 1) do
    Self[s] := Self[s - 1]; 
end;

{==============================================================================]
  <Vacate>
  @action: Clamps aIndex to [0, High(Self)] after growing the array by
           one element, then shifts all elements from that position
           onward one slot to the right, returning the now-vacant index.
  @note: Does not write a value into the opened slot — pair with an
         assignment (or a future `Admit`) to complete the insertion.
[==============================================================================}
function MArrayHelper.Vacate(const aIndex: UInt32 = 0): Integer; overload;
begin
  Result := Min(Integer(aIndex), Self.Length);
  Insert(Self[Result], Self, (Result + 1));
end;
{$ENDIF}
