#include <ArduinoMqttClient.h>
#include <WiFiEspAT.h>

#define PIN_1A A2
#define PIN_1B A1
#define PIN_1C 4
#define PIN_1D 5
#define PIN_1E 6
#define PIN_1F 7
#define PIN_1G 8

#define PIN_2A 10
#define PIN_2B 9
#define PIN_2C A5
#define PIN_2D A4
#define PIN_2E A3
#define PIN_2F 11
#define PIN_2G 12

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = "Bruh";        // your network SSID (name)
char pass[] = "bruh1234";    // your network password (use for WPA, or use as key for WEP)

#if defined(ARDUINO_ARCH_AVR) && !defined(HAVE_HWSERIAL1)
#include "SoftwareSerial.h"
SoftwareSerial Serial1(2, 3); // RX, TX
#define AT_BAUD_RATE 9600
#else
#define AT_BAUD_RATE 115200
#endif

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "broker.hivemq.com";
int        port     = 1883;
const char topic[]  = "ats-temp";

//set interval for sending messages (milliseconds)
const long interval = 1000;
unsigned long previousMillis = 0;

int count = 0;

void setup() {
  // seven segment

  pinMode(PIN_1A, OUTPUT);
  pinMode(PIN_1B, OUTPUT);
  pinMode(PIN_1C, OUTPUT);
  pinMode(PIN_1D, OUTPUT);
  pinMode(PIN_1E, OUTPUT);
  pinMode(PIN_1F, OUTPUT);
  pinMode(PIN_1G, OUTPUT);

  pinMode(PIN_2A, OUTPUT);
  pinMode(PIN_2B, OUTPUT);
  pinMode(PIN_2C, OUTPUT);
  pinMode(PIN_2D, OUTPUT);
  pinMode(PIN_2E, OUTPUT);
  pinMode(PIN_2F, OUTPUT);
  pinMode(PIN_2G, OUTPUT);


  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial);

  Serial1.begin(AT_BAUD_RATE);
  WiFi.init(Serial1);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  int status = WiFi.begin(ssid, pass);

  if (status == WL_CONNECTED) {
    Serial.println();
    Serial.println("Connected to WiFi network.");
  } else {
    WiFi.disconnect(); // remove the WiFi connection
    Serial.println();
    Serial.println("Connection to WiFi network failed.");
  }

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();
}

void loop() {
  // call poll() regularly to allow the library to send MQTT keep alive which
  // avoids being disconnected by the broker
  mqttClient.poll();

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time a message was sent
    previousMillis = currentMillis;

    //record random value from A0, A1 and A2
    int Rvalue = analogRead(A0);

    float voltage = (float)Rvalue * 5.0;
    voltage /= 1024.0;

    Serial.print("Sending message to topic: ");
    Serial.println(topic);


    double temp = (voltage - 0.5) * 100;


    Serial.println(temp);
    int temp1, temp2;
    temp1 = (int)temp / 10;
    temp2 = (int)temp % 10;

    displayNumber1(temp1);
    displayNumber2(temp2);

    // send message, the Print interface can be used to set the message contents
    mqttClient.beginMessage(topic);
    mqttClient.print(temp);
    mqttClient.endMessage();

    Serial.println();
  }
}

void displayNumber1(int number) {
  switch (number) {
    case 0:
      digitalWrite(PIN_1A, HIGH);
      digitalWrite(PIN_1B, HIGH);
      digitalWrite(PIN_1C, HIGH);
      digitalWrite(PIN_1D, HIGH);
      digitalWrite(PIN_1E, HIGH);
      digitalWrite(PIN_1F, HIGH);
      digitalWrite(PIN_1G, LOW);
      break;
    case 1:
      digitalWrite(PIN_1A, LOW);
      digitalWrite(PIN_1B, HIGH);
      digitalWrite(PIN_1C, HIGH);
      digitalWrite(PIN_1D, LOW);
      digitalWrite(PIN_1E, LOW);
      digitalWrite(PIN_1F, LOW);
      digitalWrite(PIN_1G, LOW);
      break;
    case 2:
      digitalWrite(PIN_1A, HIGH);
      digitalWrite(PIN_1B, HIGH);
      digitalWrite(PIN_1C, LOW);
      digitalWrite(PIN_1D, HIGH);
      digitalWrite(PIN_1E, HIGH);
      digitalWrite(PIN_1F, LOW);
      digitalWrite(PIN_1G, HIGH);
      break;
    case 3:
      digitalWrite(PIN_1A, HIGH);
      digitalWrite(PIN_1B, HIGH);
      digitalWrite(PIN_1C, HIGH);
      digitalWrite(PIN_1D, HIGH);
      digitalWrite(PIN_1E, LOW);
      digitalWrite(PIN_1F, LOW);
      digitalWrite(PIN_1G, HIGH);
      break;
    case 4:
      digitalWrite(PIN_1A, LOW);
      digitalWrite(PIN_1B, HIGH);
      digitalWrite(PIN_1C, HIGH);
      digitalWrite(PIN_1D, LOW);
      digitalWrite(PIN_1E, LOW);
      digitalWrite(PIN_1F, HIGH);
      digitalWrite(PIN_1G, HIGH);
      break;
    case 5:
      digitalWrite(PIN_1A, HIGH);
      digitalWrite(PIN_1B, LOW);
      digitalWrite(PIN_1C, HIGH);
      digitalWrite(PIN_1D, HIGH);
      digitalWrite(PIN_1E, LOW);
      digitalWrite(PIN_1F, HIGH);
      digitalWrite(PIN_1G, HIGH);
      break;
    case 6:
      digitalWrite(PIN_1A, HIGH);
      digitalWrite(PIN_1B, LOW);
      digitalWrite(PIN_1C, HIGH);
      digitalWrite(PIN_1D, HIGH);
      digitalWrite(PIN_1E, HIGH);
      digitalWrite(PIN_1F, HIGH);
      digitalWrite(PIN_1G, HIGH);
      break;
    case 7:
      digitalWrite(PIN_1A, HIGH);
      digitalWrite(PIN_1B, HIGH);
      digitalWrite(PIN_1C, HIGH);
      digitalWrite(PIN_1D, LOW);
      digitalWrite(PIN_1E, LOW);
      digitalWrite(PIN_1F, LOW);
      digitalWrite(PIN_1G, LOW);
      break;
    case 8:
      digitalWrite(PIN_1A, HIGH);
      digitalWrite(PIN_1B, HIGH);
      digitalWrite(PIN_1C, HIGH);
      digitalWrite(PIN_1D, HIGH);
      digitalWrite(PIN_1E, HIGH);
      digitalWrite(PIN_1F, HIGH);
      digitalWrite(PIN_1G, HIGH);
      break;
    case 9:
      digitalWrite(PIN_1A, HIGH);
      digitalWrite(PIN_1B, HIGH);
      digitalWrite(PIN_1C, HIGH);
      digitalWrite(PIN_1D, HIGH);
      digitalWrite(PIN_1E, LOW);
      digitalWrite(PIN_1F, HIGH);
      digitalWrite(PIN_1G, HIGH);
      break;
  }
}


void displayNumber2(int number) {
  switch (number) {
    case 0:
      digitalWrite(PIN_2A, HIGH);
      digitalWrite(PIN_2B, HIGH);
      digitalWrite(PIN_2C, HIGH);
      digitalWrite(PIN_2D, HIGH);
      digitalWrite(PIN_2E, HIGH);
      digitalWrite(PIN_2F, HIGH);
      digitalWrite(PIN_2G, LOW);
      break;
    case 1:
      digitalWrite(PIN_2A, LOW);
      digitalWrite(PIN_2B, HIGH);
      digitalWrite(PIN_2C, HIGH);
      digitalWrite(PIN_2D, LOW);
      digitalWrite(PIN_2E, LOW);
      digitalWrite(PIN_2F, LOW);
      digitalWrite(PIN_2G, LOW);
      break;
    case 2:
      digitalWrite(PIN_2A, HIGH);
      digitalWrite(PIN_2B, HIGH);
      digitalWrite(PIN_2C, LOW);
      digitalWrite(PIN_2D, HIGH);
      digitalWrite(PIN_2E, HIGH);
      digitalWrite(PIN_2F, LOW);
      digitalWrite(PIN_2G, HIGH);
      break;
    case 3:
      digitalWrite(PIN_2A, HIGH);
      digitalWrite(PIN_2B, HIGH);
      digitalWrite(PIN_2C, HIGH);
      digitalWrite(PIN_2D, HIGH);
      digitalWrite(PIN_2E, LOW);
      digitalWrite(PIN_2F, LOW);
      digitalWrite(PIN_2G, HIGH);
      break;
    case 4:
      digitalWrite(PIN_2A, LOW);
      digitalWrite(PIN_2B, HIGH);
      digitalWrite(PIN_2C, HIGH);
      digitalWrite(PIN_2D, LOW);
      digitalWrite(PIN_2E, LOW);
      digitalWrite(PIN_2F, HIGH);
      digitalWrite(PIN_2G, HIGH);
      break;
    case 5:
      digitalWrite(PIN_2A, HIGH);
      digitalWrite(PIN_2B, LOW);
      digitalWrite(PIN_2C, HIGH);
      digitalWrite(PIN_2D, HIGH);
      digitalWrite(PIN_2E, LOW);
      digitalWrite(PIN_2F, HIGH);
      digitalWrite(PIN_2G, HIGH);
      break;
    case 6:
      digitalWrite(PIN_2A, HIGH);
      digitalWrite(PIN_2B, LOW);
      digitalWrite(PIN_2C, HIGH);
      digitalWrite(PIN_2D, HIGH);
      digitalWrite(PIN_2E, HIGH);
      digitalWrite(PIN_2F, HIGH);
      digitalWrite(PIN_2G, HIGH);
      break;
    case 7:
      digitalWrite(PIN_2A, HIGH);
      digitalWrite(PIN_2B, HIGH);
      digitalWrite(PIN_2C, HIGH);
      digitalWrite(PIN_2D, LOW);
      digitalWrite(PIN_2E, LOW);
      digitalWrite(PIN_2F, LOW);
      digitalWrite(PIN_2G, LOW);
      break;
    case 8:
      digitalWrite(PIN_2A, HIGH);
      digitalWrite(PIN_2B, HIGH);
      digitalWrite(PIN_2C, HIGH);
      digitalWrite(PIN_2D, HIGH);
      digitalWrite(PIN_2E, HIGH);
      digitalWrite(PIN_2F, HIGH);
      digitalWrite(PIN_2G, HIGH);
      break;
    case 9:
      digitalWrite(PIN_2A, HIGH);
      digitalWrite(PIN_2B, HIGH);
      digitalWrite(PIN_2C, HIGH);
      digitalWrite(PIN_2D, HIGH);
      digitalWrite(PIN_2E, LOW);
      digitalWrite(PIN_2F, HIGH);
      digitalWrite(PIN_2G, HIGH);
      break;
  }
}
