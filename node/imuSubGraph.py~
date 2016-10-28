#!/usr/bin/env python
import roslib
import rospy
from sensor_msgs.msg import Imu
import numpy as np
import matplotlib.pyplot as plt


plt.ion()
fig=plt.figure()
plt.title("Test d\'acqusition", fontsize=20)
plt.xlabel("Temps(s)", fontsize=20)
plt.ylabel("Tension (V)", fontsize=20)
plt.grid(True)

    
def callback(data):
	#rospy.loginfo(rospy.get_caller_id())
	#rospy.loginfo(data)
	x = data.header.seq
	y = data.linear_acceleration.x
	plt.plot(x, y)
	fig.canvas.draw()

def listener():
	rospy.init_node('imu_listener', anonymous=False)
	rospy.Subscriber('/imu/data_raw', Imu, callback)

	# spin() simply keeps python from exiting until this node is stopped
	#rospy.spin()
	plt.show(block=True)

if __name__ == '__main__':
	listener()

