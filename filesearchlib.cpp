#include "filesearchlib.h"
#include <dirent.h>

std::string searchFile(const std::string& name, const std::string& directory) {
    DIR* dir = opendir(directory.c_str());
    if (dir) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_type == DT_REG && entry->d_name == name) {
                closedir(dir);
                return directory + "/" + entry->d_name;
            }
        }
        closedir(dir);
    }
    return "";
}
