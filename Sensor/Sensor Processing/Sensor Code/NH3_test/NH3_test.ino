#define NH3_pin A15

int NH3 = 0;

  // put your setup code here, to run once:
  

}

void loop() {
  // put your main code here, to run repeatedly:
  NH3 = analogRead(NH3_pin);
  Serial.println(NH3);

}
