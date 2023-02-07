#include <iostream>
#include <unistd.h>
#include <cstdlib> 
#include <spdlog/spdlog.h>
#include <json/json.h>


// Library effective with Windows
// #include <windows.h>


using namespace std;
int main(int argc, char const *argv[])
{
    /* code */

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);


    
    return 0;
}


int main1(int argc, char const *argv[]) {

    cout << "Join the Line:\n";
    cout << "Wait for 5 seconds\n";
    
    // sleep will schedule rest of
    // activities after 10 seconds
    sleep(5);
    
    cout << "It's your time buy ticket" << endl;
    double d = strtold("-0.33", NULL);
    cout << d << "\n";

    return 0;
}
