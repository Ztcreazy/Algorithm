#! /usr/bin/env python

import rospy
from publish_subscribe.msg import Person

def Implement(msg):
    rospy.loginfo("Paper: %s, Age: %d, JCR: %.2f",msg.name,msg.age,msg.height)

if __name__ == "__main__":
    rospy.init_node("Subscriber_py_person")

    sub = rospy.Subscriber("Paper",Person,Implement,queue_size = 10)

    rospy.spin()