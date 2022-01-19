/*

data: 18/01/2022
author: DARKnx#6070
creditos: Guaxinim#2753
descrição: Calculadora simples com arduino, teclado matricial e lcd
componentes usados: arduino uno, teclado matricial 4x4, lcd 16x2 azul, potenciometro 5k, protoboard, resistor 1k
*/


#include <LiquidCrystal.h>
#include <Keypad.h>



byte pinosColunas[] = {6,7,A1,A0}; //pinos colunas 
byte pinosLinhas[] =   {2,3,4,5}; //pinos linhas 

//mapeamento das teclas
char teclas[4][4] = {{'1','2','3', '+'},
                     {'4','5','6', '-'},
                     {'7','8','9', 'x'},
                     {'c','0','=', '/'}};

//usando biblioteva Keypad para iniciar o teclado
Keypad teclado = Keypad( makeKeymap(teclas), pinosLinhas, pinosColunas, 4, 4);  
//declarando o display lcd 
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);


int currentNum, result, n, i = 0;
int end, fase = false;
char operador = '\0';


void setup() {
  
  lcd.begin(16,2);
  reset();
  Serial.begin(9600);
  Serial.println("Calculadora com arduino");
}


void eval() {
   if(operador == '+') {
     result += currentNum;
     currentNum = 0;
   } else if(operador == '-') {
     result -= currentNum;
     currentNum = 0;
   } else if(operador == 'x') {
     result *= currentNum;
     currentNum = 0;
   } else if(operador == '/') {
     result /= currentNum;
     currentNum = 0;
   }
}

void loop() {

char tecla = teclado.getKey();
if (!tecla) return;

//iniciando o switch
switch(tecla) {
  
case '0'...'9': {

  if (end) reset();
  int num = atoi(&tecla);
  currentNum = currentNum * 10 + num;
  if (fase == false) n++; else i++;
  updateLCD();
    
break;
}
case 'c':
  reset();     
break;

case '+':
case '-':
case 'x':
case '/':
case '=':


  if(operador == '\0'){
    // se o operador antigo por '\0', quer dizer que é o primeiro operador a ser apertado
    result = currentNum;
    currentNum = 0;
    fase = true;
  } else {
    // se a pessoa já tiver clicado em um operadoro arduino faz a conta
    eval();
  }
       
  if(tecla == '=') {
    lcd.setCursor(1,1);
    lcd.print(result);
    operador = '\0';
    currentNum,result,n,i = 0;
    end = true;
  } else {
    operador = tecla;
    updateLCD();
  }
  
break;
        
      
}//switch
  
}


int updateLCD (){


if (operador == '\0'){
   lcd.setCursor(0,0);
   lcd.print(currentNum);
  } else {

   if ( currentNum == 0){
    
 lcd.setCursor(0,0);
 lcd.print(result);
 lcd.setCursor(n,0);
 lcd.print(operador);   

   
    } else {

 lcd.setCursor(0,0);
 lcd.print(result);
 lcd.setCursor(n,0);
 lcd.print(operador);
 lcd.setCursor((n+1),0);
 lcd.print(currentNum);

      }
}
}
int reset(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("0");
    lcd.setCursor(0, 1);
    lcd.print("=");

    operador = '\0';
    fase, end = false;
    currentNum, result, n, i = 0;
}


