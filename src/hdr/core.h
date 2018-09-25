/**
 * @file conf.h
 * @brief defined config
 * @author simpart
 */

#ifndef __OCN_CORE_H__
#define __OCN_CORE_H__

/*** define ***/
#define OCNCRE_CONNM_LEN 32   //! console name length
#define OCNCRE_MODE_LEN  4    //! mode length
#define OCNCRE_CMD_LEN   256  //! command length

/*** struct ***/
typedef struct ocncre_sts {
    char con_name[OCNCRE_CONNM_LEN];
    char pmpt[OCNCRE_MODE_LEN];
    int  posi;
} ocncre_sts_t;


/*** prototype ***/
/* init */
int  ocncre_init    (void);
int  ocncre_ignsig  (void);
void ocncre_ignecho (void);
void ocncre_rtinput (void);
/* ctrl */
int  ocncre_start   (void);
/* array */
int ocncre_arrayctl (void);
int ocncre_curshift (int);
#endif
/* end of file */
