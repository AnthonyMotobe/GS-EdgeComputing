# Projeto de Monitoramento com Arduino Uno

Este projeto utiliza um Arduino Uno, um sensor PIR, um sensor de temperatura TMP e LEDs para detectar movimento e monitorar a temperatura ambiente. Quando o sensor PIR detecta movimento, os LEDs são acionados para alertar sobre a presença de movimento.

## Tabela de Conteúdos

1. [Integrantes](#Integrantes)
2. [Componentes](#componentes)
3. [Esquema de Ligação](#esquema-de-ligação)
4. [Conexões](#Conexões)
5. [Uso](#uso)
6. [Expansões Futuras](#Expansões_Futuras)
7. [Instalação](#instalação)

## Integrantes

 - RM: 558488 e 555342
 - Nomes: Anthony Motobe e Arthur Rodrigues

## Componentes

- Arduino Uno
- Sensor PIR (Passive Infrared Sensor)
- Sensor TMP (Sensor de Temperatura)
- LEDs (por exemplo, vermelho para alerta de movimento)
- Resistores (adequados para os LEDs)
- Protoboard e jumpers

## Esquema de Ligação

![Esquema de Ligação](https://github.com/AnthonyMotobe/GS.EdgeComputing/assets/161531653/8ab03f72-63c2-4ee6-8d74-82279b251ecc)

### Conexões:

- **Sensor PIR:**
  - VCC -> 5V no Arduino
  - GND -> GND no Arduino
  - OUT -> Pino digital 2 no Arduino

- **Sensor TMP:**
  - VCC -> 5V no Arduino
  - GND -> GND no Arduino
  - Vout -> Entrada analógica A0 no Arduino

- **LED Vermelho e Verde:**
  - Anodo (perna longa) -> Pinos digitais 3 e 4 no Arduino com resistores em série
  - Catodo (perna curta) -> GND no Arduino

## Uso

Após instalar e configurar o projeto conforme as instruções na seção de Instalação, siga os passos abaixo para operar o sistema:

1. **Inicialize o Sistema:**
   - Conecte a fonte de alimentação do Arduino (via cabo USB ou fonte externa).

2. **Monitoramento de Movimento:**
   - O sensor PIR detecta movimento em sua área de alcance. Quando o movimento é detectado, o LED vermelho acende.
   - Você pode ajustar a sensibilidade e o tempo de retardo do sensor PIR utilizando os potenciômetros no próprio sensor.

3. **Monitoramento de Temperatura:**
   - O sensor TMP monitora a temperatura ambiente continuamente.
   - Abra o Monitor Serial no Arduino IDE para visualizar a leitura da temperatura em tempo real.
     - No Arduino IDE, clique em `Ferramentas` > `Monitor Serial`.
     - Certifique-se de que a taxa de transmissão (baud rate) está configurada para 9600.

4. **Interpretação dos LEDs:**
   - **LED Vermelho Aceso:** Movimento detectado pelo sensor PIR.
   - Você pode adicionar mais LEDs e lógica para diferentes níveis de alerta, conforme necessário.

5. **Código Exemplo:**
   - Aqui está um exemplo do código que você deve carregar no Arduino para este projeto:
     // Definição dos pinos
const int pirPin = 2;      // Pino digital conectado ao sensor PIR
const int LedVermelho = 3;      // Pino digital conectado ao LED vermelho
const int LedVerde =  4; // Pino digital conectado ao LED verde
const int tempPin = A0;    // Pino analógico conectado ao sensor de temperatura

void setup() {  
  // Inicialização dos pinos dos LEDs como saída
  pinMode(LedVermelho, OUTPUT);
  pinMode(LedVerde, OUTPUT);

  // Inicialização do pino do sensor PIR como entrada
  pinMode(pirPin, INPUT);

  // Inicialização da comunicação serial para monitorar o sensor de temperatura
  Serial.begin(9600);

  // Mensagem inicial
  Serial.println("Sistema iniciado");
}

void loop() {
  // Leitura do estado do sensor PIR
  int pirState = digitalRead(pirPin);
  Serial.print("PIR State: ");
  Serial.println(pirState);

  // Controle dos LEDs baseado no estado do sensor PIR
  if (pirState == HIGH) {
    // Se movimento detectado, acende o LED vermelho
    Serial.println("Movimento detectado! Acendendo LED vermelho.");
    digitalWrite(LedVermelho, HIGH);
    digitalWrite(LedVerde, LOW);
  } else {
    // Se não há movimento, acende o LED verde
    Serial.println("Sem movimento. Acendendo LED verde.");
    digitalWrite(LedVermelho, LOW);
    digitalWrite(LedVerde, HIGH);
  }

  // Leitura do sensor de temperatura
  int tempValue = analogRead(tempPin);

  // Conversão do valor analógico para temperatura 
  float voltage = tempValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0; // Para TMP36

  // Envio da temperatura para o monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  // Atraso para não ter spam de Alertas
  delay(1000);
}

### Expansões Futuras
- **Adição de Mais Sensores:**
  - Considere adicionar outros tipos de sensores (umidade, pH, etc.) e modificar o código para integrá-los.
- **Notificações Remotas:**
  - Adicione funcionalidades para enviar notificações pelo site, quando movimento ou temperaturas anormais forem detectados.


## Instalação

1. **Clone este repositório:**
   ```bash
   git clone [https://github.com/AnthonyMotobe/GS.EdgeCompunting.git](https://github.com/AnthonyMotobe/GS-EdgeComputing)
