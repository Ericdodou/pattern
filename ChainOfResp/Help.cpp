

class HelpHandler {
  public:
    HelpHandler(HelpHandler* s) : _successor(s) {};
    virtual void HandleHelp();
  private:
    HelpHandler* _successor;
};

void HelpHandler::HandleHelp() {
  if (_successor) {
    _successor->HandleHelp();
  }
}

void Handler::HandleRequest(Request* theRequest) {
  switch (theRequest->GetKind()) {
    case Help:
      HandleHelp((HelpRequest*) theRequest);
      break;
    case Print:
      HandlePrint((PrintRequest*) theRequest);
      break;
    default:
      break;
  }
}

class ExtendedHandler : public Handler {
  public:
    virtual void HandleRequest(Request* theRequest);
};

void ExtendedHandler::HandlerRequest(Request* theRequest) {
  switch (theRequest->GetKind()) {
    case Preview:
      break;
    default:
      Handler::HandleRequest(theRequest);
  }
}

