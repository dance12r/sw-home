#include <ESP8266WiFi.h> // подключение библиотеки ESP8266
#include <BlynkSimpleEsp8266.h> // подключение библиотеки Blynk
#include <SimpleTimer.h> // подключение таймера
#include <DHT.h> // подключение бибилиотеки датчика DHT

#define DHTTYPE DHT22 // или DHT22
#define DHTPIN 4 // к какому GPIO подключен датчик DHT

char auth[] = "41ccb9e4914d4e889f6c7f102498af44"; // указать токен сгенерированый при добавлении проекта на сервере Blynk

DHT dht(DHTPIN, DHTTYPE); // инициализируем датчик DHT

SimpleTimer timer; // объявление переменной таймера

// Эта функция отсылает данные кадую сикунду на виртуальные пины.
// В приложении виджеты должны быть настроены на PUSH. Это ознчает
// что тут вы определяете как часто отправлять данные в приложение.
void sendUptime()
{
  // Вы можете отправлять данные в любое время.
  // Но не отправляйте больше 10 значений в секунду.
  Blynk.virtualWrite(V10, dht.readTemperature()); // температура, виртуальный пин 10
  Blynk.virtualWrite(V11, dht.readHumidity()); // влажность, виртуальный пин 11
  Blynk.virtualWrite(V1, analogRead(A0)); // освещенность, фоторезистор, виртуальный пин 1
  delay(2000); // задержка
}

void setup()
{
  dht.begin();
  //Blynk.begin(auth, "home", "qwertyui", IPAddress(192,168,200,2)); // введите здесь свою WIFI сеть и пароль, а так же IP адресс сервера Blynk
  Blynk.begin(auth, "home", "qwertyui");
  
  timer.setInterval(2000, sendUptime);
}

void loop()
{
  Blynk.run(); // запуск Blynk
  timer.run(); // запуск таймера
}
