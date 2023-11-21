#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <std_msgs/Float32.h>


ros::Subscriber sub;
float x;
float y;
float theta;


void Callback(const turtlesim::Pose& data)
   {
    x = data.x;
    y = data.y;
    theta = data.theta;

    ROS_INFO("distance of x : %f, distance of y : %f , angle of theta %f", data.x , data.y , data.theta);
   
  
   }



int main(int argc, char** argv)

{
   ros::init(argc, argv, "listener");
   ros::NodeHandle n;
 
   sub = n.subscribe("turtle1/pose", 1000, Callback);

   ros::spin();

   return 0;
}



