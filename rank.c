#include "준비중.h"

int rank() {	//총 3가지 경우
				//기록으로 5등 안에 든 경우, 순위로는 꼴찌지만 순위가 다 차있지 않은 경우(랭킹등록)
				//순위에 못드는 경우(순위가 다 차있는 경우.등록안됨)
	struct user u[5];
	FILE *fb = NULL;
	int k = 0, i = 0, j = 0, z = 0, e = 0, n, end, tmp;

	system("cls");
	gotoxy(0, 2);
	printf("# 보유 토큰의 수 : %d", token);

	fb = fopen("list.txt", "r");
	if (fb == NULL) {
		printf("FILE OPEN ERROR\n");
		exit(0);
	}

	fseek(fb, 0, 2);	//파일의 마지막으로 이동
	end = ftell(fb);

	rewind(fb);

	while (ftell(fb) != end) {
		fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
		i++;
	}
	n = i; //등록된 사용자 수(1~5)
	i = 0;
	fclose(fb); //파일 일단 닫아줌

	//이미 랭킹 등록자 선별
	while (1) {
		if (!(strcmp(name, u[k].name))) {
			fb = fopen("list.txt", "w+"); //데이터 쓰기 모드, 데이터가 있으면 다 지우고 입력한다
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}
			for (z = 0; z < n ; z++) {		//원래 있는 기록은 지워서 갱신
				if (z != k) {
					fprintf(fb, "%s %d\n", u[z].name, u[z].score);
				}
			}

			/*
			for (z = 0; z < 5; z++) {			//배열 초기화
				strcpy(u[z].name, "\0");
				u[z].score = 0;
			}
			*/
			fseek(fb, 0, 2);	//파일의 마지막으로 이동
			end = ftell(fb);

			rewind(fb);
			i = 0;
			while (ftell(fb) != end) {
				fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
				i++;
			}
			n = i; //등록된 사용자 수(1~5)
			fclose(fb);
			break;
		}
		k++;
		if (k == n) break;
	}

	i = 0;
	while (1) {
		if (token >= u[i].score) {	//마지막 순위로 들어가지 않는 이상 어떤 것보단 클 것
									//만약 동점자가 있으면 최신 등록자가 더 높은 순위를 가져감
			if (n == 5) { //마지막 순위(5등) 기록은 삭제
				j = 4;
			}
			else {
				j = n;	//등록된 사용자 수보다 1개 더 등록해야 하므로 --n이 아닌 그냥 n
				n++;	//등록된 기록 개수 추가됨
			}
			while (j != i) {
				u[j].score = u[j - 1].score;
				strcpy(u[j].name, u[j - 1].name);
				j--;
			}
			u[i].score = token;
			strcpy(u[i].name, name);

			//파일 갱신
			fb = fopen("list.txt", "w"); //데이터 쓰기 모드, 데이터가 있으면 다 지우고 입력한다
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}

			for (z = 0; z < n; z++) {		//갱신된 기록 새로 입력
				fprintf(fb, "%s %d\n", u[z].name, u[z].score);
			}
			fclose(fb);

			//순위 출력
			draw_rank(1);
			for (z = 0, e=7; z < n; z++, e+=3) {
				gotoxy(37, e);
				printf("%d: %s", z + 1, u[z].name);
				gotoxy(68, e);
				printf("토큰 %d 개", u[z].score);
			}
			gotoxy(35, 31);
			color(8);
			printf("---아무 키를 누르면 메인 메뉴로 돌아갑니다.--- ");
			getch();
			color(15);

			//러시안 룰렛
			if ((token > 300 && token < 400) || (token > 900 && token < 1000) || (token > 100000 && token < 200000) || (token > 100000000 && token < 200000000))
				Russian_roulette();
			//

			return 0;	//함수 끝~
		}
		else {
			if (i + 1 == n) break;
		}
		i++;
	}

	//어느 순위보다 높지 않았을 경우
	if (n < 5) {	//순위에 자리가 남았을 경우
		fb = fopen("list.txt", "a"); //데이터 추가 모드로 열기
		if (fb == NULL) {
			printf("FILE OPEN ERROR\n");
			exit(0);
		}
		fprintf(fb, "%s %d\n", name, token);	//마지막 순위에 기록 추가하기
		fclose(fb);

		//순위 출력
		draw_rank(1);
		for (z = 0, e=7; z < n; z++, e+=3) {
			gotoxy(37, e);
			printf("%d: %s", z + 1, u[z].name);
			gotoxy(68, e);
			printf("토큰 %d 개", u[z].score);
		}
		gotoxy(37, e);
		printf("%d: %s", z + 1, name);
		gotoxy(68, e);
		printf("토큰 %d 개", token);

		gotoxy(35, 31);
		color(8);
		printf("---아무 키를 누르면 메인 메뉴로 돌아갑니다.--- ");
		getch();
		color(15);
	}
	else {			//순위가 5등까지 꽉 차있는 경우
		draw_rank(0);
		for (z = 0, e=7; z < n; z++, e+=3) {
			gotoxy(37, e);
			printf("%d: %s", z + 1, u[z].name);
			gotoxy(68, e);
			printf("토큰 %d 개", u[z].score);
		}
		gotoxy(35, 29);
		color(8);
		printf("---아무 키를 누르면 메인 메뉴로 돌아갑니다.--- ");
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

	fseek(fb, 0, 2);	//파일의 마지막으로 이동
	end = ftell(fb);
	rewind(fb);
	while (ftell(fb) != end) {
		fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
		i++;
	}
	n = i; //등록된 사용자 수(1~5)
	i = 0;
	fclose(fb); //파일 일단 닫아줌

	while (1) {
		if (!(strcmp(name, u[k].name))) {
			fb = fopen("list.txt", "w+"); //데이터 쓰기 모드, 데이터가 있으면 다 지우고 입력한다
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}
			for (z = 0; z < n ; z++) {		//원래 있는 기록은 지워서 갱신
				if (z != k) {
					fprintf(fb, "%s %d\n", u[z].name, u[z].score);
				}
			}
			fseek(fb, 0, 2);	//파일의 마지막으로 이동
			end = ftell(fb);
			rewind(fb);
			while (ftell(fb) != end) {
				fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
				i++;
			}
			n = i; //등록된 사용자 수(1~5)
			fclose(fb);
			break;
		}
		k++;
		if (k == n) break;
	}
	i = 0;
	while (1) {
		if (token >= u[i].score) {	//마지막 순위로 들어가지 않는 이상 어떤 것보단 클 것
									//만약 동점자가 있으면 최신 등록자가 더 높은 순위를 가져감
			if (n == 5) { //마지막 순위(5등) 기록은 삭제
				j = 4;
			}
			else {
				j = n;	//등록된 사용자 수보다 1개 더 등록해야 하므로 --n이 아닌 그냥 n
				n++;	//등록된 기록 개수 추가됨
			}
			while (j != i) {
				u[j].score = u[j - 1].score;
				strcpy(u[j].name, u[j - 1].name);
				j--;
			}
			u[i].score = token;
			strcpy(u[i].name, name);

			//파일 갱신
			fb = fopen("list.txt", "w"); //데이터 쓰기 모드, 데이터가 있으면 다 지우고 입력한다
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}

			for (z = 0; z < n; z++) {		//갱신된 기록 새로 입력
				fprintf(fb, "%s %d\n", u[z].name, u[z].score);
			}
			fclose(fb);
			//
			return 0;	//함수 끝~
		}
		else {
			if (i + 1 == n) break;
		}
		i++;
	}

	//어느 순위보다 높지 않았을 경우
	if (n < 5) {	//순위에 자리가 남았을 경우
		fb = fopen("list.txt", "a"); //데이터 추가 모드로 열기
		if (fb == NULL) {
			printf("FILE OPEN ERROR\n");
			exit(0);
		}
		fprintf(fb, "%s %d\n", name, token);	//마지막 순위에 기록 추가하기
		fclose(fb);
	}
	return 0;
}

void draw_rank(int k) {
	color(3);
	gotoxy(53, 3);
	puts("▶ 순위표 ◀");
	color(6);
	gotoxy(30, 5);
	printf("┌───────────────────────────────────────────────────────┐ ");
	gotoxy(30, 6);
	printf("│                                                       │ ");
	gotoxy(30, 7);
	printf("│                                                       │ ");
	gotoxy(30, 8);
	printf("│                                                       │ ");
	gotoxy(30, 9);
	printf("│                                                       │ ");
	gotoxy(30, 10);
	printf("│                                                       │ ");
	gotoxy(30, 11);
	printf("│                                                       │ ");
	gotoxy(30, 12);
	printf("│                                                       │ ");
	gotoxy(30, 13);
	printf("│                                                       │ ");
	gotoxy(30, 14);
	printf("│                                                       │ ");
	gotoxy(30, 15);
	printf("│                                                       │ ");
	gotoxy(30, 16);
	printf("│                                                       │ ");
	gotoxy(30, 17);
	printf("│                                                       │ ");
	gotoxy(30, 18);
	printf("│                                                       │ ");
	gotoxy(30, 19);
	printf("│                                                       │ ");
	gotoxy(30, 20);
	printf("│                                                       │ ");
	gotoxy(30, 21);
	printf("└───────────────────────────────────────────────────────┘ ");
	
	if (k) {
		gotoxy(30, 25);
		puts("♬");
		gotoxy(25, 24);
		puts("♬");
		gotoxy(90, 24);
		puts("♬");
		gotoxy(85, 26);
		puts("♬");
		
		color(15);
		gotoxy(35, 23);
		puts("＼ ● ／  ＼ ●        ●        ● ／  ＼ ● ／ ");
		gotoxy(35, 24);
		puts(" ┌───┐     ┌───┐     ┌───┐     ┌───┐     ┌───┐ ");
		gotoxy(35, 25);
		puts(" │   │     │   │＼   │| |│   ／│   │     │   │ ");
		gotoxy(35, 26);
		puts(" │   │     │   │     │   │     │   │     │   │ ");
		gotoxy(35, 27);
		puts(" └───┘     └───┘     └───┘     └───┘     └───┘ ");
		gotoxy(35, 28);
		puts(" ／  ＼    ／  |      |  |      |  ＼    ／  ＼ ");
	}
	else {
		color(15);
		gotoxy(35, 24);
		printf("아쉽게도 순위에 들지 못했습니다.");
		gotoxy(73, 23);
		puts("┌──────┐  ");
		gotoxy(71, 24);
		puts("●│      │   ");
		gotoxy(73, 25);
		puts("└──────┘ ");
		gotoxy(73, 26);
		puts(" │     └─ ");
	}
}