{$IFDEF HELPERS}
function HalfLength: Integer; overload;
function Hidex: Integer; overload;
function Lodex: Integer; overload;
function MiddleIndex: Integer; overload;
function Midex: Integer; overload;
function Pivot: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Hidex>
  @action: Returns half the length of the array (integer division, floor).
  @return: Self.Length div 2. For empty array, returns 0.
  @note: The result is an index, not an element. For non‑empty arrays,
         this is the middle index (lower midpoint). Use in combination
         with Length to determine valid ranges.
[==============================================================================}
function MArrayHelper.HalfLength: Integer; overload;
begin
  Result := (Self.Length div 2);
end;

{==============================================================================]
  <Hidex>
  @action: Returns the highest (last) index of the array (High Index).
  @note: Self.Length - 1 if the array is not empty, otherwise -1.
[==============================================================================}
function MArrayHelper.Hidex: Integer; overload;
begin
  if (Self.Length > 0) then
    Result := (Self.Length - 1)
  else
    Result := -1;
end;

{==============================================================================]
  <Lodex>
  @action: Returns the lowest (first) index of the array (Low Index).
  @note: 0 if the array is not empty, otherwise -1.
[==============================================================================}
function MArrayHelper.Lodex: Integer; overload;
begin
  if (Self.Length > 0) then
    Result :=  0
  else
    Result := -1;
end;

{==============================================================================]
  <MiddleIndex>
  @action: Returns the middle index of the array (floor of half the length).
           For an empty array, returns -1.
  @note: Uses IfThen from Math unit. The result is equivalent to Self.Length div 2
         when Self.Length > 0, otherwise -1. This index can be used as a pivot
         for partitioning or as a midpoint in divide‑and‑conquer algorithms.
         For odd lengths, the middle index is the lower midpoint
         (e.g., length 5 → index 2).
[==============================================================================}
function MArrayHelper.MiddleIndex: Integer; overload;
begin
  Result := IfThen((Self.Length > 0), Self.HalfLength, -1);
end;

{==============================================================================]
  <Midex>
  @action: Returns the middle index of the array (Mid Index).
  @note: Self.Length div 2 if the array is not empty, otherwise -1. For odd length, the result is
         the floor of half (e.g., length 5 → 2). Returns -1 for empty array
         to indicate no valid middle index.
[==============================================================================}
function MArrayHelper.Midex: Integer; overload;
begin
  if (Self.Length > 0) then
    Result := Self.HalfLength
  else
    Result := -1;
end;

{==============================================================================]
  <Pivot>
  @action: Returns the middle index of the array (floor of half length).
           For an empty array, returns -1.
  @note: Uses Self.Empty (boolean) to detect empty array. The expression
         subtracts 1 when empty, giving -1; otherwise subtracts 0.
         This is a branch‑free, concise implementation.
[==============================================================================}
function MArrayHelper.Pivot: Integer; overload;
begin
  Result := (Self.HalfLength - Ord(Self.Empty));
end;
{$ENDIF}