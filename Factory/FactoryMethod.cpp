

class Creator {
  public:
    virtual Product* Create(ProductId);
};

Product* Creator::Create(ProductId id) {
  if (id == MINE) return new MyProduct;
  if (id == YOURS) return new YourProduct;
  // if all fails, return 0
  return 0;
}

class MyCreator {
  public:
    Product* GetProduct();
  protected:
    virtual Product* CreateProduct();
  private:
    Product* _product;
};
/*
MyCreator::CreateProduct() {
  _product = 0;
}
*/
Product* MyCreator::GetProduct() {
  if (_product == 0) 
    _product = CreateProduct();
  return _product;
}


class YourCreator {
  public:
    virtual Product* CreateProduct() = 0;
};

template<class TheProduct>
class StandardCreator : public Creator {
  public:
    virtual Product* CreateProduct();
};

template<class TheProduct>
Product* StandardCreator<TheProduct>::CreateProduct() {
  return new TheProduct;
}


