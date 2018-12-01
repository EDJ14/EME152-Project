/*==============================================  
|    FILE NAME: mechanism.h
|    
|    AUTHORS: Carl Hutchinson, Edward Jacobs
|    DATE: 12/7/18
|    
|    VERSION NUMBER: 1
|    LAST UPDATED BY: Carl
===============================================*/

#ifndef _MECHANISM_H_
#define _MECHANISM_H_

#include <linkage.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <float.h>
#include <complex.h>
#include <chplot.h>

enum 
{
   SI,             //  SI units, use with uscUnit()
   USC,            //  USC units,  "    "    "
   QR_LINK_2,      //  Link 2
   QR_LINK_4,      //  Link 4
   QR_LINK_5,      //  Link 5
   QR_POINT_A,     //  Point A: point of slider 3
   QR_POINT_B,     //  Point B: end of Link 4

};


/**********************************************
 * CQuickReturn class definition
 *********************************************/

class CMechanism
{
   private:
      // Private data members
      double m_omega[1:5];     // angular velocity
      double m_r[1:8];         // lengths of links
      double m_theta[1:7];     // phase angles for the links
      double complex m_v3;     // velocity of slider 3
      int m_numpoints;         // number of points to plot or for animation
      bool m_uscunit;          // unit choice

      // Private function members 
      void m_initialize(void);              // initialize private members
      void calcPosition(double theta2);     // calc. ang. pos. 
      void calcVelocity(double theta2);     // calc. ang. vel. and r9 dot
      
   public:
      // Constructor and Destructor
      CMechanism();
      ~CMechanism();

      //Set
      void setLinks(double r1, r2, r4, r5, r7, theta1);
      void setAngVel(double initomega2);
      void setNumPoints(int numpoints);
      void uscUnit(bool unit); 

      //Get
      double sliderPos(double theta2);
      double sliderVel(double theta2);
      double getAngPos(double theta2, int link);
      double getAngVel(double theta2, int link);
      
      // Output display functions
      void displayPosition(double theta2, ...);
      void animation(...);

      // Plot information functions
      void plotSliderPos(CPlot *plot);
      void plotSliderVel(CPlot *plot);
      void plotAngPos(CPlot *plot);
      void plotAngVel(CPlot *plot);
      
    
      
};

#pragma importf <CMechanism.chf>

#endif
