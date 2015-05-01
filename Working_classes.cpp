#include <signal.h>
#include <stdlib.h>
#include <iostream>
#include "Working_classes.h"

void Working_classes::sigfunc(int sig) {
    char c;
    if(sig != SIGINT)
        return;
    else {
        printf("\nХотите завершить программу (y/n) : ");
        while((c=getchar()) == 'n')
        return;
        exit (0);
    }
}

Working_classes::Working_classes() {
    sig_analysator = new Signature_analysis();
    stat_analysator = new Statistic_analysis();
    signal(SIGINT,sigfunc);
}

/*Working_classes::Working_classes(Signature_configurations& config) {
    sig_analysator = new Signature_analysis(config);
    stat_analysator = new Statistic_analysis();
    signal(SIGINT,sigfunc);
}*/
