// تعريف المنافذ
const int buzzerPin = 8;      // الطنان على المنفذ 8
const int ledPin = 13;        // LED على المنفذ 13
const int contactPin = 2;     // سلك المسار على المنفذ 2

void setup() {
  // تهيئة المنافذ
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(contactPin, INPUT); // مدخل بدون سحب داخلي
  
  // مقاومة السحب لأعلى خارجية (10 كيلو أوم بين المنفذ 2 و 5V)
  
  Serial.begin(9600); // لمراقبة الحالة
}

void loop() {
  int contactState = digitalRead(contactPin); // قراءة حالة التلامس
  
  Serial.print("حالة التلامس: ");
  Serial.println(contactState);
  
  // عند التلامس (الحالة 1)
  if (contactState == HIGH) {
    tone(buzzerPin, 1000); // تشغيل الطنان (1000 هرتز)
    digitalWrite(ledPin, HIGH); // تشغيل LED
    Serial.println("تم التلامس! إنذار نشط");
  }
  // عند عدم التلامس (الحالة 0)
  else {
    noTone(buzzerPin); // إيقاف الطنان
    digitalWrite(ledPin, LOW); // إطفاء LED
  }
  
  delay(50); // تأخير بسيط لتجنب الارتداد
}
