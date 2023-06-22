#include "rclpp/rclpp.hpp"
#include "sensor_msgs/msg/LaserScan.hpp"
/*class yournode : public rclcpp::Node {
    public:
    yournode() :  Node("my_node_name"){ //

    }
    private:
    void subscription(){
       RCLCPP_INFO(this->get_logger(),"Hello from the subscriber_node");   //
}      

};

int main (int argc, char **argv){

rclcpp::init(argc,argv);
auto node = std::make_shared<yournode>();

rclcpp::spin(node);
rclcpp::shutdown();
return 0;
}
*/
class MinimalSubscriber() : public rclcpp::Node{
    public:
    MinimalSubscriber()
: Node("minimal_subscriber")
{
    subscription_ = this->create_subcription<sensor_msgs::msg::LaserScan>("topic", 10, std::bind(&MinimalSubscriber::topic_callback,this,std::placeholders::_1));

}
private:
void topic_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg) const{
    RCLCPP_INFO(this->get_logger(),"I heard: '%s'",msg->data.c_str());
}
rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
};

int main (int argc, char **argv){

rclcpp::init(argc,argv);

rclcpp::spin(std::make_shared<MinimalSubscriber>());
rclcpp::shutdown();
return 0;
}
