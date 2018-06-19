#include <NewPing.h>

#define SONAR_NUM 2      
#define MAX_DISTANCE 50 

NewPing sonar[SONAR_NUM] = {  
  NewPing(4, 5, MAX_DISTANCE), // trigger, echo, max distance. 
  NewPing(8, 9, MAX_DISTANCE)
};

void setup() {
  Serial.begin(9600); 
  Serial.println("-----------------------");
  }

void loop() { 
    
    Serial.print("SENSOR PING AB = ");
    float pingSensor1=sonar[0].ping_median(6);
    //float pingSensor1=sonar[0].ping();
    Serial.print(pingSensor1);
    Serial.println(" us");
    delay(1000);
    
    Serial.print("SENSOR PING BA = ");
    float pingSensor2=sonar[1].ping_median(6);
    //float pingSensor2=sonar[1].ping();
    Serial.print(pingSensor2);
    Serial.println(" us");

//https://wikimedia.org/api/rest_v1/media/math/render/svg/fef32b5ef4e6b21aa4a76e1af24085f5f1b9f778

float WaterSpeed=(0.3/2)*((pingSensor1/1000000-pingSensor2/1000000)/(pingSensor1/1000000*pingSensor2/1000000));
float error=100-(pingSensor2/pingSensor1)*100;
Serial.print("Error = ");
Serial.print(error);
Serial.println("%");

Serial.print("Water flow =");
Serial.print(WaterSpeed);
Serial.println("m/s");
Serial.println("-----------------------");

delay(1000);
}
 

