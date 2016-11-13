#ifndef CHAOS_MANAGER_H
#define CHAOS_MANGER_H

enum cmd {start, stop, restart, change_interval, change_policy};

class ChaosManager 
{
    public:
        ChaosManager(cmd comamdn); 
        ChaosManager(cmd command, int interval);
    private:
        int start_daemon();
        int kill_daemon();
        int restart_daemon();


    private:
        int command_;
        int interval_;


};
#endif
