//app_manager: Kiểm tra và xử lý các sự kiện khác nhau trong một vòng lặp chính
#include "app_manager.h"
#include "event.h"
#include "ui_main.h"
#include "ui_img_calculator.h"
#include "ui_real_calculator.h"
#include "ui_exit.h"

void APP_MANAGER_Launch(void) {
    bool WindowShouldClose = false;

    while (!WindowShouldClose) {
        /*Kiểm tra xem sự kiện cửa sổ chính có được kích hoạt hay không?
        - Nếu sự kiện cửa sổ chính được kích hoạt sẽ khởi chạy cửa sổ giao diện chính. */
        if (EVENT_MANAGER_GetSignal_MainWindow()) {
            CUI_MAIN_WINDOW_Launch();
        }
        /*Kiểm tra xem sự kiện tính toán số phức có được kích hoạt hay không?
        - Nếu sự kiện tính toán số phức được kích hoạt, hàm này sẽ khởi chạy cửa sổ tính toán số phức. */
        if (EVENT_MANAGER_GetSignal_Img_CalculationWindow()) {
            CUI_Img__CALCULATION_WINDOW_Launch();
        }
        /*Kiểm tra xem sự kiện tính toán số thực có được kích hoạt hay không?
        - Nếu sự kiện tính toán số thực được kích hoạt, hàm này sẽ khởi chạy cửa sổ tính toán số thực. */
        if(EVENT_MANAGER_GetSignal_Real_CalculationWindow()){
            REAL_CALCULATION_WINDOW_Launch();
        }
        /*Kiểm tra xem có sự kiện thoát không.?
        -  Nếu sự kiện thoát được kích hoạt, hàm này sẽ mở cửa sổ thoát để người dùng xác nhận thoát chương trình. */
        if (EVENT_MANAGER_GetSignal_Exit()) {
            CUI_EXIT_WINDOW_Launch();
            if(get_status_exit())
            {
              WindowShouldClose = true; 
            }
        }
    }
}

