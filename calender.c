#include <stdio.h>
int leap_year(int y){ //윤년 판별 함수
	int year_day = 365;//1년의 일수
	if((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0))){
		year_day = 366;
		return year_day;
	} 
	return year_day;
}

int cal_month_day(int y, int m){ //특정 연 월이 며칠까지 인지 판별하는 함수
	int month_day = 0;
	switch(m){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			month_day = 31;
			break;
		case 2:
			month_day = 28;
			break;
		default:
			month_day = 30;
			break;
	} 
	if(m == 2){
		if((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0))){
			month_day = 29;
		} else {
			month_day = 28;
		}
	}
	return month_day;
}

int cal_total_day(int year, int month){ //전체 날 수를 알아내는 함수
	int total_day = 0;
	int year_day = 0;
	int month_day = 0;
	for(int y = 1970; y < year; y++){
		year_day = leap_year(y);
		total_day += year_day;
	}
	for(int m = 1; m < month; m++){
		month_day = cal_month_day(year, m);
		total_day += month_day;
	}
	return total_day;
}

void make_calender(int year, int month){
	int start_day= 0; //시작 요일
	int total_day = cal_total_day(year, month);
	int this_month_day = cal_month_day(year, month);
	start_day = (total_day + 4) % 7;

	printf(" 일 월 화 수 목 금 토 \n");
	for(int i = 0; i < start_day; i++){
		printf(" * ");
	}
	for(int j  = 1; j  <= this_month_day; j++){
		if((j + start_day - 1) % 7 == 0){
			printf("\n");
		}
		printf("%3d", j);
	}
	int last_day = (start_day + this_month_day) % 7; //마지막 날이 일주일 중 며칠 째에서 끝나는지 
	if(last_day != 0){
		for(int k = 1; k <= 7 - last_day; k++){ 
			printf(" * ");
		}
	}
}	

int main(){
	int year; //입력받을 연
	int month; //입력받을 달

	printf("연과 월을 입력해주세요.\n");
	scanf("%d %d", &year, &month);

	//int year_day = leap_year(year);
	//printf("%d\n", year_day);

	//int month_day = cal_month_day(year, month);
	//printf("%d\n", month_day);
	
	//int total_day = cal_total_day(year, month);
	//printf("%d\n", total_day);
	
	//int start_day = make_calender(year, month);
	//printf("%d\n", start_day);
	
	make_calender(year, month);
	
	return 0;
}
