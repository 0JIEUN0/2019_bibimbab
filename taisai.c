#include "�غ���.h"

void taisai()
{
	system("mode con cols=120 lines=35");

	int bet, wager = 0;

	printf("\n\n");
	srand((unsigned)time(NULL));

	gotoxy(0, 1);
	printf("# ������ ��ū�� �� : %d     ", wager);
	printf("# ���� ��ū�� �� : %d", token);

	show_rule2();

	do {
		puts("1. Big or Small Bet   2. Total Number Bet   3.Any Triple Bet   4.Triple Bet\n");
		printf("������ ������ ����: ");
		scanf("%d", &bet);
		printf("\n");
	} while (bet < 1 || bet>4);


	while (1) {
		printf("������ ��ū�� ������ �Է��Ͻÿ�: ");
		scanf("%d", &wager);
		if (wager > token) {
			printf("(system) ��ū�� ������ �����մϴ�.\n\n");
			Sleep(500);
		}
		else {
			printf("������ ��ū�� ������ �����Ǿ����ϴ�. ");
			Sleep(1000);
			break;
		}
	}

	token -= wager;

	system("cls");

	gotoxy(0, 1);
	printf("# ������ ��ū�� �� : %d     ", wager);
	printf("# ���� ��ū�� �� : %d", token);

	token += wager * play(bet);

	gotoxy(38, 34);
	printf("   �ƹ� Ű�� ������ ������ ����˴ϴ�.");
	getch();
}
void show_rule2()
{
	gotoxy(0, 3);
	puts("�������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������� ");
	puts("��                 �ֻ��� 3���� ����                                             ��           �ֻ��� 3���� ���ڰ�      �� ");
	puts("�������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������� ");
	puts("��1. Big or Small Bet��                    2. Total Number Bet                    �� 3. Any Triple Bet��  4. Triple Bet  �� ");
	puts("�������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������� ");
	puts("��         ��         ��         ��         ��         ��         ��         ��         ��                  ��                 �� ");
	puts("��         ��         ��         ��         ��         ��         ��         ��         ��                  ��                 �� ");
	puts("��  4 - 10 �� 11 - 17 ��  4 or 7 �� 5 or 16 �� 6 or 15 �� 7 or 14 �� 8 or 13 ��  9, 10  ��   ��� �����ϸ�  ��   ��� �����ϰ� �� ");
	puts("��   ����  ��   ����  ��         ��         ��         ��         ��         ��  11, 12 ��                  ��   ���� ���� ��  �� ");
	puts("��         ��         ��         ��         ��         ��         ��         ��         ��                  ��                 �� ");
	puts("��   1��   ��   1��   ��   50��  ��   30��  ��   18��  ��   12��  ��    8��  ��    6��  ��        24��      ��       150��     �� ");
	puts("��         ��         ��         ��         ��         ��         ��         ��         ��                  ��                 �� ");
	puts("�������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������� ");
	puts("\n*1,2���� ��� Ʈ�����̸� ������ �����ص� �й��Դϴ�.");
	puts("*Ʈ����: �ֻ��� 3���� ���ڰ� ��� ������ ��.\n");
}
int play(int bet)
{
	int dice[3];
	int sum = 0, total, predict, multiple;
	char choice;

	for (int i = 0; i < 3; i++)
	{
		dice[i] = 1 + rand() % 6;
		sum += dice[i];
	}


	switch (bet)
	{
	case 1:
		gotoxy(48, 4);
		puts("������������������������������������������ ");
		gotoxy(48, 5);
		puts("�� �ֻ��� 3���� ���� �� ");
		gotoxy(48, 6);
		puts("������������������������������������������ ");
		gotoxy(48, 7);
		puts("��         ��         �� ");
		gotoxy(48, 8);
		puts("��  Small  ��   Big   �� ");
		gotoxy(48, 9);
		puts("��         ��         �� ");
		gotoxy(48, 10);
		puts("��  4 - 10 �� 11 - 17 �� ");
		gotoxy(48, 11);
		puts("��         ��         �� ");
		gotoxy(48, 12);
		puts("��   1��   ��   1��   �� ");
		gotoxy(48, 13);
		puts("��         ��         �� ");
		gotoxy(48, 14);
		puts("������������������������������������������ ");

		do {
			gotoxy(40, 16);
			printf("Small�̸� s, Big�̸� b�� �Է��ϼ���: ");
			scanf(" %c", &choice);
		} while (choice != 's' && choice != 'b');

		gotoxy(44, 18);
		printf("�ֻ����� ���� �� �Դϴ�");
		for (int g = 0; g < 3; g++)
		{
			Sleep(1000);
			printf(".");
		}

		show_dice(dice, 0);

		gotoxy(48, 32);
		if (dice[0] == dice[1] && dice[1] == dice[2] && dice[0] == dice[2])
		{
			puts("!Ʈ����! �й��߽��ϴ�.");
			multiple = 0;
			break;
		}
		gotoxy(53, 31);
		printf("�ֻ��� ��: %d\n\n", sum);
		Sleep(1000);

		gotoxy(41, 32);
		if (choice == 'b')
		{
			if (sum >= 11 && sum <= 17)
			{
				puts("�¸��߽��ϴ�! ���� �ݾ��� 1�踦 ����ϴ�.");
				multiple = 1;
			}
			else
			{
				puts("�й��߽��ϴ�. ���� �ݾ��� �ҽ��ϴ�.");
				multiple = 0;
			}
		}
		else if (choice == 's')
		{
			if (sum >= 4 && sum <= 10)
			{
				puts("�¸��߽��ϴ�! ���� �ݾ��� 1�踦 ����ϴ�.");
				multiple = 1;
			}
			else
			{
				puts("�й��߽��ϴ�. ���� �ݾ��� �ҽ��ϴ�.");
				multiple = 0;
			}
		}
		break;

	case 2:
		gotoxy(29, 4);
		puts("�������������������������������������������������������������������������������������������������������������������������� ");
		gotoxy(29, 5);
		puts("��                      �ֻ��� 3���� ����                    �� ");
		gotoxy(29, 6);
		puts("�������������������������������������������������������������������������������������������������������������������������� ");
		gotoxy(29, 7);
		puts("��         ��         ��         ��         ��         ��         �� ");
		gotoxy(29, 8);
		puts("��         ��         ��         ��         ��         ��         �� ");
		gotoxy(29, 9);
		puts("��  4 or 7 �� 5 or 16 �� 6 or 15 �� 7 or 14 �� 8 or 13 ��  9, 10  �� ");
		gotoxy(29, 10);
		puts("��         ��         ��         ��         ��         ��  11, 12 �� ");
		gotoxy(29, 11);
		puts("��         ��         ��         ��         ��         ��         �� ");
		gotoxy(29, 12);
		puts("��    50�� ��   30��  ��   18��  ��   12��  ��    8��  ��    6��  �� ");
		gotoxy(29, 13);
		puts("��         ��         ��         ��         ��         ��         �� ");
		gotoxy(29, 14);
		puts("�������������������������������������������������������������������������������������������������������������������������� ");

		do {
			gotoxy(45, 16);
			printf("�ֻ��� ���� �������ּ���: ");
			scanf(" %d", &total);
		} while (total < 4 || total>17);

		gotoxy(45, 18);
		printf("�ֻ����� ���� �� �Դϴ�");
		for (int g = 0; g < 3; g++)
		{
			Sleep(1000);
			printf(".");
		}

		show_dice(dice, 0);

		gotoxy(48, 32);
		if (dice[0] == dice[1] && dice[1] == dice[2] && dice[0] == dice[2])
		{
			puts("!Ʈ����! �й��߽��ϴ�.");
			multiple = 0;
			break;
		}

		gotoxy(52, 31);
		printf(" �ֻ��� ��: %d\n\n", sum);
		Sleep(1000);

		gotoxy(40, 32);
		if (sum != total)
		{
			puts("�й��߽��ϴ�. ���� �ݾ��� �ҽ��ϴ�.");
			multiple = 0;
		}
		else if (sum == total)
		{

			if (sum == 4 || sum == 17)
			{
				multiple = 50;
			}
			else if (sum == 5 || sum == 16)
			{
				multiple = 30;
			}
			else if (sum == 6 || sum == 15)
			{
				multiple = 18;
			}
			else if (sum == 7 || sum == 14)
			{
				multiple = 12;
			}
			else if (sum == 8 || sum == 13)
			{
				multiple = 8;
			}
			else if (sum == 9 || sum == 10 || sum == 11 || sum == 12)
			{
				multiple = 6;
			}
			printf("�¸��߽��ϴ�! ���� �ݾ��� %d�踦 ����ϴ�.\n", multiple);
		}
		break;

	case 3:

		gotoxy(0, 4);
		puts("������ ����: Any Triple Bet\n");
		Sleep(1000);


		gotoxy(45, 8);
		printf("�ֻ����� ���� �� �Դϴ�");
		for (int g = 0; g < 3; g++)
		{
			Sleep(1000);
			printf(".");
		}

		show_dice(dice, 8);
		Sleep(1000);

		if (dice[0] == dice[1] && dice[1] == dice[2] && dice[0] == dice[2])
		{
			gotoxy(34, 25);
			puts("!Ʈ����! �¸��߽��ϴ�! ���� �ݾ��� 24�踦 ����ϴ�.");
			multiple = 24;
		}
		else
		{
			gotoxy(40, 25);
			puts(" �й��߽��ϴ�. ���� �ݾ��� �ҽ��ϴ�.");
			multiple = 0;
		}
		break;

	case 4:

		gotoxy(0, 4);
		puts("������ ����: Triple Bet\n");
		Sleep(1000);

		do {
			gotoxy(45, 8);
			printf("�ֻ��� ���ڸ� �������ּ���: ");
			scanf(" %d", &predict);
		} while (predict < 1 || predict > 6);

		gotoxy(45, 10);
		printf(" �ֻ����� ���� �� �Դϴ�");
		for (int g = 0; g < 3; g++)
		{
			Sleep(1000);
			printf(".");
		}

		show_dice(dice, 6);

		Sleep(1000);


		if (dice[0] == dice[1] && dice[1] == dice[2] && dice[0] == dice[2])
		{
			if (dice[0] == predict)
			{
				gotoxy(38, 27);
				puts("�¸��߽��ϴ�! ���� �ݾ��� 150�踦 ����ϴ�.");
				multiple = 150;
			}
			else
			{
				gotoxy(40, 27);
				puts("  �й��߽��ϴ�. ���� �ݾ��� �ҽ��ϴ�.");
				multiple = 0;
			}
		}
		else
		{
			gotoxy(40, 27);
			puts(" �й��߽��ϴ�. ���� �ݾ��� �ҽ��ϴ�.");
			multiple = 0;
		}
		break;
	}

	return multiple;
}

void show_dice(int dice[], int n)
{
	for (int i = 0; i < 3; i++)
	{

		if (dice[i] == 1)
		{
			gotoxy(21 + i * 25, 20 - n);
			printf("      ..............\n");
			gotoxy(21 + i * 25, 21 - n);
			printf("     soooooosssssooss\n");
			gotoxy(21 + i * 25, 22 - n);
			printf("    ooososooosssssssss\n");
			gotoxy(21 + i * 25, 23 - n);
			printf("    ooooooso++osssssss\n");
			gotoxy(21 + i * 25, 24 - n);
			printf("    ooooooo/``'sssssss\n");
			gotoxy(21 + i * 25, 25 - n);
			printf("    oooosso+...sssssss\n");
			gotoxy(21 + i * 25, 26 - n);
			printf("    ooooooooosssssssss\n");
			gotoxy(21 + i * 25, 27 - n);
			printf("    ooooooooosssssssss\n");
			gotoxy(21 + i * 25, 28 - n);
			printf("    :oooooooossssssss:\n");
			gotoxy(21 + i * 25, 29 - n);
			printf("      ``````````````\n");
			Sleep(1000);
		}
		else if (dice[i] == 2)
		{
			gotoxy(21 + i * 25, 20 - n);
			printf("      ..............\n");
			gotoxy(21 + i * 25, 21 - n);
			printf("     oo/++/ooosssssss\n");
			gotoxy(21 + i * 25, 22 - n);
			printf("    oo/``':oosssssssss\n");
			gotoxy(21 + i * 25, 23 - n);
			printf("    oo+...oooossssssss\n");
			gotoxy(21 + i * 25, 24 - n);
			printf("    oooooooooossssssss\n");
			gotoxy(21 + i * 25, 25 - n);
			printf("    ooooooooosss+/+sss\n");
			gotoxy(21 + i * 25, 26 - n);
			printf("    oooooooooss/``':oo\n");
			gotoxy(21 + i * 25, 27 - n);
			printf("    oooooooosso+...'s:\n");
			gotoxy(21 + i * 25, 28 - n);
			printf("    :oooooooossssssss:\n");
			gotoxy(21 + i * 25, 29 - n);
			printf("     ````````````````\n");
			Sleep(1000);
		}
		else if (dice[i] == 3)
		{
			gotoxy(21 + i * 25, 20 - n);
			printf("      ..............\n");
			gotoxy(21 + i * 25, 21 - n);
			printf("     ++++++++ooooooos\n");
			gotoxy(21 + i * 25, 22 - n);
			printf("    oo/``'oossssssssss\n");
			gotoxy(21 + i * 25, 23 - n);
			printf("    oo+...oossssssssss\n");
			gotoxy(21 + i * 25, 24 - n);
			printf("    ooooooo/``'sssssss\n");
			gotoxy(21 + i * 25, 25 - n);
			printf("    ooooooo+...ossssss\n");
			gotoxy(21 + i * 25, 26 - n);
			printf("    sooooooo++os++osss\n");
			gotoxy(21 + i * 25, 27 - n);
			printf("    oooooooosss/``':oo\n");
			gotoxy(21 + i * 25, 28 - n);
			printf("    :oooooossso+...'s:\n");
			gotoxy(21 + i * 25, 29 - n);
			printf("     ````````````````\n");
			Sleep(1000);
		}
		else if (dice[i] == 4)
		{
			gotoxy(21 + i * 25, 20 - n);
			printf("      ..............\n");
			gotoxy(21 + i * 25, 21 - n);
			printf("     ++++++++ooooooos\n");
			gotoxy(21 + i * 25, 22 - n);
			printf("    oo/``'oossss/``'ss\n");
			gotoxy(21 + i * 25, 23 - n);
			printf("    oo+...oossss+...ss\n");
			gotoxy(21 + i * 25, 24 - n);
			printf("    oooooooossssssssss\n");
			gotoxy(21 + i * 25, 25 - n);
			printf("    ooo++ooossssooosss\n");
			gotoxy(21 + i * 25, 26 - n);
			printf("    oo/``':oosso/``'ss\n");
			gotoxy(21 + i * 25, 27 - n);
			printf("    oo+...oossss+...ss\n");
			gotoxy(21 + i * 25, 28 - n);
			printf("    :ooooosssoss++sss:\n");
			gotoxy(21 + i * 25, 29 - n);
			printf("     ````````````````\n");
			Sleep(1000);
		}
		else if (dice[i] == 5)
		{
			gotoxy(21 + i * 25, 20 - n);
			printf("      ..............\n");
			gotoxy(21 + i * 25, 21 - n);
			printf("     ++++++++ooooooos\n");
			gotoxy(21 + i * 25, 22 - n);
			printf("    oo/``'oossss/``'ss\n");
			gotoxy(21 + i * 25, 23 - n);
			printf("    oo+...oossss+...ss\n");
			gotoxy(21 + i * 25, 24 - n);
			printf("    ooooooo/``'sssssss\n");
			gotoxy(21 + i * 25, 25 - n);
			printf("    ooo++oo+...sooosss\n");
			gotoxy(21 + i * 25, 26 - n);
			printf("    oo/``':oosso/``'ss\n");
			gotoxy(21 + i * 25, 27 - n);
			printf("    oo+...oossss+...ss\n");
			gotoxy(21 + i * 25, 28 - n);
			printf("    :ooooosssoss++sss:\n");
			gotoxy(21 + i * 25, 29 - n);
			printf("     ````````````````\n");
			Sleep(1000);
		}
		else if (dice[i] == 6)
		{
			gotoxy(21 + i * 25, 20 - n);
			printf("      ..............\n");
			gotoxy(21 + i * 25, 21 - n);
			printf("     ++++++++ooooooos\n");
			gotoxy(21 + i * 25, 22 - n);
			printf("    oo/``'oossss/``'ss\n");
			gotoxy(21 + i * 25, 23 - n);
			printf("    oo+...oossss+...ss\n");
			gotoxy(21 + i * 25, 24 - n);
			printf("    oo/``'oossss/``'ss\n");
			gotoxy(21 + i * 25, 25 - n);
			printf("    oo+...oossss+...ss\n");
			gotoxy(21 + i * 25, 26 - n);
			printf("    oo/``':oosso/``'ss\n");
			gotoxy(21 + i * 25, 27 - n);
			printf("    oo+...oossss+...ss\n");
			gotoxy(21 + i * 25, 28 - n);
			printf("    :ooooosssoss++sss:\n");
			gotoxy(21 + i * 25, 29 - n);
			printf("     ````````````````\n");
			Sleep(1000);
		}
	}
}