#include <SDL3/SDL.h>

#include "window.h"


int main() {
    s2::window window;
    if(!window.create("Snake 2", {800, 600})) return 1;
    if(!window.show()) return 1;

    while(!window.should_close()) {
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            window.handle_events(e);
        }

        if(!window.clear_screen()) return 1;
        if(!window.render()) return 1;
    }

    return 0;
}
