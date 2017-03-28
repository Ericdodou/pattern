class View {
public:
  View();
  virtual void Display();
  virtual void SetFocus() = 0;
  virtual void DosDisplay();
  virtual void ResetFocus();
};

void View::Display () {
  SetFocus();
  DoDisplay();
  ResetFocus();
}

void View::DoDisplay () {}

class MyView : public View {
  MyView();
};

void MyView::DoDisplay () {
  // render the view's contents
}
