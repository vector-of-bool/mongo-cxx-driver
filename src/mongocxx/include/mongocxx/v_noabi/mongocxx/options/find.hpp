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

#include <chrono>
#include <cstdint>

#include <mongocxx/options/find-fwd.hpp>

#include <bsoncxx/document/view_or_value.hpp>
#include <bsoncxx/stdx/optional.hpp>
#include <bsoncxx/string/view_or_value.hpp>
#include <bsoncxx/types/bson_value/view_or_value.hpp>

#include <mongocxx/cursor.hpp>
#include <mongocxx/hint.hpp>
#include <mongocxx/read_preference.hpp>

#include <mongocxx/config/prelude.hpp>

namespace mongocxx {
namespace v_noabi {
namespace options {

///
/// Used by MongoDB find operations.
///
class find {
   public:
    ///
    /// Enables writing to temporary files on the server. When set to true, the server
    /// can write temporary data to disk while executing the find operation.
    ///
    /// This option is sent only if the caller explicitly provides a value. The default
    /// is to not send a value.
    ///
    /// This option may only be used with MongoDB version 4.4 or later.
    ///
    /// @param allow_disk_use
    ///   Whether to allow writing temporary files on the server.
    ///
    /// @return
    ///   A reference to this object to facilitate method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) allow_disk_use(bool allow_disk_use);

    ///
    /// Gets the current setting for allowing disk use on the server.
    ///
    /// This option may only be used with MongoDB version 4.4 or later.
    ///
    /// @return Whether disk use on the server is allowed.
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bool> const&) allow_disk_use() const;

    ///
    /// Sets whether to allow partial results from a mongos if some shards are down (instead of
    /// throwing an error).
    ///
    /// @param allow_partial
    ///   Whether to allow partial results from mongos.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) allow_partial_results(bool allow_partial);

    ///
    /// Gets the current setting for allowing partial results from mongos.
    ///
    /// @return Whether partial results from mongos are allowed.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bool> const&)
    allow_partial_results() const;

    ///
    /// Sets the number of documents to return per batch.
    ///
    /// @param batch_size
    ///   The size of the batches to request.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) batch_size(std::int32_t batch_size);

    ///
    /// The current batch size setting.
    ///
    /// @return The current batch size.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<std::int32_t> const&)
    batch_size() const;

    ///
    /// Sets the collation for this operation.
    ///
    /// @param collation
    ///   The new collation.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) collation(bsoncxx::v_noabi::document::view_or_value collation);

    ///
    /// Retrieves the current collation for this operation.
    ///
    /// @return
    ///   The current collation.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> const&)
    collation() const;

    ///
    /// Attaches a comment to the query. If $comment also exists in the modifiers document then
    /// the comment field overwrites $comment.
    ///
    /// @deprecated use comment_option instead.
    ///
    /// @param comment
    ///   The comment to attach to this query.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) comment(bsoncxx::v_noabi::string::view_or_value comment);

    ///
    /// Gets the current comment attached to this query.
    ///
    /// @deprecated use comment_option instead.
    ///
    /// @return The comment attached to this query.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::string::view_or_value> const&)
    comment() const;

    ///
    /// Indicates the type of cursor to use for this query.
    ///
    /// @param cursor_type
    ///   The cursor type to set.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) cursor_type(cursor::type cursor_type);

    ///
    /// Gets the current cursor type.
    ///
    /// @return The current cursor type.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<cursor::type> const&)
    cursor_type() const;

    ///
    /// Sets the index to use for this operation.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    /// @note if the server already has a cached shape for this query, it may
    /// ignore a hint.
    ///
    /// @param index_hint
    ///   Object representing the index to use.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) hint(mongocxx::v_noabi::hint index_hint);

    ///
    /// Gets the current hint.
    ///
    /// @return The current hint, if one is set.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<mongocxx::v_noabi::hint> const&)
    hint() const;

    ///
    /// Set the value of the let option.
    ///
    /// @param let
    ///   The new let option.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) let(bsoncxx::v_noabi::document::view_or_value let);

    ///
    /// Gets the current value of the let option.
    ///
    /// @return
    ///  The current let option.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> const)
    let() const;

    ///
    /// Set the value of the comment option.
    ///
    /// @note Not to be confused with the $comment query modifier.
    ///
    /// @param comment
    ///   The new comment option.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&)
    comment_option(bsoncxx::v_noabi::types::bson_value::view_or_value comment);

    ///
    /// Gets the current value of the comment option.
    ///
    /// @note Not to be confused with the $comment query modifier.
    ///
    /// @return
    ///  The current comment option.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::types::bson_value::view_or_value> const&)
    comment_option() const;

    ///
    /// Sets maximum number of documents to return.
    ///
    /// @param limit
    ///   The maximum number of documents to return.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) limit(std::int64_t limit);

    ///
    /// Gets the current limit.
    ///
    /// @return The current limit.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<std::int64_t> const&) limit() const;

    ///
    /// Gets the current exclusive upper bound for a specific index.
    ///
    /// @param max
    ///   The exclusive upper bound for a specific index.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) max(bsoncxx::v_noabi::document::view_or_value max);

    ///
    /// Sets the current exclusive upper bound for a specific index.
    ///
    /// @return The exclusive upper bound for a specific index.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> const&)
    max() const;

    ///
    /// The maximum amount of time for the server to wait on new documents to satisfy a tailable
    /// cursor query. This only applies to a TAILABLE_AWAIT cursor. When the cursor is not a
    /// TAILABLE_AWAIT cursor, this option is ignored. The default on the server is to wait for one
    /// second.
    ///
    /// @note On servers < 3.2, this option is ignored.
    ///
    /// @param max_await_time
    ///   The max amount of time (in milliseconds) to wait for new documents.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) max_await_time(std::chrono::milliseconds max_await_time);

    ///
    /// The maximum amount of time for the server to wait on new documents to satisfy a tailable
    /// cursor query.
    ///
    /// @return The current max await time (in milliseconds).
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<std::chrono::milliseconds> const&)
    max_await_time() const;

    ///
    /// Sets the maximum amount of time for this operation to run (server-side) in milliseconds.
    ///
    /// @param max_time
    ///   The max amount of time (in milliseconds).
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) max_time(std::chrono::milliseconds max_time);

    ///
    /// The current max_time_ms setting.
    ///
    /// @return The current max time (in milliseconds).
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<std::chrono::milliseconds> const&)
    max_time() const;

    ///
    /// Gets the current inclusive lower bound for a specific index.
    ///
    /// @param min
    ///   The inclusive lower bound for a specific index.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) min(bsoncxx::v_noabi::document::view_or_value min);

    ///
    /// Sets the current inclusive lower bound for a specific index.
    ///
    /// @return The inclusive lower bound for a specific index.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> const&)
    min() const;

    ///
    /// Sets the cursor flag to prevent cursor from timing out server-side due to a period of
    /// inactivity.
    ///
    /// @param no_cursor_timeout
    ///   When true prevents the cursor from timing out.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) no_cursor_timeout(bool no_cursor_timeout);

    ///
    /// Gets the current no_cursor_timeout setting.
    ///
    /// @return The current no_cursor_timeout setting.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bool> const&)
    no_cursor_timeout() const;

    ///
    /// Sets a projection which limits the returned fields for all matching documents.
    ///
    /// @param projection
    ///   The projection document.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&)
    projection(bsoncxx::v_noabi::document::view_or_value projection);

    ///
    /// Gets the current projection set on this query.
    ///
    /// @return The current projection.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> const&)
    projection() const;

    ///
    /// Sets the read_preference for this operation.
    ///
    /// @param rp
    ///   The new read_preference.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) read_preference(mongocxx::v_noabi::read_preference rp);

    ///
    /// The current read_preference for this operation.
    ///
    /// @return
    ///   The current read_preference.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<mongocxx::v_noabi::read_preference> const&)
    read_preference() const;

    ///
    /// Sets whether to return the index keys associated with the query results, instead of the
    /// actual query results themselves.
    ///
    /// @param return_key
    ///   Whether to return the index keys associated with the query results, instead of the actual
    ///   query results themselves.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) return_key(bool return_key);

    ///
    /// Gets the current setting for returning the index keys associated with the query results,
    /// instead of the actual query results themselves.
    ///
    /// @return
    ///   Whether index keys associated with the query results are returned, instead of the actual
    ///   query results themselves.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bool> const&) return_key() const;

    ///
    /// Sets whether to include the record identifier for each document in the query results.
    ///
    /// @param show_record_id
    ///   Whether to include the record identifier.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) show_record_id(bool show_record_id);

    ///
    /// Gets the current setting for whether the record identifier is returned for each document in
    /// the query results.
    ///
    /// @return
    ///   Whether the record identifier is included.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bool> const&) show_record_id() const;

    ///
    /// Sets the number of documents to skip before returning results.
    ///
    /// @param skip
    ///   The number of documents to skip.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) skip(std::int64_t skip);

    ///
    /// Gets the current number of documents to skip.
    ///
    /// @return The number of documents to skip.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<std::int64_t> const&) skip() const;

    ///
    /// The order in which to return matching documents. If $orderby also exists in the modifiers
    /// document, the sort field takes precedence over $orderby.
    ///
    /// @param ordering
    ///   Document describing the order of the documents to be returned.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(find&) sort(bsoncxx::v_noabi::document::view_or_value ordering);

    ///
    /// Gets the current sort ordering for this query.
    ///
    /// @return The current sort ordering.
    ///
    /// @see
    /// - https://www.mongodb.com/docs/manual/reference/command/find/
    ///
    MONGOCXX_ABI_EXPORT_CDECL(bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> const&)
    sort() const;

   private:
    bsoncxx::v_noabi::stdx::optional<bool> _allow_disk_use;
    bsoncxx::v_noabi::stdx::optional<bool> _allow_partial_results;
    bsoncxx::v_noabi::stdx::optional<std::int32_t> _batch_size;
    bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> _collation;
    bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::string::view_or_value> _comment;
    bsoncxx::v_noabi::stdx::optional<cursor::type> _cursor_type;
    bsoncxx::v_noabi::stdx::optional<mongocxx::v_noabi::hint> _hint;
    bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> _let;
    bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::types::bson_value::view_or_value> _comment_option;
    bsoncxx::v_noabi::stdx::optional<std::int64_t> _limit;
    bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> _max;
    bsoncxx::v_noabi::stdx::optional<std::chrono::milliseconds> _max_await_time;
    bsoncxx::v_noabi::stdx::optional<std::chrono::milliseconds> _max_time;
    bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> _min;
    bsoncxx::v_noabi::stdx::optional<bool> _no_cursor_timeout;
    bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> _projection;
    bsoncxx::v_noabi::stdx::optional<mongocxx::v_noabi::read_preference> _read_preference;
    bsoncxx::v_noabi::stdx::optional<bool> _return_key;
    bsoncxx::v_noabi::stdx::optional<bool> _show_record_id;
    bsoncxx::v_noabi::stdx::optional<std::int64_t> _skip;
    bsoncxx::v_noabi::stdx::optional<bsoncxx::v_noabi::document::view_or_value> _ordering;
};

} // namespace options
} // namespace v_noabi
} // namespace mongocxx

#include <mongocxx/config/postlude.hpp>

///
/// @file
/// Provides @ref mongocxx::v_noabi::options::find.
///
