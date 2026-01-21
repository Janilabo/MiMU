{$IFDEF FUNCTIONS}
function Max(const a, b, c: Integer): Integer; overload;
function Max(const a, b, c, d: Integer): Integer; overload;
function Max(const a: TIntegerArray): Integer; overload;
function Maximum(const a, b, c: Integer): Integer; overload;
function Min(const a, b, c: Integer): Integer; overload;
function Min(const a, b, c, d: Integer): Integer; overload;
function Min(const a: TIntegerArray): Integer; overload;
function Minimum(const a, b, c: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function Max(const a, b, c: Integer): Integer; overload;
begin
  Result := Max(Max(a, b), c);
end;

function Max(const a, b, c, d: Integer): Integer; overload;
begin
  Result := Max(Max(a, b), Max(c, d));
end;

function Max(const a: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  if (Length(a) = 0) then
    Exit(Low(Integer));
  Result := a[0];
  for i := 1 to High(a) do
    if (a[i] > Result) then
      Result := a[i];
end;

function Maximum(const a, b, c: Integer): Integer; overload;
begin
  Result := a;
  if (b > Result) then
    Result := b;
  if (c > Result) then
    Result := c;
end;

function Min(const a, b, c: Integer): Integer; overload;
begin
  Result := Min(Min(a, b), c);
end;

function Min(const a, b, c, d: Integer): Integer; overload;
begin
  Result := Min(Min(a, b), Min(c, d));
end;

function Min(const a: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  if (Length(a) = 0) then
    Exit(High(Integer));
  Result := a[0];
  for i := 1 to High(a) do
    if (a[i] < Result) then
      Result := a[i];
end;

function Minimum(const a, b, c: Integer): Integer; overload;
begin
  Result := a;
  if (b < Result) then
    Result := b;
  if (c < Result) then
    Result := c;
end;
{$ENDIF}