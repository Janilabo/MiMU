{$IFDEF METHODS}
class function Construct(const rStart, rStop: Integer): TRange; overload; static;
class function Construct(const rVal: Integer): TRange; overload; static;
class function Construct: TRange; overload; static;
class function Construct(const arr: TIntegerArray; const oAscending: Boolean = True): TRange; overload; static;
function Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer;
constructor Create(const rStart, rStop: Integer); overload;
constructor Create(const value: Integer); overload;
constructor Create(const data: string); overload;
function Init(const rStart, rStop: Integer): TRange; overload;
function Init(const r: TRange): TRange; overload;
function Init(const val: Integer = 0): TRange; overload;
class function Null(const value: Integer = -2147483648): TRange; overload; static;
class function Unbounded(const oAscending: Boolean = True): TRange; static;
{$ENDIF}

{$IFDEF HELPERS}
function Create: TRange; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Range(const rStart, rStop: Integer): TRange; overload;
function Range(const val: Integer = 0): TRange; overload;
function R(const startVal, stopVal: Integer): TRange; overload;
function R(const val: Integer = 0): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Construct>
  @action: Constructs TRange with rVal.
  @note: rVal will be used for both start and stop.
[==============================================================================}
class function TRange.Construct(const rVal: Integer): TRange; overload;
begin
  Result.start := rVal;
  Result.stop := rVal;
end;

{==============================================================================]
  <Construct>
  @action: Constructs TRange with 0's.
  @note: 0 will be used for both start and stop.
[==============================================================================}
class function TRange.Construct: TRange; overload;
begin
  Result.start := 0;
  Result.stop := 0;
end;

{==============================================================================]
  <Construct>
  @action: Constructs a TRange whose bounds span all values in the given integer array.
  @note: The oAscending flag only controls comparison direction; the resulting range
         always represents the minimum and maximum values in the array.
[==============================================================================}
class function TRange.Construct(const arr: TIntegerArray; const oAscending: Boolean = True): TRange; overload;
var
  i: Integer;
begin
  if (System.Length(arr) = 0) then
    Exit(TRange.Null);
  Result.start := arr[0];
  Result.stop := arr[0];
  case oAscending of
    True:
    for i := 1 to High(arr) do
      if (arr[i] < Result.start) then
        Result.start := arr[i]
      else if (arr[i] > Result.stop) then
        Result.stop := arr[i];
    False:
    for i := 1 to High(arr) do
      if (arr[i] < Result.stop) then
        Result.stop := arr[i]
      else if (arr[i] > Result.start) then
        Result.start := arr[i];
  end;
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
  @action: Create a TRange with value
  @note: None.
[==============================================================================}
constructor TRange.Create(const data: string);
var
  p: TStringArray;
  s: string;
begin
  if Pos('..', data) > 0 then
    s := '..'
  else if Pos('-', data) > 0 then
    s := '-'
  else if Pos(':', data) > 0 then
    s := ':'
  else if Pos(',', data) > 0 then
    s := ','
  else
    raise Exception.Create('Invalid range format');
  p := SplitString(data, s);
  if (System.Length(p) <> 2) then
    raise Exception.Create('Invalid range format');
  start := StrToInt(Trim(p[0]));
  stop  := StrToInt(Trim(p[1]));
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
  <Unbounded>
  @action: Constructs a TRange representing the full span of Integer values.
  @note: The oAscending flag determines the ordering of start and stop:
         ascending yields (Low(Integer), High(Integer));
         descending yields (High(Integer), Low(Integer)).
[==============================================================================}
class function TRange.Unbounded(const oAscending: Boolean = True): TRange;
begin
  if oAscending then
    Result.Create(Low(Integer), High(Integer))
  else
    Result.Create(High(Integer), Low(Integer));
end;

{==============================================================================]
  <Range>
  @action: Constructs and returns a TRange whose start and stop values are set to
           rStart and rStop respectively. No normalization or validation is
           performed.
  @note: The resulting range preserves the specified ordering. If rStart > rStop,
         the function returns a descending range.
[==============================================================================}
function Range(const rStart, rStop: Integer): TRange; overload;
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
function Range(const val: Integer = 0): TRange; overload;
begin
  Result.start := val;
  Result.stop := val;
end;

{==============================================================================]
  <R>
  @action: Constructs and returns a TRange whose start and stop values are set to
           startVal and stopVal respectively. No normalization or validation is
           performed.
  @note: The resulting range preserves the specified ordering. If startVal > stopVal,
         the function returns a descending range.
[==============================================================================}
function R(const startVal, stopVal: Integer): TRange; overload;
begin
  Result.start := startVal;
  Result.stop := stopVal;
end;

{==============================================================================]
  <R>
  @action: Constructs and returns a TRange representing a single-value range,
           with both start and stop initialized to val.
  @note: This overload is intended for convenience when creating point ranges.
         The default value (0) is used when no argument is provided.
[==============================================================================}
function R(const val: Integer = 0): TRange; overload;
begin
  Result.start := val;
  Result.stop := val;
end;
{$ENDIF}