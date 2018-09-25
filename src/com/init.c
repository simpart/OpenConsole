/**
 * @file init.c
 * @brief  initialize application
 * @author simpart
 */
#include <stdio.h>
#include "tetraring.h"
#include "com.h"
#include "conf.h"
#include "core.h"

int ocn_init (void) {
    int ret = 0;
    
    /* core */
    ret = ocncre_init();
    __ttrchk_retng(ret);
    
    /* config */
    ret = ocncnf_init();
    __ttrchk_retng(ret);
    
    //printf("\n");
    
    return COM_OK;
}
/* end of file */
