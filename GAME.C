#include <conio.h>
#include <stdio.h>

#include "game.h"

game _game;
char* msglog[8];

void setState(char state) { _game.state = state; }

void helloworld() {
 textcolor(RED+BLINK);
 clrscr();
 gotoxy(35,12);
 cprintf("Hello world!");
 getch();
 setState(STATE_EXIT);
}

void titleScreen() {
 clrscr();
 textcolor(YELLOW);
 gotoxy(34,8);
 cprintf("VAMPIRE QUEST");
 textcolor(DARKGRAY);
 gotoxy(28,10);
 cprintf("Prototype Version %s", VERSION);
 textcolor(MAGENTA);
 gotoxy(32,14); cprintf("(N)ew game");
 gotoxy(32,15); cprintf("(L)oad game");
 gotoxy(32,16); cprintf("(H)elp");
 gotoxy(32,17); cprintf("(S)ystem Options");
 gotoxy(32,18); cprintf("(Q)uit to DOS");
 gotoxy(80,25);
 _game.command = getch();
 switch(_game.command){
  case 'N': case 'n':
   _game.state = STATE_GAME;
   break;
  case 'Q': case 'q': default:
   _game.state = STATE_EXIT;
   break;
 }
}

void drawMessageLog() {
 int i;
 for(i=0;i<8;i++){
	     if(i>=7) { textcolor(WHITE); }
	else if(i>4)  { textcolor(LIGHTGRAY); }
	else          { textcolor(DARKGRAY); }
	gotoxy(40,18+i);
	cprintf(msglog[i]);
 }

}

void printMessage(char* msg) {
 char* lastmsglog[7];
 int i;
 for(i=0;i<7;i++){
	lastmsglog[i]=msglog[i+1];
 }
 for(i=0         ;i<7;i++){
	msglog[i]=lastmsglog[i];
 }
 msglog[7] = msg;
}

void drawMap() {
 /*draw player  */
 gotoxy(_game.pActor.x,
	_game.pActor.y);
 textcolor(YELLOW);
 putch('@');
}

void printStatus() {
 gotoxy(2,18);
 textcolor(GREEN);
 cprintf("HP:  %i/%i",80,100);
 gotoxy(2,20);
 textcolor(RED);
 cprintf("VP:  000**");
}

void drawGameScreen(){
 clrscr();
 drawMap();
 drawMessageLog();
 printStatus();
 gotoxy(80,25);
}

void endscreen() {
 textcolor(LIGHTGRAY);textbackground(BLACK);
 clrscr();
 printf("Thank you for playing Vampire Quest.");
}

void input(){
 _game.command = getch();
 switch(_game.command){
  case 'W': case 'w':
	printMessage("Up!");
	moveActor(&_game.pActor,0,-1);
	break;
  case 'S': case 's':
	printMessage("Down!");
	moveActor(&_game.pActor,0,1);
	break;
  case 'A': case 'a':
	printMessage("Left!");
	moveActor(&_game.pActor,-1,0);
	break;
  case 'D': case 'd':
	printMessage("Right!");
	moveActor(&_game.pActor,1,0);
	break;
  case 'F': case 'f':
	printMessage("Bye");
	_game.state = STATE_EXIT;
	break;
 }
}

void advanceTurn(){

}

void update() {
 switch(_game.state){
	case STATE_INIT:
	 printf("Vampire Quest\nVer %s\n(C)%s VampSoft", VERSION, YEAR );
	 _game.state = STATE_TITLE;
	 break;
	case STATE_TITLE:
	 titleScreen();
	 break;
	case STATE_GAME:
	 input();
	 advanceTurn();
	 drawGameScreen();
	 break;
	case STATE_EXIT: default:
	 break;
 }
}

void init() {
 _game.state = STATE_INIT;
 setActor(&_game.pActor,16,8);
 msglog[7] = "Press f to quit to DOS";
}

int main() {
 init();
 while(_game.state != STATE_EXIT){ update(); }
 endscreen();
}
