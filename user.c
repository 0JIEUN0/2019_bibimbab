#include "�غ���.h"

void user_menu() {
	int menu;
	char t;

	while (1) {
		system("cls");
		gotoxy(42, 5);
		color(3);
		puts("ī���� ���ӿ� ���� ���� ȯ���մϴ�!");
		color(15);
		gotoxy(49, 8);
		puts("����ڸ� ������ּ���.");
		gotoxy(45, 10);
		puts("1) ���� ����� ����");
		gotoxy(45, 11);
		puts("2) �ű� ���");
		color(5);
		gotoxy(50, 14);
		puts("���������������������������������� ");
		gotoxy(50, 15);
		puts("��               �� ");
		gotoxy(50, 16);
		puts("��               �� ");
		gotoxy(50, 17);
		puts("��               �� ");
		gotoxy(50, 18);
		puts("���������������������������������� ");
		gotoxy(55, 16);
		puts("�Է�: ");
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
			puts("�߸��� ���� �Է��ϼ̽��ϴ�.");
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

	fseek(fb, 0, 2);	//������ ���������� �̵�
	end = ftell(fb);
	if (end < 2) {
		fclose(fb);
		gotoxy(47, 15);
		printf("��ϵ� ����ڰ� �����ϴ�.");
		gotoxy(47, 17);
		printf("�ű� ������� �Ѿ�ϴ�.");
		user();
		return 0;
	}

	rewind(fb);
	color(14);
	gotoxy(42, 5);
	printf("���������������������������������������������������������������� ");
	gotoxy(42, 6);
	printf("��                              �� ");
	gotoxy(42, 7);
	printf("��                              �� ");
	gotoxy(42, 8);
	printf("��                              �� ");
	gotoxy(42, 9);
	printf("��                              �� ");
	gotoxy(42, 10);
	printf("��                              �� ");
	gotoxy(42, 11);
	printf("��                              �� ");
	gotoxy(42, 12);
	printf("��                              �� ");
	gotoxy(42, 13);
	printf("��                              �� ");
	gotoxy(42, 14);
	printf("��                              �� ");
	gotoxy(42, 15);
	printf("��                              �� ");
	gotoxy(42, 16);
	printf("��                              �� ");
	gotoxy(42, 17);
	printf("���������������������������������������������������������������� ");
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
		printf("����Ʈ�� ����� �̸��� �����ϼ���(�ű� ����Ϸ��� 0�� �Է��ϼ���) ");
		color(5);
		gotoxy(50, 23);
		puts("���������������������������������� ");
		gotoxy(50, 24);
		puts("��               �� ");
		gotoxy(50, 25);
		puts("��               �� ");
		gotoxy(50, 26);
		puts("��               �� ");
		gotoxy(50, 27);
		puts("���������������������������������� ");
		gotoxy(55, 25);
		puts("�Է�: ");
		gotoxy(61, 25);
		color(15);
		scanf("%d", &n);
		while ((t = getchar()) != '\n');		//�׳� getchar() �� �ص� �Ǵ°�..?
		if (n < 0 || n>i) {
			color(8);
			gotoxy(46, 29);
			puts("�߸��� ���� �Է��ϼ̽��ϴ�.");
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
	printf("���� ������� �̸��� ");
	color(5);
	printf("%s, ", name);
	color(15);
	printf("��ū�� ");
	color(5);
	printf("%d", token);
	color(15);
	printf("�� �ֽ��ϴ�.");
	gotoxy(33, 12);
	printf("���α׷� ����� 5���������� ��ϵǰ�,");
	gotoxy(33, 13);
	printf("���Ƿ� ���α׷��� �����Ű�� ������ �ݿ����� �ʽ��ϴ�.");
	gotoxy(41, 22);
	printf("�ƹ� Ű�� �����ø� ������ ���۵˴ϴ�.");
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
		printf("�̸��� �Է��Ͻÿ�(���� ���� �ִ� 20��). ");
		color(14);
		gotoxy(40, 10);
		puts("�������������������������������������������������������������������������� ");
		gotoxy(40, 11);
		puts("��                                   �� ");
		gotoxy(40, 12);
		puts("��                                   �� ");
		gotoxy(40, 13);
		puts("��                                   �� ");
		gotoxy(40, 14);
		puts("�������������������������������������������������������������������������� ");
		gotoxy(45, 12);
		puts("�̸�: ");
		gotoxy(51, 12);
		color(15);
		fgets(name, 21, stdin);
		while (1) {
			if (name[i] == ' ') {
				color(8);
				gotoxy(46, 15);
				puts("������ ����� �� �����ϴ�.");
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
				puts("���� ���� �ʰ��Ǿ����ϴ�.");
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
	fseek(fb, 0, 2);	//������ ���������� �̵�
	end = ftell(fb);
	rewind(fb);
	while (ftell(fb) != end) {
		fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
		i++;
	}
	n = i; //��ϵ� ����� ��(1~5)
	i = 0;
	fclose(fb);
	while (1) {
		if (!(strcmp(name, u[k].name))) {
			while (1) {
				gotoxy(45, 18);
				printf("������ �̸��� ��Ͽ� �ֽ��ϴ�.");
				gotoxy(25, 19);
				printf("�ش� ����� ����Ͻ÷��� 1��, �ٸ� �̸����� �����Ͻ÷��� 0�� �Է��ϼ���.");
				color(5);
				gotoxy(50, 22);
				puts("���������������������������������� ");
				gotoxy(50, 23);
				puts("��               �� ");
				gotoxy(50, 24);
				puts("��               �� ");
				gotoxy(50, 25);
				puts("��               �� ");
				gotoxy(50, 26);
				puts("���������������������������������� ");
				gotoxy(55, 24);
				puts("�Է�: ");
				gotoxy(61, 24);
				color(15);
				scanf("%d", &w);
				while ((g = getchar()) != '\n');
				if (w == 0) {
					strcpy(name, "");
					user();		//���Է�
					return 0;
				}
				else if (w == 1) {
					token = u[k].score;
					system("cls");
					gotoxy(33, 9);
					printf("���� ������� �̸��� ");
					color(5);
					printf("%s, ", name);
					color(15);
					printf("��ū�� ");
					color(5);
					printf("%d", token);
					color(15);
					printf("�� �ֽ��ϴ�.");
					gotoxy(33, 12);
					printf("���α׷� ����� 5���������� ��ϵǰ�,");
					gotoxy(33, 13);
					printf("���Ƿ� ���α׷��� �����Ű�� ������ �ݿ����� �ʽ��ϴ�.");
					gotoxy(41, 22);
					printf("�ƹ� Ű�� �����ø� ������ ���۵˴ϴ�.");
					getch();
					return 0;
				}
				else {
					color(8);
					gotoxy(46, 28);
					puts("�߸��� ���� �Է��ϼ̽��ϴ�.");
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
	printf("��ū�� �⺻������ 25�� �־����ϴ�.");
	gotoxy(33, 9);
	printf("���� ������� �̸��� ");
	color(5);
	printf("%s, ", name);
	color(15);
	printf("��ū�� ");
	color(5);
	printf("%d", token);
	color(15);
	printf("�� �ֽ��ϴ�.");
	gotoxy(33, 12);
	printf("���α׷� ����� 5���������� ��ϵǰ�,");
	gotoxy(33, 13);
	printf("���Ƿ� ���α׷��� �����Ű�� ������ �ݿ����� �ʽ��ϴ�.");
	gotoxy(41, 22);
	printf("�ƹ� Ű�� �����ø� ������ ���۵˴ϴ�.");
	getch();
	return 0;
}

