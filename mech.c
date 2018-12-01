/*==============================================  
|    FILE NAME: mech.c
|    
|    AUTHORS: Carl Hutchinson, Edward Jacobs
|    DATE: 12/7/18
|    
|    VERSION NUMBER: 1
|    LAST UPDATED BY: Carl
===============================================*/

#include "mechanism.h"

int main()
{
   class CMechanism qr;
   double output, range_max, range_min;
   double complex cmplx;
   class CPlot plot1, plot2, plot3, plot4;

   int numpoints = 360;

   bool unit = SI;
   double r1 = 0.025, r2 = 0.010, r4 = 0.065, r5 = 0.030, r7 = 0.040;
   double theta1 = M_PI/2;
   double theta2 = 30*M_PI_180;
   double omega2 = -15.0;
   double rg2 = 0.0125, rg4 = 0.0275, rg5 = 0.0250;
   double delta2 = 30*M_PI/180, delta4 = 15*M_PI/180, delta5 = 30*M_PI/180;
   double ig2 = 0.012, ig4 = 0.119, ig5 = 0.038;
   

   //bool unit = USC;
   //double r1 = 0.0820, r2 = 0.0328, r4 = 0.2132, r5 = 0.0984, r7 = 0.164;
   //double theta1 = M_PI/2;
   //double theta2 = -30*M_PI_180;
   //double omega2 = -15.0;
   //double rg2 = 0.04101, rg4 = 0.09022, rg5 = 0.08202;
   //double delta2 = 30*M_PI/180, delta4 = 15*M_PI/180, delta5 = 30*M_PI/180;
   //double ig2 = 0.00885, ig4 = 0.08777, ig5 = 0.02803;
   //double m2 = 1.764, m3 = 0.661, m4 = 5.291, m5 = 3.086, m6 = 0.661;
   //double fl = -22.48;

   qr.uscUnit(unit);
   qr.setLinks(r1, r2, r4, r5, r7, theta1);
   qr.setAngVel(omega2);
   qr.setNumPoints(numpoints);

/* Calculations */
   output = qr.sliderPos(theta2);
   printf("slide position = %f\n", output);

   output = qr.sliderVel(theta2);
   printf("slide velocity = %f\n", output);

   output = qr.getAngPos(theta2, QR_LINK_4);
   printf("theta 4 = %f\n", output);

   output = qr.getAngPos(theta2, QR_LINK_5);
   printf("theta 5 = %f\n", output);

   output = qr.getAngVel(theta2, QR_LINK_4);
   printf("omega 4 = %f\n", output);

   output = qr.getAngVel(theta2, QR_LINK_5);
   printf("omega 5 = %f\n", output);


   qr.plotSliderPos(&plot1);
   qr.plotSliderVel(&plot2);
  
   //qr.plotAngPos(&plot);
   //qr.plotAngVel(&plot);
   //qr.plotAngAccel(&plot);
   //qr.plotCGaccel(&plot);  
   //qr.plotForce(MAG_F34 | F16Y, &plot4);
   //qr.plotTorque(&plot);

   qr.setNumPoints(50);
   qr.displayPosition(theta2, QANIMATE_OUTPUTTYPE_DISPLAY);
   //qr.displayPosition(theta2, QANIMATE_OUTPUTTYPE_STREAM);
   //qr.displayPosition(theta2, QANIMATE_OUTPUTTYPE_FILE, "position.qnm");
   qr.animation(QANIMATE_OUTPUTTYPE_DISPLAY);
   //qr.animation(QANIMATE_OUTPUTTYPE_STREAM);
   //qr.animation(QANIMATE_OUTPUTTYPE_FILE, "animation.qnm");
   printf("Done!\n");
   return 0;
}
