#include <list>
#include <vector>

typedef vector NameSingletonPair;


class Singleton {
  public:
    static void Register(const char* name, Singleton*);
    static Singleton* Instance();
  protected:
    static Singleton* Lookup(const char* name);
  private:
    static Singleton* _instance;
    static list<NameSingletonPair*> _registry;
};

Singleton* Singleton::Instance() {
  if (_instance == 0) {
    const char* singletonName = getenv("SINGLETON");
    _instance = Lookup(singletonName);
  }
  return _instance;
}

Singleton* Lookup(const char* name) {
  
}

class MySingleton : public Singleton {
  public:
    MySingleton();
};

MySingleton::MySingleton() {
  Singleton::Register("MySingleton", this);
}



