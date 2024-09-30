
//Inverse_Kinematics _Elbow_down_algorithm
#include <Servo.h>
Servo servo1;
Servo servo2;
const int servoPin1 = 9;
const int servoPin2 = 10;
int a;  // (  ⃤⃤ bac) top angle at top link: to be solved 
int b;  // (  ⃤⃤ abc) middle angle between links: to be solved 
int c;  // (  ⃤⃤ bca) bottom angle at lower link: might be unimportant atm 
int d;  // (  ⃤⃤ fde) bottom angle at triangle  ⃤⃤ def: to be solved
int x = 15;  // x lenth or x-axis position(end-effector): to be given
int y = 20;  // y lenth or y-axis position(end-effector): to be given
int l3; // resultant link(for end-effector): to be solved
int l2 = 15; // second link: to be given
int l1 = 14; // first link: to be given
int theta_1; // Angle deviation of first joint from origin(x- axis): to be solved
int theta_2; // Angle deviation of first joint from origin(l1- axis 0r link 1 axis): to be solved
int angle_1; // Angle of the first motor displacement: to be solved
int angle_2; // Angle of the second motor displacement: to be solved

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);

}


void loop() {
  // put your main code here, to run repeatedly:

// resultant link(for end-effector): to be solved
int l3 = sqrt(pow(x,2) + pow(y,2));

// (  ⃤⃤ abc) middle angle between links: to be solved 
double b = ((pow(l3,2)) - (pow(l2,2) )- (pow(l1,2))) / -((2) * (l2) * (l1));
double b_radian = acos(b);
double doubleValue_b_degrees = b_radian * 180.0 / PI;
int b_degrees = (int)doubleValue_b_degrees;

//Angle deviation of first joint from origin(l1- axis 0r link 1 axis): to be solved
int theta_2 = 180 - b_degrees;

// (  ⃤⃤ bac) top angle at top link: to be solved 
double a = (pow(l2,2) - pow(l1,2) - pow(l3,2)) / (-2 * l1 * l3);
double a_radian = acos(a);
double doubleValue_a_degrees = a_radian * 180.0 / PI;
int a_degrees = (int)doubleValue_a_degrees;

// (  ⃤⃤ fde) bottom angle at triangle  ⃤⃤ def: to be solved
// alternatively int d = acos( (pow(y,2) - pow(x,2) - pow(l3,2)) / (-2 * x * l3));
double d = (y/x);
double d_radian = atan(d);
double doubleValue_d_degrees = d_radian * 180.0 / PI;
int d_degrees = (int)doubleValue_d_degrees;

// Angle deviation of first joint from origin(x- axis): to be solved
int theta_1 = a_degrees + d_degrees;


// Angle of the first motor displacement: to be solved
int angle_1 = theta_1 + 0; 

// Angle of the second motor displacement: to be solved
int angle_2 = 180 - theta_2; 


// Move the first servo 
  servo1.write(angle_1);
  delay(1000); // Wait for 1 second

// Move the second servo
  servo2.write(angle_2);
  delay(1000); 

//Display
  Serial.print("Solving...");
  Serial.print(" \n");
  delay(300);
  Serial.print("The value of theta_1 is: ");
  Serial.println(theta_1);
  Serial.print("The value of theta_2 is: ");
  Serial.println(theta_2);
  Serial.print("The value of b_degrees is: ");
  Serial.println(b_degrees);
  Serial.print("The value of a_degrees is: ");
  Serial.println(a_degrees);
  Serial.print("The value of d_degrees is: ");
  Serial.println(d_degrees);
  
}
