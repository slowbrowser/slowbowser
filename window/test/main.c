#include <sb_window.h>

int
main()
{
    struct sb_window w = sb_window_init();

    enum sb_event event;
    while(event != sb_event_quit)
    {
        event = sb_window_poll_event(w);
    }
}