
class TCPOctetStream;
class TCPState;

class TCPconnection {
public:
  TCPConenction();
  void ActiveOpen();
  void PassiveOpen();
  void Close();
  void Send();
  void Acknowledge();
  void Synchronize();
  void ProcessOctet(TCPOctetStream*);
private:
  friend class TCPState;
  void ChangeState(TCPState*);
  TCPState* _state;
};

class TCPState {
public:
  virtual void Transmit(TCPConenction*, TCPOctetStream*) {};
  virtual void ActiveOpen(TCPConenction*) {};
  virtual void PassiveOpen(TCPConenction*) {};
  virtual void Close(TCPConenction*) {};
  virtual void Synchronize(TCPConenction*) {};
  virtual void Acknowledge(TCPConenction*);
  virtual void Send(TCPConenction*);
protected:
  void ChangeState(TCPConenction*, TCPState*);
};

TCPConenction::TCPConenction () {
  _state = TCPClosed::Instance();
}

void TCPConenction::ChangeState (TCPState* s) {
  _state = s;
}

void TCPConenction::ActiveOpen () {
  _state->ActiveOpen(this);
}

void TCPConenction::PassiveOpen () {
  _state->PassiveOpen(this);
}

void TCPConenction::Close () {
  _state->Close(this);
}

void TCPConenction::Acknowledge () {
  _state->Acknowledge(this);
}

void TCPConenction::Synchronize () {
  _state->Synchronize(this);
}

void TCPState::ChangeState (TCPConenction* t, TCPState* s) {
  t->ChangeState(s);
}

class TCPEstablished : public TCPState {
public:
  static TCPState* Instance();
  virtual void Transmit(TCPConenction*, TCPOctetStream*);
  virtual void Close(TCPConenction*);
};

class TCPListen : public TCPState {
public:
  static TCPState* Instance();
  virtual void Send(TCPConenction*);
};

class TCPClosed : public TCPState {
public:
  static TCPState* Instance();
  virtual void ActiveOpen(TCPConenction*);
  virtual void PassiveOpen(TCPConenction*);
};

void TCPClosed::ActiveOpen (TCPConenction* t) {
  ChangeState(t, TCPEstablished::Instance());
}

void TCPClosed::PassiveOpen (TCPConenction* t) {
  ChangeState(t, TCPListen::Instance());
}

void TCPEstablished::Close (TCPConenction* t) {
  ChangeState(t, TCPListen::Instance());
}

void TCPEstablished::Transmit (TCPConenction* t, TCPOctetStream* o) {
  t->ProcessOctet(o);
}

void TCPListen::Send (TCPConenction* t) {
  ChangeState(t, TCPEstablished::Instance);
}
