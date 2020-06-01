#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define ROUL_X 65

unsigned int token;
char name[22];

struct user {
	char name[22];
	int score;
};
struct roul {
	int x;
	int y;
	int num;
};

void menu2();
void Russian_roulette();
void draw_gun(int n);
void out();
void user_menu();
int list();
int user();
void developer();

int rank();
int end_rank();
void draw_rank(int k);

int show_rule(int);
void design();

void horse();
int select_horse();
int run_horse(int, int);
void horse_design();

void black();
void player_card(int *i, int *j);
void vs_card(int *i, int *j);
void card_design(int, int, int);

void slot();
int play_slot();
void show_rule3();
void draw_machine();

void roulette();
void roulette_bet(int, int *);
int draw_roulette(struct roul r[], int);

void taisai();
void show_rule2();
int play(int bet);
void show_dice(int dice[], int n);

void gotoxy(int x, int y);
void color(int color_number);
void CursorView(char show);

void opening();
void ending();
void human(int a, int b);
void build();
void door();
void board();
void board_t();
void star();
void line();
void game_over();
void beg();
void lucky_box();