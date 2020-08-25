// Koden får en led til at blinke når der er bevægelse foran sensoren og printer dens value til serial monitor

const int knap = 4;             // Sætter knap lig med dens pin
const int led = 3;              // Sætter led lig med dens pin
int sensor = 7;                 // Sætter sensor lig med dens pin
int pirState = LOW;             // Starter med at antage at sensorens state er lav
int val = 0;                    // Variabel for statusen for sensoren

void setup() {
  Serial.begin(9600);           // Just some prep for reading stuff in the serial monitor
  pinMode(knap, INPUT);         // Sætter min knap som input
  pinMode(sensor, INPUT);       // Sætter min sensor som input
  
  Serial.println("Hey, I'm working here");  // printer random shit så jeg ved tingen kører

}

void loop() {
  val = digitalRead(sensor);    // Læser sensorens state og klemmer det ind i variablen val
  
  if (val == HIGH) {            // Hvis val er høj så kør den her kode
    
    digitalWrite(led, HIGH);    // Tænd led'en
    if (pirState == LOW) {      // Hvis pirState er lav så kør det her
      Serial.println(val);      // Printer sensorens værdi i serial monitoren
      Serial.println("Der er noget lort foran mig!");     // Print det her når noget bevæger sig ind foran sensoren
      pirState = HIGH;          // Sæt pirState til høj
      
    }
  } else {                      // Hvis alt går galt så bare bliv ved med at køre den her kode
    digitalWrite(led, LOW);     // Sluk for led'en
    if (pirState == HIGH){      // Kør det her hvis pirState er høj
      Serial.println(val);      // Printer sensorens værdi i serial monitoren
      Serial.println("Lorten flyttede sig fra mit åsyn");     // Print noget når der ikke længere er noget foran sensoren
      pirState = LOW;           // Sæt pirState til lav
      
    }
  }
}
