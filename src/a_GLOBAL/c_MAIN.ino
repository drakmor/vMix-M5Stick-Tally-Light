WiFiClient client;
WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)

PinButton btnM5(37);

char currentState = -1;
char screen = 0;

char deviceName[32];
int status = WL_IDLE_STATUS;
bool apEnabled = false;
char apPass[64];

// Time measure
int interval = 5000;
unsigned long lastCheck = 0;

void setup()
{
  Serial.begin(115200);
  M5.begin();
  delay(10);
  M5.Lcd.setRotation(3);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  EEPROM.begin(512);
  SPIFFS.begin();


  start();

  server.on("/", handle_root);
  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  server.handleClient();
  btnM5.update();
  if (btnM5.isClick()) {
    if (screen == 0) {
      showNetworkScreen();
    } else if (screen == 1) {
      showTallyScreen();
    }
  }
  while (client.available())
  {
    String data = client.readStringUntil('\r\n');
    handleData(data);
  }
  
  if (!client.connected() && !apEnabled && millis() > lastCheck + interval)
  {
    client.stop();
    connectTovMix();
    lastCheck = millis();
  }
}

void cls()
{
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setCursor(0, 0);
}

void restart()
{
  saveSettings();

  Serial.println();
  Serial.println();
  Serial.println("------------");
  Serial.println("------------");
  Serial.println("RESTART");
  Serial.println("------------");
  Serial.println("------------");
  Serial.println();
  Serial.println();

  start();
}

void start()
{
  M5.Lcd.setCursor(20, 20);
  M5.Lcd.println("vMix M5Stick-C Tally");
  M5.Lcd.setCursor(35, 40);
  M5.Lcd.println("by Guido Visser");
  delay(2000);
  
  sprintf(deviceName, "vMix_Tally_%d", settings.tallyNumber);
  sprintf(apPass, "%s%s", deviceName, "_access");

  connectToWifi();

  if (WiFi.status() == WL_CONNECTED)
  {
    connectTovMix();
  }
}
