

#include "daemon_manager.hpp"
#include <boost/program_options.hpp>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
using namespace boost::program_options;

int main(int argc, char *argv[])
{

    options_description desc{"Options"};
	
    int flags, opt;
    int nsecs, tfnd;

    nsecs = 0;
    tfnd = 0;
    flags = 0;
    while ((opt = getopt(argc, argv, "o:")) != -1) {
        switch (opt) {
        case 'o':
            nsecs = atoi(optarg);
            tfnd = 1;
            break;
        default: /* '?' */
            fprintf(stderr, "Usage: %s [-o option]\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if(nsecs == 1) {
    	DaemonManager *manager = new DaemonManager(start);
    } else if(nsecs == 2) {
        DaemonManager *manager = new DaemonManager(stop);
    }


    return 0;
}
