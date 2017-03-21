#include <iostream>

class Singleton {
  public:
    static Singleton* Instance();
  protected:
    Singleton();
  private:
    static Singleton* _instance;
};

Singleton* Singleton::_instance = 0;
Singleton::Singleton() {std::cout << "Set up Singleton" << std::endl;}
Singleton* Singleton::Instance() {
  if (_instance == 0) _instance = new Singleton;
  return _instance;
}


int main() {
  Singleton* sgn = Singleton::Instance();
  delete sgn;
  return 0;
}

