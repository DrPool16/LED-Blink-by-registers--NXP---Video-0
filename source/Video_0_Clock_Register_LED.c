#include <stdio.h>
#include <K32L2B31A.h>


void delay(void) {
	for(volatile int i=0; i < 300000; i++);
}


int main(void) {
    /* 1. Habilitar el reloj para el Puerto D y Puerto E */
    // El registro SIM->SCGC5 controla el paso de reloj a los puertos
    SIM->SCGC5 |= (SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK);

    /* 2. Configurar los pines como GPIO (Mux Alt 1) */
    // Pin Control Register (PCR). El campo MUX son los bits 8-10.
    // 001 es Alt 1 (GPIO)
    PORTD->PCR[5] = PORT_PCR_MUX(1);  // LED Verde
    PORTE->PCR[31] = PORT_PCR_MUX(1); // LED Rojo

    /* 3. Configurar los pines como SALIDA */
    // Registro PDDR (Port Data Direction Register)
    GPIOD->PDDR |= (1 << 5);
    GPIOE->PDDR |= (1 << 31);

    /* 4. Estado inicial: Apagados (Set = 1 porque son Active Low) */
    GPIOD->PSOR = (1 << 5);
    GPIOE->PSOR = (1 << 31);

    while (1) {
        // Encender Verde, Apagar Rojo
        GPIOD->PCOR = (1 << 5); // PCOR = Port Clear Output (Pone a 0)
        GPIOE->PSOR = (1 << 31); // PSOR = Port Set Output (Pone a 1)
        delay();

        // Apagar Verde, Encender Rojo
        GPIOD->PSOR = (1 << 5);
        GPIOE->PCOR = (1 << 31);
        delay();
    }

    return 0;
}
