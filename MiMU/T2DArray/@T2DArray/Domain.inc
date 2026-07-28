{$IFDEF HELPERS}
function Ambit: TRange; overload;
function Ambit(const sIndex: Integer): TRange; overload;
function Demesne: TRange; overload;
function Demesne(const sIndex: Integer): TRange; overload;
function Domain: TRange; overload;
function Domain(const sIndex: Integer): TRange; overload;
function Envelope: TRange; overload;
function Envelope(const sIndex: Integer): TRange; overload;
function Purview: TRange; overload;
function Purview(const sIndex: Integer): TRange; overload;
function Scope: TRange; overload;
function Scope(const sIndex: Integer): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ambit>
  @action: Returns a TRange representing the row index boundaries of the 2D array.
  @note: Uses a branchless boolean-to-integer evaluation trick. If the array has 
         no rows, `Result.stop = -1` evaluates to True (1), making start -1. 
         Otherwise start becomes 0.
[==============================================================================}
function M2DArrayHelper.Ambit: TRange; overload;
begin
  Result.stop := High(Self);
  Result.start := -Integer(Result.stop = -1);
end;

{==============================================================================]
  <Ambit>
  @action: Returns a TRange representing the column index boundaries of the row 
           at sIndex.
  @note: Delegates to the 1D MArrayHelper.Ambit on Self[sIndex], correctly 
         reflecting that specific row's own length rather than assuming 
         uniform row width across a jagged array.
[==============================================================================}
function M2DArrayHelper.Ambit(const sIndex: Integer): TRange; overload;
begin
  Result := Self[sIndex].Ambit;
end;

{==============================================================================]
  <Demesne>
  @action: Returns a TRange representing the row index boundaries of the 2D array.
  @note: Uses an explicit conditional check. If the array has rows (High >= 0), 
         start is set to 0. If there are no rows, start becomes -1.
[==============================================================================}
function M2DArrayHelper.Demesne: TRange; overload;
begin
  Result.stop := High(Self);
  if (Result.stop > -1) then
    Result.start := 0
  else
    Result.start := -1;
end;

{==============================================================================]
  <Demesne>
  @action: Returns a TRange representing the column index boundaries of the row 
           at sIndex.
  @note: Delegates to the 1D MArrayHelper.Demesne on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Demesne(const sIndex: Integer): TRange; overload;
begin
  Result := Self[sIndex].Demesne;
end;

{==============================================================================]
  <Domain>
  @action: Returns the valid row index range of the 2D array.
  @note:
    - If the array has no rows, start and stop are both -1.
    - Otherwise start = 0 and stop = Self.Size - 1.
[==============================================================================}
function M2DArrayHelper.Domain: TRange; overload;
begin
  Result.stop := (Self.Size - 1);
  if (Result.stop = -1) then
    Result.start := -1
  else
    Result.start := 0;
end;

{==============================================================================]
  <Domain>
  @action: Returns the valid column index range of the row at sIndex.
  @note: Delegates to the 1D MArrayHelper.Domain on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Domain(const sIndex: Integer): TRange; overload;
begin
  Result := Self[sIndex].Domain;
end;

{==============================================================================]
  <Envelope>
  @action: Returns a TRange representing the row index boundaries of the 2D array.
  @note: Delegates to TRange's own constructor rather than manually assigning 
         start/stop. For an array with no rows, Low(Self) = 0 and High(Self) = -1.
[==============================================================================}
function M2DArrayHelper.Envelope: TRange; overload;
begin
  Result.Create(Low(Self), High(Self));
end;

{==============================================================================]
  <Envelope>
  @action: Returns a TRange representing the column index boundaries of the row 
           at sIndex.
  @note: Delegates to the 1D MArrayHelper.Envelope on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Envelope(const sIndex: Integer): TRange; overload;
begin
  Result := Self[sIndex].Envelope;
end;

{==============================================================================]
  <Purview>
  @action: Returns a TRange representing the row index boundaries of the 2D array.
  @note: Uses an arithmetic right-shift to extract the sign bit of `stop` directly. 
         When the array has no rows, stop = -1 (all bits set), so shifting right 
         by 31 propagates the sign bit, yielding -1. Otherwise the shift yields 0.
[==============================================================================}
function M2DArrayHelper.Purview: TRange; overload;
begin
  Result.stop := High(Self);
  Result.start := (Result.stop shr 31);
end;

{==============================================================================]
  <Purview>
  @action: Returns a TRange representing the column index boundaries of the row 
           at sIndex.
  @note: Delegates to the 1D MArrayHelper.Purview on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Purview(const sIndex: Integer): TRange; overload;
begin
  Result := Self[sIndex].Purview;
end;

{==============================================================================]
  <Scope>
  @action: Returns a TRange representing the row index boundaries of the 2D array.
  @note: Uses Math.Sign on the array's row count. Sign(0) = 0, giving start = -1 
         for an array with no rows.
[==============================================================================}
function M2DArrayHelper.Scope: TRange; overload;
begin
  Result := TRange.Construct((Sign(Self.Length) - 1), High(Self));
end;

{==============================================================================]
  <Scope>
  @action: Returns a TRange representing the column index boundaries of the row 
           at sIndex.
  @note: Delegates to the 1D MArrayHelper.Scope on Self[sIndex].
[==============================================================================}
function M2DArrayHelper.Scope(const sIndex: Integer): TRange; overload;
begin
  Result := Self[sIndex].Demesne;
end;
{$ENDIF}
