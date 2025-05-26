{==============================================================================]
 <Boolean_Random>
 @action: Returns random boolean.
 @note: None
[==============================================================================}

function Boolean_Random: Boolean; cdecl; inline;
begin
  Result := (Random(2) = 0);
end;
