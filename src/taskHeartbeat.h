
#ifndef TASK_HEARTBEAT_H
#define	TASK_HEARTBEAT_H

#ifdef	__cplusplus
extern "C" {
#endif

    extern void taskHeartbeat_init(unsigned portBASE_TYPE);
    void taskHeartbeat_Execute(void);

#ifdef	__cplusplus
}
#endif

#endif	/* TASK_HEARTBEAT_H */

