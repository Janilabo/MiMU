{$IFDEF HELPERS}
function Select(const sTrue, sFalse: Integer): TIntegerArray; overload;
function Select(const sTrue, sFalse: Double): TDoubleArray; overload;
function Select(const sTrue, sFalse: string): TStringArray; overload;
function Select(const sTrue, sFalse: Char): TCharArray; overload;
function Select(const sTrue, sFalse: Boolean): TBooleanArray; overload;
function Select(const sTrue, sFalse: TPoint): TPointArray; overload;
function Select(const sTrue, sFalse: TBox): TBoxArray; overload;
function Select(const sTrue, sFalse: TRange): TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Select>
  @action: IfThen method for TBooleanArray.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Integer): TIntegerArray; overload; {$I Skeletons/Select.inc}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Double): TDoubleArray; overload; {$I Skeletons/Select.inc}
function TBooleanArrayHelper.Select(const sTrue, sFalse: string): TStringArray; overload; {$I Skeletons/Select.inc}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Char): TCharArray; overload; {$I Skeletons/Select.inc}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Boolean): TBooleanArray; overload; {$I Skeletons/Select.inc}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TPoint): TPointArray; overload; {$I Skeletons/Select.inc}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TBox): TBoxArray; overload; {$I Skeletons/Select.inc}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TRange): TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    if Self[i] then
      Result[i] := sTrue
    else
      Result[i] := sFalse;
end;
{$ENDIF}
