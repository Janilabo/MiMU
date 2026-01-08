{$IFDEF HELPERS}
function Mode: MType; overload; cdecl;
function Center: MType; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Mode>
  @action: The value that occurs most frequently in arr.
  @note: None
[==============================================================================}
function MArrayHelper.Mode: MType; overload; cdecl;
var
  a: MArray;
  c: TIntegerArray;
  h, i, j, l: Integer;
begin
  h := High(Self);
  if (h > -1) then
  case (h = 0) of
    False:
    begin
      SetLength(c, 0);
      SetLength(a, 0);
      for i := 0 to High(Self) do
      begin
        l := -1;
        for j := 0 to High(a) do
          if (Self[i] = a[j]) then
          begin
            l := j;
            Break;
          end;
        if (l = -1) then
        begin
          a := a.Append(Self[i]);
          c := c.Append(1);
        end else
          Inc(c[l]);
      end;
      Result := a[c.Maxi];
    end;
    True: Result := Self[0];
  end;
end;

{==============================================================================]
  <Center>
  @action: The value at the center position of a sorted or unsorted arr.
  @note: None
[==============================================================================}
function MArrayHelper.Center: MType; overload; cdecl;
begin
  if (Self.Size > 0) then
    Result := Self[Self.Size div 2];
end;
{$ENDIF}