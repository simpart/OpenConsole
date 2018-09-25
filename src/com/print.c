/**
 * @file print.c
 * @brief common stdout function
 * @author simpart
 */
/*** include ***/
#include <stdio.h>
#include <string.h>
#include "tetraring.h"
#include "core.h"
#include "com.h"

/*** global ***/
extern ocncre_sts_t g_status;

/*** function ***/
void ocn_printf (char *str) {
    if (NULL == str) {
        return;
    }
    int posi   = strnlen(str, OCNCRE_CMD_LEN);
    int arw_tp = ttrpri_arrowtype(str);
    switch (arw_tp) {
        case TTRPRI_ARROW_UP:
        case TTRPRI_ARROW_DOWN:
            /* ignore up,down key */
            return;
        case TTRPRI_ARROW_RIGHT:
            posi = 1;
            break;
        case TTRPRI_ARROW_LEFT:
            posi = -1;
            break;
    }
    
    printf("%s", str);
    fflush(stdout);
    g_status.posi += posi;
}

void ocn_printf2 (char *str, void *prm) {
    if ((NULL == str) || (NULL == prm)) {
        return;
    }
    
    char buf[OCNCRE_CMD_LEN] = {0};
    __ttrstr_init(buf);
    
    snprintf(buf, OCNCRE_CMD_LEN-1, str, prm);
    ocn_printf(&buf[0]);
}

void ocn_printf2_chr (char *str, int prm) {
    if (NULL == str) {
        return;
    }
    
    char buf[OCNCRE_CMD_LEN] = {0};
    __ttrstr_init(buf);
    
    snprintf(buf, OCNCRE_CMD_LEN-1, str, prm);
    ocn_printf(&buf[0]);
}

void ocn_newline(void) {
    printf("\n");
    fflush(stdout);
    g_status.posi = 0;
}
/* end of file */
