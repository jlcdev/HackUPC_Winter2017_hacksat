void setup() {
  //Init Serial communication; Experiment only use the serial Tx and Rx for send any data to CubeSAT.
  Serial1.begin(9600);
}

void loop() {
  //Fake example data for send
  const char *msg = "Telemetry: Fake data 04/03/2017";
  Serial1.write(msg, strlen(msg));
  //Time between data submission to SAT
  delay(100);
}
