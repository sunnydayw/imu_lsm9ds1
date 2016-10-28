#!/usr/bin/env python
import roslib
import rospy
from sensor_msgs.msg import Imu

def callback(data):

	rospy.loginfo(rospy.get_caller_id())
	rospy.loginfo(data)

def listener():
	rospy.init_node('imu_listener', anonymous=False)
	rospy.Subscriber('/imu/data_raw', Imu, callback)

	# spin() simply keeps python from exiting until this node is stopped
	rospy.spin()

if __name__ == '__main__':
	listener()

