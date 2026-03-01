#include "CSubscribe.hpp"

class dummy : public CSubscribe
{
public:
    dummy();
    void Notify(std::string message) override;
};