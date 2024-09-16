// ui_real_calculation.c: thực hiện các phép tính toán số thực (như cộng, trừ, nhân, chia)
#include "ui_real_calculator.h"
#include <stdio.h>
#include "event.h"
//Hàm trừ hai số thực
real_t addReal(real_t a, real_t b) {
    real_t result;
    result.value = a.value + b.value;
    return result;
}
//Hàm trừ hai số thực
real_t subtractReal(real_t a, real_t b) {
    real_t result;
    result.value = a.value - b.value;
    return result;
}
//Hàm nhân hai số thực
real_t multiplyReal(real_t a, real_t b) {
    real_t result;
    result.value = a.value * b.value;
    return result;
}
//Hàm chia hai số thực
real_t divideReal(real_t a, real_t b) {
    real_t result;
    if (b.value == 0) {
        printf("Error: Khong co phep chia cho 0\n");
        result.value = 0;
    } else {
        result.value = a.value / b.value;
    }
    return result;
}
//Hiển thị một menu hướng dẫn người dùng nhập phép toán giữa hai số thực
void REAL_CALCULATION_WINDOW_DisplayMenu(void) {
    printf("\n\nChe do so thuc");
    printf("\n-----------------------------");
    printf("\nLua chon phep toan: a [+,-,*,/] b");
    printf("\n");
}
//Hàm chính điều khiển toàn bộ quá trình tính toán.
void REAL_CALCULATION_WINDOW_Launch(void) {
    REAL_CALCULATION_WINDOW_DisplayMenu();

    real_t a, b, result;
    char op;

    printf("\nNhap gia tri a: ");
    scanf("%lf", &a);

    printf("\nNhap gia tri b: ");
    scanf("%lf", &b);

    printf("\nNhap phep toan [+,-,*,/]: ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            result = addReal(a, b);
            break;
        case '-':
            result = subtractReal(a, b);
            break;
        case '*':
            result = multiplyReal(a, b);
            break;
        case '/':
            result = divideReal(a, b);
            break;
        default:
            printf("Phep toan khong hop le\n");
            return;
    }

    printf("\nKet qua: %.2lf %c %.2lf = %.2lf\n", a, op, b, result);
    EVENT_MANAGER_TriggerSignal_MainWindow();
}