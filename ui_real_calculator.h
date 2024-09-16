// ui_real_calculator.h
#ifndef REAL_CALCULATOR_H
#define REAL_CALCULATOR_H



typedef struct {
    double value;
} real_t;

typedef real_t (*handlert_real)(real_t a, real_t b);

real_t addReal(real_t a, real_t b);
real_t subtractReal(real_t a, real_t b);
real_t multiplyReal(real_t a, real_t b);
real_t divideReal(real_t a, real_t b);

void REAL_CALCULATION_WINDOW_Launch(void);
void REAL_CALCULATION_WINDOW_DisplayMenu(void);

#endif // REAL_CALCULATION_H
