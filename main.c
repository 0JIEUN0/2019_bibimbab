#include "�غ���.h"

/*
		system("cls");
		gotoxy(0, 1);
		printf("# ���� ��ū�� �� : %d", token);
			*/


int main() {
	system("mode con cols=120 lines=35");
	int menu;
	srand((unsigned)time(0));
	CursorView(0);
	opening();
	user_menu();
	gotoxy(40, 22);
	printf("enterŰ�� ������ ���Ӹ޴��� �Ѿ�ϴ�.");
	getch();
	while (1) {

		system("cls");
		design();
		gotoxy(0, 3);
		printf("# ���� ��ū�� �� : %d", token);
		do {
			gotoxy(50, 11);
			printf("+ l ���� �޴� �� +");
			gotoxy(51, 14);
			printf("1) ī���� ����");
			gotoxy(51, 16);
			printf("2) ���� ����");
			gotoxy(51, 18);
			printf("3) ���� ���� ��");
			gotoxy(51, 20);
			printf("4) ���α׷� ����");
			gotoxy(50, 23);
			printf("�޴��� �����ϼ���: ");
			scanf("%d", &menu);
			getchar();
		} while (menu < 1 || menu>4);

		if (menu == 4) {
			end_rank();
			break;
		}

		switch (menu) {
		case 1:
			menu2();
			break;
		case 2:
			rank();
			break;
		case 3:
			developer();
			break;
		}
		if (token == 0)break;
	}
	return 0;
}

void menu2() {
	int menu;
	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (token == 0) {
			lucky_box();
			if (token == 0)break;
		}
		system("cls");
		design();
		gotoxy(0, 3);
		printf("# ���� ��ū�� �� : %d", token);
		do {
			gotoxy(50, 10);
			printf("+ l ī���� ���� �� +");
			gotoxy(53, 12);
			printf("1) ���ָ�\n");
			gotoxy(53, 14);
			printf("2) ���Ըӽ�\n");
			gotoxy(53, 16);
			printf("3) ����\n");
			gotoxy(53, 18);
			printf("4) �귿\n");
			gotoxy(53, 20);
			printf("5) ���̻���\n");
			gotoxy(53, 22);
			printf("6) ���� �޴��� ���ư���\n");
			gotoxy(51, 25);
			printf("�޴��� �����ϼ���: ");
			scanf("%d", &menu);
			getchar();
		} while (menu < 1 || menu>6);

		if (menu == 6) {
			system("cls");
			break;
		}
		if (show_rule(menu)) {
			switch (menu) {
			case 1:
				horse();
				break;
			case 2:
				slot();
				break;
			case 3:
				black();
				break;
			case 4:
				roulette();
				break;
			case 5:
				taisai();
				break;
			}
		}
	}
}

int show_rule(int m) {
	char ch;
	system("cls");
	gotoxy(0, 3);
	printf("# ���� ��ū�� �� : %d", token);
	switch (m) {
	case 1:
		gotoxy(13, 11);
		printf("    `.`");
		gotoxy(13, 12);
		printf("     -//:--.`");
		gotoxy(13, 13);
		printf("    `::++++++/:.");
		gotoxy(13, 14);
		printf(" `-/++++++++++++/.");
		gotoxy(13, 15);
		printf(" :+++:-::/++++++++:");
		gotoxy(13, 16);
		printf(" `::`    -+++++++++/`");
		gotoxy(13, 17);
		printf(" `..`     -+++++++++/`");
		gotoxy(13, 18);
		printf("           ````````````");
		gotoxy(39, 11);
		printf("+ ���ָ� ���� +");
		gotoxy(39, 13);
		printf("�� 5������ ���� ���ָ� �ϰ� �˴ϴ�.\n");
		gotoxy(39, 15);
		printf("������ ���� ������ �� ���� �ݾ��� �Է��մϴ�.\n");
		gotoxy(39, 17);
		printf("������ �� ���� ����ϸ� ���ñݾ��� 2�踦 ����ϴ�.");
		gotoxy(39, 19);
		printf("�ݴ��, ������ �� ���� ������� ������ ��, ���� �ݾ��� ���θ� �ҽ��ϴ�.\n\n");
		break;
	case 2:
		gotoxy(10, 9);
		puts("    hy/y:oo+o+/+o//oo+y+sm");
		gotoxy(10, 10);
		puts("    hy/y:oo+o+/+o//oo+y+sm");
		gotoxy(9, 11);
		puts("  o-osssyyos/sooo+sossdshy+o-o");
		gotoxy(9, 12);
		puts("::hdhhhhhhhhhhhhhhhhhhhhhddy++h::");
		gotoxy(9, 13);
		puts(":+hmd       ��       ��        hy/:");
		gotoxy(9, 14);
		printf(":+ymh hhhhhh�� hhhhhh�� hhhhhh hy/:");
		gotoxy(9, 15);
		printf("/+hmd     //��     //��     // lmho");
		gotoxy(9, 16);
		printf("/+ydd    // ��    // ��    //  ddy:");
		gotoxy(9, 17);
		printf(":/s/s   //  ��   //  ��   //   s+y+");
		gotoxy(9, 18);
		printf(".+o//       ��       ��        ooy+");
		gotoxy(7, 19);
		printf(" :ohyyhddhhhddhyyhhhhhddddddddhhhho:");
		gotoxy(7, 20);
		printf(" +:+o++++++++++++++++++++++++++oo+:+");
		gotoxy(7, 21);
		printf(" +:+o++++++++++++++++++++++++++oo+:+");
		gotoxy(47, 11);
		printf("+ ���Ըӽ� +");
		gotoxy(47, 13);
		printf("���� Ȥ�� �밢�� �������� ������ �����ϸ� ������ ������ ����");
		gotoxy(47, 14);
		printf("������ ��� �˴ϴ�.");
		gotoxy(47, 16);
		printf("[��ū ȹ�� ���]");
		gotoxy(47, 18);
		printf("���Ըӽ��� ���� ���� Ȥ�� �밢�� �������� ���ǿ� �����ϴ� ��ȣ��");
		gotoxy(47, 19);
		printf("������ �ּ� 1��, �ִ� 7�踦 ��� �˴ϴ�.\n\n\n\n");
		break;
	case 3:
		gotoxy(10, 6);
		printf("            ������   ");
		gotoxy(10, 7);
		printf("          ��          ��     ");
		gotoxy(10, 8);
		printf("        ��              ��     ");
		gotoxy(10, 9);
		printf("        ��              ��     ");
		gotoxy(10, 10);
		printf("        ��              ��     ");
		gotoxy(10, 11);
		printf("        ��      ��      ��     ");
		gotoxy(10, 12);
		printf("        ��     ���     ��     ");
		gotoxy(10, 13);
		printf("        ��   �����   ��     ");
		gotoxy(10, 14);
		printf("        �� ������� ��     ");
		gotoxy(10, 15);
		printf("        ��   �����   ��     ");
		gotoxy(10, 16);
		printf("        ��     ���     ��     ");
		gotoxy(10, 17);
		printf("        ��      ��      ��     ");
		gotoxy(10, 18);
		printf("        ��              ��     ");
		gotoxy(10, 19);
		printf("        ��              ��     ");
		gotoxy(10, 20);
		printf("        ��              ��     ");
		gotoxy(10, 21);
		printf("          ��          ��     ");
		gotoxy(10, 22);
		printf("            ������");
		gotoxy(45, 6);
		printf("����");
		gotoxy(45, 8);
		printf("Ace = 1 or 11    2 ~ 10 = �� ���� ��    J, Q, K = 10");
		gotoxy(45, 10);
		printf("������ �÷��̾ ���� 2���� ���� �����ϴ�");
		gotoxy(45, 12);
		printf("������ ������ ī�尡 16�� �Ѿ�� �״�� ����ϴ�.");
		gotoxy(45, 14);
		printf("[��ū ȹ�� ���]");
		gotoxy(45, 16);
		printf("�÷��̾��� ���� ���� 21�� �Ѿ�� ���ñݾ��� ���� �ҽ��ϴ�.");
		gotoxy(45, 18);
		printf("�������� ī������� ���� 21�� �����ٸ�, ���ñݾ��� 1.5�踦 ����ϴ�.");
		gotoxy(45, 21);
		printf("������ ���� ���� ���� ���ñݾ��� 0.5�踦 �ҽ��ϴ�.");
		break;
	case 4:
		gotoxy(12, 9);
		puts("         .--:--:--.         ");
		gotoxy(12, 10);
		puts("     -+shysoo/+oosyys+-     ");
		gotoxy(12, 11);
		puts("   /sysosysNd/+ydmo++syy/`  ");
		gotoxy(12, 12);
		puts(" .sys/syds:-:/:-:/+dNs/shy. ");
		gotoxy(12, 13);
		puts(" sys-hNd---:///:---:sys:shy ");
		gotoxy(12, 14);
		puts("`yyo-ddo----:::::---sNM/+yh.");
		gotoxy(12, 15);
		puts("`yyy:sdh+:---------ohyo-yhh.");
		gotoxy(12, 16);
		puts(" +yys/+d//yo////syyhdo:shhs ");
		gotoxy(12, 17);
		puts("  +hsys+/+yysddsyyo/+ssyho  ");
		gotoxy(12, 18);
		puts("   `+hhhhhysooooosyyhhh+.   ");
		gotoxy(12, 19);
		puts("      ./oyhhhhhhhhys+-      ");
		gotoxy(12, 20);
		puts("            ````            ");
		gotoxy(46, 8);
		printf("+ �귿 +");
		gotoxy(46, 10);
		printf("������ ���ڰ� ǥ�õ� ��(Wheel)�� ȸ����Ų ��, �� �ݴ� ��������");
		gotoxy(46, 11);
		puts("���� ȸ������ ���� �����Ǵ� ����(0~36)�� ���� ������ �÷��̾��");
		gotoxy(46, 12);
		printf("������ �׼��� �����ϴ� �����Դϴ�.");
		gotoxy(46, 14);
		printf("���� ����: 1���� ���ڿ� ����\n");
		gotoxy(46, 15);
		printf("���� ����: 2���� ���ڿ� ����\n");
		gotoxy(46, 16);
		printf("���� ����: �� �� �ϳ��� ���� ����\n");
		gotoxy(46, 18);
		puts("[��ū ȹ�� ���]");
		gotoxy(46, 20);
		puts("���� ����� �����ؼ� ���߸� ���� ������ ���� �ݾ��� 35��,");
		gotoxy(46, 21);
		puts("���� ������ 17��, ���� ������ 5�踦 ��� �˴ϴ�.");
		break;
	case 5:
		gotoxy(14, 10);
		printf(" :+ooooooooosssssooss+:");
		gotoxy(14, 11);
		printf(" oo+   :oooossss:   +ss");
		gotoxy(14, 12);
		printf(":oo-   `osoossso.   :ss:");
		gotoxy(14, 13);
		printf(":ooo/:/+oooosssso//+sss:");
		gotoxy(14, 14);
		printf(":ooooooooo- -:ossssssss:");
		gotoxy(14, 15);
		printf(":oooooooo/    +ssssssss:");
		gotoxy(14, 16);
		printf(":ooooooooo/:/+sssssssss:");
		gotoxy(14, 17);
		printf(":oo+-../oooossss/--:oss:");
		gotoxy(14, 18);
		printf(":oo-   `ooosssso`  `:ss:");
		gotoxy(14, 19);
		printf(" ooo:-:+oooossss+../oss");
		gotoxy(14, 20);
		printf(" :/+ooooooooooooooooo+:");
		gotoxy(47, 10);
		printf("+ ���̻��� +");
		gotoxy(47, 12);
		printf("�ֻ��� 3���� ���� ������ �ֻ������� ���� �����ϰų� �ֻ��� 3����");
		gotoxy(47, 13);
		printf("���ڸ� ������ �����ϸ� ������ ������ ���� ������ ���޵Ǵ� ����");
		gotoxy(47, 14);
		printf("�Դϴ�.");
		gotoxy(47, 16);
		printf("[��ū ȹ�� ���]");
		gotoxy(47, 18);
		printf("������ �� �ִ� ������ ������ 4�����̸� ������ �����ϸ� �ּ� 1.2��,");
		gotoxy(47, 19);
		printf("�ִ� 150�踦 ��� �˴ϴ�.\n\n");
		break;
	}
	gotoxy(28, 26);
	printf("ī���� ���� Ư�� �� �ѹ� ������ �����ϸ� �߰��� ���� �� �����ϴ�.");
	gotoxy(27, 28);
	printf("������ �����Ͻ÷��� �ƹ� Ű�� �����ð�, ���ư��÷��� esc�� ��������.");
	ch = getch();
	if (ch == 27) return 0;
	else system("cls");
	return 1;
}

void gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void color(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}


/*
#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>     // fopen, fwrite, fclose �Լ��� ����� ��� ����
#include <string.h>    // strcpy, memset �Լ��� ����� ��� ����

#pragma pack(push, 1)    //  1����Ʈ ũ��� ����
struct Data {
	char c1;        //  1����Ʈ
	short num1;     //  2����Ʈ
	int num2;       //  4����Ʈ
	char s1[20];    // 20����Ʈ
};
#pragma pack(pop)       // ���� ������ ���� ����(�⺻��)�� �ǵ���

int main()
{
	struct Data d1;
	memset(&d1, 0, sizeof(d1));    // ����ü ������ ������ 0���� �ʱ�ȭ

	d1.c1 = 'a';                       // ���� ����
	d1.num1 = 32100;                   // 2����Ʈ ũ���� ���� ����
	d1.num2 = 2100000100;              // 4����Ʈ ũ���� ���� ����
	strcpy(d1.s1, "Hello, world!");    // ���ڿ� ����

	FILE *fp = fopen("data2.bin", "wb");   // ������ ����/���̳ʸ� ���(wb)�� ����

	fwrite(&d1, sizeof(d1), 1, fp);        // ����ü�� ������ ���Ͽ� ����

	fclose(fp);    // ���� ������ �ݱ�

	return 0;
}*/