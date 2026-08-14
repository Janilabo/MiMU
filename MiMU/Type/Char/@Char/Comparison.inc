{$IFDEF FUNCTIONS}
function Max(const a, b: Char): Char; overload;
function Min(const a, b: Char): Char; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
