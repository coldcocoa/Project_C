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
//    // man1 ������ �ʱ�ȭ
//    strcpy_s(man1.name,20, "�ȼ���");
//    strcpy_s(man1.phoneNum,20, "010-1122-3344");
//    man1.age = 23;
//
//    // man2 ������ �Է¹ޱ�
//    printf("�̸� �Է�: ");
//    scanf_s("%s", 20,man2.name);
//
//    printf("��ȣ �Է�: ");
//    scanf_s("%s", 20,man2.phoneNum);
//
//    printf("���� �Է�: ");
//    scanf_s("%d", &(man2.age));
//
//    // man1 ���
//    printf("�̸�: %s\n", man1.name);
//    printf("��ȣ: %s\n", man1.phoneNum);
//    printf("����: %d\n", man1.age);
//
//    // man2 ���
//    printf("�̸�: %s\n", man2.name);
//    printf("��ȣ: %s\n", man2.phoneNum);
//    printf("����: %d\n", man2.age);
//
//    return 0;
//}
