//
// Created by suxin on 18-4-20.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/numbers.h"
#include "../../include/boolean.h"
#include "../../include/profile_active.h"

/**
 * 生成随机数
 *
 * @return 随机数值
 */
int get_rand_num() {
    //新增,srand
    srand((unsigned) time(NULL));

    return rand() % 100;
}

/**
 * 猜数字
 *
 * @return 是否正确
 */
BOOL guess_num() {

    int cows = get_rand_num();
#if PROFILE_ACTIVE == 'T'
    printf("临时数字是 %d\n", cows);
#endif
    int guess_num = 1;

    while (guess_num <= MAX_ALLOW_GUESS_NUM) {

        printf("请输入您猜的数字(范围在[1, 100]): ");
        int bulls;
        scanf("%d", &bulls);

        if (bulls < MIN_NUM) {
            printf("您输入的数字 %d 必须大于 %d\n", bulls, MIN_NUM);
            guess_num++;
            continue;
        }

        if (bulls > MAX_NUM) {
            printf("您输入的数字 %d 必须小于等于 %d\n", bulls, MAX_NUM);
            guess_num++;
            continue;
        }

        if (bulls == cows) {
            printf("恭喜, 您使用%d次猜出了答案, 程序已退出!", guess_num);
            return TRUE;
        } else if (bulls > cows) {
            printf("您猜的数比预期数要大, 您还有 %d 次机会\n", MAX_ALLOW_GUESS_NUM - guess_num);
            guess_num++;
        } else if (bulls < cows) {
            printf("您猜的数比预期数要小, 您还有 %d 次机会\n", MAX_ALLOW_GUESS_NUM - guess_num);
            guess_num++;
        } else {
            printf("系统发生错误, 已退出!");
            return FALSE;
        }
    }

    return TRUE;
}



