/*
 * scheduler.c
 *
 *  Created on: Nov 13, 2022
 *      Author: phucd
 */

#include "scheduler.h"
#include "led.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;
unsigned char Error_code_G = 0;
unsigned char Last_Error_code_G = 0;
unsigned int Error_tick_count_G;
unsigned int Error_Port;
char flag_oneshot[SCH_MAX_TASKS];

void none_task(){
	return;
}

#define ERROR_SCH_INVALID_INDEX								1
#define ERROR_SCH_TOO_MANY_TASKS 							2
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK 					3
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER 	4
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START 			5
#define ERROR_SCH_LOST_SLAVE 								6
#define ERROR_SCH_CAN_BUS_ERROR 							7
#define ERROR_I2C_WRITE_BYTE_AT24C64 						8

void SCH_Init(){

	clearLED();
	clearLight();

	for(int i=0; i<SCH_MAX_TASKS;i+=1){
		flag_oneshot[i] = 0;
	}
	current_index_task = 0;
}

void SCH_Add_Task ( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD, uint8_t oneshot){
	if(current_index_task < SCH_MAX_TASKS){

		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY;
		SCH_tasks_G[current_index_task].Period =  PERIOD;
		SCH_tasks_G[current_index_task].RunMe = 0;
		SCH_tasks_G[current_index_task].TaskID = current_index_task; //using to delete task

		flag_oneshot[current_index_task] = oneshot;

		current_index_task+=1;

	}else{
		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		// if this happen then remove current index and replace it by new task.
		current_index_task-=1;
		SCH_Delete_Task(current_index_task);
		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY;
		SCH_tasks_G[current_index_task].Period =  PERIOD;
		SCH_tasks_G[current_index_task].RunMe = 0;
		SCH_tasks_G[current_index_task].TaskID = current_index_task; //using to delete task
	}
}

void SCH_Delete_Task(uint32_t task_ID){
	if(task_ID > SCH_MAX_TASKS || task_ID > current_index_task){
		Error_code_G = ERROR_SCH_INVALID_INDEX;
		return;
	}

	if(task_ID < 0 ){
		Error_code_G = ERROR_SCH_INVALID_INDEX;
		return;
	}
		SCH_tasks_G[task_ID].pTask = none_task;
		SCH_tasks_G[task_ID].Delay = 0;
		SCH_tasks_G[task_ID].Period =  0;
		SCH_tasks_G[task_ID].RunMe = 0;
}

void SCH_Update(void) {
	for (int i = 0; i < current_index_task; i+=1 ) {
			if (SCH_tasks_G[i].Delay > 0) {

				SCH_tasks_G[i].Delay -= 1;
			} else {
				// periodic
				SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
				SCH_tasks_G[i].RunMe += 1;
			}
	}
}

void SCH_Dispatch_Tasks(void) {
	if(current_index_task>0){

		for (int i = 0; i < current_index_task; ++i) {
				if (SCH_tasks_G[i].RunMe > 0) {
					SCH_tasks_G[i].RunMe -= 1;
					(*SCH_tasks_G[i].pTask)();

					//delete if task is on-shot type.
					if(flag_oneshot[i]){
						SCH_Delete_Task(i);
					}
				}
			}
	}
//	SCH_Report_Status();
	SCH_Go_to_Sleep();
}

void SCH_Go_to_Sleep(){
	// TODO: none
	// It do nothing until the next task executed

	char flag = 0;
	while(!flag){
		for (int i = 0; i < current_index_task; i+=1 ) {
				if (SCH_tasks_G[i].RunMe) {
					flag = 1;
					break;
				}
		}
	}
}

//void SCH_Report_Status(){
//	if(Error_code_G != Last_Error_code_G){
//		Error_Port = 255 - Error_code_G;
//		Last_Error_code_G = Error_code_G;
//		if(Error_code_G != 0){
//			Error_tick_count_G = 600000;
//		}
//		else{
//			Error_tick_count_G = 0;
//		}
//	}
//	else{
//		if(Error_tick_count_G != 0 ){
//			if(--Error_tick_count_G == 0){
//				Error_code_G = 0;
//			}
//		}
//	}
//}

