#include <string.h>

typedef string State;
class Graphic;

class MoveCommand {
public:
  MoveCommand(Graphic* target, const Point& delta);
  void Execute();
  void Unexecute();
private:
  ConstraintSolverMemento* _state;
  Point _delta;
  Graphic* _target;
};

class ConstraintSolver {
public:
  static ConstraintSolver* Instance();
  void Solve();
  void AddConstraint(Graphic* startConnection, Graphic* endConnection);
  void RemoveConstraint(Graphic* startConnection, Graphic* endConnection);
  ConstraintSolverMemento* CreateMemento();
  void SetMemento(ConstraintSolverMemento*);
protected:
  ConstraintSolver();
private:
  State _st;
  ConstraintSolver* _instance;
};

class ConstraintSolverMemento {
public:
  virtual ~ConstraintSolverMemento();
private:
  friend class ConstraintSolver;
  ConstraintSolverMemento();
  State GetState() const;
  void SetState(const State);
  State _state;
}

void MoveCommand::Execute () {
  ConstraintSolver* solver = ConstraintSolver::Instance();
  _state = ConstraintSolver::CreateMemento();
  _target->Move(_delta);
  solver->Solve();
}

void MoveCommand::Unexecute () {
  ConstraintSolver* solver = ConstraintSolver::Instance();
  _target->Move(_delta);
  solver->SetMemento(_state);
  solver->Solve();
}
