#include <signal.h>
#include <evpp/libevent_watcher.h>
#include <evpp/event_loop.h>

#include "examples/winmain-inl.h"

int main(int argc, char* argv[]) {
    evpp::EventLoop loop;
    std::unique_ptr<evpp::SignalEventWatcher> ev(
        new evpp::SignalEventWatcher(
            SIGINT, &loop, []() { LOG_INFO << "SIGINT caught.";}));
    ev->Init();
    ev->AsyncWait();
    loop.Run();
    return 0;
}

