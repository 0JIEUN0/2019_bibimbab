#include "�غ���.h"

void slot()
{
	CursorView(0);
	int wager = 0;

	show_rule3();

	gotoxy(45, 29);
	puts("�ƹ� Ű�� ������ �����մϴ�.");
	getchar();
	system("cls");

	draw_machine();

	while (1) {

		gotoxy(0, 1);
		printf("# ������ ��ū�� �� : %d     ", wager);
		printf("# ���� ��ū�� �� : %d", token);

		gotoxy(56, 14);
		printf("������ ��ū�� ������ �Է��Ͻÿ�: ");
		scanf("%d", &wager);
		if (wager > token) {
			gotoxy(56, 15);
			printf("(system) ��ū�� ������ �����մϴ�.\n\n");
			Sleep(500);
		}
		else {
			gotoxy(56, 15);
			printf("������ ��ū�� ������ �����Ǿ����ϴ�. ");
			Sleep(1000);
			break;
		}
	}

	token -= wager;

	gotoxy(0, 1);
	printf("# ������ ��ū�� �� : %d     ", wager);
	printf("# ���� ��ū�� �� : %d", token);

	token += wager * play_slot();

	gotoxy(56, 21);

	printf("�ƹ� Ű�� ������ ������ ����˴ϴ�.");

	getch();
}

int play_slot()
{
	int slot[4][4];
	int mul = 0, min = 0;
	int a[5];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		a[i] = 20;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			slot[i][j] = rand() % 4 + 1;
		}
	}

	for (int j = 1; j < 4; j++)
	{
		if (slot[0][j - 1] == 1)
		{
			gotoxy(6 * j + 24, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("7");
		}
		else if (slot[0][j - 1] == 2)
		{
			gotoxy(6 * j + 24, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("��");
		}
		else if (slot[0][j - 1] == 3)
		{
			gotoxy(6 * j + 24, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			printf("��");
		}
		else if (slot[0][j - 1] == 4)
		{
			gotoxy(6 * j + 24, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("��");
		}
	}
	Sleep(1000);
	for (int j = 1; j < 4; j++)
	{
		if (slot[1][j - 1] == 1)
		{
			gotoxy(6 * j + 24, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("7");
		}
		else if (slot[1][j - 1] == 2)
		{
			gotoxy(6 * j + 24, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("��");
		}
		else if (slot[1][j - 1] == 3)
		{
			gotoxy(6 * j + 24, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			printf("��");
		}
		else if (slot[1][j - 1] == 4)
		{
			gotoxy(6 * j + 24, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("��");
		}
	}
	Sleep(1000);
	for (int j = 1; j < 4; j++)
	{
		if (slot[2][j - 1] == 1)
		{
			gotoxy(6 * j + 24, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("7");
		}
		else if (slot[2][j - 1] == 2)
		{
			gotoxy(6 * j + 24, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("��");
		}
		else if (slot[2][j - 1] == 3)
		{
			gotoxy(6 * j + 24, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			printf("��");
		}
		else if (slot[2][j - 1] == 4)
		{
			gotoxy(6 * j + 24, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("��");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}

	while (1)
	{
		//��� 3�� ����(���⼭ �����̸� �ٷ� ��÷)
		if (slot[1][0] == slot[1][1] && slot[1][1] == slot[1][2])
		{
			if (slot[1][0] == 4)
			{
				mul = 4;
			}
			else if (slot[1][0] == 3)
			{
				mul = 5;
			}
			else if (slot[1][0] == 2)
			{
				mul = 6;
			}
			else if (slot[1][0] = 1)
			{
				mul = 7;
			}
			min = mul;
			break;

		}
		//ù° �� 2�� ����
		if (slot[0][0] == slot[0][1] || slot[0][1] == slot[0][2])
		{
			if (slot[0][0] == slot[0][1] && slot[0][1] == slot[0][2])
			{
				mul = 0;
			}
			else if (slot[0][1] == 1)
			{
				mul = 3;
			}
			else if (slot[0][1] == 2)
			{
				mul = 2;
			}
			else if (slot[0][1] == 3)
			{
				mul = 1;
			}
			if (mul == 1 || mul == 2 || mul == 3)
			{
				a[0] = mul;
			}
		}
		//�ι�° �� 2�� ����
		if (slot[1][0] == slot[1][1] || slot[1][1] == slot[1][2])
		{
			if (slot[1][1] == 1)
			{
				mul = 3;
			}
			else if (slot[1][1] == 2)
			{
				mul = 2;
			}
			else if (slot[1][1] == 3)
			{
				mul = 1;
			}
			if (mul == 1 || mul == 2 || mul == 3)
			{
				a[1] = mul;
			}
		}
		//����° �� 2�� ����
		if (slot[2][0] == slot[2][1] || slot[2][1] == slot[2][2])
		{
			if (slot[2][0] == slot[2][1] && slot[2][1] == slot[2][2])
			{
				mul = 0;
			}
			else if (slot[2][1] == 1)
			{
				mul = 3;
			}
			else if (slot[2][1] == 2)
			{
				mul = 2;
			}
			else if (slot[2][1] == 3)
			{
				mul = 1;
			}
			if (mul == 1 || mul == 2 || mul == 3)
			{
				a[2] = mul;
			}
		}
		//������ �밢������ 2�� ����
		if (slot[0][0] == slot[1][1] || slot[1][1] == slot[2][2])
		{
			if (slot[0][0] == slot[1][1] && slot[1][1] == slot[2][2])
			{
				mul = 0;
			}
			else if (slot[1][1] == 1)
			{
				mul = 3;
			}
			else if (slot[1][1] == 2)
			{
				mul = 2;
			}
			else if (slot[1][1] == 3)
			{
				mul = 1;
			}
			if (mul == 1 || mul == 2 || mul == 3)
			{
				a[3] = mul;
			}
		}
		//���� �밢������ 2�� ����
		if (slot[0][2] == slot[1][1] || slot[1][1] == slot[2][0])
		{
			if (slot[0][2] == slot[1][1] && slot[1][1] == slot[2][0])
			{
				mul = 0;
			}
			else if (slot[1][1] == 1)
			{
				mul = 3;
			}
			else if (slot[1][1] == 2)
			{
				mul = 2;
			}
			else if (slot[1][1] == 3)
			{
				mul = 1;
			}
			if (mul == 1 || mul == 2 || mul == 3)
			{
				a[4] = mul;
			}
		}
		min = a[0];
		for (int i = 1; i < 5; i++)
		{
			if (min > a[i])
			{
				min = a[i];
			}
		}
		break;
	}
	gotoxy(56, 17);
	if (min == 0 || min == 20)
	{
		puts("!����! ���� �ݾ��� �ҽ��ϴ�.");
		min = 0;
	}
	else
	{
		printf("!����! ���� �ݾ��� %d�踦 ����ϴ�.", min);
	}
	return min;
}
void show_rule3()
{
	gotoxy(15, 10);
	puts("���������������������������������������������������� ");
	gotoxy(15, 11);
	puts("��  1. 7 7 7 : 7��\t�� ");
	gotoxy(15, 12);
	puts("���������������������������������������������������� ");
	gotoxy(15, 13);
	puts("��  2. �� �� �� : 6��\t�� ");
	gotoxy(15, 14);
	puts("����������������������������������������������������");
	gotoxy(15, 15);
	puts("��  3. �� �� �� : 5��\t�� ");
	gotoxy(15, 16);
	puts("���������������������������������������������������� ");
	gotoxy(15, 17);
	puts("��  4. �� �� �� : 4��\t�� ");
	gotoxy(15, 18);
	puts("���������������������������������������������������� ");
	gotoxy(15, 19);
	puts("��  5. 7 7 ���� : 3��\t�� ");
	gotoxy(15, 20);
	puts("���������������������������������������������������� ");
	gotoxy(15, 21);
	puts("��  6. �� �� ���� : 2��\t�� ");
	gotoxy(15, 22);
	puts("���������������������������������������������������� ");
	gotoxy(15, 23);
	puts("��  7. �� �� ���� : 1��\t�� ");
	gotoxy(15, 24);
	puts("���������������������������������������������������� ");

	gotoxy(44, 12);
	puts("*1,2,3,4���� �����ϱ� ���ؼ��� ��� �ٿ� ��ȣ�� ��µǾ�� �մϴ�.");
	gotoxy(44, 13);
	puts("  ��: ? ? ?");
	gotoxy(50, 14);
	puts("7 7 7");
	gotoxy(50, 15);
	puts("? ? ?");
	gotoxy(44, 17);
	puts("*5,6,7���� �����ϱ� ���ؼ��� �������� ��ȣ�� ��µǾ�� �մϴ�.");
	gotoxy(44, 18);
	puts("  ��: �� ��  ? or ? �� ��");
	gotoxy(44, 20);
	puts("*�ߺ������̸� ������ �� ���� ������ �־����ϴ�.");
	gotoxy(44, 21);
	puts("  ��: 5�� 6�� �ߺ����� ������ �� ���� �ݾ��� 2�踦 ����ϴ�.");
}
void draw_machine()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (int i = 0; i < 5; i++)
	{
		gotoxy(33, 10 + i);
		puts("��");
	}
	for (int i = 0; i < 5; i++)
	{
		gotoxy(39, 10 + i);
		puts("��");
	}
	for (int i = 0; i < 17; i++)
	{
		gotoxy(28 + i, 11);
		puts("��");
	}
	for (int i = 0; i < 17; i++)
	{
		gotoxy(28 + i, 13);
		puts("��");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(26, 9);
	puts("������������������������������������������ ");
	for (int i = 0; i < 6; i++)
	{
		gotoxy(26, 10 + i);
		printf("��");
	}
	for (int i = 0; i < 6; i++)
	{
		gotoxy(46, 10 + i);
		printf("��");
	}
	gotoxy(26, 15);
	puts("������������������������������������������ ");
	gotoxy(24, 8);
	puts("�������������������������������������������������� ");
	for (int i = 0; i < 8; i++)
	{
		gotoxy(24, 9 + i);
		printf("��");
	}
	for (int i = 0; i < 8; i++)
	{
		gotoxy(48, 9 + i);
		printf("��");
	}
	gotoxy(24, 16);
	puts("�������������������������������������������������� ");
	gotoxy(24, 7);
	puts("�������������������������������������������������� ");
	gotoxy(24, 8);
	printf("��");
	gotoxy(48, 8);
	printf("��");
	gotoxy(24, 5);
	puts("�������������������������������������������������� ");
	for (int i = 0; i < 2; i++)
	{
		gotoxy(24, 6 + i);
		printf("��");
	}
	for (int i = 0; i < 2; i++)
	{
		gotoxy(48, 6 + i);
		printf("��");
	}
	gotoxy(24, 17);
	puts("�������������������������������������������������� ");
	gotoxy(24, 16);
	printf("��");
	gotoxy(48, 16);
	printf("��");
	for (int i = 0; i < 14; i++)
	{
		gotoxy(24, 17 + i);
		printf("��");
	}
	for (int i = 0; i < 14; i++)
	{
		gotoxy(48, 17 + i);
		printf("��");
	}
	gotoxy(24, 31);
	puts("�������������������������������������������������� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(29, 6);
	printf("$ SLOT MACHINE $");
	gotoxy(25, 24);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("  ��    ��    ��    x4");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(25, 18);
	printf("   7     7     7    x7");
	gotoxy(25, 26);
	printf("   7     7    $     x3");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	gotoxy(25, 28);
	printf("  ��    ��    $     x2");
	gotoxy(25, 20);
	printf("  ��    ��    ��    x6");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	gotoxy(25, 22);
	printf("  ��    ��    ��    x5");
	gotoxy(25, 30);
	printf("  ��    ��    $     x1");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

