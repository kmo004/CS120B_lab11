/*	Author: kmo004
 *  Partner(s) Name: Michael Wen
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

typedef struct _task {
	signed char state;
	unsigned long int period;
	unsigned long int elapsedTime;
	int (*TickFct)(int);
	
} task;

unsigned char led0_output = 0x00;
unsigned char led1_output = 0x00;
unsigned char pause = 0;

enum pauseButtomSM_States {pauseButton_wait, pauseButton_press, pauseButton_release};

int pauseButtonSMTick(int state){
	unsigned char press = ~PINA & 0x01;
	
	switch(state){
		case pauseButton_wait:
			state = press == 0x01? pauseButton_press:pauseButton_wait; break;
		case pauseButton_press:
			state = pauseButton_release; break;
		case pauseButton_release:
			state = press == 0x00? pauseButton_wait: pauseButton_press; break;
		default: state = pauseButton_wait; break;
	}
	
	switch(state) {
		case pauseButton_wait:break;
		case pauseButton_press:
			pause = (pause ==0) ?1:0;
			break;
		case pauseButton_release: break;
	}
	return state;
}

enum toggleLED0_States {toggleLED0_wait, toggleLED0_blink};

int toggleLED0SMTick(int state){
	switch (state) {
		




int main(void) {
    /* Insert DDR and PORT initializations */
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTD = 0x00;
	
	
    /* Insert your solution below */
    static_task task1, task2, task3, task 4;
    _task *tasks[] = { &task1, &task2, &task3, &task4 };
    const unsigned short numTasks = sizeof[tasks]/sizeof(task*);
    
    
	task1.state = start;
	task1.period = 50;
	task1.elapsedTime = task1.period;
	task1.TickFct = &pauseButtonToggleSMTick;
	
	task2.state = start;
	task2.period = 500;
	task2.elapsedTime = task2.period;
	task2.TickFct = &toggleLED0SMTick;
	
	task3.state = start;
	task3.period = 1000;
	task3.elapsedTime = task3.period;
	task3.TickFct = &toggleLED1SMTick;
	
	task4.state = start;
	task4.period = 10;
	task4.elapsedTime = task4.period;
	task4.TickFct = &SMTick4;
	
	TimerSet{GCD}
	TimerOn();
	
	unsigned short i;
	
	while(1) {
		for( i = 0; i < numTasks; i++) {
			if( tasks[i] -> elapsedTime == tasks[i] -> period){
				tasks[i]->state = task[i]->TickFct(tasks[i]->state);
				tasks[i]->elapsedTime = 0;
			}
			tasks[1]->elapsedTime += GCD;
			
		}
		while(!TimerFlag);
		TimerFlag = 0;
	}
	return 0;
}
unsigned long int findGCD(unsigned long int a, unsigned long int b){
	unsigned long int c;
	while(1){
		c = a%b;
		if(c == 0){return b;}
		a = b;
		b = c;
	}
	return 0;
}

unsigned long GCD = tasks[0]->period;
	for (i = 1; i < numTasks; i++){
		GCD findGCD(GCD,tasks[i]->period);
}


	
