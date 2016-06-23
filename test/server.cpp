
#include "cpprest/http_listener.h"
#include "cpprest/http_client.h"
#include <csignal>

using namespace web::http;
using namespace web::http::experimental::listener;
using namespace std;

sig_atomic_t sigflag = 0;

void sighandler(int signum) {
        sigflag = 1;
}

int main() {
        cout << "Hi\n";
        utility::string_t home_uri(U("http://localhost:5001"));
        http_listener m_listener(home_uri);

        m_listener.support([&](http_request request) -> void
                        {
                        auto now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                        cout << now_time << "\n";
                        request.reply(status_codes::OK, U(std::string("Current time is: ") + std::to_string(now_time)));
                        });
        m_listener.open().wait();
        std::signal(SIGINT, sighandler);
        while(!sigflag);
        m_listener.close().wait();

        cout << "Bye\n";
}

