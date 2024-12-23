#include <stdio.h>

//int main(void)
//{
//    int ch, i;
//    FILE* fp = fopen("C:\\Users\\user\\Documents\\Downloads\\data.txt", "rt");
//
//    if (fp == NULL) {
//        puts("파일 오픈 실패!");
//        return -1;
//    }
//
//    for (i = 0; i < 3; i++) {
//        ch = fgetc(fp); // 파일에서 문자 읽기
//        if (ch == EOF) {
//            puts("파일의 끝에 도달했습니다.");
//            break;
//        }
//        printf("%c\n", ch); // 읽은 문자 출력
//    }
//
//    fclose(fp);
//    return 0;
//}
