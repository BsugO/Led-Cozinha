/*
 Name:		Led_Cozinha.ino
 Created:	4/12/2019 4:06:54 PM
 Author:	PTL00023-PAN006
*/
// *************************************************
//  Projeto Arduino - LED
//  Fita de LED com 4 reles
//  Alarme com Arduino e sensor de movimento PIR
//
//              HRinnovation V 1.0
// *************************************************
//---------------------------- VARIAVEIS------------------------------
int aux = 7;
int contador = 0;
long distancia;
long tempo;
int Infra_Red;
//------------------------------ SETUP--------------------------------
void setup() {
	// put your setup code here, to run once:
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	//pinMode(9, OUTPUT);  //PULSE
	//pinMode(8, INPUT);   //Trigger
	pinMode(10, INPUT);     //IR
	// pinMode(6, INPUT);
	Serial.begin(9600);
}
void Ligar() {
	for (int x = 2; x < 6; x++) {
		digitalWrite(x, HIGH);
		contador = contador - 2;
		delay(250);
	}
}
void Apagar() {
	for (int y = 2; y < 6; y++) {
		aux = aux - 1;
		digitalWrite(aux, LOW);
		delay(500);
	}
	aux = 6;
}
void HC_SR() {
	digitalWrite(9, LOW);
	delayMicroseconds(2);
	digitalWrite(9, HIGH);
	delayMicroseconds(10);
	tempo = pulseIn(8, HIGH);
	distancia = tempo / 29.1 / 2;
}
void Infra() {
	Infra_Red = digitalRead(10);
	delay(10);

}
//---------------------------- MAIN SOFTWARE------------------------------
void loop() {
	//HC_SR();
	Infra();
	if (Infra_Red >= 1) {
		Ligar();
		Infra();
	}
	if (contador > 200) {
		Apagar();
		Infra();
		contador = 0;
	}
	Serial.print("estado do contador : ");
	Serial.println(contador);
	Serial.print("estado do IR : ");
	Serial.println(Infra_Red);
	delay(250);
	contador = contador + 1;
}