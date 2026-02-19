{$IFDEF HELPERS}
function Downtrending: Boolean; overload;
function Uptrending: Boolean; overload;
function Notrending: Boolean; overload;
function Trend: Integer; overload;
function Trending: Boolean; overload;
function TrendFalling: Boolean; overload;
function TrendRising: Boolean; overload;
function Trendy: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Downtrending>
  @action: Returns True if the first element of the array is greater than the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates a “falling” trend.
[==============================================================================}
function MArrayHelper.Downtrending: Boolean; overload;
begin
  Result := ((Self.Size > 1) and (Self[Low(Self)] > Self[High(Self)]));
end;

{==============================================================================]
  <Uptrending>
  @action: Returns True if the first element of the array is less than the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates a “rising” trend.
[==============================================================================}
function MArrayHelper.Uptrending: Boolean; overload;
begin
  Result := ((Self.Size > 1) and (Self[Low(Self)] < Self[High(Self)]));
end;

{==============================================================================]
  <Notrending>
  @action: Returns True if the first element of the array is equal to the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates no significant trend.
[==============================================================================}
function MArrayHelper.Notrending: Boolean; overload;
begin
  Result := ((Self.Size > 1) and (Self[Low(Self)] = Self[High(Self)]));
end;

{==============================================================================]
  <Trend>
  @action: Returns the trend of the array’s endpoints:
            1 = Uptrend (first < last),
           -1 = Downtrend (first > last),
            0 = Notrend (first = last or array too short).
  @note: Only meaningful for arrays with at least 2 elements.
         Comparison is done between the first and last elements only.
[==============================================================================}
function MArrayHelper.Trend: Integer; overload;
begin
  if ((Self.Size < 2) or (Self[Low(Self)] = Self[High(Self)])) then
    Result := 0
  else if (Self[Low(Self)] > Self[High(Self)]) then
    Result := -1
  else
    Result := 1;
end;

{==============================================================================]
  <Trending>
  @action: Returns True if the array is either Uptrending or Downtrending.
  @note: Only meaningful for arrays with at least 2 elements.
         Returns False if the array has no trend (Notrending).
[==============================================================================}
function MArrayHelper.Trending: Boolean; overload;
begin
  Result := (Self.Trend <> 0);
end;

{==============================================================================]
  <TrendFalling>
  @action: Returns True if the first element of the array is greater than or equal to the last element,
           indicating a non-increasing trend from start to end.
  @note: Only meaningful for arrays with at least 2 elements.
         This checks only the first and last elements, not the full array.
[==============================================================================}
function MArrayHelper.TrendFalling: Boolean; overload;
begin
  Result := ((Self.Size > 1) and (Self[Low(Self)] >= Self[High(Self)]));
end;

{==============================================================================]
  <TrendRising>
  @action: Returns True if the first element of the array is less than or equal to the last element,
           indicating a non-decreasing trend from start to end.
  @note: Only meaningful for arrays with at least 2 elements.
         This checks only the first and last elements, not the full array.
[==============================================================================}
function MArrayHelper.TrendRising: Boolean; overload;
begin
  Result := ((Self.Size > 1) and (Self[Low(Self)] <= Self[High(Self)]));
end;

{==============================================================================]
  <Trendy>
  @action: Checks whether the array is monotonic — either entirely non-decreasing,
           non-increasing, or constant.
  @note: Returns True if the array changes in only one direction; False otherwise.
[==============================================================================}
function MArrayHelper.Trendy: Boolean; overload;
var
  i, h, l: Integer;
begin
  h := 0;
  l := 0;
  for i := 1 to High(Self) do
    if ((Self[i] > Self[i - 1]) and (h.Increment <= l)) then
      Break
    else if ((Self[i] < Self[i - 1]) and (l.Increment <= h)) then
      Break;
  Result := not ((h > 0) and (l > 0));
end;
{$ENDIF}