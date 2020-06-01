#include "준비중.h"

void user_menu() {
	int menu;
	char t;

	while (1) {
		system("cls");
		gotoxy(42, 5);
		color(3);
		puts("카지노 게임에 오신 것을 환영합니다!");
		color(15);
		gotoxy(49, 8);
		puts("사용자를 등록해주세요.");
		gotoxy(45, 10);
		puts("1) 기존 사용자 선택");
		gotoxy(45, 11);
		puts("2) 신규 등록");
		color(5);
		gotoxy(50, 14);
		puts("┌───────────────┐ ");
		gotoxy(50, 15);
		puts("│               │ ");
		gotoxy(50, 16);
		puts("│               │ ");
		gotoxy(50, 17);
		puts("│               │ ");
		gotoxy(50, 18);
		puts("└───────────────┘ ");
		gotoxy(55, 16);
		puts("입력: ");
		gotoxy(61, 16);
		color(15);
		scanf("%d", &menu);
		while ((t = getchar()) != '\n');
		if (menu == 1) {
			list();
			break;
		}
		else if (menu == 2) {
			user();
			break;
		}
		else {
			color(8);
			gotoxy(46, 21);
			puts("잘못된 값을 입력하셨습니다.");
			Sleep(500);
		}
	}
}


int list() {
	struct user u[5];
	FILE *fb = NULL;
	int i = 0, n=0, end;
	char t;

	system("cls");
	fb = fopen("list.txt", "r");
	if (fb == NULL) {
		printf("FILE OPEN ERROR");
		exit(0);
	}

	fseek(fb, 0, 2);	//파일의 마지막으로 이동
	end = ftell(fb);
	if (end < 2) {
		fclose(fb);
		gotoxy(47, 15);
		printf("등록된 사용자가 없습니다.");
		gotoxy(47, 17);
		printf("신규 등록으로 넘어갑니다.");
		user();
		return 0;
	}

	rewind(fb);
	color(14);
	gotoxy(42, 5);
	printf("┌──────────────────────────────┐ ");
	gotoxy(42, 6);
	printf("│                              │ ");
	gotoxy(42, 7);
	printf("│                              │ ");
	gotoxy(42, 8);
	printf("│                              │ ");
	gotoxy(42, 9);
	printf("│                              │ ");
	gotoxy(42, 10);
	printf("│                              │ ");
	gotoxy(42, 11);
	printf("│                              │ ");
	gotoxy(42, 12);
	printf("│                              │ ");
	gotoxy(42, 13);
	printf("│                              │ ");
	gotoxy(42, 14);
	printf("│                              │ ");
	gotoxy(42, 15);
	printf("│                              │ ");
	gotoxy(42, 16);
	printf("│                              │ ");
	gotoxy(42, 17);
	printf("└──────────────────────────────┘ ");
	n = 7;
	while (ftell(fb) != end) {
		fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
		gotoxy(48, n);
		printf("%d) %s", i + 1, u[i].name);
		i++;
		n += 2;
	}
	color(15);
	n = 0;
	while (1) {
		gotoxy(28, 21);
		printf("리스트의 사용자 이름을 선택하세요(신규 등록하려면 0을 입력하세요) ");
		color(5);
		gotoxy(50, 23);
		puts("┌───────────────┐ ");
		gotoxy(50, 24);
		puts("│               │ ");
		gotoxy(50, 25);
		puts("│               │ ");
		gotoxy(50, 26);
		puts("│               │ ");
		gotoxy(50, 27);
		puts("└───────────────┘ ");
		gotoxy(55, 25);
		puts("입력: ");
		gotoxy(61, 25);
		color(15);
		scanf("%d", &n);
		while ((t = getchar()) != '\n');		//그냥 getchar() 만 해도 되는걸..?
		if (n < 0 || n>i) {
			color(8);
			gotoxy(46, 29);
			puts("잘못된 값을 입력하셨습니다.");
			Sleep(500);
			gotoxy(55, 25);
			puts("                                                    ");
			color(15);
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
	gotoxy(33, 9);
	printf("현재 사용자의 이름은 ");
	color(5);
	printf("%s, ", name);
	color(15);
	printf("토큰은 ");
	color(5);
	printf("%d", token);
	color(15);
	printf("개 있습니다.");
	gotoxy(33, 12);
	printf("프로그램 기록은 5순위까지만 기록되고,");
	gotoxy(33, 13);
	printf("임의로 프로그램을 종료시키면 순위에 반영되지 않습니다.");
	gotoxy(41, 22);
	printf("아무 키를 누르시면 게임이 시작됩니다.");
	getch();
	return 0;
}

int user() {
	struct user u[5] = { 0, };
	FILE *fb = NULL;
	int k = 0, i = 0, z = 0, n, end, w;
	char g;
	system("cls");
	while (1) {
		system("cls");
		color(15);
		gotoxy(40, 7);
		printf("이름을 입력하시오(공백 없이 최대 20자). ");
		color(14);
		gotoxy(40, 10);
		puts("┌───────────────────────────────────┐ ");
		gotoxy(40, 11);
		puts("│                                   │ ");
		gotoxy(40, 12);
		puts("│                                   │ ");
		gotoxy(40, 13);
		puts("│                                   │ ");
		gotoxy(40, 14);
		puts("└───────────────────────────────────┘ ");
		gotoxy(45, 12);
		puts("이름: ");
		gotoxy(51, 12);
		color(15);
		fgets(name, 21, stdin);
		while (1) {
			if (name[i] == ' ') {
				color(8);
				gotoxy(46, 15);
				puts("공백은 사용할 수 없습니다.");
				color(15);
				Sleep(500);
				i = 0;
				break;
			}
			else if (name[i] == '\n' || name[i] == '\0') {
				name[i] = 0;
				break;
			}
			i++;
			if (i == 22) {
				color(8);
				gotoxy(47, 15);
				puts("글자 수가 초과되었습니다.");
				color(15);
				Sleep(500);
				while ((g = getchar()) != '\n');
				break;
			}
		}
		if (i == 22) {
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
				printf("해당 기록을 사용하시려면 1을, 다른 이름으로 시작하시려면 0을 입력하세요.");
				color(5);
				gotoxy(50, 22);
				puts("┌───────────────┐ ");
				gotoxy(50, 23);
				puts("│               │ ");
				gotoxy(50, 24);
				puts("│               │ ");
				gotoxy(50, 25);
				puts("│               │ ");
				gotoxy(50, 26);
				puts("└───────────────┘ ");
				gotoxy(55, 24);
				puts("입력: ");
				gotoxy(61, 24);
				color(15);
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
					gotoxy(33, 9);
					printf("현재 사용자의 이름은 ");
					color(5);
					printf("%s, ", name);
					color(15);
					printf("토큰은 ");
					color(5);
					printf("%d", token);
					color(15);
					printf("개 있습니다.");
					gotoxy(33, 12);
					printf("프로그램 기록은 5순위까지만 기록되고,");
					gotoxy(33, 13);
					printf("임의로 프로그램을 종료시키면 순위에 반영되지 않습니다.");
					gotoxy(41, 22);
					printf("아무 키를 누르시면 게임이 시작됩니다.");
					getch();
					return 0;
				}
				else {
					color(8);
					gotoxy(46, 28);
					puts("잘못된 값을 입력하셨습니다.");
					Sleep(500);
					gotoxy(55, 24);
					puts("                                                    ");
					color(15);
				}
			}

		}
		k++;
		if (k == n) break;
	}
	token = 25;
	system("cls");
	gotoxy(33, 7);
	printf("토큰은 기본적으로 25개 주어집니다.");
	gotoxy(33, 9);
	printf("현재 사용자의 이름은 ");
	color(5);
	printf("%s, ", name);
	color(15);
	printf("토큰은 ");
	color(5);
	printf("%d", token);
	color(15);
	printf("개 있습니다.");
	gotoxy(33, 12);
	printf("프로그램 기록은 5순위까지만 기록되고,");
	gotoxy(33, 13);
	printf("임의로 프로그램을 종료시키면 순위에 반영되지 않습니다.");
	gotoxy(41, 22);
	printf("아무 키를 누르시면 게임이 시작됩니다.");
	getch();
	return 0;
}

