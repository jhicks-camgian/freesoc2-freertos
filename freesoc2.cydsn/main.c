
#include "app.h"
#include "device.h"
#include "FreeRTOS.h"
#include "port.h"
#include "task.h"

void
vApplicationMallocFailedHook(void)
{
    /* The heap space has been execeeded. */
    app_panic();
}

void
vApplicationStackOverflowHook(void)
{
    /* The stack space has been overflowed */
    app_panic();
}


static void
prvInstallVectors(void)
{
    /* Install the OS Interrupt Handlers. */
    CyRamVectors[11] = (cyisraddress) vPortSVCHandler;
    CyRamVectors[14] = (cyisraddress) xPortPendSVHandler;
    CyRamVectors[15] = (cyisraddress) xPortSysTickHandler;
}

int
main(void)
{
    prvInstallVectors();
    app_tasks_create();
    vTaskStartScheduler();
    
    /*NOTREACHED*/
    for(;;);
}
