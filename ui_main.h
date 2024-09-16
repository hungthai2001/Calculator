/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CUI_MAIN_WINDOW_H
#define CUI_MAIN_WINDOW_H

/* Includes ------------------------------------------------------------------*/


/* Structure Declaration -----------------------------------------------------*/
// Structure to hold data in window
typedef struct {
    int mode;
} cui_main_window_data_t;

/* Getter and Setter Functions -----------------------------------------------*/
void CUI_MAIN_WINDOW_Data_SetMode(int mode);
int CUI_MAIN_WINDOW_Data_GetMode(void);

/* Window Management Functions -----------------------------------------------*/
void CUI_MAIN_WINDOW_Launch(void);
void CUI_MAIN_WINDOW_DisplayMenu(void);
void CUI_MAIN_WINDOW_GetInputFromUser(void);
void CUI_MAIN_WINDOW_HandleUserInput(void);

/* Window Helpers Functions --------------------------------------------------*/

#endif /* CUI_MAIN_WINDOW_H */