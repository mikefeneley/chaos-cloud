#include "chaos_daemon.hpp"

/*
 * Fork off a new chaosdaemon and exit the parent funciton.
 */
ChaosDaemon::ChaosDaemon()
{
	pid_t pid;
	pid = fork();

	if(pid < 0) {
		exit(EXIT_FAILURE);
	}
	if(pid > 0) {
		exit(EXIT_SUCCESS);
	}
	if(pid == 0) {
		this->execute();
	}
}


void chaos_sighandler(int signum) {
	switch(signum) {
		case(SIGUSR1): {

		} case(SIGUSR2): {

		}
	}
}

/*
 * Configure the new chaosdaemon object.
 */ 
int ChaosDaemon::setup()
{
	umask(0);

    /* Create a new SID for the child process */
    pid_t sid = setsid();
    if (sid < 0) {
        /* Log any failure */
        exit(EXIT_FAILURE);
    }

	this->save_pid();


    /* Change the current working directory */
    if ((chdir("/")) < 0) {
        /* Log any failure here */
        exit(EXIT_FAILURE);
    }

    /*
    signal(SIGUSR1, chaos_sighandler);
    signal(SIGUSR2, chaos_sighandler);  
    raise(SIGUSR1);
    */    

    /* Close out the standard file descriptors */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
	this->save_pid();
}
/*
 * Save the PID of the chaosdaemon process in a file.
 */
int ChaosDaemon::save_pid()
{
	std::fstream pid_file;
	pid_file.open("/var/run/chaosdaemon.pid", std::fstream::out);
	
	if(!pid_file.is_open()) {
		exit(EXIT_FAILURE);
	}
	pid_file << getpid();
	pid_file << fflush;
	pid_file.close();
	return 0;
}

int ChaosDaemon::connect_local_db()
{
	
}


/*
 * Perform chaosdaemon functionality: Setup database to track items,
 * and periodically compress and encrypt items before pushing them to 
 * remote db.
 */ 
int ChaosDaemon::execute()
{
	pid_t pid = getpid();
	this->setup();
	int i = 0;

	while(1) { // Compress, Encrypt.
		sleep(30);

		i++;

		if(i == 3) {
			raise(SIGKILL);
		}


	}

}
