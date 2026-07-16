{$IFDEF METHODS}
function FromStart(const sCount: Integer = 1): TRange; overload;
function FromStop(const sCount: Integer = 1): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <FromStart>
  @action: Extracts a sub-range of a specific size starting from the beginning.
  @note: The resulting range starts at the original Start. If sCount exceeds 
         the parent Size, the original range is effectively cloned.
[==============================================================================}
function TRange.FromStart(const sCount: Integer = 1): TRange; overload;
begin
  Result.start := Self.start;
  Result.stop := (Self.start + ((Max(0, Min(sCount, Self.Size)) - 1) * Self.Direction));
end;

{==============================================================================]
  <FromStop>
  @action: Extracts a sub-range of a specific size starting from the end.
  @note: The resulting range starts at the original Stop and grows "backwards" 
         relative to the original flow to maintain count.
[==============================================================================}
function TRange.FromStop(const sCount: Integer = 1): TRange; overload;
begin
  Result.start := Self.stop;
  Result.stop := (Self.stop - ((Max(0, Min(sCount, Self.Size)) - 1) * Self.Direction));
end;
{$ENDIF}
