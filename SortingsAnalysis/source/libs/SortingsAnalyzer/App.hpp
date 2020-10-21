#ifndef __SORTINGS_APP__
#define __SORTINGS_APP__

#include "../Application/AbstractApplication.hpp"
#include "MainWindow.hpp"

class Application final : public AbstractApplication {

public:
    int initialize() override;
    int run() override; 

private:
    MainWindow windowsManager;
};

#endif //__SORTINGS_APP__
