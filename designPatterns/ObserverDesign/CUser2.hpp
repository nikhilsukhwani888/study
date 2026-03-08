#include "CSubscribe.hpp"

class CUser2 : public CSubscribe
{
public:
    CUser2();
    void Notify(std::string message) override;
};