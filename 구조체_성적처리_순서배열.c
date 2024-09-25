#include <stdio.h>
#define MAX_SUBJ 10
#define MAX_NAME_LEN 15
#define MAX_STU 100
struct student{
	char name[MAX_NAME_LEN+1];
	int scores[MAX_SUBJ];
	float average;
}  ;

void get_data(struct student st[], int nStu, int nSubj){
	for(int i = 0; i < nStu; i++){
		scanf("%s", st[i].name); 
		for(int j = 0; j < nSubj; j++){
			scanf("%d", &st[i].scores[j]);
		}
	}
}

void calc_average(struct student  st[], int nStu, int nSubj){
	int i, j;
	for(i = 0; i < nStu; i++){
		float sum = 0;
		for(j = 0; j < nSubj; j++){
			sum += st[i].scores[j];
		}
		st[i].average = sum / nSubj;
	}
}

void print_data(struct student st[], int nStu, int nSubj){
	printf("=========================\n");
	for(int i = 0; i < nStu; i++){
		printf("%s  ", st[i].name);
		for(int j = 0; j < nSubj; j++){
			printf("%d  ", st[i].scores[j]);
		}
		printf("%.2f\n", st[i].average);
		printf("\n");
	}
}

// void bubble_up(struct student  st[], int top, int bottom){
// 	// bubble_up 함수는 index가 top 부터 bottom까지의 구조체 중에서
// 	// 가장 average가 큰 것이 위로 가도록 밑에서부터
// 	// 두개씩 비교해서 올리는 함수로 만든다.
// 	for(int i = bottom; i > top; i--){
// 		if(st[i].average > st[i-1].average){
// 			struct student temp = st[i];
// 			st[i] = st[i-1];
// 			st[i-1] = temp;
// 		}
// 	}
//}

void sort_student(struct student st[], int nStu, int order[]){
	for(int i = 0; i < nStu; i++){
		order[i] = i;
	}
	for(int i = 0; i < nStu-1; i++){
		for(int j = 0; j < nStu-1-i; j++){
			if(st[order[j]].average < st[order[j+1]].average){
				int temp = order[j];
				order[j] = order[j+1];
				order[j+1] = temp;
			}
		}
	}
}

int main(){
	struct student  st[MAX_STU] ={};// 0으로 초기화
	int order[MAX_STU]; //순서를 나타내는 배열

	int nStu, nSubj;
	printf("학생수와 과목 수 입력:\n");
	scanf("%d %d", &nStu, &nSubj);


	// 성적을 입력한다. 
	get_data(st, nStu, nSubj);
	
	// 입력된 데이터를 확인하자. 평균 값은 당연히 틀릴 것이다.
    // print_data(st, nStu, nSubj);

	// 평균을 계산하여 저장하자.
	calc_average(st, nStu, nSubj);
	
	// 정렬한다.
	sort_student(st, nStu, order);

	// 정렬된 데이터를 출력.(순서배열)
	printf("=========================\n");
	for(int i = 0; i < nStu; i++){
		printf("%s  ", st[order[i]].name);
		for(int j = 0; j < nSubj; j++){
			printf("%d  ", st[order[i]].scores[j]);
		}
		printf("%.2f\n", st[order[i]].average);
		printf("\n");
	}
	
	
	print_data(st, nStu, nSubj);

	return 0;
}

