#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {A3, A2, A1, A0};

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String buffer = "";
int mode = 0;      // 0=menu, 1=calc, 2=parallel, 3=ohm
char ohmTarget = 0;
float ohmA = 0, ohmB = 0;

void showMenu() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1:Calc 2:||R");
  lcd.setCursor(0,1);
  lcd.print("3:OhmLaw");
  mode = 0;
  buffer = "";
}

float evalSimple(String expr) {
  char op;
  int idx = -1;

  for (int i = 0; i < expr.length(); i++) {
    if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
      op = expr[i];
      idx = i;
      break;
    }
  }

  if (idx == -1) return 0;

  float a = expr.substring(0, idx).toFloat();
  float b = expr.substring(idx + 1).toFloat();

  if (op == '+') return a + b;
  if (op == '-') return a - b;
  if (op == '*') return a * b;
  if (op == '/') return a / b;
  return 0;
}

float parallelRes(String expr) {
  int idx = expr.indexOf('+');
  float r1 = expr.substring(0, idx).toFloat();
  float r2 = expr.substring(idx + 1).toFloat();
  return 1.0 / ((1.0 / r1) + (1.0 / r2));
}

void setup() {
  lcd.init();
  lcd.backlight();
  showMenu();
}

void loop() {
  char key = keypad.getKey();
  if (!key) return;

  if (key == 'C') {
    showMenu();
    return;
  }

  // MENU
  if (mode == 0) {
    if (key == '1') {
      mode = 1;
      lcd.clear();
      lcd.print("Calc:");
    } 
    else if (key == '2') {
      mode = 2;
      lcd.clear();
      lcd.print("|| Res:");
    } 
    else if (key == '3') {
      mode = 3;
      lcd.clear();
      lcd.print("Find V I R");
      lcd.setCursor(0,1);
      lcd.print("Press + - *");
    }
    return;
  }

  // OHM TARGET SELECTION
  if (mode == 3 && ohmTarget == 0) {
    if (key == '+') ohmTarget = 'V';
    if (key == '-') ohmTarget = 'I';
    if (key == '*') ohmTarget = 'R';
    lcd.clear();
    lcd.print("Enter 2 vals");
    lcd.setCursor(0,1);
    lcd.print("Use +");
    buffer = "";
    return;
  }

  // INPUT HANDLING
  if (key != '=') {
    buffer += key;
    lcd.setCursor(0,1);
    lcd.print(buffer);
    return;
  }

  // CALCULATE
  lcd.clear();
  float result = 0;

  if (mode == 1) {
    result = evalSimple(buffer);
    lcd.print(result);
  }
  else if (mode == 2) {
    result = parallelRes(buffer);
    lcd.print("Req=");
    lcd.print(result);
  }
  else if (mode == 3) {
    int idx = buffer.indexOf('+');
    ohmA = buffer.substring(0, idx).toFloat();
    ohmB = buffer.substring(idx + 1).toFloat();

    if (ohmTarget == 'V') result = ohmA * ohmB;
    if (ohmTarget == 'I') result = ohmA / ohmB;
    if (ohmTarget == 'R') result = ohmA / ohmB;

    lcd.print(ohmTarget);
    lcd.print("=");
    lcd.print(result);
    ohmTarget = 0;
  }

  buffer = "";
}
