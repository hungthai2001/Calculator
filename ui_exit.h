/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CUI_EXIT_WINDOW_H
#define CUI_EXIT_WINDOW_H

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>


/* Structure Declaration -----------------------------------------------------*/

/* Window Management Functions -----------------------------------------------*/
void CUI_EXIT_WINDOW_Launch(void);
void CUI_CONFIRM_EXIT_WINDOW_LUNCH(void);
void CUI_EXIT_WINDOW_DisplayMenu(void);
void CUI_EXIT_WINDOW_GetInputFromUser(void);
void CUI_EXIT_WINDOW_HandleUserInput(void);
bool get_status_exit();
void set_status_exit(bool a);
/* Window Helpers Functions --------------------------------------------------*/

#endif /* CUI_EXIT_WINDOW_H */