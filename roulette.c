#include "�غ���.h"

void roulette() {
	CursorView(1);
	int menu, bet;
	int num1, num2;
	int goal, gcolor, betcolor;
	int f = 0;
	struct roul r[37] = {
		{28, 4, 0}, {32, 4, 32}, {36,5,15}, {40,6,19}, {44,7,4}, {47,8,21}, {50, 10, 2}, {52,12,25}, {53,14,17}, {54,16,34},
		{55,18,6}, {53,20,27}, {52,22,13}, {50, 24, 36}, {47, 26, 30}, {44,28, 8}, {39, 29, 23}, {34, 30, 10}, {30,30,5},
		{25,30,24},{20,29,16}, {16,28,33}, {13,27,1}, {10,26,20},{7, 24, 14},{5,22,31},{4, 20, 9},{3, 18, 22},
		 {3,16,18},{4,14,29},{5,12,7},{7, 10, 28}, {10,8,12},  {13,7,35},  {17,6, 3},  {20,5,26},{24,4,11}
	};
	system("cls");
	gotoxy(0, 1);
	printf("# ���� ��ū�� �� : %d", token);
	draw_roulette(r, 0);

	f = 5;
	gotoxy(ROUL_X, ++f);
	printf("1) ���� ����(���� �ݾ��� 35��)");
	gotoxy(ROUL_X, ++f);
	printf("2) ���� ����(���� �ݾ��� 17��)");
	gotoxy(ROUL_X, ++f);
	printf("3) ���� ����(���� �ݾ��� 5��)");

	while (1) {
		gotoxy(ROUL_X, ++f);
		printf("���� ����� �����ϼ���: ");
		scanf("%d", &menu);
		getchar();
		if (menu >= 1 && menu <= 3) break;
		else {
			gotoxy(ROUL_X, ++f);
			printf("(system) �߸��� �޴��� �Է��ϼ̽��ϴ�.");
			++f;
		}
	}

	//��ū ����
	system("cls");
	gotoxy(0, 1);
	printf("# ���� ��ū�� �� : %d", token);
	draw_roulette(r, 0);
	roulette_bet(menu, &bet);

	//�귿 ����
	system("cls");
	gotoxy(0, 1);
	printf("# ������ ��ū�� �� : %d     ", bet);
	printf("# ���� ��ū�� �� : %d", token);
	draw_roulette(r, 0);

	f = 5;
	switch (menu) {
	case 1:
		while (1) {
			gotoxy(ROUL_X, ++f);
			printf("������ ���ڸ� �Է��ϼ���(0~36): ");
			scanf("%d", &num1);
			if (num1 < 0 || num1 > 36) {
				gotoxy(ROUL_X, ++f);
				printf("(system) �߸��� ���� �Է��Ͽ����ϴ�.");
				Sleep(500);
				++f;
			}
			else break;
		}
		break;
	case 2:
		while (1) {
			gotoxy(ROUL_X, ++f);
			printf("ù��°�� ������ ���ڸ� �Է��ϼ���(0~36): ");
			scanf("%d", &num1);
			if (num1 < 0 || num1 > 36) {
				gotoxy(ROUL_X, ++f);
				printf("(system) �߸��� ���� �Է��Ͽ����ϴ�.");
				Sleep(500);
				++f;
			}
			else {
				++f;
				break;
			}
		}
		while (1) {
			gotoxy(ROUL_X, ++f);
			printf("�ι�°�� ������ ���ڸ� �Է��ϼ���(0~36): ");
			scanf("%d", &num2);
			if (num2 < 0 || num2 > 36 || num2 == num1) {
				gotoxy(ROUL_X, ++f);
				printf("(system) �߸��� ���� �Է��Ͽ����ϴ�.");
				Sleep(500);
				++f;
			}
			else break;
		}
		break;
	case 3:
		gotoxy(ROUL_X, ++f);
		printf("0:�ʷϻ�, 1:������, 2:������");
		while (1) {
			gotoxy(ROUL_X, ++f);
			printf("������ ���� �����ϼ���: ");
			scanf("%d", &betcolor);
			if (betcolor < 0 || betcolor > 2) {
				gotoxy(ROUL_X, ++f);
				printf("(system) �߸��� ���� �Է��Ͽ����ϴ�.");
				Sleep(500);
				++f;
			}
			else break;
		}
		break;

	}
	gotoxy(ROUL_X, ++f);
	printf("������ �����Ǿ����ϴ�.");
	Sleep(1000);

	//�귿 ���
	goal = rand() % 37;

	//�귿 ������
	system("cls");
	gotoxy(0, 1);
	printf("# ������ ��ū�� �� : %d     ", bet);
	printf("# ���� ��ū�� �� : %d", token);
	gotoxy(ROUL_X, 6);
	printf("(system) �귿 ���� ȸ����ŵ�ϴ�...");
	gcolor=draw_roulette(r, goal);		

	if (goal == 0) {
		gcolor = 0;
	}
	else if (gcolor % 2) {
		gcolor = 1;
	}
	else gcolor = 2;

	system("cls");
	gotoxy(0, 1);
	printf("# ������ ��ū�� �� : %d     ", bet);
	printf("# ���� ��ū�� �� : %d", token);
	draw_roulette(r, 0);

	CursorView(0);
	f = 5;
	gotoxy(ROUL_X, ++f);
	printf("���� ������ ����: %d", goal);
	gotoxy(ROUL_X, ++f);
	switch (gcolor) {
	case 0:
		printf("����: �ʷϻ�");
		break;
	case 1:
		printf("����: ������");
		break;
	case 2:
		printf("����: ������");
		break;
	}
	f += 2;
	gotoxy(ROUL_X, f);
	switch (menu) {
	case 1:
		printf("������ ����: %d", num1);
		Sleep(2000);
		if (goal == num1) {
			f += 3;
			gotoxy(ROUL_X, f);
			printf("���ÿ� �����ϼ̽��ϴ�. �����մϴ�!");
			f += 2;
			gotoxy(ROUL_X, f);
			printf("���ÿ� �����Ͽ� ���� ��ū�� 35����");
			gotoxy(ROUL_X, ++f);
			printf("%d ��ū�� ������ϴ�.", bet * 35);
			token += bet * 35;
		}
		else {
			f += 3;
			gotoxy(ROUL_X, f);
			printf("��Ÿ���Ե� ���ÿ� �����Ͽ����ϴ�.");
			gotoxy(ROUL_X, f++);
			printf("������ %d ��ū�� ��� �Ҿ����ϴ�.", bet);
		}
		break;
	case 2:
		printf("������ ����: %d, %d", num1, num2);
		Sleep(2000);
		if (goal == num1 || goal == num2) {
			f += 3;
			gotoxy(ROUL_X, f);
			printf("���ÿ� �����ϼ̽��ϴ�. �����մϴ�!");
			f += 2;
			gotoxy(ROUL_X, f);
			printf("���ÿ� �����Ͽ� ���� ��ū�� 17����");
			gotoxy(ROUL_X, ++f);
			printf("%d ��ū�� ������ϴ�.", bet * 17);
			token += bet * 17;
		}
		else {
			f += 3;
			gotoxy(ROUL_X, f);
			printf("��Ÿ���Ե� ���ÿ� �����Ͽ����ϴ�.");
			gotoxy(ROUL_X, f);
			printf("������ %d ��ū�� ��� �Ҿ����ϴ�.", bet);
		}
		break;
	case 3:
		switch (betcolor) {
		case 0:
			printf("������ ����: �ʷϻ�");
			break;
		case 1:
			printf("������ ����: ������");
			break;
		case 2:
			printf("������ ����: ������");
			break;
		}
		Sleep(2000);
		if (gcolor == betcolor) {
			f += 3;
			gotoxy(ROUL_X, f);
			printf("���ÿ� �����ϼ̽��ϴ�. �����մϴ�!");
			f += 2;
			gotoxy(ROUL_X, f);
			printf("���ÿ� �����Ͽ� ���� ��ū�� 5����");
			gotoxy(ROUL_X, ++f);
			printf("%d ��ū�� ������ϴ�.", bet * 5);
			token += bet * 5;
		}
		else {
			f += 3;
			gotoxy(ROUL_X, f);
			printf("��Ÿ���Ե� ���ÿ� �����Ͽ����ϴ�.");
			gotoxy(ROUL_X, ++f);
			printf("������ %d ��ū�� ��� �Ҿ����ϴ�.", bet);
		}
		break;
	}
	f += 3;
	gotoxy(ROUL_X, f);
	printf("�ƹ� Ű�� ������ ������ ����˴ϴ�.");
	getch();
}

int draw_roulette(struct roul r[], int c) {
	int i = 0, j = 0;

	color(6);
	gotoxy(14, 14);
	printf("����  ���  ��  �� ��    ");
	gotoxy(14, 15);
	printf("���   ��  �� ��  �� ��    ");
	gotoxy(14, 16);
	printf("��  ��  ���  ���� ����");
	gotoxy(19, 18);
	printf("���� ���� ���� ����");
	gotoxy(19, 19);
	printf("���     ��     ��   ���");
	gotoxy(19, 20);
	printf("����   ��     ��   ����");


	color(10);
	gotoxy(r[i].x, r[i].y);
	printf("%d", r[i].num);
	Sleep(j);
	for (i = 1; i < 36; i++) {
		color(12);
		gotoxy(r[i].x, r[i].y);
		printf("%d", r[i].num);
		Sleep(j);
		i++;
		color(8);
		gotoxy(r[i].x, r[i].y);
		printf("%d", r[i].num);
		Sleep(j);
	}
	if (c) {
		for (j = 50; j <= 100; j *= 2) {
			i = 0;
			color(10);
			gotoxy(r[i].x, r[i].y);
			printf("%d", r[i].num);
			Sleep(j);
			for (i = 1; i < 36; i++) {
				color(12);
				gotoxy(r[i].x, r[i].y);
				printf("%d", r[i].num);
				Sleep(j);
				i++;
				color(8);
				gotoxy(r[i].x, r[i].y);
				printf("%d", r[i].num);
				Sleep(j);
			}
		}
		i = 0;
		j = 400;
		color(10);
		while (r[i].num != c) {
			if (i == 0) {
				color(10);
				gotoxy(r[i].x, r[i].y);
				printf("%d", r[i].num);
				Sleep(j);
				color(12);
				i++;
				continue;
			}
			if (i % 2) {
				gotoxy(r[i].x, r[i].y);
				printf("%d", r[i].num);
				Sleep(j);
				color(8);
			}
			else {
				gotoxy(r[i].x, r[i].y);
				printf("%d", r[i].num);
				Sleep(j);
				color(12);
			}
			i++;
		}

		for (j = 0; j < 3; j++) {
			gotoxy(r[i].x, r[i].y);
			printf("%d", r[i].num);
			Sleep(700);
			gotoxy(r[i].x, r[i].y);
			printf("  ");
			Sleep(700);
		}
	}

	color(15);
	return i;		//'���°' ��������..
}

void roulette_bet(int m, int *b) {
	int f;
	f = 5;
	gotoxy(ROUL_X, ++f);
	switch (m) {
	case 1:
		printf("���� ����(���� �ݾ��� 35��)");
		break;
	case 2:
		printf("���� ����(���� �ݾ��� 17��)");
		break;
	case 3:
		printf("���� ����(���� �ݾ��� 5��)");
		break;
	}

	while (1) {
		gotoxy(ROUL_X, ++f);
		printf("������ ��ū�� ������ �Է��Ͻÿ�: ");
		scanf("%d", b);
		if (*b > token) {
			gotoxy(ROUL_X, ++f);
			printf("(system) ��ū�� ������ �����մϴ�.");
			Sleep(500);
			f++;
		}
		else {
			gotoxy(ROUL_X, ++f);
			printf("������ ��ū�� ������ �����Ǿ����ϴ�. ");
			Sleep(1000);
			break;
		}
	}
	token -= *b;
}