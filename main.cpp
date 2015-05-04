#include <iostream>
#include <new>
#include <stdlib.h>
#include <fstream>


#include "Net_sniffer.h"
#include "Signature_analysis.h"

#define SNAP_LEN 1518
#define SIZE_ETHERNET 14
#define ETHER_ADDR_LEN 6
#define UDP_LENGTH 8

using namespace std;

int main(int argc, char **argv) {
    string filter_expr = "ip";
    Working_classes wc;
    if (argc == 2) {
        Net_sniffer *obj = new Net_sniffer(argv[1], filter_expr, true);
        try {
            obj->start_sniff(&wc);
        }
        catch (Net_sniffer_exception *e) {
            cout << e->get_exception_reason() << endl;
        }
        delete obj;
    }
    else {
        if (argc == 3) {
            bool mode = true;
            if (strcmp(argv[2], "offline") == 0) {
                mode = false;
            }
            Net_sniffer *obj = new Net_sniffer(argv[1], filter_expr, mode);
            try {
                obj->start_sniff(&wc);
            }
            catch (Net_sniffer_exception *e) {
                cout << e->get_exception_reason() << endl;
            }
            delete obj;
        }
        else {
            if (argc > 3) {
                cout << "error: unrecognized command-line options\n" << endl;
                return 0;
            }
            else {
                Net_sniffer *obj = new Net_sniffer();
                try {
                    obj->start_sniff(&wc);
                }
                catch (Net_sniffer_exception *e) {
                    cout << e->get_exception_reason() << endl;
                }
                delete obj;
            }
        }
    }
    return 0;
};
