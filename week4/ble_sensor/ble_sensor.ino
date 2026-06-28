#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22      // Change to DHT11 on real hardware

DHT dht(DHTPIN, DHTTYPE);

BLECharacteristic *tempCharacteristic;
BLECharacteristic *humCharacteristic;
BLECharacteristic *timeCharacteristic;

#define SERVICE_UUID      "12345678-1234-1234-1234-1234567890AB"
#define TEMP_UUID         "12345678-1234-1234-1234-1234567890AC"
#define HUM_UUID          "12345678-1234-1234-1234-1234567890AD"
#define TIME_UUID         "12345678-1234-1234-1234-1234567890AE"

void setup(){
  Serial.begin(115200);
  dht.begin();
  BLEDevice::init("ESP32 Weather Station");
  BLEServer *server = BLEDevice::createServer();
  BLEService *service = server->createService(SERVICE_UUID);

  tempCharacteristic =
  service->createCharacteristic(
      TEMP_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY );

  humCharacteristic =
  service->createCharacteristic(
      HUM_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY);

  timeCharacteristic =
  service->createCharacteristic(
      TIME_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY);

  tempCharacteristic->addDescriptor(new BLE2902());
  humCharacteristic->addDescriptor(new BLE2902());
  timeCharacteristic->addDescriptor(new BLE2902());

  service->start();
  BLEAdvertising *advertising = BLEDevice::getAdvertising();
  advertising->start();}

void loop(){

  float t = dht.readTemperature();
  float h = dht.readHumidity();
  String timeStamp = String(millis());

  tempCharacteristic->setValue(String(t).c_str());
  humCharacteristic->setValue(String(h).c_str());
  timeCharacteristic->setValue(timeStamp.c_str());

  tempCharacteristic->notify();
  humCharacteristic->notify();
  timeCharacteristic->notify();

  delay(3000);}