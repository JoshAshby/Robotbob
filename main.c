#include "adc.h"
#include "pwm.h"
//-------------------------------------------

//-------------------------------------------
int main(void)
{
    pwm_setup();
    for(;;){
        pwm_ramp(50, 10);
    }
return 0;   //  never reached
}
