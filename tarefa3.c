#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para a função sleep()



//definições dos pinos utilizados
#define LEDgreen 0 //define o LED verde
#define LEDyellow 1 //define o LED amarelo
#define LEDred 2 //define o LED vermelho
#define LEDpedestrian 3 //define o LED do pedestre
#define BUTTON 4 //define a botoeira
#define BUZZER 5 //define o buzzer



// FUNÇÕES DE CONTROLE DOS PINOS DOS LEDS E DO BUZZER
void onLED(int pino) {
    // ACENDE o LED do pino especificado
    printf("LED %d acionado\n", pino);
}

void offLED(int pino) {
    //APAGA o LED do pino especificado
    printf("LED %d apagado\n", pino);
}

void actionBuzzer() {
    // ACIONA o buzzer
    printf("Buzzer acionado\n");
}

int main() {
    int BUTTONPress = 0; // define o estado do botão pressionado como falso

    // Loop principal com while
    while (1) {
        // Estado inicial do semáforo
        onLED(LEDgreen); // acende o LED Verde dos carros
        sleep(8); // duração de 8 segundos
        onLED(LEDyellow); // acende o LED amarelo dos carros
        sleep(2); // duração de 2 segundos
        onLED(LEDred); // acende o LED Vermelho dos carros
        sleep(10); // duração de 10 segundos

        // Verifica se o botão foi pressionado
        if (BUTTONPress == 1) {
            onLED(LEDyellow); // acende o LED amarelo dos carros
            sleep(5); // duração de 5 segundos
            onLED(LEDred); // acende o LED Vermelho dos carros
            onLED(LEDpedestrian); // acende o LED Verde dos pedestres
            actionBuzzer(); // aciona o Buzzer
            sleep(15); // duração de 15 segundos
            offLED(LEDred); // desliga o LED Vermelho dos carros
            offLED(LEDpedestrian); // desliga o LED Verde dos pedestres
            actionBuzzer(); // aciona o Buzzer
            BUTTONPress == 0; // o botão volta ao estado inicial
        }
    
    }
    return 0;
}