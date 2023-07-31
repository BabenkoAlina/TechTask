#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <atomic>
#include <mutex>
#include <dirent.h>
#include "filesearchlib.h"

const int MAX_THREADS = 8;

std::atomic<bool> found(false);
std::mutex printMutex;

void searchDirectory(const std::string& directory, const std::string& filename) {
    std::cout << "Searching directory: " << directory << std::endl;

    if (found)
        return;

    std::string foundFilePath = searchFile(filename, directory);
    if (!foundFilePath.empty()) {
        std::lock_guard<std::mutex> lock(printMutex);
        std::cout << "File found: " << foundFilePath << std::endl;
        found = true;
    }
}


int main() {
    std::string filename;
    std::string rootDirectory = "/Users/alina.babenko";

    std::vector<std::thread> threads;

    std::cout << "Enter you filename: " << std::endl;
    std::cin >> filename;

    DIR* dir = opendir(rootDirectory.c_str());
    if (dir != nullptr) {
        dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_type == DT_DIR) {
                std::string subDirectory = entry->d_name;
                if (subDirectory != "." && subDirectory != "..") {
                    threads.emplace_back([&]() { searchDirectory(rootDirectory + subDirectory, filename); });

                    if (threads.size() >= MAX_THREADS) {
                        for (auto& thread : threads) {
                            thread.join();
                        }
                        threads.clear();
                    }
                }
            }
        }
        closedir(dir);
    }

    // Join remaining threads
    for (auto& thread : threads) {
        thread.join();
    }

    if (!found) {
        std::cout << "File not found." << std::endl;
    }

    return 0;
}
