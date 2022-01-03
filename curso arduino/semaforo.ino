//Feito em 02/02/2022, projeto de sinal de transito 

//declarando portas  do arduino 
#define green 2
#define yellow 3
#define red 4


void setup() {

//Declarando portas do arduino como saida 
pinMode(green, OUTPUT);
pinMode(red, OUTPUT);
pinMode(yellow, OUTPUT);

}

void loop() {

//Ligando e desligando led verde com a função criada abaixo
onLed(green, 600);

//Piscando led amarelo 3 vezes para sinalizar que o sinal ira fechar 
onLed(yellow, 300);

//liga led vermelho 
onLed(red, 700);

}



//função que liga e desliga os leds com o delay declarado do parametro 
int onLed(int led, int time){
  
 digitalWrite(led, HIGH);
 delay(time);
 digitalWrite(led, LOW);
 delay(time);
  
  }
