{$IFDEF TYPES}
function Contract(const N: Integer = 1): TRange; overload; 
function Contracted(const N: Integer = 1): TRange; overload; 
function Expand(const N: Integer = 1): TRange; overload; 
function Expanded(const N: Integer = 1): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Contract>
  @action: Moves both range bounds toward each other by the given amount N,
           effectively reducing the range span. Modifies Self in place and
           returns the original (pre-contracted) range.
  @note:   Direction-aware; contracts correctly for both ascending and
           descending ranges.
[==============================================================================}
function TRange.Contract(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  if Self.Ascending then
    Self.Modify(N, -N)
  else
    Self.Modify(-N, N);
end;

{==============================================================================]
  <Contracted>
  @action: Returns a new TRange contracted by the given amount N without
           modifying Self.
  @note:   Functional style version of Contract; preserves Self and is safe
           for use in expressions or chainable operations.
[==============================================================================}
function TRange.Contracted(const N: Integer = 1): TRange; overload;
begin
  if Self.Ascending then
    Result.Create((Self.start + N), (Self.stop - N))
  else
    Result.Create((Self.start - N), (Self.stop + N));
end;

{==============================================================================]
  <Expand>
  @action: Moves both bounds of the range away from each other by the given
           amount N, effectively increasing the span of the range. Modifies Self
           in place and returns the original (pre-expanded) range.
  @note:   Direction-aware; expands correctly for both ascending and descending
           ranges. Used when the current range should grow outward.
[==============================================================================}
function TRange.Expand(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  if Self.Ascending then
    Self.Modify(-N, N)
  else
    Self.Modify(N, -N);
end;

{==============================================================================]
  <Expanded>
  @action: Returns a new TRange expanded by the given amount N without modifying
           Self.
  @note:   Functional version of Expand. Preserves the original range and can
           be used in expression-style or chainable operations. Handles both
           ascending and descending ranges.
[==============================================================================}
function TRange.Expanded(const N: Integer = 1): TRange; overload;
begin
  if Self.Ascending then
    Result.Create((Self.start - N), (Self.stop + N))
  else
    Result.Create((Self.start + N), (Self.stop - N));
end;
{$ENDIF}