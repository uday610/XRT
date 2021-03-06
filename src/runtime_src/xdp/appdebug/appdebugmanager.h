/**
 * Copyright (C) 2016-2020 Xilinx, Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may
 * not use this file except in compliance with the License. A copy of the
 * License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#ifndef APP_DEBUG_MANAGER_DOT_H
#define APP_DEBUG_MANAGER_DOT_H

#include "xocl/core/platform.h"

namespace appdebug {

  class AppDebugManager
  {
  private:
    std::shared_ptr<xocl::platform> Platform ;

  public:
    AppDebugManager() ;
    ~AppDebugManager() ;

    inline xocl::platform* getcl_platform_id() { return Platform.get() ; }

    static bool isActive() ;
  } ;

} // end namespace appdebug

#endif
