{$IFDEF HELPERS}
function Adjust(const cValue: Integer; const limits: TRange): Boolean;
function Adjusted(const cValue: Integer; const limits: TRange): Integer;
function AdjustedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer;
function AdjustedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer;
function AdjustMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean;
function AdjustMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean;
function Decrease(const N: Integer = 1): Integer; overload;
function Decrease(const B: Boolean): Integer; overload;
function Decrement(const N: Integer = 1): Integer; overload;
function Decrement(const B: Boolean): Integer; overload;
function Increase(const N: Integer = 1): Integer; overload;
function Increase(const B: Boolean): Integer; overload;
function Increment(const N: Integer = 1): Integer; overload;
function Increment(const B: Boolean): Integer; overload;
function Update(const cValue: Integer; const limits: TRange): Boolean;
function Updated(const cValue: Integer; const limits: TRange): Integer;
function UpdatedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer;
function UpdatedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer;
function UpdateMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean;
function UpdateMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Adjust>
  @action: Attempts to adjust the current value by cValue if the resulting value
           stays within the specified limits range.
  @note: Returns True if the value was adjusted, False if it would go out of range.
[==============================================================================}
function TIntegerHelper.Adjust(const cValue: Integer; const limits: TRange): Boolean;
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
function TIntegerHelper.Adjusted(const cValue: Integer; const limits: TRange): Integer;
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
function TIntegerHelper.AdjustedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer;
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
function TIntegerHelper.AdjustedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer;
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
function TIntegerHelper.AdjustMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean;
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
function TIntegerHelper.AdjustMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean;
begin
  Result := ((Self + cValue) >= limit);
  if Result then
    Self := (Self + cValue);
end;

{==============================================================================]
  <Decrease>
  @action: Decreases the Integer value x by N.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TIntegerHelper.Decrease(const N: Integer = 1): Integer; overload;
begin
  Result := Self;
  Self := (Self - N);
end;

{==============================================================================]
  <Decrease>
  @action: Decreases the Integer value x by 1 if B is true.
  @note: Returns x before decreasing!
[==============================================================================}
function TIntegerHelper.Decrease(const B: Boolean): Integer; overload;
begin
  Result := Self;
  if B then
    Self := (Self - 1);
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Integer value x by N.
  @note: Returns the decreased x!
[==============================================================================}
function TIntegerHelper.Decrement(const N: Integer = 1): Integer; overload;
begin
  Self := (Self - N);
  Result := Self;
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Integer value x by 1 if B is true.
  @note: Returns the decreased x!
[==============================================================================}
function TIntegerHelper.Decrement(const B: Boolean): Integer; overload;
begin
  if B then
    Self := (Self - 1);
  Result := Self;
end;

{==============================================================================]
  <Increase>
  @action: Increases the Integer value x by N.
  @note: Returns x before increasing it with N!
[==============================================================================}
function TIntegerHelper.Increase(const N: Integer = 1): Integer; overload;
begin
  Result := Self;
  Self := (Self + N);
end;

{==============================================================================]
  <Increase>
  @action: Increases the Integer value x by 1 when B is true.
  @note: Returns x before increasing!
[==============================================================================}
function TIntegerHelper.Increase(const B: Boolean): Integer; overload;
begin
  Result := Self;
  if B then
    Self := (Self + 1);
end;

{==============================================================================]
  <Increment>
  @action: Increases the Integer value x by N.
  @note: Returns the increased x!
[==============================================================================}
function TIntegerHelper.Increment(const N: Integer = 1): Integer; overload;
begin
  Self := (Self + N);
  Result := Self;
end;

{==============================================================================]
  <Increment>
  @action: Increases the Integer value x by 1 if B is true.
  @note: Returns the increased x!
[==============================================================================}
function TIntegerHelper.Increment(const B: Boolean): Integer; overload;
begin
  if B then
    Self := (Self + 1);
  Result := Self;
end;

{==============================================================================]
  <Update>
  @action: Adjusts the integer by cValue and clamps it within the specified limits.
  @note: Returns True if the result was within the range and assigned without clamping.
[==============================================================================}
function TIntegerHelper.Update(const cValue: Integer; const limits: TRange): Boolean;
var
  r: TRange;
  n: Integer;
begin
  r := limits.Normalized;
  n := (Self + cValue);
  if (n < r.start) then
    Self := r.start
  else
    if (n > r.stop) then
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
function TIntegerHelper.Updated(const cValue: Integer; const limits: TRange): Integer;
var
  r: TRange;
  n: Integer;
begin
  r := limits.Normalized;
  n := (Self + cValue);
  if (n < r.start) then
    Result := r.start
  else
    if (n > r.stop) then
      Result := r.stop
    else
      Result := n;
end;

{==============================================================================]
  <UpdatedMax>
  @action: Returns Self + cValue, ensuring the result is not above limit.
  @note: Does not modify Self.
[==============================================================================}
function TIntegerHelper.UpdatedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer;
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
function TIntegerHelper.UpdatedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer;
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
function TIntegerHelper.UpdateMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean;
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
function TIntegerHelper.UpdateMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean;
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