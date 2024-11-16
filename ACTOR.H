#ifndef ACTOR_H_
#define ACTOR_H_

#include "def.h"

typedef struct {
 u8 x;
 u8 y;
 u8 dir;
} actor;

void setActor(actor*, u8, u8);
void moveActor(actor*, i8, i8);

#endif