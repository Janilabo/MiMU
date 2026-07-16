{$IFDEF METHODS}
function BitCast: Int64; overload;
procedure BitCast(const rCast: Int64); overload;
function Decode(const rPacked: Int64): Integer; overload;
function Encode: Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BitCast>
  @action: Returns a 64-bit integer representing the raw memory of this TRange instance.
           The lower 32 bits store the start value and the upper 32 bits store the stop value.
  @note: This is a low-level, unsafe operation that reinterprets the bits of Self. 
         The result is layout- and endianness-dependent. Use only when you understand
         that the returned value is tied to the exact memory representation of TRange.
[==============================================================================}
function TRange.BitCast: Int64; overload;
begin
  Result := PInt64(@Self)^;
end;

{==============================================================================]
  <BitCast>
  @action: Assigns the raw memory of Self from the given 64-bit integer.
           The lower 32 bits are assigned to start, the upper 32 bits to stop.
  @note: This is a low-level, unsafe operation that overwrites Self directly. 
         The input must represent a valid TRange layout; passing arbitrary values
         may produce an invalid or nonsensical range. Use with care.
[==============================================================================}
procedure TRange.BitCast(const rCast: Int64); overload;
begin
  PInt64(@Self)^ := rCast;
end;

{==============================================================================]
  <Decode>
  @action: Decodes a packed 64-bit value into the current TRange instance and
           returns the resulting range size.
  @note: The lower 32 bits of rPacked are assigned to start and the upper 32 bits
         to stop. This method overwrites the current instance.
[==============================================================================}
function TRange.Decode(const rPacked: Int64): Integer; overload;
begin
  Self.start := Integer(UInt32(rPacked and $FFFFFFFF));
  Self.stop := Integer(UInt32((rPacked shr 32) and $FFFFFFFF));
  Result := Self.Size;
end;

{==============================================================================]
  <Encode>
  @action: Encodes the current TRange instance into a packed 64-bit value.
  @note: The start value is stored in the lower 32 bits and the stop value in the
         upper 32 bits of the returned Int64.
[==============================================================================}
function TRange.Encode: Int64; overload;
begin
  Result := (Int64(UInt32(Self.start)) or (Int64(UInt32(Self.stop)) shl 32));
end;
{$ENDIF}