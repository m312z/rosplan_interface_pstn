#include <ros/ros.h>
#include <vector>
#include <iostream>
#include <fstream>

#include "rosplan_knowledge_msgs/KnowledgeItem.h"
#include "rosplan_knowledge_msgs/KnowledgeUpdateService.h"
#include "rosplan_knowledge_msgs/GetAttributeService.h"
#include "rosplan_dispatch_msgs/ActionDispatch.h"
#include "rosplan_dispatch_msgs/ActionFeedback.h"

#include "std_msgs/String.h"
#include "std_srvs/Empty.h"

#ifndef KCL_action_monitor
#define KCL_action_monitor

/**
 * This file defines the RPActionMonitor class.
 * RPActionMonitor is used to record the duration and success rate of actions.
 */
namespace KCL_rosplan {

	class RPActionMonitor
	{

	private:

		ros::NodeHandle* node_handle;

		/* rosplan knowledge interface */
		ros::ServiceClient current_knowledge_client;

	public:

		/* constructor */
		RPActionMonitor(ros::NodeHandle &nh);

		/* plan topic callback */
		void dispatchCallback(const rosplan_dispatch_msgs::ActionDispatch& msg);
		void feedbackCallback(const rosplan_dispatch_msgs::ActionFeedback& msg);
	};
}
#endif
