/**
 * @file init.c
 * @brief  initialize core function
 * @author simpart
 */
#define _GNU_SOURCE

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "tetraring.h"
#include "core.h"
#include "com.h"

/*** global ***/
ocncre_sts_t g_status = {0};

/*** function ***/
int ocncre_init (void) {
    //int ret = 0;
    
    memset(&g_status, 0x00, sizeof(ocncre_sts_t));
    
    /* ignore signal */
    //ret = ocncre_ignsig();
    //__ttrchk_retng(ret);
    
    /* ignore echo */
    ocncre_ignecho();
    
    /* real time key input */
    ocncre_rtinput();
    
    return COM_OK;
}

int ocncre_ignsig (void) {
    sighandler_t sig = 0;

    /* ignore SIGINT */
    sig = signal( SIGINT , SIG_IGN );
    __ttrchk_equal(sig, SIG_ERR, "falied ignore");

    /* ignore SIGTERM */
    sig = signal( SIGTERM , SIG_IGN );
    __ttrchk_equal(sig, SIG_ERR, "falied ignore");

    /* ignore SIGQUIT */
    sig = signal( SIGQUIT , SIG_IGN );
    __ttrchk_equal(sig, SIG_ERR, "falied ignore");

    /* ignore SIGTSTP */
    sig = signal( SIGTSTP , SIG_IGN );
    __ttrchk_equal(sig, SIG_ERR, "falied ignore");
    
    return COM_OK;
}

void ocncre_ignecho (void) {
    struct termios io_conf;

    memset(&io_conf, 0x00, sizeof(struct termios));

    tcgetattr(0, &io_conf);
    io_conf.c_lflag &= ~(ECHO);  // disabled echo
    io_conf.c_cc[VMIN]  = 0;
    io_conf.c_cc[VTIME] = 1;
    tcsetattr( 0 , TCSAFLUSH , &io_conf );
}


void ocncre_rtinput (void) {
    struct termios io_conf;

    memset(&io_conf, 0x00, sizeof(struct termios));

    tcgetattr(0, &io_conf);
    io_conf.c_lflag &= ~(ICANON);  // disabled canonical
    io_conf.c_cc[VMIN]  = 0;
    io_conf.c_cc[VTIME] = 1;
    tcsetattr( 0 , TCSAFLUSH , &io_conf );
}
/* end of file */
