//This program publishes randomly-generated velocity messages for turtlesim

#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<stdlib.h>//for rand() and RAND_MAX

int main(int argc,char **argv)
{
  ros::init(argc,argv,"hiturtule");//Initialize
  ros::NodeHandle nh;//Establish this program as a ROS node

  //create a publisher object
  ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);

  //Seed the random number generator
  srand(time(0));

  //Loop at 2HZ until the node is shut down
  ros::Rate rate(2);
  while(ros::ok()){
  //Create and fill in the message.
  geometry_msgs::Twist msg;
  msg.linear.x=double(rand())/double(RAND_MAX);
  msg.angular.z=2*double(rand())/double(RAND_MAX)-1;

  //Publish the message
  pub.publish(msg);

  //Send a message to rosout.
  ROS_INFO_STREAM("Sending random velocity command:linear="<< msg.linear.x
                    << "angular=" << msg.angular.z);//Send output as a log message
  
  //Wait until it's time for another iteration
  rate.sleep();
}
}
