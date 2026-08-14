{$IFDEF HELPERS}
function Add(const N: Integer; const aBounds: TRange): Integer; overload;
function Adjust(const cValue: Integer; const limits: TRange): Boolean; overload;
function Adjusted(const cValue: Integer; const limits: TRange): Integer; overload;
function AdjustedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer; overload;
function AdjustedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer; overload;
function AdjustMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean; overload;
function AdjustMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean; overload;
function Pred(const N: Integer = 1; const minBound: Integer = -2147483648): Integer; overload;
function Succ(const N: Integer = 1; const maxBound: Integer = 2147483647): Integer; overload;
function Update(const cValue: Integer; const limits: TRange): Boolean; overload;
function Updated(const cValue: Integer; const limits: TRange): Integer; overload;
function UpdatedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer; overload;
function UpdatedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer; overload;
function UpdateMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean; overload;
function UpdateMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Add>
  @action: Adds N to Self, clamped within the given range (aBounds).
  @note: Uses Int64 arithmetic to prevent overflow; handles negative N by clamping to Min(aBounds), positive N by clamping to Max(aBounds).
[==============================================================================}
function TIntegerHelper.Add(const N: Integer; const aBounds: TRange): Integer; overload;
begin
  if (N < 0) then
    Result := Max((Int64(Self) + N), Min(aBounds.start, aBounds.stop))
  else
    Result := Min((Int64(Self) + N), Max(aBounds.start, aBounds.stop));
end;

{==============================================================================]
  <Adjust>
  @action: Attempts to adjust the current value by cValue if the resulting value
           stays within the specified limits range.
  @note: Returns True if the value was adjusted, False if it would go out of range.
[==============================================================================}
function TIntegerHelper.Adjust(const cValue: Integer; const limits: TRange): Boolean; overload;
begin
  Result := limits.Contains(Self + cValue);
  if Result then
    Self := (Self + cValue);
end;

{==============================================================================]
  <Adjusted>
  @action: Returns a potentially adjusted copy of the integer, adding cValue
           only if it stays within limits.
  @note: Non-mutating version of Adjust.
[==============================================================================}
function TIntegerHelper.Adjusted(const cValue: Integer; const limits: TRange): Integer; overload;
begin
  Result := Self;
  if limits.Contains(Self + cValue) then
    Result := (Result + cValue);
end;

{==============================================================================]
  <AdjustedMax>
  @action: Returns Self + cValue if below limit; otherwise returns Self.
  @note:   Non-mutating version of AdjustMax.
[==============================================================================}
function TIntegerHelper.AdjustedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer; overload;
begin
  Result := Self;
  if ((Self + cValue) <= limit) then
    Result := (Result + cValue);
end;

{==============================================================================]
  <AdjustedMin>
  @action: Returns Self + cValue if above limit; otherwise returns Self.
  @note: Non-mutating version of AdjustMin.
[==============================================================================}
function TIntegerHelper.AdjustedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer; overload;
begin
  Result := Self;
  if ((Self + cValue) >= limit) then
    Result := (Result + cValue);
end;

{==============================================================================]
  <AdjustMax>
  @action: Attempts to adjust by cValue but prevents exceeding the upper limit.
  @note: Returns True if the new value remains <= limit.
[==============================================================================}
function TIntegerHelper.AdjustMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean; overload;
begin
  Result := ((Self + cValue) <= limit);
  if Result then
    Self := (Self + cValue);
end;

{==============================================================================]
  <AdjustMin>
  @action: Attempts to increase or decrease the integer by cValue, but prevents
           it from going below limit.
  @note: Returns True if the value stayed above or equal to limit.
[==============================================================================}
function TIntegerHelper.AdjustMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean; overload;
begin
  Result := ((Self + cValue) >= limit);
  if Result then
    Self := (Self + cValue);
end;

{==============================================================================]
  <Pred>
  @action: Returns the predecessor of Self, decreased by N, not below minBound.
  @note: Uses Int64 arithmetic to prevent underflow; default N = 1, default minBound = Low(Integer).
[==============================================================================}
function TIntegerHelper.Pred(const N: Integer = 1; const minBound: Integer = -2147483648): Integer; overload;
begin
  Result := Max((Int64(Self) - N), minBound);
end;

{==============================================================================]
  <Succ>
  @action: Returns the successor of Self, increased by N, not above maxBound.
  @note: Uses Int64 arithmetic to prevent overflow; default N = 1, default maxBound = High(Integer).
[==============================================================================}
function TIntegerHelper.Succ(const N: Integer = 1; const maxBound: Integer = 2147483647): Integer; overload;
begin
  Result := Min((Int64(Self) + N), maxBound);
end;

{==============================================================================]
  <Update>
  @action: Adjusts the integer by cValue and clamps it within the specified limits.
  @note: Returns True if the result was within the range and assigned without clamping.
[==============================================================================}
function TIntegerHelper.Update(const cValue: Integer; const limits: TRange): Boolean; overload;
var
  r: TRange;
  n: Integer;
begin
  r := limits.Normalized;
  n := (Self + cValue);
  if (n < r.start) then
    Self := r.start
  else if (n > r.stop) then
    Self := r.stop
  else
    Self := n;
  Result := (n = Self);
end;

{==============================================================================]
  <Updated>
  @action: Returns a new value equal to Self + cValue, clamped within the specified limits.
  @note: Does not modify Self.
[==============================================================================}
function TIntegerHelper.Updated(const cValue: Integer; const limits: TRange): Integer; overload;
var
  r: TRange;
  n: Integer;
begin
  r := limits.Normalized;
  n := (Self + cValue);
  if (n < r.start) then
    Result := r.start
  else if (n > r.stop) then
    Result := r.stop
  else
    Result := n;
end;

{==============================================================================]
  <UpdatedMax>
  @action: Returns Self + cValue, ensuring the result is not above limit.
  @note: Does not modify Self.
[==============================================================================}
function TIntegerHelper.UpdatedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer; overload;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n > limit) then
    Result := limit
  else
    Result := n;
end;

{==============================================================================]
  <UpdatedMin>
  @action: Returns Self + cValue, ensuring the result is not below limit.
  @note: Does not modify Self.
[==============================================================================}
function TIntegerHelper.UpdatedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer; overload;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n < limit) then
    Result := limit
  else
    Result := n;
end;

{==============================================================================]
  <UpdateMax>
  @action: Adjusts the integer by cValue, ensuring it does not exceed limit.
  @note: Returns True if the result was below or equal to limit (no clamping).
[==============================================================================}
function TIntegerHelper.UpdateMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean; overload;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n > limit) then
    Self := limit
  else
    Self := n;
  Result := (n = Self);
end;

{==============================================================================]
  <UpdateMin>
  @action: Adjusts the integer by cValue, ensuring it does not fall below limit.
  @note: Returns True if the result was above or equal to limit (no clamping).
[==============================================================================}
function TIntegerHelper.UpdateMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean; overload;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n < limit) then
    Self := limit
  else
    Self := n;
  Result := (n = Self);
end;
{$ENDIF}
