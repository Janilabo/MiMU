{$IFDEF HELPERS}
function Ascending: Boolean; overload;
function Ascends: Boolean; overload;
function Descending: Boolean; overload;
function Descends: Boolean; overload;
function Decreasing: Boolean; overload;
function Increasing: Boolean; overload;
function IsAscending: Boolean; overload;
function IsDescending: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascending>
  @action: Returns True if all ranges in the array are strictly ascending.
  @note: Returns False if any range is not ascending or if the array is empty.
[==============================================================================}
function TRangeArrayHelper.Ascending: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i].Ascending then
	  Exit(False);
  Result := not Self.Empty;
end;

{==============================================================================]
  <Ascends>
  @action: Returns True if all ranges in the array ascend according to their Ascends predicate.
  @note: Returns False if any range does not ascend or if the array is empty.
[==============================================================================}
function TRangeArrayHelper.Ascends: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i].Ascends then
	  Exit(False);
  Result := not Self.Empty;
end;

{==============================================================================]
  <Decreasing>
  @action: Returns True if all ranges in the array are strictly decreasing.
  @note: Returns False if any range is not decreasing or if the array is empty.
[==============================================================================}
function TRangeArrayHelper.Decreasing: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i].Decreasing then
	  Exit(False);
  Result := not Self.Empty;
end;

{==============================================================================]
  <Descending>
  @action: Returns True if all ranges in the array are strictly descending.
  @note: Returns False if any range is not descending or if the array is empty.
[==============================================================================}
function TRangeArrayHelper.Descending: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i].Descending then
	  Exit(False);
  Result := not Self.Empty;
end;

{==============================================================================]
  <Descends>
  @action: Returns True if all ranges in the array descend according to their Descends predicate.
  @note: Returns False if any range does not descend or if the array is empty.
[==============================================================================}
function TRangeArrayHelper.Descends: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i].Descends then
	  Exit(False);
  Result := not Self.Empty;
end;

{==============================================================================]
  <Increasing>
  @action: Returns True if all ranges in the array are strictly increasing.
  @note: Returns False if any range is not increasing or if the array is empty.
[==============================================================================}
function TRangeArrayHelper.Increasing: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i].Increasing then
	  Exit(False);
  Result := not Self.Empty;
end;

{==============================================================================]
  <IsAscending>
  @action: Returns True if all ranges in the array satisfy the IsAscending predicate.
  @note: Returns False if any range is not ascending or if the array is empty.
[==============================================================================}
function TRangeArrayHelper.IsAscending: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i].IsAscending then
	  Exit(False);
  Result := not Self.Empty;
end;

{==============================================================================]
  <IsDescending>
  @action: Returns True if all ranges in the array satisfy the Descending predicate.
  @note: Returns False if any range is not descending or if the array is empty.
[==============================================================================}
function TRangeArrayHelper.IsDescending: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i].Descending then
	  Exit(False);
  Result := not Self.Empty;
end;
{$ENDIF}