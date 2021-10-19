#include "emailAlerter.h"
#include "stats.h"

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
  /* check whether max value is more than threshold*/
  /*raises alerts when max is greater than threshold*/
  int number_of_alerts = 2;
  if(computedStats.max > maxThreshold)
  {
    for(int id = 0; id<number_of_alerts;id++)
    {
      (*alerters[id])(); /* calling email alert or led alert function based on id ( 0 ==> email alert ,  1==> led alert)*/
    }
  }
  else
  {
    /* everything is under range, no alert is needed.*/
  }
}

void emailAlerter(void)
{
  ++emailAlertCallCount; /* increment the count for email alert */
}
void ledAlerter(void)
{
  ++ledAlertCallCount;  /* increment the count for led alert */
}
