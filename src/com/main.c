/**
 * @file main.c
 * @brief startup function
 * @author simpart
 */
//#include <unistd.h>
#include <stdio.h>
#include "tetraring.h"
#include "com.h"
#include "core.h"

int main (void) {
    
    int ret = 0;
    
    /* initialize */
    ret = ocn_init();
    __ttrchk_retng(ret);
    
    /* start app */
    ocncre_start();
    
    /* termination */
    ocn_term();
    
    return COM_OK;
}
/* end of file */
