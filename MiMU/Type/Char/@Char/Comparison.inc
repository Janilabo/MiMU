{$IFDEF HELPERS}
function Precede(const target: Char; const aAscending: Boolean): Boolean; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Comparison(const A, B: Char): Integer; overload;
function Max(const a, b: Char): Char; overload;
function Min(const a, b: Char): Char; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TCharHelper.Precede(const target: Char; const aAscending: Boolean): Boolean; overload;
begin
  Result := ((aAscending and (Self <= target)) or ((not aAscending) and (Self >= target)));
end;

function Comparison(const A, B: Char): Integer; overload;
begin
  if (A < B) then
    Exit(-1);
  if (A > B) then
    Exit(1);
  Result := 0;
end;

function Max(const A, B: Char): Char; overload;
begin
  if (A > B) then
    Result := A
  else
    Result := B;
end;

function Min(const A, B: Char): Char; overload;
begin
  if (A < B) then
    Result := A
  else
    Result := B;
end;
{$ENDIF}