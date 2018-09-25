/**
 * @file init.c
 * @brief  initialize core function
 * @author simpart
 */
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "tetraring.h"
#include "conf.h"
#include "core.h"
#include "com.h"

/*** global ***/
extern ocncre_sts_t g_status;

/*** function ***/
int ocncre_start (void) {
    int  key = 0;
    
    ocn_newline();
    ocn_printf2("%s ", g_status.pmpt);
    
    while (COM_TRUE) {
        key = fgetc( stdin );

        if (-1 == key) {
            usleep(200000);
            continue;
        }
        
        if (TTR_TRUE == ttrpri_isarrow_chr(key)) {
            ocncre_arrayctl();
        } else if ('\n' == key) {
            ocn_newline();
            /* check command */
            
            /* return prompt */
            ocn_printf2("%s ", g_status.pmpt);
        } else if (127 == key) {
            ocn_printf(TTRPRI_ARWSTR_LEFT);
            ocn_printf(" ");
            ocn_printf(TTRPRI_ARWSTR_LEFT);
        } else {
            ocn_printf2_chr("%c", key);
        }
    }
   
    return COM_OK;
}



/* end of file */
