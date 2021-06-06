#include "BP_Controller.h"
BP_Controller* BP_Controller::unique_instance{ nullptr };
mutex BP_Controller::mutex_;

BP_Controller::BP_Controller()
{
}

BP_Controller::~BP_Controller() {}

/**
 * @brief Getter for the static class instance
 * @return the static instance
*/
BP_Controller* BP_Controller::getInstance()
{
	lock_guard<std::mutex> lock(mutex_);
	if (unique_instance == nullptr) { unique_instance = new BP_Controller(); }
	return unique_instance;
}