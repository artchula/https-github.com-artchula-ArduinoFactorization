unsigned long start, finished, elapsed;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

int gcd( int a,  int b) {
  int remainder;
  while (b != 0) {
    remainder = a % b;
    a = b;
    b = remainder;
  }
  return a;
}



void loop() {
  unsigned long int  number =  8;
  int x_fixed = 2, cycle_size = 2, x = 2, factor = 1;

  Serial.println("    PollardRHO method");

    int  roundStep =0;
  while (factor == 1) {
    for (int count = 1; count <= cycle_size && factor <= 1; count++) {

    roundStep ++;
      x = (x * x + 1) % number;
      factor = gcd(x - x_fixed, number);
      int xmod = x % 101;
      int xfixedmod = x_fixed % 101;


      Serial.print(" roundStep  ");
      Serial.print(roundStep);

      Serial.print(", x = ");
      Serial.print(x);

      Serial.print(",  x_fixed = ");
      Serial.print(x_fixed);

      Serial.print(",  x mod 101 = ");
      Serial.print(xmod);

      Serial.print(",  x_fixed mod 101 = ");
      Serial.println(xfixedmod);
    }

    cycle_size *= 2;
    x_fixed = x;
    Serial.println("-----------------");

  }
  Serial.print(" Number is  ");
  Serial.println(number);

  Serial.print(" Factor is  ");
  Serial.println(factor);


  finished = millis();
  elapsed = finished - start;
  Serial.print(elapsed);
  Serial.println(" milliseconds elapsed");
  Serial.println();
  while (1);
  while (1);
}


