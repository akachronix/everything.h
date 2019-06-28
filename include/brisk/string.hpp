#pragma once

#include <istream>
#include <ostream>
#include <cstring>
#include <iterator>

namespace brisk
{
    class string
    {
    private:
        char* m_string;
        size_t m_size;
    
    public:
        string()
        {
            m_string = nullptr;
        }

        string(const char* s)
        {
            m_size = std::strlen(s);
            m_string = new char[m_size + 1];

            std::memcpy(m_string, s, m_size + 1);
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

        friend std::ostream& operator<<(std::ostream& out, const brisk::string& string);
		friend std::istream& operator>>(std::istream& in, brisk::string& string);
    };
    
    std::ostream& operator<<(std::ostream& out, const brisk::string& string)
    {
        out << string.m_string;
        return out;
    }
}