/**
 * @file init.c
 * @brief  initialize application
 * @author simpart
 */
#include <stdio.h>
#include "tetraring.h"
#include "com.h"
#include "conf.h"

int ocn_term (void) {
    int ret = 0;
    
    ret = ocncnf_term();
    __ttrchk_retng(ret);
    
    
    
    return COM_OK;
}
/* end of file */
