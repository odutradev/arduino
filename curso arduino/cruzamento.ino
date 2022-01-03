//02/02/2022,  semaforos duplos

#define green 2
#define yellow 3
#define red 4

#define verde 5
#define amarelo 6
#define vermelho 7



void setup() {

 pinMode(green, OUTPUT);
 pinMode(yellow, OUTPUT);
 pinMode(red, OUTPUT);

 pinMode(verde, OUTPUT);
 pinMode(amarelo, OUTPUT);
 pinMode(vermelho, OUTPUT);
 
}

void loop() {
 
digitalWrite(red, HIGH);
digitalWrite(vermelho, HIGH);
reset(1000);

digitalWrite(green, HIGH);
digitalWrite(vermelho, HIGH);
reset(3000);

digitalWrite(yellow, HIGH);
digitalWrite(vermelho, HIGH);
reset(500);

digitalWrite(yellow, HIGH);
digitalWrite(vermelho, HIGH);
reset(500);

digitalWrite(red, HIGH);
digitalWrite(vermelho, HIGH);
reset(1000);

digitalWrite(red, HIGH);
digitalWrite(verde, HIGH);
reset(3000);

digitalWrite(red, HIGH);
digitalWrite(amarelo, HIGH);
reset(500);

digitalWrite(red, HIGH);
digitalWrite(amarelo, HIGH);
reset(500);
}



   int reset(int time){

  int valores []{green, yellow, red, verde, amarelo, vermelho};
  delay(time);
  
    for (int x : valores){
      digitalWrite(x, LOW);
    }
  delay(50);
    } 
