
#include "daemon_manager.hpp"
#include "chaos_daemon.hpp"

DaemonManager::DaemonManager(cmd command)
{
   this->command_ = command;  
   this->manage();
}

DaemonManager::DaemonManager(cmd command, policy pol)
{
    this->command_ = command;
    this->pol_ = pol;
    this->manage();
}

int DaemonManager::manage()
{

    switch(this->command_) {
    	case start:	{
    		std::cout << "Start";
    		this->start_daemon();
    		break;
    	} case stop: {
    		std::cout << "Stop\n";
    		this->stop_daemon();
    		break;
    	} case kill_p: {
    		std::cout << "Kill\n";
    		this->kill_daemon();
    		break;
    	}case restart: {
    		std::cout << "Restart\n";
    		this->restart_daemon();
    		break;
    	} case change_int: {
    		std::cout << "Change Interval\n";
    		this->change_interval();
    		break;
    	} case change_pol: {
    		std::cout << "Change Policy\n";
    		this->change_policy();
    		break;
    	}
    }
    return -1;
}

int DaemonManager::start_daemon()
{
	ChaosDaemon *daemon = new ChaosDaemon();
	return -1;
}

int DaemonManager::stop_daemon()
{
	std::fstream pid_file;
	pid_file.open("/var/run/chaosdaemon.pid", std::fstream::in);
	if(!pid_file.is_open()) {
		return 0;
	}
	pid_t pid = 0;
	pid_file >> pid;

	pid = pid / 10;

	std::cout << pid;

	 if(pid > 0) {
    	kill(pid, SIGTERM);
 	}
 	return 1;
}

int DaemonManager::kill_daemon()
{
	return -1;
}

int DaemonManager::restart_daemon()
{
	this->stop_daemon();
	this->start_daemon();
	return 1;
}

int DaemonManager::change_interval()
{
	return -1;
}

int DaemonManager::change_policy()
{
	return -1;
}