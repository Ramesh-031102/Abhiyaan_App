/* Subscriber Node
   Subscribes to the Topic: /turtle1/pose
   Type: turtlesim/Pose
 & Publisher Node
   Publishes to the Topic: /turtle1/cmd_vel
   Type: geometry_msgs/Twist */

// PDF attached related to this. 

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

float l_vel_x1, a_vel_z1;    

void func(const turtlesim::Pose& msg){
    float pos_x,pos_y,theta,theta1,r;    // pos_x & pos_y - coords of turtle1,
    pos_x = msg.x;                       // theta - angle the seperation vector makes with the positive x axis,
    pos_y = msg.y;                       // theta1 - angle the tangential velocity makes with the positive x axis,
    theta1 = msg.theta;                  // r - seperation between the turtles.
    r = 2*pow((pow((pos_x-5.544445),2)+pow((pos_y-5.544445),2)),0.5);
    theta = acos(1.414214*(1-(2/r)));
    if(pos_y < 5.544445)
        theta = 6.283185 - theta;
    if(theta1 < 0)
        theta1 += 6.283185;
    l_vel_x1 = 3/(r*sin(theta1-theta));
    a_vel_z1 = 6/pow(r,2);
}

int main(int argc, char **argv){
	ros::init(argc, argv, "Turtle1");
	ros::NodeHandle n;
    ros::Subscriber pose_sub1 = n.subscribe("/turtle1/pose",1000,func);
    ros::Publisher vel_pub1 =  n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1000);
    ros::Rate loop_rate(10);
    while(ros::ok()){
    	geometry_msgs::Twist vel_msg1;
    	vel_msg1.linear.x = l_vel_x1;
        vel_msg1.linear.y = 0;           
        vel_msg1.linear.z = 0;
        vel_msg1.angular.x = 0;
        vel_msg1.angular.y = 0;
        vel_msg1.angular.z = a_vel_z1;
        vel_pub1.publish(vel_msg1);
    	ros::spinOnce();
    	loop_rate.sleep();
    }
    ros::spin();
    return 0;
}

    	