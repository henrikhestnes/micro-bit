#include "uart.h"
#include "gpio.h"
#include <stdint.h>

#define UART ((NRF_UART_REG*)0x40002000)
#define __BUTTON_A_PIN__ 17
#define __BUTTON_B_PIN__ 26


typedef struct {
	volatile uint32_t STARTRX;
	volatile uint32_t STOPRX;
	volatile uint32_t STARTTTX;
	volatile uint32_t STOPTX;
   	volatile uint32_t RESERVED1[3];
	volatile uint32_t SUSPEND;
	volatile uint32_t RESERVED2[56];
	volatile uint32_t CTS;
	volatile uint32_t NCTS;
	volatile uint32_t RXDRDY;
	volatile uint32_t RESERVED3[4];
    volatile uint32_t TXDRXY;
	volatile uint32_t RESERVED4[1];
	volatile uint32_t ERROR;
	volatile uint32_t RESERVED5[7];
	volatile uint32_t RXTO;
	volatile uint32_t RESERVED6[110];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile uint32_t RESERVED7[93];
	volatile uint32_t ERRORSRC;
	volatile uint32_t RESERVED8[31];
	volatile uint32_t ENABLE;
	volatile uint32_t RESERVED9[1];
	volatile uint32_t PSELRTS;
	volatile uint32_t PSELTXD;
	volatile uint32_t PSELCTS;
   	volatile uint32_t PSELRXD;
	volatile uint32_t RXD;
	volatile uint32_t TDX;
	volatile uint32_t RESERVED10[1];
	volatile uint32_t BAUDRATE;
	volatile uint32_t RESERVED[17];
	volatile uint32_t CONFIG;


} NRF_UART_REG;


void uart_init(){
	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[__BUTTON_A_PIN__] = 0;
	GPIO->PIN_CNF[__BUTTON_B_PIN__] = 0;

    UART->PSELTXD = 24;
    UART->PSELRXD = 25;

    UART->PSELCTS = 0xFFFFFFFF;
    UART->PSELRTS = 0xFFFFFFFF;

    UART->BAUDRATE = 0x00275000;

    UART->ENABLE = 4;
    UART->STARTRX = 1;
}

void uart_send(char letter){

}

char uart_read(){

}