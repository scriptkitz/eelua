// sktoolslib - common files for SK tools

// Copyright (C) 2012-2013 - Stefan Kueng

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//

#include "UnicodeUtils.h"

#include <memory>

CUnicodeUtils::CUnicodeUtils(void)
{
}

CUnicodeUtils::~CUnicodeUtils(void)
{
}

#ifdef UNICODE
std::string CUnicodeUtils::StdGetUTF8(const std::wstring& wide)
{
    int len = (int)wide.size();
    if (len == 0)
        return std::string();
    int size = len*4;
    std::unique_ptr<char[]> narrow(new char[size]);
    int ret = WideCharToMultiByte(CP_UTF8, 0, wide.c_str(), len, narrow.get(), size-1, NULL, NULL);
    narrow[ret] = 0;
    std::string sRet = std::string(narrow.get());
    return sRet;
}

std::string CUnicodeUtils::StdGetANSI(const std::wstring& wide)
{
    int len = (int)wide.size();
    if (len == 0)
        return std::string();
    int size = len*4;
    std::unique_ptr<char[]> narrow(new char[size]);
    int ret = WideCharToMultiByte(CP_ACP, 0, wide.c_str(), len, narrow.get(), size-1, NULL, NULL);
    narrow[ret] = 0;
    std::string sRet = std::string(narrow.get());
    return sRet;
}

std::wstring CUnicodeUtils::StdGetUnicode(const std::string& multibyte)
{
    int len = (int)multibyte.size();
    if (len == 0)
        return std::wstring();
    int size = len*4;
    std::unique_ptr<wchar_t[]> wide(new wchar_t[size]);
    int ret = MultiByteToWideChar(CP_UTF8, 0, multibyte.c_str(), len, wide.get(), size - 1);
    wide[ret] = 0;
    std::wstring sRet = std::wstring(wide.get());
    return sRet;
}
#endif

std::string WideToMultibyte(const std::wstring& wide)
{
    std::unique_ptr<char[]> narrow(new char[wide.length()*3+2]);
    BOOL defaultCharUsed;
    int ret = (int)WideCharToMultiByte(CP_ACP, 0, wide.c_str(), (int)wide.size(), narrow.get(), (int)wide.length()*3 - 1, ".", &defaultCharUsed);
    narrow[ret] = 0;
    std::string str = narrow.get();
    return str;
}

std::string WideToUTF8(const std::wstring& wide)
{
    std::unique_ptr<char[]> narrow(new char[wide.length()*3+2]);
    int ret = (int)WideCharToMultiByte(CP_UTF8, 0, wide.c_str(), (int)wide.size(), narrow.get(), (int)wide.length()*3 - 1, NULL, NULL);
    narrow[ret] = 0;
    std::string str = narrow.get();
    return str;
}

std::wstring MultibyteToWide(const std::string& multibyte)
{
    size_t length = multibyte.length();
    if (length == 0)
        return std::wstring();

    std::unique_ptr<wchar_t[]> wide(new wchar_t[multibyte.length()*2+2]);
    if (wide == NULL)
        return std::wstring();
    int ret = (int)MultiByteToWideChar(CP_ACP, 0, multibyte.c_str(), (int)multibyte.size(), wide.get(), (int)length*2 - 1);
    wide[ret] = 0;
    std::wstring str = wide.get();
    return str;
}

std::wstring UTF8ToWide(const std::string& multibyte)
{
    size_t length = multibyte.length();
    if (length == 0)
        return std::wstring();

    std::unique_ptr<wchar_t[]> wide(new wchar_t[length*2+2]);
    if (wide == NULL)
        return std::wstring();
    int ret = (int)MultiByteToWideChar(CP_UTF8, 0, multibyte.c_str(), (int)multibyte.size(), wide.get(), (int)length*2 - 1);
    wide[ret] = 0;
    std::wstring str = wide.get();
    return str;
}
#ifdef UNICODE
tstring UTF8ToString(const std::string& string) {return UTF8ToWide(string);}
std::string StringToUTF8(const tstring& string) {return WideToUTF8(string);}
#else
tstring UTF8ToString(const std::string& string) {return WideToMultibyte(UTF8ToWide(string));}
std::string StringToUTF8(const tstring& string) {return WideToUTF8(MultibyteToWide(string));}
#endif

int GetCodepageFromBuf( LPVOID pBuffer, int cb, bool& hasBOM )
{
    hasBOM = false;
    if (cb < 2)
        return CP_ACP;
    const UINT32 * const pVal32 = (UINT32 *)pBuffer;
    const UINT16 * const pVal16 = (UINT16 *)pBuffer;
    const UINT8 * const pVal8 = (UINT8 *)pBuffer;
    // scan the whole buffer for a 0x00000000 sequence
    // if found, we assume a binary file
    int nDwords = cb/4;
    for (int i=0; i<nDwords; ++i)
    {
        if (0x00000000 == pVal32[i])
            return -1;
    }
    if (cb >=4 )
    {
        if (*pVal32 == 0x0000FEFF)
        {
            hasBOM = true;
            return 12000; // UTF32_LE
        }
        if (*pVal32 == 0xFFFE0000)
        {
            hasBOM = true;
            return 12001; // UTF32_BE
        }
    }
    if (*pVal16 == 0xFEFF)
    {
        hasBOM = true;
        return 1200; // UTF16_LE
    }
    if (*pVal16 == 0xFFFE)
    {
        hasBOM = true;
        return 1201; // UTF16_BE
    }
    if (cb < 3)
        return CP_ACP;
    if (*pVal16 == 0xBBEF)
    {
        if (pVal8[2] == 0xBF)
        {
            hasBOM = true;
            return CP_UTF8;
        }
    }
    // check for illegal UTF8 sequences
    bool bNonANSI = false;
    int nNeedData = 0;
    int i=0;
    // run fast for ASCII
    for (; i<cb; i+=8)
    {
        if ((*(UINT64 *)&pVal8[i] & 0x8080808080808080)!=0) // all ASCII?
        {
            bNonANSI = true;
            break;
        }
    }
    int nullcount = 0;
    // continue slow
    for (; i<cb; ++i)
    {
        UINT8 zChar = pVal8[i];
        if ((zChar & 0x80)==0) // ASCII
        {
            if (zChar == 0)
            {
                ++nullcount;
                // count the null chars, we do not want to treat an ASCII/UTF8 file
                // as UTF16 just because of some null chars that might be accidentally
                // in the file.
                // Use an arbitrary value of one fiftieth of the file length as
                // the limit after which a file is considered UTF16.
                if (nullcount > (cb / 50))
                {
                    // null-chars are not allowed for ASCII or UTF8, that means
                    // this file is most likely UTF16 encoded
                    if (i%2)
                        return 1200; // UTF16_LE
                    else
                        return 1201; // UTF16_BE
                }
                nNeedData = 0;
            }
            else if (nNeedData)
            {
                return CP_ACP;
            }
            continue;
        }
        if ((zChar & 0x40)==0) // top bit
        {
            if (!nNeedData)
                return CP_ACP;
            --nNeedData;
        }
        else if (nNeedData)
        {
            return CP_ACP;
        }
        else if ((zChar & 0x20)==0) // top two bits
        {
            if (zChar<=0xC1)
                return CP_ACP;
            nNeedData = 1;
        }
        else if ((zChar & 0x10)==0) // top three bits
        {
            nNeedData = 2;
        }
        else if ((zChar & 0x08)==0) // top four bits
        {
            if (zChar>=0xf5)
                return CP_ACP;
            nNeedData = 3;
        }
        else
            return CP_ACP;
    }
    if (bNonANSI && nNeedData==0)
        return CP_UTF8;

    return CP_ACP;
}

