{$IFDEF HELPERS}
function Disizequal(const target: MArray): Boolean; overload;
function Sizequal(const target: MArray; const tolerance: Integer): Boolean; overload;
function Sizequal(const target: MArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Disizequal>
  @action: Determines whether the current array and the target array have unequal sizes.
  @note: Returns True if Self.Size <> target.Size, otherwise False.
[==============================================================================}
function MArrayHelper.Disizequal(const target: MArray): Boolean; overload;
begin
  Result := (Self.Size <> target.Size);
end;

{==============================================================================]
  <Sizequal>
  @action: Determines whether the current array and the target array have the exact same size.
  @note: Returns True if Self.Size = target.Size, otherwise False.
[==============================================================================}
function MArrayHelper.Sizequal(const target: MArray): Boolean; overload;
begin
  Result := (Self.Size = target.Size);
end;

{==============================================================================]
  <Sizequal>
  @action: Determines whether the size difference between the current array and the target array is within a specified tolerance.
  @note: Returns True if Abs(Self.Size - target.Size) <= tolerance, otherwise False.
[==============================================================================}
function MArrayHelper.Sizequal(const target: MArray; const tolerance: Integer): Boolean; overload;
begin
  Result := (Abs(Self.Size - target.Size) <= tolerance);
end;
{$ENDIF}
