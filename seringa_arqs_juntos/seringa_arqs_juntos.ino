//exemplo de entrada:
//Q300T5X
//300ml, 5min
char leitura[50];
char quant[25];
int abilitar;
long int qt;
long int temp;
String recebido;
long int passo = 0;
int posq;
int post;
int posfinal;
int flagok;
const int stepPin1 = 3;
const int dirPin1 = 4;
const int enable1 = 5;
double tpassos;
long int microtemp;
int flagencher;

void setup() {
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(enable1, OUTPUT);
  Serial.begin(115200);//ABRIR O SERIAL MONITOR E COLOCAR NOVA LINHA
  digitalWrite(enable1, HIGH);
  posq = 0;
  post = 0;
  posfinal = 0;
  flagok = 0;
  flagencher = 0;
}


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
  Serial.print("Recebi: ");
  Serial.println(conteudo);
  return conteudo;
}


void loop() {
  recebido = "                                                                    ";
  if (Serial.available() > 0) {
    recebido = leStringSerial();
  }

  recebido.toCharArray(leitura, 50);
  for (int i = 0; i < 50; i++) {
    if (leitura[i] == 'Q') {
      posq = i;
    }
    if (leitura[i] == 'T') {
      post = i;
    }
    if (leitura[i] == 'X') {
      posfinal = i;
      flagok = 1;
    }
  }


  if (flagok == 1) {
    /*Serial.print("Posicao Q:");
      Serial.print(posq);
      Serial.print("Posicao T:");
      Serial.print(post);
      Serial.print("Posicao X:");
      Serial.println(posfinal);*/
    for (int i = posq; i < post - 1; i++) {
      quant[i - posq] = leitura[i + 1];
    }

    qt = atol(quant);
    Serial.println("quant");
    //Serial.println(quant);
    Serial.println(qt);

    char tempo[25];
    for (int i = post; i < posfinal - 1; i++) {
      tempo[i - post] = leitura[i + 1];
    }
    //Serial.println();

    if (tempo[0] == 'E') {

      //Serial.println("encher seringa");
      flagencher = 1;
    }
    temp = atol(tempo);
    Serial.println("tempo");
    //Serial.println(tempo);
    Serial.println(temp);



    if (qt > 0 && flagencher == 0) {
      tpassos = ((double)(temp * 300000)) / (double)qt;
      microtemp = tpassos * 100;


      if (microtemp > 30000) {
        microtemp = microtemp / 1000;
        Serial.println("TEMPO POR PASSO no delay: ");
        Serial.println(microtemp);
        // Serial.println("TEMPO total: ");
        //Serial.println((microtemp*24600)/60000000);

        digitalWrite(enable1, LOW);
        for (int i = 0; i < qt ; i++) {
          digitalWrite(dirPin1, LOW);
          digitalWrite(stepPin1, HIGH);
          delay(microtemp);
          digitalWrite(stepPin1, LOW);
          delay(microtemp);
          passo++;
          //Serial.println(passo);
          }
        Serial.println(passo);
      }
      else {

        Serial.println("TEMPO POR PASSO: ");
        Serial.println(microtemp);
        // Serial.println("TEMPO total: ");
        //Serial.println((microtemp*24600)/60000000);

        digitalWrite(enable1, LOW);
        for (int i = 0; i < qt ; i++) {
          digitalWrite(dirPin1, LOW);
          digitalWrite(stepPin1, HIGH);
          delayMicroseconds(microtemp);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(microtemp);
          passo++;
          //Serial.println(passo);
          }
        Serial.println(passo);
      }

    }
    if (qt < 0 && flagencher == 0) {
      tpassos = ((double)(temp * 300000)) / (double)(-qt);
      microtemp = tpassos * 100 ;
      if (microtemp > 30000) {
        microtemp = microtemp / 1000;
        Serial.println("PASSOS POR TEMPO no delay: ");
        Serial.println(microtemp);
        //Serial.println("TEMPO PARA 1 PASSO: ");
        //Serial.println(microtemp);
        digitalWrite(enable1, LOW);
        for (int i = 0; i > qt ; i--) {
          digitalWrite(dirPin1, HIGH);
          digitalWrite(stepPin1, HIGH);
          delay(microtemp);
          digitalWrite(stepPin1, LOW);
          delay(microtemp);
          passo--;
          //Serial.println(passo);
          }
        Serial.println(passo);
      }
      else {
        Serial.println("PASSOS POR TEMPO: ");
        Serial.println(microtemp);
        //Serial.println("TEMPO PARA 1 PASSO: ");
        //Serial.println(microtemp);
        digitalWrite(enable1, LOW);
        for (int i = 0; i > qt ; i--) {
          digitalWrite(dirPin1, HIGH);
          digitalWrite(stepPin1, HIGH);
          delayMicroseconds(microtemp);
          digitalWrite(stepPin1, LOW);
          delayMicroseconds(microtemp);
          passo--;
          //Serial.println(passo);
          }
        Serial.println(passo);
      }




    }



    if (qt > 0 && flagencher == 1) {
      digitalWrite(enable1, LOW);
      for (int i = 0; i < qt ; i++) {
         digitalWrite(dirPin1, LOW);
         digitalWrite(stepPin1, HIGH);
         delayMicroseconds(150);
         digitalWrite(stepPin1, LOW);
         delayMicroseconds(150);
         passo++;
        flagencher = 0;
         //Serial.println(passo);
        }
      Serial.println(passo);
    }
    if (qt < 0 && flagencher == 1) {
      digitalWrite(enable1, LOW);
      for (int i = 0; i > qt ; i--) {
        digitalWrite(dirPin1, HIGH);
        digitalWrite(stepPin1, HIGH);
        delayMicroseconds(150);
        digitalWrite(stepPin1, LOW);
        delayMicroseconds(150);
        passo--;
        flagencher = 0;
        //Serial.println(passo);
        }
      Serial.println(passo);
    }




    flagok = 0;
  }


  for (int i = posq; i < post; i++) {
    quant[i - posq] = leitura[i];

  }

}

