#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class Logger {
private:
    static Logger* instance;
    std::ofstream logfile;

    Logger() {
        // Open log file in append mode
        logfile.open("log.txt", std::ios::app);
        if (!logfile.is_open()) {
            throw std::runtime_error("Failed to open log file.");
        }
    }

public:
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void log(const std::string& message) {
        // Get current time
        std::time_t now = std::time(nullptr);
        std::tm* now_tm = std::localtime(&now);
        char timestamp[80];
        std::strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S] ", now_tm);

        // Write message to log file with timestamp
        logfile << timestamp << message << std::endl;
    }
};

// Initialize static member of class
Logger* Logger::instance = nullptr;

int main() {
    Logger* logger = Logger::getInstance();
    logger->log("Starting application.");

    string s;
    cout << "Your input: ";
    getline(cin,s);
    logger->log(s);

    logger->log("Application complete.");
    return 0;
}
