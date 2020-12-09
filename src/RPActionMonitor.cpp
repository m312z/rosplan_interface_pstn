#include "rosplan_interface_pstn/RPActionMonitor.h"
#include <iostream>

/* The implementation of RPActionMonitor.h */
namespace KCL_rosplan {

	/* constructor */
	RPActionMonitor::RPActionMonitor(ros::NodeHandle &nh) {

		node_handle = &nh;

		// knowledge interface
		// current_knowledge_client = nh.serviceClient<rosplan_knowledge_msgs::KnowledgeUpdateService>("/rosplan_knowledge_base/state/");
	}

	void RPActionMonitor::dispatchCallback(const rosplan_dispatch_msgs::ActionDispatch& msg) {
        ROS_INFO("KCL: (%s) Noting action start: (%s).", ros::this_node::getName().c_str(), msg.name.c_str());
    }

	void RPActionMonitor::feedbackCallback(const rosplan_dispatch_msgs::ActionFeedback& msg) {
        ROS_INFO("KCL: (%s) Noting action end: (%s).", ros::this_node::getName().c_str(), msg.status.c_str());
    }

} // close namespace

	/*-------------*/
	/* Main method */
	/*-------------*/

	int main(int argc, char **argv) {

		ros::init(argc, argv, "rosplan_action_monitor");
		ros::NodeHandle nh("~");

		// launch params
		std::string dsp_topic;
		std::string fdb_topic;
		nh.param("dispatch_topic", dsp_topic, std::string("/rosplan_plan_dispatcher/action_dispatch"));
		nh.param("feedback_topic", fdb_topic, std::string("/rosplan_plan_dispatcher/action_feedback"));

		// create node
		KCL_rosplan::RPActionMonitor rpam(nh);

		// listen on topics
		ros::Subscriber dsp = nh.subscribe(dsp_topic, 100, &KCL_rosplan::RPActionMonitor::dispatchCallback, &rpam);
		ros::Subscriber fdb = nh.subscribe(fdb_topic, 100, &KCL_rosplan::RPActionMonitor::feedbackCallback, &rpam);

		ROS_INFO("KCL: (%s) Ready to receive", ros::this_node::getName().c_str());

		ros::spin();

		return 0;
	}
