/*----------------------------------------------------------------------
  Generate Sine Wave Signal on AD Channel 2
----------------------------------------------------------------------*/
SIGNAL void AIN2_Sine (void)  {
  float volts;        // peak-to-peak voltage
  float frequency;    // output frequency in Hz
  float offset;       // voltage offset
  float duration;     // duration in Seconds
  float val;
  long  i, end;

  volts     = 1.4;
  offset    = 1.6;
  frequency = 1800;
  duration  = 0.1;

  printf ("Sine Wave Signal on AD Channel 2.\n");

  end = (duration * 100000);
  for (i = 0 ; i < end; i++)  {
    val = __sin (frequency * (((float) STATES) / CLOCK) * 2 * 3.1415926);
    AIN2 = (val * volts) + offset;
    swatch (0.00001);                // in 10 uSec steps
  }
}

DEFINE BUTTON "AIN2 Sin","AIN2_Sine()"