#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);

int distancia;

#define roda_da_direita_1 2
#define roda_da_ESQUERDA_1 3

#define roda_da_direita_2 4
#define roda_da_ESQUERDA_2 5

void setup(){
  pinMode(roda_da_direita_1 , OUTPUT);
  pinMode(roda_da_ESQUERDA_1 , OUTPUT);
  pinMode(roda_da_direita_2 , OUTPUT);
  pinMode(roda_da_ESQUERDA_2 , OUTPUT);

  delay(2000);//DELAY DE INICIO
}
void loop(){

  distancia = ultrasonic.read();

if ( distancia <=35 && distancia >=11) {// SE A DISTANCIA ESTIVAR ENTRE 35 E 11 FAÇA O DESVIO 
  if (random (1 ,2 + 1) ==1){ // IRÁ SORTEAR A DIREÇÃO
    digitalWrite(roda_da_ESQUERDA_2, LOW);//DIREITA
    digitalWrite(roda_da_direita_1, HIGH);

    digitalWrite(roda_da_direita_2, LOW);
    digitalWrite(roda_da_ESQUERDA_1, LOW);
    delay(100);

    }else{
    digitalWrite(roda_da_ESQUERDA_2,HIGH);//ESQUERDA
    digitalWrite(roda_da_direita_1, LOW);

    digitalWrite(roda_da_direita_2, LOW);
    digitalWrite(roda_da_ESQUERDA_1,LOW);
    delay(100);
    }
  }else{ 
    digitalWrite(roda_da_ESQUERDA_2, HIGH);// FRENTE      
    digitalWrite(roda_da_direita_1, HIGH);

    digitalWrite(roda_da_direita_2, LOW);
    digitalWrite(roda_da_ESQUERDA_1, LOW);
  }
if ( distancia <=10 && distancia >=1) { //SE A DISTACIA FOR MENOR QUE 10 VAI DAR RÉ
    digitalWrite(roda_da_ESQUERDA_2, LOW);//RÉ     
    digitalWrite(roda_da_direita_1, LOW);

    digitalWrite(roda_da_direita_2, HIGH);
    digitalWrite(roda_da_ESQUERDA_1, HIGH);
    delay(600);
  }
  delay(50);
}
