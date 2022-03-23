#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int Z = 2000;
int Y = 5000;
int V = 0;
int K = 100;
int B = 1;
int N = 2;
int I = 0;
int J = 0;
int T = 100;
int M = 0;
int O = 0;
int P = 0;
int Q = 0;
int R = 0;
int C, H, A, W, S, L;

void instructions();
void mainGameLoop();
void randomEvent();
void viewPrices();
void viewInventory();
void buyDrugs();
void sellDrugs();
void run();
void fight();
void gameOver();
void visitLoanShark();
void visitBank();

int main(){
  srand(static_cast<unsigned>(time(0)));
  cout << "J.M.'S DRUGWAR SIMULATION VERSION 2.00\n"
    << "            'JUST SAY NO.'\n";

  system("pause");
  system("cls");

  int X;
  cout << "ORIGINAL GAME FOR IBM BY: JOHN E. DELL\n";
  cout << "INSTRUCTIONS?\n";
  cout << "(1=YES,2=NO)";
  cin >> X;

  if (X == 1){
    instructions();
  }
  mainGameLoop();

  return 0;
}

void instructions(){
  system("cls");
  cout << "THIS IS A GAME OF BUYING AND SELLING.\n"
    <<"YOUR GOAL IS TO PAY OFF YOUR DEBT TO THE LOAN SHARK, AND THEN MAKE AS MUCH MONEY AS POSSIBLE IN A 1 MONTH PERIOD.\n"
    <<"WATCH-OUT FOR THE POLICE IF YOU DEAL TOO HEAVILY!\n";
  system("pause");
  system("cls");
  cout << "PRICES FOR DRUGS ARE:\nCOCAINE: 15000-28000\nHEROIN: 5000-12000\nACID: 1000-4200\nWEED: 300-720\nSPEED: 70-220\nLUDES: 10-50\n";
  system("pause");
  system("cls");
  cout << "GENERALY, TYPE THE FIRST LETTER OF WHAT YOU WANT TO DO, I.E.: W=WEED, L=LUDES ETC...\n";
  system("pause");
  cout << "BUT, 1=YES AND 2=NO\n";
  system("pause");
  system("cls");
  cout << "THE LAST NUMBER IN THE PRICES LIST IS YOUR WALLET. THE LAST NUMBER IN YOUR TRENCHCOAT IS FREE SPACE.\n";
  system("pause");
}

void randomEvent(){
newChance:
  C = rand() % 12001 + 16000;
  H = rand() % 7001 + 5000;
  A = rand() % 35 + 10;
  W = rand() % 43 + 33;
  S = rand() % 16 + 7;
  L = rand() % 5 + 1;
  int D = rand() % 21;

  system("cls");

  if (D == 1){
    cout << "RIVAL DEALERS ARE SELLING CHEAP LUDES!!!\n";
    system("pause");
    L = 2;
  }

  if (D == 2) {
    cout << "WEED PRICES HAVE BOTTOMED-OUT!!!\n";
    system("pause");
    W = 122;
  }

  if (D == 3) {
    cout << "PIGS ARE SELLING CHEAP HEROIN FROM LAST WEEK'S RAID!!!!\n";
    system("pause");
    H = rand() % 1151 + 850;
  }

  if (D == 4 || D == 5){
    cout << "ADDICTS ARE BUYING HEROIN AT OUTRAGEOUS PRICES!!!\n";
    system("pause");
    H = rand() % 25001 + 18000;
  }

  if (D == 6 || D == 7){
    cout << "PIGS MADE A BIG COKE BUST! PRICES ARE OUTRAGEOUS!!!!\n";
    system("pause");
    C = rand() % 60001 + 80000;
  }

  if (D == 8){
    cout << "YOU WERE MUGGED IN THE SUBWAY!\n";
    system("pause");
    Z /= 3;
    Z *= 2;
  }

  if (D == 15 && Z >= 300){
    cout << "WILL YOU BUY A NEW TRENCHCOAT WITH MORE POCKETS FOR 200 BUCKS?\n";
    int X1;
    cin >> X1;
    if (X1 == 1){
      T += 10;
      K = T - M - N - O - P - Q - R;
      Z -= 200;
    }
  }

  if (D == 14){
    cout << "THERE'S SOME WEED HERE THAT SMELLS LIKE GOOD STUFF!! WILL YOU SMOKE IT?\n";
    int X2;
    cin >> X2;
    if (X2 == 1){
      system("cls");
      cout << "YOU HALLUCINATE ON THE WILDEST TRIP OF YOUR LIFE, STUMBLE ON TO THE SUBWAY TRACKS AND GET CREAMED BY A TRAIN.\n";
      cout << "JUST SAY NO TO\nDRUGS.\n";
      system("pause");
      system("cls");
      cout << "JUST SAY NO TO DRUGS.\n";
      system("pause");
      gameOver();
    }
  }

  if ((Z >= 500 && K>=5) && (D == 12 || D == 13)){
    cout << "WILL YOU BUY A ";
    int X3 = rand() % 3;
    if (X3 == 0) cout << "BARRETTA";
    else if (X3 == 1) cout << "SATURDAY NIGHT SPECIAL";
    else if (X3 == 2) cout << ".44 MAGNUM";
    cout << " FOR 400 DOLLARS?\n";
    int X4;
    cin >> X4;
    if (X4 == 1){
      I++;
      Z -= 400;
      T -= 5;
      K = T - M - N - O - P - Q - R;
    }
  }

  if (D == 16 && K >= 8){
    int F = rand() % 8 + 1;
    cout << "YOU FOUND: " << F << " UNITS OF: ";
    int X5 = rand() % 6;
    if (X5 == 0){
      cout << "LUDES";
      R += F;
    }
    else if (X5 == 1){
      cout << "SPEED";
      Q += F;
    }
    else if (X5 == 2){
      cout << "WEED";
      P += F;
    }
    else if (X5 == 3){
      cout << "ACID";
      O += F;
    }
    else if (X5 == 4){
      cout << "HEROIN";
      N += F;
    }
    else if (X5 == 5){
      cout << "COCAINE";
      M += F;
    }
    cout << " ON A DEAD DUDE IN THE SUBWAY!!!\n";
    K = T - M - N - O - P - Q - R;
    system("pause");
  }

  if (D == 17){
    cout << "THE MARKET HAS BEEN FLOODED WITH CHEAP HOME-MADE ACID!!!!\n";
    A = rand() % 551 + 250;
    system("pause");
  }

  if ((D == 9 || D == 10 || D == 11) && (M + N + O + P + Q + R >= 50)){
    if (D == 9)D = 1;
    if (D == 10)D = 3;
    if (D == 11)D = 4;
    cout << "OFFICER HARDASS AND " << D << " OF HIS DEPUTIES ARE AFTER YOU!\n";
    system("pause");
    system("cls");
  menu:
    cout << "BEING CHASED!!\n\n";
    cout << "1. VIEW GUNS\n";
    cout << "2. VIEW DAMMAGE\n";
    cout << "3. NUMBER OF PIGS\n";
    cout << "4. RUN\n";
    cout << "5. FIGHT\n";
    cout << "Your choice: ";
    int X6;
    cin >> X6;

    switch (X6){
    case 1:
      system("cls");
      cout << "NUMBER OF GUNS YOU HAVE: " << I;
      system("pause");
      goto menu;
    case 2:
      system("cls");
      cout << "YOUR DAMMAGE=" << J
        << "(50 DAMMAGE AND YOU DIE!)";
      system("pause");
      goto menu;
    case 3:
      system("cls");
      cout << "THERE ARE: ";
      D++;
      cout << D;
      D--;
      cout << " PIGS STILL CHASING YOU!";
      system("pause");
      goto menu;
    case 4:
      system("cls");
      cout << ".\n.\n.\n.\n.....RUNNING";
      int X7;
      X7 = rand() % 2;
      if (X7 == 0){
        system("cls");
        cout<< "YOU LOST THEM IN AN ALLEY!!";
        system("pause");
        if (B == 31) break;
        else goto newChance;
      }
      else if (X7 == 1){
        system("cls");
        cout << "YOU CAN'T SHAKE THEM!";
        system("pause");
        int X8;
        X8 = rand() % 2;
        system("cls");
        cout << "THEY'RE FIRING AT YOU!!";
        if (X8 == 0){
          cout << "THEY MISSED!!";
          system("pause");
          goto menu;
        }
        else{
          cout << "YOU'VE BEEN HIT!";
          J += 3;
          system("pause");
          if (J >= 50) {
            cout << "YOU'VE BEEN KILLED!!";
            system("pause");
            gameOver();
          }
          goto menu;
        }
      }
    case 5:
      if (I == 0){
        system("cls");
        cout << "YOU DON'T HAVE ANY GUNS!";
        system("pause");
        cout << "YOU HAVE TO RUN!";
        system("pause");
        goto menu;
      }
      else{
        int X9;
        X9 = rand() % 2;
        if (X9 == 0){
          system("cls");
          cout << "YOU MISSED!!!";
          system("pause");
          goto menu;
        }
        else{
          system("cls");
          cout << "YOU KILLED ONE!!";
          system("pause");
          D--;
          if (D == -1){
            system("cls");
            cout << "YOU KILLED ALL OF THEM!\n";
            int X10;
            X10 = rand() % 1251 + 750;
            Z += X10;
            system("pause");
            cout << "YOU FOUND " << X10 << " DOLLARS ON OFFICER HARDASS' CARCASS!!";
            system("pause");
            if (Z >= 1200){
              system("cls");
              cout << "WILL YOU PAY 1000 DOLLARS FOR A DOCTOR TO SEW YOU UP?";
              int X11;
              cin >> X11;
              if (X11 == 1){
                Z -= 1000;
                J = 0;
              }     
            }
            break;
          }
          goto menu;
        }
      }
    default:
      cout << "Invalid choice. Try again.\n";
      goto menu;
    }
  }
}

void mainGameLoop(){
start:
  int F;
  while (B <= 31){
    randomEvent();
  menu:
    cout << "DRUGWAR!\n\n";
    cout << "DAY NUMBER: " << B << endl;  
    cout << "1. SEE PRICES\n";
    cout << "2. TRENCHCOAT\n";
    cout << "3. BUY\n";
    cout << "4. SELL\n";
    cout << "5. JET\n";
    cout << "6. SEE LOAN SHARK\n";
    cout << "7. VISIT BANK\n";
    cout << "Your choice: ";
    cin >> F;

    switch (F){
    case 1:
      viewPrices();
      goto menu;
    case 2:
      viewInventory();
      goto menu;
    case 3:
      buyDrugs();
      goto menu;
    case 4:
      sellDrugs();
      goto menu;
    case 5:
      run();
      goto start;
    case 6:
      visitLoanShark();
      goto menu;
    case 7:
      visitBank();
      goto menu;
    default:
      cout << "Invalid choice. Try again.\n";
      system("pause");
      system("cls");
      goto menu;
    }
    B++;
  }
  gameOver();
}

void viewPrices() {
  system("cls");
  cout << "COCAINE: " << C << endl;
  cout << "HEROINE: " << H << endl;
  cout << "ACID: " << A << endl;
  cout << "WEED: " << W << endl;
  cout << "SPEED: " << S << endl;
  cout << "LUDES: " << L << endl;
  cout << "WALLET: " << Z << endl;
  system("pause");
  system("cls");
}

void viewInventory() {
  system("cls");
  cout << "COCAINE: " << M << endl;
  cout << "HEROIN: " << N << endl;
  cout << "ACID: " << O << endl;
  cout << "WEED: " << P << endl;
  cout << "SPEED: " << Q << endl;
  cout << "LUDES: " << R << endl;
  cout << "FREE SPACE: " << K << endl;
  system("pause");
  system("cls");
}

void buyDrugs() {
tryAgain:
  int F;  char drug;
  system("cls");
  cout << "DAY NUMBER: " << B << endl;
  cout << "WHAT TO BUY? ";
  cin >> drug;

  switch (drug) {
  case'C':
    F = C;
    break;
  case'H':
    F = H;
    break;
  case'A':
    F = A;
    break;
  case'W':
    F = W;
    break;
  case'S':
    F = S;
    break;
  case'L':
    F = L;
    break;
  default:
    cout << "Invalid choice. Try again.\n";
    system("pause");
    goto tryAgain;
  }
 

  if (F != C && F != H && F != A && F != W && F != S && F != L) {
    cout << "Invalid choice. Try again.\n";
    system("pause");
    goto tryAgain;
  }

  int E = Z / F;
  cout << "HOW MUCH? YOU CAN AFFORD: " << E << " YOU CAN HOLD: " << K << endl;
  int G;
  cin >> G;

  if (G > K || G < 0 || G > E) {
    cout << "Invalid amount. Try again.\n";
    system("pause");
    goto tryAgain;
  }

  Z -= F * G;
  if (F == C) M += G;
  if (F == H) N += G;
  if (F == A) O += G;
  if (F == W) P += G;
  if (F == S) Q += G;
  if (F == L) R += G;

  K = T - M - N - O - P - Q - R;
  system("pause");
  system("cls");
}

void sellDrugs() {
tryAgain:
  int F; char drug;
  system("cls");
  cout << "DAY NUMBER: " << B << endl;
  cout << "WHAT TO SELL? ";
  cin >> drug;
 
  switch (drug) {
  case'C':
    F = C;
    break;
  case'H':
    F = H;
    break;
  case'A':
    F = A;
    break;
  case'W':
    F = W;
    break;
  case'S':
    F = S;
    break;
  case'L':
    F = L;
    break;
  default:
    cout << "Invalid choice. Try again.\n";
    system("pause");
    goto tryAgain;
  }

  if (F != C && F != H && F != A && F != W && F != S && F != L) {
    cout << "Invalid choice. Try again.\n";
    system("pause");
    goto tryAgain;
  }

  int E;

  if (F == C) E = M;
  if (F == H) E = N;
  if (F == A) E = O;
  if (F == W) E = P;
  if (F == S) E = Q;
  if (F == L) E = R;

  cout << "HOW MUCH? YOU HAVE: " << E << endl;
  int G;
  cin >> G;

  if (G > E || G < 0) {
    cout << "Invalid amount. Try again.\n";
    system("pause");
    goto tryAgain;
  }

  if (F == C) M -= G;
  if (F == H) N -= G;
  if (F == A) O -= G;
  if (F == W) P -= G;
  if (F == S) Q -= G;
  if (F == L) R -= G;
  
  Z += F * G;
  K = T - M - N - O - P - Q - R;

  system("pause");
  system("cls");
}

void run() {
tryAgain:
  system("cls");

  cout << "WHERE TO, DUDE?\n\n";
  cout << "1. BRONX\n";
  cout << "2. GHETTO\n";
  cout << "3. CENTRAL PARK\n";
  cout << "4. MANHATTEN\n";
  cout << "5. CONEY ISLAND\n";
  cout << "6. BROOKLYN\n";
  cout << "7. OOPS... STAY!\n";
  cout << "Your choice: ";
  int F;
  cin >> F;

  switch (F) {
  case 1:
    if (N == 2){
      system("cls");
      cout << "YOU'RE ALREADY IN THE BRONX!";
      system("pause");
      goto tryAgain;
    }
    else{
      N = 2;
      break;
    }
  case 2:
    N = 1;
    break;
  case 3:
    N = 1;
    break;
  case 4:
    N = 1;
    break;
  case 5:
    N = 1;
    break;
  case 6:
    N = 1;
    break;
  case 7:
    system("cls");
    goto tryAgain;
  default:
    cout << "Invalid choice. Try again.\n";
    system("pause");
    goto tryAgain;
  }

  system("cls");
  cout << ".\n.\n.\n.\n.....SUBWAY";
  B++;
  Y *= 1.1;
  V *= 1.06;
  if (B == 31)gameOver();
}

void gameOver() {
  system("cls");
  cout << "   GAME OVER!\n";
  V = V + Z - Y;
  if (V < 0)
    V = 0;
  else {
    V = sqrt(V / 31.5);
    if (V > 100)
      V = 100;
  }
  cout << "YOUR SCORE (ON A SCALE OF 1 TO 100): " << V << endl;

  cout << "PLAY AGAIN? (1=YES, 0=NO): ";
  cin >> V;
  if (V == 1) {
    Z = 2000;
    Y = 5000;
    V = 0;
    K = 100;
    B = 1;
    N = 2;
    I = 0;
    J = 0;
    T = 100;
    M = 0;
    O = 0;
    P = 0;
    Q = 0;
    R = 0;
    mainGameLoop();
  }
  else {
    cout << "THANKS FOR PLAYING!\n";
    cout << "REMEMBER:\n";
    cout << "WATCH YOUR BACK.\n";
    cout << "HAVE A NICE DAY!\n";
  }
}

void visitLoanShark() {
tryAgain:
  int X;
  system("cls");
  if (N == 1) {
    cout << "THE LOAN SHARK ONLY DEALS IN THE BRONX.\n";
    system("pause");
    return;
  }

  system("cls");
  cout << "LOAN SHARK...\n";
  cout << "1. REPAY\n";
  cout << "2. BORROW\n";
  cin >> X;

  switch (X){
  case 1:
    system("cls");
    cout << "YOUR DEBT IS: " << Y << endl;
    cout << "YOUR WALLET = " << Z << endl;
    cout << "REPAY HOW MUCH? ";
    int F;
    cin >> F;
    if (F > Z || F < 0 || F > Y){
      cout << "Invalid amount. Try again.\n";
      system("pause");
      goto tryAgain;
    }
    else{
      Y -= F;
      Z -= F;
    }
    break;
  case 2:
  tryAgainBorrow:
    system("cls");
    cout << "YOUR DEBT IS: " << Y << endl;
    cout << "YOUR WALLET = " << Z << endl;
    cout << "BORROW HOW MUCH MORE? ";
    int G;
    cin >> G;
    if (G > 5000){
      system("cls");
      cout << "YOU THINK HE'S CRAZY, MAN?!";
      system("pause");
      goto tryAgainBorrow;
    }
    else if (G < 0) goto tryAgain;
    else{
      Y += G;
      Z += G;
    }
    break;
  default:
    cout << "Invalid choice. Try again.\n";
    system("pause");
    system("cls");
    goto tryAgain;
  }
  cout << "Transaction successful.\n";
  system("pause");
  system("cls");
}

void visitBank() {
tryAgain:
  int X;
  system("cls");
  if (N == 1) {
    cout << "THE BANK IS IN THE BRONX.\n";
    system("pause");
    return;
  }

  cout << "      BANK      \n\n";
  cout << "1. VIEW ACCOUNT\n";
  cout << "2. DEPOSIT\n";
  cout << "3. WITHDRAW\n";
  cout << "4. GOODBYE\n";
  cout << "Your choice: ";
  cin >> X;

  switch (X){
  case 1:
    system("cls");
    cout << "YOUR ACCOUNT= " << V;
    system("pause");
    goto tryAgain;
  case 2:
  tryAgainDeposit:
    system("cls");
    cout << "HOW MUCH TO DEPOSIT? YOU HAVE: " << Z;
    int G;
    cin >> G;
    if (G > Z || G < 0){
      cout << "Invalid amount. Try again.\n";
      system("pause");
      goto tryAgainDeposit;
    }
    else{
      cout << "Transaction successful.\n";
      system("pause");
      V += G;
      Z -= G;
      goto tryAgain;
    }
  case 3:
  tryAgainWithdraw:
    system("cls");
    cout << "HOW MUCH TO WITHDRAW? ACCOUNT = " << V << endl;
    int G2;
    cin >> G2;
    if (G2 > V || G2 < 0){
      cout << "Invalid amount. Try again.\n";
      system("pause");
      goto tryAgainWithdraw;
    }
    else{
      cout << "Transaction successful.\n";
      system("pause");
      V -= G2;
      Z += G2;
      goto tryAgain;
    }
  case 4:
    break;
  default:
    cout << "Invalid choice. Try again.\n";
    system("pause");
    system("cls");
    goto tryAgain;
  }
  system("cls");
}