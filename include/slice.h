#ifndef MYC_SLICE_H
#define MYC_SLICE_H
#include <cstring>
#include <string>
#include <cassert>
namespace MyC
{
    class Slice
    {
    public:
        Slice() : data_(""), size_(0){};
        Slice(const char *d, size_t n) : data_(d), size_(n){};
        Slice(const std::string &str) : data_(str.c_str()), size_(str.size()){};
        Slice(const char *s) : data_(s), size_(strlen(s)){};
        Slice(const Slice &) = default;
        Slice &operator=(const Slice &) = default;
        const char *data() const { return data_; }
        size_t size() const { return size_; }
        bool empty() { return size_ == 0; }
        char operator[](size_t n) const
        {
            assert(n < size_);
            return data_[n];
        }
        void clean()
        {
            data_ = "";
            size_ = 0;
        }

        void remove_prefix(size_t n)
        {
            assert(n <= size_);
            data_ += n;
            size_ -= n;
        }

        std::string ToString() const
        {
            std::string r;
            r.append(data_, size_);
            return r;
        }

        int comparse(const Slice &) const;

        bool start_with(const Slice &x) const
        {
            return ((size_ >= x.size_) && memcmp(data_, x.data_, x.size_) == 0);
        }

    private:
        const char *data_;
        size_t size_;
    };
    inline bool operator==(const Slice &x, const Slice &y)
    {
        return ((x.size() == y.size()) &&
                (memcmp(x.data(), y.data(), x.size()) == 0));
    }
    inline bool operator!=(const Slice &x, const Slice &y) { return !(x == y); }
    inline int Slice::comparse(const Slice &b) const
    {
        const size_t min_len = (size_ < b.size()) ? size_ : b.size_;
        int r = memcmp(data_, b.data_, min_len);
        if (r == 0)
        {
            if (size_ < b.size_)
                r = -1;
            else if (size_ > b.size_)
                r = +1;
        }
        return r;
    }

};
#endif