#include <iostream>
using namespace std;
class CMyString
{
  public:
    CMyString(char *pData = nullptr);
    CMyString(const CMyString &str);
    ~CMyString(void);
    CMyString &operator=(const CMyString &str);

  private:
    char *m_pData;
};

CMyString &CMyString::operator=(const CMyString &str)
{
    if (this == &str)
        return *this;

    if (this->m_pData != nullptr)
    {
        auto temp = this->m_pData;
        this->m_pData = nullptr;
        free(temp);
    }
    int len = sizeof(str.m_pData) / sizeof(char);
    this->m_pData = new char[len];
    for (int i = 0; i < len; i++)
    {
        this->m_pData[i] = str.m_pData[i];
    }
    return *this;
}