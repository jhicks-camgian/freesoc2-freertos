#ifndef APP_H

#include <stddef.h>

#include "FreeRTOS.h"
#include "task.h"
    
struct app_task_def
{
    const char *label;
    TaskFunction_t func;
    unsigned short stackdepth;
    void *parm;
    UBaseType_t priority;
};

struct app_task
{
    const struct app_task_def *def;
    TaskHandle_t task;
};

#define APP_TASK_DECL(LABEL, FUNC, STKDEPTH, PARM, PRI) \
    static const struct app_task_def \
      __attribute__((section(".app.task.defs"))) \
    APP_TASK_##LABEL = {        \
        .label = #LABEL,        \
        .func  = FUNC,          \
        .stackdepth = STKDEPTH, \
        .parm = PARM,           \
        .priority = PRI,        \
    }

extern struct app_task_def __app_task_defs[];
extern struct app_task_def __app_task_defs_end;

extern size_t app_task_count;
extern struct app_task *app_tasks;

void app_panic(void);
void app_tasks_create(void);
struct app_task * app_task_find(const char *);
#endif
