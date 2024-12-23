#include <stdio.h>
#include <string.h>

struct person {
    char name[20];
    char phoneNum[20];
    int age;
};

//int main(void)
//{
//    struct person man1, man2;
//
//    // man1 데이터 초기화
//    strcpy_s(man1.name,20, "안성준");
//    strcpy_s(man1.phoneNum,20, "010-1122-3344");
//    man1.age = 23;
//
//    // man2 데이터 입력받기
//    printf("이름 입력: ");
//    scanf_s("%s", 20,man2.name);
//
//    printf("번호 입력: ");
//    scanf_s("%s", 20,man2.phoneNum);
//
//    printf("나이 입력: ");
//    scanf_s("%d", &(man2.age));
//
//    // man1 출력
//    printf("이름: %s\n", man1.name);
//    printf("번호: %s\n", man1.phoneNum);
//    printf("나이: %d\n", man1.age);
//
//    // man2 출력
//    printf("이름: %s\n", man2.name);
//    printf("번호: %s\n", man2.phoneNum);
//    printf("나이: %d\n", man2.age);
//
//    return 0;
//}
