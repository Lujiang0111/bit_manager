#include "bit_manager_api.h"
#include "bit_reader.h"
#include "bit_writer.h"

namespace bitmgr
{

std::shared_ptr<IBitReader> CreateBitReader(const uint8_t *data, size_t data_size, ByteOrders byte_order)
{
    if (!data)
    {
        return nullptr;
    }

    return std::make_shared<BitReader>(data, data_size, byte_order);
}

std::shared_ptr<IBitWriter> CreateBitWriter(size_t buf_size, ByteOrders byte_order)
{
    return std::make_shared<BitWriter>(nullptr, buf_size, byte_order);
}

std::shared_ptr<IBitWriter> CreateBitWriterWithBuffer(uint8_t *buf, size_t buf_size, ByteOrders byte_order)
{
    if (!buf)
    {
        return nullptr;
    }

    return std::make_shared<BitWriter>(buf, buf_size, byte_order);
}

}
