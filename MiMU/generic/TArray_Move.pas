{==============================================================================]
 <TArray_Move>
 @action: Moves item from oldIndex to newIndex in array arr.
 @note: Returns true with success.
[==============================================================================}

// TIntegerArray
function TArray_Move(var arr: TIntegerArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
var
  h, i, t: Int32;
begin
  h := High(arr);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    t := arr[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        arr[i] := arr[(i - 1)];
      False:
      for i := oldIndex to (newIndex - 1) do
        arr[i] := arr[(i + 1)];
    end;
    arr[newIndex] := t;
  end;
end;

// TDoubleArray
function TArray_Move(var arr: TDoubleArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
var
  h, i: Int32;
  t: Double;
begin
  h := High(arr);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    t := arr[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        arr[i] := arr[(i - 1)];
      False:
      for i := oldIndex to (newIndex - 1) do
        arr[i] := arr[(i + 1)];
    end;
    arr[newIndex] := t;
  end;
end;

// TStringArray
function TArray_Move(var arr: TStringArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
var
  h, i: Int32;
  t: string;
begin
  h := High(arr);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    t := arr[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        arr[i] := arr[(i - 1)];
      False:
      for i := oldIndex to (newIndex - 1) do
        arr[i] := arr[(i + 1)];
    end;
    arr[newIndex] := t;
  end;
end;

// TCharArray
function TArray_Move(var arr: TCharArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
var
  h, i: Int32;
  t: Char;
begin
  h := High(arr);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    t := arr[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        arr[i] := arr[(i - 1)];
      False:
      for i := oldIndex to (newIndex - 1) do
        arr[i] := arr[(i + 1)];
    end;
    arr[newIndex] := t;
  end;
end;

// TBooleanArray
function TArray_Move(var arr: TBooleanArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
var
  h, i: Int32;
  t: Boolean;
begin
  h := High(arr);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    t := arr[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        arr[i] := arr[(i - 1)];
      False:
      for i := oldIndex to (newIndex - 1) do
        arr[i] := arr[(i + 1)];
    end;
    arr[newIndex] := t;
  end;
end;

// TPointArray
function TArray_Move(var arr: TPointArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
var
  h, i: Int32;
  t: TPoint;
begin
  h := High(arr);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    t := arr[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        arr[i] := arr[(i - 1)];
      False:
      for i := oldIndex to (newIndex - 1) do
        arr[i] := arr[(i + 1)];
    end;
    arr[newIndex] := t;
  end;
end;

// TBoxArray
function TArray_Move(var arr: TBoxArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
var
  h, i: Int32;
  t: TBox;
begin
  h := High(arr);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    t := arr[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        arr[i] := arr[(i - 1)];
      False:
      for i := oldIndex to (newIndex - 1) do
        arr[i] := arr[(i + 1)];
    end;
    arr[newIndex] := t;
  end;
end;

// TRangeArray
function TArray_Move(var arr: TRangeArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
var
  h, i: Int32;
  t: TRange;
begin
  h := High(arr);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    t := arr[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        arr[i] := arr[(i - 1)];
      False:
      for i := oldIndex to (newIndex - 1) do
        arr[i] := arr[(i + 1)];
    end;
    arr[newIndex] := t;
  end;
end;
