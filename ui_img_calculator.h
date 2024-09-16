/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CUI_IMG_CALCULATION_WINDOW_H
#define CUI_IMG_CALCULATION_WINDOW_H

/* Includes ------------------------------------------------------------------*/
typedef struct {
    double real;            // Real part of a complex number
    double imagine;         // Imaginary part of a complex number
} complex_t;

// Enumeration for math operators
typedef enum {
    CHAR_PLUS = '+',        // Math operator: addition
    CHAR_SUBTRACT = '-',    // Math operator: subtraction
    CHAR_MULTIPLY = '*',    // Math operator: multiplication
    CHAR_DIVIDE = '/'       // Math operator: division
} math_operator_t;

/* Structure Declaration -----------------------------------------------------*/
// Structure to hold data in window
typedef struct {
    complex_t z1;
    complex_t z2;
    math_operator_t op;
    complex_t result;
} cui_Img_calculation_window_data_t;

/* Getter and Setter Functions -----------------------------------------------*/
cui_Img_calculation_window_data_t CUI_Img__CALCULATION_WINDOW_Data_GetWindowData(void);
void CUI_Img__CALCULATION_WINDOW_Data_SetZ1(complex_t z);
complex_t CUI_Img__CALCULATION_WINDOW_Data_GetZ1(void);
void CUI_Img__CALCULATION_WINDOW_Data_SetZ2(complex_t z);
complex_t CUI_Img__CALCULATION_WINDOW_Data_GetZ2(void);
void CUI_Img__CALCULATION_WINDOW_Data_SetOperator(math_operator_t op);
math_operator_t CUI_Img__CALCULATION_WINDOW_Data_GetOperator(void);
void CUI_Img__CALCULATION_WINDOW_Data_SetResult(complex_t result);
complex_t CUI_Img__CALCULATION_WINDOW_Data_GetResult(void);

/* Window Management Functions -----------------------------------------------*/
void CUI_Img__CALCULATION_WINDOW_Launch(void);
void CUI_Img__CALCULATION_WINDOW_DisplayMenu(void);
void CUI_Img__CALCULATION_WINDOW_GetInputFromUser(void);
void CUI_Img__CALCULATION_WINDOW_HandleUserInput(void);

/* Window Helpers Functions --------------------------------------------------*/
void CUI_Img__CALCULATION_WINDOW_DisplayResult(void);

complex_t CUI_Img__CALCULATION_WINDOW_ExtractData(const char* data_stream);

#endif /* CUI_Img__CALCULATION_WINDOW_H */
