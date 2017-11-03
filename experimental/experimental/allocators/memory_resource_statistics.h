#pragma once

#include <experimental/memory_resource>
#include <allocators/memory_pool_fixed_size.h>
#include <cstdint>

// Do not care to make the namespace global
namespace pmr = std::experimental::fundamentals_v2::pmr;

namespace experimental
{
    template <typename StatisticsHandler>
    class MemoryResourceStatistics : public pmr::memory_resource
    {
    public:
        explicit MemoryResourceStatistics(StatisticsHandler& iStatisticsHandler, pmr::memory_resource* iDefaultResource = pmr::get_default_resource());

    protected:
         virtual void* do_allocate(std::size_t iBytes, std::size_t iAlignment) override;
         virtual void do_deallocate(void* iPointer, std::size_t iBytes, std::size_t iAlignment) override;
         virtual bool do_is_equal(const pmr::memory_resource& iMemoryResource) const noexcept override;

    private:
         StatisticsHandler& m_StatisticsHandler;
         pmr::memory_resource* m_DefaultResource;
    };
}

#include <allocators/memory_resource_statistics.hxx>