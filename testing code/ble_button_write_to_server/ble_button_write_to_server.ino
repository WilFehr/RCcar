//this is to test the writing to the ble server

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <BLEClient.h> // Though often implicitly used by the BLEDevice library

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/
/*
563fd77b-
978c-
452e-
8b1a-
f355f13b0d25- ó U ñ ; \n % (oun)
*/
#define bleServerName "ESP32com5" // The name of the target server device

#define SERVICE_UUID "563fd77b-978c-452e-8b1a-f355f13b0d25"
#define CHARACTERISTIC_UUID "563fd77b-0000-452e-8b1a-f355f13b0d25"


//device
static BLEUUID com9ServiceUUID(SERVICE_UUID); // Service UUID
//function/data
static BLEUUID messageCharacteristicUUID(CHARACTERISTIC_UUID); // Characteristic UUID


static bool doConnect = false;
static bool connected = false;
static BLEAdvertisedDevice* myDevice;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
        // Check if the found device is the target server
        if (advertisedDevice.getName() == bleServerName) { 
            advertisedDevice.getScan()->stop(); // Stop scanning once found
            // Store the server's address for connection
            pServerAddress = new BLEAddress(advertisedDevice.getAddress());
            doConnect = true; // Set a flag to initiate connection in the main loop
        }
    }
};

//not sure if incomplete
/* the AI explination of purpose
Implement Connection Logic: Create a function to handle the actual connection 
to the server's address found in the scanning phase.
*/
bool connectToServer(BLEAddress pAddress) {
    // ... Code to create a client and connect to the server address ...
    // Once connected, get the service and characteristic to read/write/notify
    BLERemoteService* pRemoteService = pClient->getService(ServiceUUID);
    if (pRemoteService == nullptr) { /* handle error */ 
      return false;
    }
    BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(messageCharacteristicUUID);
    
    if (pRemoteCharacteristic == nullptr) { /* handle error */ 
      return false;
    }
    // ... assign callback functions for characteristics and activate notifications if needed ...
    pRemoteCharacteristic->registerForNotify(messageNotifyCallback); 
    // ... return true if successful, false otherwise ...
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BLEDevice::init("MyESP32");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic( 
    CHARACTERISTIC_UUID, 
    BLECharacteristic::PROPERTY_READ | 
    BLECharacteristic::PROPERTY_WRITE );//end of create characteristic

  pCharacteristic->setCallbacks(new MyCallbacks());
  pCharacteristic->setValue("Hello World");
  pService->start();
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();

}

void loop() {
  // put your main code here, to run repeatedly:

}
