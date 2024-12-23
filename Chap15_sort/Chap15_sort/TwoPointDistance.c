#include <stdio.h>
#include <math.h>

struct point {
    int xpos;
    int ypos;
};

//int main(void)
//{
//    struct point pos1, pos2;
//    double distance;
//
//    fputs("Point1 pos: ", stdout);
//    scanf_s("%d %d", &pos1.xpos, &pos1.ypos);
//
//    fputs("Point2 pos: ", stdout);
//    scanf_s("%d %d", &pos2.xpos, &pos2.ypos);
//
//    /* 두 점 간의 거리 계산 */
//    distance = sqrt((double)((pos1.xpos - pos2.xpos) * (pos1.xpos - pos2.xpos) +
//        (pos1.ypos - pos2.ypos) * (pos1.ypos - pos2.ypos)));
//
//    printf("두 점의 거리는 %g 입니다.\n", distance);
//
//    return 0;
//}
