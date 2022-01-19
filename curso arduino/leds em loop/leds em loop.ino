//Feito em 02/02/2022, programa liga e desliga 2 leds em loop

#define ledDelay 250
#define green 2  
#define red 3

     
void setup() {
  
  //declarando portas do arduino como: entrada/saida
  pinMode(green, OUTPUT); 
  pinMode(red, OUTPUT);

    }


    
void loop() {

    //ligando led red e desligando led verde
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(ledDelay);

    //desligando led red e ligando led verde
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    delay(ledDelay);

}
