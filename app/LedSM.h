#ifndef LedSM_H
#define LedSM_H
#include <stdint.h>
#include "State.h"

typedef struct {
  State state;
  uint32_t time;
} LedData;

#endif // LedSM_H
