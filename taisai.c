#include "遽綠醞.h"

void taisai()
{
	system("mode con cols=120 lines=35");

	int bet, wager = 0;

	printf("\n\n");
	srand((unsigned)time(NULL));

	gotoxy(0, 1);
	printf("# 漆たи 饜贖曖 熱 : %d     ", wager);
	printf("# 爾嶸 饜贖曖 熱 : %d", token);

	show_rule2();

	do {
		puts("1. Big or Small Bet   2. Total Number Bet   3.Any Triple Bet   4.Triple Bet\n");
		printf("摹鷗й 漆た曖 璋濠: ");
		scanf("%d", &bet);
		printf("\n");
	} while (bet < 1 || bet>4);


	while (1) {
		printf("寡たй 饜贖曖 偃熱蒂 殮溘ж衛螃: ");
		scanf("%d", &wager);
		if (wager > token) {
			printf("(system) 饜贖曖 偃熱陛 睡褶м棲棻.\n\n");
			Sleep(500);
		}
		else {
			printf("寡たй 饜贖曖 偃熱陛 唸薑腎歷蝗棲棻. ");
			Sleep(1000);
			break;
		}
	}

	token -= wager;

	system("cls");

	gotoxy(0, 1);
	printf("# 漆たи 饜贖曖 熱 : %d     ", wager);
	printf("# 爾嶸 饜贖曖 熱 : %d", token);

	token += wager * play(bet);

	gotoxy(38, 34);
	printf("   嬴鼠 酈釭 援腦賊 啪歜檜 謙猿腌棲棻.");
	getch();
}
void show_rule2()
{
	gotoxy(0, 3);
	puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 ");
	puts("弛                 輿餌嬪 3偃曖 м檜                                             弛           輿餌嬪 3偃曖 璋濠陛      弛 ");
	puts("戍式式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式式式成式式式式式式式式式式式式式式式式式扣 ");
	puts("弛1. Big or Small Bet弛                    2. Total Number Bet                    弛 3. Any Triple Bet弛  4. Triple Bet  弛 ");
	puts("戍式式式式式式式式式成式式式式式式式式式托式式式式式式式式式成式式式式式式式式式成式式式式式式式式式成式式式式式式式式式成式式式式式式式式式成式式式式式式式式式托式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式式扣 ");
	puts("弛         弛         弛         弛         弛         弛         弛         弛         弛                  弛                 弛 ");
	puts("弛         弛         弛         弛         弛         弛         弛         弛         弛                  弛                 弛 ");
	puts("弛  4 - 10 弛 11 - 17 弛  4 or 7 弛 5 or 16 弛 6 or 15 弛 7 or 14 弛 8 or 13 弛  9, 10  弛   賅舒 翕橾ж賊  弛   賅舒 翕橾ж堅 弛 ");
	puts("弛   餌檜  弛   餌檜  弛         弛         弛         弛         弛         弛  11, 12 弛                  弛   璋濠 蕨難 衛  弛 ");
	puts("弛         弛         弛         弛         弛         弛         弛         弛         弛                  弛                 弛 ");
	puts("弛   1寡   弛   1寡   弛   50寡  弛   30寡  弛   18寡  弛   12寡  弛    8寡  弛    6寡  弛        24寡      弛       150寡     弛 ");
	puts("弛         弛         弛         弛         弛         弛         弛         弛         弛                  弛                 弛 ");
	puts("戌式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式式式式式式式式式式扛式式式式式式式式式式式式式式式式式戎 ");
	puts("\n*1,2廓曖 唳辦 お葬Ы檜賊 漆た檜 瞳醞п紫 ぬ寡殮棲棻.");
	puts("*お葬Ы: 輿餌嬪 3偃曖 璋濠陛 賅舒 翕橾и 匙.\n");
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
		puts("忙式式式式式式式式式式式式式式式式式式式忖 ");
		gotoxy(48, 5);
		puts("弛 輿餌嬪 3偃曖 м檜 弛 ");
		gotoxy(48, 6);
		puts("戍式式式式式式式式式成式式式式式式式式式扣 ");
		gotoxy(48, 7);
		puts("弛         弛         弛 ");
		gotoxy(48, 8);
		puts("弛  Small  弛   Big   弛 ");
		gotoxy(48, 9);
		puts("弛         弛         弛 ");
		gotoxy(48, 10);
		puts("弛  4 - 10 弛 11 - 17 弛 ");
		gotoxy(48, 11);
		puts("弛         弛         弛 ");
		gotoxy(48, 12);
		puts("弛   1寡   弛   1寡   弛 ");
		gotoxy(48, 13);
		puts("弛         弛         弛 ");
		gotoxy(48, 14);
		puts("戌式式式式式式式式式扛式式式式式式式式式戎 ");

		do {
			gotoxy(40, 16);
			printf("Small檜賊 s, Big檜賊 b蒂 殮溘ж撮蹂: ");
			scanf(" %c", &choice);
		} while (choice != 's' && choice != 'b');

		gotoxy(44, 18);
		printf("輿餌嬪蒂 �蝯撏� 醞 殮棲棻");
		for (int g = 0; g < 3; g++)
		{
			Sleep(1000);
			printf(".");
		}

		show_dice(dice, 0);

		gotoxy(48, 32);
		if (dice[0] == dice[1] && dice[1] == dice[2] && dice[0] == dice[2])
		{
			puts("!お葬Ы! ぬ寡ц蝗棲棻.");
			multiple = 0;
			break;
		}
		gotoxy(53, 31);
		printf("輿餌嬪 м: %d\n\n", sum);
		Sleep(1000);

		gotoxy(41, 32);
		if (choice == 'b')
		{
			if (sum >= 11 && sum <= 17)
			{
				puts("蝓葬ц蝗棲棻! 漆た 旎擋曖 1寡蒂 橢蝗棲棻.");
				multiple = 1;
			}
			else
			{
				puts("ぬ寡ц蝗棲棻. 漆た 旎擋擊 檠蝗棲棻.");
				multiple = 0;
			}
		}
		else if (choice == 's')
		{
			if (sum >= 4 && sum <= 10)
			{
				puts("蝓葬ц蝗棲棻! 漆た 旎擋曖 1寡蒂 橢蝗棲棻.");
				multiple = 1;
			}
			else
			{
				puts("ぬ寡ц蝗棲棻. 漆た 旎擋擊 檠蝗棲棻.");
				multiple = 0;
			}
		}
		break;

	case 2:
		gotoxy(29, 4);
		puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 ");
		gotoxy(29, 5);
		puts("弛                      輿餌嬪 3偃曖 м檜                    弛 ");
		gotoxy(29, 6);
		puts("戍式式式式式式式式式成式式式式式式式式式成式式式式式式式式式成式式式式式式式式式成式式式式式式式式式成式式式式式式式式式扣 ");
		gotoxy(29, 7);
		puts("弛         弛         弛         弛         弛         弛         弛 ");
		gotoxy(29, 8);
		puts("弛         弛         弛         弛         弛         弛         弛 ");
		gotoxy(29, 9);
		puts("弛  4 or 7 弛 5 or 16 弛 6 or 15 弛 7 or 14 弛 8 or 13 弛  9, 10  弛 ");
		gotoxy(29, 10);
		puts("弛         弛         弛         弛         弛         弛  11, 12 弛 ");
		gotoxy(29, 11);
		puts("弛         弛         弛         弛         弛         弛         弛 ");
		gotoxy(29, 12);
		puts("弛    50寡 弛   30寡  弛   18寡  弛   12寡  弛    8寡  弛    6寡  弛 ");
		gotoxy(29, 13);
		puts("弛         弛         弛         弛         弛         弛         弛 ");
		gotoxy(29, 14);
		puts("戌式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式扛式式式式式式式式式戎 ");

		do {
			gotoxy(45, 16);
			printf("輿餌嬪 м擊 蕨難п輿撮蹂: ");
			scanf(" %d", &total);
		} while (total < 4 || total>17);

		gotoxy(45, 18);
		printf("輿餌嬪蒂 �蝯撏� 醞 殮棲棻");
		for (int g = 0; g < 3; g++)
		{
			Sleep(1000);
			printf(".");
		}

		show_dice(dice, 0);

		gotoxy(48, 32);
		if (dice[0] == dice[1] && dice[1] == dice[2] && dice[0] == dice[2])
		{
			puts("!お葬Ы! ぬ寡ц蝗棲棻.");
			multiple = 0;
			break;
		}

		gotoxy(52, 31);
		printf(" 輿餌嬪 м: %d\n\n", sum);
		Sleep(1000);

		gotoxy(40, 32);
		if (sum != total)
		{
			puts("ぬ寡ц蝗棲棻. 漆た 旎擋擊 檠蝗棲棻.");
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
			printf("蝓葬ц蝗棲棻! 漆た 旎擋曖 %d寡蒂 橢蝗棲棻.\n", multiple);
		}
		break;

	case 3:

		gotoxy(0, 4);
		puts("摹鷗и 漆た: Any Triple Bet\n");
		Sleep(1000);


		gotoxy(45, 8);
		printf("輿餌嬪蒂 �蝯撏� 醞 殮棲棻");
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
			puts("!お葬Ы! 蝓葬ц蝗棲棻! 漆た 旎擋曖 24寡蒂 橢蝗棲棻.");
			multiple = 24;
		}
		else
		{
			gotoxy(40, 25);
			puts(" ぬ寡ц蝗棲棻. 漆た 旎擋擊 檠蝗棲棻.");
			multiple = 0;
		}
		break;

	case 4:

		gotoxy(0, 4);
		puts("摹鷗и 漆た: Triple Bet\n");
		Sleep(1000);

		do {
			gotoxy(45, 8);
			printf("輿餌嬪 璋濠蒂 蕨難п輿撮蹂: ");
			scanf(" %d", &predict);
		} while (predict < 1 || predict > 6);

		gotoxy(45, 10);
		printf(" 輿餌嬪蒂 �蝯撏� 醞 殮棲棻");
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
				puts("蝓葬ц蝗棲棻! 漆た 旎擋曖 150寡蒂 橢蝗棲棻.");
				multiple = 150;
			}
			else
			{
				gotoxy(40, 27);
				puts("  ぬ寡ц蝗棲棻. 漆た 旎擋擊 檠蝗棲棻.");
				multiple = 0;
			}
		}
		else
		{
			gotoxy(40, 27);
			puts(" ぬ寡ц蝗棲棻. 漆た 旎擋擊 檠蝗棲棻.");
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