#define BLYNK_TEMPLATE_ID "TMPL3EN8xyE5p"
#define BLYNK_TEMPLATE_NAME "Light Intensity Measure"
#define BLYNK_AUTH_TOKEN "q4CLpHHcb7MKdMHrFoRkM5BBeX0uDrmz"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define led D1
#define sensor A0
char auth[] = "q4CLpHHcb7MKdMHrFoRkM5BBeX0uDrmz";
char ssid[] = "Enter your hospot name";
char pass[] = "Enter yout hospot password";

BlynkTimer timer;


void setup()
{
  // Debug console
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(500L, sendSensor);

}

void loop()
{
  Blynk.run();
  timer.run();
}

void sendSensor()
{
  int LDR = analogRead(sensor);
    if(LDR <150)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
   
  }

  Blynk.virtualWrite(V5, LDR);

}
