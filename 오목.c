#include <stdio.h>
#define BSIZE 10 //Board Size

// 아래는 그림을 그릴 때 쓰는 문자(열)이다.
#define PIC_SQUARE "□"   
#define PIC_ROUND "●"
#define PIC_EMPTY "┼"

// 아래는 배열에 저장하는 값이다.
#define SQUARE 1    // 오타 수정 2021.5.21.
#define ROUND  -1
#define EMPTY 0

void draw(int data[BSIZE][BSIZE]){
    printf(" ");
    for(int i = 0; i < BSIZE; i++){
        printf("%2d", i);
    }
    printf("\n");
	for(int row = 0; row < BSIZE; row++){
        printf("%2d", row);
		for(int col = 0; col < BSIZE; col++){
			if(data[row][col] == SQUARE){
				printf("%s", PIC_SQUARE);
			} else if(data[row][col] == ROUND){
				printf("%s", PIC_ROUND);
			} else {
				printf("%s", PIC_EMPTY);
			}
		}
		printf("\n");
	}
}

//입력 받은 값이 바둑판 안의 값인지
int isValid(int data[BSIZE][BSIZE], int r, int c){
    if(r >= 0 && r < BSIZE && c >= 0 && c < BSIZE && data[r][c] == 0){
        return 1;
    } else {
        return 0;
    }
}

//입력 받은 값이 돌을 놓을 수 있는 자리인지 판별 후, 아니면 재입력 받는 함수
int getPosition(int data[BSIZE][BSIZE], int pos[2]){
	// valid position 나올 때까지 반복 입력한다.
	// EOF가 되면 0 을 반환, 성공하면 1을 반환한다.
	 while(1){
        if(scanf("%d %d", &pos[0], &pos[1]) == 2){
            int row = pos[0];
            int col = pos[1];
            if(isValid(data, row, col)){
                return 1;
                break;
            } else {
                printf("돌을 놓을 수 없는 위치입니다.\n");
                printf("다른 위치를 입력해주세요.\n");
                continue;
                return 0;
            }
        } else {
            return 0;
        }
    }
}

//좌우 방향 돌 개수 세기
int count_h(int data[BSIZE][BSIZE], int row, int col){
	int count=1;
	char stone = data[row][col]; //돌 종류
	
	//왼쪽 수평 방향으기로 확인
	for(int c = col - 1 ; c >= 0; c--){
		if(data[row][c] == stone){
			count++;
		} else {
			break;
		}
	}

	//오른쪽 수평 방향으로 확인
	for(int c = col + 1; c < BSIZE; c++){
		if(data[row][c] == stone){
			count++;
		} else {
			break;
		}
	}
	return count;
}

//상하 방향 승패 판정
int count_v(int data[BSIZE][BSIZE], int row, int col){
	int count = 1;
	char stone = data[row][col]; //돌 종류
	
	//위쪽 수직 방향으로 확인
	for(int r = row - 1 ; r >= 0; r--){
		if(data[r][col] == stone){
			count++;
		} else {
			break;
		}
	}

	//아래쪽 수직 방향으로 확인
	for(int r = row + 1; r < BSIZE; r++){
		if(data[r][col] == stone){
			count++;
		} else {
			break;
		}
	}
	return count;
}

//우 상향, 좌 하향 대각선 방향 승패 판정
int count_d1(int data[BSIZE][BSIZE], int row, int col){
	int count = 1;
	char stone = data[row][col]; //돌 종류

	//우 상향 대각선 방향으로 확인
	for(int r = row - 1, c = col + 1; r >= 0 && c < BSIZE; r--, c++){
		if(data[r][c] == stone){
			count++;
		} else {
		    break;
		}
	}
	
	//좌 하향 대각선 방향으로 확인
    for(int r = row + 1, c = col - 1; r < BSIZE && c >= 0; r++, c--){
		if(data[r][c] == stone){
			count++;
		} else {
		    break;
		}
	}
	return count;
}

//우 하향, 좌 상향 대각선 방향 승패 판정
int count_d2(int data[BSIZE][BSIZE], int row, int col){
	int count = 1;
	char stone = data[row][col]; //돌 종류
	
	//우 하향 대각선 방향으로 확인
	for(int r = row + 1, c= col + 1; r < BSIZE && c < BSIZE; r++, c++){
		if(data[r][c] == stone){
			count++;
		} else {
		    break;
		}
	}
	//좌 상향 대각선 방향으로 확인
    for(int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--){
		if(data[r][c] == stone){
			count++;
		} else {
		    break;
		}
	}
	return count;
}

int win(int data[BSIZE][BSIZE], int row, int col){
	if (count_h(data, row, col) == 5 || count_v(data, row, col) == 5 
				|| count_d1(data, row, col) == 5 || count_d2(data, row, col) == 5) {  // 6목은 안 쳐준다.
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int board[BSIZE][BSIZE] = { };  // 전부 0으로 초기화.
	int turn = SQUARE;
	int pos[2]; // 0번은 행번호, 1번은 열번호

	// 먼저 빈 판을 그려준다.
	draw(board);
	while (getPosition(board, pos)){
		board[pos[0]][pos[1]] = turn;
		draw(board);  // 돌이 놓일 때마다 판을 다시 그린다.
		if (win(board, pos[0], pos[1])){
			if (turn == SQUARE){
				printf("네모(%s)가 이겼습니다.\n", PIC_SQUARE);
			} else {
				printf("동그라미(%s)가 이겼습니다.\n", PIC_ROUND);
			}
			return 0;
		}
		turn = -turn;  // 1과 -1 을 교대로
	}
	printf("게임을 종료합니다.\n");
	return 0;
}

