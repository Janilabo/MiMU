{$IFDEF FUNCTIONS}
function Max(const a, b: string): string; overload;
function Min(const a, b: string): string; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
