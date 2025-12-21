{$IFDEF HELPERS}
function Increase(const N: Int64 = 1): Int64; overload;
function Increase(const B: Boolean): Int64; overload;
function Decrease(const N: Int64 = 1): Int64; overload;
function Decrease(const B: Boolean): Int64; overload;	
function Increment(const N: Int64 = 1): Int64; overload;
function Increment(const B: Boolean): Int64; overload;
function Decrement(const N: Int64 = 1): Int64; overload;
function Decrement(const B: Boolean): Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Increase>
  @action: Increases the Int64 value x by N.
  @note: Returns x before increasing it with N!
[==============================================================================}
function TInt64Helper.Increase(const N: Int64 = 1): Int64; overload; {$DEFINE Skeleton_Increase}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Increase}

{==============================================================================]
  <Increase>
  @action: Increases the Int64 value x by 1 if B is true.
  @note: Returns x before increasing it!
[==============================================================================}
function TInt64Helper.Increase(const B: Boolean): Int64; overload; {$DEFINE Skeleton_IncreaseB}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_IncreaseB}

{==============================================================================]
  <Decrease>
  @action: Decreases the Int64 value x by N.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TInt64Helper.Decrease(const N: Int64 = 1): Int64; overload; {$DEFINE Skeleton_Decrease}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Decrease}

{==============================================================================]
  <Decrease>
  @action: Decreases the Int64 value x by 1 if B is true.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TInt64Helper.Decrease(const B: Boolean): Int64; overload; {$DEFINE Skeleton_DecreaseB}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_DecreaseB}

{==============================================================================]
  <Increment>
  @action: Increases the Int64 value x by N.
  @note: Returns the increased x!
[==============================================================================}
function TInt64Helper.Increment(const N: Int64 = 1): Int64; overload; {$DEFINE Skeleton_Increment}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Increment}

{==============================================================================]
  <Increment>
  @action: Increases the Int64 value x by 1 if B is true.
  @note: Returns the increased x!
[==============================================================================}
function TInt64Helper.Increment(const B: Boolean): Int64; overload; {$DEFINE Skeleton_IncrementB}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_IncrementB}

{==============================================================================]
  <Decrement>
  @action: Decreases the Int64 value x by N.
  @note: Returns the decreased x!
[==============================================================================}
function TInt64Helper.Decrement(const N: Int64 = 1): Int64; overload; {$DEFINE Skeleton_Decrement}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Decrement}

{==============================================================================]
  <Decrement>
  @action: Decreases the Int64 value x by 1 if B is true.
  @note: Returns the decreased x!
[==============================================================================}
function TInt64Helper.Decrement(const B: Boolean): Int64; overload; {$DEFINE Skeleton_DecrementB}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_DecrementB}
{$ENDIF}