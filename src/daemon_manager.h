#ifndef CHAOS_MANAGER_H
#define CHAOS_MANGER_H

#include <iostream>

enum cmd {start, stop, restart, change_interval, change_policy};
enum option {interval, file, folder};

class ChaosManager 
{
    public:
        ChaosManager(cmd comamd); 
        ChaosManager(cmd command, option opt);
        
    private:
        int manager();
        int start_daemon();
        int kill_daemon();
        int restart_daemon();


    private:
        int command_;
        int opt_;
};
#endif
