{$IFDEF HELPERS}
function XBisectLower(const xValue: Integer): Integer; overload;
function XBisectUpper(const xValue: Integer): Integer; overload;

function YBisectLower(const yValue: Integer): Integer; overload;
function YBisectUpper(const yValue: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <XBisectLower>
  @action: Finds the first index in an X-sorted TPointArray where X >= xValue.
  @note: PRECONDITION: Array must be sorted by X. Only requires simple X sorting 
         (does not require compound X-then-Y sorting). Returns -1 if not found.
[==============================================================================}
function TPointArrayHelper.XBisectLower(const xValue: Integer): Integer; overload;
var
  l, h, m: Integer;
begin
  Result := -1;
  h := High(Self);
  if (h < 0) then
    Exit;
  l := 0;
  while (l <= h) do
  begin
    m := (l + (h - l) div 2);
    if (Self[m].X >= xValue) then
    begin
      Result := m;
      h := (m - 1);
    end else
      l := (m + 1);
  end;
end;

{==============================================================================]
  <XBisectUpper>
  @action: Finds the last index in an X-sorted TPointArray where X <= xValue.
  @note: PRECONDITION: Array must be sorted by X. Only requires simple X sorting 
         (does not require compound X-then-Y sorting). Returns -1 if not found.
[==============================================================================}
function TPointArrayHelper.XBisectUpper(const xValue: Integer): Integer; overload;
var
  l, h, m: Integer;
begin
  Result := -1;
  h := High(Self); 
  if (h < 0) then
    Exit;
  l := 0;
  while (l <= h) do
  begin
    m := (l + (h - l) div 2);
    if (Self[m].X <= xValue) then
    begin
      Result := m;
      l := (m + 1);
    end else
      h := (m - 1);
  end;
end;

{==============================================================================]
  <YBisectLower>
  @action: Finds the first index in a Y-sorted TPointArray where Y >= yValue.
  @note: PRECONDITION: Array must be sorted by Y. Only requires simple Y sorting 
         (does not require compound Y-then-X sorting). Returns -1 if not found.
[==============================================================================}
function TPointArrayHelper.YBisectLower(const yValue: Integer): Integer; overload;
var
  l, h, m: Integer;
begin
  Result := -1;
  h := High(Self);
  if (h < 0) then
    Exit;
  l := 0;
  while (l <= h) do
  begin
    m := (l + (h - l) div 2);
    if (Self[m].Y >= yValue) then
    begin
      Result := m;
      h := (m - 1);
    end else
      l := (m + 1);
  end;
end;

{==============================================================================]
  <YBisectUpper>
  @action: Finds the last index in a Y-sorted TPointArray where Y <= yValue.
  @note: PRECONDITION: Array must be sorted by Y. Only requires simple Y sorting 
         (does not require compound Y-then-X sorting). Returns -1 if not found.
[==============================================================================}
function TPointArrayHelper.YBisectUpper(const yValue: Integer): Integer; overload;
var
  l, h, m: Integer;
begin
  Result := -1;
  h := High(Self);
  if (h < 0) then
    Exit;
  l := 0;
  while (l <= h) do
  begin
    m := (l + (h - l) div 2);
    if (Self[m].Y <= yValue) then
    begin
      Result := m;
      l := (m + 1);
    end else
      h := (m - 1);
  end;
end;
{$ENDIF}
