#include <HTTPClient.h>
#include <WiFi.h>


class PtzController
{

String user = "admin";
String password = "";
String putAdress = "http://192.168.1.98/";
String putAlias = "PTZ/1/";


  void init(String command)
  {
    WiFiClient client;
    HTTPClient http;

    String httpRequestData = "";
    if(command != "stop")
    {
        httpRequestData = "Param1=1&Param2=5";
    }
    else
    {
        command = "TurnRight";
        httpRequestData = "Param1=0&Param2=5";
    }

    String putCommand = putAdress + putAlias + command;
    http.begin(client,putCommand.c_str());
    http.setAuthorization(user.c_str(),password.c_str());
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    http.PUT(httpRequestData);

  }
  
public:
  void moveLeft()
  {
    init("TurnRight");
  }

  void moveRight()
  {
    init("TurnLeft");
  }

  void moveUp()
  {
    init("TurnUp");
  }

  void moveDown()
  {
      init("TurnDown");
  }

  void stopMove()
  {
    init("stop");
  }

  void gotoPreset(String preset)
  {
      WiFiClient client;
      HTTPClient http;

      String httpRequestData = "";
      String command = "Presets/Goto";
      httpRequestData = "Param1=" + preset;

      String putCommand = putAdress + putAlias + command;
      http.begin(client, putCommand.c_str());
      http.setAuthorization(user.c_str(), password.c_str());
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");

      http.PUT(httpRequestData);
  }
};