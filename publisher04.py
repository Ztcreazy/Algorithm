#! /usr/bin/env python

import rospy
from publish_subscribe.msg import Person

if __name__ == "__main__":
    rospy.init_node("Publisher_py_person")

    pub = rospy.Publisher("Paper",Person,queue_size = 10)

    message = Person()
    message.name = "IEEE"
    message.age = 24
    message.height = 1.0

    rate = rospy.Rate(1)

    rospy.sleep(5)

    while not rospy.is_shutdown():
        message.height += 1
        pub.publish(message)
        rospy.loginfo("Paper: %s, Age: %d, JCR: %.2f", message.name,message.age,message.height)

        rate.sleep()
