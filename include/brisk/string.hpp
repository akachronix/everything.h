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
        size_t m_characters;
        size_t m_size;
        
    public:
        string()
        {
            m_string = new char[16];
            m_size = 16;
            m_characters = 0;
        }

        string(const char* s)
        {
            m_characters = strlen(s);
            m_size = (m_characters == 0) ? 16 : m_characters << 2;
            m_string = new char[m_size];

            memcpy(m_string, s, m_characters + 1);
            memset(m_string + m_characters, 0, m_size - m_characters - 1);
        }

        string(size_t sz)
        {
            m_size = sz * 2;
            m_string = new char[sz];
        }

        string(const string& other)
        {
            m_size = other.m_size;
            m_characters = other.m_characters;
            m_string = new char[m_size];
            memcpy(m_string, other.m_string, m_size);
        }

        string(string&& other)
        {
            m_string = other.m_string;
            m_size = brisk::move(other.m_size);
            m_characters = brisk::move(other.m_characters);
            other.m_string = new char[16];
            other.m_size = 16;
            other.m_characters = 0;
        }

        ~string()
        {
            delete[] m_string;
        }

        string& operator=(const string& str)
        {
            m_characters = str.size();
            m_size = str.capacity();
            m_string = new char[m_size];

            memcpy(m_string, str.data(), m_size);
            
            // needed until we guarantee other strings are always zero'ed out
            memset(m_string + m_characters, 0, m_size - m_characters - 1);

            return *this;
        }

        string& operator=(const char* s)
        {
            m_characters = strlen(s);

            if (m_size <= strlen(s) + 1)  // add one extra byte cause strlen doesnt include null terminator
            {
                delete[] m_string;
                m_size = m_characters << 2;
                m_string = new char[m_size];
            }

            memcpy(m_string, s, m_characters + 1);
            memset(m_string + m_characters, 0, m_size - m_characters);

            return *this;
        }
        
        string& operator=(char c)
        {
            m_characters = 1;

            if (m_size <= 2)  // add one extra byte cause strlen doesnt include null terminator
            {
                delete[] m_string;
                m_size = m_characters << 2;
                m_string = new char[m_size];
            }

            m_string[0] = c;
            memset(m_string + 1, 0, m_size - 1);

            return *this;
        }

        string& operator+=(const string& str)
        {
            this->append(str);
            return *this;
        }

        string& append(const string& str)
        {
            if (m_size <= m_characters + str.size())
            {
                char* old_str = nullptr;
                if (m_characters != 0) {
                    old_str = new char[m_characters + 1];
                    memcpy(old_str, m_string, m_characters + 1);
                }

                delete[] m_string;
                m_size += str.size() << 2;
                m_string = new char[m_size];
                
                if (old_str != nullptr) {
                    memcpy(m_string, old_str, m_characters + 1);
                }
            }

            memcpy(m_string + m_characters, str.data(), str.size());
            memset(m_string + m_characters + str.size(), 0, m_size - (m_characters + str.size()));
            m_characters += str.size();

            return *this;
        }

        string& append(const char* s)
        {
            if (m_size <= m_characters + strlen(s))
            {
                char* old_str = nullptr;
                if (m_characters != 0) {
                    old_str = new char[m_characters + 1];
                    memcpy(old_str, m_string, m_characters + 1);
                }

                delete[] m_string;
                m_size += strlen(s) << 2;
                m_string = new char[m_size];
                
                if (old_str != nullptr) {
                    memcpy(m_string, old_str, m_characters + 1);
                }
            }

            memcpy(m_string + m_characters, s, strlen(s));
            memset(m_string + m_characters + strlen(s), 0, m_size - (m_characters + strlen(s)));
            m_characters += strlen(s);

            return *this;
        }

        string& append(char c)
        {
            if (m_size <= m_characters + 1)
            {
                char* old_str = nullptr;
                if (m_characters != 0) {
                    old_str = new char[m_characters + 1];
                    memcpy(old_str, m_string, m_characters + 1);
                }

                delete[] m_string;
                m_size += 1 << 2;
                m_string = new char[m_size];

                if (old_str != nullptr) {
                    memcpy(m_string, old_str, m_characters + 1);
                }
            }

            memcpy(m_string + m_characters, &c, 1);
            memset(m_string + m_characters + 1, 0, m_size - (m_characters + 1));
            m_characters += 1;

            return *this;
        }

        string& insert(size_t index, const string& s)
        {
            char* old_str = new char[m_size + 1];
            memcpy(old_str, m_string, m_size + 1);

            if (m_string != nullptr)
                delete[] m_string;
            
            m_string = new char[m_size + s.size() + 1];
            memcpy(m_string, s.data(), index + 1);
            memcpy(m_string + index, s.data(), s.size());
            memcpy(m_string + index + s.size(), old_str + index, m_size - index);

            m_size += s.size();
            m_string[m_size + 1] = '\0';

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
            return m_characters;
        }

        size_t length() const noexcept
        {
            return m_characters;
        }

        size_t capacity() const noexcept
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
        rhs.insert(0, lhs);
        return brisk::move(rhs);
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
