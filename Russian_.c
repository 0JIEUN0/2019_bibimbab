#include "�غ���.h"

void draw_gun(int n) {
	color(15);
	gotoxy(0, 1);
	printf("# ���� ��ū�� �� : %d ", token);
	color(6);
	gotoxy(7, 5);
	puts("    ��			    	    ����");
	gotoxy(7, 6);
	puts("  ���������������������������");
	gotoxy(7, 7);
	puts(" ���������������������������");
	gotoxy(7, 8);
	puts("���������������������������");
	gotoxy(7, 9);
	puts(" ���������������������������");
	gotoxy(7, 10);
	puts("   ������  ����  ����������������");
	gotoxy(7, 11);
	puts("   ������    ���    ��");
	gotoxy(7, 12);
	puts("   ������      ��    �� ");
	gotoxy(7, 13);
	puts("   �������        ���");
	gotoxy(7, 14);
	puts("   �������������");
	gotoxy(7, 15);
	puts("   ��������");
	gotoxy(7, 16);
	puts("  ��������");
	gotoxy(7, 17);
	puts(" ��������");
	gotoxy(7, 18);
	puts(" ��������");
	gotoxy(7, 19);
	puts("��������");
	gotoxy(7, 20);
	puts("��������");
	gotoxy(7, 21);
	puts("��������");
	gotoxy(7, 22);
	puts("��������");
	gotoxy(7, 23);
	color(15);

	if (n) {
		gotoxy(17, 8);
		switch (n) {
		case 7:
			puts("�ܡܡܡܡܡ� ");
			break;
		case 6:
			puts("�ܡܡܡܡܡ� ");
			break;
		case 5:
			puts("�ܡܡܡܡۡ� ");
			break;
		case 4:
			puts("�ܡܡܡۡۡ� ");
			break;
		case 3:
			puts("�ܡܡۡۡۡ� ");
			break;
		case 2:
			puts("�ܡۡۡۡۡ� ");
			break;
		case 1:
			puts("�ۡۡۡۡۡ� ");
			break;
		}


	}
}

void Russian_roulette() {
	int i = 0, f, n;
	int j;
	int ch;
	char russ[6] = { 0, };
	CursorView(0);
	gotoxy(0, 1);
	printf("# ���� ��ū�� �� : %d", token);
	system("cls");
	gotoxy(50, 7);
	printf("+ ���þ� �귿 +");
	gotoxy(23, 9);
	printf("����ϸ� ��� ����� �������, �����ϸ� ���� ��ū�� 300�踦 ��� �˴ϴ�.");
	gotoxy(48, 13);
	printf("�޾Ƶ��̽ðڽ��ϱ�?");
	color(5);
	gotoxy(44, 18);
	puts("�������������������������������������������������� ");
	gotoxy(44, 19);
	puts("��           ��           �� ");
	gotoxy(44, 20);
	puts("��           ��           �� ");
	gotoxy(44, 21);
	puts("��           ��           �� ");
	gotoxy(44, 22);
	puts("�������������������������������������������������� ");
	color(15);
	gotoxy(49, 20);
	puts("yes");
	gotoxy(62, 20);
	puts("no");
	while (1) {
		ch = getch();
		if (ch == 224) {
			ch = getch();
			switch (ch) {
			case 75:			//����
				color(15);
				gotoxy(62, 20);
				puts("no");
				color(6);
				gotoxy(49, 20);
				puts("yes");
				f = 1;
				break;
			case 77:			//������
				color(15);
				gotoxy(49, 20);
				puts("yes");
				color(6);
				gotoxy(62, 20);
				puts("no");
				f = 0;
				break;
			}
		}
		else if (ch == 13) break;
	}
	color(15);
	system("cls");

	if (f) {
		draw_gun(0);
		gotoxy(55, 13);
		printf("6���� �������� ���տ� �ֽ��ϴ�.");
		Sleep(1000);
		gotoxy(50, 15);
		printf("�Ѿ��� �� �߸� �����ϰ� źâ�� �����ϴ�");
		Sleep(1000);
		gotoxy(50, 15);
		printf("�Ѿ��� �� �߸� �����ϰ� źâ�� �����ϴ�.");
		Sleep(1000);
		gotoxy(50, 15);
		printf("�Ѿ��� �� �߸� �����ϰ� źâ�� �����ϴ�..");
		Sleep(1000);
		gotoxy(50, 15);
		printf("�Ѿ��� �� �߸� �����ϰ� źâ�� �����ϴ�...");
		Sleep(1000);
		russ[rand() % 6] = 1;			//���� �� �� �ϳ��� 1�� �ٲ���(����)
		gotoxy(56, 19);
		printf("���� ��Ƽ踦 ���ðڽ��ϱ�?");
		color(5);
		gotoxy(57, 21);
		puts("�������������������������������������������������� ");
		gotoxy(57, 22);
		puts("��           ��           �� ");
		gotoxy(57, 23);
		puts("��           ��           �� ");
		gotoxy(57, 24);
		puts("��           ��           �� ");
		gotoxy(57, 25);
		puts("�������������������������������������������������� ");
		color(15);
		gotoxy(62, 23);
		puts("yes");
		gotoxy(75, 23);
		puts("no");
		while (1) {
			ch = getch();
			if (ch == 224) {
				ch = getch();
				switch (ch) {
				case 75:			//����
					color(15);
					gotoxy(75, 23);
					puts("no");
					color(6);
					gotoxy(62, 23);
					puts("yes");
					f = 1;
					break;
				case 77:			//������
					color(15);
					gotoxy(62, 23);
					puts("yes");
					color(6);
					gotoxy(75, 23);
					puts("no");
					f = 0;
					break;
				}
			}
			else if (ch == 13) break;
		}
		system("cls");
		n = 7;
		draw_gun(n);
		if (f) {
			while (1) {
				if (!(i % 2)) {
					gotoxy(67, 7);
					printf("[%s] �� ��Ƽ踦 �����ϴ�.", name);
					Sleep(2000);
					if (russ[i] == 0) {
						gotoxy(67, 9);
						printf("ƽ! �ҹ��Դϴ�.");
						n--;
						draw_gun(n);
						Sleep(1000);
					}
					else {
						gotoxy(67, 9);
						printf("��!");
						n--;
						draw_gun(n);
						Sleep(1000);
						gotoxy(67, 13);
						printf("[%s] �� ����Ͽ����ϴ�.", name);
						Sleep(1000);
						color(1);
						gotoxy(40, 20);
						printf("��� ������ ��ϵ�, ��ū�� ������ϴ�.");
						token = 0;
						Sleep(2000);
						system("cls");
						ending();
						Sleep(1000);
						out();
						break;
					}
				}
				else {
					gotoxy(67, 7);
					printf("[COMPUTER] �� ��Ƽ踦 �����ϴ�.");
					Sleep(2000);
					if (russ[i] == 0) {
						gotoxy(67, 9);
						printf("ƽ! �ҹ��Դϴ�.");
						n--;
						draw_gun(n);
						Sleep(1000);
					}
					else {
						gotoxy(67, 9);
						printf("��!");
						n--;
						draw_gun(n);
						Sleep(1000);
						gotoxy(67, 13);
						printf("[COMPUTER] �� ����Ͽ����ϴ�.");
						color(1);
						gotoxy(58, 19);
						printf("�����մϴ�.");
						gotoxy(30, 21);
						printf("����� �� �ѹ��� ��ȸ�� �������� ���� ������ 300�踦 ��� �Ǿ����ϴ�.");
						color(8);
						gotoxy(35, 26);
						printf("--�ƹ� Ű�� ������ ������ ����˴ϴ�.--");
						color(15);
						token = token * 300;
						getch();
						break;
					}
				}
				i++;
				system("cls");
				draw_gun(n);
				Sleep(1000);
			}
		}
		else {
			while (1) {
				if (!(i % 2)) {
					gotoxy(67, 7);
					printf("[COMPUTER] �� ��Ƽ踦 �����ϴ�.");
					Sleep(2000);
					if (russ[i] == 0) {
						gotoxy(67, 9);
						printf("ƽ! �ҹ��Դϴ�.");
						n--;
						draw_gun(n);
						Sleep(1000);
					}
					else {
						gotoxy(67, 9);
						printf("��!");
						n--;
						draw_gun(n);
						Sleep(1000);
						gotoxy(67, 13);
						printf("[COMPUTER] �� ����Ͽ����ϴ�.");
						color(1);
						gotoxy(58, 19);
						printf("�����մϴ�.");
						gotoxy(30, 21);
						printf("����� �� �ѹ��� ��ȸ�� �������� ���� ������ 300�踦 ��� �Ǿ����ϴ�.");
						color(8);
						gotoxy(35, 26);
						printf("--�ƹ� Ű�� ������ ������ ����˴ϴ�.--");
						color(15);
						token = token * 300;
						getch();
						break;
					}
				}
				else {
					gotoxy(67, 7);
					printf("[%s] �� ��Ƽ踦 �����ϴ�.", name);
					Sleep(2000);
					if (russ[i] == 0) {
						gotoxy(67, 9);
						printf("ƽ! �ҹ��Դϴ�.");
						n--;
						draw_gun(n);
						Sleep(1000);
					}
					else {
						gotoxy(67, 9);
						printf("��!");
						n--;
						draw_gun(n);
						Sleep(1000);
						gotoxy(67, 13);
						printf("[%s] �� ����Ͽ����ϴ�.", name);
						Sleep(1000);
						color(1);
						gotoxy(40, 20);
						printf("��� ������ ��ϵ�, ��ū�� ������ϴ�.");
						token = 0;
						Sleep(2000);
						system("cls");
						ending();
						Sleep(1000);
						out();
						break;
					}
				}
				i++;
				system("cls");
				draw_gun(n);
				Sleep(1000);
			}
		}
	}
	CursorView(1);
}

void out() {
	struct user u[5];
	FILE *fb = NULL;
	int k = 0, i = 0, z = 0, n, end;

	fb = fopen("list.txt", "r");
	if (fb == NULL) {
		printf("FILE OPEN ERROR\n");
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
	fclose(fb); //���� �ϴ� �ݾ���

	while (1) {
		if (!(strcmp(name, u[k].name))) {
			fb = fopen("list.txt", "w"); //������ ���� ���, �����Ͱ� ������ �� ����� �Է��Ѵ�
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}
			for (z = 0; z < n ; z++) {		//���� �ִ� ����� ������ ����
				if (z != k) {
					fprintf(fb, "%s %d\n", u[z].name, u[z].score);
				}
			}
			fclose(fb);
			break;
		}
		k++;
		if (k == n) break;
	}
}