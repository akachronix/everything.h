#pragma once

#include <istream>
#include <ostream>
#include <cstring>
#include <iterator>

#include "utility.hpp"

namespace brisk
{
    class string
    {
    private:
        char* m_string;
        size_t m_size;  // this does NOT include the null termination character
    
    public:
        string()
        {
            m_string = nullptr;
            m_size = 0;
        }

        string(const char* s)
        {
            m_size = strlen(s);
            m_string = new char[m_size + 1];
            std::memcpy(m_string, s, m_size + 1);
        }

        string(size_t sz)
        {
            m_size = sz;
            m_string = new char[sz + 1];
        }

        string(const string& other)
        {
            if (m_string != nullptr)
                delete[] m_string;
            
            m_string = new char[other.m_size + 1];
            m_size = other.m_size;
            memcpy(m_string, other.m_string, other.m_size + 1);
        }

        string(string&& other)
        {
            m_string = other.m_string;
            m_size = brisk::move(other.m_size);
            other.m_string = nullptr;
            other.m_size = 0;
        }

        ~string()
        {
            if (m_string != nullptr)
                delete[] m_string;
        }

        string& operator=(const string& str)
        {
            if (m_string != nullptr)
                delete[] m_string;
            
            m_size = str.size();
            m_string = new char[m_size + 1];

            std::memcpy(m_string, str.data(), m_size + 1);

            return *this;
        }

        string& operator=(const char* s)
        {
            if (m_string != nullptr)
                delete[] m_string;
            
            m_size = strlen(s);
            m_string = new char[m_size + 1];

            std::memcpy(m_string, s, m_size + 1);

            return *this;
        }
        
        string& operator=(char c)
        {
            if (m_string != nullptr)
                delete[] m_string;
            
            m_size = sizeof(char);
            m_string = new char[2];

            m_string[0] = c;
            m_string[1] = '\0';

            return *this;
        }

        string& operator+=(const string& str)
        {
            this->append(str);
            return *this;
        }

        string& append(const string& str)
        {
            // copy old string into a buffer for safe-keeping
            char* old_str = nullptr;
            if (m_string != nullptr) {
                old_str = new char[m_size + 1];
                memcpy(old_str, m_string, m_size + 1);
                delete[] m_string;
            }

            // create new string and concatenate
            m_string = new char[m_size + str.size() + 1];
            if (old_str != nullptr) {
                memcpy(m_string, old_str, m_size);
            }
            memcpy(m_string + m_size, str.data(), str.size());
            m_string[m_size + str.size() + 1] = '\0';
            m_size += str.size();

            delete[] old_str;
            return *this;
        }

        string& append(const char* s)
        {
            // copy old string into a buffer for safe-keeping
            char* old_str = nullptr;
            if (m_string != nullptr) {
                old_str = new char[m_size + 1];
                memcpy(old_str, m_string, m_size + 1);
                delete[] m_string;
            }

            // create new string and concatenate
            m_string = new char[m_size + strlen(s) + 1];
            if (old_str != nullptr) {
                memcpy(m_string, old_str, m_size);
            }
            memcpy(m_string + m_size, s, strlen(s));
            m_string[m_size + strlen(s) + 1] = '\0';
            m_size += strlen(s);

            delete[] old_str;
            return *this;
        }

        string& append(char c)
        {
            // copy old string into a buffer for safe-keeping
            char* old_str = nullptr;
            if (m_string != nullptr) {
                old_str = new char[m_size + 1];
                memcpy(old_str, m_string, m_size + 1);
                delete[] m_string;
            }

            // create new string and concatenate
            m_string = new char[m_size + 2];
            if (old_str != nullptr) {
                memcpy(m_string, old_str, m_size);
            }
            memcpy(m_string + m_size, &c, 1);
            m_string[m_size + 2] = '\0';
            m_size += 1;

            delete[] old_str;
            return *this;
        }

        string& insert(size_t index, const char* s)
        {
            char* old_str = new char[m_size + 1];
            memcpy(old_str, m_string, m_size + 1);

            if (m_string != nullptr)
                delete[] m_string;
            
            m_string = new char[m_size + strlen(s) + 1];
            memcpy(m_string, old_str, index + 1);
            memcpy(m_string + index, s, strlen(s));
            memcpy(m_string + index + strlen(s), old_str + index, m_size - index);
            
            m_size += strlen(s);
            m_string[m_size + 1] = '\0';

            delete[] old_str;
            return *this;
        }

        string& insert(size_t index, char c)
        {
            char* old_str = new char[m_size + 1];
            memcpy(old_str, m_string, m_size + 1);

            if (m_string != nullptr)
                delete[] m_string;
            
            m_string = new char[m_size + 2];
            memcpy(m_string, old_str, index + 1);
            memcpy(m_string + index, &c, 1);
            memcpy(m_string + index + 1, old_str + index, m_size - index);
            
            m_size += 1;
            m_string[m_size + 1] = '\0';

            delete[] old_str;
            return *this;
        }

        char* begin() noexcept
        {
            return &m_string[0];
        }

        char* end() noexcept
        {
            return &m_string[m_size + 1];
        }

        const char* cbegin() const noexcept
        {
            return &m_string[0];
        }

        const char* cend() const noexcept
        {
            return &m_string[m_size + 1];
        }

        std::reverse_iterator<char*> rbegin() noexcept
        {
            return std::reverse_iterator<char*>(&m_string[m_size + 1]);
        }

        std::reverse_iterator<char*> rend() noexcept
        {
            return std::reverse_iterator<char*>(&m_string[0]);
        }

        std::reverse_iterator<const char*> crbegin() const noexcept
        {
            return std::reverse_iterator<const char*>(&m_string[m_size + 1]);
        }

        std::reverse_iterator<const char*> crend() const noexcept
        {
            return std::reverse_iterator<const char*>(&m_string[0]);
        }

        size_t size() const noexcept
        {
            return m_size;
        }

        size_t length() const noexcept
        {
            return m_size;
        }

        char& operator[](size_t index)
        {
            return m_string[index];
        }

        const char& operator[](size_t index) const
        {
            return m_string[index];
        }

        char& at(size_t index)
        {
            if (index > (m_size + 1))
                throw std::out_of_range("index out of range");
            
            return m_string[index];
        }

        const char& at(size_t index) const
        {
            if (index > (m_size + 1))
                throw std::out_of_range("index out of range");
            
            return m_string[index];
        }

        char& front()
        {
            return m_string[0];
        }

        char& back()
        {
            return m_string[m_size];
        }

        const char& front() const
        {
            return m_string[0];
        }

        const char& back() const
        {
            return m_string[m_size];
        }

        char* data() const noexcept
        {
            return m_string;
        }

        const char* c_str() const noexcept
        {
            return m_string;
        }

        friend std::ostream& operator<<(std::ostream& out, const brisk::string& string);
	    friend std::istream& operator>>(std::istream& in, brisk::string& string);
    };
    
    std::ostream& operator<<(std::ostream& out, const brisk::string& string)
    {
        out << string.m_string;
        return out;
    }

    std::istream& operator>>(std::istream &in, brisk::string &string);

    string operator+(const string& lhs, const string& rhs)
    {
        brisk::string result;
        result.append(lhs);
        result.append(rhs);
        return result;
    }

    string operator+(const string& lhs, const char* rhs)
    {
        brisk::string result;
        result.append(lhs);
        result.append(rhs);
        return result;
    }

    string operator+(const string& lhs, char rhs)
    {
        brisk::string result;
        result.append(lhs);
        result.append(rhs);
        return result;
    }

    string operator+(const char* lhs, const string& rhs)
    {
        brisk::string result;
        result.append(lhs);
        result.append(rhs);
        return result;
    }

    string operator+(char lhs, const string& rhs)
    {
        brisk::string result;
        result.append(lhs);
        result.append(rhs);
        return result;
    }

    string operator+(string&& lhs, string&& rhs)
    {
        lhs.append(rhs);
        return brisk::move(lhs);
    }

    string operator+(string&& lhs, const string& rhs)
    {
        lhs.append(rhs);
        return brisk::move(lhs);
    }

    string operator+(string&& lhs, const char* rhs)
    {
        lhs.append(rhs);
        return brisk::move(lhs);
    }

    string operator+(string&& lhs, char rhs)
    {
        lhs.append(rhs);
        return brisk::move(lhs);
    }

    string operator+(const string& lhs, string&& rhs)
    {
        // TODO: create insert() overload for string&
        // rhs.insert(0, lhs);
        // return brisk::move(rhs);
    }

    string operator+(const char* lhs, string&& rhs)
    {
        rhs.insert(0, lhs);
        return brisk::move(rhs);
    }

    string operator+(char lhs, string&& rhs)
    {
        rhs.insert(0, lhs);
        return brisk::move(rhs);
    }
}