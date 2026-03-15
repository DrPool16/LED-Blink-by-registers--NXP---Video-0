#include <stdio.h>
#include <K32L2B31A.h>

/*CLOCK CONFIGURATIONS*/
#define SIM_SCGC5_OFFSET	0x40048038  	// System Clock Gating Control Register 5 (SIM_SCGC5)

/*PORTS CONFIG*/
#define LED_RED				0x4004D07C 		//LED RED 		PORTE 31U
#define LED_GREEN			0x4004C014 		//LED GREEN 	PORTD 5U

/*GPIOS CONFIG*/
#define GPIOE_PDDR			0x400FF114 		//PDDR	(OUTPUT = 0 o INPUT = 1) - Port Data Direction
#define GPIOE_PSOR			0x400FF104		//PSOR 	(3.3V = 1)      - Port Set Output
#define GPIOE_PCOR			0x400FF108		//PCOR 	(0V = 1)		- Port Clear Output

#define GPIOD_PDDR			0x400FF0D4
#define GPIOD_PSOR			0x400FF0C4
#define GPIOD_PCOR			0x400FF0C8


// We create a pointer that points exactly to that memory address
volatile uint32_t *my_clock = (uint32_t *)(SIM_SCGC5_OFFSET);

volatile uint32_t *PORT_R = (uint32_t *)(LED_RED);
volatile uint32_t *PORT_G = (uint32_t *)(LED_GREEN);

volatile uint32_t *PDDR_E = (uint32_t *)(GPIOE_PDDR);
volatile uint32_t *PSOR_E = (uint32_t *)(GPIOE_PSOR);
volatile uint32_t *PCOR_E = (uint32_t *)(GPIOE_PCOR);

volatile uint32_t *PDDR_D = (uint32_t *)(GPIOD_PDDR);
volatile uint32_t *PSOR_D = (uint32_t *)(GPIOD_PSOR);
volatile uint32_t *PCOR_D = (uint32_t *)(GPIOD_PCOR);


int main(void) {

	*my_clock |= ((1<<12) | (1<<13));				// 12 and 13 habilita el clock para el PORTD and PORTE correspondientement
	*PORT_R |= (1<<8);								// 8 habilita el MUX (alt 1) = GPIO mode
	*PORT_G |= (1<<8);								// 8 habilita el MUX (alt 1) = GPIO mode

	*PDDR_E |= (1<<31);								// El LED rojo esta en PTE31 , habilita pin 31 (salida)
	*PSOR_E |= (1<<31);								// Pone el pin 31 en 3.3V = TURN OFF
	*PCOR_E |= (1<<31);								// Pone el pin 31 en OV   = TURN ON

	*PDDR_D |= (1<<5);								// El LED rojo esta en PTD5 , habilita pin 5 (salida)
	*PSOR_D |= (1<<5);								// Put pin 5 en 3.3V = TURN OFF
	*PCOR_D |= (1<<5);								// Put el pin 5 en OV   = TURN ON


	while(1){

		*PCOR_E = (1<<31);
		*PSOR_D = (1<<5);
		for(volatile int i=0; i < 300000; i++); //delay

		*PSOR_E = (1<<31);
		*PCOR_D |= (1<<5);
		for(volatile int i=0; i < 300000; i++); //delay
	}



    return 0 ;
}
