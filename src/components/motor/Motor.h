#ifndef __MOTOR__
#define __MOTOR__


class Motor {
    public:
        virtual void autoMove(int angle);
        virtual void potMove(int angle);
};


#endif