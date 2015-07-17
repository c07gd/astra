#ifndef FRAMEINPUTSTREAM_H
#define FRAMEINPUTSTREAM_H

#include "StreamFileModels.h"
#include <cstdint>
#include <exception>

// Is noexcept supported?
#if defined(__clang__) && __has_feature(cxx_noexcept) ||                \
    defined(__GXX_EXPERIMENTAL_CXX0X__) && __GNUC__ * 10 + __GNUC_MINOR__ >= 46 || \
    defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 180021114
#  define NOEXCEPT noexcept
#else
#  define NOEXCEPT
#endif

namespace sensekit { namespace serialization {


    class ResourceNotFoundException : std::exception
    {
    public:
        ResourceNotFoundException(const char* uri)
            : m_uri(uri)
        {

        }

        const char* what() const NOEXCEPT override
        {
            return m_uri;
        }

    private:
        const char* m_uri;
    };

    class FrameInputStream
    {
    public:
        FrameInputStream() { }
        virtual ~FrameInputStream() { }

        virtual void close() = 0;
        virtual bool read_frame(Frame*& frame) = 0;
        virtual bool read_frame_description(FrameDescription*& frameDescription) = 0;
        virtual bool read_stream_header(StreamHeader*& streamHeader) = 0;
        virtual bool seek(int offset) = 0;
        virtual bool seek_to_first_frame() = 0;
        virtual int64_t get_position() = 0;
        virtual bool is_end_of_file() = 0;
        virtual int get_frame_description_size() = 0;
        virtual int get_stream_header_size() = 0;
    };
}}

#endif /* FRAMEINPUTSTREAM_H */