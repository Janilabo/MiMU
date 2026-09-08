{$IFDEF TYPES}
generic TPair<T1, T2> = record
  first: T1;
  second: T2;
  constructor Create(const AFirst: T1; const ASecond: T2);
  class function Build(const AFirst: T1; const ASecond: T2): TPair; static;
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Build>
  @action: Constructs and initializes a new TPair instance with the specified 
           values.
  @note: Static factory method returning a populated TPair record without 
         requiring class/record instantiation syntax.
[==============================================================================}
class function TPair.Build(const AFirst: T1; const ASecond: T2): TPair;
begin
  Result.first := AFirst;
  Result.second := ASecond;
end;

{==============================================================================]
  <Create>
  @action: Initializes a TPair instance in-place with the provided values.
  @note: Record constructor allowing direct variable instantiation 
         (e.g., MyPair := TPair.Create(Val1, Val2)).
[==============================================================================}
constructor TPair.Create(const AFirst: T1; const ASecond: T2);
begin
  Self.first := AFirst;
  Self.second := ASecond;
end;
{$ENDIF}