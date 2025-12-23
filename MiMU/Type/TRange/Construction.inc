{$IFDEF TYPES}
constructor Create(const rStart, rStop: Integer); overload;
constructor Create(const value: Integer); overload;
class function Construct(const rStart, rStop: Integer): TRange; overload; static;
class function Null(const value: Integer = -2147483648): TRange; overload; static;
function Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer; 
function Init(const rStart, rStop: Integer): TRange; overload; 
function Init(const r: TRange): TRange; overload; 
function Init(const val: Integer = 0): TRange; overload; 
{$ENDIF}

{$IFDEF HELPERS}
function Create: TRange; overload;
{$ENDIF}

{$IFDEF METHODS}
function Range(const rStart, rStop: Integer): TRange; overload; inline;
function Range(const val: Integer = 0): TRange; overload; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Range>
  @action: Constructs and returns a TRange whose start and stop values are set to
           rStart and rStop respectively. No normalization or validation is
           performed.
  @note: The resulting range preserves the specified ordering. If rStart > rStop,
         the function returns a descending range.
[==============================================================================}
function Range(const rStart, rStop: Integer): TRange; overload; inline;
begin
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <Range>
  @action: Constructs and returns a TRange representing a single-value range,
           with both start and stop initialized to val.
  @note: This overload is intended for convenience when creating point ranges.
         The default value (0) is used when no argument is provided.
[==============================================================================}
function Range(const val: Integer = 0): TRange; overload; inline;
begin
  Result.start := val;
  Result.stop := val;
end;

{==============================================================================]
  <Create>
  @action: Create a TRange with start and stop
  @note: None.
[==============================================================================}
constructor TRange.Create(const rStart, rStop: Integer); overload;
begin
  Self.start := rStart;
  Self.stop := rStop;
end;

{==============================================================================]
  <Create>
  @action: Create a TRange with value
  @note: None.
[==============================================================================}
constructor TRange.Create(const value: Integer); overload;
begin
  Self.Create(value, value);
end;

{==============================================================================]
  <Create>
  @action: TRange 0..0.
  @note: None.
[==============================================================================}
function TRangeHelper.Create: TRange;
begin
  Self.start := 0;
  Self.stop := 0;
  Result := Self;
end;

{==============================================================================]
  <Construct>
  @action: Constructs TRange with rStart and rStop.
  @note: None.
[==============================================================================}
class function TRange.Construct(const rStart, rStop: Integer): TRange; overload;
begin
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <Null>
  @action: Returns a special "null" or empty range, represented by both start and stop
           being set to the specified sentinel value.
  @param: value - Optional integer to use as the sentinel for an empty range. Defaults
                  to Low(Integer) (-2147483648 for 32-bit integers).
  @note:   This function is typically used to represent non-overlapping ranges or
           invalid ranges in operations like intersection. It provides a consistent
           marker for "empty" ranges.
[==============================================================================}
class function TRange.Null(const value: Integer = -2147483648): TRange; overload;
begin
  Result := Range(value, value);
end;

{==============================================================================]
  <Build>
  @action: Create a TRange with rStart and rStop, using Min and Max for safety.
  @note: None.
[==============================================================================}
function TRange.Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer;
begin
  Self.start := Min(rStart, rStop);
  Self.stop := Max(rStop, rStart);
  Result := (Abs(rStop - rStart) + 1);
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TRange with the specified start and stop values.
           Also returns the initialized record so it can be assigned in-line.
  @note: Useful for initializing a TRange instance and simultaneously returning it
         for assignment. Example: a := b.Init(1, 10);
[==============================================================================}
function TRange.Init(const rStart, rStop: Integer): TRange; overload;
begin
  Self.start := rStart;
  Self.stop := rStop;
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TRange as a copy of another TRange.
           Also returns the copied record.
  @note: Useful for copying values from an existing TRange while allowing in-line assignment.
         Example: a := b.Init(c);
[==============================================================================}
function TRange.Init(const r: TRange): TRange; overload;
begin
  Self := r;
  Result := r;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TRange with both start and stop set to the same value.
           Also returns the initialized record.
  @note: The parameter has a default of 0, allowing zero-initialization.
         Example: a := b.Init; or a := b.Init(5);
[==============================================================================}
function TRange.Init(const val: Integer = 0): TRange; overload;
begin
  Self.start := val;
  Self.stop := val;
  Result.start := val;
  Result.stop := val;
end;
{$ENDIF}