#include <iostream>
#include <new>
#include <stdlib.h>

#include "Net_sniffer.h"
#include "Signature_analysis.h"

#define SNAP_LEN 1518
#define SIZE_ETHERNET 14
#define ETHER_ADDR_LEN 6
#define UDP_LENGTH 8

using namespace std;



int main(int argc, char **argv) {
    char protocol[] = "ip";
    Working_classes wc;
    if (argc == 2) {
        Net_sniffer *obj = new Net_sniffer(argv[1], protocol, 0, "live");
        wc = obj->start_sniff();
    }
    else {
        if (argc == 3) {
            Net_sniffer *obj = new Net_sniffer(argv[1], protocol, 0, argv[2]);
            wc = obj->start_sniff();
        }
        else {
            if (argc > 3) {
                cout << "error: unrecognized command-line options\n" << endl;
                return 0;
            }
            else {
                Net_sniffer *obj = new Net_sniffer();
                wc = obj->start_sniff();
            }
        }
    }
    //Statistic_analysis * stat_analysis = new StatisticAnalysis(p.v);
    //wc.stat_analysator.print_map();
    //wc.sig_analysator.print_sessions_list();
    cout << "Capture complete" << endl;
    return 0;
};
