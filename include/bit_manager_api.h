#ifndef BIT_MANAGER_INCLUDE_BIT_MANAGER_API_H_
#define BIT_MANAGER_INCLUDE_BIT_MANAGER_API_H_

#include <cstddef>
#include <cstdint>
#include <memory>

#if defined(_WIN32)
#if defined(BITMGR_API_EXPORT)
#define BITMGR_API __declspec(dllexport)
#else
#define BITMGR_API __declspec(dllimport)
#endif
#else
#define BITMGR_API
#endif

namespace bitmgr
{

enum class ByteOrders : int
{
    kLe = 0,
    kBe,
};

class IBitReader
{
public:
    virtual ~IBitReader() = default;

    // bit
    virtual int64_t ReadBits(size_t bits) = 0;
    virtual int64_t ReadUe() = 0;
    virtual int64_t ReadSe() = 0;
    virtual void ReadAlign() = 0;

    // byte
    virtual int64_t ReadByte() = 0;
    virtual int64_t Read2Bytes() = 0;
    virtual int64_t Read4Bytes() = 0;
    virtual int64_t Read8Bytes() = 0;

    // byte stream
    virtual void ReadBytes(uint8_t *buf, size_t size) = 0;

    // skip
    virtual void SkipBits(size_t bits) = 0;
    virtual void SkipBytes(size_t bytes) = 0;

    // save/load
    virtual int64_t Save() = 0;
    virtual bool Load(int64_t saved_point) = 0;
    virtual void ClearSave(int64_t saved_point) = 0;

    virtual size_t Size() const = 0;
    virtual bool IsAvailable(size_t size) const = 0;
};

BITMGR_API std::shared_ptr<IBitReader> CreateBitReader(const uint8_t *data, size_t data_size = 0, ByteOrders byte_order = ByteOrders::kBe);

class IBitWriter
{
public:
    virtual ~IBitWriter() = default;

    // bit
    virtual void WriteBits(int64_t val, size_t bits) = 0;
    virtual void WriteUe(int64_t val) = 0;
    virtual void WriteSe(int64_t val) = 0;
    virtual void WriteAlign() = 0;

    // byte
    virtual void WriteByte(int64_t val) = 0;
    virtual void Write2Bytes(int64_t val) = 0;
    virtual void Write4Bytes(int64_t val) = 0;
    virtual void Write8Bytes(int64_t val) = 0;

    // byte stream
    virtual void WriteBytes(const uint8_t *data, size_t size) = 0;

    // skip
    virtual void SkipBits(size_t bits) = 0;
    virtual void SkipBytes(size_t bytes) = 0;

    // save/load
    virtual int64_t Save() = 0;
    virtual bool Load(int64_t saved_point) = 0;
    virtual void ClearSave(int64_t saved_point) = 0;

    virtual uint8_t *Buf() = 0;
    virtual size_t Size() const = 0;
    virtual bool IsAvailable(size_t size) const = 0;
};

BITMGR_API std::shared_ptr<IBitWriter> CreateBitWriter(size_t buf_size = 0, ByteOrders byte_order = ByteOrders::kBe);

BITMGR_API std::shared_ptr<IBitWriter> CreateBitWriterWithBuffer(uint8_t *buf, size_t buf_size = 0, ByteOrders byte_order = ByteOrders::kBe);

}

#endif // !BIT_MANAGER_INCLUDE_BIT_MANAGER_API_H_
