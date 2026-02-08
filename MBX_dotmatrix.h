#ifndef MBX_DOTMATRIX_H
#define MBX_DOTMATRIX_H
#include <Arduino.h>
#include <Wire.h>

#ifndef HT16K33_ADDR
#define HT16K33_ADDR 0x70
#endif

#ifndef SCROLL_MAX_CHARS
#define SCROLL_MAX_CHARS 10
#endif

static uint8_t fb[16];

void cmd(uint8_t c) {
  Wire.beginTransmission(HT16K33_ADDR);
  Wire.write(c);
  Wire.endTransmission();
}

void dotClear() {
  for (int i = 0; i < 16; i++) fb[i] = 0x00;
}

void dotShow() {
  Wire.beginTransmission(HT16K33_ADDR);
  Wire.write((uint8_t)0x00);
  for (int i = 0; i < 16; i++) Wire.write(fb[i]);
  Wire.endTransmission();
}

void dotSetBrightness(uint8_t bright) {
  if (bright > 15) bright = 15;
  cmd(0xE0 | bright);
}


void dotmatrixSetup() {
  Wire.begin();
  cmd(0x21);
  cmd(0x81);
  dotSetBrightness(2);
  dotClear();
  dotShow();
}

void setPixel(uint8_t comX, uint8_t rowY, bool on) {
  if (comX > 7 || rowY > 15) return;

  uint8_t addr = comX * 2 + (rowY >= 8 ? 1 : 0);
  uint8_t bit = (rowY >= 8) ? (rowY - 8) : rowY;

  if (on) fb[addr] |= (1 << bit);
  else fb[addr] &= ~(1 << bit);
}

void dotS(uint8_t row, uint8_t col, bool on) {
  if (row > 7 || col > 15) return;
  uint8_t yy = 7 - row;
  uint8_t xx = col;

  if (xx < 8) {
    setPixel(xx, yy, on);
  } else {
    setPixel(xx - 8, yy + 8, on);
  }
}

void dotShowAt(uint8_t row, uint8_t col, bool on) {
  dotS(row, col, on);
  dotShow();
}
static inline const uint8_t* glyph(char c) {
  if (c >= 'a' && c <= 'z') c = c - 32;


  static const uint8_t DIG0[5] = { 0x3E, 0x51, 0x49, 0x45, 0x3E };
  static const uint8_t DIG1[5] = { 0x00, 0x42, 0x7F, 0x40, 0x00 };
  static const uint8_t DIG2[5] = { 0x62, 0x51, 0x49, 0x49, 0x46 };
  static const uint8_t DIG3[5] = { 0x22, 0x41, 0x49, 0x49, 0x36 };
  static const uint8_t DIG4[5] = { 0x18, 0x14, 0x12, 0x7F, 0x10 };
  static const uint8_t DIG5[5] = { 0x2F, 0x49, 0x49, 0x49, 0x31 };
  static const uint8_t DIG6[5] = { 0x3E, 0x49, 0x49, 0x49, 0x32 };
  static const uint8_t DIG7[5] = { 0x01, 0x71, 0x09, 0x05, 0x03 };
  static const uint8_t DIG8[5] = { 0x36, 0x49, 0x49, 0x49, 0x36 };
  static const uint8_t DIG9[5] = { 0x26, 0x49, 0x49, 0x49, 0x3E };


  static const uint8_t A[5] = { 0x7E, 0x11, 0x11, 0x11, 0x7E };
  static const uint8_t B[5] = { 0x7F, 0x49, 0x49, 0x49, 0x36 };
  static const uint8_t C[5] = { 0x3E, 0x41, 0x41, 0x41, 0x22 };
  static const uint8_t D[5] = { 0x7F, 0x41, 0x41, 0x22, 0x1C };
  static const uint8_t E[5] = { 0x7F, 0x49, 0x49, 0x49, 0x41 };
  static const uint8_t F[5] = { 0x7F, 0x09, 0x09, 0x09, 0x01 };
  static const uint8_t G[5] = { 0x3E, 0x41, 0x49, 0x49, 0x7A };
  static const uint8_t H[5] = { 0x7F, 0x08, 0x08, 0x08, 0x7F };
  static const uint8_t I[5] = { 0x00, 0x41, 0x7F, 0x41, 0x00 };
  static const uint8_t J[5] = { 0x20, 0x40, 0x41, 0x3F, 0x01 };
  static const uint8_t K[5] = { 0x7F, 0x08, 0x14, 0x22, 0x41 };
  static const uint8_t L[5] = { 0x7F, 0x40, 0x40, 0x40, 0x40 };
  static const uint8_t M[5] = { 0x7F, 0x02, 0x0C, 0x02, 0x7F };
  static const uint8_t N[5] = { 0x7F, 0x04, 0x08, 0x10, 0x7F };
  static const uint8_t O[5] = { 0x3E, 0x41, 0x41, 0x41, 0x3E };
  static const uint8_t P[5] = { 0x7F, 0x09, 0x09, 0x09, 0x06 };
  static const uint8_t Q[5] = { 0x3E, 0x41, 0x51, 0x21, 0x5E };
  static const uint8_t R[5] = { 0x7F, 0x09, 0x19, 0x29, 0x46 };
  static const uint8_t S[5] = { 0x46, 0x49, 0x49, 0x49, 0x31 };
  static const uint8_t T[5] = { 0x01, 0x01, 0x7F, 0x01, 0x01 };
  static const uint8_t U[5] = { 0x3F, 0x40, 0x40, 0x40, 0x3F };
  static const uint8_t V[5] = { 0x1F, 0x20, 0x40, 0x20, 0x1F };
  static const uint8_t W[5] = { 0x3F, 0x40, 0x38, 0x40, 0x3F };
  static const uint8_t X[5] = { 0x63, 0x14, 0x08, 0x14, 0x63 };
  static const uint8_t Y[5] = { 0x07, 0x08, 0x70, 0x08, 0x07 };
  static const uint8_t Z[5] = { 0x61, 0x51, 0x49, 0x45, 0x43 };

  static const uint8_t SPACE[5] = { 0, 0, 0, 0, 0 };
  static const uint8_t DASH[5] = { 0x08, 0x08, 0x08, 0x08, 0x08 };

  if (c >= '0' && c <= '9') {
    const uint8_t* Digs[10] = { DIG0, DIG1, DIG2, DIG3, DIG4, DIG5, DIG6, DIG7, DIG8, DIG9 };
    return Digs[c - '0'];
  }

  switch (c) {
    case 'A': return A;
    case 'B': return B;
    case 'C': return C;
    case 'D': return D;
    case 'E': return E;
    case 'F': return F;
    case 'G': return G;
    case 'H': return H;
    case 'I': return I;
    case 'J': return J;
    case 'K': return K;
    case 'L': return L;
    case 'M': return M;
    case 'N': return N;
    case 'O': return O;
    case 'P': return P;
    case 'Q': return Q;
    case 'R': return R;
    case 'S': return S;
    case 'T': return T;
    case 'U': return U;
    case 'V': return V;
    case 'W': return W;
    case 'X': return X;
    case 'Y': return Y;
    case 'Z': return Z;
    case '-': return DASH;
    case ' ': return SPACE;
    default: return SPACE;
  }
}


void drawBitmap16x8(const uint16_t* bmp) {
  dotClear();

  for (uint8_t y = 0; y < 8; y++) {
    uint16_t row = bmp[y];

    for (uint8_t x = 0; x < 16; x++) {
      // bit 15 = leftmost pixel
      if (row & (1 << (15 - x))) {
        dotS(7 - y, x, true);
      }
    }
  }

  dotShow();
}


void drawChar5x7(int16_t col0, int16_t row0, char c) {
  const uint8_t* g = glyph(c);
  for (int16_t x = 0; x < 5; x++) {
    uint8_t bits = g[x];
    for (int16_t y = 0; y < 7; y++) {
      if (bits & (1 << y)) {
        int16_t col = col0 + x;
        int16_t row = row0 + y;
        if (row >= 0 && row <= 7 && col >= 0 && col <= 15) {
          dotS((uint8_t)row, (uint8_t)col, true);
        }
      }
    }
  }
}

void dotshow2Char(const char* txt) {
  dotClear();
  char c1 = (txt && txt[0]) ? txt[0] : ' ';
  char c2 = (txt && txt[1]) ? txt[1] : ' ';
  drawChar5x7(1, 0, c1);
  drawChar5x7(9, 0, c2);
  dotShow();
}

void dotshowScrollText(const char* txt, uint16_t speedMs = 80) {
  if (!txt) return;

  char buf[SCROLL_MAX_CHARS + 1];
  for (int i = 0; i < SCROLL_MAX_CHARS; i++) {
    buf[i] = txt[i] ? txt[i] : ' ';
  }
  buf[SCROLL_MAX_CHARS] = '\0';

  const int16_t textWidth = SCROLL_MAX_CHARS * 6;

  for (int16_t offset = 16; offset > -textWidth; offset--) {
    dotClear();
    int16_t col = offset;
    for (int i = 0; i < SCROLL_MAX_CHARS; i++) {
      drawChar5x7(col, 0, buf[i]);
      col += 6;
    }
    dotShow();
    delay(speedMs);
  }
}

void dotshowFirework(uint16_t speedMs = 60) {
  int launchCol = random(3, 13);
  for (int r = 7; r >= 1; r--) {
    dotClear();
    dotS(r, launchCol, true);
    dotShow();
    delay(speedMs);
  }
  const int cr = 1;
  const int cc = launchCol;
  dotClear();
  dotS(cr, cc, true);
  dotS(cr - 1, cc, true);
  dotS(cr + 1, cc, true);
  dotS(cr, cc - 1, true);
  dotS(cr, cc + 1, true);
  dotShow();
  delay(120);
  dotClear();
  for (int dr = -2; dr <= 2; dr++) {
    for (int dc = -2; dc <= 2; dc++) {
      if ((abs(dr) == 2 && abs(dc) == 0) || (abs(dc) == 2 && abs(dr) == 0) || (abs(dr) == 1 && abs(dc) == 1)) {
        int rr = cr + dr;
        int cc2 = cc + dc;
        if (rr >= 0 && rr <= 7 && cc2 >= 0 && cc2 <= 15) {
          dotS(rr, cc2, true);
        }
      }
    }
  }
  dotShow();
  delay(150);

  dotClear();
  for (int i = 0; i < 12; i++) {
    int rr = random(0, 8);
    int cc3 = random(0, 16);
    dotS(rr, cc3, true);
  }
  dotShow();
  delay(150);

  dotClear();
  dotShow();
}


void dotshowRainFall(uint16_t frames = 80, uint16_t speedMs = 60) {
  // simple falling particles
  static int8_t dropRow[16];
  static bool init = false;

  if (!init) {
    for (int c = 0; c < 16; c++) dropRow[c] = -1;
    init = true;
  }

  for (int f = 0; f < frames; f++) {
    dotClear();

    // move drops
    for (int c = 0; c < 16; c++) {
      if (dropRow[c] >= 0) dropRow[c]++;

      // respawn sometimes
      if (dropRow[c] > 7) dropRow[c] = -1;
      if (dropRow[c] < 0 && (random(0, 100) < 18)) dropRow[c] = 0;

      if (dropRow[c] >= 0 && dropRow[c] <= 7) {
        dotS(dropRow[c], c, true);
      }
    }

    dotShow();
    delay(speedMs);
  }
}



static const uint8_t blinkImg[][8] PROGMEM = {

  { B00000000, B11000000, B11111000, B01111111, B01111111, B00111111, B00111110, B00011100 },
  { B00000000, B00000000, B11111000, B01111111, B01111111, B00111111, B00111110, B00011100 },
  { B00000000, B00000000, B11111000, B01111111, B01111111, B00111111, B00111110, B00000000 },
  { B00000000, B00000000, B00000000, B01111111, B01111111, B00111111, B00000000, B00000000 },
  { B00000000, B00000000, B00000000, B00000000, B01111111, B00000000, B00000000, B00000000 },


  { B00000000, B00000011, B00011111, B11111110, B11111110, B11111100, B01111100, B00111000 },
  { B00000000, B00000000, B00011111, B11111110, B11111110, B11111100, B01111100, B00111000 },
  { B00000000, B00000000, B00011111, B11111110, B11111110, B11111100, B01111100, B00000000 },
  { B00000000, B00000000, B00000000, B11111110, B11111110, B11111100, B00000000, B00000000 },
  { B00000000, B00000000, B00000000, B00000000, B11111110, B00000000, B00000000, B00000000 }
};


static const uint8_t blinkIndex[] = { 1, 2, 3, 4, 3, 2, 1 };
#define PUPIL_W 2
#define PUPIL_H 2
#define PUPIL_Y 3
#define EYE_LEFT_X0 0
#define EYE_RIGHT_X0 8


static int16_t blinkCountdown = 100;
static int16_t gazeCountdown = 75;
static int16_t gazeFrames = 50;

static int8_t eyeX = 3;
static int8_t newX = 3;
static int8_t dX = 0;

static inline uint8_t reverse8(uint8_t b) {
  b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
  b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
  b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
  return b;
}

static inline uint16_t makeRow16(uint8_t leftRow8, uint8_t rightRow8) {

  uint8_t L = reverse8(leftRow8);
  uint8_t R = reverse8(rightRow8);
  return ((uint16_t)L << 8) | (uint16_t)R;
}

static void clearRect16(uint16_t frame[8], int x, int y, int w, int h) {
  for (int yy = y; yy < y + h; yy++) {
    if (yy < 0 || yy >= 8) continue;
    for (int xx = x; xx < x + w; xx++) {
      if (xx < 0 || xx >= 16) continue;
      frame[yy] &= ~(1U << (15 - xx));
    }
  }
}


void dotEvilEyes() {
  uint16_t frame[8];
  uint8_t idx;
  if (blinkCountdown < (int)sizeof(blinkIndex)) {
    idx = blinkIndex[blinkCountdown];
  } else {
    idx = 0;
  }
  const uint8_t* leftPtr = &blinkImg[idx][0];
  const uint8_t* rightPtr = &blinkImg[idx + 5][0];
  for (int r = 0; r < 8; r++) {
    uint8_t L = pgm_read_byte(&leftPtr[r]);
    uint8_t R = pgm_read_byte(&rightPtr[r]);
    frame[r] = makeRow16(L, R);
  }
  blinkCountdown--;
  if (blinkCountdown <= 0) {
    blinkCountdown = random(5, 180);
  }
  gazeCountdown--;
  int pupilXNow;

  if (gazeCountdown <= gazeFrames) {
    pupilXNow = newX - (dX * gazeCountdown / gazeFrames);

    if (gazeCountdown <= 0) {
      eyeX = newX;
      newX = random(3) + 3;
      dX = newX - eyeX;
      gazeFrames = random(3, 15);
      gazeCountdown = random(gazeFrames, 120);
    }
  } else {
    pupilXNow = eyeX;
  }
  if (pupilXNow < 0) pupilXNow = 0;
  if (pupilXNow > 6) pupilXNow = 6;
  clearRect16(frame, EYE_LEFT_X0 + pupilXNow, PUPIL_Y, PUPIL_W, PUPIL_H);
  clearRect16(frame, EYE_RIGHT_X0 + pupilXNow, PUPIL_Y, PUPIL_W, PUPIL_H);
  drawBitmap16x8(frame);
}


#define EYE_GAP_COLS 2
#define LEFT_EYE_X0 0
#define RIGHT_EYE_X0 9
#define EYE_W 7
#define PUPIL_W 2
#define PUPIL_H 2
#define PUPIL_Y 3


static const uint16_t EYES_OPEN[8] = {
  0x7C3E,
  0xFE7F,
  0xFE7F,
  0xFE7F,
  0xFE7F,
  0xFE7F,
  0x7C3E,
  0x0000
};


static const uint16_t EYES_HALF[8] = {
  0x0000,
  0x7C3E,
  0xFE7F,
  0xFE7F,
  0xFE7F,
  0x7C3E,
  0x0000,
  0x0000
};

static const uint16_t EYES_CLOSED[8] = {
  0x0000,
  0x0000,
  0x0000,
  0xFE7F,  // solid line across both eyes
  0x0000,
  0x0000,
  0x0000,
  0x0000
};

void clearR(uint16_t frame[8], int x, int y, int w, int h) {
  for (int yy = y; yy < y + h; yy++) {
    if (yy < 0 || yy >= 8) continue;
    for (int xx = x; xx < x + w; xx++) {
      if (xx < 0 || xx >= 16) continue;
      frame[yy] &= ~(1U << (15 - xx));
    }
  }
}

void buildEyesFrame(uint16_t out[8], const uint16_t base[8], int pupilX) {

  for (int r = 0; r < 8; r++) out[r] = base[r];
  if (pupilX < 0) pupilX = 0;
  if (pupilX > (EYE_W - PUPIL_W)) pupilX = (EYE_W - PUPIL_W);
  clearR(out, LEFT_EYE_X0 + pupilX, PUPIL_Y, PUPIL_W, PUPIL_H);
  clearR(out, RIGHT_EYE_X0 + pupilX, PUPIL_Y, PUPIL_W, PUPIL_H);
}

static int pupilX = 2;
static uint16_t blinkTimer = 0;
static uint16_t blinkWait = 1200;

void dotEyes(uint16_t frameDelayMs = 20) {
  static uint32_t last = 0;
  uint32_t now = millis();
  if (now - last < frameDelayMs) return;
  last = now;
  static uint8_t blinkPhase = 0;
  static uint16_t phaseCount = 0;

  uint16_t frame[8];
  if (blinkPhase == 0) {
    buildEyesFrame(frame, EYES_OPEN, pupilX);
    if (blinkTimer == 0) blinkTimer = now;
    if (now - blinkTimer > blinkWait) {
      blinkPhase = 1;
      phaseCount = 0;
      blinkTimer = now;
      blinkWait = random(800, 2500);
    }
  } else if (blinkPhase == 1) {
    buildEyesFrame(frame, EYES_HALF, pupilX);
    if (++phaseCount > 3) {
      blinkPhase = 2;
      phaseCount = 0;
    }
  } else if (blinkPhase == 2) {
    for (int r = 0; r < 8; r++) frame[r] = EYES_CLOSED[r];
    if (++phaseCount > 2) {
      blinkPhase = 3;
      phaseCount = 0;
    }
  } else if (blinkPhase == 3) {
    buildEyesFrame(frame, EYES_HALF, pupilX);
    if (++phaseCount > 3) {
      blinkPhase = 4;
      phaseCount = 0;
    }
  } else {
    buildEyesFrame(frame, EYES_OPEN, pupilX);
    if (++phaseCount > 2) {
      blinkPhase = 0;
      blinkTimer = now;
      phaseCount = 0;
    }
  }
  drawBitmap16x8(frame);
}



#define SNK_UP 0
#define SNK_RIGHT 1
#define SNK_DOWN 2
#define SNK_LEFT 3

static const uint8_t SNK_W = 16;
static const uint8_t SNK_H = 8;
static const uint16_t SNK_MAX = SNK_W * SNK_H;

static uint8_t snkX[SNK_MAX];
static uint8_t snkY[SNK_MAX];
static uint16_t snkLen = 0;

static uint8_t foodX = 0, foodY = 0;
static uint8_t snkDir = SNK_RIGHT;
static bool snkAlive = false;
static bool snkJustAte = false;

static uint32_t snkRng = 0xABCDEF01;

static inline uint32_t snk_rand32() {
  snkRng = snkRng * 1664525UL + 1013904223UL;
  return snkRng;
}
static inline uint8_t snk_rand8(uint8_t maxv) {
  return (uint8_t)(snk_rand32() % (uint32_t)maxv);
}

static inline bool snk_inBounds(int x, int y) {
  return (x >= 0 && x < (int)SNK_W && y >= 0 && y < (int)SNK_H);
}

static inline bool snk_isBody(uint8_t x, uint8_t y) {
  for (uint16_t i = 0; i < snkLen; i++) {
    if (snkX[i] == x && snkY[i] == y) return true;
  }
  return false;
}

static inline uint8_t snk_safeDir(uint8_t cur, uint8_t next) {
  // block reverse
  if ((cur == SNK_UP && next == SNK_DOWN) || (cur == SNK_DOWN && next == SNK_UP) || (cur == SNK_LEFT && next == SNK_RIGHT) || (cur == SNK_RIGHT && next == SNK_LEFT)) return cur;
  return next;
}

static inline void snk_spawnFood() {
  for (uint16_t tries = 0; tries < 500; tries++) {
    uint8_t x = snk_rand8(SNK_W);
    uint8_t y = snk_rand8(SNK_H);
    if (!snk_isBody(x, y)) {
      foodX = x;
      foodY = y;
      return;
    }
  }
  foodX = 0;
  foodY = 0;
}

static inline void snk_draw() {
  dotClear();

  // food
  dotS(foodY, foodX, true);

  // snake
  for (uint16_t i = 0; i < snkLen; i++) {
    dotS(snkY[i], snkX[i], true);
  }

  dotShow();
}

static inline void snk_reset() {
  snkLen = 3;
  snkDir = SNK_RIGHT;
  snkAlive = true;
  snkJustAte = false;

  snkX[0] = 5;
  snkY[0] = 4;
  snkX[1] = 4;
  snkY[1] = 4;
  snkX[2] = 3;
  snkY[2] = 4;

  snk_spawnFood();
  snk_draw();
}

static inline void snk_gameOverBlink(uint8_t times = 4) {
  for (uint8_t i = 0; i < times; i++) {
    dotClear();
    dotShow();
    delay(120);
    dotClear();
    for (uint16_t k = 0; k < snkLen; k++) dotS(snkY[k], snkX[k], true);
    dotShow();
    delay(120);
  }
}

static inline bool snk_step(uint8_t inputDir) {
  if (!snkAlive) return false;

  snkDir = snk_safeDir(snkDir, inputDir);

  int nx = (int)snkX[0];
  int ny = (int)snkY[0];

  if (snkDir == SNK_UP) ny--;
  else if (snkDir == SNK_DOWN) ny++;
  else if (snkDir == SNK_LEFT) nx--;
  else if (snkDir == SNK_RIGHT) nx++;

  if (!snk_inBounds(nx, ny)) {
    snkAlive = false;
    return false;
  }

  bool willEat = ((uint8_t)nx == foodX && (uint8_t)ny == foodY);
  snkJustAte = willEat;
  uint8_t tailX = snkX[snkLen - 1];
  uint8_t tailY = snkY[snkLen - 1];

  for (uint16_t i = 0; i < snkLen; i++) {
    if (snkX[i] == (uint8_t)nx && snkY[i] == (uint8_t)ny) {
      if (!willEat && (uint8_t)nx == tailX && (uint8_t)ny == tailY) break;
      snkAlive = false;
      return false;
    }
  }

  if (willEat && snkLen < SNK_MAX) snkLen++;

  for (int i = (int)snkLen - 1; i > 0; i--) {
    snkX[i] = snkX[i - 1];
    snkY[i] = snkY[i - 1];
  }

  snkX[0] = (uint8_t)nx;
  snkY[0] = (uint8_t)ny;

  if (willEat) snk_spawnFood();

  snk_draw();
  return true;
}

static inline bool snk_didEat() {
  return snkJustAte;
}


uint32_t snakeTimer = 0;

void playminiSnakeGame(int snakeSpeed = 200) {
  if (millis() - snakeTimer >= snakeSpeed) {
    snakeTimer = millis();
    uint8_t dir = snkDir;
    if (joyUp == 1) dir = SNK_UP;
    else if (joyDown == 1) dir = SNK_DOWN;
    else if (joyRight == 1) dir = SNK_RIGHT;
    else if (joyLeft == 1) dir = SNK_LEFT;

    bool ok = snk_step(dir);
    dotShow();
    if (ok && snk_didEat()) {
      uploadDone();
    }
    //  press cross for manual reset
    if (joyCross == 1) {
      beep();
      snk_reset();
      dotShow();
    }
  }

  delay(5);
}

#endif
