#include <iostream>

#include <SDL3/SDL.h>

#include "window.h"
#include "utils/array.h"
#include "snake.h"


int main() {
    s2::window window;
    if(!window.create("Snake 2", {700, 500})) return 1;
    if(!window.show()) return 1;

    s2::snake snake({16.0f}, {5.0f, 5.0f});
    while(!window.should_close()) {
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            window.handle_events(e);
        }

        if(!window.clear_screen()) return 1;
        if(!snake.render(window.renderer())) return 1;
        if(!window.render()) return 1;
    }

    return 0;
}
