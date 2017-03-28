class IterationState;

template <class Item>
class Collection {
  public:
    Collection();

    IterationState* CreateInitialState();
    void Next(IterationState*);
    bool IsDone(const IterationState*) const;
    Item CurrentItem(const IterationState*) const;
    IterationState* Copy(const IterationState*) const;

    void Append(const Item&);
    void Remove(const Item&);
};

class ItemType {
  public:
    void Process();
};

Collection<ItemType*> aCollection;
IterationState* state;

state = aCollection.CreateInitialState();

while (!aCollection.IsDone(state)) {
  aCollection.CurrentItem(state)->Process();
  aCollection.Next(state);
}
delete state;
