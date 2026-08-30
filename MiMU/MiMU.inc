{$IFNDEF IMPLEMENTATION}
  {Radix sets}
  BINARY_CHARS: set of Char = ['0', '1'];
  BINARY_BITS: set of Byte = [0, 1];
  BINARY_BOOLS: set of Boolean = [False, True];
  BINARY_CODES: set of Byte = [48, 49];
  DIGIT_CHARS: set of Char = ['0'..'9'];
  SIGN_CHARS: set of Char = ['+', '-'];
  
  BOOL_CHR: array[Boolean] of Char = ('0', '1');
  BOOL_BIT: array[Boolean] of Byte = (0, 1);
  BOOL_STR: array[Boolean] of string = ('False', 'True');
  
  {Digit value tables}
  DECIMAL_VALUES: array['0'..'9'] of Byte = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  BASE_DIGITS: array[0..9] of Byte = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  DIGIT_MINIMA: array[0..18] of Int64 = (
    0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000,
    10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000
  );
  DIGIT_MAXIMA: array[0..18] of Int64 = (
    0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999, 99999999999, 999999999999, 9999999999999,
    99999999999999, 999999999999999, 9999999999999999, 99999999999999999, 999999999999999999
  );
  
  {Power tables}
  POWERS_OF_TEN: array[0..18] of Int64 = (
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000,
	10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000
  );
  POWERS_OF_TWO: array[0..62] of Int64 = (
    1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576,
    2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648,
    4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776,
    2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312,
    1125899906842624, 2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984, 36028797018963968,
    72057594037927936, 144115188075855872, 288230376151711744, 576460752303423488, 1152921504606846976, 2305843009213693952, 4611686018427387904
  );
  
  WHITESPACE_CHARS: set of Char = [#9, #10, #13, #32];
  ALPHA_CHARS: set of Char = ['A'..'Z', 'a'..'z'];
  UPPER_CHARS: set of Char = ['A'..'Z'];
  LOWER_CHARS: set of Char = ['a'..'z'];
  
  NULL = #0;
  TAB = #9;
  LF = #10;
  CR = #13;
  SPACE = #32;
  CRLF = #13#10;

  MIN_INTEGER: Integer = -2147483648;
  MAX_INTEGER: Integer = 2147483647;
  MIN_INT64: Int64 = -9223372036854775808;
  MAX_INT64: Int64 = 9223372036854775807;
  
  {$DEFINE TYPES}
  type
    TByteSet = set of Byte;
    TVariantArray = array of Variant;
    TConstArray = array of TVarRec;
  {$I Generic/Generic.inc}
  {$I Type/Type+.inc}
  {$I TArray/TArray+.inc}
  {$i T2DArray/T2DArray+.inc}
  {$UNDEF TYPES}

  {$DEFINE OPERATORS}
  {$I Type/Type+.inc}
  {$UNDEF OPERATORS}

  {$DEFINE HELPERS}
  type
  {$I Type/Type+.inc}
  {$I TArray/TArray+.inc}
  {$i T2DArray/T2DArray+.inc}
  {$UNDEF HELPERS}

  {$DEFINE FUNCTIONS}
  {$I Generic/Generic.inc}
  {$I Type/Type+.inc}
  {$I TArray/TArray+.inc}
  {$i T2DArray/T2DArray+.inc}
  {$I Miscellaneous/BinarySearch.inc}
  {$I Miscellaneous/Bounds.inc}
  {$I Miscellaneous/Mathematics.inc}
  {$I Miscellaneous/Randomness.inc}
  {$I Miscellaneous/Select.inc}
  {$UNDEF FUNCTIONS}

  {$DEFINE CLASSES}
  type
  {$DEFINE TBS}
    TBinarySearch = class
    public
    {$I TArray/TArray+.inc}
    end;
  {$UNDEF TBS}
  {$DEFINE T1D}
    T1D = class
    public
    {$I TArray/TArray+.inc}
    end;
  {$UNDEF T1D}
  {$DEFINE T2D}
    T2D = class
    public
    {$i T2DArray/T2DArray+.inc}
    end;
  {$UNDEF T2D}
  {$UNDEF CLASSES}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
  {$I Generic/Generic.inc}
  {$I Type/Type+.inc}
  {$I TArray/TArray+.inc}
  {$i T2DArray/T2DArray+.inc}
  {$I Miscellaneous/BinarySearch.inc}
  {$I Miscellaneous/Bounds.inc}
  {$I Miscellaneous/Mathematics.inc}
  {$I Miscellaneous/Randomness.inc}
  {$I Miscellaneous/Select.inc}
{$ENDIF}