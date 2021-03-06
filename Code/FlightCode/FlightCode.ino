////////////////////////////////////////////////////////////////////////////////
// Don't forget to check that all pins are assigned correctly (they currently
// are not) and to set the experiment parameters (they currently are not).
// Better yet, actually look through the code (especially the early variable
// assignment parts) to make sure that things make sense before bricking your
// device!
////////////////////////////////////////////////////////////////////////////////
//General Includes

#include "HardwareConfiguration.h"
#include "Logger.h"

//#define IS_RUN_OPERATIONAL //Comment out if you would like to run tests only

void setup()
{
  Log_Init();
}

#ifdef IS_RUN_OPERATIONAL
#include "Logic.h"

void loop()
{
  //Operational mode
  delay(1000); //delay before starting
  RunLogic();
}
#else

#include "Driver_IMU.h"
#include "Driver_Distance.h"
#include "ImpactForecast.h"

void loop()
{
  //Blink before starting tests
  for (int i=0;i<4;i++)
  {
    Log_SetLoigcState(i);
    delay(500);
  }
    
  //Testers (uncomment if needed)
  Log_Test();     //Passed for COM, SD 060317; Flash 120517
  //IMU_Test();     //Passed 060317
  //Dist_Test();    //Passed 060317
  //Or_Prop_Test(); //Written (072717) but Not Passed Yet
  //IMFO_Test();    //Passed ImpactTime 060417, Not Passed: IMFO_WhenToStartMotor
  //Motor_Test();     //Written (071917) but Not Passed Yet

  while (true);
}

#endif
