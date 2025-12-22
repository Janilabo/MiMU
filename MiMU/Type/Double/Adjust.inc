{$IFDEF HELPERS}
function Increase(const N: Double = 1): Double; overload;
function Increase(const B: Boolean): Double; overload;
function Decrease(const N: Double = 1): Double; overload;
function Decrease(const B: Boolean): Double; overload;
function Increment(const N: Double = 1): Double; overload;
function Increment(const B: Boolean): Double; overload;
function Decrement(const N: Double = 1): Double; overload;
function Decrement(const B: Boolean): Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Increase>
  @action: Increases the Double value x by N.
  @note: Returns x before increasing it with N!
[==============================================================================}
function TDoubleHelper.Increase(const N: Double = 1): Double; overload; {$DEFINE Skeleton_Increase}{$I ../Skeletons.inc}{$UNDEF Skeleton_Increase}

{==============================================================================]
  <Increase>
  @action: Increases the Double value x by 1 if B is true.
  @note: Returns x before increasing it!
[==============================================================================}
function TDoubleHelper.Increase(const B: Boolean): Double; overload; {$DEFINE Skeleton_IncreaseB}{$I ../Skeletons.inc}{$UNDEF Skeleton_IncreaseB}

{==============================================================================]
  <Decrease>
  @action: Decreases the Double value x by N.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TDoubleHelper.Decrease(const N: Double = 1): Double; overload; {$DEFINE Skeleton_Decrease}{$I ../Skeletons.inc}{$UNDEF Skeleton_Decrease}

{==============================================================================]
  <Decrease>
  @action: Decreases the Double value x by 1 if B is true.
  @note: Returns x before decreasing it!
[==============================================================================}
function TDoubleHelper.Decrease(const B: Boolean): Double; overload; {$DEFINE Skeleton_DecreaseB}{$I ../Skeletons.inc}{$UNDEF Skeleton_DecreaseB}

{==============================================================================]
  <Increment>
  @action: Increases the Double value x by N.
  @note: Returns the increased x!
[==============================================================================}
function TDoubleHelper.Increment(const N: Double = 1): Double; overload; {$DEFINE Skeleton_Increment}{$I ../Skeletons.inc}{$UNDEF Skeleton_Increment}

{==============================================================================]
  <Increment>
  @action: Increases the Double value x by 1 if B is true.
  @note: Returns the increased x!
[==============================================================================}
function TDoubleHelper.Increment(const B: Boolean): Double; overload; {$DEFINE Skeleton_IncrementB}{$I ../Skeletons.inc}{$UNDEF Skeleton_IncrementB}

{==============================================================================]
  <Decrement>
  @action: Decreases the Double value x by N.
  @note: Returns the decreased x!
[==============================================================================}
function TDoubleHelper.Decrement(const N: Double = 1): Double; overload; {$DEFINE Skeleton_Decrement}{$I ../Skeletons.inc}{$UNDEF Skeleton_Decrement}

{==============================================================================]
  <Decrement>
  @action: Decreases the Double value x by 1 if B is true.
  @note: Returns the decreased x!
[==============================================================================}
function TDoubleHelper.Decrement(const B: Boolean): Double; overload; {$DEFINE Skeleton_DecrementB}{$I ../Skeletons.inc}{$UNDEF Skeleton_DecrementB}
{$ENDIF}