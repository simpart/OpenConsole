/**
 * @file init.c
 * @brief  initialize application
 * @author simpart
 */
#include <stdlib.h>
#include <string.h>
#include "tetraring.h"
#include "com.h"
#include "conf.h"
#include "core.h"

/*** global ***/
extern ocncre_sts_t g_status;
int g_ocncnf_mode = TTRCHN_ID_INIT;

/*** function ***/
int ocncnf_init (void) {
    char * mode = NULL;
    int    ret  = 0;
    
    // load console name
    //strncpy(g_status.con_name, "", OCNCNF_CONNM_LEN);
    
    
    // load mode
    g_ocncnf_mode = ttrchn_create();
    __ttrchk_retng(g_ocncnf_mode);
    
    mode = (char *) ttrmem_strmloc("#", OCNCRE_MODE_LEN);
    __ttrchk_retnull(mode);
    
    ret = ttrchn_add(g_ocncnf_mode, mode);
    __ttrchk_retng(ret);
    
    /* set mode */
    strncpy(&g_status.pmpt[0], mode, strlen(mode));
    
    return COM_OK;
}



/* end of file */
