#include <stdlib.h>

#include "FreeRTOS.h"
#include "timers.h"
#include "task.h"

#include "../mcc_generated_files/pin_manager.h"


#define taskPRIORITY        0
#define taskSTACK_SIZE      512

/*****************************************************************************

    Private functions prototype

*****************************************************************************/
static portTASK_FUNCTION(vHeartbeatTask, pvParameters);

/*****************************************************************************

    FreeRTOS Task implementation

*****************************************************************************/
static inline void vCreatNewTasks(unsigned portBASE_TYPE uxPriority)
{
    xTaskCreate(vHeartbeatTask, (char const*)"taskName", (uint16_t)taskSTACK_SIZE/(uint16_t)(2), NULL, uxPriority, (TaskHandle_t *) NULL );
}

/*****************************************************************************

    Public functions implementation.

*****************************************************************************/
void taskHeartbeat_Execute(void)
{
    portENTER_CRITICAL();
    {
        IO_RB15_Toggle();        //Toggle signal
    }
    portEXIT_CRITICAL();
}

static portTASK_FUNCTION(vHeartbeatTask, pvParameters)
{
    /* Just to stop compiler warnings. */
    (void) pvParameters;

    //===========================================
    //Task entrance
    //===========================================
    while(1)
    {
        vTaskDelay(500);
        IO_RB15_Toggle();
    }
}