const int stepPin1 = 3;
const int dirPin1 = 4;
const int enable1 = 5;
int chave;
int tempo = 100;
long int passo = 0;
String recebido;
int valorA = 0;
int filtrado;

int valor = 0;

int valorfinal = 0;
String leStringSerial() {
  String conteudo = "";
  char caractere;

  while (Serial.available() > 0) {
    caractere = Serial.read();
    if (caractere != '\n') {
      conteudo.concat(caractere);
    }
    delay(10);
  }

  Serial.print("Recebi UNO: ");
  Serial.println(conteudo);

  return conteudo;
}


void setup() {
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(9, INPUT);
  digitalWrite(9, HIGH);
    digitalWrite(enable1, LOW);
  Serial.begin(115200);
}
void loop() {

  if (Serial.available() > 0) {
    recebido = leStringSerial();
  }

  if (recebido == "mx") {
    digitalWrite(enable1, HIGH);
    Serial.println("Parado");
  }
  if (recebido == "mp") {
    digitalWrite(enable1, HIGH);
    Serial.println(passo);
  }

  if (recebido == "ms") {
    digitalWrite(enable1, HIGH);
    valorA = 0;
    valor = 0;
    valorfinal = 0;
    for (int i = 0; i <= 2500; i++) {
      valorA = analogRead(A1);
      valor = valor + valorA;
    }
    valorfinal = valor / 2500;
    valorfinal = map(valorfinal, 1023, 0, 1000, 0);
    //valorfinal=valorfinal-5;
    Serial.println(valorfinal);
    delay(200);
  }

  if (recebido == "m1") {
    digitalWrite(enable1, LOW);
    for (int i = 0; i < 100 ; i++) {
      digitalWrite(dirPin1, LOW);
      digitalWrite(stepPin1, HIGH);
      delayMicroseconds(tempo);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(tempo);
      passo++;
      //Serial.println(passo);
    }
  }
  if (recebido == "m0") {
    digitalWrite(enable1, LOW);
    for (int i = 0; i < 100 ; i++) {
      digitalWrite(dirPin1, HIGH);
      digitalWrite(stepPin1, HIGH);
      delayMicroseconds(tempo);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(tempo);
      passo--;
      //Serial.println(passo);
    }
  }

}
