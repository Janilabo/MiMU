{==============================================================================]
 <TArray_Dupe>
 @action: Returns copy of an array arr.
 @note: None.
[==============================================================================}

// TIntegerArray
function TArray_Dupe(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i, l, j: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    if ((l mod 2) <> 0) then
    begin
      j := (l div 2);
      Result[j] := arr[j];
    end;
    if (l = 1) then
	  Exit;
    for i := 0 to ((l div 2) - 1) do
    begin
      j := ((l - i) - 1);
      Result[i] := arr[i];
      Result[j] := arr[j];
    end;
  end;
end;

// TDoubleArray
function TArray_Dupe(const arr: TDoubleArray): TDoubleArray; overload; cdecl;
var
  i, l, j: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    if ((l mod 2) <> 0) then
    begin
      j := (l div 2);
      Result[j] := arr[j];
    end;
    if (l = 1) then
	  Exit;
    for i := 0 to ((l div 2) - 1) do
    begin
      j := ((l - i) - 1);
      Result[i] := arr[i];
      Result[j] := arr[j];
    end;
  end;
end;

// TStringArray
function TArray_Dupe(const arr: TStringArray): TStringArray; overload; cdecl;
var
  i, l, j: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    if ((l mod 2) <> 0) then
    begin
      j := (l div 2);
      Result[j] := arr[j];
    end;
    if (l = 1) then
	  Exit;
    for i := 0 to ((l div 2) - 1) do
    begin
      j := ((l - i) - 1);
      Result[i] := arr[i];
      Result[j] := arr[j];
    end;
  end;
end;

// TCharArray
function TArray_Dupe(const arr: TCharArray): TCharArray; overload; cdecl;
var
  i, l, j: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    if ((l mod 2) <> 0) then
    begin
      j := (l div 2);
      Result[j] := arr[j];
    end;
    if (l = 1) then
	  Exit;
    for i := 0 to ((l div 2) - 1) do
    begin
      j := ((l - i) - 1);
      Result[i] := arr[i];
      Result[j] := arr[j];
    end;
  end;
end;

// TBooleanArray
function TArray_Dupe(const arr: TBooleanArray): TBooleanArray; overload; cdecl;
var
  i, l, j: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    if ((l mod 2) <> 0) then
    begin
      j := (l div 2);
      Result[j] := arr[j];
    end;
    if (l = 1) then
	  Exit;
    for i := 0 to ((l div 2) - 1) do
    begin
      j := ((l - i) - 1);
      Result[i] := arr[i];
      Result[j] := arr[j];
    end;
  end;
end;

// TPointArray
function TArray_Dupe(const arr: TPointArray): TPointArray; overload; cdecl;
var
  i, l, j: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    if ((l mod 2) <> 0) then
    begin
      j := (l div 2);
      Result[j] := arr[j];
    end;
    if (l = 1) then
	  Exit;
    for i := 0 to ((l div 2) - 1) do
    begin
      j := ((l - i) - 1);
      Result[i] := arr[i];
      Result[j] := arr[j];
    end;
  end;
end;

// TBoxArray
function TArray_Dupe(const arr: TBoxArray): TBoxArray; overload; cdecl;
var
  i, l, j: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    if ((l mod 2) <> 0) then
    begin
      j := (l div 2);
      Result[j] := arr[j];
    end;
    if (l = 1) then
	  Exit;
    for i := 0 to ((l div 2) - 1) do
    begin
      j := ((l - i) - 1);
      Result[i] := arr[i];
      Result[j] := arr[j];
    end;
  end;
end;

// TRangeArray
function TArray_Dupe(const arr: TRangeArray): TRangeArray; overload; cdecl;
var
  i, l, j: Int32;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    if ((l mod 2) <> 0) then
    begin
      j := (l div 2);
      Result[j] := arr[j];
    end;
    if (l = 1) then
	  Exit;
    for i := 0 to ((l div 2) - 1) do
    begin
      j := ((l - i) - 1);
      Result[i] := arr[i];
      Result[j] := arr[j];
    end;
  end;
end;