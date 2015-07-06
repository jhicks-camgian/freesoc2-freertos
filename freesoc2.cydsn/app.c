#include <stdlib.h>
#include <string.h>

#include "app.h"

size_t app_task_count;
struct app_task *app_tasks;

static int
app_task_compar(const void *l, const void *r)
{
    const struct app_task *l_p = l;
    const struct app_task *r_p = r;

    return strcmp(l_p->def->label, r_p->def->label);
}

struct app_task *
app_task_find(const char *label)
{
    struct app_task *p;
    
    p = bsearch(label, app_tasks,
                app_task_count, sizeof(app_tasks[0]), app_task_compar);
    
    return p;
}

void
app_panic(void)
{
    taskDISABLE_INTERRUPTS();
    for( ;; );
}

void
app_tasks_create(void)
{
    struct app_task *p;
    const struct app_task_def *td;
    BaseType_t rc;
    
    app_task_count = &__app_task_defs_end - __app_task_defs;
    if(app_task_count < 1)
        return;
    
    app_tasks = pvPortMalloc(sizeof(struct app_task) * app_task_count);
    if(!app_tasks)
        app_panic();

    for(p = app_tasks, td = __app_task_defs; td < &__app_task_defs_end; ++p, ++td)
    {
        p->def = td;
        rc = xTaskCreate(td->func, td->label,
                         td->stackdepth, td->parm,
                         td->priority, &p->task);
        if(rc != pdPASS)
            app_panic();        
    }
    
    qsort(app_tasks, app_task_count, sizeof(app_tasks[0]), app_task_compar);
    
}
