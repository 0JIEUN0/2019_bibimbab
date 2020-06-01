#include "준비중.h"

int arrow = 0, newbie = 0;

void user_menu() {
	int menu;
	int t, test, X, Y, color = 8;
	CursorView(0);

	if (color == 15)color = 8;
	gotoxy(13, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	printf("□□□□□□         □□        □□□□□□□  □□□□□  □□□   □□□   □□□□□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 6);
	printf("□□    □□        □□□       □□      □□     □□      □□     □□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 7);
	printf("□□               □□□□      □□               □□      □□□   □□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 8);
	printf("□□              □□  □□     □□□□□□□     □□      □□ □  □□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 9);
	printf("□□             □□    □□    □□□□□□□     □□      □□  □ □□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 10);
	printf("□□            □□□□□□□             □□     □□      □□   □□□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 11);
	printf("□□    □□   □□        □□  □□      □□     □□      □□     □□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 12);
	printf("□□□□□□  □□□      □□□ □□□□□□□  □□□□□  □□□  □□□□  □□□□□");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(40, 17);
	printf("----------[사용자 이름 설정]----------");
	gotoxy(40, 18);
	printf("l                                    l");
	gotoxy(40, 19);
	printf("l           1)사용자 선택            l");
	gotoxy(40, 20);
	printf("l                                    l");
	gotoxy(40, 21);
	printf("l           2) 신규 등록             l");
	gotoxy(40, 22);
	printf("l                                    l");
	gotoxy(40, 23);
	printf("--------------------------------------");

	X = 49;
	Y = 19;
	gotoxy(X, Y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("▷ 1) 사용자 선택");

	while (1) {
		test = getch();
		switch (test) {
		case 80:
			if (Y == 21)break;
			else {
				gotoxy(X, 19);
				printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("  1) 사용자 선택");
				gotoxy(X, 21);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				printf("▷ 2) 신규 등록");
				Y = 21;
				break;
			}

		case 72:
			if (Y == 19)break;
			else {
				gotoxy(X, 21);
				printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("  2) 신규 등록");
				gotoxy(X, 19);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				printf("▷ 1) 사용자 선택");
				Y = 19;
				break;
			}
		case 13:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			design();
			if (Y == 19)list();
			else if (Y == 21)user();
			break;
		}
		if (arrow == 1)break;
	}
	return;
}


int list() {
	int Y;
	struct user u[5];
	FILE *fb = NULL;
	int i = 0, n, end;

	gotoxy(48, 12);
	printf("+ ㅣ 사용자 선택 ㅣ +");

	fb = fopen("list.txt", "r");
	if (fb == NULL) {
		gotoxy(50, 15);
		printf("FILE OPEN ERROR\n");
		exit(0);
	}
	arrow = 1;

	fseek(fb, 0, 2);   //파일의 마지막으로 이동
	end = ftell(fb);
	if (end < 2) {
		fclose(fb);
		gotoxy(47, 15);
		printf("등록된 사용자가 없습니다.\n");
		gotoxy(40, 17);
		printf("enter 키를 누르면 신규 등록으로 넘어갑니다.");
		getch();
		newbie = 1;
		user();
		return 0;
	}

	rewind(fb);
	Y = 15;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	while (ftell(fb) != end) {
		fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
		gotoxy(50, Y++);
		printf("%d: %s", i + 1, u[i].name);
		i++;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	Y += 2;
	while (1) {
		gotoxy(43, Y + 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		puts("(신규 등록하려면 0을 입력하세요)");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoxy(43, Y);
		printf("사용자 이름의 번호를 선택하세요: ");
		scanf("%d", &n);
		getchar();
		if (n < 0 || n>i) {
			gotoxy(43, Y + 2);
			puts("                                             ");
			gotoxy(46, 24);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			printf("잘못된 값을 입력하셨습니다.");
			Sleep(1000);
			gotoxy(42, Y);
			puts("                                                   ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (n == 0) {
			user();
			return 0;
		}
		else {
			strcpy(name, u[n - 1].name);
			token = u[n - 1].score;
			break;
		}

	}
	fclose(fb);
	system("cls");
	design();
	gotoxy(33, 12);
	printf("현재 사용자의 이름은 ");
	color(6);
	printf("%s, ", name);
	color(15);
	printf("토큰은 ");
	color(6);
	printf("%d", token);
	color(15);
	printf("개 있습니다.");
	gotoxy(33, 15);
	printf("프로그램 기록은 5순위까지만 기록되고,");
	gotoxy(33, 16);
	printf("임의로 프로그램을 종료시키면 순위에 반영되지 않습니다.");
	return 0;

}

int user() {
	struct user u[5] = { 0, };
	FILE *fb = NULL;
	int k = 0, i = 0, z = 0, n, end, w;
	char g;
	system("cls");
	while (1) {
		design();
		gotoxy(48, 12);
		printf("+ ㅣ 신규  등록 ㅣ +           ");
		if (newbie == 1) {
			gotoxy(47, 15); printf("                            ");
			gotoxy(40, 17); printf("                                            ");
		}
		gotoxy(40, 15);
		printf("이름을 입력하시오(공백 없이 최대 20자)");
		CursorView(1);
		gotoxy(44, 20);
		color(6);
		puts("───────────────────────────── ");
		color(15);
		gotoxy(46, 19);
		fgets(name, 22, stdin);
		CursorView(0);
		while (1) {
			if (name[i] == ' ') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				gotoxy(46, 22);
				printf("공백은 사용할 수 없습니다.");
				Sleep(500);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				i = 0;
				break;
			}
			else if (name[i] == '\n' || name[i]=='\0') {
				name[i] = 0;
				if (i == 21) {
					color(8);
					gotoxy(47, 22);
					puts("글자 수가 초과되었습니다.");
					color(15);
					Sleep(500);
					while ((g = getchar()) != '\n');
					break;
				}
				break;
			}
			i++;
		}
		if (i == 21) {
			i = 0;
			continue;
		}
		else if (name[i] == 0) break;
	}
	i = 0;

	fb = fopen("list.txt", "r");
	if (fb == NULL) {
		printf("FILE OPEN ERROR");
		exit(0);
	}
	fseek(fb, 0, 2);	//파일의 마지막으로 이동
	end = ftell(fb);
	rewind(fb);
	while (ftell(fb) != end) {
		fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
		i++;
	}
	n = i; //등록된 사용자 수(1~5)
	i = 0;
	fclose(fb);
	while (1) {
		if (!(strcmp(name, u[k].name))) {
			while (1) {
				gotoxy(45, 18);
				printf("동일한 이름이 기록에 있습니다.");
				gotoxy(25, 19);
				printf("해당 기록을 사용하시려면 1을, 다른 이름으로 시작하시려면 0을 입력하세요: ");
				scanf("%d", &w);
				while ((g = getchar()) != '\n');
				if (w == 0) {
					strcpy(name, "");
					user();		//재입력
					return 0;
				}
				else if (w == 1) {
					token = u[k].score;
					system("cls");
					design();
					gotoxy(33, 12);
					printf("현재 사용자의 이름은 ");
					color(6);
					printf("%s, ", name);
					color(15);
					printf("토큰은 ");
					color(6);
					printf("%d", token);
					color(15);
					printf("개 있습니다.");
					gotoxy(33, 15);
					printf("프로그램 기록은 5순위까지만 기록되고,");
					gotoxy(33, 16);
					printf("임의로 프로그램을 종료시키면 순위에 반영되지 않습니다.");

					arrow = 1;
					return 0;
				}
				else {
					color(8);
					gotoxy(47, 22);
					puts("잘못된 값을 입력하셨습니다.");
					Sleep(500);
					gotoxy(55, 19);
					puts("here                                                    ");
					color(15);
				}
			}

		}
		k++;
		if (k == n) break;
	}
	token = 25;
	system("cls");
	design();
	gotoxy(33, 10);
	printf("토큰은 기본적으로 25개 주어집니다.");
	gotoxy(33, 12);
	printf("현재 사용자의 이름은 ");
	color(6);
	printf("%s, ", name);
	color(15);
	printf("토큰은 ");
	color(6);
	printf("%d", token);
	color(15);
	printf("개 있습니다.");
	gotoxy(33, 15);
	printf("프로그램 기록은 5순위까지만 기록되고,");
	gotoxy(33, 16);
	printf("임의로 프로그램을 종료시키면 순위에 반영되지 않습니다.");

	arrow = 1; //왓??

	return 0;
}

void design() {
	system("cls");
	color(3);
	gotoxy(22, 6);
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(22, 7);
	puts("■                                                                        ■");
	gotoxy(22, 8);
	puts("■                                                                        ■");
	gotoxy(22, 9);
	puts("■                                                                        ■");
	gotoxy(22, 10);
	puts("■                                                                        ■");
	gotoxy(22, 11);
	puts("■                                                                        ■");
	gotoxy(22, 12);
	puts("■                                                                        ■");
	gotoxy(22, 13);
	puts("■                                                                        ■");
	gotoxy(22, 14);
	puts("■                                                                        ■");
	gotoxy(22, 15);
	puts("■                                                                        ■");
	gotoxy(22, 16);
	puts("■                                                                        ■");
	gotoxy(22, 17);
	puts("■                                                                        ■");
	gotoxy(22, 18);
	puts("■                                                                        ■");
	gotoxy(22, 19);
	puts("■                                                                        ■");
	gotoxy(22, 20);
	puts("■                                                                        ■");
	gotoxy(22, 21);
	puts("■                                                                        ■");
	gotoxy(22, 22);
	puts("■                                                                        ■");
	gotoxy(22, 23);
	puts("■                                                                        ■");
	gotoxy(22, 24);
	puts("■                                                                        ■");
	gotoxy(22, 25);
	puts("■                                                                        ■");
	gotoxy(22, 26);
	puts("■                                                                        ■");
	gotoxy(22, 27);
	puts("■                                                                        ■");
	gotoxy(22, 28);
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	color(15);
}

void developer() {
	system("cls");
	design();
	gotoxy(0, 3);
	printf("# 보유 토큰의 수 : %d", token);
	color(9);
	gotoxy(40, 10);
	printf("버전");
	color(15);
	gotoxy(54, 10);
	printf("0.0.1");
	color(9);
	gotoxy(40, 12);
	printf("제작자");
	color(15);
	gotoxy(54, 12);
	printf("김미승");
	gotoxy(54, 13);
	printf("김지은");
	gotoxy(54, 14);
	printf("유수연");
	color(9);
	gotoxy(40, 16);
	printf("제작기간");
	color(15);
	gotoxy(54, 16);
	printf("2019.07.11 - 2019.09.17");
	color(9);
	gotoxy(40, 18);
	printf("공간 제공");
	color(15);
	gotoxy(54, 18);
	printf("카카오톡");
	gotoxy(54, 19);
	printf("투썸 충정로점");
	gotoxy(54, 20);
	printf("투썸 냅킨");
	gotoxy(54, 21);
	printf("김지은 메모장");
	color(8);
	gotoxy(40, 25);
	printf("아무 키를 누르면 메인 메뉴로 돌아갑니다.");
	getch();
	color(15);
}