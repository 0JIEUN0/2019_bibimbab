#include "�غ���.h"

int rank() {	//�� 3���� ���
				//������� 5�� �ȿ� �� ���, �����δ� �������� ������ �� ������ ���� ���(��ŷ���)
				//������ ����� ���(������ �� ���ִ� ���.��Ͼȵ�)
	struct user u[5];
	FILE *fb = NULL;
	int k = 0, i = 0, j = 0, z = 0, e = 0, n, end, tmp;

	system("cls");
	gotoxy(0, 2);
	printf("# ���� ��ū�� �� : %d", token);

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

	//�̹� ��ŷ ����� ����
	while (1) {
		if (!(strcmp(name, u[k].name))) {
			fb = fopen("list.txt", "w+"); //������ ���� ���, �����Ͱ� ������ �� ����� �Է��Ѵ�
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}
			for (z = 0; z < n ; z++) {		//���� �ִ� ����� ������ ����
				if (z != k) {
					fprintf(fb, "%s %d\n", u[z].name, u[z].score);
				}
			}

			/*
			for (z = 0; z < 5; z++) {			//�迭 �ʱ�ȭ
				strcpy(u[z].name, "\0");
				u[z].score = 0;
			}
			*/
			fseek(fb, 0, 2);	//������ ���������� �̵�
			end = ftell(fb);

			rewind(fb);
			i = 0;
			while (ftell(fb) != end) {
				fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
				i++;
			}
			n = i; //��ϵ� ����� ��(1~5)
			fclose(fb);
			break;
		}
		k++;
		if (k == n) break;
	}

	i = 0;
	while (1) {
		if (token >= u[i].score) {	//������ ������ ���� �ʴ� �̻� � �ͺ��� Ŭ ��
									//���� �����ڰ� ������ �ֽ� ����ڰ� �� ���� ������ ������
			if (n == 5) { //������ ����(5��) ����� ����
				j = 4;
			}
			else {
				j = n;	//��ϵ� ����� ������ 1�� �� ����ؾ� �ϹǷ� --n�� �ƴ� �׳� n
				n++;	//��ϵ� ��� ���� �߰���
			}
			while (j != i) {
				u[j].score = u[j - 1].score;
				strcpy(u[j].name, u[j - 1].name);
				j--;
			}
			u[i].score = token;
			strcpy(u[i].name, name);

			//���� ����
			fb = fopen("list.txt", "w"); //������ ���� ���, �����Ͱ� ������ �� ����� �Է��Ѵ�
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}

			for (z = 0; z < n; z++) {		//���ŵ� ��� ���� �Է�
				fprintf(fb, "%s %d\n", u[z].name, u[z].score);
			}
			fclose(fb);

			//���� ���
			draw_rank(1);
			for (z = 0, e=7; z < n; z++, e+=3) {
				gotoxy(37, e);
				printf("%d: %s", z + 1, u[z].name);
				gotoxy(68, e);
				printf("��ū %d ��", u[z].score);
			}
			gotoxy(35, 31);
			color(8);
			printf("---�ƹ� Ű�� ������ ���� �޴��� ���ư��ϴ�.--- ");
			getch();
			color(15);

			//���þ� �귿
			if ((token > 300 && token < 400) || (token > 900 && token < 1000) || (token > 100000 && token < 200000) || (token > 100000000 && token < 200000000))
				Russian_roulette();
			//

			return 0;	//�Լ� ��~
		}
		else {
			if (i + 1 == n) break;
		}
		i++;
	}

	//��� �������� ���� �ʾ��� ���
	if (n < 5) {	//������ �ڸ��� ������ ���
		fb = fopen("list.txt", "a"); //������ �߰� ���� ����
		if (fb == NULL) {
			printf("FILE OPEN ERROR\n");
			exit(0);
		}
		fprintf(fb, "%s %d\n", name, token);	//������ ������ ��� �߰��ϱ�
		fclose(fb);

		//���� ���
		draw_rank(1);
		for (z = 0, e=7; z < n; z++, e+=3) {
			gotoxy(37, e);
			printf("%d: %s", z + 1, u[z].name);
			gotoxy(68, e);
			printf("��ū %d ��", u[z].score);
		}
		gotoxy(37, e);
		printf("%d: %s", z + 1, name);
		gotoxy(68, e);
		printf("��ū %d ��", token);

		gotoxy(35, 31);
		color(8);
		printf("---�ƹ� Ű�� ������ ���� �޴��� ���ư��ϴ�.--- ");
		getch();
		color(15);
	}
	else {			//������ 5����� �� ���ִ� ���
		draw_rank(0);
		for (z = 0, e=7; z < n; z++, e+=3) {
			gotoxy(37, e);
			printf("%d: %s", z + 1, u[z].name);
			gotoxy(68, e);
			printf("��ū %d ��", u[z].score);
		}
		gotoxy(35, 29);
		color(8);
		printf("---�ƹ� Ű�� ������ ���� �޴��� ���ư��ϴ�.--- ");
		getch();
		color(15);
	}
	if ((token > 300 && token < 400) || (token > 900 && token < 1000) || (token > 100000 && token < 200000) || (token > 100000000 && token < 200000000))
		Russian_roulette();
	return 0;
}


int end_rank() {
	struct user u[5];
	FILE *fb = NULL;
	int k = 0, i = 0, j = 0, z = 0, n, end, tmp;

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
			fb = fopen("list.txt", "w+"); //������ ���� ���, �����Ͱ� ������ �� ����� �Է��Ѵ�
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}
			for (z = 0; z < n ; z++) {		//���� �ִ� ����� ������ ����
				if (z != k) {
					fprintf(fb, "%s %d\n", u[z].name, u[z].score);
				}
			}
			fseek(fb, 0, 2);	//������ ���������� �̵�
			end = ftell(fb);
			rewind(fb);
			while (ftell(fb) != end) {
				fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
				i++;
			}
			n = i; //��ϵ� ����� ��(1~5)
			fclose(fb);
			break;
		}
		k++;
		if (k == n) break;
	}
	i = 0;
	while (1) {
		if (token >= u[i].score) {	//������ ������ ���� �ʴ� �̻� � �ͺ��� Ŭ ��
									//���� �����ڰ� ������ �ֽ� ����ڰ� �� ���� ������ ������
			if (n == 5) { //������ ����(5��) ����� ����
				j = 4;
			}
			else {
				j = n;	//��ϵ� ����� ������ 1�� �� ����ؾ� �ϹǷ� --n�� �ƴ� �׳� n
				n++;	//��ϵ� ��� ���� �߰���
			}
			while (j != i) {
				u[j].score = u[j - 1].score;
				strcpy(u[j].name, u[j - 1].name);
				j--;
			}
			u[i].score = token;
			strcpy(u[i].name, name);

			//���� ����
			fb = fopen("list.txt", "w"); //������ ���� ���, �����Ͱ� ������ �� ����� �Է��Ѵ�
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}

			for (z = 0; z < n; z++) {		//���ŵ� ��� ���� �Է�
				fprintf(fb, "%s %d\n", u[z].name, u[z].score);
			}
			fclose(fb);
			//
			return 0;	//�Լ� ��~
		}
		else {
			if (i + 1 == n) break;
		}
		i++;
	}

	//��� �������� ���� �ʾ��� ���
	if (n < 5) {	//������ �ڸ��� ������ ���
		fb = fopen("list.txt", "a"); //������ �߰� ���� ����
		if (fb == NULL) {
			printf("FILE OPEN ERROR\n");
			exit(0);
		}
		fprintf(fb, "%s %d\n", name, token);	//������ ������ ��� �߰��ϱ�
		fclose(fb);
	}
	return 0;
}

void draw_rank(int k) {
	color(3);
	gotoxy(53, 3);
	puts("�� ����ǥ ��");
	color(6);
	gotoxy(30, 5);
	printf("������������������������������������������������������������������������������������������������������������������ ");
	gotoxy(30, 6);
	printf("��                                                       �� ");
	gotoxy(30, 7);
	printf("��                                                       �� ");
	gotoxy(30, 8);
	printf("��                                                       �� ");
	gotoxy(30, 9);
	printf("��                                                       �� ");
	gotoxy(30, 10);
	printf("��                                                       �� ");
	gotoxy(30, 11);
	printf("��                                                       �� ");
	gotoxy(30, 12);
	printf("��                                                       �� ");
	gotoxy(30, 13);
	printf("��                                                       �� ");
	gotoxy(30, 14);
	printf("��                                                       �� ");
	gotoxy(30, 15);
	printf("��                                                       �� ");
	gotoxy(30, 16);
	printf("��                                                       �� ");
	gotoxy(30, 17);
	printf("��                                                       �� ");
	gotoxy(30, 18);
	printf("��                                                       �� ");
	gotoxy(30, 19);
	printf("��                                                       �� ");
	gotoxy(30, 20);
	printf("��                                                       �� ");
	gotoxy(30, 21);
	printf("������������������������������������������������������������������������������������������������������������������ ");
	
	if (k) {
		gotoxy(30, 25);
		puts("��");
		gotoxy(25, 24);
		puts("��");
		gotoxy(90, 24);
		puts("��");
		gotoxy(85, 26);
		puts("��");
		
		color(15);
		gotoxy(35, 23);
		puts("�� �� ��  �� ��        ��        �� ��  �� �� �� ");
		gotoxy(35, 24);
		puts(" ����������     ����������     ����������     ����������     ���������� ");
		gotoxy(35, 25);
		puts(" ��   ��     ��   ����   ��| |��   ����   ��     ��   �� ");
		gotoxy(35, 26);
		puts(" ��   ��     ��   ��     ��   ��     ��   ��     ��   �� ");
		gotoxy(35, 27);
		puts(" ����������     ����������     ����������     ����������     ���������� ");
		gotoxy(35, 28);
		puts(" ��  ��    ��  |      |  |      |  ��    ��  �� ");
	}
	else {
		color(15);
		gotoxy(35, 24);
		printf("�ƽ��Ե� ������ ���� ���߽��ϴ�.");
		gotoxy(73, 23);
		puts("����������������  ");
		gotoxy(71, 24);
		puts("�ܦ�      ��   ");
		gotoxy(73, 25);
		puts("���������������� ");
		gotoxy(73, 26);
		puts(" ��     ���� ");
	}
}