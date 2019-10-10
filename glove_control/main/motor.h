int tspeed = 0;
int tespeed = 0;
int ispeed = 0;
int mspeed = 0;
int rspeed = 0;
int pspeed = 0;

//----pid control----
double Kp = 0.5; 
double Ki = 0.2;
double Kd = 0.1;

//integral used in motor PID
int tt_integral = 0;
int te_integral = 0;
int i_integral = 0;
int m_integral = 0;
int r_integral = 0;
int p_integral = 0;

//previous error used in motor PID
int tt_pre_error = 0;
int te_pre_error = 0;
int i_pre_error = 0;
int m_pre_error = 0;
int r_pre_error = 0;
int p_pre_error = 0;


//----motor control----
int tpwm = 0;
int tepwm = 0;
int ipwm = 0;
int mpwm = 0;
int rpwm = 0;
int ppwm = 0;
boolean tdir = false;
boolean tedir = false;
boolean idir = false;
boolean mdir = false;
boolean rdir = false;
boolean pdir = false;
