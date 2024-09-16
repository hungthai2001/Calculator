//module xử lý giao diện chính (main window) của một chương trình máy tính cá nhân
//Cho phép người dùng lựa chọn các chế độ tính toán (phép toán số thực, số phức) hoặc thoát chương trình.
#include"ui_main.h"
#include"event.h"
#include <stdio.h>
#include <stdbool.h>

static cui_main_window_data_t cui_main_window_data;
//Đặt giá trị mode (chế độ lựa chọn) mà người dùng đã chọn.
void CUI_MAIN_WINDOW_Data_SetMode(int mode) {
    cui_main_window_data.mode = mode;
}
//Trả về giá trị mode hiện tại của cửa sổ chính.
int CUI_MAIN_WINDOW_Data_GetMode(void) {
    return cui_main_window_data.mode;
}
/*
Hàm này khởi chạy cửa sổ chính của chương trình.
Đầu tiên, nó hiển thị menu lựa chọn bằng cách gọi hàm CUI_MAIN_WINDOW_DisplayMenu.
Sau đó, nó nhận dữ liệu đầu vào từ người dùng thông qua hàm CUI_MAIN_WINDOW_GetInputFromUser.
Cuối cùng, nó xử lý dữ liệu nhập từ người dùng qua hàm CUI_MAIN_WINDOW_HandleUserInput.
*/
void CUI_MAIN_WINDOW_Launch(void) {
    CUI_MAIN_WINDOW_DisplayMenu();
    CUI_MAIN_WINDOW_GetInputFromUser();
    CUI_MAIN_WINDOW_HandleUserInput();
}
/*
Hiển thị giao diện menu chính của chương trình, cho phép người dùng lựa chọn:
    1.Phép toán với số thực.
    2.Phép toán với số phức.
    3.Thoát chương trình.
*/
void CUI_MAIN_WINDOW_DisplayMenu(void) {
    printf("\n\nMay tinh ca nhan");
    printf("\n-----------------------------");
    printf("\nChon phep toan:");
    printf("\n\t1. Phep toan voi so thuc\n");
    printf("\n\t2. Phep toan voi so phuc\n");
    printf("\n\t3. Thoat");
    printf("\n");
}

/*
Hàm này nhận chế độ lựa chọn từ người dùng và kiểm tra tính hợp lệ của dữ liệu nhập.
Nếu người dùng nhập vào một giá trị không hợp lệ (không nằm trong khoảng từ 1 đến 3), hàm sẽ yêu cầu người dùng nhập lại.
Sau khi nhận được giá trị hợp lệ, nó trả về giá trị mode.
*/
int CUI_INPUT_VALIDATION_GetModeFromUser(void) {
    int mode;
    int number_of_received_input = 0;
    bool input_is_valid = true;

    do {
        input_is_valid = true;
        printf("\nSelect mode [1-3]: ");
        number_of_received_input = scanf("%d", &mode);
        while(getchar() != '\n');
        printf("Current received input: %d", mode);

        if (!((mode >= 1 && mode <= 3) && (number_of_received_input == 1))) {
            input_is_valid = false;
            printf("\n\nSorry, try again!");
        }
    } while (!input_is_valid);

    return mode;
}

//Hàm này gọi hàm CUI_INPUT_VALIDATION_GetModeFromUser để nhận chế độ từ người dùng.
void CUI_MAIN_WINDOW_GetInputFromUser(void) {
    int mode = CUI_INPUT_VALIDATION_GetModeFromUser();
    CUI_MAIN_WINDOW_Data_SetMode(mode);
}

/*
Hàm này xử lý hành động tương ứng với chế độ người dùng đã chọn:
    Nếu người dùng chọn 1: Chương trình sẽ chuyển sang chế độ tính toán với số thực.
    Nếu người dùng chọn 2: Chương trình chuyển sang chế độ tính toán với số phức.
    Nếu người dùng chọn 3: Chương trình sẽ thoát.
    Nếu người dùng nhập lựa chọn khác, chương trình sẽ báo tính năng đang phát triển và quay lại cửa sổ chính
*/
void CUI_MAIN_WINDOW_HandleUserInput(void) {
    switch (cui_main_window_data.mode)
    {
    case 1:
        EVENT_MANAGER_TriggerSignal_Real_CalculationWindow();
        break;
    case 2:
        EVENT_MANAGER_TriggerSignal_Img_CalculationWindow();
        break;
    case 3:
        EVENT_MANAGER_TriggerSignal_ExitWindow();
        break;
    
    default:
        printf("\nTinh nang dang phat trien");
        EVENT_MANAGER_TriggerSignal_MainWindow();
        break;
    }
}
