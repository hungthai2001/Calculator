//Module điều khiển quá trình thoát khỏi chương trình, bao gồm việc xác nhận thoát và xử lý các thao tác tương ứng từ người dùng.
#include "ui_exit.h"
#include <stdio.h>
#include "event.h"

static bool exit_conf = false;
/*
Đây là hàm chính để khởi chạy cửa sổ thoát chương trình.
Đầu tiên, nó gọi hàm CUI_CONFIRM_EXIT_WINDOW_LUNCH() để xác nhận việc người dùng có muốn thoát chương trình hay không.
Nếu người dùng chọn thoát (exit_conf == true), chương trình sẽ hiển thị menu thoát và chờ xử lý các thao tác từ người dùng.
Nếu người dùng từ chối thoát (exit_conf == false), chương trình sẽ quay lại cửa sổ chính thông qua việc gọi hàm EVENT_MANAGER_TriggerSignal_MainWindow().
*/
void CUI_EXIT_WINDOW_Launch(void) {
    CUI_CONFIRM_EXIT_WINDOW_LUNCH();
    if(exit_conf)
    {
    CUI_EXIT_WINDOW_DisplayMenu();
    CUI_EXIT_WINDOW_GetInputFromUser();
    CUI_EXIT_WINDOW_HandleUserInput();
    }
    else
    {
        EVENT_MANAGER_TriggerSignal_MainWindow();
    }
}
//Hiển thị thông báo thoát khỏi chương trình với lời chào "Hẹn gặp lại" sau khi người dùng xác nhận thoát.
void CUI_EXIT_WINDOW_DisplayMenu(void) {
    printf("\nThoat khoi chuong trinh...");
    printf("\nHen gap lai!");
}

void CUI_EXIT_WINDOW_GetInputFromUser(void) {
  
}

void CUI_EXIT_WINDOW_HandleUserInput(void) {
   
}

/*
Hàm này được sử dụng để yêu cầu người dùng xác nhận việc thoát chương trình.
Người dùng nhập Y hoặc y để xác nhận thoát, và biến exit_conf được đặt thành true.
Nếu người dùng nhập N hoặc n, exit_conf được đặt thành false và chương trình sẽ không thoát.
Một vòng lặp kiểm tra đầu vào được sử dụng để đảm bảo rằng người dùng chỉ nhập ký tự hợp lệ (Y/N).
*/
void CUI_CONFIRM_EXIT_WINDOW_LUNCH(void)
{
    char op;
    int check=0;
    do
    {
    printf("\nBan chac chu[Y/N]:");
    scanf("%c", &op);
    while (getchar() != '\n');
    if(op=='y'|| op == 'Y')
    {
        exit_conf = true;
        check =1;
    }
    else if(op=='n'|| op == 'N')
    {
        exit_conf = false;
        check=1;
    }
    }while(!check);
}
bool get_status_exit()
{
    return exit_conf;
}

void set_status_exit(bool a)
{
    exit_conf=a;
}