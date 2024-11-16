#include "actor.h"

void setActor(actor* Actor, u8 x, u8 y) { Actor->x=x; Actor->y=y; }

void moveActor(actor* Actor, i8 x, i8 y) { Actor->x+=x; Actor->y+=y; }