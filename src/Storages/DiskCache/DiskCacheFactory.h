/*
 * Copyright (2022) Bytedance Ltd. and/or its affiliates
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <Storages/DiskCache/DiskCache_fwd.h>
#include <common/singleton.h>

namespace DB
{
class Context;

class DiskCacheFactory : public ext::singleton<DiskCacheFactory>
{
public:
    using CacheEntry = std::pair<IDiskCachePtr, IDiskCacheStrategyPtr>;

    void init(Context & global_context);
    void shutdown() const;

    CacheEntry getDefault() const { return default_cache; }

private:
    // std::unordered_map<String, CacheEntry> caches;
    CacheEntry default_cache;
};
}
