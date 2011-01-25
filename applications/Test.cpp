/****************************************************************
 *
 * Copyright (c) 2011
 * All rights reserved.
 *
 * Hochschule Bonn-Rhein-Sieg
 * University of Applied Sciences
 * Computer Science Department
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Author:
 * Jan Paulus, Nico Hochgeschwender, Michael Reckhaus, Azamat Shakhimardanov
 * Supervised by:
 * Gerhard K. Kraetzschmar
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * This sofware is published under a dual-license: GNU Lesser General Public
 * License LGPL 2.1 and BSD license. The dual-license implies that users of this
 * code may choose which terms they prefer.
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Hochschule Bonn-Rhein-Sieg nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as
 * published by the Free Software Foundation, either version 2.1 of the
 * License, or (at your option) any later version or the BSD license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License LGPL and the BSD license for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License LGPL and BSD license along with this program.
 *
 ****************************************************************/

#include <iostream>
#include <vector>
#include <signal.h>
#include "youbot/YouBotJointParameter.hpp"
#include "youbot/YouBotGripper.hpp"
#include "youbot/YouBotBase.hpp"
#include "youbot/YouBotManipulator.hpp"




using namespace std;
using namespace youbot;

bool running = true;

void sigintHandler(int signal) {
  running = false;

  std::cout << " Interrupt!" << std::endl;

}

int main() {

  signal(SIGINT, sigintHandler);

  try {

 //   YouBotManipulator myYouBotManipulator("youbot-manipulator");
    YouBotBase myYouBotBase("youbot-base");

    
    //  std::cout << myYouBot.getNumberOfJoints() << std::endl;
    JointSensedTemperature temp;
    JointSensedAngle angle;
    JointSensedVelocity vel;
    JointSensedCurrent current;
    JointVelocitySetpoint setVel;
    JointAngleSetpoint setangle;
    setangle.angle = 2.0 * M_PI *radian;
    setVel.angularVelocity = 0.1 * M_PI *radian_per_second;
/*
    quantity<si::velocity> longitudinalVelocity = 0 * meter_per_second;
    quantity<si::velocity> transversalVelocity = 0 * meter_per_second;
    quantity<si::angular_velocity> angularVelocity = 0 * radian_per_second;

    quantity<si::velocity> longitudinalVel = 0 * meter_per_second;
    quantity<si::velocity> transversalVel = 0 * meter_per_second;
    quantity<si::angular_velocity> angularVel = 0 * radian_per_second;
    quantity<si::length> sensedLongitudinalPos;
    quantity<si::length> sensedTransversalPos;
    quantity<si::plane_angle> sensedAngularPos;

    quantity<si::plane_angle> lastAngle;

    setVel.angularVelocity = 0 * radian_per_second;


    MaximumPositioningSpeed test;


    YouBotGripper& gripper = myYouBotManipulator.getArmGripper();


    SLEEP_MILLISEC(2000);

    int jointNo = 1;

    JointAngleSetpoint jAngle;
    jAngle.angle = 0.5 *radian;

  //  myYouBot.getArm1Joint(5).setData(setVel);
    LOG(trace) << "move to pose: " << jAngle.angle;
    myYouBotManipulator.getArmJoint(jointNo).setData(jAngle);

    EncoderResolution encRes;

    MotorContollerGearRatio gearRatio;

    myYouBotManipulator.getArmJoint(1).getConfigurationParameter(encRes);
    myYouBotManipulator.getArmJoint(1).getConfigurationParameter(gearRatio);
    unsigned int enc;
    unsigned int gear;
 //   encRes.getParameter(enc);
 //   gearRatio.getParameter(gear);
 //   LOG(trace) << "gearRatio " << gear << "encoderResolution " << enc;
*/

    quantity<si::velocity> longitudinalVelocity = 0.2 * meter_per_second;
    quantity<si::velocity> transversalVelocity = 0.0 * meter_per_second;
    quantity<si::angular_velocity> angularVelocity = 0 * radian_per_second;

    quantity<si::velocity> actLongitudinalVelocity = 0 * meter_per_second;
    quantity<si::velocity> actTransversalVelocity = 0 * meter_per_second;
    quantity<si::angular_velocity> actAngularVelocity = 0 * radian_per_second;

    quantity<si::length> actLongitudinalPose = 0 * meter;
    quantity<si::length> actTransversalPose = 0 * meter;
    quantity<si::plane_angle> actAngle = 0 * radian;


    MaximumMotorCurrent maxCurrent;

    myYouBotBase.getBaseJoint(1).getConfigurationParameter(maxCurrent);

    quantity<si::current> maxc;
    maxCurrent.getParameter(maxc);

    LOG(info) << "max Current J1: " << maxc;

    maxCurrent.setParameter(1 * ampere);

    myYouBotBase.getBaseJoint(1).setConfigurationParameter(maxCurrent);
  //  myYouBotBase.getBaseJoint(2).setConfigurationParameter(initSinus);
  //  myYouBotBase.getBaseJoint(3).setConfigurationParameter(initSinus);
  //  myYouBotBase.getBaseJoint(4).setConfigurationParameter(initSinus);

    while (running) {

      myYouBotBase.setBaseVelocity(longitudinalVelocity, transversalVelocity, angularVelocity);
      myYouBotBase.getBasePosition(actLongitudinalPose, actTransversalPose, actAngle);
   //   myYouBotBase.getBaseVelocity(actLongitudinalVelocity, actTransversalVelocity, actAngularVelocity);
  //    LOG(info) << "actual Pose Longitudinal: " << actLongitudinalPose << " Transversal: " << actTransversalPose << " Angle: " << actAngle;

   //   LOG(info) << "actual Velocity Longitudinal: " << actLongitudinalVelocity << " Transversal: " << actTransversalVelocity << " Angular: " << actAngularVelocity;


  //    myYouBotBase.getBaseJoint(4).setData(setVel);
/*
       for (unsigned int i = 1; i <= 4; i++) {
        myYouBotBase.getBaseJoint(i).getData(temp);
        myYouBotBase.getBaseJoint(i).getData(angle);
        myYouBotBase.getBaseJoint(i).getData(vel);
        myYouBotBase.getBaseJoint(i).getData(current);
        std::cout << "Joint: " << i //<< //" Temp: " << temp.temperature
              //  << " Angle: " << angle.angle
                << " Vel: " << vel.angularVelocity
              //  << " Current: " << current.current
                << std::endl;
      }
*/
   //    myYouBotManipulator.getArmJoint(jointNo).getData(angle);

   //    std::cout << " Angle: " << angle.angle << std::endl;

      SLEEP_MILLISEC(100);
    }


//} catch (FileNotFoundException& e) {
//    std::cout << e.what() << std::endl;
//   std::cout << "FileNotFoundException" << std::endl;
} catch (std::ios_base::failure& e) {
    std::cout << e.what() << std::endl;
    std::cout << "std::ios_base::failure" << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    std::cout << "std::exception" << std::endl;
  } catch (...) {
    std::cout << "unhandled exception" << std::endl;
  }


  return 0;
}