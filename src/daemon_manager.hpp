#ifndef DAEMON_MANAGER_H
#define DAEMON_MANGER_H

enum cmd {start, stop, kill, restart, change_int, change_pol};
enum policy {};

#include <iostream>


class DaemonManager 
{
    public:
        DaemonManager(cmd comamd); 
        DaemonManager(cmd command, policy pol);

    private:
        int manage();
        int start_daemon();
        int stop_daemon();
        int kill_daemon();
        int restart_daemon();
        int change_interval();
        int change_policy();

    private:
        cmd command_;
        policy pol_;
};
#endif
