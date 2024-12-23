#include <stdio.h>

typedef struct person {
    char name[20];
    char phoneNum[20];
    int age;
} Person;

void ShowPersonInfo(Person man) {
    printf("Name: %s\n", man.name);
    printf("Phone: %s\n", man.phoneNum);
    printf("Age: %d\n", man.age);
}

Person ReadPersonInfo(void) {
    Person man;
    printf("Name? ");
    scanf_s("%s", man.name);
    printf("Phone? ");
    scanf_s("%s", man.phoneNum);
    printf("Age? ");
    scanf_s("%d", &man.age);
    return man;
}

//int main(void) {
//    Person man = ReadPersonInfo();
//    ShowPersonInfo(man);
//    return 0;
//}
