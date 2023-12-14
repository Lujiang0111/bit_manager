#include "bit_manager_api.h"
#include "bit_reader.h"
#include "bit_writer.h"

namespace bitmgr
{

std::shared_ptr<IBitReader> CreateBitReader(const uint8_t *data, ByteOrders byte_order)
{
    if (!data)
    {
        return nullptr;
    }

    return std::make_shared<BitReader>(data, byte_order);
}

std::shared_ptr<IBitWriter> CreateBitWriter(ByteOrders byte_order)
{
    return std::make_shared<BitWriter>(nullptr, byte_order);
}

std::shared_ptr<IBitWriter> CreateBitWriterWithBuffer(uint8_t *buf, ByteOrders byte_order)
{
    if (!buf)
    {
        return nullptr;
    }

    return std::make_shared<BitWriter>(buf, byte_order);
}

}
