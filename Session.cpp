#include "Session.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

using namespace std;

bool Session::operator < (const Session & b) const {
    if (ip_src.s_addr != b.ip_src.s_addr) return ip_src.s_addr < b.ip_src.s_addr;
    if (ip_dst.s_addr != b.ip_dst.s_addr) return ip_dst.s_addr < b.ip_dst.s_addr;
    if (port_src != b.port_src) return port_src < b.port_src;
    if (port_dst != b.port_dst) return port_dst < b.port_dst;
    return protocol < b.protocol;
}


void Session::print_session(){
    cout << "From ip:   " << inet_ntoa(ip_src) << endl;
    cout << "To ip:     " << inet_ntoa(ip_dst) << endl;
    cout << "From port: " << ntohs(port_src) << endl;
    cout << "To port:   " << ntohs(port_dst) << endl;
    cout << "Protocol   " << prot << endl;
    cout << endl;
}
