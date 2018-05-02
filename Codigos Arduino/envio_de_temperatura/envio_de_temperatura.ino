#define TAM 25


char v[TAM];
char n[TAM];
int rec;
String msgfloat = "";
int i = 0;
int j = 0;
float num = 0;
int flag;
String msgEnvio = "";
char msg[20];
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

    if ((v[j] == 'T' || v[j] == 't' )) {
      for (int i = 1; i < 20; i++) {//as 2 primeiras posiçoes ja ocupadas e a 3 é o espaço
        rec = v[i];
        msgfloat += (char)rec;
        //Serial.print(rec);
        delay(10);
      }
      //Serial.print("msg: ");
      //Serial.println(msgfloat);
      num = msgfloat.toFloat();
      msgEnvio = "T";
      msgEnvio.concat(num);
      //Serial.print("numero: ");
      //Serial.println(num);
      //Serial.println(num + 5.25);
      msgEnvio.toCharArray(msg, msgEnvio.length()+1);
      //Serial.println(msgEnvio);
      //Serial.write('l');
      Serial.write(msg);
    }
  }






/*
Serial.println("T20.12");
delay(1000);
Serial.println("T25.16");
delay(1000);
Serial.println("T40.79");
delay(1000);
Serial.println("T120.90");
delay(1000);
Serial.println("T80.99");
delay(1000);*/
}
