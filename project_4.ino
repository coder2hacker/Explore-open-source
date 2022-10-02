int yogi[]={2,3,4,5};
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  serial.begin(9600);
 }

void loop() {
  // put your main code here, to run repeatedly:
 for(int i=2;i<=5:i++)
  {
  digitalWrite(yogi[i],HIGH);
  int a= digitalRead(i);
  serial.print(a);
  
  delay(1000);
  digitalWrite(yogi[i],LOW);
   int a= digitalRead(i);
  serial.print(a);
  
  delay(1000);}
  
  
}
