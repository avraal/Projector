// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

// Read an INI file into easy-to-access name/value pairs.

// inih and INIReader are released under the New BSD license (see LICENSE.txt).
// Go to the project home page for more info:
//
// https://github.com/benhoyt/inih

//
// Created by andrew on 17.01.19.
//

#ifndef PROJECTOR_INIREADER_HPP
#define PROJECTOR_INIREADER_HPP

#include <map>
#include <string>

class INIReader
{
private:
    int _error;
    std::map<std::string, std::string> _values;
    static std::string MakeKey(const std::string &section, const std::string &name);
    static int ValueHandler(void *user, const char* section, const char *name, const char* value);
public:
    explicit INIReader(const std::string &fileName);
    int ParseError() const;

    std::string Get(const std::string &section, const std::string &name, const std::string &defaultValue) const;
    std::string GetString(const std::string &section, const std::string &name, const std::string &defaultValue) const;
    long GetInteger(const std::string &section, const std::string &name, long defaultValue) const;
    double GetReal(const std::string &section, const std::string &name, double defaultValue) const;
    bool GetBoolean(const std::string &section, const std::string &name, bool defaultValue) const;
    bool HasValue(const std::string &section, const std::string &name) const;
};

#endif //PROJECTOR_INIREADER_HPP
