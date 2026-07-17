{$IFDEF METHODS}
function Comparable(const target: TRange; const tolerance: Integer = 0): Boolean; overload;
function Tolerable(const target: TRange; const tolerance: Integer = 0): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Comparable>
  @action: Determines whether two ranges are equal within a given tolerance.
  @note: 
    - Compares Abs(start deltas) and Abs(stop deltas) against `tolerance` independently.
    - tolerance = 0 degenerates to exact equality.
    - Direction-sensitive; use Comparabel for a normalized, direction-insensitive variant.
[==============================================================================}
function TRange.Comparable(const target: TRange; const tolerance: Integer = 0): Boolean; overload;
begin
  Result := ((Abs(Self.start - target.start) <= tolerance) and (Abs(Self.stop - target.stop) <= tolerance));
end;

{==============================================================================]
  <Tolerable>
  @action: Determines whether two ranges are equal within a given tolerance, 
           after normalizing both ranges to account for reversed bounds.
  @note: 
    - Direction-insensitive sibling of Comparable.
    - Normalizes both ranges first, resolving inverted bounds (where start > stop) 
      before running the tolerance comparison.
[==============================================================================}
function TRange.Tolerable(const target: TRange; const tolerance: Integer = 0): Boolean; overload;
var
  s, t: TRange;
begin
  s := Self.Normalized;
  t := target.Normalized;
  Result := ((Abs(s.start - t.start) <= tolerance) and (Abs(s.stop - t.stop) <= tolerance));
end;
{$ENDIF}
