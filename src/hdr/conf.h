/**
 * @file conf.h
 * @brief defined config
 * @author simpart
 */

#ifndef __OCN_CONF_H__
#define __OCN_CONF_H__

/*** define ***/
//#define OCNCNF_CONNM_LEN 32  //! console name length
//#define OCNCNF_MODE_LEN  4   //! mode length

/*** struct ***/
//typedef struct cnf_sts {
//    char con_name[OCNCNF_CONNM_LEN];
//    char mode[OCNCNF_MODE_LEN];
//} cnf_sts_t;

/*** prototype ***/
int ocncnf_init   (void);
int ocncnf_term   (void);

#endif
/* end of file */
