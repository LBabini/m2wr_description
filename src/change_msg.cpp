#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/MagneticField.h"
#include "geometry_msgs/Vector3Stamped.h"
#include "std_msgs/Header.h"


ros::Publisher magn_field_pub = {};

   void clbk_magnetic(const geometry_msgs::Vector3Stamped::ConstPtr& msg)
 {

    sensor_msgs::MagneticField mag_field;
 mag_field.header = msg->header;
 mag_field.magnetic_field.x = msg->vector.x;
 mag_field.magnetic_field.y = msg->vector.y;
 mag_field.magnetic_field.z = msg->vector.z;
 
 magn_field_pub.publish(mag_field);
 }


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "change_msg");
  ros::NodeHandle n;

  ros::Subscriber magnetic_sub = n.subscribe("/magnetic", 100, clbk_magnetic);

  ::magn_field_pub = n.advertise<sensor_msgs::MagneticField>("/mag_field", 50);

  ros::spin();
	
return 0;
  
}

