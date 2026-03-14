#include <stdio.h>
#include <K32L2B31A.h>

/*CLOCK CONFIGURATIONS*/
#define SIM_BASE  			0x40048000
#define SIM_SCGC5_OFFSET	0x38

#define PORTE_BASE			0x4004D000
#define PORTE_31			0x7C

#define GPIO_BASE			0x400FF000
#define GPIOE_PDDR			0x114
#define GPIOE_PSOR			0x104
#define GPIOE_PCOR			0x108


// Creamos un puntero que apunta exactamente a esa dirección de memoria
volatile uint32_t *mi_reloj_manual = (uint32_t *)(SIM_BASE + SIM_SCGC5_OFFSET);
volatile uint32_t *port_31 = (uint32_t *)(PORTE_BASE + PORTE_31);
volatile uint32_t *gpioe_pddr = (uint32_t *)(GPIO_BASE + GPIOE_PDDR);
volatile uint32_t *gpioe_psor = (uint32_t *)(GPIO_BASE + GPIOE_PSOR);
volatile uint32_t *gpioe_pcor = (uint32_t *)(GPIO_BASE + GPIOE_PCOR);

int main(void) {

	*mi_reloj_manual |= (1<<13);	// 13 habilita el clock para el PORTE
	*port_31 |= (1<<8);				// 8 habilita el MUX
	*gpioe_pddr |= (1<<31);			// El LED rojo esta en PTE31 , habilita pin 31 (salida)
	*gpioe_psor |= (1<<31);			// Pone el pin 31 en 1, es decir, 3.3V


	while(1){

		*gpioe_pcor = (1<<31);

		for(volatile int i=0; i < 500000; i++); //delay

		*gpioe_psor = (1<<31);

		for(volatile int i=0; i < 500000; i++); //delay
	}



    return 0 ;
}
