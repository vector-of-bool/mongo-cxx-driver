// Copyright 2009-present MongoDB, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <mongocxx/write_concern.hpp>

#include <mongocxx/private/mongoc.hh>

namespace mongocxx {
namespace v_noabi {

class write_concern::impl {
   public:
    impl(mongoc_write_concern_t* write_concern) : write_concern_t(write_concern) {}

    ~impl() {
        libmongoc::write_concern_destroy(write_concern_t);
    }

    impl(impl&&) = delete;
    impl& operator=(impl&&) = delete;

    impl(impl const&) = delete;
    impl& operator=(impl const&) = delete;

    mongoc_write_concern_t* write_concern_t;
};

} // namespace v_noabi
} // namespace mongocxx
