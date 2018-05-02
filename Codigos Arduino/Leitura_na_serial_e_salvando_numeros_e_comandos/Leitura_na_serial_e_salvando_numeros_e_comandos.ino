#define TAM 50


char v[TAM];
char n[TAM];
int rec;
String msgfloat = "";
int i = 0;
int j = 0;
float num = 0;
int flag;

void setup() {
  Serial.begin(115200);
}

void loop() {

  flag = 0;
  rec = 0;
  msgfloat = "";
  for (i = 0; i < TAM; i++) {
    n[i] = 'k'; v[i] = 'k';
  }
  if (Serial.available() > 0) {
    Serial.readBytesUntil('k', v, TAM);
    Serial.print(v);
   /* Serial.println("inicio da leitura: ");
    for (i = 0; i < 20; i++) {
      Serial.println(v[i]);
    }*/

    //for (j = 0; v[j] != 'x' && flag == 0; j++) {
      if ((v[j] == 'M' || v[j] == 'm' ) && (v[j + 1] == 'X' || v[j + 1] == 'x' )) {
        for (int i = 3; i < 20; i++) {//as 2 primeiras posiçoes ja ocupadas e a 3 é o espaço
          rec = v[i];
          Serial.println(v[i]);
          msgfloat += (char)rec;
          delay(10);
        }
        Serial.print("msg: ");
        Serial.println(msgfloat);
        num = msgfloat.toFloat();
        Serial.print("numero: ");
        Serial.println(num);
        Serial.println(num + 5.25);
        flag = 1;
      }
    //}
  }
}
