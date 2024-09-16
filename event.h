#ifndef EVENT_H
#define EVENT_H

#include <stdbool.h>


/* Structure Declaration -----------------------------------------------------*/
// Structure to hold event signals
typedef struct {
    bool signal_main_window;                    // Signal for the main window
    bool signal_Img__calculation_window;    // Signal for the Img_ calculation window
    bool signal_real_calculation_window;        // Signal for the real calculation window
    bool signal_exit_window;                           // Signal for exiting the application
} event_manager_event_t;

/* Getter and Setter Functions -----------------------------------------------*/
bool EVENT_MANAGER_GetSignal_MainWindow(void);
void EVENT_MANAGER_TriggerSignal_MainWindow(void);

bool EVENT_MANAGER_GetSignal_Img_CalculationWindow(void);
void EVENT_MANAGER_TriggerSignal_Img_CalculationWindow(void);

bool EVENT_MANAGER_GetSignal_Real_CalculationWindow(void);
void EVENT_MANAGER_TriggerSignal_Real_CalculationWindow(void);

bool EVENT_MANAGER_GetSignal_Exit(void);
void EVENT_MANAGER_TriggerSignal_ExitWindow(void);

#endif