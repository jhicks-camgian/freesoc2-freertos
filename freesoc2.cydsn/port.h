#ifndef PORT_H
#define PORT_H

/* Port layer functions that need to be copied into the vector table. */

void xPortPendSVHandler(void);
void xPortSysTickHandler(void);
void vPortSVCHandler(void);

#endif