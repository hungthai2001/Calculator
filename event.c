//Định nghĩa một Event Manager , nơi các tín hiệu (signal) được sử dụng để điều khiển và thay đổi trạng thái của ứng dụng. 
//Các tín hiệu này kích hoạt các cửa sổ hoặc chế độ khác nhau của chương trình.
#include "event.h" 

static event_manager_event_t event_manager_event = {true,false,false,false};

bool EVENT_MANAGER_GetSignal_MainWindow(void) {
    bool signal = event_manager_event.signal_main_window;
    event_manager_event.signal_main_window = false;
    return signal;
}

void EVENT_MANAGER_TriggerSignal_MainWindow(void) {
    event_manager_event.signal_main_window = true;
}

bool EVENT_MANAGER_GetSignal_Exit(void) {
    bool signal = event_manager_event.signal_exit_window;
    event_manager_event.signal_exit_window = false;
    return signal;
}

void EVENT_MANAGER_TriggerSignal_ExitWindow(void) {
    event_manager_event.signal_exit_window = true;
}

bool EVENT_MANAGER_GetSignal_Img_CalculationWindow(void) {
    bool signal = event_manager_event.signal_Img__calculation_window;
    event_manager_event.signal_Img__calculation_window = false;
    return signal;
}

void EVENT_MANAGER_TriggerSignal_Img_CalculationWindow(void) {
    event_manager_event.signal_Img__calculation_window = true;
}

bool EVENT_MANAGER_GetSignal_Real_CalculationWindow(void) {
    bool signal = event_manager_event.signal_real_calculation_window;
    event_manager_event.signal_real_calculation_window = false;
    return signal;
}

void EVENT_MANAGER_TriggerSignal_Real_CalculationWindow(void) {
    event_manager_event.signal_real_calculation_window = true;
}