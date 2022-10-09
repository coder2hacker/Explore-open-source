void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  serial.begin(9600);
 }

void loop() {
  // put your main code here, to run repeatedly:
 
  
  digitalWrite(13,HIGH);
  int a= digitalRead(13);
  serial.print(a);
  
  delay(1000);
  digitalWrite(13,LOW);
   int a= digitalRead(13);
  serial.print(a);
  
  delay(1000);
  
  
}
