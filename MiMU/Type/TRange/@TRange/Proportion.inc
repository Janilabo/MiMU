{$IFDEF METHODS}
function Disizequal(const target: TRange): Boolean; overload;
function Sizequal(const target: TRange; const tolerance: Integer): Boolean; overload;
function Sizequal(const target: TRange): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Disizequal>
  @action: Determines whether two ranges have different discrete sizes.
  @note: Returns True if Self.Size does not equal target.Size. Logical negation of Sizequal.
[==============================================================================}
function TRange.Disizequal(const target: TRange): Boolean; overload;
begin
  Result := (Self.Size <> target.Size);
end;

{==============================================================================]
  <Sizequal>
  @action: Determines whether two ranges have the same discrete size, regardless
           of position or direction.
  @note: Returns True if Self.Size equals target.Size.
[==============================================================================}
function TRange.Sizequal(const target: TRange): Boolean; overload;
begin
  Result := (Self.Size = target.Size);
end;

{==============================================================================]
  <Sizequal>
  @action: Determines whether two ranges have discrete sizes within a given tolerance.
  @note: Returns True if the absolute difference between sizes is <= Tolerance.
         Tolerance = 0 behaves identically to exact Sizequal.
[==============================================================================}
function TRange.Sizequal(const target: TRange; const tolerance: Integer): Boolean; overload;
begin
  Result := (Abs(Self.Size - target.Size) <= tolerance);
end;
{$ENDIF}
