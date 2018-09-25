/**
 * @file init.c
 * @brief  initialize application
 * @author simpart
 */
#include <stdlib.h>
#include <string.h>
#include "tetraring.h"
#include "conf.h"
#include "com.h"

/*** global ***/
//cnf_sts_t g_status;

extern int g_ocncnf_mode;

/*** function ***/
int ocncnf_term (void) {
    
    ttrchn_free(g_ocncnf_mode);
    
    return COM_OK;
}



/* end of file */
