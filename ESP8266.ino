#include <PubSubClient.h>
#include <ESP8266WiFi.h>

//EDIT these lines to masth your setup
#define MQTT_SSERVER "192.168.1.117"  //My MQTT Broker'sIP
const char* ssid = "Fourie3";
const char* password = "mantaray";

char* Topic = "inTopic"; //subscribe to be notified about

WiFiClient wifiClient;

void setup() {
  // initialize the light as an output and set to LOW (off)

  //start the serial line for debugging
  Serial.begin(9600);
  delay(100);

  //start wifi subsystem
  WiFi.begin(ssid, password);
  //attemt to connect to the WIFI network and then connect to the MQTT server
  reconnect();

  //wait a bit before starting the mail loop
  delay(2000);
}

PubSubClient client(MQTT_SERVER, 1883, callback, wifiClient);

void loop() {

  //reconnect if connection is lost
  if (!client.connected() && Wifi.status() == 3) (reconnect();)

  //maintain MQTT connection
  client.loop();

  //Must delay to allow ESP8266 WIFI funstions to run
  delay(20);
}

void callback(char* topic, byte* payload, unsigned int length) {

  //convert topic to string to make it easier to work with
  String topicStr = topic;

  //Print out some debugging info
  //Serial.println("Callback update.");
  //Serial.println("Topic: ");
  //Serial.println(topicStr);

  //turn the light off if the payload is '0' and publish to the MQTT server a confirmation message
  if (payload[0] == '0'){
    client.publish("outTopic", "Relay 1 is ON");
    setial.print("0");}
  if (payload[0] == '1'){
    client.publish("outTopic", "Relay 1 is OFF");
    setial.print("1");}

  if (payload[0] == '2'){
    client.publish("outTopic", "Relay 2 is ON");
    setial.print("2");}
  if (payload[0] == '3'){
    client.publish("outTopic", "Relay 2 is OFF");
    setial.print("3");}

  if (payload[0] == '4'){
    client.publish("outTopic", "Relay 3 is ON");
    setial.print("4");}
  if (payload[0] == '5'){
    client.publish("outTopic", "Relay 3 is OFF");
    setial.print("5");}

  if (payload[0] == '6'){
    client.publish("outTopic", "Relay 4 is ON");
    setial.print("6");}
  if (payload[0] == '7'){
    client.publish("outTopic", "Relay 4 is OFF");
    setial.print("7");}

  if (payload[0] == '8'){
    client.publish("outTopic", "Relay 5 is ON");
    setial.print("8");}
  if (payload[0] == '9'){
    client.publish("outTopic", "Relay 5 is OFF");
    setial.print("9");}

  if (payload[0] == '10'){
    client.publish("outTopic", "Relay 6 is ON");
    setial.print("10");}
  if (payload[0] == '11'){
    client.publish("outTopic", "Relay 6 is OFF");
    setial.print("11");}

  if (payload[0] == '12'){
    client.publish("outTopic", "Relay 7 is ON");
    setial.print("12");}
  if (payload[0] == '13'){
    client.publish("outTopic", "Relay 7 is OFF");
    setial.print("13");}
}

void reconnect() {

  //attempt to connect to the wifi if connection is lost
  if (WiFi.status() != WL_CONNECTED) {
    
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Setial.print(".");
    }
  }
  //make sure we are connected to WIFI before attempting to reconnect to MQTT
  if(WiFi.status() == WL_CONNECTED){
    //Loop until we're reconnected to the MQTT server
    while (!client.connected()) {
      //Setial.print("Attempt MQTT Connection.....");

      //Generate client name based on MAC address and last 8 bits of microsecond counter
      String clientName;
      clientName += "esp8266-";
      uint8_t mac[6];
      WiFi.macAddress(mac);
      clientName += macToStr(mac);

      //if connected, subscribe to the topic(s) we want to be notified about
      if (client.connected((char*) clientName.c_str())) {
        Serial.print("\tMQTT Connected");
        client.subscribe(Topic);
      }
      //otherwise print failed for debugging
      else(Serial.println("\tFailed."); abort();}
     }
    }
  }


//generate unique name from MAC addr
String macToStr(const uint8_t* mac){

  String result;

  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);

    if (i < 5) {
      result += ':';
    }
  }

  return result;
}
