#include <stdio.h>
int main(){
    int mile; //여행 거리
    int point; //마일리지 포인트
    int point_use; //마일리지로 차감 가능한 거리
    int point_remain; //사용 후 남은 마일리지
    int credit_result; //신용카드 사용 실적
    int credit_use; //신용카드 실적으로 차감 가능한 거리
    int credit_remain; // 사용 후 남은 신용카드 실적
    int price; //항공권 가격

    
    printf("이번에 구입할 항공권의 비행거리, 이전 여행 실적(마일리지), 제휴 신용카드 사용 실적(원 단위)를 입력해주세요.\n");
    scanf("%d %d %d", &mile, &point, &credit_result);
    
    //10000 포인트 이상인 경우, 10%만큼 차감 가능
    if(point >= 10000){
        point_use = point * 0.1;
        if(point_use > mile){
            point_use = mile;
        }
        mile -= point_use;   
        point_remain = point - (point_use * 10);
    } else {
        point_use = 0;
        point_remain = point;
    }
    
    //신용카드 할인
    if(mile > 0){
            if(credit_result > 300000){
                if(credit_result <= 700000){
                    credit_use = (credit_result - 300000) * 0.0001;
                    if(credit_use > mile){
                        credit_use = mile;
                    }
                    credit_remain = credit_result - (credit_use * 10000);
                    mile -= credit_use;
                } else {
                    credit_use = (credit_result - 300000) * 0.0002;
                    if(credit_use > mile){
                        credit_use = mile;
                    }
                    credit_remain = credit_result - (credit_use * 0.5 * 10000);
                    mile -= credit_use;
                }
            } else {
                credit_use = 0;
                credit_remain = credit_result;
            }
    } else {
        credit_use = 0;
        credit_remain = credit_result;
    }

    //가격 계산
    if(mile <= 1000){
        price = 50000 + (mile * 200);
    } else if(mile <= 2000){
        price = 50000 + (1000 * 200) + (mile - 1000) * 180;
    } else {
        price = 50000 + (1000 * 200) + (1000 * 180) + (mile - 2000) * 150;
    }

    //부가세 계산
    price *= 1.1;

    //마일리지 재산정
    point_remain += mile;

    printf("1. 포인트로 차감된 마일 수 : %d\n", point_use);
    printf("2. 신용카드로 차감된 마일 수 : %d\n", credit_use);
    printf("3. 돈을 지불해야하는 총 거리(마일) : %d\n", mile);
    printf("4. 항공권 가격 (세금 포함) : %d원\n", price);
    printf("5. 잔여 마일리지 실적 : %d\n", point_remain);
    printf("6. 잔여 전월 신용카드 실적 : %d원\n", credit_remain);



    return 0;
}


