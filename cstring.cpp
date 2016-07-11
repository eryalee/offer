

#include <stdio.h>
#include <string.h>
#include <new>

class CString {
public:
    CString() {
        data_ = new (std::nothrow) char[1];
        if (data_ == NULL) {
            throw "init data failed.";
        }
        *data_ = '\0';
    }
    ~CString() {
        if (NULL != data_) {
            delete [] data_;
            data_ = NULL;
        }
    }
    CString(const CString& other) {
        int len = strlen(other.data_);
        if (len < 0) {
            throw "len error.";
        }
        data_ = new (std::nothrow) char[len + 1];
        if (NULL == data_) {
            throw "new data failed.";
        }
        int offset = snprintf(data_, len + 1, "%s", other.data_);
        if (offset != len) {
            throw "copy data failed.";
        }
    }
    CString& operator=(const CString& other) {
        if (this != &other) {
            CString temp(other);
            char *p_c = data_;
            data_ = temp.data_;
            temp.data_ = p_c;
        }
        return *this;
    }
private:
    char *data_;
};

int main() {
    return 0;
}
