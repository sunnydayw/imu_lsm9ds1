#include <ctime>
#include <cstdlib> 
#include "ros/ros.h"
#include "sensor_msgs/Imu.h"

	int main(int argc, char **argv)
	{
		ros::init(argc, argv, "imu");
		ros::NodeHandle n;
		ros::Publisher chatter_pub = n.advertise<sensor_msgs::Imu >("imu/data_raw", 1000);
		ros::Rate loop_rate(1);
		int ax,ay,az,vx,vy,vz;
			while (ros::ok())
			{
				srand( time(0));
				ax = rand()%100+1;
				ay = rand()%100+1;
				az = rand()%100+1;
				vx = rand()%100+1;
				vy = rand()%100+1;
				vz = rand()%100+1;

				sensor_msgs::Imu imu_msg = sensor_msgs::Imu();	
				imu_msg.header.stamp = ros::Time::now();

				//imu_msg.orientation.x = ;
				//imu_msg.orientation.y = ;
				//imu_msg.orientation.z = ;
				//imu_msg.angular_velocity_covariance = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
				imu_msg.angular_velocity.x = vx;
				imu_msg.angular_velocity.y = vy;
				imu_msg.angular_velocity.z = vz;
				//imu_msg.angular_velocity_covariance = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
				imu_msg.linear_acceleration.x = ax;
				imu_msg.linear_acceleration.y = ay;
				imu_msg.linear_acceleration.z = az;
				chatter_pub.publish(imu_msg);
				//ROS_INFO("%s", "send an imu message");
				ros::spinOnce();
				loop_rate.sleep();

			}
		return 0;
	}

