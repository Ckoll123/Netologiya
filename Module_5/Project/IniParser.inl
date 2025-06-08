template <typename T>
T IniParser::get_value(std::string sectionAndVariable){
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
                std::cerr << "Секция пуста" << std::endl;
                throw std::out_of_range{""};
            }
            std::cerr << "В секции \"" + section + "\" имеются следующие переменные:" << std::endl;
            printAvailableVars(section);
            throw std::out_of_range{""};
        }
    }
    else{
        std::cerr << "Данной секции не сущетсвует" << std::endl;
        throw std::out_of_range{""};
    }
    
    // value = fileParsed.at(section).at(variable);

    T outValue{};
    std::istringstream iss(value);
    if (!(iss >> outValue))
        throw std::runtime_error("Не удалось преобразовать в число");
    return outValue;
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
                std::cerr << "Секция пуста" << std::endl;
                throw std::out_of_range{""};
            }
            std::cerr << "В секции \"" + section + "\" имеются следующие переменные:" << std::endl;
            printAvailableVars(section);
            throw std::out_of_range{""};
        }
    }
    else{
        std::cerr << "Данной секции не сущетсвует" << std::endl;
        throw std::out_of_range{""};
    }

    return value;

    // return fileParsed.at(section).at(variable);
}