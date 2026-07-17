{$IFDEF METHODS}
function Divergency(const b: TRange): Integer; overload;
function Variance(const b: TRange): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Divergency>
  @action: Returns the count of normalized boundaries (0, 1, or 2) that differ
           between Self and b, rather than a simple Boolean mismatch flag.
  @note: 
    - Uses normalized bounds (Minimum/Maximum) instead of raw start/stop,
      making the count direction-insensitive: 0..3 and 3..0 yield 0.
    - 0: ranges are Matchet-equal.
    - 1: exactly one boundary (Minimum XOR Maximum) differs — a partial match.
    - 2: both boundaries differ.
    - Direction-insensitive sibling of Divergence (formerly named Variance),
      mirroring the raw-vs-normalized split seen across the Differ/Mismatch families.
[==============================================================================}
function TRange.Divergency(const b: TRange): Integer; overload;
begin
  Result := (Ord(Self.Minimum <> b.Minimum) + Ord(Self.Maximum <> b.Maximum));
end;

{==============================================================================]
  <Variance>
  @action: Returns the count of boundaries (0, 1, or 2) that differ between
           Self and b, rather than a simple Boolean mismatch flag.
  @note: 
    - 0: ranges are Equal.
    - 1: exactly one boundary (start XOR stop) differs — a partial match.
    - 2: both boundaries differ.
[==============================================================================}
function TRange.Variance(const b: TRange): Integer; overload;
begin
  Result := (Ord(Self.start <> b.start) + Ord(Self.stop <> b.stop));
end;
{$ENDIF}
