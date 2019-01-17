// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//
#include <algorithm>
#include "INIReader.hpp"
#include "ini.hpp"
INIReader::INIReader(const std::string &fileName)
{
    _error = ini_parse(fileName.c_str(), ValueHandler, this);
}
int INIReader::ParseError() const
{
    return _error;
}
std::string INIReader::Get(const std::string &section, const std::string &name, const std::string &defaultValue) const
{
    std::string key = MakeKey(section, name);
    return _values.count(key) ? _values.find(key)->second : defaultValue;
}
std::string
INIReader::GetString(const std::string &section, const std::string &name, const std::string &defaultValue) const
{
    const std::string str = Get(section, name, "");
    return str.empty() ? defaultValue : str;
}
long INIReader::GetInteger(const std::string &section, const std::string &name, long defaultValue) const
{
    std::string valstr = Get(section, name, "");
    const char *value = valstr.c_str();
    char  *end;
    long n = std::strtol(value, &end, 0);
    return end > value ? n : defaultValue;
}
double INIReader::GetReal(const std::string &section, const std::string &name, double defaultValue) const
{
    std::string valstr = Get(section, name, "");
    const char *value = valstr.c_str();
    char  *end;
    long n = std::strtod(value, &end);
    return end > value ? n : defaultValue;
}
bool INIReader::GetBoolean(const std::string &section, const std::string &name, bool defaultValue) const
{
    std::string valstr = Get(section, name, "");
    std::transform(valstr.begin(), valstr.end(), valstr.begin(), ::tolower);
    if (valstr == "true" || valstr == "yes" || valstr == "on" || valstr == "1")
    {
        return true;
    } else if (valstr == "false" || valstr == "no" || valstr == "off" || valstr == "0")
    {
        return false;
    } else
    {
        return defaultValue;
    }
}
bool INIReader::HasValue(const std::string &section, const std::string &name) const
{
    std::string key = MakeKey(section, name);
    return _values.count(key);
}
std::string INIReader::MakeKey(const std::string &section, const std::string &name)
{
    std::string key = section + "=" + name;
    std::transform(key.begin(), key.end(), key.begin(),::tolower);
    return key;
}
int INIReader::ValueHandler(void *user, const char *section, const char *name, const char *value)
{
    INIReader *reader = static_cast<INIReader*>(user);
    std::string key = MakeKey(section, name);
    if (reader->_values[key].size() > 0)
    {
        reader->_values[key] += "\n";
    }
    reader->_values[key] += value;
    return 1;
}
