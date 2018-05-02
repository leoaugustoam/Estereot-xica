const int stepPin1 = 3;
const int dirPin1 = 4;
const int enable1 = 5;
int chave;
int tempo = 250;
int passo = 0;
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
  chave = digitalRead(9);

  if (chave) {

    Serial.println("chave ok");
    for (int i = 0; i < 100 ; i++) {
      digitalWrite(dirPin1, LOW);
      digitalWrite(stepPin1, HIGH);
      delayMicroseconds(tempo);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(tempo);
      passo++;
      Serial.println(passo);
    }
  }
  if (!chave) {
    Serial.println("chave fora");
    for (int i = 0; i < 100 ; i++) {
      digitalWrite(dirPin1, HIGH);
      digitalWrite(stepPin1, HIGH);
      delayMicroseconds(tempo);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(tempo);
      Serial.println(i);
    }

  }
}
