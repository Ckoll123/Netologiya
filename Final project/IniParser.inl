template<typename T>
T IniParser::get_value(std::string sectionAndVariable) {    //вместо тела, можно поставить ; будет просто ошибка компиляции
    static_assert(sizeof(T) == -1, "not implemented type for get_value");
}


template <>
inline int IniParser::get_value<int>(std::string sectionAndVariable){
    size_t dot = sectionAndVariable.find('.');
    std::string section = sectionAndVariable.substr(0, dot);
    std::string variable = sectionAndVariable.substr(dot + 1);
    
    std::string value{};
    auto itSection = fileParsed.find(section);
    if (itSection != fileParsed.end()){
        auto itVariable = itSection->second.find(variable);
        if (itVariable != itSection->second.end()){
            value = itVariable->second;
        }
        else{
            std::cerr << "Данной переменной в секции \"" + section + "\" не существует" << std::endl;

            if (!itSection->second.size()){
                throw std::out_of_range{"Секция пуста"};
            }
            printAvailableVars(section);
            throw std::out_of_range{"В секции \"" + section + "\" имеются следующие переменные:"};
        }
    }
    else{
        throw std::out_of_range{"Данной секции не существует"};
    }
    
    // value = fileParsed.at(section).at(variable);

    return std::stoi(value);
}


template <>
inline double IniParser::get_value<double>(std::string sectionAndVariable){
    size_t dot = sectionAndVariable.find('.');
    std::string section = sectionAndVariable.substr(0, dot);
    std::string variable = sectionAndVariable.substr(dot + 1);
    
    std::string value{};
    auto itSection = fileParsed.find(section);
    if (itSection != fileParsed.end()){
        auto itVariable = itSection->second.find(variable);
        if (itVariable != itSection->second.end()){
            value = itVariable->second;
        }
        else{
            std::cerr << "Данной переменной в секции \"" + section + "\" не существует" << std::endl;

            if (!itSection->second.size()){
                throw std::out_of_range{"Секция пуста"};
            }
            printAvailableVars(section);
            throw std::out_of_range{"В секции \"" + section + "\" имеются следующие переменные:"};
        }
    }
    else{
        throw std::out_of_range{"Данной секции не существует"};
    }
    
    // value = fileParsed.at(section).at(variable);

    for (char &c : value) {
        if (c == ',') {
            c = '.';
        }
    }

    return std::stod(value);
}


template <>
inline std::string IniParser::get_value<std::string>(std::string sectionAndVariable){
    size_t dot = sectionAndVariable.find('.');
    std::string section = sectionAndVariable.substr(0, dot);
    std::string variable = sectionAndVariable.substr(dot + 1);

    std::string value{};
    auto itSection = fileParsed.find(section);
    if (itSection != fileParsed.end()){
        auto itVariable = itSection->second.find(variable);
        if (itVariable != itSection->second.end()){
            value = itVariable->second;
        }
        else{
            std::cerr << "Данной переменной в секции \"" + section + "\" не существует" << std::endl;

            if (!itSection->second.size()){
                throw std::out_of_range{"Секция пуста"};
            }
            printAvailableVars(section);
            throw std::out_of_range{"В секции \"" + section + "\" имеются следующие переменные:"};
        }
    }
    else{
        throw std::out_of_range{"Данной секции не существует"};
    }

    return value;

    // return fileParsed.at(section).at(variable);
}