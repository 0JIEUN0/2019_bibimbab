#include "�غ���.h"
int card[52] = { 1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10 };
int sum_player, sum_deal;
int deal[21], money;
int player[21];
int black_count;
void black() {
	int i = 2, j = 2;
	system("cls");
	gotoxy(0, 1);
	printf("# ���� ��ū�� �� : %d", token);

	while (1) {
		gotoxy(50, 5);
		printf("������ ��ū�� ������ �Է��Ͻÿ�: ");
		scanf("%d", &money); getchar();
		gotoxy(50, 7);
		if (money > token) {
			printf("(system) ��ū�� ������ �����մϴ�.");
			gotoxy(50, 5); printf("                                                                ");
		}
		else {
			printf("������ ��ū�� ������ �����Ǿ����ϴ�. ");
			break;
		}
	}
	gotoxy(50, 7); printf("                                         ");
	token -= money;
	gotoxy(0, 1);
	printf("# ���� ��ū�� �� : %d", token);
	gotoxy(0, 3);
	printf("# ������ ��ū�� �� : %d", money);
	srand((unsigned)time(0));
	deal[0] = rand() % 52;
	player_card(&i, &j);
	vs_card(&i, &j);
	gotoxy(83, 33);
	printf("�ƹ� Ű�� ������ ������ ����˴ϴ�.");
	getchar();
}

void player_card(int *i, int *j) {

	int choose = 2, q, k, ace;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(5, 7);   printf("[����]");
	gotoxy(5, 21);   printf("[�÷��̾�]");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


	gotoxy(45, 3);
	printf("������ �÷��̾�, ī�� ������ ���� �����ϴ�.");
	do {
		deal[1] = rand() % 52;
	} while (deal[0] == deal[1]);
	do {
		player[0] = rand() % 52;
	} while (player[0] == deal[0] || player[0] == deal[1]);
	do {
		player[1] = rand() % 52;
	} while (player[0] == player[1] || player[0] == deal[0] || player[0] == deal[1]);

	sum_deal = card[deal[0]] + card[deal[1]];
	sum_player = card[player[0]] + card[player[1]];
	card_design(1, card[deal[1]], 0);
	card_design(2, card[player[0]], card[player[1]]);

	gotoxy(45, 5);
	printf("�ƹ�Ű�� ������ �÷��̾��� ���ʷ� �Ѿ�ϴ�.");
	getchar();
	gotoxy(45, 5);
	printf("                                                    ");

	while (1) {
		while (choose != 1 && choose != 0) {
			gotoxy(45, 3);
			printf("ī�带 �� �����ðڽ��ϱ�? (������ 1, �ƴϸ� 0 �Է�) ");
			black_count++;
			scanf("%d", &choose);
			getchar();
		}
		if (choose == 1) {
			for (q = 0; q < *i; q++) {
				do {
					player[*i] = rand() % 52;
				} while (player[*i] == player[q]);
			}
			gotoxy(45, 5);
			printf("ī�� �� ���� �� �̾ҽ��ϴ�. ");
			gotoxy(45, 7);
			printf("�ƹ�Ű�� ������ ī�� ����� �Ѿ�ϴ�.");
			getchar();
			gotoxy(45, 3); printf("                                                                ");
			gotoxy(45, 5); printf("                                 ");
			gotoxy(45, 7); printf("                                        ");
			gotoxy(45, 3);
			if (card[player[*i]] == 1) {
				do {
					printf("Ace�� 1�� 11 �� � ���ڷ� ����Ͻðڽ��ϱ�? ");
					scanf("%d", &ace);
				} while (ace != 1 && ace != 11);
				if (ace == 1)card[player[*i]] = 1;
				else card[player[*i]] = 11;
				card_design(3, card[player[*i]], 0);
			}
			else if (player[*i] == 10 || player[*i] == 23 || player[*i] == 36 || player[*i] == 49)   card_design(3, 10, 1);
			else if (player[*i] == 11 || player[*i] == 24 || player[*i] == 37 || player[*i] == 50)   card_design(3, 10, 2);
			else if (player[*i] == 12 || player[*i] == 25 || player[*i] == 38 || player[*i] == 51) card_design(3, 10, 3);
			else card_design(3, card[player[*i]], 0);
			sum_player += card[player[*i]];
			(*i)++;
		}
		else if (choose == 0)break;
		choose = 2;
	}
	gotoxy(45, 5);
	printf("�ƹ�Ű�� ������ ������ ���ʷ� �Ѿ�ϴ�.");
	getchar();
	gotoxy(45, 5); printf("                                                ");
	black_count = 0;
	if (sum_deal <= 16) {
		do {
			for (q = 0; q < *j; q++) {
				do {
					deal[*j] = rand() % 52;
				} while (deal[*j] == deal[q]);
			}
			for (q = 0; q < *i; q++) {
				do {
					deal[*j] = rand() % 52;
				} while (deal[*j] == player[q]);
			}
			gotoxy(45, 3);
			printf("������ ������ ī�带 �� �̽��ϴ�.                             ");
			black_count++;
			if (card[deal[*j]] == 1) {
				if (sum_deal + 11 > 21) {
					card[deal[*j]] = 1;
				}
				else card[deal[*j]] = 11;
			}
			else if (deal[*j] == 10 || deal[*j] == 23 || deal[*j] == 36 || deal[*j] == 49)    card_design(4, 10, 1);
			else if (deal[*j] == 11 || deal[*j] == 24 || deal[*j] == 37 || deal[*j] == 50)   card_design(4, 10, 2);
			else if (deal[*j] == 12 || deal[*j] == 25 || deal[*j] == 38 || deal[*j] == 51)   card_design(4, 10, 3);
			else card_design(4, card[deal[*j]], 0);
			sum_deal += card[deal[*j]];
			(*j)++;
		} while (sum_deal <= 16);
	}
	else {
		gotoxy(45, 3);
		printf("���� ī���� ���� 16�� �Ѿ� �� �̻� ī�带 ���� �ʽ��ϴ�.");
	}
	gotoxy(45, 5);
	printf("�ƹ� Ű�� ������ ���� �ջ����� �Ѿ�ϴ�.                     ");
	getchar();

}
void vs_card(int *i, int *j) {
	gotoxy(90, 3);
	printf("# ���� ī�� �ջ� : %d", sum_deal);
	gotoxy(90, 5);
	printf("# �÷��̾� ī�� �ջ� : %d", sum_player);
	card_design(5, card[deal[0]], 0);
	gotoxy(20, 19);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	if (sum_player > 21) printf("�÷��̾��� ī�� ���� 21�� �Ѿ�⿡ [������ ��!]   ���� �ݾ� ���θ� �ҽ��ϴ�.");
	else if (sum_deal > 21) {
		printf("������ ī�� ���� 21�� �Ѿ�⿡ [�÷��̾��� ��!]   ���� �ݾ��� 2�踦 ����ϴ�. ");
		token += (money * 2);
	}
	else if (sum_deal == sum_player) {
		printf("[���º�]  ���ñݾ��� 0.5�踦 �ҽ��ϴ�.");
		token += (money*0.5);
	}
	else if (sum_deal > sum_player) printf("[������ ��!]  ���� �ݾ��� ���� �ҽ��ϴ�.");
	else {
		printf("[�÷��̾��� ��!]  ���� �ݾ��� 1.5�踦 ����ϴ�.");
		token += (money * 1.5);
	}
	return;
}

void card_design(int i, int j, int k) {
	int x = 0, y = 8, flag = 0;
	if (i == 2)   y = 22;
	if (i == 3) {
		x = 22 + (17 * black_count); y = 22;
	}
	if (i == 4) {
		x = 22 + (17 * black_count); y = 8;
	}
	if (i == 5) x = 17;
	while (1) {
		if (flag == 1) {
			x = 17;  y = 22; i = 3;  j = k;
		}
		if (j == 0) {
			x = 17; y = 8; i = 3;
		}
		gotoxy(5 + x, y++);
		printf("���������������������������������� ");
		gotoxy(5 + x, y++);
		printf("��               �� ");
		gotoxy(5 + x, y++);
		printf("��               �� ");
		gotoxy(5 + x, y++);
		printf("��               �� ");
		gotoxy(5 + x, y++);
		printf("��               �� ");
		gotoxy(5 + x, y++);
		printf("��               �� ");
		gotoxy(5 + x, y++);
		printf("��               �� ");
		gotoxy(5 + x, y++);
		printf("��               �� ");
		gotoxy(5 + x, y++);
		printf("��               �� ");
		gotoxy(5 + x, y++);
		printf("��               �� ");
		gotoxy(5 + x, y++);
		printf("���������������������������������� ");
		if (i == 2 || i == 3)y = 24;
		else y = 10;
		switch (j) {
		case 0:
			y = 10;
			gotoxy(7 + x, y++);
			printf("  ������");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("    �����");
			gotoxy(7 + x, y++);
			printf("    ��");
			gotoxy(7 + x, y++);
			printf("    �� ");
			gotoxy(7 + x, y++);
			printf("");
			gotoxy(7 + x, y++);
			printf("    �� ");
			break;
		case 1:
			gotoxy(7 + x, y++);
			printf("      ��");
			gotoxy(7 + x, y++);
			printf("  ����");
			gotoxy(7 + x, y++);
			printf("      ��");
			gotoxy(7 + x, y++);
			printf("      ��");
			gotoxy(7 + x, y++);
			printf("      ��");
			gotoxy(7 + x, y++);
			printf("      ��");
			gotoxy(7 + x, y++);
			printf("      ��");
			gotoxy(7 + x, y++);
			printf("  ������");
			break;
		case 2:
			gotoxy(7 + x, y++);
			printf("�������");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("�������");
			gotoxy(7 + x, y++);
			printf("�� ");
			gotoxy(7 + x, y++);
			printf("��");
			gotoxy(7 + x, y++);
			printf("��");
			gotoxy(7 + x, y++);
			printf("�������");
			break;
		case 3:
			gotoxy(7 + x, y++);
			printf("�������");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("�������");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("�������");
			break;
		case 4:
			gotoxy(7 + x, y++);
			printf("  ��      ��");
			gotoxy(7 + x, y++);
			printf("  ��      ��");
			gotoxy(7 + x, y++);
			printf("  ��      ��");
			gotoxy(7 + x, y++);
			printf("  ��      ��");
			gotoxy(7 + x, y++);
			printf("  ������");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("        ����");
			break;
		case 5:
			gotoxy(7 + x, y++);
			printf("�������");
			gotoxy(7 + x, y++);
			printf("��   ");
			gotoxy(7 + x, y++);
			printf("��    ");
			gotoxy(7 + x, y++);
			printf("�������");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("          ��");
			gotoxy(7 + x, y++);
			printf("�������");
			break;
		case 6:
			gotoxy(7 + x, y++);
			printf("�������");
			gotoxy(7 + x, y++);
			printf("��   ");
			gotoxy(7 + x, y++);
			printf("��    ");
			gotoxy(7 + x, y++);
			printf("��������");
			gotoxy(7 + x, y++);
			printf("��          ��");
			gotoxy(7 + x, y++);
			printf("��          ��");
			gotoxy(7 + x, y++);
			printf("��          ��");
			gotoxy(7 + x, y++);
			printf("��������");
			break;
		case 7:
			gotoxy(7 + x, y++);
			printf(" �������");
			gotoxy(7 + x, y++);
			printf(" ��        ��");
			gotoxy(7 + x, y++);
			printf(" ��        ��");
			gotoxy(7 + x, y++);
			printf("           ��");
			gotoxy(7 + x, y++);
			printf("           ��");
			gotoxy(7 + x, y++);
			printf("           ��");
			gotoxy(7 + x, y++);
			printf("           ��");
			gotoxy(7 + x, y++);
			printf("           ��");
			break;
		case 8:
			gotoxy(7 + x, y++);
			printf("  ������");
			gotoxy(7 + x, y++);
			printf("  ��      ��");
			gotoxy(7 + x, y++);
			printf("  ��      ��");
			gotoxy(7 + x, y++);
			printf("  ������");
			gotoxy(7 + x, y++);
			printf("  ��      ��");
			gotoxy(7 + x, y++);
			printf("  ��      ��");
			gotoxy(7 + x, y++);
			printf("  ��      ��");
			gotoxy(7 + x, y++);
			printf("  ������");
			break;
		case 9:
			gotoxy(7 + x, y++);
			printf(" �������");
			gotoxy(7 + x, y++);
			printf(" ��        ��");
			gotoxy(7 + x, y++);
			printf(" ��        ��");
			gotoxy(7 + x, y++);
			printf(" �������");
			gotoxy(7 + x, y++);
			printf("           ��");
			gotoxy(7 + x, y++);
			printf("           ��");
			gotoxy(7 + x, y++);
			printf("           ��");
			gotoxy(7 + x, y++);
			printf(" �������");
			break;
		case 10:
			if (i == 3 || i == 4 && k == 1) {
				gotoxy(7 + x, y++);
				printf(" �������");
				gotoxy(7 + x, y++);
				printf("         ��");
				gotoxy(7 + x, y++);
				printf("         ��");
				gotoxy(7 + x, y++);
				printf("         ��");
				gotoxy(7 + x, y++);
				printf("         ��");
				gotoxy(7 + x, y++);
				printf("         ��");
				gotoxy(7 + x, y++);
				printf(" ��      ��");
				gotoxy(7 + x, y++);
				printf("  �����");
				break;
			}
			else if (i == 3 || i == 4 && k == 2) {
				gotoxy(7 + x, y++);
				printf(" �������");
				gotoxy(7 + x, y++);
				printf(" ��        ��");
				gotoxy(7 + x, y++);
				printf(" ��        ��");
				gotoxy(7 + x, y++);
				printf(" ��        ��");
				gotoxy(7 + x, y++);
				printf(" ��        ��");
				gotoxy(7 + x, y++);
				printf(" ��   ��   ��");
				gotoxy(7 + x, y++);
				printf(" �������");
				gotoxy(7 + x, y++);
				printf("         ��");
				break;
			}
			else if (i == 3 || i == 4 && k == 3) {

				gotoxy(7 + x, y++);
				printf("   ��     ��");
				gotoxy(7 + x, y++);
				printf("   ��   ��");
				gotoxy(7 + x, y++);
				printf("   ��  �� ");
				gotoxy(7 + x, y++);
				printf("   �� �� ");
				gotoxy(7 + x, y++);
				printf("   �� �� ");
				gotoxy(7 + x, y++);
				printf("   ��  ��");
				gotoxy(7 + x, y++);
				printf("   ��   �� ");
				gotoxy(7 + x, y++);
				printf("   ��    ��");
				break;
			}
			else {
				gotoxy(7 + x, y++);
				printf(" ��  �����");
				gotoxy(7 + x, y++);
				printf(" ��  ��    ��");
				gotoxy(7 + x, y++);
				printf(" ��  ��    ��");
				gotoxy(7 + x, y++);
				printf(" ��  ��    ��");
				gotoxy(7 + x, y++);
				printf(" ��  ��    ��");
				gotoxy(7 + x, y++);
				printf(" ��  ��    ��");
				gotoxy(7 + x, y++);
				printf(" ��  ��    ��");
				gotoxy(7 + x, y++);
				printf(" ��  �����");
				break;
			}
		case 11:
			gotoxy(7 + x, y++);
			printf("  ��    ��");
			gotoxy(7 + x, y++);
			printf("���  ���");
			gotoxy(7 + x, y++);
			printf("  ��    ��");
			gotoxy(7 + x, y++);
			printf("  ��    ��");
			gotoxy(7 + x, y++);
			printf("  ��    ��");
			gotoxy(7 + x, y++);
			printf("  ��    ��");
			gotoxy(7 + x, y++);
			printf("  ��    ��");
			gotoxy(7 + x, y++);
			printf("  ��    ��");
			break;
		}
		if (i == 1) j = 0;
		else if (i == 3 || i == 4 || i == 5)break;
		else if (i == 2) {
			flag = 1;
			continue;
		}
	}


}