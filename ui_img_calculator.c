
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "ui_img_calculator.h"
#include "event.h"

static cui_Img_calculation_window_data_t cui_Img_calculation_window_data;

typedef complex_t (*handlert_cal)(complex_t a,complex_t b);

typedef struct 
{
    math_operator_t op;
    handlert_cal handle_func;
}cmd_t;
//Hàm cộng hai số phức
complex_t addComplex(complex_t c1, complex_t c2) {
    complex_t result;
    result.real = c1.real + c2.real;
    result.imagine = c1.imagine + c2.imagine;
    return result;
}

// Hàm trừ hai số phức
complex_t subtractComplex(complex_t c1, complex_t c2) {
    complex_t result;
    result.real = c1.real - c2.real;
    result.imagine = c1.imagine - c2.imagine;
    return result;
}

// Hàm nhân hai số phức
complex_t multiplyComplex(complex_t c1, complex_t c2) {
    complex_t result;
    result.real = c1.real * c2.real - c1.imagine * c2.imagine;
    result.imagine = c1.real * c2.imagine + c1.imagine * c2.real;
    return result;
}

// Hàm chia hai số phức
complex_t divideComplex(complex_t a, complex_t b) {
    complex_t result;
    float denominator = b.real * b.real + b.imagine * b.imagine;
    
    if (denominator == 0) {
        printf("Error: Division by zero\n");
        result.real = 0;
        result.imagine = 0;
        return result;
    }

    result.real = (a.real * b.real + a.imagine * b.imagine) / denominator;
    result.imagine = (a.imagine * b.real - a.real * b.imagine) / denominator;

    return result;
}
cmd_t cmd_list_complex[] ={
    {CHAR_PLUS, addComplex},
    {CHAR_SUBTRACT,subtractComplex},
    {CHAR_MULTIPLY,multiplyComplex},
    {CHAR_DIVIDE,divideComplex},
};


cui_Img_calculation_window_data_t CUI_Img__CALCULATION_WINDOW_Data_GetWindowData(void) {
    return cui_Img_calculation_window_data;
}
//Set giá trị của số phức thứ nhất.
void CUI_Img__CALCULATION_WINDOW_Data_SetZ1(complex_t z) {
    cui_Img_calculation_window_data.z1 = z;
}
//Get giá trị của số phức thứ nhất.
complex_t CUI_Img__CALCULATION_WINDOW_Data_GetZ1(void) {
    return cui_Img_calculation_window_data.z1;
}
//Set giá trị của số phức thứ hai.
void CUI_Img__CALCULATION_WINDOW_Data_SetZ2(complex_t z) {
    cui_Img_calculation_window_data.z2 = z;
}
//Get giá trị của số phức thứ hai.
complex_t CUI_Img__CALCULATION_WINDOW_Data_GetZ2(void) {
    return cui_Img_calculation_window_data.z2;
}
//Set toán tử được nhập
void CUI_Img__CALCULATION_WINDOW_Data_SetOperator(math_operator_t op) {
    cui_Img_calculation_window_data.op = op;
}
//Get toán tử
math_operator_t CUI_Img__CALCULATION_WINDOW_Data_GetOperator(void) {
    return cui_Img_calculation_window_data.op;
}
//Set kết quả của phép toán số phức
void CUI_Img__CALCULATION_WINDOW_Data_SetResult(complex_t result) {
    cui_Img_calculation_window_data.result = result;
}
//Get kết quả của phép toán số phức
complex_t CUI_Img__CALCULATION_WINDOW_Data_GetResult(void) {
    return cui_Img_calculation_window_data.result;
}
//Hàm xử lý chính của các phép toán số phức
void CUI_Img__CALCULATION_WINDOW_Launch(void) {
    CUI_Img__CALCULATION_WINDOW_DisplayMenu(); //Giao diện menu(Nhập,xuất dữ liệu)
    CUI_Img__CALCULATION_WINDOW_GetInputFromUser(); // Nhập dữ liêu từ người dùng (toán tử, phần thực + phần ảo của các toán hạng )
    CUI_Img__CALCULATION_WINDOW_HandleUserInput();//Tính toán kết quả phép toán số phức

    EVENT_MANAGER_TriggerSignal_MainWindow(); // Set cờ màn hình chính lên 1 -> quay lại cửa chính sau khi thực hiện phép toán.
}
//Hiển thị một menu hướng dẫn người dùng nhập phép toán giữa hai số phức
void CUI_Img__CALCULATION_WINDOW_DisplayMenu(void) {
    printf("\n\nChe do so phuc");
    printf("\n-----------------------------");
    printf("\nMODE: Img_ CALCULATION");
    printf("\nLua chon phep toan: z1 [+,-,*,/] z2");
    printf("\nz1 = a1 + b1.i");
    printf("\nz2 = a2 + b2.i");
    printf("\n");
}
//Nhập một giá trị số thực từ người dùng và đảm bảo rằng giá trị nhập vào hợp lệ.
double CUI_INPUT_VALIDATION_GetDoubleFromUser(const char* input_prompt_msg) {
    double number;
    int number_of_received_input = 0;
    bool input_is_valid = true;

    do {
        input_is_valid = true;
        printf("\n%s: ", input_prompt_msg);
        number_of_received_input = scanf("%lf", &number);
        while(getchar() != '\n');
        printf("Current received input: %.15g", number);

        if (!(number_of_received_input == 1)) {
            input_is_valid = false;
            printf("\n\nSorry, try again!");
        }
    } while (!input_is_valid);

    return number;
}
// Nhập toán tử từ người dùng và kiểm tra xem toán tử có hợp lệ hay không (+,-,*,/).
math_operator_t CUI_INPUT_VALIDATION_GetOperatorFromUser(const char* input_prompt_msg) {
    char op;
    bool input_is_valid = true;

    do {
        input_is_valid = true;
        printf("\n%s: ", input_prompt_msg);
        scanf("%c", &op);
        while(getchar() != '\n');
        printf("Current received input: %c", op);

        if (!(op == '+' || op == '-' || op == '*' || op == '/')) {
            input_is_valid = false;
            printf("\n\nSorry, try again!");
        }
    } while (!input_is_valid);

    return (math_operator_t) op;
}
// Lấy đầu vào từ người dùng r set 2 số phức tương ứng với số liệu được nhập.
void CUI_Img__CALCULATION_WINDOW_GetInputFromUser(void) {
    complex_t z1;
    z1.real = CUI_INPUT_VALIDATION_GetDoubleFromUser("a1");
    z1.imagine = CUI_INPUT_VALIDATION_GetDoubleFromUser("b1");
    printf("\nReceived: z1 = %.15g + %.15g.i\n", z1.real, z1.imagine);

    complex_t z2;
    z2.real = CUI_INPUT_VALIDATION_GetDoubleFromUser("a2");
    z2.imagine = CUI_INPUT_VALIDATION_GetDoubleFromUser("b2");
    printf("\nReceived: z2 = %.15g + %.15g.i\n", z2.real, z2.imagine);

    math_operator_t op = CUI_INPUT_VALIDATION_GetOperatorFromUser("Operator [+,-,*,/]");
    printf("\nReceived: op = %c\n", op);

    CUI_Img__CALCULATION_WINDOW_Data_SetZ1(z1);
    CUI_Img__CALCULATION_WINDOW_Data_SetZ2(z2);
    CUI_Img__CALCULATION_WINDOW_Data_SetOperator(op);
}


//Sau khi phép toán được thực hiện, kết quả sẽ được hiển thị ra màn hình dưới dạng số phức với phần thực và phần ảo.
void CUI_Img__CALCULATION_WINDOW_DisplayResult(void) {
    cui_Img_calculation_window_data_t data = CUI_Img__CALCULATION_WINDOW_Data_GetWindowData();
    switch (data.op)
    {
    case CHAR_PLUS:
    case CHAR_SUBTRACT:
    case CHAR_MULTIPLY:
    case CHAR_DIVIDE:
        printf("\nResult: (%.15g + %.15g.i) %c (%.15g + %.15g.i) = %.15g + %.15g.i\n", 
            data.z1.real, data.z1.imagine, 
            data.op, 
            data.z2.real, data.z2.imagine, 
            data.result.real, data.result.imagine);
        break;
    
    default:
        printf("\nThis math operation is currently in development!");
        break;
    }
}
//Xử lý đầu vào: Dựa trên toán tử mà người dùng đã chọn, chương trình tìm kiếm trongcmd_list_complex để thực hiện phép toán tương ứng. 
void CUI_Img__CALCULATION_WINDOW_HandleUserInput(void) {
    cui_Img_calculation_window_data_t data = cui_Img_calculation_window_data;
    for(int i= 0; i< sizeof(cmd_list_complex) / sizeof(cmd_t); i++)
    {
        if(data.op == cmd_list_complex[i].op)
        {
            data.result = cmd_list_complex[i].handle_func(data.z1,data.z2);
            CUI_Img__CALCULATION_WINDOW_Data_SetResult(data.result);
            CUI_Img__CALCULATION_WINDOW_DisplayResult();
        }
    }
}