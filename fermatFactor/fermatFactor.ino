unsigned long start, finished, elapsed;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("FermatFactor");
  start = millis();
  Serial.println(FermatFactor(15347));
  finished = millis();
  elapsed = finished - start;
  Serial.print(elapsed);
  Serial.println(" milliseconds elapsed");
  Serial.println();
  while (1);
}


int FermatFactor(unsigned long long int oddNumber)
{

  int a = sqrt(oddNumber) + 1;
  int b2 = a * a - oddNumber;
  Serial.print(" B2: ");
  Serial.print(b2);
  Serial.print(" a: ");
  Serial.println(a);

  int tmp = sqrt(b2);
  while (tmp * tmp != b2)
  {
    a = a + 1;
    b2 = a * a - oddNumber;
    Serial.print(" B2: ");
    Serial.print(b2);
    Serial.print(" a: ");
    Serial.println(a);
    tmp = sqrt(b2);
  }

  return a + tmp;

}


