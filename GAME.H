#ifndef GAME_H_
#define GAME_H_

#include "actor.h"
#include "def.h"

#define VERSION		"0.22.1A"
#define YEAR		"2023, 2024"

#define STATE_INIT	0
#define STATE_TITLE	1
#define STATE_MENU	2
#define STATE_GAME	3
#define STATE_G_OVER	4
#define STATE_SYSTEM	5
#define STATE_EXIT	6

#define D_UP		0
#define D_LEFT		1
#define D_DOWN		2
#define D_RIGHT		3

typedef struct {
 u8 state;
 u8 command;
 actor pActor;
 u8 inMenu;
} game;

void gainXP();
void advanceTurn();
u8 checkMap(u8, u8);
u8 interact(u8, u8);
void attackPlayer();
void attackNPC(u8);
void lootNPC(u8);


#endif