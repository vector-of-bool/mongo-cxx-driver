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

#include <mongocxx/events/server_opening_event.hpp>

#include <mongocxx/private/mongoc.hh>

namespace mongocxx {
namespace v_noabi {
namespace events {

server_opening_event::server_opening_event(void const* event) : _event(event) {}

server_opening_event::~server_opening_event() = default;

bsoncxx::v_noabi::stdx::string_view server_opening_event::host() const {
    return libmongoc::apm_server_changed_get_host(static_cast<mongoc_apm_server_changed_t const*>(_event))->host;
}

std::uint16_t server_opening_event::port() const {
    return libmongoc::apm_server_changed_get_host(static_cast<mongoc_apm_server_changed_t const*>(_event))->port;
}

bsoncxx::v_noabi::oid const server_opening_event::topology_id() const {
    bson_oid_t boid;
    libmongoc::apm_server_changed_get_topology_id(static_cast<mongoc_apm_server_changed_t const*>(_event), &boid);

    return bsoncxx::v_noabi::oid{reinterpret_cast<char const*>(boid.bytes), sizeof(boid.bytes)};
}

} // namespace events
} // namespace v_noabi
} // namespace mongocxx
