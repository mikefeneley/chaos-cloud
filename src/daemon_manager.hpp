#ifndef DAEMON_MANAGER_H
#define DAEMON_MANAGER_H


enum cmd {start, stop, kill_p, restart, change_int, change_pol};
enum policy {};



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
