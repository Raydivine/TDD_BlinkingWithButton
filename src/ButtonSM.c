#include "ButtonSM.h"
#include <stdio.h>
#include "Message.h"

void buttonInitData(ButtonData *data){
  data->state = RELEASE;
}


void buttonSM(ButtonData *data){
  switch(data->state){
  
  MESSAGE = change_mode;
  data->state = PRESS;
  
  
  
  default:  printf("Error: unknown state encountered in buttonSM : %d\n", data->state);
  break;
  }
}