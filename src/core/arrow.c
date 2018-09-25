/**
 * @file array.c
 */
#include <stdio.h>
#include "tetraring.h"
#include "conf.h"
#include "core.h"
#include "com.h"

/*** global ***/


/*** function ***/
int ocncre_arrayctl (void) {
    int key  = 0;
    int type = 0;
    
    key = fgetc( stdin );
    if ('[' != key) {
        return COM_OK;
    }
    key = fgetc( stdin );
    if (-1 == key) {
        return COM_OK;
    }
    
    type = ttrpri_arrowtype_chr(key);
    switch (type) {
        case TTRPRI_ARROW_UP:
        case TTRPRI_ARROW_DOWN:
            /* command history */
            
            return COM_OK;
        case TTRPRI_ARROW_RIGHT:
        case TTRPRI_ARROW_LEFT:
            
            //if (posi)
            
            //ocncre_curshift(type);
            return COM_OK;
        default:
          printf("ops! %d %c\n", key, key);
    }
    
    
    return COM_NG;
}

//int ocncre_curshift(int type) {
//    type = type;
//    return COM_OK;
//}

/* end of file */
