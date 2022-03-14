#pragma once

struct sb_window
{
};

enum sb_event
{
    sb_event_none,
    sb_event_quit
};

struct sb_window
sb_window_init();

enum sb_event
sb_window_poll_event(struct sb_window);