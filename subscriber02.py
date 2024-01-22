#! /usr/bin/env python

import rospy
from std_msgs.msg import String

def Implement(msg):
    rospy.loginfo("Subscriber_py is subscribing: %s",msg.data)

if __name__ == "__main__":
    rospy.init_node("Subscriber_py")

    sub = rospy.Subscriber("Vehicle",String,Implement,queue_size = 12)

    rospy.spin()