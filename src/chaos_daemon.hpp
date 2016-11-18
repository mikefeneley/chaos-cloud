#ifndef CHAOS_DAEMON_H
#define CHAOS_DAEMON_H

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <syslog.h>
#include <csignal>
#include <fstream>
#include <cstdlib>

class ChaosDaemon
{
	public:
		ChaosDaemon();


	private:
		int execute();
		int setup();
		int save_pid();

};



#endif