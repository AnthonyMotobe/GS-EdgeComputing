# Projeto de Monitoramento com Arduino Uno

Este projeto utiliza um Arduino Uno, um sensor PIR, um sensor de temperatura TMP e LEDs para detectar movimento e monitorar a temperatura ambiente. Quando o sensor PIR detecta movimento, os LEDs são acionados para alertar sobre a presença de movimento.

## Tabela de Conteúdos

1. [Integrantes](#Integrantes)
2. [Componentes](#componentes)
3. [Esquema de Ligação](#esquema-de-ligação)
4. [Conexões](#Conexões)
5. [Uso](#uso)
6. [Expansões Futuras](#Expansões-Futuras)
7. [Instalação](#instalação)

## Integrantes

 - RM: 558488 e 555342
 - Nomes: Anthony Motobe e Arthur Rodrigues

## Componentes

- Arduino Uno
- Sensor PIR (Passive Infrared Sensor)
- Sensor TMP (Sensor de Temperatura)
- LEDs (por exemplo, vermelho para alerta de temperatura)
- Resistores (adequados para os LEDs)
- Protoboard e jumpers

## Esquema de Ligação

![Esquema de Ligação](https://github.com/AnthonyMotobe/GS.EdgeComputing/assets/161531653/8ab03f72-63c2-4ee6-8d74-82279b251ecc)


Link para acesso ao tinkercad:
https://www.tinkercad.com/things/2alWbcqObCa-copy-of-terrific-bojo/editel?sharecode=ULMN7RzIR4x7xO5ffgWC7xdrg5SeeVDhuZpTBz5lWqc

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
     ```cpp
     // Define os pinos dos sensores e LEDs
     const int pirPin = 2;       // Pino digital conectado ao sensor PIR
     const int tmpPin = A0;      // Pino analógico conectado ao sensor TMP
     const int ledPin = 3;       // Pino digital conectado ao LED

     void setup() {
       pinMode(pirPin, INPUT);   // Configura o pino do PIR como entrada
       pinMode(ledPin, OUTPUT);  // Configura o pino do LED como saída
       Serial.begin(9600);       // Inicializa a comunicação serial
     }

     void loop() {
       // Leitura do sensor PIR
       int pirState = digitalRead(pirPin);
       if (pirState == HIGH) {
         digitalWrite(ledPin, HIGH); // Acende o LED se o PIR detectar movimento
       } else {
         digitalWrite(ledPin, LOW);  // Apaga o LED se não houver movimento
       }

       // Leitura do sensor TMP
       int tmpValue = analogRead(tmpPin);
       float voltage = tmpValue * (5.0 / 1023.0);  // Converte a leitura para tensão
       float temperatureC = (voltage - 0.5) * 100; // Converte a tensão para temperatura em Celsius

       // Imprime a temperatura no Monitor Serial
       Serial.print("Temperatura: ");
       Serial.print(temperatureC);
       Serial.println(" °C");

       delay(1000); // Espera 1 segundo antes de fazer a próxima leitura
     }
     ```

### Expansões Futuras
- **Adição de Mais Sensores:**
  - Considere adicionar outros tipos de sensores (umidade, pH, etc.) e modificar o código para integrá-los.
- **Notificações Remotas:**
  - Adicione funcionalidades para enviar notificações pelo site, quando movimento ou temperaturas anormais forem detectados.


## Instalação

1. **Clone este repositório:**
   ```bash
   git clone [https://github.com/AnthonyMotobe/GS.EdgeCompunting.git](https://github.com/AnthonyMotobe/GS-EdgeComputing)
