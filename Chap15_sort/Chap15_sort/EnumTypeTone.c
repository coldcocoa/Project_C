#include <stdio.h>

typedef enum syllable {
    DO = 1, Re = 2, Mi = 3, Fa = 4, So = 5, La = 6, Ti = 7
} Syllable;

void Sound(Syllable sy) {
    switch (sy) {
    case DO:
        puts("���� �Ͼ� ������");
        return;
    case Re:
        puts("���� �ձ� ���ڵ�");
        return;
    case Mi:
        puts("�̴� �Ķ� �̳���");
        return;
    case Fa:
        puts("�Ĵ� ���� �Ķ���");
        return;
    case So:
        puts("���� ���� �ֹ��");
        return;
    case La:
        puts("��� ��������~");
        return;
    case Ti:
        puts("�ô� ���� �ó���");
        return;
    }
    puts("�� �Բ� �θ���~ �������� �ֶ�õ� �� ��~ ��~");
}

//int main(void) {
//    Syllable tone;
//    for (tone = DO; tone <= Ti; tone++) {
//        Sound(tone);
//    }
//    return 0;
//}