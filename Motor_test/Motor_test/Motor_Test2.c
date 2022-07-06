/*
 * Motor_Test2.C
 *
 * Created: 2022-07-06 오후 12:48:45
 *  Author: USER
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define ROTATION_DELAY  1000  //1초대기
#define PULSE_MIN       1300  //최소펄스길이
#define PULSE_MID       3000  
#define PULSE_MAX       4700 //최대펄스길이

void INIT_TIMER1(void)
{
	//Fast PWM모드,top=ICR1
	TCCR1A |=(1 << WGM11);
	TCCR1B |=(1 << WGM12) | (1 << WGM13);
	
	TCCR1B|=(1 << CS11); //분주율 8.2MHZ
	nvbhgmffffffffffffffffffffffffffffffffffffffhmgfgmhvbvbnvbfdgch xr x
	ICR1=500; //20ms주기
	
	TCCR1A |=(1 << COM1A1); //비반전모드
	
	// OC1A(PB1, 아두이노9번 핀을 출력으로 설정
	DDRB |=(1 << PB1);
}
int main(void)
{

	INIT_TIMER1();
	
	while(1)
	{
		OCR1A = PULSE_MIN;
		_delay_ms(ROTATION_DELAY);  //0도

		OCR1A = PULSE_MID;
		_delay_ms(ROTATION_DELAY);  //90도

		OCR1A = PULSE_MAX;
		_delay_ms(ROTATION_DELAY);  //180도
	}
}