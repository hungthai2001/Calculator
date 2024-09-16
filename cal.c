#include <stdio.h>
#include <stdbool.h>
#include "app_manager.h"

int main()
{
    APP_MANAGER_Launch();
    return 0;
}

// int main() {
//     int choice;
//     float real1, real2;
//     Complex comp1, comp2, compResult;

//     printf("Chon phep toan:\n");
//     printf("1. Phep toan voi so thuc\n");
//     printf("2. Phep toan voi so phuc\n");
//     printf("Lua chon cua ban: ");
//     scanf("%d", &choice);

//     if (choice == 1) {
//         int realChoice;
//         printf("Chon phep toan cho so thuc:\n");
//         printf("1. Cong\n2. Tru\n3. Nhan\n4. Chia\n");
//         printf("Lua chon cua ban: ");
//         scanf("%d", &realChoice);

//         printf("Nhap so thuc thu nhat: ");
//         scanf("%f", &real1);
//         printf("Nhap so thuc thu hai: ");
//         scanf("%f", &real2);

//         switch (realChoice) {
//             case 1:
//                 printf("Ket qua: %.2f\n", addReal(real1, real2));
//                 break;
//             case 2:
//                 printf("Ket qua: %.2f\n", subtractReal(real1, real2));
//                 break;
//             case 3:
//                 printf("Ket qua: %.2f\n", multiplyReal(real1, real2));
//                 break;
//             case 4:
//                 printf("Ket qua: %.2f\n", divideReal(real1, real2));
//                 break;
//             default:
//                 printf("Lua chon khong hop le!\n");
//                 break;
//         }
//     } else if (choice == 2) {
//         int compChoice;
//         printf("Chon phep toan so phuc:\n");
//         printf("1. Cong\n2. Tru\n3. Nhan\n");
//         printf("Lua chon cua ban: ");
//         scanf("%d", &compChoice);

//         printf("\na+bi");
//         printf("\nNhap phan thuc so phuc thu nhat: a1=");
//         scanf("%f", &comp1.real); 
//         printf("\nNhap phan ao so phuc thu nhat: b1=");
//         scanf("%f", &comp1.imag);
//         printf("Nhap phan thuc so phuc thu hai: a2=");
//         scanf("%f", &comp2.real); 
//         printf("\nNhap phan ao so phuc thu hai: b2=");
//         scanf("%f", &comp2.imag);

//         switch (compChoice) {
//             case 1:
//                 compResult = addComplex(comp1, comp2);
//                 printf("Ket qua: %.2f + %.2fi\n", compResult.real, compResult.imag);
//                 break;
//             case 2:
//                 compResult = subtractComplex(comp1, comp2);
//                 printf("Ket qua: %.2f + %.2fi\n", compResult.real, compResult.imag);
//                 break;
//             case 3:
//                 compResult = multiplyComplex(comp1, comp2);
//                 printf("Ket qua: %.2f + %.2fi\n", compResult.real, compResult.imag);
//                 break;
//             default:
//                 printf("Lua chon khong hop le!\n");
//                 break;
//         }
//     } else {
//         printf("Lua chon khong hop le!\n");
//     }

//     return 0;
// }