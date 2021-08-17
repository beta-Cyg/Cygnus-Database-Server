#include<stdio.h>

/*各函数声明*/
void shizhuaner(int in, int n, int *md5);

void shizhuaner_weishu(int in, int *md5);

void shiliuzhuaner(char *t, int *temp);

void c_out(int *a);

void abcd_out(int *a);

void F(int *b, int *c, int *d, int *temp1, int *temp2);

void G(int *b, int *c, int *d, int *temp1, int *temp2);

void H(int *b, int *c, int *d, int *temp);

void I(int *b, int *c, int *d, int *temp);

void yu(int *a, int *b, int *temp);

void huo(int *a, int *b, int *temp);

void fei(int *a, int *temp);

void yihuo(int *a, int *b, int *temp);

void jia(int *a, int *b, int *temp);

/*十进制转二进制函数*/
void shizhuaner(int in, int n, int *md5) {
    int j, s, w;
    s = n / 4 + 1;  //s是md5里面组的排位数，w是该组里面的位数
    w = n % 4;
    j = 1;
    do {
        md5[32 * s - 8 * w - j] = in % 2;
        in = in / 2;
        j++;
    } while (in != 0);
    while (j <= 8)  //二进制不够八位时补零
    {
        md5[32 * s - 8 * w - j] = 0;
        j++;
    }
}

/* 位数填充时所用到的十进制转二进制函数 */
void shizhuaner_weishu(int in, int *md5) {
    int i, j, temp, a[64];
    for (i = 0; in != 0; i++) {
        a[i] = in % 2;
        in = in / 2;
    }
    while (i % 8 != 0)  //二进制位数不够八的整数倍时补零
    {
        a[i] = 0;
        i++;
    }
    for (j = 0; j < i / 2; j++) {
        temp = a[i - j - 1];
        a[i - j - 1] = a[j];
        a[j] = temp;

    }
    temp = i / 8;
    for (i = i - 1; i < 64; i++)
        a[i] = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++)
            md5[512 - temp * 8 + j - 32] = a[i * 8 + j];
        temp = temp - 1;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++)
            md5[512 - (i + 1) * 8 + j] = a[i * 8 + j + 32];
    }
}

/* 十六进制转二进制函数 */
void shiliuzhuaner(char *t, int *temp) {
    int i;
    for (i = 0; i < 8; i++) {
        switch (t[i]) {
            case '0': {
                temp[4 * i] = 0;
                temp[4 * i + 1] = 0;
                temp[4 * i + 2] = 0;
                temp[4 * i + 3] = 0;
            }
                break;
            case '1': {
                temp[4 * i] = 0;
                temp[4 * i + 1] = 0;
                temp[4 * i + 2] = 0;
                temp[4 * i + 3] = 1;
            }
                break;
            case '2': {
                temp[4 * i] = 0;
                temp[4 * i + 1] = 0;
                temp[4 * i + 2] = 1;
                temp[4 * i + 3] = 0;
            }
                break;
            case '3': {
                temp[4 * i] = 0;
                temp[4 * i + 1] = 0;
                temp[4 * i + 2] = 1;
                temp[4 * i + 3] = 1;
            }
                break;
            case '4': {
                temp[4 * i] = 0;
                temp[4 * i + 1] = 1;
                temp[4 * i + 2] = 0;
                temp[4 * i + 3] = 0;
            }
                break;
            case '5': {
                temp[4 * i] = 0;
                temp[4 * i + 1] = 1;
                temp[4 * i + 2] = 0;
                temp[4 * i + 3] = 1;
            }
                break;
            case '6': {
                temp[4 * i] = 0;
                temp[4 * i + 1] = 1;
                temp[4 * i + 2] = 1;
                temp[4 * i + 3] = 0;
            }
                break;
            case '7': {
                temp[4 * i] = 0;
                temp[4 * i + 1] = 1;
                temp[4 * i + 2] = 1;
                temp[4 * i + 3] = 1;
            }
                break;
            case '8': {
                temp[4 * i] = 1;
                temp[4 * i + 1] = 0;
                temp[4 * i + 2] = 0;
                temp[4 * i + 3] = 0;
            }
                break;
            case '9': {
                temp[4 * i] = 1;
                temp[4 * i + 1] = 0;
                temp[4 * i + 2] = 0;
                temp[4 * i + 3] = 1;
            }
                break;
            case 'a': {
                temp[4 * i] = 1;
                temp[4 * i + 1] = 0;
                temp[4 * i + 2] = 1;
                temp[4 * i + 3] = 0;
            }
                break;
            case 'b': {
                temp[4 * i] = 1;
                temp[4 * i + 1] = 0;
                temp[4 * i + 2] = 1;
                temp[4 * i + 3] = 1;
            }
                break;
            case 'c': {
                temp[4 * i] = 1;
                temp[4 * i + 1] = 1;
                temp[4 * i + 2] = 0;
                temp[4 * i + 3] = 0;
            }
                break;
            case 'd': {
                temp[4 * i] = 1;
                temp[4 * i + 1] = 1;
                temp[4 * i + 2] = 0;
                temp[4 * i + 3] = 1;
            }
                break;
            case 'e': {
                temp[4 * i] = 1;
                temp[4 * i + 1] = 1;
                temp[4 * i + 2] = 1;
                temp[4 * i + 3] = 0;
            }
                break;
            case 'f': {
                temp[4 * i] = 1;
                temp[4 * i + 1] = 1;
                temp[4 * i + 2] = 1;
                temp[4 * i + 3] = 1;
            }
                break;
        }
    }
}

/* 密文输出函数 */
void c_out(int *a) {
    int i, add;
    for (i = 1; i <= 4; i++)  //二进制转换成十六进制输出
    {
        add = a[32 - i * 8] * 8 + a[32 - i * 8 + 1] * 4 + a[32 - i * 8 + 2] * 2 + a[32 - i * 8 + 3];
        if (add >= 10) {
            switch (add) {
                case 10:
                    printf("a");
                    break;
                case 11:
                    printf("b");
                    break;
                case 12:
                    printf("c");
                    break;
                case 13:
                    printf("d");
                    break;
                case 14:
                    printf("e");
                    break;
                case 15:
                    printf("f");
                    break;
            }
        } else
            printf("%d", add);
        add = a[32 - i * 8 + 4] * 8 + a[32 - i * 8 + 5] * 4 + a[32 - i * 8 + 6] * 2 + a[32 - i * 8 + 7];
        if (add >= 10) {
            switch (add) {
                case 10:
                    printf("a");
                    break;
                case 11:
                    printf("b");
                    break;
                case 12:
                    printf("c");
                    break;
                case 13:
                    printf("d");
                    break;
                case 14:
                    printf("e");
                    break;
                case 15:
                    printf("f");
                    break;
            }
        } else
            printf("%d", add);
    }
}

/* 中间过程的输出函数 */
void abcd_out(int *a) {
    int i, add;
    for (i = 0; i < 4; i++)  //二进制转换成十六进制输出
    {
        add = a[i * 8] * 8 + a[i * 8 + 1] * 4 + a[i * 8 + 2] * 2 + a[i * 8 + 3];
        if (add >= 10) {
            switch (add) {
                case 10:
                    printf("a");
                    break;
                case 11:
                    printf("b");
                    break;
                case 12:
                    printf("c");
                    break;
                case 13:
                    printf("d");
                    break;
                case 14:
                    printf("e");
                    break;
                case 15:
                    printf("f");
                    break;
            }
        } else
            printf("%d", add);
        add = a[i * 8 + 4] * 8 + a[i * 8 + 5] * 4 + a[i * 8 + 6] * 2 + a[i * 8 + 7];
        if (add >= 10) {
            switch (add) {
                case 10:
                    printf("a");
                    break;
                case 11:
                    printf("b");
                    break;
                case 12:
                    printf("c");
                    break;
                case 13:
                    printf("d");
                    break;
                case 14:
                    printf("e");
                    break;
                case 15:
                    printf("f");
                    break;
            }
        } else
            printf("%d", add);
    }
}

/* 与函数 */
void yu(int *a, int *b, int *temp) {
    int i;
    for (i = 0; i < 32; i++)  //同为1为1，否则为0
    {
        if (a[i] == 1 && b[i] == 1)
            temp[i] = 1;
        else
            temp[i] = 0;
    }
}

/* 或函数 */
void huo(int *a, int *b, int *temp) {
    int i;
    for (i = 0; i < 32; i++)  //同0为0，否则为1
    {
        if (a[i] == 0 && b[i] == 0)
            temp[i] = 0;
        else
            temp[i] = 1;
    }
}

/* 非函数 */
void fei(int *a, int *temp) {
    int i;
    for (i = 0; i < 32; i++) {
        if (a[i] == 0)
            temp[i] = 1;
        else
            temp[i] = 0;
    }
}

/*异或函数*/
void yihuo(int *a, int *b, int *temp) {
    int i;
    for (i = 0; i < 32; i++)  //相同为0，不同为1
    {
        if (a[i] != b[i])
            temp[i] = 1;
        else
            temp[i] = 0;
    }
}

/* 模二的32次加 */
void jia(int *a, int *b, int *temp) {
    int i, jin;
    jin = 0;
    for (i = 0; i < 32; i++) {
        if (a[31 - i] + b[31 - i] + jin > 1) {
            temp[31 - i] = a[31 - i] + b[31 - i] + jin - 2;
            jin = 1;
        } else {
            temp[31 - i] = a[31 - i] + b[31 - i] + jin;
            jin = 0;
        }
    }
}

/* F函数 */
void F(int *b, int *c, int *d, int *temp1, int *temp2) {
    /* F(x,y,z)=(x∧y)∨(¬x∧z) */
    yu(b, c, temp1);
    fei(b, temp2);
    yu(temp2, d, temp2);
    huo(temp1, temp2, temp2);
}

/* G函数 */
void G(int *b, int *c, int *d, int *temp1, int *temp2) {
    /* G(x,y,z)=(x∧z)∨(y∧¬z) */
    yu(b, d, temp1);
    fei(d, temp2);
    yu(temp2, c, temp2);
    huo(temp1, temp2, temp2);
}

/* H函数 */
void H(int *b, int *c, int *d, int *temp) {
    /* H(x,y,z)=x⊕y⊕z */
    yihuo(b, c, temp);
    yihuo(temp, d, temp);
}

/* I函数 */
void I(int *b, int *c, int *d, int *temp) {
    /* I(x,y,z)=y⊕(x∨¬z) */
    fei(d, temp);
    huo(b, temp, temp);
    yihuo(c, temp, temp);
}

/*左移函数*/
void move(int step, int *temp1, int *temp2) {
    int i;
    for (i = 0; i < 32 - step; i++)
        temp2[i] = temp1[i + step];
    for (i = 0; i < step; i++)
        temp2[32 - step + i] = temp1[i];
}

/*每一大轮的16小轮循环函数*/
void _round(int *a, int *b, int *c, int *d, int *m, int *md5, int r, char *t1,
           char *t2, char *t3, char *t4, char *t5, char *t6, char *t7, char *t8, char *t9,
           char *t10, char *t11, char *t12, char *t13, char *t14, char *t15, char *t16) {
    int i, j, in, step, temp1[32], temp2[32];
    for (i = 0; i < 16; i++) {
        switch (r)  //根据r判断所选的逻辑函数
        {
            case 1:
                F(b, c, d, temp1, temp2);
                break;
            case 2:
                G(b, c, d, temp1, temp2);
                break;
            case 3:
                H(b, c, d, temp2);
                break;
            case 4:
                I(b, c, d, temp2);
                break;
        }
        in = m[i];
        for (j = 0; j < 32; j++)
            temp1[j] = md5[in * 32 + j];
        jia(temp2, temp1, temp2);
        switch (i + 1)  //选择t[]
        {
            case 1:
                shiliuzhuaner(t1, temp1);
                break;
            case 2:
                shiliuzhuaner(t2, temp1);
                break;
            case 3:
                shiliuzhuaner(t3, temp1);
                break;
            case 4:
                shiliuzhuaner(t4, temp1);
                break;
            case 5:
                shiliuzhuaner(t5, temp1);
                break;
            case 6:
                shiliuzhuaner(t6, temp1);
                break;
            case 7:
                shiliuzhuaner(t7, temp1);
                break;
            case 8:
                shiliuzhuaner(t8, temp1);
                break;
            case 9:
                shiliuzhuaner(t9, temp1);
                break;
            case 10:
                shiliuzhuaner(t10, temp1);
                break;
            case 11:
                shiliuzhuaner(t11, temp1);
                break;
            case 12:
                shiliuzhuaner(t12, temp1);
                break;
            case 13:
                shiliuzhuaner(t13, temp1);
                break;
            case 14:
                shiliuzhuaner(t14, temp1);
                break;
            case 15:
                shiliuzhuaner(t15, temp1);
                break;
            case 16:
                shiliuzhuaner(t16, temp1);
                break;
        }
        jia(temp2, temp1, temp2);
        jia(temp2, a, temp2);
        switch (r)  //根据r为左移步数step赋值
        {
            case 1:
                switch (i % 4 + 1) {
                    case 1:
                        step = 7;
                        break;
                    case 2:
                        step = 12;
                        break;
                    case 3:
                        step = 17;
                        break;
                    case 4:
                        step = 22;
                        break;
                }
                break;
            case 2:
                switch (i % 4 + 1) {
                    case 1:
                        step = 5;
                        break;
                    case 2:
                        step = 9;
                        break;
                    case 3:
                        step = 14;
                        break;
                    case 4:
                        step = 20;
                        break;
                }
                break;
            case 3:
                switch (i % 4 + 1) {
                    case 1:
                        step = 4;
                        break;
                    case 2:
                        step = 11;
                        break;
                    case 3:
                        step = 16;
                        break;
                    case 4:
                        step = 23;
                        break;
                }
                break;
            case 4:
                switch (i % 4 + 1) {
                    case 1:
                        step = 6;
                        break;
                    case 2:
                        step = 10;
                        break;
                    case 3:
                        step = 15;
                        break;
                    case 4:
                        step = 21;
                        break;
                }
                break;
        }
        move(step, temp2, temp1);
        jia(temp1, b, temp2);
        for (j = 0; j < 32; j++) {
            a[j] = d[j];
            d[j] = c[j];
            c[j] = b[j];
            b[j] = temp2[j];
        }

        /*若想输出每轮a、b、c、d的值，把下面的注释取消即可*/
        /*printf("第%d大轮的第%d小轮\n", r, i);
         * 		abcd_out(a);
         * 				printf("   ");
         * 						abcd_out(b);
         * 								printf("   ");
         * 										abcd_out(c);
         * 												printf("   ");
         * 														abcd_out(d);
         * 																printf("\n");*/

    }
}

/* 主函数 */
int main(int argc, char **args) {
    freopen(args[1], "r", stdin);
    freopen(args[2], "w", stdout);
    char ch,
    /* 一大坨t[] */
    t1[8] = {'d', '7', '6', 'a', 'a', '4', '7', '8'},
            t2[8] = {'e', '8', 'c', '7', 'b', '7', '5', '6'},
            t3[8] = {'2', '4', '2', '0', '7', '0', 'd', 'b'},
            t4[8] = {'c', '1', 'b', 'd', 'c', 'e', 'e', 'e'},
            t5[8] = {'f', '5', '7', 'c', '0', 'f', 'a', 'f'},
            t6[8] = {'4', '7', '8', '7', 'c', '6', '2', 'a'},
            t7[8] = {'a', '8', '3', '0', '4', '6', '1', '3'},
            t8[8] = {'f', 'd', '4', '6', '9', '5', '0', '1'},
            t9[8] = {'6', '9', '8', '0', '9', '8', 'd', '8'},
            t10[8] = {'8', 'b', '4', '4', 'f', '7', 'a', 'f'},
            t11[8] = {'f', 'f', 'f', 'f', '5', 'b', 'b', '1'},
            t12[8] = {'8', '9', '5', 'c', 'd', '7', 'b', 'e'},
            t13[8] = {'6', 'b', '9', '0', '1', '1', '2', '2'},
            t14[8] = {'f', 'd', '9', '8', '7', '1', '9', '3'},
            t15[8] = {'a', '6', '7', '9', '4', '3', '8', 'e'},
            t16[8] = {'4', '9', 'b', '4', '0', '8', '2', '1'},
            t17[8] = {'f', '6', '1', 'e', '2', '5', '6', '2'},
            t18[8] = {'c', '0', '4', '0', 'b', '3', '4', '0'},
            t19[8] = {'2', '6', '5', 'e', '5', 'a', '5', '1'},
            t20[8] = {'e', '9', 'b', '6', 'c', '7', 'a', 'a'},
            t21[8] = {'d', '6', '2', 'f', '1', '0', '5', 'd'},
            t22[8] = {'0', '2', '4', '4', '1', '4', '5', '3'},
            t23[8] = {'d', '8', 'a', '1', 'e', '6', '8', '1'},
            t24[8] = {'e', '7', 'd', '3', 'f', 'b', 'c', '8'},
            t25[8] = {'2', '1', 'e', '1', 'c', 'd', 'e', '6'},
            t26[8] = {'c', '3', '3', '7', '0', '7', 'd', '6'},
            t27[8] = {'f', '4', 'd', '5', '0', 'd', '8', '7'},
            t28[8] = {'4', '5', '5', 'a', '1', '4', 'e', 'd'},
            t29[8] = {'a', '9', 'e', '3', 'e', '9', '0', '5'},
            t30[8] = {'f', 'c', 'e', 'f', 'a', '3', 'f', '8'},
            t31[8] = {'6', '7', '6', 'f', '0', '2', 'd', '9'},
            t32[8] = {'8', 'd', '2', 'a', '4', 'c', '8', 'a'},
            t33[8] = {'f', 'f', 'f', 'a', '3', '9', '4', '2'},
            t34[8] = {'8', '7', '7', '1', 'f', '6', '8', '1'},
            t35[8] = {'6', 'd', '9', 'd', '6', '1', '2', '2'},
            t36[8] = {'f', 'd', 'e', '5', '3', '8', '0', 'c'},
            t37[8] = {'a', '4', 'b', 'e', 'e', 'a', '4', '4'},
            t38[8] = {'4', 'b', 'd', 'e', 'c', 'f', 'a', '9'},
            t39[8] = {'f', '6', 'b', 'b', '4', 'b', '6', '0'},
            t40[8] = {'b', 'e', 'b', 'f', 'b', 'c', '7', '0'},
            t41[8] = {'2', '8', '9', 'b', '7', 'e', 'c', '6'},
            t42[8] = {'e', 'a', 'a', '1', '2', '7', 'f', 'a'},
            t43[8] = {'d', '4', 'e', 'f', '3', '0', '8', '5'},
            t44[8] = {'0', '4', '8', '8', '1', 'd', '0', '5'},
            t45[8] = {'d', '9', 'd', '4', 'd', '0', '3', '9'},
            t46[8] = {'e', '6', 'd', 'b', '9', '9', 'e', '5'},
            t47[8] = {'1', 'f', 'a', '2', '7', 'c', 'f', '8'},
            t48[8] = {'c', '4', 'a', 'c', '5', '6', '6', '5'},
            t49[8] = {'f', '4', '2', '9', '2', '2', '4', '4'},
            t50[8] = {'4', '3', '2', 'a', 'f', 'f', '9', '7'},
            t51[8] = {'a', 'b', '9', '4', '2', '3', 'a', '7'},
            t52[8] = {'f', 'c', '9', '3', 'a', '0', '3', '9'},
            t53[8] = {'6', '5', '5', 'b', '5', '9', 'c', '3'},
            t54[8] = {'8', 'f', '0', 'c', 'c', 'c', '9', '2'},
            t55[8] = {'f', 'f', 'e', 'f', 'f', '4', '7', 'd'},
            t56[8] = {'8', '5', '8', '4', '5', 'd', 'd', '1'},
            t57[8] = {'6', 'f', 'a', '8', '7', 'e', '4', 'f'},
            t58[8] = {'f', 'e', '2', 'c', 'e', '6', 'e', '0'},
            t59[8] = {'a', '3', '0', '1', '4', '3', '1', '4'},
            t60[8] = {'4', 'e', '0', '8', '1', '1', 'a', '1'},
            t61[8] = {'f', '7', '5', '3', '7', 'e', '8', '2'},
            t62[8] = {'b', 'd', '3', 'a', 'f', '2', '3', '5'},
            t63[8] = {'2', 'a', 'd', '7', 'd', '2', 'b', 'b'},
            t64[8] = {'e', 'b', '8', '6', 'd', '3', '9', '1'};
    int in, n = 0, i, j, addup;
    int md5[512],
    /*每一大轮m[]的调用顺序*/
    m1[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
            m2[16] = {1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12},
            m3[16] = {5, 8, 11, 14, 1, 4, 7, 10, 13, 0, 3, 6, 9, 12, 15, 2},
            m4[16] = {0, 7, 14, 5, 12, 3, 10, 1, 8, 15, 6, 13, 4, 11, 2, 9},
    /* a[]、b[]、c[]、d[]的初始值(已经过大小端处理) */
    /* 把a[]、b[]、c[]、d[]赋值给a1[]、b1[]、c1[]、d1[]*/
    a[32] = {0, 1, 1, 0, 0, 1, 1, 1,
             0, 1, 0, 0, 0, 1, 0, 1,
             0, 0, 1, 0, 0, 0, 1, 1,
             0, 0, 0, 0, 0, 0, 0, 1},
            a1[32] = {0, 1, 1, 0, 0, 1, 1, 1,
                      0, 1, 0, 0, 0, 1, 0, 1,
                      0, 0, 1, 0, 0, 0, 1, 1,
                      0, 0, 0, 0, 0, 0, 0, 1},
            b[32] = {1, 1, 1, 0, 1, 1, 1, 1,
                     1, 1, 0, 0, 1, 1, 0, 1,
                     1, 0, 1, 0, 1, 0, 1, 1,
                     1, 0, 0, 0, 1, 0, 0, 1},
            b1[32] = {1, 1, 1, 0, 1, 1, 1, 1,
                      1, 1, 0, 0, 1, 1, 0, 1,
                      1, 0, 1, 0, 1, 0, 1, 1,
                      1, 0, 0, 0, 1, 0, 0, 1},
            c[32] = {1, 0, 0, 1, 1, 0, 0, 0,
                     1, 0, 1, 1, 1, 0, 1, 0,
                     1, 1, 0, 1, 1, 1, 0, 0,
                     1, 1, 1, 1, 1, 1, 1, 0},
            c1[32] = {1, 0, 0, 1, 1, 0, 0, 0,
                      1, 0, 1, 1, 1, 0, 1, 0,
                      1, 1, 0, 1, 1, 1, 0, 0,
                      1, 1, 1, 1, 1, 1, 1, 0},
            d[32] = {0, 0, 0, 1, 0, 0, 0, 0,
                     0, 0, 1, 1, 0, 0, 1, 0,
                     0, 1, 0, 1, 0, 1, 0, 0,
                     0, 1, 1, 1, 0, 1, 1, 0},
            d1[32] = {0, 0, 0, 1, 0, 0, 0, 0,
                      0, 0, 1, 1, 0, 0, 1, 0,
                      0, 1, 0, 1, 0, 1, 0, 0,
                      0, 1, 1, 1, 0, 1, 1, 0};
    ch = getchar();
    while (ch != '\n' && n < 57)  //用getchar()函数接收字符，直到接收到回车符或字符数超过56为止
    {
        in = (int) ch;
        shizhuaner(in, n, md5);
        n++;
        ch = getchar();
    }
    i = 0;
    addup = n;
    while (n % 4 != 0 && n < 56)  //长度不是4的倍数，补一个1和0直到长度为4的倍数,，最终实现用1与0使其长度模512与448同于，在这个程序里也就是448
    {
        int s, w, j;
        s = n / 4 + 1;
        w = n % 4;
        j = 1;
        do {
            md5[32 * s - 8 * w - j] = 0;
            j++;
        } while (j <= 7);
        if (i == 0) {
            md5[32 * s - 8 * w - j] = 1;
            i = 1;
        }
        n++;
    }
    if (i == 0)  //长度不是4的倍数，补一个1和31个0
    {
        for (j = 0; j < 32; j++)
            md5[n * 8 + j] = 0;
        md5[8 * n + 24] = 1;
    }
    for (i = 0; i < 512; i++)  //补零，任何不为1的数都设为0
    {
        if (md5[i] == 1)
            md5[i] = 1;
        else
            md5[i] = 0;
    }
    printf("\n");
    shizhuaner_weishu(addup * 8, md5);  //64位数填充

    /*若想看m[0]~m[15],把下面注释去掉即可*/
    /*printf("m[0]~m[15]如下:\n");
 * 	for (i = 0; i < 512; i++)
 * 		{
 * 				printf("%d ", md5[i]);
 * 						if (i % 8 == 7)
 * 									printf("\n");
 * 											if (i % 32 == 31)
 * 														printf("\n");
 * 															}
 * 																printf("\n");*/

    /* 第一、二、三、四大轮，每一大轮下有16小轮 */
    _round(a, b, c, d, m1, md5, 1, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16);
    _round(a, b, c, d, m2, md5, 2, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32);
    _round(a, b, c, d, m3, md5, 3, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48);
    _round(a, b, c, d, m4, md5, 4, t49, t50, t51, t52, t53, t54, t55, t56, t57, t58, t59, t60, t61, t62, t63, t64);
    printf("\n");
    /* 最终的a、b、c、d分别与最初的a、b、c、d相加 */
    jia(a, a1, a);
    jia(b, b1, b);
    jia(c, c1, c);
    jia(d, d1, d);
    /*密文输出*/
    c_out(a);
    c_out(b);
    c_out(c);
    c_out(d);
    printf("\n");
    return 0;
}
