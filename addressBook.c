#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 정의
typedef struct {
    int num;
    char name[20];
    char phone[20];
    int student_id;
    char birthday[20];
} Address;

// 전역 변수
Address addr_list[100];
int count = 0;

// 함수 선언
void print_menu();
void add_address();
void search_address();
void delete_address();

int main() {
    int menu_num;

    while (1) {
        print_menu();
        scanf("%d", &menu_num);

        switch (menu_num) {
            case 1:
                // 목록 보기
                printf("순번\t이름\t전화번호\t학번\t생일\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%s\t%s\t%d\t%s\n", addr_list[i].num, addr_list[i].name, addr_list[i].phone, addr_list[i].student_id, addr_list[i].birthday);
                }
                break;
            case 2:
                // 추가하기
                add_address();
                break;
            case 3:
                // 검색하기
                search_address();
                break;
            case 4:
                // 삭제하기
                delete_address();
                break;
            case 5:
                // 프로그램 종료
                printf("프로그램을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 입력입니다. 다시 입력해주세요.\n");
                break;
        }
    }

    return 0;
}

// 메뉴 출력 함수
void print_menu() {
    printf("\n===== 메뉴 =====\n");
    printf("1. 목록 보기\n");
    printf("2. 추가하기\n");
    printf("3. 검색하기\n");
    printf("4. 삭제하기\n");
    printf("5. 종료하기\n");
    printf("=================\n");
    printf("메뉴를 선택하세요: ");
}

// 추가하기 함수
void add_address() {
    Address new_addr;

    // 순번 자동으로 변환
    new_addr.num = count + 1;

    // 이름 입력 받기
    printf("이름을 입력하세요: ");
    scanf("%s", new_addr.name);

    // 전화번호 입력 받기
    printf("전화번호를 입력하세요: ");
    scanf("%s", new_addr.phone);

    // 학번 입력 받기
    printf("학번을 입력하세요: ");
    scanf("%d", &new_addr.student_id);

    // 생일 입력 받기
    printf("생일을 입력하세요(YYYY.MM.DD): ");
    scanf("%s", new_addr.birthday);

    // 주소록에 추가
    addr_list[count] = new_addr;
    count++;

    printf("주소록에 추가되었습니다.\n");
}

// 검색하기 함수
void search_address() {
    char name[20];
    int found = 0;

    // 검색할 이름 입력 받기
    printf("검색할 이름을 입력하세요: ");
    scanf("%s", name);

    // 이름이 일치하는 주소록 출력
    printf("순번\t이름\t전화번호\t학번\t생일\n");
    for (int i = 0; i < count; i++){
        if (strcmp(name, addr_list[i].name) == 0) {
            printf("%d\t%s\t%s\t%d\t%s\n", addr_list[i].num, addr_list[i].name, addr_list[i].phone, addr_list[i].student_id, addr_list[i].birthday);
            found = 1;
        }
    }

    // 검색 결과가 없을 경우
        if (!found) {
         printf("검색 결과가 없습니다.\n");
    }
}

// 삭제하기 함수
void delete_address() {
    int num;
    int found = 0;

    // 삭제할 순번 입력 받기
    printf("삭제할 순번을 입력하세요: ");
    scanf("%d", &num);

    // 순번이 일치하는 주소록 삭제
    for (int i = 0; i < count; i++) {
        if (num == addr_list[i].num) {
            // 삭제할 주소록의 다음 주소록부터 순번 1씩 감소
            for (int j = i + 1; j < count; j++) {
                addr_list[j].num--;
            }

            // 주소록에서 삭제
            for (int j = i; j < count - 1; j++) {
                addr_list[j] = addr_list[j + 1];
            }
            count--;
            printf("주소록에서 삭제되었습니다.\n");
            found = 1;
            break;
        }
    }

    // 검색 결과가 없을 경우
    if (!found) {
        printf("검색 결과가 없습니다.\n");
    }
}