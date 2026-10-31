{$IFDEF FUNCTIONS}
function Minor(const a, b: Integer): Integer; overload;
function Major(const a, b: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Minor>
  @action: Returns the minimum of two integers (a and b) using branchless bitwise operations.
  @note: Implements a branchless min function without conditional jumps (no if/else), optimizing performance by avoiding branch mispredictions in tight loops.
[==============================================================================}
function Minor(const a, b: Integer): Integer; overload;
begin
  Result := (b xor ((a xor b) and -Ord(a < b)));
end;

{==============================================================================]
  <Major>
  @action: Returns the maximum of two integers (a and b) using branchless bitwise operations.
  @note: Implements a branchless max function without conditional jumps (no if/else), optimizing performance by avoiding branch mispredictions in tight loops.
[==============================================================================}
function Major(const a, b: Integer): Integer; overload;
begin
  Result := (b xor ((a xor b) and -Ord(a > b)));
end;
{$ENDIF}
