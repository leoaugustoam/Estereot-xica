//exemplo de entrada:
//Q300T5X
//300ml, 5min
char leitura[50];
char quant[25];
int abilitar;
long int qt;
long int temp;
String recebido;
int posq;
int post;
int posfinal;
int flagok;

void setup() {
  Serial.begin(115200);//ABRIR O SERIAL MONITOR E COLOCAR NOVA LINHA
  posq = 0;
  post = 0;
  posfinal = 0;
  flagok = 0;
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
    Serial.print("Posicao Q:");
    Serial.print(posq);
    Serial.print("Posicao T:");
    Serial.print(post);
    Serial.print("Posicao X:");
    Serial.println(posfinal);
    for (int i = posq; i < post - 1; i++) {
      quant[i - posq] = leitura[i + 1];
    }

    qt = atol(quant);
    Serial.println("quant");
    Serial.println(quant);
    Serial.println(qt);

    char tempo[25];
    for (int i = post; i < posfinal - 1; i++) {
      tempo[i - post] = leitura[i + 1];
    }
    Serial.println();
    temp = atol(tempo);
    Serial.println("tempo");
    Serial.println(tempo);
    Serial.println(temp);
    
    Serial.println("tempo+10");
    Serial.println(temp+10);
    Serial.println("tempo+990");
    Serial.println(temp+990);
    flagok = 0;
  }


  for (int i = posq; i < post; i++) {
    quant[i - posq] = leitura[i];

  }
  //ci = atoi(SuaString);








  if (recebido == "LED1:1") {
    Serial.println("if 1");
    digitalWrite(13, HIGH);
  }
  if (recebido == "LED1:0") {
    Serial.println("if 2");
    digitalWrite(13, LOW);
  }
}

