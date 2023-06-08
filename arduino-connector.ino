float Vin = 5; // Volt
float R = 221; // Ohm
float R1, R2, R3, R4, R5, R6; // Ohm
float t1, t2, t3, t4, t5, t6; // °C


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  R1 = R/((1024.0/analogRead(A0))-1);
  R2 = R/((1024.0/analogRead(A1))-1);
  R3 = R/((1024.0/analogRead(A2))-1);
  R4 = R/((1024.0/analogRead(A3))-1);
  R5 = R/((1024.0/analogRead(A4))-1);
  R6 = R/((1024.0/analogRead(A5))-1);
  float R0 = 100; float Rcof = 0.38;
  t1 = (R1-R0)/Rcof; t2 = (R2-R0)/Rcof; t3 = (R3-R0)/Rcof;
  t4 = (R4-R0)/Rcof; t5 = (R5-R0)/Rcof; t6 = (R6-R0)/Rcof;

  //t1 = R1; t2 = R2; t3 = R3; t4 = R4; t5 = R5; t6 = R6;
  Serial.print(t1);
  Serial.print(",");
  Serial.print(t2);
  Serial.print(",");
  Serial.print(t3);
  Serial.print(",");
  Serial.print(t4);
  Serial.print(",");
  Serial.print(t5);
  Serial.print(",");
  Serial.println(t6);
  delay(3000);
}
