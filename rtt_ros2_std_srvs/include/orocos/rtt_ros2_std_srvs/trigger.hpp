// Copyright 2020 Intermodalics BVBA
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef OROCOS__RTT_ROS2_STD_SRVS__TRIGGER_HPP_
#define OROCOS__RTT_ROS2_STD_SRVS__TRIGGER_HPP_

#include <memory>
#include <string>

#include "rtt_ros2_services/rtt_ros2_services_proxy.hpp"
#include "std_srvs/srv/trigger.hpp"

// Specialized implementations of RosServiceServerOperationCallerWrapper for std_srvs/srv/Trigger.
//
// Accepted signatures:
//  - bool trigger(Request&, Response&) // the default signature
//  - bool trigger(std::string &message_out)
//  - bool trigger() // response->message will be empty
//  - std::string trigger() // response->success = true
//

namespace rtt_ros2_services
{

template<>
struct RosServiceServerOperationCallerWrapper<std_srvs::srv::Trigger, 1>
{
  typedef bool Signature (std::string & message_out);
  typedef RTT::OperationCaller<Signature> ProxyOperationCallerType;
  template<typename Callable>
  static void dispatch(
    Callable & call,
    std::shared_ptr<rmw_request_id_t>,
    std_srvs::srv::Trigger::Request::SharedPtr request,
    std_srvs::srv::Trigger::Response::SharedPtr response)
  {
    response->success = call(response->message);
  }
};

template<>
struct RosServiceServerOperationCallerWrapper<std_srvs::srv::Trigger, 2>
{
  typedef bool Signature ();
  typedef RTT::OperationCaller<Signature> ProxyOperationCallerType;
  template<typename Callable>
  static void dispatch(
    Callable & call,
    std::shared_ptr<rmw_request_id_t>,
    std_srvs::srv::Trigger::Request::SharedPtr request,
    std_srvs::srv::Trigger::Response::SharedPtr response)
  {
    response->success = call();
  }
};

template<>
struct RosServiceServerOperationCallerWrapper<std_srvs::srv::Trigger, 3>
{
  typedef std::string Signature ();
  typedef RTT::OperationCaller<Signature> ProxyOperationCallerType;
  template<typename Callable>
  static void dispatch(
    Callable & call,
    std::shared_ptr<rmw_request_id_t>,
    std_srvs::srv::Trigger::Request::SharedPtr request,
    std_srvs::srv::Trigger::Response::SharedPtr response)
  {
    response->message = call();
    response->success = true;
  }
};

}  // namespace rtt_ros2_services

#endif  // OROCOS__RTT_ROS2_STD_SRVS__TRIGGER_HPP_
