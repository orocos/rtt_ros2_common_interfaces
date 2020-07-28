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

#ifndef OROCOS__RTT_ROS2_STD_SRVS__EMPTY_HPP_
#define OROCOS__RTT_ROS2_STD_SRVS__EMPTY_HPP_

#include <memory>
#include <string>

#include "rtt_ros2_services/rtt_ros2_services_proxy.hpp"
#include "std_srvs/srv/empty.h"

// Specialized implementations of RosServiceServerOperationCallerWrapper for std_srvs/srv/Empty.
//
// Accepted signatures:
//  - bool empty(Request&, Response&) // the default signature
//  - void empty()
//

namespace rtt_ros2_services
{

template<>
struct RosServiceServerOperationCallerWrapper<std_srvs::srv::Empty, 1>
{
  typedef void Signature ();
  typedef RTT::OperationCaller<Signature> ProxyOperationCallerType;
  template<typename Callable>
  static void dispatch(
    Callable & call,
    std::shared_ptr<rmw_request_id_t>,
    std_srvs::srv::Empty::Request::SharedPtr,
    std_srvs::srv::Empty::Response::SharedPtr)
  {
    call();
  }
};

}  // namespace rtt_ros2_services

#endif  // OROCOS__RTT_ROS2_STD_SRVS__EMPTY_HPP_
