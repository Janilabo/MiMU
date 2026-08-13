{$IFDEF HELPERS}
function Precede(const target: string; const aAscending: Boolean): Boolean; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Comparison(const A, B: string): Integer; overload;
function Max(const a, b: string): string; overload;
function Min(const a, b: string): string; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TStringHelper.Precede(const target: string; const aAscending: Boolean): Boolean; overload;
begin
  Result := ((aAscending and (Self <= target)) or ((not aAscending) and (Self >= target)));
end;

function Comparison(const A, B: string): Integer; overload;
begin
  if (A < B) then
    Exit(-1);
  if (A > B) then
    Exit(1);
  Result := 0;
end;

function Max(const A, B: string): string; overload;
begin
  if (A > B) then
    Result := A
  else
    Result := B;
end;

function Min(const A, B: string): string; overload;
begin
  if (A < B) then
    Result := A
  else
    Result := B;
end;
{$ENDIF}
