#include <SPI.h>
#include <Phpoc.h>

enum day { FAILURE, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };
enum day today;

void weekdayTask() {
  Serial.println("This is weekday task");
  //TODO
}

void weekendTask() {
  Serial.println("This is weekend task");
  //TODO:
}

PhpocDateTime datetime;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Phpoc.begin();

  Serial.println("Weekly Scheduling");

  datetime.date("Y-m-d D H:i:s");
  Serial.println(datetime.date());
}

void loop() {
    
  today =  datetime.dayofWeek();

  if (today == FAILURE)
    Serial.println("System Error!");
  else if ( today >= MONDAY && today <= FRIDAY)
    weekdayTask(); //Program for weekday
  else
    weekendTask(); //Program for weekkend
}
