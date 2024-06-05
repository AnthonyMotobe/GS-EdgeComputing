# Projeto de Monitoramento com Arduino Uno

Este projeto utiliza um Arduino Uno, um sensor PIR, um sensor de temperatura TMP e LEDs para detectar movimento e monitorar a temperatura ambiente. Quando o sensor PIR detecta movimento, os LEDs são acionados para alertar sobre a presença de movimento.

## Tabela de Conteúdos

1. [Componentes](#componentes)
2. [Esquema de Ligação](#esquema-de-ligação)
3. [Instalação](#instalação)
4. [Uso](#uso)
5. [Contribuição](#contribuição)
6. [Licença](#licença)
7. [Contato](#contato)

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

## Instalação

1. **Clone este repositório:**
   ```bash
   git clone https://github.com/AnthonyMotobe/GS.EdgeCompunting.git
