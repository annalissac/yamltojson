#include <yaml-cpp/yaml.h>
#include <json.hpp>
#include <vector>
#include <iostream>

nlohmann::json yamltojson(YAML::Node yaml) {
    std::vector<nlohmann::json> jsona;
    std::map<std::string, nlohmann::json> jsonm;
    std::string s;
    nlohmann::json jp;
    switch (yaml.Type()) {
        case YAML::NodeType::Scalar:
            s = yaml.as<std::string>();
            try {
                jp = nlohmann::json::parse("["+s+"]");
            } catch (nlohmann::json::parse_error) { }
            if (jp.size() == 1) {
                return jp[0];
            }
            jp = nlohmann::json(s);
            return jp;
            break;

        case YAML::NodeType::Map:
            for(YAML::const_iterator it=yaml.begin();it!=yaml.end();++it) {
                jsonm[it->first.as<std::string>()] = yamltojson(it->second);
            }
            return nlohmann::json(jsonm);
            break;
        case YAML::NodeType::Sequence:
            for (std::size_t i = 0; i < yaml.size(); ++i) {
                jsona.push_back(yamltojson(yaml[i]));
            }
            return nlohmann::json(jsona);
            break;
    }
}

int main(int argc, char **argv) {
    YAML::Node yamlnode;
    yamlnode = YAML::LoadFile("obj.yaml");
    auto jsnode = yamltojson(yamlnode);
    std::cout << jsnode << "\n";
    return 0;
}
