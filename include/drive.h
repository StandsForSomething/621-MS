fbc_t LDriveFBC;
fbc_t RDriveFBC;
fbc_t MDriveFBC;

Encoder leftEnc;
Encoder rightEnc;

int LDriveSense();
int RDriveSense();

void drive(int distance, bool blocking);
void turn(int left, int right , bool blocking);
void driveL(int power);
void driveR(int power);
void initDrive();
