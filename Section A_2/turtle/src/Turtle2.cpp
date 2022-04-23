/* Subscriber Node
   Subscribes to the Topic: /turtle2/pose
   Type: turtlesim/Pose
 & Publisher Node
   Publishes to the Topic: /turtle2/cmd_vel
   Type: geometry_msgs/Twist */

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

float l_vel_x2, a_vel_z2;    

void func(const turtlesim::Pose& msg){
    float pos_x,pos_y,theta,theta1,r;    // pos_x & pos_y - coords of turtle2,
    pos_x = msg.x;                       // theta - angle the seperation vector makes with the positive x axis,
    pos_y = msg.y;                       // theta1 - angle the tangential velocity makes with the positive x axis,
    theta1 = msg.theta;                  // r - seperation between the turtles.
    r = 2*pow((pow((pos_x-5.544445),2)+pow((pos_y-5.544445),2)),0.5);
    theta = acos(1.414214*(1-(2/r)));
    if(pos_y < 5.544445)
        theta = 6.283185 - theta;
    if(theta1 < 0)
        theta1 += 6.283185;
    l_vel_x2 = 3/(r*sin(theta1-theta));
    a_vel_z2 = 6/pow(r,2);
}

int main(int argc, char **argv){
	ros::init(argc, argv, "Turtle2");
	ros::NodeHandle n;
    ros::Subscriber pose_sub2 = n.subscribe("/turtle2/pose",1000,func);
    ros::Publisher vel_pub2 =  n.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",1000);
    ros::Rate loop_rate(10);
    while(ros::ok()){
    	geometry_msgs::Twist vel_msg2;
    	vel_msg2.linear.x = l_vel_x2;
        vel_msg2.linear.y = 0;           
        vel_msg2.linear.z = 0;
        vel_msg2.angular.x = 0;
        vel_msg2.angular.y = 0;
        vel_msg2.angular.z = a_vel_z2;
        vel_pub2.publish(vel_msg2);
    	ros::spinOnce();
    	loop_rate.sleep();
    }
    ros::spin();
    return 0;
}

    	