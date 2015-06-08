#include <stdio.h>
#include "ButtonSM.h"
#include "Button.h"
#include "Message.h"

void buttonInitData(ButtonData *data)  {
  data->state = RELEASE;
}

void buttonSM(ButtonData *data) {
  switch(data->state)  {
    case RELEASE:   if(isButtonPressed()){
                      msg = CHANGE_MODE;
                      data->state = PRESS;
                      printf("button is pressed\n");
                    }
                    break;

    case PRESS:
      break;

    default:
      printf("Error: unknown state encountered in buttonSM: %d\n", data->state);
      break;
  }
}
