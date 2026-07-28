{$IFDEF HELPERS}
function Ambit: TRange; overload;
function Demesne: TRange; overload;
function Domain: TRange; overload;
function Envelope: TRange; overload;
function Purview: TRange; overload;
function Scope: TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ambit>
  @action: Returns a TRange representing the index boundaries of the array.
  @note: Uses a branchless boolean-to-integer evaluation trick. If the array is 
         empty, `Result.stop = -1` evaluates to True (1), making start -1. Otherwise, 
         it evaluates to False (0), making start 0.
[==============================================================================}
function MArrayHelper.Ambit: TRange; overload;
begin
  Result.stop := High(Self);
  Result.start := -Integer(Result.stop = -1);
end;

{==============================================================================]
  <Demesne>
  @action: Returns a TRange representing the index boundaries of the array.
  @note: Uses an explicit conditional check. If the array is not empty (High >= 0), 
         start is set to 0. For an empty array (High = -1), start becomes -1.
[==============================================================================}
function MArrayHelper.Demesne: TRange; overload;
begin
  Result.stop := High(Self);
  if (Result.stop > -1) then
    Result.start := 0
  else
    Result.start := -1;
end;

{==============================================================================]
  <Domain>
  @action: Returns the valid index range of the array.
  @note:
    - If the array is empty, start and stop are set to -1.
    - Otherwise, start = 0 and stop = Length(Self) - 1.
[==============================================================================}
function MArrayHelper.Domain: TRange; overload;
begin
  Result.stop := (Self.Size - 1);
  if (Result.stop = -1) then
    Result.start := -1
  else
    Result.start := 0;
end;

{==============================================================================]
  <Envelope>
  @action: Returns a TRange representing the index boundaries of the array.
  @note: Delegates to TRange's own constructor rather than manually assigning 
         start/stop. For an empty array, Low(Self) = 0 and High(Self) = -1.
[==============================================================================}
function MArrayHelper.Envelope: TRange; overload;
begin
  Result.Create(Low(Self), High(Self));
end;

{==============================================================================]
  <Purview>
  @action: Returns a TRange representing the index boundaries of the array.
  @note: Uses an arithmetic right-shift to extract the sign bit of `stop` directly.
         When the array is empty, stop = -1 (all bits set), so shifting right by 31
         propagates the sign bit, yielding -1. When non-empty, stop >= 0, so the
         shift yields 0. Avoids any boolean-to-integer conversion.
[==============================================================================}
function MArrayHelper.Purview: TRange; overload;
begin
  Result.stop := High(Self);
  Result.start := (Result.stop shr 31);
end;

{==============================================================================]
  <Scope>
  @action: Returns a TRange representing the index boundaries of the array.
  @note: Uses Math.Sign on the array's Length. Sign(0) = 0, giving start = -1 for
         an empty array. Sign of any positive length = 1, giving start = 0.
		 So for empty arrays this method will return <-1..-1>
[==============================================================================}
function MArrayHelper.Scope: TRange; overload;
begin
  Result := TRange.Construct((Sign(Self.Length) - 1), High(Self));
end;
{$ENDIF}
