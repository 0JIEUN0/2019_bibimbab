#include "�غ���.h" /// ó������ ������ ���������� ����Ұ�
int horse_s[5], rank_s[6], luckyhorse;  // horse_s[] = ���� �޸� �Ÿ�, rank=���
int lucky_num[5] = { 1,1,1,0,0 };

void horse() {
	
	int h, winner, select_num, money, i;
	CursorView(0);
	horse_design();
	luckyhorse = (rand() % 5) + 1;

	gotoxy(50, 8);
	printf("���ָ� ����");
	gotoxy(50, 13);
	printf("  ��");
	gotoxy(50, 14);
	printf(" ��������/ ");
	gotoxy(50, 15);
	printf("/��  �� ");
	gotoxy(50, 16);
	printf(" �������� ");
	gotoxy(50, 17);
	printf("  ���� ");

	gotoxy(60, 13);
	printf("������ ��� ��");
	gotoxy(60, 15);
	printf("%d�� ��!", luckyhorse);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(60, 17);
	printf("���� [������] �¸����� �ʽ��ϴ�.");


	gotoxy(0, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("# ������ ��ū�� ���� : %d", token);
	select_num = select_horse();
	gotoxy(0, 3);
	printf("# ������ ���� ��ȣ : %d", select_num);


	while (1) {
		gotoxy(53, 21);
		printf("������ ��ū�� ������ �Է��Ͻÿ�: ");
		scanf("%d", &money); getchar();
		if (money > token) {
			gotoxy(53, 23);
			printf("(system) ��ū�� ������ �����մϴ�.");
			gotoxy(72, 21);
			printf("                                                         ");
		}
		else {
			gotoxy(53, 23);
			printf("(system) ������ ��ū�� ������ �����Ǿ����ϴ�. ");
			break;
		}
	}
	token -= money;
	gotoxy(0, 1);
	printf("# ������ ��ū�� ���� : %d", token);
	gotoxy(0, 5);
	printf("# ������ ��ū�� �� : %d", money);
	gotoxy(40, 28);
	printf("enter Ű�� ������ ���ְ� ���۵˴ϴ�.");
	getchar();
	for (i = 0; i < 3; i++) {
		gotoxy(80, 28);
		printf("%d", i + 1);
		Sleep(1000);
		printf("\b ");
	}

	winner = run_horse(select_num, money);
	gotoxy(70, 15);
	printf("%d�� ���� ����Ͽ����ϴ�!", winner);
	if (select_num == winner) {
		gotoxy(70, 17);
		printf("���ϵ帳�ϴ�.������ ���� ����Ͽ����ϴ�.");
		token += (2 * money);
		gotoxy(70, 19);
		printf("���ñݾ��� 2�踦 ����ϴ�.");
	}
	else {
		gotoxy(70, 17);
		printf("������ ���� ������� ���Ͽ����ϴ�.");
		gotoxy(70, 19);
		printf("���ñݾ��� ���θ� �Ҿ����ϴ�.");
	}
	gotoxy(40, 30);
	printf("�ƹ� Ű�� ������ ������ ����˴ϴ�.");
	getchar();

}

int select_horse() {
	int i = 0;
	gotoxy(53, 21);
	printf("1��  2��  3��  4��  5��");
	gotoxy(53, 23);
	printf("���� �������ֽʽÿ�. ");
	scanf("%d", &i);
	while (i < 1 || i>5) {
		gotoxy(53, 25);
		printf("�߸� �����ϼ̽��ϴ�.");
		gotoxy(53, 21);
		printf("1��  2��  3��  4��  5��");
		gotoxy(53, 23);
		printf("���� �ٽ� �������ֽʽÿ�. ");
		scanf("%d", &i);
	}
	gotoxy(53, 25);
	printf("                                ");
	gotoxy(53, 23);
	printf("                                  ");
	return i;
}


int run_horse(int a, int b) {
	int i, cnt = 0, num, dis, w, j; // cnt=Ƚ��, num = �� ��ȣ, dis=���� �޸� �Ÿ�
	system("cls");

	gotoxy(0, 1);
	printf("# ������ ��ū�� ���� : %d", token);
	gotoxy(0, 3);
	printf("# ������ ���� ��ȣ : %d", a);
	gotoxy(0, 5);
	printf("# ������ ��ū�� �� : %d", b);

	gotoxy(68, 3);
	printf("�ݢܢݢܢݢ�");
	gotoxy(48, 5);
	printf("      ��           ��            ��           ��");
	gotoxy(48, 6);
	printf("    ����������/     ����  )��      |��������|       ����  )��         ");
	gotoxy(48, 7);
	printf("������������������������������������������������������������������������������������������������������������");


	gotoxy(10, 13);
	printf("������������������������������������������������������������������������������������������������������������");
	gotoxy(55, 11); printf("<end>");
	for (i = 0; i < 5; i++) {
		gotoxy(10, 15 + i * 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i + 9);
		printf("# %d�� ��  �� %d", i + 1, i + 1);
		gotoxy(10, 16 + i * 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("������������������������������������������������������������������������������������������������������������");
		rank_s[i] = 0;
		horse_s[i] = 0;
	}
	while (cnt != 5) {
		num = rand() % 5;
		if (rank_s[num] != 0)continue;
		dis = rand() % 2 + 2;
		if (lucky_num[luckyhorse] == 1) horse_s[num] += (dis + 2);
		else horse_s[num] += dis;
		Sleep(300);
		if (horse_s[num] > 39) {
			horse_s[num] = 40;
			if (!rank_s[num]) {
				cnt++;
				rank_s[num] = cnt;
				gotoxy(18, 15 + num * 3);
				for (i = 0; i < horse_s[num]; i++)
					printf(" ");
				if (horse_s[num])
					printf("�� %d", num + 1);
				gotoxy(57, 15 + num * 3);
				printf("   %d��", cnt);
				if (cnt == 1)w = (num + 1);
			}
		}
		else {
			gotoxy(18, 15 + num * 3);
			for (i = 0; i < horse_s[num]; i++)
				printf(" ");
			if (horse_s[num])
				printf("�� %d", num + 1);
		}
	}
	return w;
}


void horse_design() {
	system("cls");
	gotoxy(1, 10);
	printf("                       sss        ");
	gotoxy(1, 11);
	printf("                    ssssssssss  ");
	gotoxy(1, 12);
	printf("                    sssssssssss ");
	gotoxy(1, 13);
	printf("                  sssssssssssss ");
	gotoxy(1, 14);
	printf("                 sssssssssssssssss ");
	gotoxy(1, 15);
	printf("                sssssssssssssssssssss");
	gotoxy(1, 16);
	printf("               sssssssssssssssssssssss");
	gotoxy(1, 17);
	printf("               sssssssssssssssssssssssso ");
	gotoxy(1, 18);
	printf("             ssssssssssooossssss   ssssss          ");
	gotoxy(1, 19);
	printf("          osssssssssos    sssssso  ssss              ");
	gotoxy(1, 20);
	printf("         osssssssos    sosssssso   sss     ");
	gotoxy(1, 21);
	printf("          'sssssso     ssssssssso  ssss      ");
	gotoxy(1, 22);
	printf("                      ssssssssss+  ssssss        ");
	gotoxy(1, 23);
	printf("                    sssssssssso   ssssss.      ");
	gotoxy(1, 24);
	printf("                   sssssssssssso  ssss  ");
	gotoxy(1, 25);
	printf("                  ssssssssssssssssssss     ");
	gotoxy(1, 26);
	printf("                 sssssssssssssssssssss    ");



}