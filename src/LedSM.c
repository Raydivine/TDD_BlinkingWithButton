#include "LedSM.h"
#include <stdio.h>
#include "Message.h"

void ledInitData(LedData *data){
  data->state = LED_OFF;
}

void ledSM(LedData *data){
  switch(data->state){
  
  case LED_OFF:  if
  
  default:  printf("Error: unknown state encountered in buttonSM : %d\n", data->state);
  break;
  }
}