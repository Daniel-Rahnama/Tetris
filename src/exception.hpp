#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP


enum ExType {
    SDL_Init_Fail,
    SDL_Window_Fail,
    SDL_Renderer_Fail
};

class Exception {
public:
    Exception(ExType);
    ExType GetType();
private:
    ExType type;
};


#endif /* EXCEPTION_HPP */