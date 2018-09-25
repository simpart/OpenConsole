/**
 * @file com.h
 * @brief defined common
 * @author simpart
 */

#ifndef __OCN_COM_H__
#define __OCN_COM_H__

/*** define ***/
/**
 * @brief value of function return
 */
#define COM_OK  0  //! function is successful
#define COM_NG -1  //! function is failed

/**
 * @brief flag value
 */
#define COM_TRUE  1
#define COM_FALSE 0

/**
 * @biref print parameter type
 */
#define OCNPRI_TYPE_STR  0x200
#define OCNPRI_TYPE_CHAR 0x201
#define OCNPRI_TYPE_INT  0x202
//#define OCNPRI_TYPE_CHAR 0x200

/*** prototype ***/
int ocn_init (void);
int ocn_term (void);
/* print */
void ocn_printf      (char *);
void ocn_printf2     (char *, void *);
void ocn_printf2_chr (char *, int);
void ocn_newline     (void);
#endif
/* end of file */
