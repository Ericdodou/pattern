class Composition {
public:
  Composition(Compositor*);
  void Repair();
private:
  Compositor* _compositor;
  Component* _components;
  int _componentCount;
  int _lineWidth;
  int* _lineBreaks;
  int _lineCount;
};

class Compositor {
public:
  virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[], int componentCount, int lineWidth, int breaks[]) = 0;
private:
  Compositor();
};

void Composition::Repair () {
  Coord* natural;
  Coord* stretchability;
  Coord* shrinkability;
  int componentCount;
  int* breaks;

  int breakCount;
  breakCount = _compositor->Compose(natural, stretchability, shrinkability, componentCount, _lineWidth, breaks);
}

class SimpleCompositor : public Compositor {
public:
  SimpleCompositor();
  virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[], int componentCount, int lineWidth, int breaks[]);
};

class TeXCompositor : public Compositor {
public:
  TeXCompositor();
  virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[], int componentCount, int lineWidth, int breaks[]);
};

class ArrayCompositor : public Compositor {
public:
  ArrayCompositor(int interval);
  virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[], int componentCount, int lineWidth, int breaks[]);
};

Composition* quick = new Composition(new SimpleCompositor);
Composition* slick = new Composition(new TeXCompositor);
Composition* iconic = new Composition(new ArrayCompositor(100));
