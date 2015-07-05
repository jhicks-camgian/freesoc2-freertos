#include "app.h"
#include "FreeRTOS.h"
#include "task.h"

static void
flasher_task_entry(void *parm)
{
    (void) parm;
    int j;

    for(j = 0 ;; j = !j)
    {
        vTaskDelay(100);

        LED_Pin_Write(j);
    }
}

APP_TASK_DECL(FLASHER, flasher_task_entry, 64, 0, 10);