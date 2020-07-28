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

#ifndef OROCOS__RTT_ROS2_STD_SRVS__SET_BOOL_HPP_
#define OROCOS__RTT_ROS2_STD_SRVS__SET_BOOL_HPP_

#include <memory>
#include <string>

#include "rtt_ros2_services/rtt_ros2_services_proxy.hpp"
#include "std_srvs/srv/set_bool.h"

// Specialized implementation of RosServiceServerOperationCallerWrapper for std_srvs/srv/SetBool.
//
// Accepted signatures:
//  - bool setBool(Request&, Response&) // the default signature
//  - bool setBool(bool, std::string &message_out)
//  - bool setBool(bool) // response.message will be empty
//  - std::string setBool(bool) // response.success = true
//  - void setBool(bool) // response.success = true and response.message will be empty
//

namespace rtt_ros2_services
{

template<>
struct RosServiceServerOperationCallerWrapper<std_srvs::srv::SetBool, 1>
{
  typedef bool Signature (bool, std::string &);
  typedef RTT::OperationCaller<Signature> ProxyOperationCallerType;
  template<typename Callable>
  static void dispatch(
    Callable & call,
    std::shared_ptr<rmw_request_id_t>,
    std_srvs::srv::SetBool::Request::SharedPtr request,
    std_srvs::srv::SetBool::Response::SharedPtr response)
  {
    response->success = call(request->data, response->message);
  }
};

template<>
struct RosServiceServerOperationCallerWrapper<std_srvs::srv::SetBool, 2>
{
  typedef bool Signature (bool);
  typedef RTT::OperationCaller<Signature> ProxyOperationCallerType;
  template<typename Callable>
  static void dispatch(
    Callable & call,
    std::shared_ptr<rmw_request_id_t>,
    std_srvs::srv::SetBool::Request::SharedPtr request,
    std_srvs::srv::SetBool::Response::SharedPtr response)
  {
    response->success = call(request->data);
  }
};

template<>
struct RosServiceServerOperationCallerWrapper<std_srvs::srv::SetBool, 3>
{
  typedef std::string Signature (bool);
  typedef RTT::OperationCaller<Signature> ProxyOperationCallerType;
  template<typename Callable>
  static void dispatch(
    Callable & call,
    std::shared_ptr<rmw_request_id_t>,
    std_srvs::srv::SetBool::Request::SharedPtr request,
    std_srvs::srv::SetBool::Response::SharedPtr response)
  {
    response->message = call(request->data);
    response->success = true;
  }
};

template<>
struct RosServiceServerOperationCallerWrapper<std_srvs::srv::SetBool, 4>
{
  typedef void Signature (bool);
  typedef RTT::OperationCaller<Signature> ProxyOperationCallerType;
  template<typename Callable>
  static void dispatch(
    Callable & call,
    std::shared_ptr<rmw_request_id_t>,
    std_srvs::srv::SetBool::Request::SharedPtr request,
    std_srvs::srv::SetBool::Response::SharedPtr response)
  {
    call(request->data);
    response->success = true;
  }
};

}  // namespace rtt_ros2_services

#endif  // OROCOS__RTT_ROS2_STD_SRVS__SET_BOOL_HPP_
