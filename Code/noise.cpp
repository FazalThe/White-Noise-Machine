

const int NOISE_PIN = 2;
const int PWM_CHANNEL = 0;
const int PWM_FREQ = 40000;  
const int PWM_RES = 8;        

uint32_t seed = 1;

void setup() {
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(NOISE_PIN, PWM_CHANNEL);

  seed = analogRead(A0) + micros();
}

void loop() {
  // Simple xorshift PRNG (fast, good for noise)
  seed ^= seed << 13;
  seed ^= seed >> 17;
  seed ^= seed << 5;

  uint8_t noise = seed & 0xFF;   
  ledcWrite(PWM_CHANNEL, noise);
}