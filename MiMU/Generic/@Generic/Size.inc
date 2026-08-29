{$IFDEF FUNCTIONS}
generic function SetSize<T>(var A, B: specialize TArray<T>; const size: Integer = 1): Integer; overload;
generic function SetSize<T>(var A, B, C: specialize TArray<T>; const size: Integer = 1): Integer; overload;
generic function SetSize<T>(var A, B, C, D: specialize TArray<T>; const size: Integer = 1): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SetSize>
  @action: Resizes two dynamic arrays to the specified size.
  @note: Returns the size used. Size is clamped to 0 minimum. Overloaded for multiple arrays.
[==============================================================================}
generic function SetSize<T>(var A, B: specialize TArray<T>; const size: Integer = 1): Integer; overload;
begin
  Result := Max(0, size);
  SetLength(A, Result);
  SetLength(B, Result);
end;

{==============================================================================]
  <SetSize>
  @action: Resizes three dynamic arrays to the specified size.
  @note: Returns the size used. Size is clamped to 0 minimum. Overloaded for multiple arrays.
[==============================================================================}
generic function SetSize<T>(var A, B, C: specialize TArray<T>; const size: Integer = 1): Integer; overload;
begin
  Result := Max(0, size);
  SetLength(A, Result);
  SetLength(B, Result);
  SetLength(C, Result);
end;

{==============================================================================]
  <SetSize>
  @action: Resizes four dynamic arrays to the specified size.
  @note: Returns the size used. Size is clamped to 0 minimum. Overloaded for multiple arrays.
[==============================================================================}
generic function SetSize<T>(var A, B, C, D: specialize TArray<T>; const size: Integer = 1): Integer; overload;
begin
  Result := Max(0, size);
  SetLength(A, Result);
  SetLength(B, Result);
  SetLength(C, Result);
  SetLength(D, Result);
end;
{$ENDIF}